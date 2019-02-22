#pragma once

bool g_AutoLoginIsEnabled = true;

uint32_t g_AutoLoginCharacterIndex = 0;

std::vector<std::string> g_AutoLoginCharacterNameList;
uint32_t g_AutoLoginCharacterNameList_reserve = 64;

EQApp::Timer g_AutoLoginTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_AutoLoginTimerInterval = 3;

void EQAPP_AutoLogin_Toggle();
void EQAPP_AutoLogin_On();
void EQAPP_AutoLogin_Off();
void EQAPP_AutoLogin_Load();
void EQAPP_AutoLogin_Execute();

void EQAPP_AutoLogin_Toggle()
{
    EQ_ToggleBool(g_AutoLoginIsEnabled);
    EQAPP_PrintBool("Auto Login", g_AutoLoginIsEnabled);

    g_AutoLoginCharacterIndex = 0;
}

void EQAPP_AutoLogin_On()
{
    if (g_AutoLoginIsEnabled == false)
    {
        EQAPP_AutoLogin_Toggle();
    }
}

void EQAPP_AutoLogin_Off()
{
    if (g_AutoLoginIsEnabled == true)
    {
        EQAPP_AutoLogin_Toggle();
    }
}

void EQAPP_AutoLogin_Load()
{
    g_AutoLoginCharacterIndex = 0;

    g_AutoLoginCharacterNameList.clear();
    g_AutoLoginCharacterNameList.reserve(g_AutoLoginCharacterNameList_reserve);

    EQAPP_ReadFileToList("autologin.txt", g_AutoLoginCharacterNameList, false);
}

void EQAPP_AutoLogin_Execute()
{
    if (g_AutoLoginIsEnabled == false)
    {
        return;
    }

    if (EQAPP_Timer_HasTimeElapsed(g_AutoLoginTimer, g_AutoLoginTimerInterval) == false)
    {
        return;
    }

    if (EQ_GetGameState() != EQ_GAME_STATE_CHARACTER_SELECT)
    {
        return;
    }

    if (EQ_ADDRESS_POINTER_CCharacterListWnd == NULL || EQ_CLASS_POINTER_CCharacterListWnd == NULL)
    {
        ////EQAPP_SetWindowTitle("CCharacterListWnd address or pointer is NULL");

        EQAPP_InitializeAddresses();
        EQAPP_InitializeAddressPointers();
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        ////EQAPP_SetWindowTitle("playerSpawn is NULL");
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.size() == 0)
    {
        ////EQAPP_SetWindowTitle("playerName size is 0");
        return;
    }

    for (auto& characterName : g_AutoLoginCharacterNameList)
    {
        if (characterName == playerName)
        {
            g_AutoLoginIsEnabled = false;
            g_AutoLoginCharacterIndex = 0;

            EQAPP_SetWindowTitle("EverQuest - Auto Login");

            EQ_CLASS_POINTER_CCharacterListWnd->EnterWorld();

            return;
        }
    }

    ////std::stringstream ss;
    ////ss << "character index: " << g_AutoLoginCharacterIndex;
    ////EQAPP_SetWindowTitle(ss.str().c_str());

    EQ_CLASS_POINTER_CCharacterListWnd->SelectCharacter(g_AutoLoginCharacterIndex, true, false);

    g_AutoLoginCharacterIndex++;

    if (g_AutoLoginCharacterIndex > EQ_NUM_CHARACTERS_PER_ACCOUNT)
    {
        g_AutoLoginCharacterIndex = 0;
    }
}
