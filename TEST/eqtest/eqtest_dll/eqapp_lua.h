#pragma once

namespace EQApp
{
    typedef struct _LuaEventScript
    {
        std::string Filename;
        sol::state LuaState;
    } LuaEventScript, *LuaEventScript_ptr;

    typedef std::shared_ptr<EQApp::LuaEventScript> LuaEventScript_sharedptr;
}

bool g_LuaIsEnabled = true;

sol::state g_LuaState;

std::vector<EQApp::LuaEventScript_sharedptr> g_LuaEventScriptList;

EQApp::Timer g_LuaOneSecondTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LuaOneSecondTimerInterval = 1;

EQApp::Timer g_LuaThreeSecondsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LuaThreeSecondsTimerInterval = 3;

EQApp::Timer g_LuaSixSecondsTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LuaSixSecondsTimerInterval = 6; // 1 tick

EQApp::Timer g_LuaOneMinuteTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LuaOneMinuteTimerInterval = 60;

EQApp::Timer g_LuaOneHourTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_LuaOneHourTimerInterval = 3600; // 60 * 60;

void EQAPP_Lua_Toggle();

void EQAPP_Lua_Load();
void EQAPP_Lua_On();
void EQAPP_Lua_Off();
void EQAPP_Lua_OpenLibraries(sol::state* state);
void EQAPP_Lua_ResetTimers();
void EQAPP_Lua_EventScriptList_Load();
void EQAPP_Lua_EventScriptList_Print();
void EQAPP_Lua_EventScriptList_ExecuteFunction(const char* functionName);
void EQAPP_Lua_ScriptFolder_Print();
bool EQAPP_Lua_ExecuteCode(sol::state* state, const char* text);
bool EQAPP_Lua_ExecuteFile(sol::state* state, const char* filename);
void EQAPP_Lua_BindFunctionsAndVariables(sol::state* state);

void EQAPP_Lua_Toggle()
{
    EQ_ToggleBool(g_LuaIsEnabled);
    EQAPP_PrintBool("Lua", g_LuaIsEnabled);

    EQAPP_Lua_ResetTimers();
}

void EQAPP_Lua_On()
{
    if (g_LuaIsEnabled == false)
    {
        EQAPP_Lua_Toggle();
    }
}

void EQAPP_Lua_Off()
{
    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_Toggle();
    }
}

void EQAPP_Lua_Load()
{
    EQAPP_Lua_OpenLibraries(&g_LuaState);
    EQAPP_Lua_BindFunctionsAndVariables(&g_LuaState);
}

void EQAPP_Lua_OpenLibraries(sol::state* state)
{
    state->open_libraries
    (
        sol::lib::base,
        sol::lib::package,
        sol::lib::coroutine,
        sol::lib::string,
        sol::lib::os,
        sol::lib::math,
        sol::lib::table,
        sol::lib::debug,
        sol::lib::bit32,
        sol::lib::io,
        sol::lib::ffi,
        sol::lib::jit
    );
}

void EQAPP_Lua_ResetTimers()
{
    g_LuaOneSecondTimer = EQAPP_Timer_GetTimeNow();

    g_LuaThreeSecondsTimer = EQAPP_Timer_GetTimeNow();

    g_LuaSixSecondsTimer = EQAPP_Timer_GetTimeNow();

    g_LuaOneMinuteTimer = EQAPP_Timer_GetTimeNow();

    g_LuaOneHourTimer = EQAPP_Timer_GetTimeNow();
}

void EQAPP_Lua_EventScriptList_Load()
{
    EQAPP_Lua_ResetTimers();

    g_LuaEventScriptList.clear();

    std::stringstream folderPath;
    folderPath << g_EQAppName << "/scripts/";

    for (auto& it : std__filesystem::directory_iterator(folderPath.str()))
    {
        if (it.path().extension().string() != ".lua")
        {
            continue;
        }

        std::string filename = it.path().filename().string();

        if (EQAPP_String_BeginsWith(filename, "event_") == false)
        {
            continue;
        }

        sol::state state;
        EQAPP_Lua_OpenLibraries(&state);
        EQAPP_Lua_BindFunctionsAndVariables(&state);

        bool result = EQAPP_Lua_ExecuteFile(&state, filename.c_str());
        if (result == false)
        {
            continue;
        }

        auto script = std::make_shared<EQApp::LuaEventScript>();
        script->Filename = filename;
        script->LuaState = std::move(state);

        g_LuaEventScriptList.push_back(std::move(script));
    }
}

void EQAPP_Lua_EventScriptList_Print()
{
    for (auto& script : g_LuaEventScriptList)
    {
        std::cout << script->Filename << std::endl;
    }
}

void EQAPP_Lua_EventScriptList_ExecuteFunction(const char* functionName)
{
    for (auto& script : g_LuaEventScriptList)
    {
        sol::protected_function luaFunction = script->LuaState[functionName];
        if (luaFunction.valid() == true)
        {
            sol::protected_function_result result = luaFunction();
            if (result.valid() == false)
            {
                std::cout << "Lua filename: " << script->Filename << std::endl;

                sol::error error = result;

                std::cout << "Lua error: " << error.what() << std::endl;
            }
        }
    }
}

void EQAPP_Lua_ScriptFolder_Print()
{
    std::stringstream folderPath;
    folderPath << g_EQAppName << "/scripts/";

    for (auto& it : std__filesystem::directory_iterator(folderPath.str()))
    {
        if (it.path().extension().string() != ".lua")
        {
            continue;
        }

        std::cout << it.path().filename().string() << std::endl;
    }
}

bool EQAPP_Lua_ExecuteCode(sol::state* state, const char* text)
{
    auto simpleHandler = [](lua_State*, sol::protected_function_result result)
    {
        return result;
    };

    sol::protected_function_result result = state->script(text, simpleHandler);
    if (result.valid() == false)
    {
        sol::error error = result;

        std::cout << "Lua error: " << error.what() << std::endl;
    }

    return result.valid();
}

bool EQAPP_Lua_ExecuteFile(sol::state* state, const char* filename)
{
    std::stringstream ss;
    ss << "scripts/" << filename;

    std::string fileContents = EQAPP_ReadFileToString(ss.str().c_str());
    if (fileContents.size() == 0)
    {
        return false;
    }

    bool result = EQAPP_Lua_ExecuteCode(state, fileContents.c_str());
    if (result == true)
    {
        ////std::cout << "Script executed: " << filename << std::endl;
    }
    else
    {
        std::cout << "Script failed to execute: " << filename << std::endl;
    }

    return result;
}

void EQAPP_Lua_BindFunctionsAndVariables(sol::state* state)
{
    // EQAPP functions
    state->set_function("EQAPP_Log", EQAPP_Log);

    state->set_function("EQAPP_EnableDebugPrivileges", EQAPP_EnableDebugPrivileges);
    state->set_function("EQAPP_IsForegroundWindowCurrentProcessID", EQAPP_IsForegroundWindowCurrentProcessID);
    state->set_function("EQAPP_IsVKKeyDown", EQAPP_IsVKKeyDown);
    state->set_function("EQAPP_GetRandomNumber", EQAPP_GetRandomNumber);
    state->set_function("EQAPP_PlaySound", EQAPP_PlaySound);
    state->set_function("EQAPP_StopSound", EQAPP_StopSound);
    state->set_function("EQAPP_Beep", EQAPP_Beep);
    state->set_function("EQAPP_BeepEx", EQAPP_BeepEx);
    state->set_function("EQAPP_IsInGame", EQAPP_IsInGame);
    state->set_function("EQAPP_CopyTextToClipboard", EQAPP_CopyTextToClipboard);
    state->set_function("EQAPP_PrintSpawnList", EQAPP_PrintSpawnList);
    state->set_function("EQAPP_PrintLocation", EQAPP_PrintLocation);

    // EQ constants
    state->set("EQ_WINDOW_TITLE_DEFAULT", EQ_WINDOW_TITLE_DEFAULT);
    state->set("EQ_PI", EQ_PI);

    state->set("EQ_SPAWN_TYPE_PLAYER", EQ_SPAWN_TYPE_PLAYER);
    state->set("EQ_SPAWN_TYPE_NPC", EQ_SPAWN_TYPE_NPC);
    state->set("EQ_SPAWN_TYPE_CORPSE", EQ_SPAWN_TYPE_CORPSE);

    state->set("EQ_STANDING_STATE_STANDING", EQ_STANDING_STATE_STANDING);
    state->set("EQ_STANDING_STATE_FROZEN" , EQ_STANDING_STATE_FROZEN);
    state->set("EQ_STANDING_STATE_KNEELING", EQ_STANDING_STATE_KNEELING);
    state->set("EQ_STANDING_STATE_SITTING", EQ_STANDING_STATE_SITTING);
    state->set("EQ_STANDING_STATE_DUCKING", EQ_STANDING_STATE_DUCKING);
    state->set("EQ_STANDING_STATE_FEIGN_DEATH", EQ_STANDING_STATE_FEIGN_DEATH);
    state->set("EQ_STANDING_STATE_DEAD", EQ_STANDING_STATE_DEAD);

    state->set("EQ_CAMERA_FIELD_OF_VIEW_DEFAULT", EQ_CAMERA_FIELD_OF_VIEW_DEFAULT);
    state->set("EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK", EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK);

    state->set("EQ_CHAT_TEXT_COLOR_WHITE_0", EQ_CHAT_TEXT_COLOR_WHITE_0);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT", EQ_CHAT_TEXT_COLOR_DEFAULT);
    state->set("EQ_CHAT_TEXT_COLOR_DARK_GREEN", EQ_CHAT_TEXT_COLOR_DARK_GREEN);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT_2", EQ_CHAT_TEXT_COLOR_DEFAULT_2);
    state->set("EQ_CHAT_TEXT_COLOR_DARK_BLUE", EQ_CHAT_TEXT_COLOR_DARK_BLUE);
    state->set("EQ_CHAT_TEXT_COLOR_PINK", EQ_CHAT_TEXT_COLOR_PINK);
    state->set("EQ_CHAT_TEXT_COLOR_DARK_GRAY", EQ_CHAT_TEXT_COLOR_DARK_GRAY);
    state->set("EQ_CHAT_TEXT_COLOR_WHITE_2", EQ_CHAT_TEXT_COLOR_WHITE_2);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT_3", EQ_CHAT_TEXT_COLOR_DEFAULT_3);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT_4", EQ_CHAT_TEXT_COLOR_DEFAULT_4);
    state->set("EQ_CHAT_TEXT_COLOR_WHITE", EQ_CHAT_TEXT_COLOR_WHITE);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT_5", EQ_CHAT_TEXT_COLOR_DEFAULT_5);
    state->set("EQ_CHAT_TEXT_COLOR_GRAY", EQ_CHAT_TEXT_COLOR_GRAY);
    state->set("EQ_CHAT_TEXT_COLOR_RED", EQ_CHAT_TEXT_COLOR_RED);
    state->set("EQ_CHAT_TEXT_COLOR_GREEN", EQ_CHAT_TEXT_COLOR_GREEN);
    state->set("EQ_CHAT_TEXT_COLOR_YELLOW", EQ_CHAT_TEXT_COLOR_YELLOW);
    state->set("EQ_CHAT_TEXT_COLOR_BLUE", EQ_CHAT_TEXT_COLOR_BLUE);
    state->set("EQ_CHAT_TEXT_COLOR_BLUE_2", EQ_CHAT_TEXT_COLOR_BLUE_2);
    state->set("EQ_CHAT_TEXT_COLOR_TEAL", EQ_CHAT_TEXT_COLOR_TEAL);
    state->set("EQ_CHAT_TEXT_COLOR_DEFAULT_6", EQ_CHAT_TEXT_COLOR_DEFAULT_6);
    state->set("EQ_CHAT_TEXT_COLOR_WHITE_20", EQ_CHAT_TEXT_COLOR_WHITE_20);
    state->set("EQ_CHAT_TEXT_COLOR_ORANGE", EQ_CHAT_TEXT_COLOR_ORANGE);
    state->set("EQ_CHAT_TEXT_COLOR_BROWN", EQ_CHAT_TEXT_COLOR_BROWN);

    state->set("EQ_DRAW_TEXT_COLOR_BLACK", EQ_DRAW_TEXT_COLOR_BLACK);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT", EQ_DRAW_TEXT_COLOR_DEFAULT);
    state->set("EQ_DRAW_TEXT_COLOR_DARK_GREEN", EQ_DRAW_TEXT_COLOR_DARK_GREEN);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT_2", EQ_DRAW_TEXT_COLOR_DEFAULT_2);
    state->set("EQ_DRAW_TEXT_COLOR_DARK_BLUE", EQ_DRAW_TEXT_COLOR_DARK_BLUE);
    state->set("EQ_DRAW_TEXT_COLOR_PINK", EQ_DRAW_TEXT_COLOR_PINK);
    state->set("EQ_DRAW_TEXT_COLOR_DARK_GRAY", EQ_DRAW_TEXT_COLOR_DARK_GRAY);
    state->set("EQ_DRAW_TEXT_COLOR_WHITE_2", EQ_DRAW_TEXT_COLOR_WHITE_2);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT_3", EQ_DRAW_TEXT_COLOR_DEFAULT_3);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT_4", EQ_DRAW_TEXT_COLOR_DEFAULT_4);
    state->set("EQ_DRAW_TEXT_COLOR_WHITE", EQ_DRAW_TEXT_COLOR_WHITE);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT_5", EQ_DRAW_TEXT_COLOR_DEFAULT_5);
    state->set("EQ_DRAW_TEXT_COLOR_GRAY", EQ_DRAW_TEXT_COLOR_GRAY);
    state->set("EQ_DRAW_TEXT_COLOR_RED", EQ_DRAW_TEXT_COLOR_RED);
    state->set("EQ_DRAW_TEXT_COLOR_GREEN", EQ_DRAW_TEXT_COLOR_GREEN);
    state->set("EQ_DRAW_TEXT_COLOR_YELLOW", EQ_DRAW_TEXT_COLOR_YELLOW);
    state->set("EQ_DRAW_TEXT_COLOR_BLUE", EQ_DRAW_TEXT_COLOR_BLUE);
    state->set("EQ_DRAW_TEXT_COLOR_BLUE_2", EQ_DRAW_TEXT_COLOR_BLUE_2);
    state->set("EQ_DRAW_TEXT_COLOR_TEAL", EQ_DRAW_TEXT_COLOR_TEAL);
    state->set("EQ_DRAW_TEXT_COLOR_DEFAULT_6", EQ_DRAW_TEXT_COLOR_DEFAULT_6);
    state->set("EQ_DRAW_TEXT_COLOR_BLACK_2", EQ_DRAW_TEXT_COLOR_BLACK_2);

    state->set("EQ_DIRECTION_NORTH", EQ_DIRECTION_NORTH);
    state->set("EQ_DIRECTION_NORTH_WEST", EQ_DIRECTION_NORTH_WEST);
    state->set("EQ_DIRECTION_NORTH_EAST", EQ_DIRECTION_NORTH_EAST);
    state->set("EQ_DIRECTION_SOUTH", EQ_DIRECTION_SOUTH);
    state->set("EQ_DIRECTION_SOUTH_WEST", EQ_DIRECTION_SOUTH_WEST);
    state->set("EQ_DIRECTION_SOUTH_EAST", EQ_DIRECTION_SOUTH_EAST);
    state->set("EQ_DIRECTION_WEST", EQ_DIRECTION_WEST);
    state->set("EQ_DIRECTION_EAST", EQ_DIRECTION_EAST);
    state->set("EQ_DIRECTION_UNKNOWN", EQ_DIRECTION_UNKNOWN);

    state->set("EQ_RACE_UNKNOWN", EQ_RACE_UNKNOWN);
    state->set("EQ_RACE_HUMAN", EQ_RACE_HUMAN);
    state->set("EQ_RACE_BARBARIAN", EQ_RACE_BARBARIAN);
    state->set("EQ_RACE_ERUDITE", EQ_RACE_ERUDITE);
    state->set("EQ_RACE_WOOD_ELF", EQ_RACE_WOOD_ELF);
    state->set("EQ_RACE_HIGH_ELF", EQ_RACE_HIGH_ELF);
    state->set("EQ_RACE_DARK_ELF", EQ_RACE_DARK_ELF);
    state->set("EQ_RACE_HALF_ELF", EQ_RACE_HALF_ELF);
    state->set("EQ_RACE_DWARF", EQ_RACE_DWARF);
    state->set("EQ_RACE_TROLL", EQ_RACE_TROLL);
    state->set("EQ_RACE_OGRE", EQ_RACE_OGRE);
    state->set("EQ_RACE_HALFLING", EQ_RACE_HALFLING);
    state->set("EQ_RACE_GNOME", EQ_RACE_GNOME);
    state->set("EQ_RACE_INVISIBLE_MAN", EQ_RACE_INVISIBLE_MAN);
    state->set("EQ_RACE_IKSAR", EQ_RACE_IKSAR);
    state->set("EQ_RACE_VAH_SHIR", EQ_RACE_VAH_SHIR);
    state->set("EQ_RACE_FROGLOK", EQ_RACE_FROGLOK);
    state->set("EQ_RACE_DRAKKIN", EQ_RACE_DRAKKIN);
    state->set("EQ_RACE_CAMPFIRE", EQ_RACE_CAMPFIRE);

    state->set("EQ_CLASS_UNKNOWN", EQ_CLASS_UNKNOWN);
    state->set("EQ_CLASS_WARRIOR", EQ_CLASS_WARRIOR);
    state->set("EQ_CLASS_CLERIC", EQ_CLASS_CLERIC);
    state->set("EQ_CLASS_PALADIN", EQ_CLASS_PALADIN);
    state->set("EQ_CLASS_RANGER", EQ_CLASS_RANGER);
    state->set("EQ_CLASS_SHADOWKNIGHT", EQ_CLASS_SHADOWKNIGHT);
    state->set("EQ_CLASS_DRUID", EQ_CLASS_DRUID);
    state->set("EQ_CLASS_MONK", EQ_CLASS_MONK);
    state->set("EQ_CLASS_BARD", EQ_CLASS_BARD);
    state->set("EQ_CLASS_ROGUE", EQ_CLASS_ROGUE);
    state->set("EQ_CLASS_SHAMAN", EQ_CLASS_SHAMAN);
    state->set("EQ_CLASS_NECROMANCER", EQ_CLASS_NECROMANCER);
    state->set("EQ_CLASS_WIZARD", EQ_CLASS_WIZARD);
    state->set("EQ_CLASS_MAGICIAN", EQ_CLASS_MAGICIAN);
    state->set("EQ_CLASS_ENCHANTER", EQ_CLASS_ENCHANTER);
    state->set("EQ_CLASS_BEASTLORD", EQ_CLASS_BEASTLORD);
    state->set("EQ_CLASS_BERSERKER", EQ_CLASS_BERSERKER);
    state->set("EQ_CLASS_MERCENARY", EQ_CLASS_MERCENARY);
    state->set("EQ_CLASS_WARRIOR_GM", EQ_CLASS_WARRIOR_GM);
    state->set("EQ_CLASS_CLERIC_GM", EQ_CLASS_CLERIC_GM);
    state->set("EQ_CLASS_PALADIN_GM", EQ_CLASS_PALADIN_GM);
    state->set("EQ_CLASS_RANGER_GM", EQ_CLASS_RANGER_GM);
    state->set("EQ_CLASS_SHADOWKNIGHT_GM", EQ_CLASS_SHADOWKNIGHT_GM);
    state->set("EQ_CLASS_DRUID_GM", EQ_CLASS_DRUID_GM);
    state->set("EQ_CLASS_MONK_GM", EQ_CLASS_MONK_GM);
    state->set("EQ_CLASS_BARD_GM", EQ_CLASS_BARD_GM);
    state->set("EQ_CLASS_ROGUE_GM", EQ_CLASS_ROGUE_GM);
    state->set("EQ_CLASS_SHAMAN_GM", EQ_CLASS_SHAMAN_GM);
    state->set("EQ_CLASS_NECROMANCER_GM", EQ_CLASS_NECROMANCER_GM);
    state->set("EQ_CLASS_WIZARD_GM", EQ_CLASS_WIZARD_GM);
    state->set("EQ_CLASS_MAGICIAN_GM", EQ_CLASS_MAGICIAN_GM);
    state->set("EQ_CLASS_ENCHANTER_GM", EQ_CLASS_ENCHANTER_GM);
    state->set("EQ_CLASS_BEASTLORD_GM", EQ_CLASS_BEASTLORD_GM);
    state->set("EQ_CLASS_BERSERKER_GM", EQ_CLASS_BERSERKER_GM);
    state->set("EQ_CLASS_BANKER", EQ_CLASS_BANKER);
    state->set("EQ_CLASS_MERCHANT", EQ_CLASS_MERCHANT);
    state->set("EQ_CLASS_OBJECT", EQ_CLASS_OBJECT);
    state->set("EQ_CLASS_GUILD_BANKER", EQ_CLASS_GUILD_BANKER);
    state->set("EQ_CLASS_FELLOWSHIP_REGISTRAR", EQ_CLASS_FELLOWSHIP_REGISTRAR);
    state->set("EQ_CLASS_FACTION_MERCHANT", EQ_CLASS_FACTION_MERCHANT);
    state->set("EQ_CLASS_MERCENARY_LIAISON", EQ_CLASS_MERCENARY_LIAISON);
    state->set("EQ_CLASS_REAL_ESTATE_MERCHANT", EQ_CLASS_REAL_ESTATE_MERCHANT);
    state->set("EQ_CLASS_LOYALTY_MERCHANT", EQ_CLASS_LOYALTY_MERCHANT);
    state->set("EQ_CLASS_TRIBUTE_MASTER", EQ_CLASS_TRIBUTE_MASTER);

    state->set("EQ_VK_ALT", EQ_VK_ALT);
    state->set("EQ_VK_LEFT_ALT", EQ_VK_LEFT_ALT);
    state->set("EQ_VK_RIGHT_ALT", EQ_VK_RIGHT_ALT);
    state->set("EQ_VK_PAGE_UP", EQ_VK_PAGE_UP);
    state->set("EQ_VK_PAGE_DOWN", EQ_VK_PAGE_DOWN);
    state->set("EQ_VK_0", EQ_VK_0);
    state->set("EQ_VK_1", EQ_VK_1);
    state->set("EQ_VK_2", EQ_VK_2);
    state->set("EQ_VK_3", EQ_VK_3);
    state->set("EQ_VK_4", EQ_VK_4);
    state->set("EQ_VK_5", EQ_VK_5);
    state->set("EQ_VK_6", EQ_VK_6);
    state->set("EQ_VK_7", EQ_VK_7);
    state->set("EQ_VK_8", EQ_VK_8);
    state->set("EQ_VK_9", EQ_VK_9);
    state->set("EQ_VK_A", EQ_VK_A); 
    state->set("EQ_VK_B", EQ_VK_B);
    state->set("EQ_VK_C", EQ_VK_C);
    state->set("EQ_VK_D", EQ_VK_D);
    state->set("EQ_VK_E", EQ_VK_E);
    state->set("EQ_VK_F", EQ_VK_F); 
    state->set("EQ_VK_G", EQ_VK_G);
    state->set("EQ_VK_H", EQ_VK_H);
    state->set("EQ_VK_I", EQ_VK_I);
    state->set("EQ_VK_J", EQ_VK_J);
    state->set("EQ_VK_K", EQ_VK_K);
    state->set("EQ_VK_L", EQ_VK_L); 
    state->set("EQ_VK_M", EQ_VK_M);
    state->set("EQ_VK_N", EQ_VK_N);
    state->set("EQ_VK_O", EQ_VK_O);
    state->set("EQ_VK_P", EQ_VK_P);
    state->set("EQ_VK_Q", EQ_VK_Q);
    state->set("EQ_VK_R", EQ_VK_R);
    state->set("EQ_VK_S", EQ_VK_S);
    state->set("EQ_VK_T", EQ_VK_T); 
    state->set("EQ_VK_U", EQ_VK_U);
    state->set("EQ_VK_V", EQ_VK_V);
    state->set("EQ_VK_W", EQ_VK_W);
    state->set("EQ_VK_X", EQ_VK_X);
    state->set("EQ_VK_Y", EQ_VK_Y);
    state->set("EQ_VK_Z", EQ_VK_Z);

    state->set("EQ_EXECUTECMD_AUTORUN", EQ_EXECUTECMD_AUTORUN);
    state->set("EQ_EXECUTECMD_JUMP", EQ_EXECUTECMD_JUMP);
    state->set("EQ_EXECUTECMD_FORWARD", EQ_EXECUTECMD_FORWARD);
    state->set("EQ_EXECUTECMD_BACK", EQ_EXECUTECMD_BACK);
    state->set("EQ_EXECUTECMD_RIGHT", EQ_EXECUTECMD_RIGHT);
    state->set("EQ_EXECUTECMD_LEFT", EQ_EXECUTECMD_LEFT);
    state->set("EQ_EXECUTECMD_STRAFE_LEFT", EQ_EXECUTECMD_STRAFE_LEFT);
    state->set("EQ_EXECUTECMD_STRAFE_RIGHT", EQ_EXECUTECMD_STRAFE_RIGHT);
    state->set("EQ_EXECUTECMD_MOUSELOOK", EQ_EXECUTECMD_MOUSELOOK);
    state->set("EQ_EXECUTECMD_MOUSELOOK_ENGAGE", EQ_EXECUTECMD_MOUSELOOK_ENGAGE);
    state->set("EQ_EXECUTECMD_AUTOPRIM", EQ_EXECUTECMD_AUTOPRIM);
    state->set("EQ_EXECUTECMD_CONSIDER", EQ_EXECUTECMD_CONSIDER);
    state->set("EQ_EXECUTECMD_DUCK", EQ_EXECUTECMD_DUCK);
    state->set("EQ_EXECUTECMD_HAIL", EQ_EXECUTECMD_HAIL);
    state->set("EQ_EXECUTECMD_INVENTORY", EQ_EXECUTECMD_INVENTORY);
    state->set("EQ_EXECUTECMD_TELL", EQ_EXECUTECMD_TELL);
    state->set("EQ_EXECUTECMD_USE", EQ_EXECUTECMD_USE);
    state->set("EQ_EXECUTECMD_PITCHUP", EQ_EXECUTECMD_PITCHUP);
    state->set("EQ_EXECUTECMD_PITCHDOWN", EQ_EXECUTECMD_PITCHDOWN);
    state->set("EQ_EXECUTECMD_CENTERVIEW", EQ_EXECUTECMD_CENTERVIEW);
    state->set("EQ_EXECUTECMD_ZOOMIN", EQ_EXECUTECMD_ZOOMIN);
    state->set("EQ_EXECUTECMD_ZOOMOUT", EQ_EXECUTECMD_ZOOMOUT);
    state->set("EQ_EXECUTECMD_TOGGLECAM", EQ_EXECUTECMD_TOGGLECAM);
    state->set("EQ_EXECUTECMD_FULLSCREEN", EQ_EXECUTECMD_FULLSCREEN);
    state->set("EQ_EXECUTECMD_TARGETME", EQ_EXECUTECMD_TARGETME);
    state->set("EQ_EXECUTECMD_PARTY1", EQ_EXECUTECMD_PARTY1);
    state->set("EQ_EXECUTECMD_PARTY2", EQ_EXECUTECMD_PARTY2);
    state->set("EQ_EXECUTECMD_PARTY3", EQ_EXECUTECMD_PARTY3);
    state->set("EQ_EXECUTECMD_PARTY4", EQ_EXECUTECMD_PARTY4);
    state->set("EQ_EXECUTECMD_PARTY5", EQ_EXECUTECMD_PARTY5);
    state->set("EQ_EXECUTECMD_TARGETPC", EQ_EXECUTECMD_TARGETPC);
    state->set("EQ_EXECUTECMD_CYCLEPCTARGETS", EQ_EXECUTECMD_CYCLEPCTARGETS);
    state->set("EQ_EXECUTECMD_TARGETNPC", EQ_EXECUTECMD_TARGETNPC);
    state->set("EQ_EXECUTECMD_CYCLENPCTARGETS", EQ_EXECUTECMD_CYCLENPCTARGETS);
    state->set("EQ_EXECUTECMD_TARGETCORPSE", EQ_EXECUTECMD_TARGETCORPSE);
    state->set("EQ_EXECUTECMD_CYCLECORPSETARGETS", EQ_EXECUTECMD_CYCLECORPSETARGETS);
    state->set("EQ_EXECUTECMD_NETSTAT", EQ_EXECUTECMD_NETSTAT);
    state->set("EQ_EXECUTECMD_HOT1_1", EQ_EXECUTECMD_HOT1_1);
    state->set("EQ_EXECUTECMD_HOT1_2", EQ_EXECUTECMD_HOT1_2);
    state->set("EQ_EXECUTECMD_HOT1_3", EQ_EXECUTECMD_HOT1_3);
    state->set("EQ_EXECUTECMD_HOT1_4", EQ_EXECUTECMD_HOT1_4);
    state->set("EQ_EXECUTECMD_HOT1_5", EQ_EXECUTECMD_HOT1_5);
    state->set("EQ_EXECUTECMD_HOT1_6", EQ_EXECUTECMD_HOT1_6);
    state->set("EQ_EXECUTECMD_HOT1_7", EQ_EXECUTECMD_HOT1_7);
    state->set("EQ_EXECUTECMD_HOT1_8", EQ_EXECUTECMD_HOT1_8);
    state->set("EQ_EXECUTECMD_HOT1_9", EQ_EXECUTECMD_HOT1_9);
    state->set("EQ_EXECUTECMD_HOT1_10", EQ_EXECUTECMD_HOT1_10);
    state->set("EQ_EXECUTECMD_HOT1_11", EQ_EXECUTECMD_HOT1_11);
    state->set("EQ_EXECUTECMD_HOT1_12", EQ_EXECUTECMD_HOT1_12);
    state->set("EQ_EXECUTECMD_HOT2_1", EQ_EXECUTECMD_HOT2_1);
    state->set("EQ_EXECUTECMD_HOT2_2", EQ_EXECUTECMD_HOT2_2);
    state->set("EQ_EXECUTECMD_HOT2_3", EQ_EXECUTECMD_HOT2_3);
    state->set("EQ_EXECUTECMD_HOT2_4", EQ_EXECUTECMD_HOT2_4);
    state->set("EQ_EXECUTECMD_HOT2_5", EQ_EXECUTECMD_HOT2_5);
    state->set("EQ_EXECUTECMD_HOT2_6", EQ_EXECUTECMD_HOT2_6);
    state->set("EQ_EXECUTECMD_HOT2_7", EQ_EXECUTECMD_HOT2_7);
    state->set("EQ_EXECUTECMD_HOT2_8", EQ_EXECUTECMD_HOT2_8);
    state->set("EQ_EXECUTECMD_HOT2_9", EQ_EXECUTECMD_HOT2_9);
    state->set("EQ_EXECUTECMD_HOT2_10", EQ_EXECUTECMD_HOT2_10);
    state->set("EQ_EXECUTECMD_HOT2_11", EQ_EXECUTECMD_HOT2_11);
    state->set("EQ_EXECUTECMD_HOT2_12", EQ_EXECUTECMD_HOT2_12);
    state->set("EQ_EXECUTECMD_HOT3_1", EQ_EXECUTECMD_HOT3_1);
    state->set("EQ_EXECUTECMD_HOT3_2", EQ_EXECUTECMD_HOT3_2);
    state->set("EQ_EXECUTECMD_HOT3_3", EQ_EXECUTECMD_HOT3_3);
    state->set("EQ_EXECUTECMD_HOT3_4", EQ_EXECUTECMD_HOT3_4);
    state->set("EQ_EXECUTECMD_HOT3_5", EQ_EXECUTECMD_HOT3_5);
    state->set("EQ_EXECUTECMD_HOT3_6", EQ_EXECUTECMD_HOT3_6);
    state->set("EQ_EXECUTECMD_HOT3_7", EQ_EXECUTECMD_HOT3_7);
    state->set("EQ_EXECUTECMD_HOT3_8", EQ_EXECUTECMD_HOT3_8);
    state->set("EQ_EXECUTECMD_HOT3_9", EQ_EXECUTECMD_HOT3_9);
    state->set("EQ_EXECUTECMD_HOT3_10", EQ_EXECUTECMD_HOT3_10);
    state->set("EQ_EXECUTECMD_HOT3_11", EQ_EXECUTECMD_HOT3_11);
    state->set("EQ_EXECUTECMD_HOT3_12", EQ_EXECUTECMD_HOT3_12);
    state->set("EQ_EXECUTECMD_HOT4_1", EQ_EXECUTECMD_HOT4_1);
    state->set("EQ_EXECUTECMD_HOT4_2", EQ_EXECUTECMD_HOT4_2);
    state->set("EQ_EXECUTECMD_HOT4_3", EQ_EXECUTECMD_HOT4_3);
    state->set("EQ_EXECUTECMD_HOT4_4", EQ_EXECUTECMD_HOT4_4);
    state->set("EQ_EXECUTECMD_HOT4_5", EQ_EXECUTECMD_HOT4_5);
    state->set("EQ_EXECUTECMD_HOT4_6", EQ_EXECUTECMD_HOT4_6);
    state->set("EQ_EXECUTECMD_HOT4_7", EQ_EXECUTECMD_HOT4_7);
    state->set("EQ_EXECUTECMD_HOT4_8", EQ_EXECUTECMD_HOT4_8);
    state->set("EQ_EXECUTECMD_HOT4_9", EQ_EXECUTECMD_HOT4_9);
    state->set("EQ_EXECUTECMD_HOT4_10", EQ_EXECUTECMD_HOT4_10);
    state->set("EQ_EXECUTECMD_HOT4_11", EQ_EXECUTECMD_HOT4_11);
    state->set("EQ_EXECUTECMD_HOT4_12", EQ_EXECUTECMD_HOT4_12);
    state->set("EQ_EXECUTECMD_HOT5_1", EQ_EXECUTECMD_HOT5_1);
    state->set("EQ_EXECUTECMD_HOT5_2", EQ_EXECUTECMD_HOT5_2);
    state->set("EQ_EXECUTECMD_HOT5_3", EQ_EXECUTECMD_HOT5_3);
    state->set("EQ_EXECUTECMD_HOT5_4", EQ_EXECUTECMD_HOT5_4);
    state->set("EQ_EXECUTECMD_HOT5_5", EQ_EXECUTECMD_HOT5_5);
    state->set("EQ_EXECUTECMD_HOT5_6", EQ_EXECUTECMD_HOT5_6);
    state->set("EQ_EXECUTECMD_HOT5_7", EQ_EXECUTECMD_HOT5_7);
    state->set("EQ_EXECUTECMD_HOT5_8", EQ_EXECUTECMD_HOT5_8);
    state->set("EQ_EXECUTECMD_HOT5_9", EQ_EXECUTECMD_HOT5_9);
    state->set("EQ_EXECUTECMD_HOT5_10", EQ_EXECUTECMD_HOT5_10);
    state->set("EQ_EXECUTECMD_HOT5_11", EQ_EXECUTECMD_HOT5_11);
    state->set("EQ_EXECUTECMD_HOT5_12", EQ_EXECUTECMD_HOT5_12);
    state->set("EQ_EXECUTECMD_HOT6_1", EQ_EXECUTECMD_HOT6_1);
    state->set("EQ_EXECUTECMD_HOT6_2", EQ_EXECUTECMD_HOT6_2);
    state->set("EQ_EXECUTECMD_HOT6_3", EQ_EXECUTECMD_HOT6_3);
    state->set("EQ_EXECUTECMD_HOT6_4", EQ_EXECUTECMD_HOT6_4);
    state->set("EQ_EXECUTECMD_HOT6_5", EQ_EXECUTECMD_HOT6_5);
    state->set("EQ_EXECUTECMD_HOT6_6", EQ_EXECUTECMD_HOT6_6);
    state->set("EQ_EXECUTECMD_HOT6_7", EQ_EXECUTECMD_HOT6_7);
    state->set("EQ_EXECUTECMD_HOT6_8", EQ_EXECUTECMD_HOT6_8);
    state->set("EQ_EXECUTECMD_HOT6_9", EQ_EXECUTECMD_HOT6_9);
    state->set("EQ_EXECUTECMD_HOT6_10", EQ_EXECUTECMD_HOT6_10);
    state->set("EQ_EXECUTECMD_HOT6_11", EQ_EXECUTECMD_HOT6_11);
    state->set("EQ_EXECUTECMD_HOT6_12", EQ_EXECUTECMD_HOT6_12);
    state->set("EQ_EXECUTECMD_HOT7_1", EQ_EXECUTECMD_HOT7_1);
    state->set("EQ_EXECUTECMD_HOT7_2", EQ_EXECUTECMD_HOT7_2);
    state->set("EQ_EXECUTECMD_HOT7_3", EQ_EXECUTECMD_HOT7_3);
    state->set("EQ_EXECUTECMD_HOT7_4", EQ_EXECUTECMD_HOT7_4);
    state->set("EQ_EXECUTECMD_HOT7_5", EQ_EXECUTECMD_HOT7_5);
    state->set("EQ_EXECUTECMD_HOT7_6", EQ_EXECUTECMD_HOT7_6);
    state->set("EQ_EXECUTECMD_HOT7_7", EQ_EXECUTECMD_HOT7_7);
    state->set("EQ_EXECUTECMD_HOT7_8", EQ_EXECUTECMD_HOT7_8);
    state->set("EQ_EXECUTECMD_HOT7_9", EQ_EXECUTECMD_HOT7_9);
    state->set("EQ_EXECUTECMD_HOT7_10", EQ_EXECUTECMD_HOT7_10);
    state->set("EQ_EXECUTECMD_HOT7_11", EQ_EXECUTECMD_HOT7_11);
    state->set("EQ_EXECUTECMD_HOT7_12", EQ_EXECUTECMD_HOT7_12);
    state->set("EQ_EXECUTECMD_HOT8_1", EQ_EXECUTECMD_HOT8_1);
    state->set("EQ_EXECUTECMD_HOT8_2", EQ_EXECUTECMD_HOT8_2);
    state->set("EQ_EXECUTECMD_HOT8_3", EQ_EXECUTECMD_HOT8_3);
    state->set("EQ_EXECUTECMD_HOT8_4", EQ_EXECUTECMD_HOT8_4);
    state->set("EQ_EXECUTECMD_HOT8_5", EQ_EXECUTECMD_HOT8_5);
    state->set("EQ_EXECUTECMD_HOT8_6", EQ_EXECUTECMD_HOT8_6);
    state->set("EQ_EXECUTECMD_HOT8_7", EQ_EXECUTECMD_HOT8_7);
    state->set("EQ_EXECUTECMD_HOT8_8", EQ_EXECUTECMD_HOT8_8);
    state->set("EQ_EXECUTECMD_HOT8_9", EQ_EXECUTECMD_HOT8_9);
    state->set("EQ_EXECUTECMD_HOT8_10", EQ_EXECUTECMD_HOT8_10);
    state->set("EQ_EXECUTECMD_HOT8_11", EQ_EXECUTECMD_HOT8_11);
    state->set("EQ_EXECUTECMD_HOT8_12", EQ_EXECUTECMD_HOT8_12);
    state->set("EQ_EXECUTECMD_HOT9_1", EQ_EXECUTECMD_HOT9_1);
    state->set("EQ_EXECUTECMD_HOT9_2", EQ_EXECUTECMD_HOT9_2);
    state->set("EQ_EXECUTECMD_HOT9_3", EQ_EXECUTECMD_HOT9_3);
    state->set("EQ_EXECUTECMD_HOT9_4", EQ_EXECUTECMD_HOT9_4);
    state->set("EQ_EXECUTECMD_HOT9_5", EQ_EXECUTECMD_HOT9_5);
    state->set("EQ_EXECUTECMD_HOT9_6", EQ_EXECUTECMD_HOT9_6);
    state->set("EQ_EXECUTECMD_HOT9_7", EQ_EXECUTECMD_HOT9_7);
    state->set("EQ_EXECUTECMD_HOT9_8", EQ_EXECUTECMD_HOT9_8);
    state->set("EQ_EXECUTECMD_HOT9_9", EQ_EXECUTECMD_HOT9_9);
    state->set("EQ_EXECUTECMD_HOT9_10", EQ_EXECUTECMD_HOT9_10);
    state->set("EQ_EXECUTECMD_HOT9_11", EQ_EXECUTECMD_HOT9_11);
    state->set("EQ_EXECUTECMD_HOT9_12", EQ_EXECUTECMD_HOT9_12);
    state->set("EQ_EXECUTECMD_HOT10_1", EQ_EXECUTECMD_HOT10_1);
    state->set("EQ_EXECUTECMD_HOT10_2", EQ_EXECUTECMD_HOT10_2);
    state->set("EQ_EXECUTECMD_HOT10_3", EQ_EXECUTECMD_HOT10_3);
    state->set("EQ_EXECUTECMD_HOT10_4", EQ_EXECUTECMD_HOT10_4);
    state->set("EQ_EXECUTECMD_HOT10_5", EQ_EXECUTECMD_HOT10_5);
    state->set("EQ_EXECUTECMD_HOT10_6", EQ_EXECUTECMD_HOT10_6);
    state->set("EQ_EXECUTECMD_HOT10_7", EQ_EXECUTECMD_HOT10_7);
    state->set("EQ_EXECUTECMD_HOT10_8", EQ_EXECUTECMD_HOT10_8);
    state->set("EQ_EXECUTECMD_HOT10_9", EQ_EXECUTECMD_HOT10_9);
    state->set("EQ_EXECUTECMD_HOT10_10", EQ_EXECUTECMD_HOT10_10);
    state->set("EQ_EXECUTECMD_HOT10_11", EQ_EXECUTECMD_HOT10_11);
    state->set("EQ_EXECUTECMD_HOT10_12", EQ_EXECUTECMD_HOT10_12);
    state->set("EQ_EXECUTECMD_HOT11_1", EQ_EXECUTECMD_HOT11_1);
    state->set("EQ_EXECUTECMD_HOT11_2", EQ_EXECUTECMD_HOT11_2);
    state->set("EQ_EXECUTECMD_HOT11_3", EQ_EXECUTECMD_HOT11_3);
    state->set("EQ_EXECUTECMD_HOT11_4", EQ_EXECUTECMD_HOT11_4);
    state->set("EQ_EXECUTECMD_HOT11_5", EQ_EXECUTECMD_HOT11_5);
    state->set("EQ_EXECUTECMD_HOT11_6", EQ_EXECUTECMD_HOT11_6);
    state->set("EQ_EXECUTECMD_HOT11_7", EQ_EXECUTECMD_HOT11_7);
    state->set("EQ_EXECUTECMD_HOT11_8", EQ_EXECUTECMD_HOT11_8);
    state->set("EQ_EXECUTECMD_HOT11_9", EQ_EXECUTECMD_HOT11_9);
    state->set("EQ_EXECUTECMD_HOT11_10", EQ_EXECUTECMD_HOT11_10);
    state->set("EQ_EXECUTECMD_HOT11_11", EQ_EXECUTECMD_HOT11_11);
    state->set("EQ_EXECUTECMD_HOT11_12", EQ_EXECUTECMD_HOT11_12);
    state->set("EQ_EXECUTECMD_HOTPAGE1_1", EQ_EXECUTECMD_HOTPAGE1_1);
    state->set("EQ_EXECUTECMD_HOTPAGE1_2", EQ_EXECUTECMD_HOTPAGE1_2);
    state->set("EQ_EXECUTECMD_HOTPAGE1_3", EQ_EXECUTECMD_HOTPAGE1_3);
    state->set("EQ_EXECUTECMD_HOTPAGE1_4", EQ_EXECUTECMD_HOTPAGE1_4);
    state->set("EQ_EXECUTECMD_HOTPAGE1_5", EQ_EXECUTECMD_HOTPAGE1_5);
    state->set("EQ_EXECUTECMD_HOTPAGE1_6", EQ_EXECUTECMD_HOTPAGE1_6);
    state->set("EQ_EXECUTECMD_HOTPAGE1_7", EQ_EXECUTECMD_HOTPAGE1_7);
    state->set("EQ_EXECUTECMD_HOTPAGE1_8", EQ_EXECUTECMD_HOTPAGE1_8);
    state->set("EQ_EXECUTECMD_HOTPAGE1_9", EQ_EXECUTECMD_HOTPAGE1_9);
    state->set("EQ_EXECUTECMD_HOTPAGE1_10", EQ_EXECUTECMD_HOTPAGE1_10);
    state->set("EQ_EXECUTECMD_HOTPAGE2_1", EQ_EXECUTECMD_HOTPAGE2_1);
    state->set("EQ_EXECUTECMD_HOTPAGE2_2", EQ_EXECUTECMD_HOTPAGE2_2);
    state->set("EQ_EXECUTECMD_HOTPAGE2_3", EQ_EXECUTECMD_HOTPAGE2_3);
    state->set("EQ_EXECUTECMD_HOTPAGE2_4", EQ_EXECUTECMD_HOTPAGE2_4);
    state->set("EQ_EXECUTECMD_HOTPAGE2_5", EQ_EXECUTECMD_HOTPAGE2_5);
    state->set("EQ_EXECUTECMD_HOTPAGE2_6", EQ_EXECUTECMD_HOTPAGE2_6);
    state->set("EQ_EXECUTECMD_HOTPAGE2_7", EQ_EXECUTECMD_HOTPAGE2_7);
    state->set("EQ_EXECUTECMD_HOTPAGE2_8", EQ_EXECUTECMD_HOTPAGE2_8);
    state->set("EQ_EXECUTECMD_HOTPAGE2_9", EQ_EXECUTECMD_HOTPAGE2_9);
    state->set("EQ_EXECUTECMD_HOTPAGE2_10", EQ_EXECUTECMD_HOTPAGE2_10);
    state->set("EQ_EXECUTECMD_HOTPAGE3_1", EQ_EXECUTECMD_HOTPAGE3_1);
    state->set("EQ_EXECUTECMD_HOTPAGE3_2", EQ_EXECUTECMD_HOTPAGE3_2);
    state->set("EQ_EXECUTECMD_HOTPAGE3_3", EQ_EXECUTECMD_HOTPAGE3_3);
    state->set("EQ_EXECUTECMD_HOTPAGE3_4", EQ_EXECUTECMD_HOTPAGE3_4);
    state->set("EQ_EXECUTECMD_HOTPAGE3_5", EQ_EXECUTECMD_HOTPAGE3_5);
    state->set("EQ_EXECUTECMD_HOTPAGE3_6", EQ_EXECUTECMD_HOTPAGE3_6);
    state->set("EQ_EXECUTECMD_HOTPAGE3_7", EQ_EXECUTECMD_HOTPAGE3_7);
    state->set("EQ_EXECUTECMD_HOTPAGE3_8", EQ_EXECUTECMD_HOTPAGE3_8);
    state->set("EQ_EXECUTECMD_HOTPAGE3_9", EQ_EXECUTECMD_HOTPAGE3_9);
    state->set("EQ_EXECUTECMD_HOTPAGE3_10", EQ_EXECUTECMD_HOTPAGE3_10);
    state->set("EQ_EXECUTECMD_HOTPAGE4_1", EQ_EXECUTECMD_HOTPAGE4_1);
    state->set("EQ_EXECUTECMD_HOTPAGE4_2", EQ_EXECUTECMD_HOTPAGE4_2);
    state->set("EQ_EXECUTECMD_HOTPAGE4_3", EQ_EXECUTECMD_HOTPAGE4_3);
    state->set("EQ_EXECUTECMD_HOTPAGE4_4", EQ_EXECUTECMD_HOTPAGE4_4);
    state->set("EQ_EXECUTECMD_HOTPAGE4_5", EQ_EXECUTECMD_HOTPAGE4_5);
    state->set("EQ_EXECUTECMD_HOTPAGE4_6", EQ_EXECUTECMD_HOTPAGE4_6);
    state->set("EQ_EXECUTECMD_HOTPAGE4_7", EQ_EXECUTECMD_HOTPAGE4_7);
    state->set("EQ_EXECUTECMD_HOTPAGE4_8", EQ_EXECUTECMD_HOTPAGE4_8);
    state->set("EQ_EXECUTECMD_HOTPAGE4_9", EQ_EXECUTECMD_HOTPAGE4_9);
    state->set("EQ_EXECUTECMD_HOTPAGE4_10", EQ_EXECUTECMD_HOTPAGE4_10);
    state->set("EQ_EXECUTECMD_HOTPAGE5_1", EQ_EXECUTECMD_HOTPAGE5_1);
    state->set("EQ_EXECUTECMD_HOTPAGE5_2", EQ_EXECUTECMD_HOTPAGE5_2);
    state->set("EQ_EXECUTECMD_HOTPAGE5_3", EQ_EXECUTECMD_HOTPAGE5_3);
    state->set("EQ_EXECUTECMD_HOTPAGE5_4", EQ_EXECUTECMD_HOTPAGE5_4);
    state->set("EQ_EXECUTECMD_HOTPAGE5_5", EQ_EXECUTECMD_HOTPAGE5_5);
    state->set("EQ_EXECUTECMD_HOTPAGE5_6", EQ_EXECUTECMD_HOTPAGE5_6);
    state->set("EQ_EXECUTECMD_HOTPAGE5_7", EQ_EXECUTECMD_HOTPAGE5_7);
    state->set("EQ_EXECUTECMD_HOTPAGE5_8", EQ_EXECUTECMD_HOTPAGE5_8);
    state->set("EQ_EXECUTECMD_HOTPAGE5_9", EQ_EXECUTECMD_HOTPAGE5_9);
    state->set("EQ_EXECUTECMD_HOTPAGE5_10", EQ_EXECUTECMD_HOTPAGE5_10);
    state->set("EQ_EXECUTECMD_HOTPAGE6_1", EQ_EXECUTECMD_HOTPAGE6_1);
    state->set("EQ_EXECUTECMD_HOTPAGE6_2", EQ_EXECUTECMD_HOTPAGE6_2);
    state->set("EQ_EXECUTECMD_HOTPAGE6_3", EQ_EXECUTECMD_HOTPAGE6_3);
    state->set("EQ_EXECUTECMD_HOTPAGE6_4", EQ_EXECUTECMD_HOTPAGE6_4);
    state->set("EQ_EXECUTECMD_HOTPAGE6_5", EQ_EXECUTECMD_HOTPAGE6_5);
    state->set("EQ_EXECUTECMD_HOTPAGE6_6", EQ_EXECUTECMD_HOTPAGE6_6);
    state->set("EQ_EXECUTECMD_HOTPAGE6_7", EQ_EXECUTECMD_HOTPAGE6_7);
    state->set("EQ_EXECUTECMD_HOTPAGE6_8", EQ_EXECUTECMD_HOTPAGE6_8);
    state->set("EQ_EXECUTECMD_HOTPAGE6_9", EQ_EXECUTECMD_HOTPAGE6_9);
    state->set("EQ_EXECUTECMD_HOTPAGE6_10", EQ_EXECUTECMD_HOTPAGE6_10);
    state->set("EQ_EXECUTECMD_HOTPAGE7_1", EQ_EXECUTECMD_HOTPAGE7_1);
    state->set("EQ_EXECUTECMD_HOTPAGE7_2", EQ_EXECUTECMD_HOTPAGE7_2);
    state->set("EQ_EXECUTECMD_HOTPAGE7_3", EQ_EXECUTECMD_HOTPAGE7_3);
    state->set("EQ_EXECUTECMD_HOTPAGE7_4", EQ_EXECUTECMD_HOTPAGE7_4);
    state->set("EQ_EXECUTECMD_HOTPAGE7_5", EQ_EXECUTECMD_HOTPAGE7_5);
    state->set("EQ_EXECUTECMD_HOTPAGE7_6", EQ_EXECUTECMD_HOTPAGE7_6);
    state->set("EQ_EXECUTECMD_HOTPAGE7_7", EQ_EXECUTECMD_HOTPAGE7_7);
    state->set("EQ_EXECUTECMD_HOTPAGE7_8", EQ_EXECUTECMD_HOTPAGE7_8);
    state->set("EQ_EXECUTECMD_HOTPAGE7_9", EQ_EXECUTECMD_HOTPAGE7_9);
    state->set("EQ_EXECUTECMD_HOTPAGE7_10", EQ_EXECUTECMD_HOTPAGE7_10);
    state->set("EQ_EXECUTECMD_HOTPAGE8_1", EQ_EXECUTECMD_HOTPAGE8_1);
    state->set("EQ_EXECUTECMD_HOTPAGE8_2", EQ_EXECUTECMD_HOTPAGE8_2);
    state->set("EQ_EXECUTECMD_HOTPAGE8_3", EQ_EXECUTECMD_HOTPAGE8_3);
    state->set("EQ_EXECUTECMD_HOTPAGE8_4", EQ_EXECUTECMD_HOTPAGE8_4);
    state->set("EQ_EXECUTECMD_HOTPAGE8_5", EQ_EXECUTECMD_HOTPAGE8_5);
    state->set("EQ_EXECUTECMD_HOTPAGE8_6", EQ_EXECUTECMD_HOTPAGE8_6);
    state->set("EQ_EXECUTECMD_HOTPAGE8_7", EQ_EXECUTECMD_HOTPAGE8_7);
    state->set("EQ_EXECUTECMD_HOTPAGE8_8", EQ_EXECUTECMD_HOTPAGE8_8);
    state->set("EQ_EXECUTECMD_HOTPAGE8_9", EQ_EXECUTECMD_HOTPAGE8_9);
    state->set("EQ_EXECUTECMD_HOTPAGE8_10", EQ_EXECUTECMD_HOTPAGE8_10);
    state->set("EQ_EXECUTECMD_HOTPAGE9_1", EQ_EXECUTECMD_HOTPAGE9_1);
    state->set("EQ_EXECUTECMD_HOTPAGE9_2", EQ_EXECUTECMD_HOTPAGE9_2);
    state->set("EQ_EXECUTECMD_HOTPAGE9_3", EQ_EXECUTECMD_HOTPAGE9_3);
    state->set("EQ_EXECUTECMD_HOTPAGE9_4", EQ_EXECUTECMD_HOTPAGE9_4);
    state->set("EQ_EXECUTECMD_HOTPAGE9_5", EQ_EXECUTECMD_HOTPAGE9_5);
    state->set("EQ_EXECUTECMD_HOTPAGE9_6", EQ_EXECUTECMD_HOTPAGE9_6);
    state->set("EQ_EXECUTECMD_HOTPAGE9_7", EQ_EXECUTECMD_HOTPAGE9_7);
    state->set("EQ_EXECUTECMD_HOTPAGE9_8", EQ_EXECUTECMD_HOTPAGE9_8);
    state->set("EQ_EXECUTECMD_HOTPAGE9_9", EQ_EXECUTECMD_HOTPAGE9_9);
    state->set("EQ_EXECUTECMD_HOTPAGE9_10", EQ_EXECUTECMD_HOTPAGE9_10);
    state->set("EQ_EXECUTECMD_HOTPAGE10_1", EQ_EXECUTECMD_HOTPAGE10_1);
    state->set("EQ_EXECUTECMD_HOTPAGE10_2", EQ_EXECUTECMD_HOTPAGE10_2);
    state->set("EQ_EXECUTECMD_HOTPAGE10_3", EQ_EXECUTECMD_HOTPAGE10_3);
    state->set("EQ_EXECUTECMD_HOTPAGE10_4", EQ_EXECUTECMD_HOTPAGE10_4);
    state->set("EQ_EXECUTECMD_HOTPAGE10_5", EQ_EXECUTECMD_HOTPAGE10_5);
    state->set("EQ_EXECUTECMD_HOTPAGE10_6", EQ_EXECUTECMD_HOTPAGE10_6);
    state->set("EQ_EXECUTECMD_HOTPAGE10_7", EQ_EXECUTECMD_HOTPAGE10_7);
    state->set("EQ_EXECUTECMD_HOTPAGE10_8", EQ_EXECUTECMD_HOTPAGE10_8);
    state->set("EQ_EXECUTECMD_HOTPAGE10_9", EQ_EXECUTECMD_HOTPAGE10_9);
    state->set("EQ_EXECUTECMD_HOTPAGE10_10", EQ_EXECUTECMD_HOTPAGE10_10);
    state->set("EQ_EXECUTECMD_HOTPAGE11_1", EQ_EXECUTECMD_HOTPAGE11_1);
    state->set("EQ_EXECUTECMD_HOTPAGE11_2", EQ_EXECUTECMD_HOTPAGE11_2);
    state->set("EQ_EXECUTECMD_HOTPAGE11_3", EQ_EXECUTECMD_HOTPAGE11_3);
    state->set("EQ_EXECUTECMD_HOTPAGE11_4", EQ_EXECUTECMD_HOTPAGE11_4);
    state->set("EQ_EXECUTECMD_HOTPAGE11_5", EQ_EXECUTECMD_HOTPAGE11_5);
    state->set("EQ_EXECUTECMD_HOTPAGE11_6", EQ_EXECUTECMD_HOTPAGE11_6);
    state->set("EQ_EXECUTECMD_HOTPAGE11_7", EQ_EXECUTECMD_HOTPAGE11_7);
    state->set("EQ_EXECUTECMD_HOTPAGE11_8", EQ_EXECUTECMD_HOTPAGE11_8);
    state->set("EQ_EXECUTECMD_HOTPAGE11_9", EQ_EXECUTECMD_HOTPAGE11_9);
    state->set("EQ_EXECUTECMD_HOTPAGE11_10", EQ_EXECUTECMD_HOTPAGE11_10);
    state->set("EQ_EXECUTECMD_CAST1", EQ_EXECUTECMD_CAST1);
    state->set("EQ_EXECUTECMD_CAST2", EQ_EXECUTECMD_CAST2);
    state->set("EQ_EXECUTECMD_CAST3", EQ_EXECUTECMD_CAST3);
    state->set("EQ_EXECUTECMD_CAST4", EQ_EXECUTECMD_CAST4);
    state->set("EQ_EXECUTECMD_CAST5", EQ_EXECUTECMD_CAST5);
    state->set("EQ_EXECUTECMD_CAST6", EQ_EXECUTECMD_CAST6);
    state->set("EQ_EXECUTECMD_CAST7", EQ_EXECUTECMD_CAST7);
    state->set("EQ_EXECUTECMD_CAST8", EQ_EXECUTECMD_CAST8);
    state->set("EQ_EXECUTECMD_CAST9", EQ_EXECUTECMD_CAST9);
    state->set("EQ_EXECUTECMD_CAST10", EQ_EXECUTECMD_CAST10);
    state->set("EQ_EXECUTECMD_CAST11", EQ_EXECUTECMD_CAST11);
    state->set("EQ_EXECUTECMD_CAST12", EQ_EXECUTECMD_CAST12);
    state->set("EQ_EXECUTECMD_CAST13", EQ_EXECUTECMD_CAST13);
    state->set("EQ_EXECUTECMD_CAST14", EQ_EXECUTECMD_CAST14);
    state->set("EQ_EXECUTECMD_REPLY", EQ_EXECUTECMD_REPLY);
    state->set("EQ_EXECUTECMD_CYCLEREPLY", EQ_EXECUTECMD_CYCLEREPLY);
    state->set("EQ_EXECUTECMD_CYCLEREPLY_BACK", EQ_EXECUTECMD_CYCLEREPLY_BACK);
    state->set("EQ_EXECUTECMD_BACKDROP", EQ_EXECUTECMD_BACKDROP);
    state->set("EQ_EXECUTECMD_TOGGLETARGET", EQ_EXECUTECMD_TOGGLETARGET);
    state->set("EQ_EXECUTECMD_SPELLBOOK", EQ_EXECUTECMD_SPELLBOOK);
    state->set("EQ_EXECUTECMD_ABILITIES", EQ_EXECUTECMD_ABILITIES);
    state->set("EQ_EXECUTECMD_COMBAT", EQ_EXECUTECMD_COMBAT);
    state->set("EQ_EXECUTECMD_SOCIALS", EQ_EXECUTECMD_SOCIALS);
    state->set("EQ_EXECUTECMD_MAIN", EQ_EXECUTECMD_MAIN);
    state->set("EQ_EXECUTECMD_WHO", EQ_EXECUTECMD_WHO);
    state->set("EQ_EXECUTECMD_INVITE_FOLLOW", EQ_EXECUTECMD_INVITE_FOLLOW);
    state->set("EQ_EXECUTECMD_DISBAND", EQ_EXECUTECMD_DISBAND);
    state->set("EQ_EXECUTECMD_CAMP", EQ_EXECUTECMD_CAMP);
    state->set("EQ_EXECUTECMD_SIT_STAND", EQ_EXECUTECMD_SIT_STAND);
    state->set("EQ_EXECUTECMD_RUN_WALK", EQ_EXECUTECMD_RUN_WALK);
    state->set("EQ_EXECUTECMD_CLIP_IN", EQ_EXECUTECMD_CLIP_IN);
    state->set("EQ_EXECUTECMD_CLIP_OUT", EQ_EXECUTECMD_CLIP_OUT);
    state->set("EQ_EXECUTECMD_VOICE_ON", EQ_EXECUTECMD_VOICE_ON);
    state->set("EQ_EXECUTECMD_SCREENCAP", EQ_EXECUTECMD_SCREENCAP);
    state->set("EQ_EXECUTECMD_HISTORY_UP", EQ_EXECUTECMD_HISTORY_UP);
    state->set("EQ_EXECUTECMD_HISTORY_DOWN", EQ_EXECUTECMD_HISTORY_DOWN);
    state->set("EQ_EXECUTECMD_PAGEUP", EQ_EXECUTECMD_PAGEUP);
    state->set("EQ_EXECUTECMD_PAGEDOWN", EQ_EXECUTECMD_PAGEDOWN);
    state->set("EQ_EXECUTECMD_CMDMODE_SAY", EQ_EXECUTECMD_CMDMODE_SAY);
    state->set("EQ_EXECUTECMD_CMDMODE_EMOTE", EQ_EXECUTECMD_CMDMODE_EMOTE);
    state->set("EQ_EXECUTECMD_LOCK_WINDOWS", EQ_EXECUTECMD_LOCK_WINDOWS);
    state->set("EQ_EXECUTECMD_TOGGLE_PLAYERWIN", EQ_EXECUTECMD_TOGGLE_PLAYERWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_PARTYWIN", EQ_EXECUTECMD_TOGGLE_PARTYWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_TARGETWIN", EQ_EXECUTECMD_TOGGLE_TARGETWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_SPELLSWIN", EQ_EXECUTECMD_TOGGLE_SPELLSWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_BUFFWIN", EQ_EXECUTECMD_TOGGLE_BUFFWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX1WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX1WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX2WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX2WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX3WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX3WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX4WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX4WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX5WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX5WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX6WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX6WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX7WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX7WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX8WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX8WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX9WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX9WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX10WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX10WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HOTBOX11WIN", EQ_EXECUTECMD_TOGGLE_HOTBOX11WIN);
    state->set("EQ_EXECUTECMD_TOGGLE_CHATWIN", EQ_EXECUTECMD_TOGGLE_CHATWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_MAILWIN", EQ_EXECUTECMD_TOGGLE_MAILWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_MAILCOMPWIN", EQ_EXECUTECMD_TOGGLE_MAILCOMPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_MAINMENUWIN", EQ_EXECUTECMD_TOGGLE_MAINMENUWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_ALTADVWIN", EQ_EXECUTECMD_TOGGLE_ALTADVWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_BAZAARWIN", EQ_EXECUTECMD_TOGGLE_BAZAARWIN);
    state->set("EQ_EXECUTECMD_RTARGET", EQ_EXECUTECMD_RTARGET);
    state->set("EQ_EXECUTECMD_TOGGLE_FRIENDSWIN", EQ_EXECUTECMD_TOGGLE_FRIENDSWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_PETINFOWIN", EQ_EXECUTECMD_TOGGLE_PETINFOWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_OPTIONSWIN", EQ_EXECUTECMD_TOGGLE_OPTIONSWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_HELPWIN", EQ_EXECUTECMD_TOGGLE_HELPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_SELECTORWIN", EQ_EXECUTECMD_TOGGLE_SELECTORWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_VIDEOMODEWIN", EQ_EXECUTECMD_TOGGLE_VIDEOMODEWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_BAZAARSEARCHWIN", EQ_EXECUTECMD_TOGGLE_BAZAARSEARCHWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_COMPASSWIN", EQ_EXECUTECMD_TOGGLE_COMPASSWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_RAIDWIN", EQ_EXECUTECMD_TOGGLE_RAIDWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_MUSICPLAYERWIN", EQ_EXECUTECMD_TOGGLE_MUSICPLAYERWIN);
    state->set("EQ_EXECUTECMD_FORWARD_CAM", EQ_EXECUTECMD_FORWARD_CAM);
    state->set("EQ_EXECUTECMD_BACK_CAM", EQ_EXECUTECMD_BACK_CAM);
    state->set("EQ_EXECUTECMD_RIGHT_CAM", EQ_EXECUTECMD_RIGHT_CAM);
    state->set("EQ_EXECUTECMD_LEFT_CAM", EQ_EXECUTECMD_LEFT_CAM);
    state->set("EQ_EXECUTECMD_PITCHUP_CAM", EQ_EXECUTECMD_PITCHUP_CAM);
    state->set("EQ_EXECUTECMD_PITCHDOWN_CAM", EQ_EXECUTECMD_PITCHDOWN_CAM);
    state->set("EQ_EXECUTECMD_TOGGLE_JOURNAL", EQ_EXECUTECMD_TOGGLE_JOURNAL);
    state->set("EQ_EXECUTECMD_TOGGLE_SDBUFFWIN", EQ_EXECUTECMD_TOGGLE_SDBUFFWIN);
    state->set("EQ_EXECUTECMD_RELEASE_MOUSE_CURSOR", EQ_EXECUTECMD_RELEASE_MOUSE_CURSOR);
    state->set("EQ_EXECUTECMD_TOGGLE_STORYWIN", EQ_EXECUTECMD_TOGGLE_STORYWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_MAPWIN", EQ_EXECUTECMD_TOGGLE_MAPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_GUILDMGMTWIN", EQ_EXECUTECMD_TOGGLE_GUILDMGMTWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_FELLOWSHIPWIN", EQ_EXECUTECMD_TOGGLE_FELLOWSHIPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_LFGROUPWIN", EQ_EXECUTECMD_TOGGLE_LFGROUPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_LFGUILDWIN", EQ_EXECUTECMD_TOGGLE_LFGUILDWIN);
    state->set("EQ_EXECUTECMD_TOGGLETWOTARGETS", EQ_EXECUTECMD_TOGGLETWOTARGETS);
    state->set("EQ_EXECUTECMD_TOGGLE_CONTEXTMENUS", EQ_EXECUTECMD_TOGGLE_CONTEXTMENUS);
    state->set("EQ_EXECUTECMD_FIRST_PERSON_CAMERA", EQ_EXECUTECMD_FIRST_PERSON_CAMERA);
    state->set("EQ_EXECUTECMD_OVERHEAD_CAMERA", EQ_EXECUTECMD_OVERHEAD_CAMERA);
    state->set("EQ_EXECUTECMD_CHASE_CAMERA", EQ_EXECUTECMD_CHASE_CAMERA);
    state->set("EQ_EXECUTECMD_USER1_CAMERA", EQ_EXECUTECMD_USER1_CAMERA);
    state->set("EQ_EXECUTECMD_USER2_CAMERA", EQ_EXECUTECMD_USER2_CAMERA);
    state->set("EQ_EXECUTECMD_TETHER_CAMERA", EQ_EXECUTECMD_TETHER_CAMERA);
    state->set("EQ_EXECUTECMD_TOGGLE_ADVREQUESTWIN", EQ_EXECUTECMD_TOGGLE_ADVREQUESTWIN);
    state->set("EQ_EXECUTECMD_CLOSE_TOP_WINDOW", EQ_EXECUTECMD_CLOSE_TOP_WINDOW);
    state->set("EQ_EXECUTECMD_CLEAR_TARGET", EQ_EXECUTECMD_CLEAR_TARGET);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_FIND_WINDOW", EQ_EXECUTECMD_CMD_TOGGLE_FIND_WINDOW);
    state->set("EQ_EXECUTECMD_TOGGLE_LEADERSHIPWIN", EQ_EXECUTECMD_TOGGLE_LEADERSHIPWIN);
    state->set("EQ_EXECUTECMD_TOGGLE_TRIBUTEBENEFITWIN", EQ_EXECUTECMD_TOGGLE_TRIBUTEBENEFITWIN);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK1", EQ_EXECUTECMD_CMD_OPENING_ATTACK1);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK2", EQ_EXECUTECMD_CMD_OPENING_ATTACK2);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK3", EQ_EXECUTECMD_CMD_OPENING_ATTACK3);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK4", EQ_EXECUTECMD_CMD_OPENING_ATTACK4);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK5", EQ_EXECUTECMD_CMD_OPENING_ATTACK5);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK6", EQ_EXECUTECMD_CMD_OPENING_ATTACK6);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK7", EQ_EXECUTECMD_CMD_OPENING_ATTACK7);
    state->set("EQ_EXECUTECMD_CMD_OPENING_ATTACK8", EQ_EXECUTECMD_CMD_OPENING_ATTACK8);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_COMBAT_ABILITY_WIN", EQ_EXECUTECMD_CMD_TOGGLE_COMBAT_ABILITY_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_DYNAMIC_ZONE_WIN", EQ_EXECUTECMD_CMD_TOGGLE_DYNAMIC_ZONE_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_PVP_LEADERBOARD", EQ_EXECUTECMD_CMD_TOGGLE_PVP_LEADERBOARD);
    state->set("EQ_EXECUTECMD_CMD_TOGGLETASKWIN", EQ_EXECUTECMD_CMD_TOGGLETASKWIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_TICKET_WND", EQ_EXECUTECMD_CMD_TOGGLE_TICKET_WND);
    state->set("EQ_EXECUTECMD_CMD_STOP_CAST", EQ_EXECUTECMD_CMD_STOP_CAST);
    state->set("EQ_EXECUTECMD_CMD_TOGGLEVOICEWIN", EQ_EXECUTECMD_CMD_TOGGLEVOICEWIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_TITLE_WND", EQ_EXECUTECMD_CMD_TOGGLE_TITLE_WND);
    state->set("EQ_EXECUTECMD_TOGGLE_BANDOLIER", EQ_EXECUTECMD_TOGGLE_BANDOLIER);
    state->set("EQ_EXECUTECMD_OPEN_INV_BAGS", EQ_EXECUTECMD_OPEN_INV_BAGS);
    state->set("EQ_EXECUTECMD_CLOSE_INV_BAGS", EQ_EXECUTECMD_CLOSE_INV_BAGS);
    state->set("EQ_EXECUTECMD_TOGGLE_INV_BAGS", EQ_EXECUTECMD_TOGGLE_INV_BAGS);
    state->set("EQ_EXECUTECMD_TOGGLE_SKILLS_WND", EQ_EXECUTECMD_TOGGLE_SKILLS_WND);
    state->set("EQ_EXECUTECMD_OPEN_ETN_HELP", EQ_EXECUTECMD_OPEN_ETN_HELP);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDBUFFWIN", EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDBUFFWIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_AUDIO_TRIGGER_WINDOW", EQ_EXECUTECMD_CMD_TOGGLE_AUDIO_TRIGGER_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_CLIPBOARD_PASTE", EQ_EXECUTECMD_CMD_CLIPBOARD_PASTE);
    state->set("EQ_EXECUTECMD_CMD_OPEN_EQPLAYERS", EQ_EXECUTECMD_CMD_OPEN_EQPLAYERS);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_AURAWND", EQ_EXECUTECMD_CMD_TOGGLE_AURAWND);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDPETBUFFWIN", EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDPETBUFFWIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_REWARD_SELECTION_WIN", EQ_EXECUTECMD_CMD_TOGGLE_REWARD_SELECTION_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_CLAIM_WIN", EQ_EXECUTECMD_CMD_TOGGLE_CLAIM_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_VOICE_BAR", EQ_EXECUTECMD_CMD_TOGGLE_VOICE_BAR);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_AS_LIST", EQ_EXECUTECMD_CMD_TOGGLE_AS_LIST);
    state->set("EQ_EXECUTECMD_CMD_PUSH_TO_TALK", EQ_EXECUTECMD_CMD_PUSH_TO_TALK);
    state->set("EQ_EXECUTECMD_CMD_PUSH_TO_TALK_SAY", EQ_EXECUTECMD_CMD_PUSH_TO_TALK_SAY);
    state->set("EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GROUP", EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GROUP);
    state->set("EQ_EXECUTECMD_CMD_PUSH_TO_TALK_RAID", EQ_EXECUTECMD_CMD_PUSH_TO_TALK_RAID);
    state->set("EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GUILD", EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GUILD);
    state->set("EQ_EXECUTECMD_CMD_MERCENARIES", EQ_EXECUTECMD_CMD_MERCENARIES);
    state->set("EQ_EXECUTECMD_CMD_MARKETPLACE", EQ_EXECUTECMD_CMD_MARKETPLACE);
    state->set("EQ_EXECUTECMD_CMD_WELCOMESCREEN", EQ_EXECUTECMD_CMD_WELCOMESCREEN);
    state->set("EQ_EXECUTECMD_CMD_EXTENDED_TARGET_WINDOW", EQ_EXECUTECMD_CMD_EXTENDED_TARGET_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_ACHIEVEMENT_WINDOW", EQ_EXECUTECMD_CMD_ACHIEVEMENT_WINDOW);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_1", EQ_EXECUTECMD_TARGET_XTARGET_1);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_2", EQ_EXECUTECMD_TARGET_XTARGET_2);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_3", EQ_EXECUTECMD_TARGET_XTARGET_3);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_4", EQ_EXECUTECMD_TARGET_XTARGET_4);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_5", EQ_EXECUTECMD_TARGET_XTARGET_5);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_6", EQ_EXECUTECMD_TARGET_XTARGET_6);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_7", EQ_EXECUTECMD_TARGET_XTARGET_7);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_8", EQ_EXECUTECMD_TARGET_XTARGET_8);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_9", EQ_EXECUTECMD_TARGET_XTARGET_9);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_10", EQ_EXECUTECMD_TARGET_XTARGET_10);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_11", EQ_EXECUTECMD_TARGET_XTARGET_11);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_12", EQ_EXECUTECMD_TARGET_XTARGET_12);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_13", EQ_EXECUTECMD_TARGET_XTARGET_13);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_14", EQ_EXECUTECMD_TARGET_XTARGET_14);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_15", EQ_EXECUTECMD_TARGET_XTARGET_15);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_16", EQ_EXECUTECMD_TARGET_XTARGET_16);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_17", EQ_EXECUTECMD_TARGET_XTARGET_17);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_18", EQ_EXECUTECMD_TARGET_XTARGET_18);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_19", EQ_EXECUTECMD_TARGET_XTARGET_19);
    state->set("EQ_EXECUTECMD_TARGET_XTARGET_20", EQ_EXECUTECMD_TARGET_XTARGET_20);
    state->set("EQ_EXECUTECMD_ADD_XTARGET", EQ_EXECUTECMD_ADD_XTARGET);
    state->set("EQ_EXECUTECMD_REMOVE_XTARGET", EQ_EXECUTECMD_REMOVE_XTARGET);
    state->set("EQ_EXECUTECMD_CYCLE_XTARGET", EQ_EXECUTECMD_CYCLE_XTARGET);
    state->set("EQ_EXECUTECMD_REMOVE_XTARGET_BY_SLOT", EQ_EXECUTECMD_REMOVE_XTARGET_BY_SLOT);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEMS_WINDOW", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEMS_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_MANAGE_WINDOW", EQ_EXECUTECMD_CMD_REAL_ESTATE_MANAGE_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_TROPHIES_WINDOW", EQ_EXECUTECMD_CMD_REAL_ESTATE_TROPHIES_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_PLOT_SEARCH_WINDOW", EQ_EXECUTECMD_CMD_REAL_ESTATE_PLOT_SEARCH_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_HELP_WINDOW", EQ_EXECUTECMD_CMD_REAL_ESTATE_HELP_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_TOGGLE_MODE", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_TOGGLE_MODE);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_COLLISION", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_COLLISION);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_WALL", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_WALL);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_CURSOR", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_CURSOR);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_FREE", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_SET_MODE_FREE);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_MOUSE_X_ROTATION", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_MOUSE_X_ROTATION);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_MOUSE_Y_ROTATION", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_MOUSE_Y_ROTATION);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_WHEEL_ROTATION", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_WHEEL_ROTATION);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_SIZE", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_RESET_ITEM_SIZE);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_MOUSE_X_ROTATION_90_DEGREES", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_MOUSE_X_ROTATION_90_DEGREES);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_MOUSE_Y_ROTATION_90_DEGREES", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_MOUSE_Y_ROTATION_90_DEGREES);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_WHEEL_ROTATION_90_DEGREES", EQ_EXECUTECMD_CMD_REAL_ESTATE_ITEM_PLACEMENT_ROTATE_ITEM_WHEEL_ROTATION_90_DEGREES);
    state->set("EQ_EXECUTECMD_CMD_REAL_ESTATE_LEAVE", EQ_EXECUTECMD_CMD_REAL_ESTATE_LEAVE);
    state->set("EQ_EXECUTECMD_CMD_VOTE_RESULTS", EQ_EXECUTECMD_CMD_VOTE_RESULTS);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_TCG", EQ_EXECUTECMD_CMD_TOGGLE_TCG);
    state->set("EQ_EXECUTECMD_CMD_MOVE_DOWN", EQ_EXECUTECMD_CMD_MOVE_DOWN);
    state->set("EQ_EXECUTECMD_CMD_STOP_ACTION", EQ_EXECUTECMD_CMD_STOP_ACTION);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_ALARM", EQ_EXECUTECMD_CMD_TOGGLE_ALARM);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_BANK_BAGS", EQ_EXECUTECMD_CMD_TOGGLE_BANK_BAGS);
    state->set("EQ_EXECUTECMD_TOGGLE_ZONE_GUIDE_WINDOW", EQ_EXECUTECMD_TOGGLE_ZONE_GUIDE_WINDOW);
    state->set("EQ_EXECUTECMD_TOGGLE_ZONE_PATH_WINDOW", EQ_EXECUTECMD_TOGGLE_ZONE_PATH_WINDOW);
    state->set("EQ_EXECUTECMD_CMD_MARKETPLACE_SILVER", EQ_EXECUTECMD_CMD_MARKETPLACE_SILVER);
    state->set("EQ_EXECUTECMD_CMD_MARKETPLACE_GOLD", EQ_EXECUTECMD_CMD_MARKETPLACE_GOLD);
    state->set("EQ_EXECUTECMD_CMD_HISTORIC_ALERTS", EQ_EXECUTECMD_CMD_HISTORIC_ALERTS);
    state->set("EQ_EXECUTECMD_CMD_SOCIAL_SHARE", EQ_EXECUTECMD_CMD_SOCIAL_SHARE);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_AGGRO", EQ_EXECUTECMD_CMD_TOGGLE_AGGRO);
    state->set("EQ_EXECUTECMD_CMD_LOCK_AGGRO", EQ_EXECUTECMD_CMD_LOCK_AGGRO);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_BARTER_SEARCH", EQ_EXECUTECMD_CMD_TOGGLE_BARTER_SEARCH);
    state->set("EQ_EXECUTECMD_CMD_OPEN_URL", EQ_EXECUTECMD_CMD_OPEN_URL);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_TARGETOFTARGETWIN", EQ_EXECUTECMD_CMD_TOGGLE_TARGETOFTARGETWIN);
    state->set("EQ_EXECUTECMD_CMD_RAID_DELEGATE_MAIN_ASSIST", EQ_EXECUTECMD_CMD_RAID_DELEGATE_MAIN_ASSIST);
    state->set("EQ_EXECUTECMD_CMD_INSPECT_BUFFS", EQ_EXECUTECMD_CMD_INSPECT_BUFFS);
    state->set("EQ_EXECUTECMD_CMD_GROUP_DELEGATE_MARK_NPC", EQ_EXECUTECMD_CMD_GROUP_DELEGATE_MARK_NPC);
    state->set("EQ_EXECUTECMD_CMD_RAID_DELEGATE_MARK_NPC", EQ_EXECUTECMD_CMD_RAID_DELEGATE_MARK_NPC);
    state->set("EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_1", EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_1);
    state->set("EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_2", EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_2);
    state->set("EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_3", EQ_EXECUTECMD_CMD_GROUP_MARK_NPC_3);
    state->set("EQ_EXECUTECMD_CMD_RAID_MARK_NPC_1", EQ_EXECUTECMD_CMD_RAID_MARK_NPC_1);
    state->set("EQ_EXECUTECMD_CMD_RAID_MARK_NPC_2", EQ_EXECUTECMD_CMD_RAID_MARK_NPC_2);
    state->set("EQ_EXECUTECMD_CMD_RAID_MARK_NPC_3", EQ_EXECUTECMD_CMD_RAID_MARK_NPC_3);
    state->set("EQ_EXECUTECMD_CMD_FIND_PC_GROUP_RAID", EQ_EXECUTECMD_CMD_FIND_PC_GROUP_RAID);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_KEYRINGS", EQ_EXECUTECMD_CMD_TOGGLE_KEYRINGS);
    state->set("EQ_EXECUTECMD_CMD_GROUP_DELEGATE_MASTER_LOOTER", EQ_EXECUTECMD_CMD_GROUP_DELEGATE_MASTER_LOOTER);
    state->set("EQ_EXECUTECMD_CMD_RAID_DELEGATE_MASTER_LOOTER", EQ_EXECUTECMD_CMD_RAID_DELEGATE_MASTER_LOOTER);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_ADVANCED_LOOT_WIN", EQ_EXECUTECMD_CMD_TOGGLE_ADVANCED_LOOT_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_PICKZONE_WIN", EQ_EXECUTECMD_CMD_TOGGLE_PICKZONE_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_TASK_OVERLAY_WIN", EQ_EXECUTECMD_CMD_TOGGLE_TASK_OVERLAY_WIN);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_ITEM_OVERFLOW_WND", EQ_EXECUTECMD_CMD_TOGGLE_ITEM_OVERFLOW_WND);
    state->set("EQ_EXECUTECMD_CMD_EVENT_CALENDAR", EQ_EXECUTECMD_CMD_EVENT_CALENDAR);
    state->set("EQ_EXECUTECMD_CMD_TOGGLE_FINDITEM_WND", EQ_EXECUTECMD_CMD_TOGGLE_FINDITEM_WND);
    state->set("EQ_EXECUTECMD_TOGGLE_FPS", EQ_EXECUTECMD_TOGGLE_FPS);
    state->set("EQ_EXECUTECMD_TOGGLE_AVATAR", EQ_EXECUTECMD_TOGGLE_AVATAR);
    state->set("EQ_EXECUTECMD_TOGGLE_PETITION", EQ_EXECUTECMD_TOGGLE_PETITION);
    state->set("EQ_EXECUTECMD_TOGGLE_MEMINFO", EQ_EXECUTECMD_TOGGLE_MEMINFO);
    state->set("EQ_EXECUTECMD_FLY_UP", EQ_EXECUTECMD_FLY_UP);
    state->set("EQ_EXECUTECMD_FLY_DOWN", EQ_EXECUTECMD_FLY_DOWN);
    state->set("EQ_EXECUTECMD_ADD_ROUTE", EQ_EXECUTECMD_ADD_ROUTE);
    state->set("EQ_EXECUTECMD_LAY_PPOINT", EQ_EXECUTECMD_LAY_PPOINT);
    state->set("EQ_EXECUTECMD_LAY_LINK", EQ_EXECUTECMD_LAY_LINK);
    state->set("EQ_EXECUTECMD_CONFIRM_YES", EQ_EXECUTECMD_CONFIRM_YES);
    state->set("EQ_EXECUTECMD_CONFIRM_NO", EQ_EXECUTECMD_CONFIRM_NO);
    state->set("EQ_EXECUTECMD_TARGET_PREV_NPC", EQ_EXECUTECMD_TARGET_PREV_NPC);
    state->set("EQ_EXECUTECMD_TARGET_NEXT_NPC", EQ_EXECUTECMD_TARGET_NEXT_NPC);
    state->set("EQ_EXECUTECMD_ROTATE_STATS", EQ_EXECUTECMD_ROTATE_STATS);
    state->set("EQ_EXECUTECMD_TOGGLE_NPC_TUNE", EQ_EXECUTECMD_TOGGLE_NPC_TUNE);
    state->set("EQ_EXECUTECMD_TOGGLEQAMARKER", EQ_EXECUTECMD_TOGGLEQAMARKER);
    state->set("EQ_EXECUTECMD_CMD_EXITGAME", EQ_EXECUTECMD_CMD_EXITGAME);

    state->set("EQ_ZONE_ID_BAZAAR", EQ_ZONE_ID_BAZAAR);
    state->set("EQ_ZONE_ID_NEXUS", EQ_ZONE_ID_NEXUS);
    state->set("EQ_ZONE_ID_POKNOWLEDGE", EQ_ZONE_ID_POKNOWLEDGE);
    state->set("EQ_ZONE_ID_POTRANQUILITY", EQ_ZONE_ID_POTRANQUILITY);
    state->set("EQ_ZONE_ID_GUILDLOBBY", EQ_ZONE_ID_GUILDLOBBY);
    state->set("EQ_ZONE_ID_GUILDHALL", EQ_ZONE_ID_GUILDHALL);
    state->set("EQ_ZONE_ID_BARTER", EQ_ZONE_ID_BARTER);

    // EQ functions
    state->set_function("EQ_Log", EQ_Log);

    state->set_function("EQ_CalculateDistance", EQ_CalculateDistance);
    state->set_function("EQ_CalculateDistance3D", EQ_CalculateDistance3D);
    state->set_function("EQ_IsWithinDistance", EQ_IsWithinDistance);

    state->set_function("EQ_GetBearing", EQ_GetBearing);

    state->set_function("EQ_IsPointInsideRectangle", EQ_IsPointInsideRectangle);

    state->set_function("EQ_GetGameState", EQ_GetGameState);
    state->set_function("EQ_IsInGame", EQ_IsInGame);
    state->set_function("EQ_IsSpellIDValid", EQ_IsSpellIDValid);

    state->set_function("EQ_IsNetStatusEnabled", EQ_IsNetStatusEnabled);
    state->set_function("EQ_IsAutoAttackEnabled", EQ_IsAutoAttackEnabled);
    state->set_function("EQ_IsAutoFireEnabled", EQ_IsAutoFireEnabled);
    state->set_function("EQ_IsAutoRunEnabled", EQ_IsAutoRunEnabled);
    state->set_function("EQ_IsMouseLookEnabled", EQ_IsMouseLookEnabled);

    state->set_function("EQ_SetNetStatus", EQ_SetNetStatus);
    state->set_function("EQ_SetAutoAttack", EQ_SetAutoAttack);
    state->set_function("EQ_SetAutoFire", EQ_SetAutoFire);
    state->set_function("EQ_SetAutoRun", EQ_SetAutoRun);
    state->set_function("EQ_SetMouseLook", EQ_SetMouseLook);

    state->set_function("EQ_GetSpawnByID", EQ_GetSpawnByID);
    state->set_function("EQ_GetSpawnByName", EQ_GetSpawnByName);

    state->set_function("EQ_GetFirstSpawn", EQ_GetFirstSpawn);
    state->set_function("EQ_GetLastSpawn", EQ_GetLastSpawn);

    state->set_function("EQ_GetPlayerSpawn", EQ_GetPlayerSpawn);
    state->set_function("EQ_GetTargetSpawn", EQ_GetTargetSpawn);

    state->set_function("EQ_SetTargetSpawn", EQ_SetTargetSpawn);

    state->set_function("EQ_GetSpawnNext", EQ_GetSpawnNext);
    state->set_function("EQ_GetSpawnPrevious", EQ_GetSpawnPrevious);

    state->set_function("EQ_GetSpawnNumbered", EQ_GetSpawnNameNumbered);
    state->set_function("EQ_GetSpawnName", EQ_GetSpawnName);
    state->set_function("EQ_GetSpawnLastName", EQ_GetSpawnLastName);

    state->set_function("EQ_GetPlayerSpawnName", EQ_GetPlayerSpawnName);
    state->set_function("EQ_GetPlayerSpawnLastName", EQ_GetPlayerSpawnLastName);
    state->set_function("EQ_GetTargetSpawnName", EQ_GetTargetSpawnName);
    state->set_function("EQ_GetTargetSpawnLastName", EQ_GetTargetSpawnLastName);

    state->set_function("EQ_IsSpawnWithinDistance", EQ_IsSpawnWithinDistance);
    state->set_function("EQ_IsSpawnWithinDistanceOfLocation", EQ_IsSpawnWithinDistanceOfLocation);
    state->set_function("EQ_GetSpawnDistance", EQ_GetSpawnDistance);
    state->set_function("EQ_GetSpawnDistance3D", EQ_GetSpawnDistance3D);

    state->set_function("EQ_GetSpawnY", EQ_GetSpawnY);
    state->set_function("EQ_GetSpawnX", EQ_GetSpawnX);
    state->set_function("EQ_GetSpawnZ", EQ_GetSpawnZ);
    state->set_function("EQ_GetSpawnMovementSpeed", EQ_GetSpawnMovementSpeed);
    state->set_function("EQ_GetSpawnHeading", EQ_GetSpawnHeading);
    state->set_function("EQ_GetSpawnType", EQ_GetSpawnType);
    state->set_function("EQ_GetSpawnHeight", EQ_GetSpawnHeight);
    state->set_function("EQ_GetSpawnID", EQ_GetSpawnID);
    state->set_function("EQ_GetSpawnZoneID", EQ_GetSpawnZoneID);
    state->set_function("EQ_GetSpawnLevel", EQ_GetSpawnLevel);
    state->set_function("EQ_GetSpawnRace", EQ_GetSpawnRace);
    state->set_function("EQ_GetSpawnClass", EQ_GetSpawnClass);
    state->set_function("EQ_GetSpawnStandingState", EQ_GetSpawnStandingState);
    state->set_function("EQ_GetSpawnHPCurrent", EQ_GetSpawnHPCurrent);
    state->set_function("EQ_GetSpawnHPMax", EQ_GetSpawnHPMax);
    state->set_function("EQ_GetSpawnHPPercent", EQ_GetSpawnHPPercent);
    state->set_function("EQ_GetSpawnManaCurrent", EQ_GetSpawnManaCurrent);
    state->set_function("EQ_GetSpawnManaMax", EQ_GetSpawnManaMax);
    state->set_function("EQ_GetSpawnManaPercent", EQ_GetSpawnManaPercent);
    state->set_function("EQ_GetSpawnEnduranceCurrent", EQ_GetSpawnEnduranceCurrent);
    state->set_function("EQ_GetSpawnEnduranceMax", EQ_GetSpawnEnduranceMax);
    state->set_function("EQ_GetSpawnEndurancePercent", EQ_GetSpawnEndurancePercent);
    state->set_function("EQ_GetSpawnFollowSpawn", EQ_GetSpawnFollowSpawn);
    state->set_function("EQ_GetSpawnDirection", EQ_GetSpawnDirection);

    state->set_function("EQ_SetSpawnHeading", EQ_SetSpawnHeading);
    state->set_function("EQ_SetSpawnHeight", EQ_SetSpawnHeight);
    state->set_function("EQ_SetSpawnFollowSpawn", EQ_SetSpawnFollowSpawn);

    state->set_function("EQ_TurnSpawnTowardsLocation", EQ_TurnSpawnTowardsLocation);
    state->set_function("EQ_TurnPlayerTowardsSpawn", EQ_TurnPlayerTowardsSpawn);

    state->set_function("EQ_IsSpawnClassTank", EQ_IsSpawnClassTank);
    state->set_function("EQ_IsSpawnClassPriest", EQ_IsSpawnClassPriest);
    state->set_function("EQ_IsSpawnClassCaster", EQ_IsSpawnClassCaster);
    state->set_function("EQ_IsSpawnClassMelee", EQ_IsSpawnClassMelee);
    state->set_function("EQ_IsSpawnClassHybrid", EQ_IsSpawnClassHybrid);

    state->set_function("EQ_InterpretCommand", EQ_InterpretCommand);
    state->set_function("EQ_ExecuteCommand", EQ_ExecuteCommand);

    state->set_function("EQ_PrintTextToChat", EQ_PrintTextToChat);
    state->set_function("EQ_PrintTextToChatEx", EQ_PrintTextToChatEx);

    state->set_function("EQ_DrawText", EQ_DrawText);
    state->set_function("EQ_DrawTextEx", EQ_DrawTextEx);

    state->set_function("EQ_GetCameraPitch", EQ_GetCameraPitch);
    state->set_function("EQ_GetCameraFieldOfView", EQ_GetCameraFieldOfView);
    state->set_function("EQ_GetCameraDrawDistance", EQ_GetCameraDrawDistance);

    state->set_function("EQ_SetCameraPitch", EQ_SetCameraPitch);
    state->set_function("EQ_SetCameraFieldOfView", EQ_SetCameraFieldOfView);
    state->set_function("EQ_SetCameraDrawDistance", EQ_SetCameraDrawDistance);

    state->set_function("EQ_PlaySound", EQ_PlaySound);
    state->set_function("EQ_StopSound", EQ_StopSound);

    state->set_function("EQ_StopFollow", EQ_StopFollow);
    state->set_function("EQ_FollowTarget", EQ_FollowTarget);
    state->set_function("EQ_TurnPlayerTowardsTarget", EQ_TurnPlayerTowardsTarget);

    state->set_function("EQ_GetSpawnTypeNameByKey", EQ_GetSpawnTypeNameByKey);
    state->set_function("EQ_GetStandingStateNameByKey", EQ_GetStandingStateNameByKey);
    state->set_function("EQ_GetDirectionNameByKey", EQ_GetDirectionNameByKey);
    state->set_function("EQ_GetZoneNameByKey", EQ_GetZoneNameByKey);
    state->set_function("EQ_GetZoneShortNameByKey", EQ_GetZoneShortNameByKey);
    state->set_function("EQ_GetRaceNameByKey", EQ_GetRaceNameByKey);
    state->set_function("EQ_GetRaceShortNameByKey", EQ_GetRaceShortNameByKey);
    state->set_function("EQ_GetClassNameByKey", EQ_GetClassNameByKey);
    state->set_function("EQ_GetClassShortNameByKey", EQ_GetClassShortNameByKey);

    state->set_function("EQ_UseAlternateAbility", EQ_UseAlternateAbility);
    state->set_function("EQ_UseDiscipline", EQ_UseDiscipline);
}
