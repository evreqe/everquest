#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <random>
#include <functional>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

#include "detours.h"
#pragma comment(lib, "detours.lib")

#include "jansson.h"
#pragma comment(lib, "jansson.lib")

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <imgui.h>
#include "imgui_impl_glfw.h"

#include "eq.h"
#include "eq_functions.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_detours.h"
#include "eqapp_console.h"
#include "eqapp_memory.h"
#include "eqapp_sounds.h"
#include "eqapp_waypoint.h"
#include "eqapp_zoneshortnames.h"
#include "eqapp_freecamera.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_hidecorpselooted.h"
#include "eqapp_maxswimmingskill.h"
#include "eqapp_changeheight.h"
#include "eqapp_swimspeed.h"
#include "eqapp_linetotarget.h"
#include "eqapp_namedspawns.h"
#include "eqapp_census.h"
#include "eqapp_nobeep.h"
#include "eqapp_spawnbeep.h"
#include "eqapp_targetbeep.h"
#include "eqapp_characterfile.h"
#include "eqapp_textoverlaychattext.h"
#include "eqapp_doors.h"
#include "eqapp_maplocations.h"
#include "eqapp_onscreentext.h"
#include "eqapp_autoloot.h"
#include "eqapp_maplabels.h"
#include "eqapp_playeralert.h"
#include "eqapp_drawdistance.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_spawnlist.h"
#include "eqapp_banklist.h"
#include "eqapp_inventorylist.h"
#include "eqapp_replaceraces.h"
#include "eqapp_autogroup.h"
#include "eqapp_zoneactors.h"
#include "eqapp_backstab.h"
#include "eqapp_esp.h"                 // needs to be included last
#include "eqapp_esp_functions.h"       // needs to be included last
#include "eqapp_hud.h"                 // needs to be included last
#include "eqapp_interpretcommand.h"    // needs to be included last

#include "eqapp_imgui.h"
#include "eqapp_imgui_functions.h"

#include "eqapp_imgui_consolewindow.h"

void EQAPP_Load()
{
    std::cout << "Loading..." << std::endl;

    EQAPP_CharacterFile_Write();

    EQAPP_Memory_Load();
    EQAPP_Sounds_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_ESP_Custom_Load();
    EQAPP_TextOverlayChatText_Load();
    EQAPP_NoBeep_Load();
    EQAPP_ZoneShortNames_Load();
    EQAPP_ZoneActors_NoCollision_Load();
    EQAPP_ZoneActors_NoCollision_Execute();

    EQ_UpdateLight(EQ_GetCharInfo());

    std::cout << "Loaded." << std::endl;

    g_bLoaded = 1;
}

void EQAPP_OnEnterZone()
{
    EQAPP_ZoneActors_NoCollision_Execute();
}

void EQAPP_Unload()
{
    std::cout << "Unloading..." << std::endl;

    EQAPP_CharacterFile_Write();

    EQ_ResetViewActor();

    g_spawnCastSpellList.clear();

    EQAPP_MapLabels_Remove();

    EQAPP_Memory_Unload();

    EQAPP_FreeCamera_Set(false);

    EQAPP_SwimSpeed_Off();

    EQ_UpdateLight(EQ_GetCharInfo());

    EQ_SetWindowTitle(EQ_STRING_WINDOW_TITLE);

    std::cout << "Unloaded." << std::endl;

    g_bExit = 1;
}

void EQAPP_SetWindowTitles()
{
    if (g_bExit == 1)
    {
        return;
    }

    HWND window = EQ_ReadMemory<HWND>(EQ_WINDOW_HWND);
    if (window == NULL)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        SetWindowTextA(window, EQ_STRING_WINDOW_TITLE);

        if (g_consoleWindowHwnd != NULL)
        {
            SetWindowTextA(g_consoleWindowHwnd, g_consoleWindowTitle);
        }
    }
    else
    {
        char playerName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(playerName, (LPVOID)(playerSpawn + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(playerName));

        std::stringstream ss;
        ss << "EQ: " << playerName;

        SetWindowTextA(window, ss.str().c_str());
        //SetWindowTextA(window, playerName);

        if (g_consoleWindowHwnd != NULL)
        {
            std::stringstream ss;
            ss << "EQC: " << playerName;

            SetWindowTextA(g_consoleWindowHwnd, ss.str().c_str());
        }
    }
}

int __cdecl EQAPP_DETOUR_ExecuteCommand(uint32_t a1, BOOL a2, PVOID a3)
{
    // a1 = command index
    // a2 = key is held down boolean
    // a3 = unknown

    if (g_bExit == 1)
    {
        return EQAPP_REAL_ExecuteCommand(a1, a2, a3);
    }

    if (g_debugIsEnabled == true)
    {
        uint32_t commandIndex = a1;
        std::string commandName = EQ_GetExecuteCommandName(commandIndex);

        if (commandName.size() > 0)
        {
            std::stringstream ss;
            ss << "ExecuteCommand(): " << commandName << " (" << commandIndex << ")";

            EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());
        }
    }

    if (g_freeCameraIsEnabled == true)
    {
        // prevent movement and changing the camera view
        if
        (
            (a1 >= EQ_EXECUTECMD_JUMP && a1 <= EQ_EXECUTECMD_STRAFE_RIGHT)            ||
            (a1 >= EQ_EXECUTECMD_OVERHEAD_CAMERA && a1 <= EQ_EXECUTECMD_USER2_CAMERA) ||
            a1 == EQ_EXECUTECMD_TOGGLECAM
        )
        {
            return EQAPP_REAL_ExecuteCommand(NULL, 0, 0);
        }
    }

    // camping out or exiting the game
    if (a1 == EQ_EXECUTECMD_CAMP || a1 == EQ_EXECUTECMD_CMD_EXITGAME)
    {
        std::cout << "Camping out or exiting the game..." << std::endl;

        EQ_ResetViewActor();

        EQAPP_CharacterFile_Write();
    }

    // open all windows is a toggle, no need for a separate close all windows key
    if (a1 == EQ_EXECUTECMD_OPEN_INV_BAGS && a2 == 1)
    {
        if (EQ_IsContainerWindowOpen() == true)
        {
            EQ_CloseAllContainers();

            return EQAPP_REAL_ExecuteCommand(NULL, 0, 0);
        }
    }
    else if (a1 == EQ_EXECUTECMD_OPEN_INV_BAGS && a2 == 0)
    {
        return EQAPP_REAL_ExecuteCommand(NULL, 0, 0);
    }

    return EQAPP_REAL_ExecuteCommand(a1, a2, a3);
}

int __cdecl EQAPP_DETOUR_SetTarget(uint32_t a1, const char* a2)
{
    // a1 = playerSpawn + 0x00 uint32_t POINTER
    // a2 = spawn name text (/target 'text')

    if (g_bExit == 1)
    {
        return EQAPP_REAL_SetTarget(a1, a2);
    }

    if (g_setTargetIsEnabled == false)
    {
        return EQAPP_REAL_SetTarget(a1, a2);
    }

    if (g_debugIsEnabled == true && a2 != NULL)
    {
        std::cout << "[debug] SetTarget():" << std::endl;
        std::cout << "[debug] a1: " << a1 << std::endl;
        std::cout << "[debug] a2: " << a2 << std::endl;
    }

    std::string targetName = a2;

    float maxDistance = EQ_SET_TARGET_DISTANCE_MAX;

    if (g_setTargetMaxDistanceIsEnabled == true)
    {
        maxDistance = g_setTargetMaxDistance;
    }

    EQ_SetTargetByName(targetName.c_str(), maxDistance);

    return 0;
}

int __fastcall EQAPP_DETOUR_CEverQuest__SetGameState(void* this_ptr, void* not_used, int a1)
{
    // a1 = game state

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__SetGameState(this_ptr, a1);
    }

    if (g_debugIsEnabled == true)
    {
        std::cout << "[debug] CEverQuest::SetGameState(): " << a1 << std::endl;
    }

    return EQAPP_REAL_CEverQuest__SetGameState(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CEverQuest__StartCasting(void* this_ptr, void* not_used, int a1)
{
    // a1 = spawn casting spell structure

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__StartCasting(this_ptr, a1);
    }

    uint32_t spawnId = EQ_ReadMemory<uint16_t>(a1);
    uint32_t spellId = EQ_ReadMemory<uint16_t>(a1 + 2);
    uint32_t spellCastTime = EQ_ReadMemory<uint32_t>(a1 + 4);

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    uint32_t spawnInfo = EQ_EQPlayerManager->GetSpawnByID(spawnId);

    if (spawnInfo != NULL && spawnInfo != playerSpawn)
    {
        char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = {0};
        memcpy(spawnName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

        std::string spellName = EQ_GetSpellNameById(spellId);

        if (spawnName != NULL && spellName.size() != 0)
        {
            if (g_debugIsEnabled == true)
            {
                std::stringstream ss;
                ss << spawnName << " begins to cast " << spellName;

                EQAPP_PrintDebugMessage(__FUNCTION__, ss.str());
            }

            std::stringstream ss;
            ss << spawnName << " (" << spellName << ")";

            EQAPP_OnScreenText_Add(ss.str());

            EQAPP_SpawnCastSpell_Add(spawnInfo, spellId, spellCastTime);
        }
    }

    return EQAPP_REAL_CEverQuest__StartCasting(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* this_ptr, void* not_used, int a1, int a2, int a3, int a4, int a5)
{
    // a1 = spawnInfo
    // a2 = 0
    // a3 = 1
    // a4 = 2
    // a5 = 1

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__CreatePlayerActor(this_ptr, a1, a2, a3, a4, a5);
    }

    if (a1 != NULL)
    {
        if (g_replaceRacesIsEnabled == true)
        {
            uint32_t playerSpawn = EQ_GetPlayerSpawn();
            if (a1 == playerSpawn)
            {
                int spawnRace = EQ_ReadMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_RACE);
                if (spawnRace == EQ_RACE_CHOKADAI)
                {
                    EQ_WriteMemory<uint32_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_RACE, EQ_RACE_HUMAN);
                }
            }
        }

        char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
        memcpy(spawnNumberedName, (LPVOID)(a1 + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

        if (g_debugIsEnabled == true && spawnNumberedName != NULL)
        {
            std::cout << "[debug] CDisplay::CreatePlayerActor(): " << spawnNumberedName << std::endl;
            std::cout << "[debug] a1: " << std::hex << a1 << std::endl; // spawnInfo
            std::cout << "[debug] a2: " << a2 << std::endl; // 0
            std::cout << "[debug] a3: " << a3 << std::endl; // 1
            std::cout << "[debug] a4: " << a4 << std::endl; // 2
            std::cout << "[debug] a5: " << a5 << std::endl; // 1
        }

        if (EQ_DoesSpawnExist(a1) == false)
        {
            EQAPP_OnScreenText_AddSpawnMessage(a1, false);
        }

        if (g_spawnBeepIsEnabled == true && EQ_IsInGame() == true)
        {
            EQAPP_SpawnBeep_Execute(a1);
        }
    }

    return EQAPP_REAL_CDisplay__CreatePlayerActor(this_ptr, a1, a2, a3, a4, a5);
}

int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* this_ptr, void* not_used, uint32_t a1)
{
    // a1 = actorInstance

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CDisplay__DeleteActor(this_ptr, a1);
    }

    if (a1 != NULL)
    {
        uint32_t spawnInfo = EQ_ReadMemory<uint32_t>(a1 + EQ_OFFSET_ACTOR_INSTANCE_INFO_SPAWN_INFO);
        if (spawnInfo != NULL)
        {
            char spawnNumberedName[EQ_SIZE_SPAWN_INFO_NUMBERED_NAME] = {0};
            memcpy(spawnNumberedName, (LPVOID)(spawnInfo + EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME), sizeof(spawnNumberedName));

            if (g_debugIsEnabled == true && spawnNumberedName != NULL)
            {
                std::cout << "[debug] CDisplay::DeleteActor(): " << spawnNumberedName << " (" << std::hex << spawnInfo << ")" << std::endl;
            }

            EQAPP_OnScreenText_AddSpawnMessage(spawnInfo, true);
        }
    }

    return EQAPP_REAL_CDisplay__DeleteActor(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_CEverQuest__dsp_chat(void* this_ptr, void* not_used, const char* a1, int a2, bool a3)
{
    // a1 = text
    // a2 = textColor

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    if (a1 == NULL)
    {
        return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    if (strlen(a1) == 0)
    {
        return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
    }

    if (g_soundsIsEnabled == true)
    {
        for (auto& sound : g_soundsList)
        {
            if (strstr(a1, sound.text.c_str()) != NULL)
            {
                EQAPP_PlaySound(sound.filename.c_str());
                break;
            }
        }
    }

    if (g_textOverlayOnChatTextIsEnabled == true)
    {
        for (auto& text : g_textOverlayChatTextList)
        {
            if (strstr(a1, text.c_str()) != NULL)
            {
                EQAPP_TextOverlayChatText_DisplayText(a1);
                EQAPP_OnScreenText_Add(a1);
                break;
            }
        }
    }

    if (g_censusIsEnabled == true)
    {
        if (strstr(a1, "[") != NULL && strstr(a1, "]") != NULL)
        {
            std::cout << a1 << std::endl;
        }
    }

    if (g_backstabIsEnabled == true)
    {
        if (strstr(a1, "You see an opening") != NULL)
        {
            EQAPP_Backstab_Execute();
        }
    }

    // camping out
    //const char* eqstr12293 = EQ_StringTable->getString(12293, 0); // 12293 It will take you about 30 seconds to prepare your camp.
    //if (strcmp(a1, eqstr12293) == 0)
    if (strcmp(a1, "It will take you about 30 seconds to prepare your camp.") == 0)
    {
        EQ_ResetViewActor();

        EQAPP_CharacterFile_Write();
    }

    return EQAPP_REAL_CEverQuest__dsp_chat(this_ptr, a1, a2, a3);
}

int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone(void* this_ptr, void* not_used, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__MoveToZone(this_ptr, a1, a2, a3, a4, a5, a6, a7, a8);
    }

    std::cout << "Moving to zone..." << std::endl;

    g_bOnEnterZone = 0;

    g_espZoneActorIsEnabled = false;

    EQAPP_MapLabels_Remove();

    return EQAPP_REAL_CEverQuest__MoveToZone(this_ptr, a1, a2, a3, a4, a5, a6, a7, a8);
}

int __fastcall EQAPP_DETOUR_CEverQuest__EnterZone(void* this_ptr, void* not_used, struct HWND__* a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__EnterZone(this_ptr, a1);
    }

    std::cout << "Entering zone..." << std::endl;

    int result = EQAPP_REAL_CEverQuest__EnterZone(this_ptr, a1);

    g_bOnEnterZone = 1;

    EQAPP_MapLabels_Remove();

    EQAPP_FreeCamera_Set(false);

    EQAPP_CharacterFile_Write();

    EQAPP_TextOverlayChatText_Load();
    EQAPP_NoBeep_Load();
    EQAPP_NamedSpawns_Load();
    EQAPP_ESP_Custom_Load();
    EQAPP_ZoneActors_NoCollision_Load();
    EQAPP_ZoneActors_NoCollision_Execute();

    g_alwaysAttackIsEnabled = false;

    g_censusIsEnabled = false;

    g_spawnCastSpellList.clear();

    g_onScreenTextList.clear();

    return result;
}

/*
int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* this_ptr, void* not_used, uint32_t a1, const char* a2)
{
    // a1 = spawnInfo
    // a2 = command text

    if (g_bExit == 1)
    {
        return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, NULL, NULL);
    }

    if (a1 == NULL || a2 == NULL)
    {
        return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, NULL, NULL);
    }

    if (strlen(a2) == 0)
    {
        return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, NULL, NULL);
    }

    if (strcmp(a2, "/exit") == 0)
    {
        EQAPP_Unload();
    }

    if (strlen(a2) > 2 && strncmp(a2, "//", 2) == 0)
    {
        EQAPP_InterpretCommand(a2);

        return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, NULL, NULL);
    }

    return EQAPP_REAL_CEverQuest__InterpretCmd(this_ptr, a1, a2);
}
*/

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* this_ptr, void* not_used, int a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);
    }

    int result = EQAPP_REAL_EQ_Character__eqspa_movement_rate(this_ptr, a1);

    if (g_movementSpeedHackIsEnabled == true)
    {
        uint32_t playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            float speedModifier = EQ_ReadMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_INFO_SPEED_MODIFIER);
            if (speedModifier < g_movementSpeedHackModifier)
            {
                EQ_WriteMemory<float>(playerSpawn + EQ_OFFSET_SPAWN_INFO_SPEED_MODIFIER, g_movementSpeedHackModifier);
            }
        }
    }

    return result;
}

int __fastcall EQAPP_DETOUR_EQPlayer__ChangePosition(void* this_ptr, void* not_used, uint8_t a1)
{
    // a1 = standing state

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__ChangePosition(this_ptr, a1);
    }

    if (g_neverFrozenIsEnabled == true)
    {
        if (a1 == EQ_STANDING_STATE_FROZEN)
        {
            a1 = EQ_STANDING_STATE_STANDING;
        }
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL && (uint32_t)this_ptr == playerSpawn)
    {
        if (a1 == EQ_STANDING_STATE_DUCKING)
        {
            if (g_freeCameraIsEnabled == true)
            {
                EQAPP_FreeCamera_Set(false);
            }

            g_censusIsEnabled = false;
        }
    }

    return EQAPP_REAL_EQPlayer__ChangePosition(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_EQPlayer__do_change_form(void* this_ptr, void* not_used, EQ::ChangeForm* a1)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__do_change_form(this_ptr, a1);
    }

    if (g_debugIsEnabled == true)
    {
        std::cout << "EQPlayer::do_change_form():" << std::endl;

        unsigned const char* bytes = (unsigned const char*)a1;

        std::cout << "Bytes:" << std::endl;
        for (size_t i = 0; i < 128; i++) // size of structure is unknown, look at 128 bytes to guess values
        {
            std::cout << "#" << i << ": " << std::hex << std::uppercase << (int)bytes[i] << std::dec << " " << std::endl;
        }
    }

    if (g_replaceRacesIsEnabled == true)
    {
        if (a1->RaceId == EQ_RACE_INVISIBLE_MAN)
        {
            a1->RaceId = EQ_RACE_HUMAN;
        }
        else if (a1->RaceId == EQ_RACE_SKELETON)
        {
            a1->RaceId = EQ_RACE_SKELETON2;
        }

        uint32_t playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL && (uint32_t)this_ptr == playerSpawn)
        {
            if (a1->RaceId == EQ_RACE_CHOKADAI)
            {
                a1->RaceId = EQ_RACE_HUMAN;
            }
        }
    }

    return EQAPP_REAL_EQPlayer__do_change_form(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_EQPlayer__SetRace(void* this_ptr, void* not_used, int a1)
{
    // a1 = race id

    if (g_bExit == 1)
    {
        return EQAPP_REAL_EQPlayer__SetRace(this_ptr, a1);
    }

    if (g_replaceRacesIsEnabled == true)
    {
        if (a1 == EQ_RACE_INVISIBLE_MAN)
        {
            a1 = EQ_RACE_HUMAN;
        }
        else if (a1 == EQ_RACE_SKELETON)
        {
            a1 = EQ_RACE_SKELETON2;
        }

        uint32_t playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL && (uint32_t)this_ptr == playerSpawn)
        {
            if (a1 == EQ_RACE_CHOKADAI)
            {
                a1 = EQ_RACE_HUMAN;
            }
        }
    }

    return EQAPP_REAL_EQPlayer__SetRace(this_ptr, a1);
}

/*
int __fastcall EQAPP_DETOUR_CMapViewWnd__dCMapViewWnd(void* this_ptr, void* not_used)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CMapViewWnd__dCMapViewWnd(this_ptr);
    }

    //std::cout << "CMapViewWnd::~CMapViewWnd()" << std::endl;

    return EQAPP_REAL_CMapViewWnd__dCMapViewWnd(this_ptr);
}
*/

int __fastcall EQAPP_DETOUR_CMapViewWnd__DrawMap(void* this_ptr, void* not_used, int a1, int a2, int a3, int a4)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_CMapViewWnd__DrawMap(this_ptr, a1, a2, a3, a4);
    }

    if (g_mapLabelsIsEnabled == true)
    {
        EQAPP_MapLabels_Execute();
    }

    return EQAPP_REAL_CMapViewWnd__DrawMap(this_ptr, a1, a2, a3, a4);
}

int __fastcall EQAPP_DETOUR_MapViewMap__Save(void* this_ptr, void* not_used, char* a1)
{
    // a1 = short zone name of map

    if (g_bExit == 1)
    {
        return EQAPP_REAL_MapViewMap__Save(this_ptr, a1);
    }

    std::cout << "The game is saving the map..." << std::endl;

    EQAPP_MapLabels_Remove();

    return EQAPP_REAL_MapViewMap__Save(this_ptr, a1);
}

int __fastcall EQAPP_DETOUR_MapViewMap__SaveEx(void* this_ptr, void* not_used, char* a1, int a2)
{
    // a1 = short zone name of map
    // a2 = map layer

    if (g_bExit == 1)
    {
        return EQAPP_REAL_MapViewMap__SaveEx(this_ptr, a1, a2);
    }

    std::cout << "The game is saving map layer #" << a2 << std::endl;

    EQAPP_MapLabels_Remove();

    return EQAPP_REAL_MapViewMap__SaveEx(this_ptr, a1, a2);
}

int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10)
{
    if (g_bExit == 1)
    {
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    if (g_bLoaded == 0)
    {
        EQAPP_Load();
    }

    // kill switch
    if (GetAsyncKeyState(g_killSwitchKey))
    {
        EQAPP_Unload();
    }

    if (EQ_IsInGame() == false)
    {
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    if (EQ_IsScreenshotBeingTaken() == true)
    {
        return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }

    if (g_bOnEnterZone == 1)
    {
        EQAPP_OnEnterZone();

        g_bOnEnterZone = 0;
    }

    EQAPP_SetWindowTitles();

    EQAPP_FreeCamera_Keys();

    EQAPP_PlayerAlert_Execute();
    EQAPP_TargetBeep_Execute();

    EQAPP_AutoGroup_Execute();
    EQAPP_HideCorpseLooted_Execute();
    EQAPP_AlwaysAttack_Execute();
    EQAPP_MaxSwimmingSkill_Execute();
    EQAPP_AutoLoot_Execute();
    EQAPP_SpawnCastSpell_Execute();
    EQAPP_CombatHotbutton_Execute();
    EQAPP_AlwaysHotbutton_Execute();
    EQAPP_ChangeHeight_Execute();
    EQAPP_SwimSpeed_Execute();
    EQAPP_DrawDistance_Execute();
    EQAPP_Census_Execute();
    EQAPP_ReplaceRaces_Execute();

    if (EQAPP_IsAnImportantWindowOpen() == false && EQ_IsKeyShiftPressed() == false)
    {
        // these functions draw on the screen
        EQAPP_LineToTarget_Execute();
        EQAPP_ESP_Execute();
        EQAPP_NamedSpawns_Execute();
        EQAPP_OnScreenText_Execute();
    }

    EQAPP_Hud_Execute();

    return EQAPP_REAL_DrawNetStatus(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int __cdecl EQAPP_DETOUR_Exit()
{
    EQAPP_Unload();

    return EQAPP_REAL_Exit();
}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    if (!glfwInit())
    {
        return 0;
    }

    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    g_videoModeWidth = videoMode->width;
    g_videoModeHeight = videoMode->height;

    g_consoleWindow = glfwCreateWindow(g_videoModeWidth, g_videoModeHeight, g_consoleWindowTitle, NULL, NULL);
    if (!g_consoleWindow)
    {
        glfwTerminate();
        ImGui_ImplGlfw_Shutdown();

        g_bConsole = 0;

        return 0;
    }

    glfwMakeContextCurrent(g_consoleWindow);
    ImGui_ImplGlfw_Init(g_consoleWindow, true);

    g_consoleWindowHwnd = glfwGetWin32Window(g_consoleWindow);

    EQAPP_CenterWindow(g_consoleWindowHwnd);

    // disable close button
    EnableMenuItem(GetSystemMenu(g_consoleWindowHwnd, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

    ShowWindow(g_consoleWindowHwnd, SW_MAXIMIZE);
    ShowWindow(g_consoleWindowHwnd, SW_SHOW);
    UpdateWindow(g_consoleWindowHwnd);

    EQAPP_Console_Load();

    while (g_bExit == 0)
    {
        if (!glfwWindowShouldClose(g_consoleWindow))
        {
            glfwPollEvents();
            ImGui_ImplGlfw_NewFrame();

            EQAPP_IMGUI_Draw();

            int displayWidth, displayHeight;
            glfwGetFramebufferSize(g_consoleWindow, &displayWidth, &displayHeight);
            glViewport(0, 0, displayWidth, displayHeight);
            glClearColor(g_consoleWindowClearColor.x, g_consoleWindowClearColor.y, g_consoleWindowClearColor.z, g_consoleWindowClearColor.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui::Render();
            glfwSwapBuffers(g_consoleWindow);
        }

        // print redirected std::cout to the console
        for (std::string text; std::getline(g_consoleStringStream, text, '\n');)
        {
            g_imguiConsoleWindow.AddLog("%s", text.c_str());
        }
        g_consoleStringStream.str(std::string());
        g_consoleStringStream.clear();

        // interpet commands sent to the console
        for (auto& command : g_imguiConsoleWindow.m_interpretCommands)
        {
            EQAPP_InterpretCommand(command.c_str());
        }
        g_imguiConsoleWindow.m_interpretCommands.clear();
    }

    ImGui_ImplGlfw_Shutdown();
    glfwTerminate();

    EQAPP_Console_Unload();

    return 0;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_bExit == 0)
    {
        Sleep(100);
    }

    // wait for the console to unload
    while (g_bConsole == 1);

    Sleep(100);

    EQAPP_Detours_Remove();

    Sleep(1000);

    FreeLibraryAndExitThread(g_module, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    EQ_LoadGraphicsDllFunctions();

    EQ_SetNetStatus(true);

    g_handleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_bConsole == 0);

    g_handleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_Detours_Add();

    return 0;
}

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    g_module = module;

    switch (reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(module);
            g_handleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
            break;

        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}
