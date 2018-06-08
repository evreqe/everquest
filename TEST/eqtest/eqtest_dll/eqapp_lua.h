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
void EQAPP_Lua_LoadGlobalScripts(sol::state* state);
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

    EQAPP_Lua_LoadGlobalScripts(&g_LuaState);

    EQAPP_Lua_EventScriptList_Load();
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

void EQAPP_Lua_LoadGlobalScripts(sol::state* state)
{
    std::stringstream folderPath;
    folderPath << g_EQAppName << "/scripts/";

    for (auto& it : std__filesystem::directory_iterator(folderPath.str()))
    {
        if (it.path().extension().string() != ".lua")
        {
            continue;
        }

        std::string filename = it.path().filename().string();

        if (EQAPP_String_BeginsWith(filename, "global_") == false)
        {
            continue;
        }

        bool result = EQAPP_Lua_ExecuteFile(state, filename.c_str());
        if (result == false)
        {
            continue;
        }
    }
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

        EQAPP_Lua_LoadGlobalScripts(&state);

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
    state->set_function("EQAPP_PrintMouseLocation", EQAPP_PrintMouseLocation);

    // EQ constants
    state->set("EQ_WINDOW_TITLE_DEFAULT", EQ_WINDOW_TITLE_DEFAULT);

    state->set("EQ_PI", EQ_PI);

    state->set("EQ_ZONE_GRAVITY_DEFAULT", EQ_ZONE_GRAVITY_DEFAULT);

    state->set("EQ_HEADING_MIN", EQ_HEADING_MIN);
    state->set("EQ_HEADING_MAX", EQ_HEADING_MAX);
    state->set("EQ_HEADING_MAX_HALF", EQ_HEADING_MAX_HALF);

    state->set("EQ_SPAWN_PITCH_DEFAULT", EQ_SPAWN_PITCH_DEFAULT);
    state->set("EQ_SPAWN_PITCH_MIN", EQ_SPAWN_PITCH_MIN);
    state->set("EQ_SPAWN_PITCH_MAX", EQ_SPAWN_PITCH_MAX);

    state->set("EQ_SPAWN_HEADING_SPEED_DEFAULT", EQ_SPAWN_HEADING_SPEED_DEFAULT);
    state->set("EQ_SPAWN_HEADING_SPEED_MIN", EQ_SPAWN_HEADING_SPEED_MIN);
    state->set("EQ_SPAWN_HEADING_SPEED_MAX", EQ_SPAWN_HEADING_SPEED_MAX);

    state->set("EQ_MELEE_DISTANCE_MIN", EQ_MELEE_DISTANCE_MIN);
    state->set("EQ_MELEE_DISTANCE_MAX", EQ_MELEE_DISTANCE_MAX);

    state->set("EQ_FAR_CLIP_PLANE_MIN", EQ_FAR_CLIP_PLANE_MIN);
    state->set("EQ_FAR_CLIP_PLANE_MAX", EQ_FAR_CLIP_PLANE_MAX);

    state->set("EQ_NUM_HOTBARS", EQ_NUM_HOTBARS);
    state->set("EQ_NUM_HOTBAR_BUTTONS", EQ_NUM_HOTBAR_BUTTONS);
    state->set("EQ_NUM_SPELLS", EQ_NUM_SPELLS);
    state->set("EQ_NUM_SPELL_GEMS", EQ_NUM_SPELL_GEMS);
    state->set("EQ_NUM_BAGS", EQ_NUM_BAGS);
    state->set("EQ_NUM_BAG_SLOTS", EQ_NUM_BAG_SLOTS);
    state->set("EQ_NUM_GROUP_MEMBERS", EQ_NUM_GROUP_MEMBERS);

    state->set("EQ_BAZAAR_SEARCH_MAX_RESULTS_PER_TRADER", EQ_BAZAAR_SEARCH_MAX_RESULTS_PER_TRADER);
    state->set("EQ_BAZAAR_SEARCH_LIST_INDEX_NULL", EQ_BAZAAR_SEARCH_LIST_INDEX_NULL);

    state->set("EQ_SPELL_ID_NULL", EQ_SPELL_ID_NULL);

    state->set("EQ_FOG_OFF", EQ_FOG_OFF);
    state->set("EQ_FOG_ON", EQ_FOG_ON);

    state->set("EQ_UPDATE_ITEM_SLOT_HEAD", EQ_UPDATE_ITEM_SLOT_HEAD);
    state->set("EQ_UPDATE_ITEM_SLOT_PRIMARY", EQ_UPDATE_ITEM_SLOT_PRIMARY);
    state->set("EQ_UPDATE_ITEM_SLOT_SECONDARY", EQ_UPDATE_ITEM_SLOT_SECONDARY);

    state->set("EQ_GAME_STATE_IN_GAME", EQ_GAME_STATE_IN_GAME);

    state->set("EQ_FONT_INDEX_DEFAULT", EQ_FONT_INDEX_DEFAULT);

    state->set("EQ_FONT_STYLE_MIN", EQ_FONT_STYLE_MIN);
    state->set("EQ_FONT_STYLE_MAX", EQ_FONT_STYLE_MAX);

    state->set("EQ_FONT_STYLE_DEFAULT", EQ_FONT_STYLE_DEFAULT);
    state->set("EQ_FONT_STYLE_CHAT_WINDOW", EQ_FONT_STYLE_CHAT_WINDOW);
    state->set("EQ_FONT_STYLE_FIXED_WIDTH", EQ_FONT_STYLE_FIXED_WIDTH);
    state->set("EQ_FONT_STYLE_NAME_SPRITE", EQ_FONT_STYLE_NAME_SPRITE);

    state->set("EQ_SPAWN_TYPE_PLAYER", EQ_SPAWN_TYPE_PLAYER);
    state->set("EQ_SPAWN_TYPE_NPC", EQ_SPAWN_TYPE_NPC);
    state->set("EQ_SPAWN_TYPE_CORPSE", EQ_SPAWN_TYPE_CORPSE);

    state->set("EQ_ACTOR_TYPE_UNDEFINED", EQ_ACTOR_TYPE_UNDEFINED);
    state->set("EQ_ACTOR_TYPE_CORPSE", EQ_ACTOR_TYPE_CORPSE);
    state->set("EQ_ACTOR_TYPE_SWITCH", EQ_ACTOR_TYPE_SWITCH);
    state->set("EQ_ACTOR_TYPE_MISSILE", EQ_ACTOR_TYPE_MISSILE);
    state->set("EQ_ACTOR_TYPE_OBJECT", EQ_ACTOR_TYPE_OBJECT);
    state->set("EQ_ACTOR_TYPE_LADDER", EQ_ACTOR_TYPE_LADDER);
    state->set("EQ_ACTOR_TYPE_TREE", EQ_ACTOR_TYPE_TREE);
    state->set("EQ_ACTOR_TYPE_WALL", EQ_ACTOR_TYPE_WALL);
    state->set("EQ_ACTOR_TYPE_PLACED_OBJECT", EQ_ACTOR_TYPE_PLACED_OBJECT);

    state->set("EQ_GROUP_ROLE_FLAGS_MAIN_TANK", EQ_GROUP_ROLE_FLAGS_MAIN_TANK);
    state->set("EQ_GROUP_ROLE_FLAGS_MAIN_ASSIST", EQ_GROUP_ROLE_FLAGS_MAIN_ASSIST);
    state->set("EQ_GROUP_ROLE_FLAGS_PULLER", EQ_GROUP_ROLE_FLAGS_PULLER);
    state->set("EQ_GROUP_ROLE_FLAGS_MARK_NPC", EQ_GROUP_ROLE_FLAGS_MARK_NPC);
    state->set("EQ_GROUP_ROLE_FLAGS_MASTER_LOOTER", EQ_GROUP_ROLE_FLAGS_MASTER_LOOTER);

    state->set("EQ_SWITCH_KEY_ID_NULL", EQ_SWITCH_KEY_ID_NULL);

    state->set("EQ_SWITCH_STATE_CLOSED", EQ_SWITCH_STATE_CLOSED);
    state->set("EQ_SWITCH_STATE_OPEN", EQ_SWITCH_STATE_OPEN);
    state->set("EQ_SWITCH_STATE_OPENING", EQ_SWITCH_STATE_OPENING);
    state->set("EQ_SWITCH_STATE_CLOSING", EQ_SWITCH_STATE_CLOSING);

    state->set("EQ_SWITCH_TYPE_TOUCH_OR_CLICK_TO_ZONE", EQ_SWITCH_TYPE_TOUCH_OR_CLICK_TO_ZONE);
    state->set("EQ_SWITCH_TYPE_CLICK_TO_ZONE", EQ_SWITCH_TYPE_CLICK_TO_ZONE);

    state->set("EQ_ENVIRONMENT_TYPE_WATER", EQ_ENVIRONMENT_TYPE_WATER);

    state->set("EQ_SPAWN_STATE_FLAGS_IDLE", EQ_SPAWN_STATE_FLAGS_IDLE);
    state->set("EQ_SPAWN_STATE_FLAGS_OPEN", EQ_SPAWN_STATE_FLAGS_OPEN);
    state->set("EQ_SPAWN_STATE_FLAGS_WEAPON_SHEATHED", EQ_SPAWN_STATE_FLAGS_WEAPON_SHEATHED);
    state->set("EQ_SPAWN_STATE_FLAGS_AGGRESIVE", EQ_SPAWN_STATE_FLAGS_AGGRESIVE);
    state->set("EQ_SPAWN_STATE_FLAGS_FORCED_AGGRESIVE", EQ_SPAWN_STATE_FLAGS_FORCED_AGGRESIVE);
    state->set("EQ_SPAWN_STATE_FLAGS_INSTRUMENT_EQUIPPED", EQ_SPAWN_STATE_FLAGS_INSTRUMENT_EQUIPPED);
    state->set("EQ_SPAWN_STATE_FLAGS_STUNNED", EQ_SPAWN_STATE_FLAGS_STUNNED);
    state->set("EQ_SPAWN_STATE_FLAGS_PRIMARY_WEAPON_EQUIPPED", EQ_SPAWN_STATE_FLAGS_PRIMARY_WEAPON_EQUIPPED);
    state->set("EQ_SPAWN_STATE_FLAGS_SECONDARY_WEAPON_EQUIPPED", EQ_SPAWN_STATE_FLAGS_SECONDARY_WEAPON_EQUIPPED);

    state->set("EQ_STANDING_STATE_STANDING", EQ_STANDING_STATE_STANDING);
    state->set("EQ_STANDING_STATE_FROZEN" , EQ_STANDING_STATE_FROZEN);
    state->set("EQ_STANDING_STATE_KNEELING", EQ_STANDING_STATE_KNEELING);
    state->set("EQ_STANDING_STATE_SITTING", EQ_STANDING_STATE_SITTING);
    state->set("EQ_STANDING_STATE_DUCKING", EQ_STANDING_STATE_DUCKING);
    state->set("EQ_STANDING_STATE_FEIGN_DEATH", EQ_STANDING_STATE_FEIGN_DEATH);
    state->set("EQ_STANDING_STATE_DEAD", EQ_STANDING_STATE_DEAD);

    state->set("EQ_CAMERA_FIELD_OF_VIEW_DEFAULT", EQ_CAMERA_FIELD_OF_VIEW_DEFAULT);
    state->set("EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK", EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK);

    state->set("EQ_CAMERA_PITCH_DEFAULT", EQ_CAMERA_PITCH_DEFAULT);
    state->set("EQ_CAMERA_PITCH_MIN", EQ_CAMERA_PITCH_MIN);
    state->set("EQ_CAMERA_PITCH_MAX", EQ_CAMERA_PITCH_MAX);

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

    state->set("EQ_COLOR_ARGB_RED", EQ_COLOR_ARGB_RED);
    state->set("EQ_COLOR_ARGB_ORANGE", EQ_COLOR_ARGB_ORANGE);
    state->set("EQ_COLOR_ARGB_YELLOW", EQ_COLOR_ARGB_YELLOW);
    state->set("EQ_COLOR_ARGB_GREEN", EQ_COLOR_ARGB_GREEN);
    state->set("EQ_COLOR_ARGB_BLUE", EQ_COLOR_ARGB_BLUE);
    state->set("EQ_COLOR_ARGB_PURPLE", EQ_COLOR_ARGB_PURPLE);
    state->set("EQ_COLOR_ARGB_PINK", EQ_COLOR_ARGB_PINK);
    state->set("EQ_COLOR_ARGB_MAGENTA", EQ_COLOR_ARGB_MAGENTA);
    state->set("EQ_COLOR_ARGB_TEAL", EQ_COLOR_ARGB_TEAL);
    state->set("EQ_COLOR_ARGB_BROWN", EQ_COLOR_ARGB_BROWN);
    state->set("EQ_COLOR_ARGB_JADE", EQ_COLOR_ARGB_JADE);
    state->set("EQ_COLOR_ARGB_GREY", EQ_COLOR_ARGB_GREY);
    state->set("EQ_COLOR_ARGB_SILVER", EQ_COLOR_ARGB_SILVER);
    state->set("EQ_COLOR_ARGB_WHITE", EQ_COLOR_ARGB_WHITE);
    state->set("EQ_COLOR_ARGB_BLACK", EQ_COLOR_ARGB_BLACK);

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
    state->set("EQ_EXECUTECMD_CMD_HEROSJOURNEY_TEXT", EQ_EXECUTECMD_CMD_HEROSJOURNEY_TEXT);
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

    state->set("EQ_ZONE_ID_QEYNOS", EQ_ZONE_ID_QEYNOS);
    state->set("EQ_ZONE_ID_QEYNOS2", EQ_ZONE_ID_QEYNOS2);
    state->set("EQ_ZONE_ID_QRG", EQ_ZONE_ID_QRG);
    state->set("EQ_ZONE_ID_QEYTOQRG", EQ_ZONE_ID_QEYTOQRG);
    state->set("EQ_ZONE_ID_HIGHKEEP", EQ_ZONE_ID_HIGHKEEP);
    state->set("EQ_ZONE_ID_FREPORTN", EQ_ZONE_ID_FREPORTN);
    state->set("EQ_ZONE_ID_FREPORTW", EQ_ZONE_ID_FREPORTW);
    state->set("EQ_ZONE_ID_FREPORTE", EQ_ZONE_ID_FREPORTE);
    state->set("EQ_ZONE_ID_RUNNYEYE", EQ_ZONE_ID_RUNNYEYE);
    state->set("EQ_ZONE_ID_QEY2HH1", EQ_ZONE_ID_QEY2HH1);
    state->set("EQ_ZONE_ID_NORTHKARANA", EQ_ZONE_ID_NORTHKARANA);
    state->set("EQ_ZONE_ID_SOUTHKARANA", EQ_ZONE_ID_SOUTHKARANA);
    state->set("EQ_ZONE_ID_EASTKARANA", EQ_ZONE_ID_EASTKARANA);
    state->set("EQ_ZONE_ID_BEHOLDER", EQ_ZONE_ID_BEHOLDER);
    state->set("EQ_ZONE_ID_BLACKBURROW", EQ_ZONE_ID_BLACKBURROW);
    state->set("EQ_ZONE_ID_PAW", EQ_ZONE_ID_PAW);
    state->set("EQ_ZONE_ID_RIVERVALE", EQ_ZONE_ID_RIVERVALE);
    state->set("EQ_ZONE_ID_KITHICOR", EQ_ZONE_ID_KITHICOR);
    state->set("EQ_ZONE_ID_COMMONS", EQ_ZONE_ID_COMMONS);
    state->set("EQ_ZONE_ID_ECOMMONS", EQ_ZONE_ID_ECOMMONS);
    state->set("EQ_ZONE_ID_COMMONLANDS", EQ_ZONE_ID_COMMONLANDS);
    state->set("EQ_ZONE_ID_OCEANOFTEARS", EQ_ZONE_ID_OCEANOFTEARS);
    state->set("EQ_ZONE_ID_KITHFOREST", EQ_ZONE_ID_KITHFOREST);
    state->set("EQ_ZONE_ID_BEFALLENB", EQ_ZONE_ID_BEFALLENB);
    state->set("EQ_ZONE_ID_HIGHPASSKEEP", EQ_ZONE_ID_HIGHPASSKEEP);
    state->set("EQ_ZONE_ID_INNOTHULEB", EQ_ZONE_ID_INNOTHULEB);
    state->set("EQ_ZONE_ID_TOXXULIA", EQ_ZONE_ID_TOXXULIA);
    state->set("EQ_ZONE_ID_MISTYTHICKET", EQ_ZONE_ID_MISTYTHICKET);
    state->set("EQ_ZONE_ID_ERUDNINT", EQ_ZONE_ID_ERUDNINT);
    state->set("EQ_ZONE_ID_ERUDNEXT", EQ_ZONE_ID_ERUDNEXT);
    state->set("EQ_ZONE_ID_NEKTULOS", EQ_ZONE_ID_NEKTULOS);
    state->set("EQ_ZONE_ID_CSHOME", EQ_ZONE_ID_CSHOME);
    state->set("EQ_ZONE_ID_LAVASTORM", EQ_ZONE_ID_LAVASTORM);
    state->set("EQ_ZONE_ID_NEKTROPOS", EQ_ZONE_ID_NEKTROPOS);
    state->set("EQ_ZONE_ID_HALAS", EQ_ZONE_ID_HALAS);
    state->set("EQ_ZONE_ID_EVERFROST", EQ_ZONE_ID_EVERFROST);
    state->set("EQ_ZONE_ID_SOLDUNGA", EQ_ZONE_ID_SOLDUNGA);
    state->set("EQ_ZONE_ID_SOLDUNGB", EQ_ZONE_ID_SOLDUNGB);
    state->set("EQ_ZONE_ID_MISTY", EQ_ZONE_ID_MISTY);
    state->set("EQ_ZONE_ID_NRO", EQ_ZONE_ID_NRO);
    state->set("EQ_ZONE_ID_SRO", EQ_ZONE_ID_SRO);
    state->set("EQ_ZONE_ID_BEFALLEN", EQ_ZONE_ID_BEFALLEN);
    state->set("EQ_ZONE_ID_OASIS", EQ_ZONE_ID_OASIS);
    state->set("EQ_ZONE_ID_TOX", EQ_ZONE_ID_TOX);
    state->set("EQ_ZONE_ID_HOLE", EQ_ZONE_ID_HOLE);
    state->set("EQ_ZONE_ID_NERIAKA", EQ_ZONE_ID_NERIAKA);
    state->set("EQ_ZONE_ID_NERIAKB", EQ_ZONE_ID_NERIAKB);
    state->set("EQ_ZONE_ID_NERIAKC", EQ_ZONE_ID_NERIAKC);
    state->set("EQ_ZONE_ID_NAJENA", EQ_ZONE_ID_NAJENA);
    state->set("EQ_ZONE_ID_QCAT", EQ_ZONE_ID_QCAT);
    state->set("EQ_ZONE_ID_INNOTHULE", EQ_ZONE_ID_INNOTHULE);
    state->set("EQ_ZONE_ID_FEERROTT", EQ_ZONE_ID_FEERROTT);
    state->set("EQ_ZONE_ID_CAZICTHULE", EQ_ZONE_ID_CAZICTHULE);
    state->set("EQ_ZONE_ID_OGGOK", EQ_ZONE_ID_OGGOK);
    state->set("EQ_ZONE_ID_RATHEMTN", EQ_ZONE_ID_RATHEMTN);
    state->set("EQ_ZONE_ID_LAKERATHE", EQ_ZONE_ID_LAKERATHE);
    state->set("EQ_ZONE_ID_GROBB", EQ_ZONE_ID_GROBB);
    state->set("EQ_ZONE_ID_AVIAK", EQ_ZONE_ID_AVIAK);
    state->set("EQ_ZONE_ID_GFAYDARK", EQ_ZONE_ID_GFAYDARK);
    state->set("EQ_ZONE_ID_AKANON", EQ_ZONE_ID_AKANON);
    state->set("EQ_ZONE_ID_STEAMFONT", EQ_ZONE_ID_STEAMFONT);
    state->set("EQ_ZONE_ID_LFAYDARK", EQ_ZONE_ID_LFAYDARK);
    state->set("EQ_ZONE_ID_CRUSHBONE", EQ_ZONE_ID_CRUSHBONE);
    state->set("EQ_ZONE_ID_MISTMOORE", EQ_ZONE_ID_MISTMOORE);
    state->set("EQ_ZONE_ID_KALADIMA", EQ_ZONE_ID_KALADIMA);
    state->set("EQ_ZONE_ID_FELWITHEA", EQ_ZONE_ID_FELWITHEA);
    state->set("EQ_ZONE_ID_FELWITHEB", EQ_ZONE_ID_FELWITHEB);
    state->set("EQ_ZONE_ID_UNREST", EQ_ZONE_ID_UNREST);
    state->set("EQ_ZONE_ID_KEDGE", EQ_ZONE_ID_KEDGE);
    state->set("EQ_ZONE_ID_GUKTOP", EQ_ZONE_ID_GUKTOP);
    state->set("EQ_ZONE_ID_GUKBOTTOM", EQ_ZONE_ID_GUKBOTTOM);
    state->set("EQ_ZONE_ID_KALADIMB", EQ_ZONE_ID_KALADIMB);
    state->set("EQ_ZONE_ID_BUTCHER", EQ_ZONE_ID_BUTCHER);
    state->set("EQ_ZONE_ID_OOT", EQ_ZONE_ID_OOT);
    state->set("EQ_ZONE_ID_CAULDRON", EQ_ZONE_ID_CAULDRON);
    state->set("EQ_ZONE_ID_AIRPLANE", EQ_ZONE_ID_AIRPLANE);
    state->set("EQ_ZONE_ID_FEARPLANE", EQ_ZONE_ID_FEARPLANE);
    state->set("EQ_ZONE_ID_PERMAFROST", EQ_ZONE_ID_PERMAFROST);
    state->set("EQ_ZONE_ID_KERRARIDGE", EQ_ZONE_ID_KERRARIDGE);
    state->set("EQ_ZONE_ID_PAINEEL", EQ_ZONE_ID_PAINEEL);
    state->set("EQ_ZONE_ID_HATEPLANE", EQ_ZONE_ID_HATEPLANE);
    state->set("EQ_ZONE_ID_ARENA", EQ_ZONE_ID_ARENA);
    state->set("EQ_ZONE_ID_FIELDOFBONE", EQ_ZONE_ID_FIELDOFBONE);
    state->set("EQ_ZONE_ID_WARSLIKSWOOD", EQ_ZONE_ID_WARSLIKSWOOD);
    state->set("EQ_ZONE_ID_SOLTEMPLE", EQ_ZONE_ID_SOLTEMPLE);
    state->set("EQ_ZONE_ID_DROGA", EQ_ZONE_ID_DROGA);
    state->set("EQ_ZONE_ID_CABWEST", EQ_ZONE_ID_CABWEST);
    state->set("EQ_ZONE_ID_SWAMPOFNOHOPE", EQ_ZONE_ID_SWAMPOFNOHOPE);
    state->set("EQ_ZONE_ID_FIRIONA", EQ_ZONE_ID_FIRIONA);
    state->set("EQ_ZONE_ID_LAKEOFILLOMEN", EQ_ZONE_ID_LAKEOFILLOMEN);
    state->set("EQ_ZONE_ID_DREADLANDS", EQ_ZONE_ID_DREADLANDS);
    state->set("EQ_ZONE_ID_BURNINGWOOD", EQ_ZONE_ID_BURNINGWOOD);
    state->set("EQ_ZONE_ID_KAESORA", EQ_ZONE_ID_KAESORA);
    state->set("EQ_ZONE_ID_SEBILIS", EQ_ZONE_ID_SEBILIS);
    state->set("EQ_ZONE_ID_CITYMIST", EQ_ZONE_ID_CITYMIST);
    state->set("EQ_ZONE_ID_SKYFIRE", EQ_ZONE_ID_SKYFIRE);
    state->set("EQ_ZONE_ID_FRONTIERMTNS", EQ_ZONE_ID_FRONTIERMTNS);
    state->set("EQ_ZONE_ID_OVERTHERE", EQ_ZONE_ID_OVERTHERE);
    state->set("EQ_ZONE_ID_EMERALDJUNGLE", EQ_ZONE_ID_EMERALDJUNGLE);
    state->set("EQ_ZONE_ID_TRAKANON", EQ_ZONE_ID_TRAKANON);
    state->set("EQ_ZONE_ID_TIMOROUS", EQ_ZONE_ID_TIMOROUS);
    state->set("EQ_ZONE_ID_KURN", EQ_ZONE_ID_KURN);
    state->set("EQ_ZONE_ID_ERUDSXING", EQ_ZONE_ID_ERUDSXING);
    state->set("EQ_ZONE_ID_STONEBRUNT", EQ_ZONE_ID_STONEBRUNT);
    state->set("EQ_ZONE_ID_WARRENS", EQ_ZONE_ID_WARRENS);
    state->set("EQ_ZONE_ID_KARNOR", EQ_ZONE_ID_KARNOR);
    state->set("EQ_ZONE_ID_CHARDOK", EQ_ZONE_ID_CHARDOK);
    state->set("EQ_ZONE_ID_DALNIR", EQ_ZONE_ID_DALNIR);
    state->set("EQ_ZONE_ID_CHARASIS", EQ_ZONE_ID_CHARASIS);
    state->set("EQ_ZONE_ID_CABEAST", EQ_ZONE_ID_CABEAST);
    state->set("EQ_ZONE_ID_NURGA", EQ_ZONE_ID_NURGA);
    state->set("EQ_ZONE_ID_VEESHAN", EQ_ZONE_ID_VEESHAN);
    state->set("EQ_ZONE_ID_VEKSAR", EQ_ZONE_ID_VEKSAR);
    state->set("EQ_ZONE_ID_ICECLAD", EQ_ZONE_ID_ICECLAD);
    state->set("EQ_ZONE_ID_FROZENSHADOW", EQ_ZONE_ID_FROZENSHADOW);
    state->set("EQ_ZONE_ID_VELKETOR", EQ_ZONE_ID_VELKETOR);
    state->set("EQ_ZONE_ID_KAEL", EQ_ZONE_ID_KAEL);
    state->set("EQ_ZONE_ID_SKYSHRINE", EQ_ZONE_ID_SKYSHRINE);
    state->set("EQ_ZONE_ID_THURGADINA", EQ_ZONE_ID_THURGADINA);
    state->set("EQ_ZONE_ID_EASTWASTES", EQ_ZONE_ID_EASTWASTES);
    state->set("EQ_ZONE_ID_COBALTSCAR", EQ_ZONE_ID_COBALTSCAR);
    state->set("EQ_ZONE_ID_GREATDIVIDE", EQ_ZONE_ID_GREATDIVIDE);
    state->set("EQ_ZONE_ID_WAKENING", EQ_ZONE_ID_WAKENING);
    state->set("EQ_ZONE_ID_WESTWASTES", EQ_ZONE_ID_WESTWASTES);
    state->set("EQ_ZONE_ID_CRYSTAL", EQ_ZONE_ID_CRYSTAL);
    state->set("EQ_ZONE_ID_NECROPOLIS", EQ_ZONE_ID_NECROPOLIS);
    state->set("EQ_ZONE_ID_TEMPLEVEESHAN", EQ_ZONE_ID_TEMPLEVEESHAN);
    state->set("EQ_ZONE_ID_SIRENS", EQ_ZONE_ID_SIRENS);
    state->set("EQ_ZONE_ID_MISCHIEFPLANE", EQ_ZONE_ID_MISCHIEFPLANE);
    state->set("EQ_ZONE_ID_GROWTHPLANE", EQ_ZONE_ID_GROWTHPLANE);
    state->set("EQ_ZONE_ID_SLEEPER", EQ_ZONE_ID_SLEEPER);
    state->set("EQ_ZONE_ID_THURGADINB", EQ_ZONE_ID_THURGADINB);
    state->set("EQ_ZONE_ID_ERUDSXING2", EQ_ZONE_ID_ERUDSXING2);
    state->set("EQ_ZONE_ID_SHADOWHAVEN", EQ_ZONE_ID_SHADOWHAVEN);
    state->set("EQ_ZONE_ID_BAZAAR", EQ_ZONE_ID_BAZAAR);
    state->set("EQ_ZONE_ID_NEXUS", EQ_ZONE_ID_NEXUS);
    state->set("EQ_ZONE_ID_ECHO", EQ_ZONE_ID_ECHO);
    state->set("EQ_ZONE_ID_ACRYLIA", EQ_ZONE_ID_ACRYLIA);
    state->set("EQ_ZONE_ID_SHARVAHL", EQ_ZONE_ID_SHARVAHL);
    state->set("EQ_ZONE_ID_PALUDAL", EQ_ZONE_ID_PALUDAL);
    state->set("EQ_ZONE_ID_FUNGUSGROVE", EQ_ZONE_ID_FUNGUSGROVE);
    state->set("EQ_ZONE_ID_VEXTHAL", EQ_ZONE_ID_VEXTHAL);
    state->set("EQ_ZONE_ID_SSERU", EQ_ZONE_ID_SSERU);
    state->set("EQ_ZONE_ID_KATTA", EQ_ZONE_ID_KATTA);
    state->set("EQ_ZONE_ID_NETHERBIAN", EQ_ZONE_ID_NETHERBIAN);
    state->set("EQ_ZONE_ID_SSRATEMPLE", EQ_ZONE_ID_SSRATEMPLE);
    state->set("EQ_ZONE_ID_GRIEGSEND", EQ_ZONE_ID_GRIEGSEND);
    state->set("EQ_ZONE_ID_THEDEEP", EQ_ZONE_ID_THEDEEP);
    state->set("EQ_ZONE_ID_SHADEWEAVER", EQ_ZONE_ID_SHADEWEAVER);
    state->set("EQ_ZONE_ID_HOLLOWSHADE", EQ_ZONE_ID_HOLLOWSHADE);
    state->set("EQ_ZONE_ID_GRIMLING", EQ_ZONE_ID_GRIMLING);
    state->set("EQ_ZONE_ID_MSERU", EQ_ZONE_ID_MSERU);
    state->set("EQ_ZONE_ID_LETALIS", EQ_ZONE_ID_LETALIS);
    state->set("EQ_ZONE_ID_TWILIGHT", EQ_ZONE_ID_TWILIGHT);
    state->set("EQ_ZONE_ID_THEGREY", EQ_ZONE_ID_THEGREY);
    state->set("EQ_ZONE_ID_TENEBROUS", EQ_ZONE_ID_TENEBROUS);
    state->set("EQ_ZONE_ID_MAIDEN", EQ_ZONE_ID_MAIDEN);
    state->set("EQ_ZONE_ID_DAWNSHROUD", EQ_ZONE_ID_DAWNSHROUD);
    state->set("EQ_ZONE_ID_SCARLET", EQ_ZONE_ID_SCARLET);
    state->set("EQ_ZONE_ID_UMBRAL", EQ_ZONE_ID_UMBRAL);
    state->set("EQ_ZONE_ID_AKHEVA", EQ_ZONE_ID_AKHEVA);
    state->set("EQ_ZONE_ID_ARENA2", EQ_ZONE_ID_ARENA2);
    state->set("EQ_ZONE_ID_JAGGEDPINE", EQ_ZONE_ID_JAGGEDPINE);
    state->set("EQ_ZONE_ID_NEDARIA", EQ_ZONE_ID_NEDARIA);
    state->set("EQ_ZONE_ID_SHADOWREST", EQ_ZONE_ID_SHADOWREST);
    state->set("EQ_ZONE_ID_TUTORIAL", EQ_ZONE_ID_TUTORIAL);
    state->set("EQ_ZONE_ID_TUTORIALA", EQ_ZONE_ID_TUTORIALA);
    state->set("EQ_ZONE_ID_TUTORIALB", EQ_ZONE_ID_TUTORIALB);
    state->set("EQ_ZONE_ID_CLZ", EQ_ZONE_ID_CLZ);
    state->set("EQ_ZONE_ID_LOAD", EQ_ZONE_ID_LOAD);
    state->set("EQ_ZONE_ID_LOAD2", EQ_ZONE_ID_LOAD2);
    state->set("EQ_ZONE_ID_ARTTEST", EQ_ZONE_ID_ARTTEST);
    state->set("EQ_ZONE_ID_APPRENTICE", EQ_ZONE_ID_APPRENTICE);
    state->set("EQ_ZONE_ID_POKNOWLEDGE", EQ_ZONE_ID_POKNOWLEDGE);
    state->set("EQ_ZONE_ID_POTRANQUILITY", EQ_ZONE_ID_POTRANQUILITY);
    state->set("EQ_ZONE_ID_CODECAY", EQ_ZONE_ID_CODECAY);
    state->set("EQ_ZONE_ID_POJUSTICE", EQ_ZONE_ID_POJUSTICE);
    state->set("EQ_ZONE_ID_PONIGHTMARE", EQ_ZONE_ID_PONIGHTMARE);
    state->set("EQ_ZONE_ID_NIGHTMAREB", EQ_ZONE_ID_NIGHTMAREB);
    state->set("EQ_ZONE_ID_PODISEASE", EQ_ZONE_ID_PODISEASE);
    state->set("EQ_ZONE_ID_POINNOVATION", EQ_ZONE_ID_POINNOVATION);
    state->set("EQ_ZONE_ID_POTORMENT", EQ_ZONE_ID_POTORMENT);
    state->set("EQ_ZONE_ID_POVALOR", EQ_ZONE_ID_POVALOR);
    state->set("EQ_ZONE_ID_BOTHUNDER", EQ_ZONE_ID_BOTHUNDER);
    state->set("EQ_ZONE_ID_POSTORMS", EQ_ZONE_ID_POSTORMS);
    state->set("EQ_ZONE_ID_HOHONORA", EQ_ZONE_ID_HOHONORA);
    state->set("EQ_ZONE_ID_HOHONORB", EQ_ZONE_ID_HOHONORB);
    state->set("EQ_ZONE_ID_SOLROTOWER", EQ_ZONE_ID_SOLROTOWER);
    state->set("EQ_ZONE_ID_POWAR", EQ_ZONE_ID_POWAR);
    state->set("EQ_ZONE_ID_POTACTICS", EQ_ZONE_ID_POTACTICS);
    state->set("EQ_ZONE_ID_POAIR", EQ_ZONE_ID_POAIR);
    state->set("EQ_ZONE_ID_POWATER", EQ_ZONE_ID_POWATER);
    state->set("EQ_ZONE_ID_POFIRE", EQ_ZONE_ID_POFIRE);
    state->set("EQ_ZONE_ID_POEARTHA", EQ_ZONE_ID_POEARTHA);
    state->set("EQ_ZONE_ID_POEARTHB", EQ_ZONE_ID_POEARTHB);
    state->set("EQ_ZONE_ID_POTIMEA", EQ_ZONE_ID_POTIMEA);
    state->set("EQ_ZONE_ID_POTIMEB", EQ_ZONE_ID_POTIMEB);
    state->set("EQ_ZONE_ID_TORGIRAN", EQ_ZONE_ID_TORGIRAN);
    state->set("EQ_ZONE_ID_NADOX", EQ_ZONE_ID_NADOX);
    state->set("EQ_ZONE_ID_GUNTHAK", EQ_ZONE_ID_GUNTHAK);
    state->set("EQ_ZONE_ID_DULAK", EQ_ZONE_ID_DULAK);
    state->set("EQ_ZONE_ID_HATESFURY", EQ_ZONE_ID_HATESFURY);
    state->set("EQ_ZONE_ID_HATEPLANEB", EQ_ZONE_ID_HATEPLANEB);
    state->set("EQ_ZONE_ID_CHARDOKB", EQ_ZONE_ID_CHARDOKB);
    state->set("EQ_ZONE_ID_SOLDUNGC", EQ_ZONE_ID_SOLDUNGC);
    state->set("EQ_ZONE_ID_GUKA", EQ_ZONE_ID_GUKA);
    state->set("EQ_ZONE_ID_RUJA", EQ_ZONE_ID_RUJA);
    state->set("EQ_ZONE_ID_TAKA", EQ_ZONE_ID_TAKA);
    state->set("EQ_ZONE_ID_MIRA", EQ_ZONE_ID_MIRA);
    state->set("EQ_ZONE_ID_MMCA", EQ_ZONE_ID_MMCA);
    state->set("EQ_ZONE_ID_GUKB", EQ_ZONE_ID_GUKB);
    state->set("EQ_ZONE_ID_RUJB", EQ_ZONE_ID_RUJB);
    state->set("EQ_ZONE_ID_TAKB", EQ_ZONE_ID_TAKB);
    state->set("EQ_ZONE_ID_MIRB", EQ_ZONE_ID_MIRB);
    state->set("EQ_ZONE_ID_MMCB", EQ_ZONE_ID_MMCB);
    state->set("EQ_ZONE_ID_GUKC", EQ_ZONE_ID_GUKC);
    state->set("EQ_ZONE_ID_RUJC", EQ_ZONE_ID_RUJC);
    state->set("EQ_ZONE_ID_TAKC", EQ_ZONE_ID_TAKC);
    state->set("EQ_ZONE_ID_MIRC", EQ_ZONE_ID_MIRC);
    state->set("EQ_ZONE_ID_MMCC", EQ_ZONE_ID_MMCC);
    state->set("EQ_ZONE_ID_GUKD", EQ_ZONE_ID_GUKD);
    state->set("EQ_ZONE_ID_RUJD", EQ_ZONE_ID_RUJD);
    state->set("EQ_ZONE_ID_TAKD", EQ_ZONE_ID_TAKD);
    state->set("EQ_ZONE_ID_MIRD", EQ_ZONE_ID_MIRD);
    state->set("EQ_ZONE_ID_MMCD", EQ_ZONE_ID_MMCD);
    state->set("EQ_ZONE_ID_GUKE", EQ_ZONE_ID_GUKE);
    state->set("EQ_ZONE_ID_RUJE", EQ_ZONE_ID_RUJE);
    state->set("EQ_ZONE_ID_TAKE", EQ_ZONE_ID_TAKE);
    state->set("EQ_ZONE_ID_MIRE", EQ_ZONE_ID_MIRE);
    state->set("EQ_ZONE_ID_MMCE", EQ_ZONE_ID_MMCE);
    state->set("EQ_ZONE_ID_GUKF", EQ_ZONE_ID_GUKF);
    state->set("EQ_ZONE_ID_RUJF", EQ_ZONE_ID_RUJF);
    state->set("EQ_ZONE_ID_TAKF", EQ_ZONE_ID_TAKF);
    state->set("EQ_ZONE_ID_MIRF", EQ_ZONE_ID_MIRF);
    state->set("EQ_ZONE_ID_MMCF", EQ_ZONE_ID_MMCF);
    state->set("EQ_ZONE_ID_GUKG", EQ_ZONE_ID_GUKG);
    state->set("EQ_ZONE_ID_RUJG", EQ_ZONE_ID_RUJG);
    state->set("EQ_ZONE_ID_TAKG", EQ_ZONE_ID_TAKG);
    state->set("EQ_ZONE_ID_MIRG", EQ_ZONE_ID_MIRG);
    state->set("EQ_ZONE_ID_MMCG", EQ_ZONE_ID_MMCG);
    state->set("EQ_ZONE_ID_GUKH", EQ_ZONE_ID_GUKH);
    state->set("EQ_ZONE_ID_RUJH", EQ_ZONE_ID_RUJH);
    state->set("EQ_ZONE_ID_TAKH", EQ_ZONE_ID_TAKH);
    state->set("EQ_ZONE_ID_MIRH", EQ_ZONE_ID_MIRH);
    state->set("EQ_ZONE_ID_MMCH", EQ_ZONE_ID_MMCH);
    state->set("EQ_ZONE_ID_RUJI", EQ_ZONE_ID_RUJI);
    state->set("EQ_ZONE_ID_TAKI", EQ_ZONE_ID_TAKI);
    state->set("EQ_ZONE_ID_MIRI", EQ_ZONE_ID_MIRI);
    state->set("EQ_ZONE_ID_MMCI", EQ_ZONE_ID_MMCI);
    state->set("EQ_ZONE_ID_RUJJ", EQ_ZONE_ID_RUJJ);
    state->set("EQ_ZONE_ID_TAKJ", EQ_ZONE_ID_TAKJ);
    state->set("EQ_ZONE_ID_MIRJ", EQ_ZONE_ID_MIRJ);
    state->set("EQ_ZONE_ID_MMCJ", EQ_ZONE_ID_MMCJ);
    state->set("EQ_ZONE_ID_ARENA", EQ_ZONE_ID_ARENA);
    state->set("EQ_ZONE_ID_ABYSMAL", EQ_ZONE_ID_ABYSMAL);
    state->set("EQ_ZONE_ID_NATIMBI", EQ_ZONE_ID_NATIMBI);
    state->set("EQ_ZONE_ID_QINIMI", EQ_ZONE_ID_QINIMI);
    state->set("EQ_ZONE_ID_RIWWI", EQ_ZONE_ID_RIWWI);
    state->set("EQ_ZONE_ID_BARINDU", EQ_ZONE_ID_BARINDU);
    state->set("EQ_ZONE_ID_SNPOOL", EQ_ZONE_ID_SNPOOL);
    state->set("EQ_ZONE_ID_TIPT", EQ_ZONE_ID_TIPT);
    state->set("EQ_ZONE_ID_VXED", EQ_ZONE_ID_VXED);
    state->set("EQ_ZONE_ID_YXTTA", EQ_ZONE_ID_YXTTA);
    state->set("EQ_ZONE_ID_UQUA", EQ_ZONE_ID_UQUA);
    state->set("EQ_ZONE_ID_KODTAZ", EQ_ZONE_ID_KODTAZ);
    state->set("EQ_ZONE_ID_IKKINZ", EQ_ZONE_ID_IKKINZ);
    state->set("EQ_ZONE_ID_INKTUTA", EQ_ZONE_ID_INKTUTA);
    state->set("EQ_ZONE_ID_TXEVU", EQ_ZONE_ID_TXEVU);
    state->set("EQ_ZONE_ID_TACVI", EQ_ZONE_ID_TACVI);
    state->set("EQ_ZONE_ID_QVIC", EQ_ZONE_ID_QVIC);
    state->set("EQ_ZONE_ID_QVICB", EQ_ZONE_ID_QVICB);
    state->set("EQ_ZONE_ID_WALLOFSLAUGHTER", EQ_ZONE_ID_WALLOFSLAUGHTER);
    state->set("EQ_ZONE_ID_BLOODFIELDS", EQ_ZONE_ID_BLOODFIELDS);
    state->set("EQ_ZONE_ID_DRANIKSSCAR", EQ_ZONE_ID_DRANIKSSCAR);
    state->set("EQ_ZONE_ID_CAUSEWAY", EQ_ZONE_ID_CAUSEWAY);
    state->set("EQ_ZONE_ID_CHAMBERSA", EQ_ZONE_ID_CHAMBERSA);
    state->set("EQ_ZONE_ID_CHAMBERSB", EQ_ZONE_ID_CHAMBERSB);
    state->set("EQ_ZONE_ID_CHAMBERSC", EQ_ZONE_ID_CHAMBERSC);
    state->set("EQ_ZONE_ID_CHAMBERSD", EQ_ZONE_ID_CHAMBERSD);
    state->set("EQ_ZONE_ID_CHAMBERSE", EQ_ZONE_ID_CHAMBERSE);
    state->set("EQ_ZONE_ID_CHAMBERSF", EQ_ZONE_ID_CHAMBERSF);
    state->set("EQ_ZONE_ID_PROVINGGROUNDS", EQ_ZONE_ID_PROVINGGROUNDS);
    state->set("EQ_ZONE_ID_ANGUISH", EQ_ZONE_ID_ANGUISH);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSA", EQ_ZONE_ID_DRANIKHOLLOWSA);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSB", EQ_ZONE_ID_DRANIKHOLLOWSB);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSC", EQ_ZONE_ID_DRANIKHOLLOWSC);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSD", EQ_ZONE_ID_DRANIKHOLLOWSD);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSE", EQ_ZONE_ID_DRANIKHOLLOWSE);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSF", EQ_ZONE_ID_DRANIKHOLLOWSF);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSG", EQ_ZONE_ID_DRANIKHOLLOWSG);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSH", EQ_ZONE_ID_DRANIKHOLLOWSH);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSI", EQ_ZONE_ID_DRANIKHOLLOWSI);
    state->set("EQ_ZONE_ID_DRANIKHOLLOWSJ", EQ_ZONE_ID_DRANIKHOLLOWSJ);
    state->set("EQ_ZONE_ID_DRANIKCATACOMBSA", EQ_ZONE_ID_DRANIKCATACOMBSA);
    state->set("EQ_ZONE_ID_DRANIKCATACOMBSB", EQ_ZONE_ID_DRANIKCATACOMBSB);
    state->set("EQ_ZONE_ID_DRANIKCATACOMBSC", EQ_ZONE_ID_DRANIKCATACOMBSC);
    state->set("EQ_ZONE_ID_DRANIKSEWERSA", EQ_ZONE_ID_DRANIKSEWERSA);
    state->set("EQ_ZONE_ID_DRANIKSEWERSB", EQ_ZONE_ID_DRANIKSEWERSB);
    state->set("EQ_ZONE_ID_DRANIKSEWERSC", EQ_ZONE_ID_DRANIKSEWERSC);
    state->set("EQ_ZONE_ID_RIFTSEEKERS", EQ_ZONE_ID_RIFTSEEKERS);
    state->set("EQ_ZONE_ID_HARBINGERS", EQ_ZONE_ID_HARBINGERS);
    state->set("EQ_ZONE_ID_DRANIK", EQ_ZONE_ID_DRANIK);
    state->set("EQ_ZONE_ID_FHALLS", EQ_ZONE_ID_FHALLS);
    state->set("EQ_ZONE_ID_BROODLANDS", EQ_ZONE_ID_BROODLANDS);
    state->set("EQ_ZONE_ID_STILLMOONA", EQ_ZONE_ID_STILLMOONA);
    state->set("EQ_ZONE_ID_STILLMOONB", EQ_ZONE_ID_STILLMOONB);
    state->set("EQ_ZONE_ID_THUNDERCREST", EQ_ZONE_ID_THUNDERCREST);
    state->set("EQ_ZONE_ID_DELVEA", EQ_ZONE_ID_DELVEA);
    state->set("EQ_ZONE_ID_DELVEB", EQ_ZONE_ID_DELVEB);
    state->set("EQ_ZONE_ID_THENEST", EQ_ZONE_ID_THENEST);
    state->set("EQ_ZONE_ID_GUILDLOBBY", EQ_ZONE_ID_GUILDLOBBY);
    state->set("EQ_ZONE_ID_GUILDHALL", EQ_ZONE_ID_GUILDHALL);
    state->set("EQ_ZONE_ID_BARTER", EQ_ZONE_ID_BARTER);
    state->set("EQ_ZONE_ID_ILLSALIN", EQ_ZONE_ID_ILLSALIN);
    state->set("EQ_ZONE_ID_ILLSALINA", EQ_ZONE_ID_ILLSALINA);
    state->set("EQ_ZONE_ID_ILLSALINB", EQ_ZONE_ID_ILLSALINB);
    state->set("EQ_ZONE_ID_ILLSALINC", EQ_ZONE_ID_ILLSALINC);
    state->set("EQ_ZONE_ID_DREADSPIRE", EQ_ZONE_ID_DREADSPIRE);
    state->set("EQ_ZONE_ID_DRACHNIDHIVE", EQ_ZONE_ID_DRACHNIDHIVE);
    state->set("EQ_ZONE_ID_DRACHNIDHIVEA", EQ_ZONE_ID_DRACHNIDHIVEA);
    state->set("EQ_ZONE_ID_DRACHNIDHIVEB", EQ_ZONE_ID_DRACHNIDHIVEB);
    state->set("EQ_ZONE_ID_DRACHNIDHIVEC", EQ_ZONE_ID_DRACHNIDHIVEC);
    state->set("EQ_ZONE_ID_WESTKORLACH", EQ_ZONE_ID_WESTKORLACH);
    state->set("EQ_ZONE_ID_WESTKORLACHA", EQ_ZONE_ID_WESTKORLACHA);
    state->set("EQ_ZONE_ID_WESTKORLACHB", EQ_ZONE_ID_WESTKORLACHB);
    state->set("EQ_ZONE_ID_WESTKORLACHC", EQ_ZONE_ID_WESTKORLACHC);
    state->set("EQ_ZONE_ID_EASTKORLACH", EQ_ZONE_ID_EASTKORLACH);
    state->set("EQ_ZONE_ID_EASTKORLACHA", EQ_ZONE_ID_EASTKORLACHA);
    state->set("EQ_ZONE_ID_SHADOWSPINE", EQ_ZONE_ID_SHADOWSPINE);
    state->set("EQ_ZONE_ID_CORATHUS", EQ_ZONE_ID_CORATHUS);
    state->set("EQ_ZONE_ID_CORATHUSA", EQ_ZONE_ID_CORATHUSA);
    state->set("EQ_ZONE_ID_CORATHUSB", EQ_ZONE_ID_CORATHUSB);
    state->set("EQ_ZONE_ID_NEKTULOSA", EQ_ZONE_ID_NEKTULOSA);
    state->set("EQ_ZONE_ID_ARCSTONE", EQ_ZONE_ID_ARCSTONE);
    state->set("EQ_ZONE_ID_RELIC", EQ_ZONE_ID_RELIC);
    state->set("EQ_ZONE_ID_SKYLANCE", EQ_ZONE_ID_SKYLANCE);
    state->set("EQ_ZONE_ID_DEVASTATION", EQ_ZONE_ID_DEVASTATION);
    state->set("EQ_ZONE_ID_DEVASTATIONA", EQ_ZONE_ID_DEVASTATIONA);
    state->set("EQ_ZONE_ID_RAGE", EQ_ZONE_ID_RAGE);
    state->set("EQ_ZONE_ID_RAGEA", EQ_ZONE_ID_RAGEA);
    state->set("EQ_ZONE_ID_TAKISHRUINS", EQ_ZONE_ID_TAKISHRUINS);
    state->set("EQ_ZONE_ID_TAKISHRUINSA", EQ_ZONE_ID_TAKISHRUINSA);
    state->set("EQ_ZONE_ID_ELDDAR", EQ_ZONE_ID_ELDDAR);
    state->set("EQ_ZONE_ID_ELDDARA", EQ_ZONE_ID_ELDDARA);
    state->set("EQ_ZONE_ID_THEATER", EQ_ZONE_ID_THEATER);
    state->set("EQ_ZONE_ID_THEATERA", EQ_ZONE_ID_THEATERA);
    state->set("EQ_ZONE_ID_FREEPORTEAST", EQ_ZONE_ID_FREEPORTEAST);
    state->set("EQ_ZONE_ID_FREEPORTWEST", EQ_ZONE_ID_FREEPORTWEST);
    state->set("EQ_ZONE_ID_FREEPORTSEWERS", EQ_ZONE_ID_FREEPORTSEWERS);
    state->set("EQ_ZONE_ID_FREEPORTACADEMY", EQ_ZONE_ID_FREEPORTACADEMY);
    state->set("EQ_ZONE_ID_FREEPORTTEMPLE", EQ_ZONE_ID_FREEPORTTEMPLE);
    state->set("EQ_ZONE_ID_FREEPORTMILITIA", EQ_ZONE_ID_FREEPORTMILITIA);
    state->set("EQ_ZONE_ID_FREEPORTARENA", EQ_ZONE_ID_FREEPORTARENA);
    state->set("EQ_ZONE_ID_FREEPORTCITYHALL", EQ_ZONE_ID_FREEPORTCITYHALL);
    state->set("EQ_ZONE_ID_FREEPORTTHEATER", EQ_ZONE_ID_FREEPORTTHEATER);
    state->set("EQ_ZONE_ID_FREEPORTHALL", EQ_ZONE_ID_FREEPORTHALL);
    state->set("EQ_ZONE_ID_NORTHRO", EQ_ZONE_ID_NORTHRO);
    state->set("EQ_ZONE_ID_SOUTHRO", EQ_ZONE_ID_SOUTHRO);
    state->set("EQ_ZONE_ID_CRESCENT", EQ_ZONE_ID_CRESCENT);
    state->set("EQ_ZONE_ID_MOORS", EQ_ZONE_ID_MOORS);
    state->set("EQ_ZONE_ID_STONEHIVE", EQ_ZONE_ID_STONEHIVE);
    state->set("EQ_ZONE_ID_MESA", EQ_ZONE_ID_MESA);
    state->set("EQ_ZONE_ID_ROOST", EQ_ZONE_ID_ROOST);
    state->set("EQ_ZONE_ID_STEPPES", EQ_ZONE_ID_STEPPES);
    state->set("EQ_ZONE_ID_ICEFALL", EQ_ZONE_ID_ICEFALL);
    state->set("EQ_ZONE_ID_VALDEHOLM", EQ_ZONE_ID_VALDEHOLM);
    state->set("EQ_ZONE_ID_SUNDEROCK", EQ_ZONE_ID_SUNDEROCK);
    state->set("EQ_ZONE_ID_VERGALID", EQ_ZONE_ID_VERGALID);
    state->set("EQ_ZONE_ID_DIREWIND", EQ_ZONE_ID_DIREWIND);
    state->set("EQ_ZONE_ID_ASHENGATE", EQ_ZONE_ID_ASHENGATE);
    state->set("EQ_ZONE_ID_HIGHPASSHOLD", EQ_ZONE_ID_HIGHPASSHOLD);
    state->set("EQ_ZONE_ID_KATTACASTRUM", EQ_ZONE_ID_KATTACASTRUM);
    state->set("EQ_ZONE_ID_THALASSIUS", EQ_ZONE_ID_THALASSIUS);
    state->set("EQ_ZONE_ID_ATIIKI", EQ_ZONE_ID_ATIIKI);
    state->set("EQ_ZONE_ID_ZHISZA", EQ_ZONE_ID_ZHISZA);
    state->set("EQ_ZONE_ID_SILYSSAR", EQ_ZONE_ID_SILYSSAR);
    state->set("EQ_ZONE_ID_SOLTERIS", EQ_ZONE_ID_SOLTERIS);
    state->set("EQ_ZONE_ID_BARREN", EQ_ZONE_ID_BARREN);
    state->set("EQ_ZONE_ID_BURIEDSEA", EQ_ZONE_ID_BURIEDSEA);
    state->set("EQ_ZONE_ID_JARDELSHOOK", EQ_ZONE_ID_JARDELSHOOK);
    state->set("EQ_ZONE_ID_MONKEYROCK", EQ_ZONE_ID_MONKEYROCK);
    state->set("EQ_ZONE_ID_SUNCREST", EQ_ZONE_ID_SUNCREST);
    state->set("EQ_ZONE_ID_DEADBONE", EQ_ZONE_ID_DEADBONE);
    state->set("EQ_ZONE_ID_BLACKSAIL", EQ_ZONE_ID_BLACKSAIL);
    state->set("EQ_ZONE_ID_MAIDENSGRAVE", EQ_ZONE_ID_MAIDENSGRAVE);
    state->set("EQ_ZONE_ID_REDFEATHER", EQ_ZONE_ID_REDFEATHER);
    state->set("EQ_ZONE_ID_SHIPMVP", EQ_ZONE_ID_SHIPMVP);
    state->set("EQ_ZONE_ID_SHIPMVU", EQ_ZONE_ID_SHIPMVU);
    state->set("EQ_ZONE_ID_SHIPPVU", EQ_ZONE_ID_SHIPPVU);
    state->set("EQ_ZONE_ID_SHIPUVU", EQ_ZONE_ID_SHIPUVU);
    state->set("EQ_ZONE_ID_SHIPMVM", EQ_ZONE_ID_SHIPMVM);
    state->set("EQ_ZONE_ID_MECHANOTUS", EQ_ZONE_ID_MECHANOTUS);
    state->set("EQ_ZONE_ID_MANSION", EQ_ZONE_ID_MANSION);
    state->set("EQ_ZONE_ID_STEAMFACTORY", EQ_ZONE_ID_STEAMFACTORY);
    state->set("EQ_ZONE_ID_SHIPWORKSHOP", EQ_ZONE_ID_SHIPWORKSHOP);
    state->set("EQ_ZONE_ID_GYROSPIREB", EQ_ZONE_ID_GYROSPIREB);
    state->set("EQ_ZONE_ID_GYROSPIREZ", EQ_ZONE_ID_GYROSPIREZ);
    state->set("EQ_ZONE_ID_DRAGONSCALE", EQ_ZONE_ID_DRAGONSCALE);
    state->set("EQ_ZONE_ID_LOPINGPLAINS", EQ_ZONE_ID_LOPINGPLAINS);
    state->set("EQ_ZONE_ID_HILLSOFSHADE", EQ_ZONE_ID_HILLSOFSHADE);
    state->set("EQ_ZONE_ID_BLOODMOON", EQ_ZONE_ID_BLOODMOON);
    state->set("EQ_ZONE_ID_CRYSTALLOS", EQ_ZONE_ID_CRYSTALLOS);
    state->set("EQ_ZONE_ID_GUARDIAN", EQ_ZONE_ID_GUARDIAN);
    state->set("EQ_ZONE_ID_CRYPTOFSHADE", EQ_ZONE_ID_CRYPTOFSHADE);
    state->set("EQ_ZONE_ID_DRAGONSCALEA", EQ_ZONE_ID_DRAGONSCALEA);
    state->set("EQ_ZONE_ID_DRAGONSCALEB", EQ_ZONE_ID_DRAGONSCALEB);
    state->set("EQ_ZONE_ID_OLDFIELDOFBONE", EQ_ZONE_ID_OLDFIELDOFBONE);
    state->set("EQ_ZONE_ID_OLDFIELDOFBONEB", EQ_ZONE_ID_OLDFIELDOFBONEB);
    state->set("EQ_ZONE_ID_OLDKAESORAA", EQ_ZONE_ID_OLDKAESORAA);
    state->set("EQ_ZONE_ID_OLDKAESORAB", EQ_ZONE_ID_OLDKAESORAB);
    state->set("EQ_ZONE_ID_OLDKURN", EQ_ZONE_ID_OLDKURN);
    state->set("EQ_ZONE_ID_OLDKITHICOR", EQ_ZONE_ID_OLDKITHICOR);
    state->set("EQ_ZONE_ID_OLDCOMMONS", EQ_ZONE_ID_OLDCOMMONS);
    state->set("EQ_ZONE_ID_OLDHIGHPASS", EQ_ZONE_ID_OLDHIGHPASS);
    state->set("EQ_ZONE_ID_THEVOIDA", EQ_ZONE_ID_THEVOIDA);
    state->set("EQ_ZONE_ID_THEVOIDB", EQ_ZONE_ID_THEVOIDB);
    state->set("EQ_ZONE_ID_THEVOIDC", EQ_ZONE_ID_THEVOIDC);
    state->set("EQ_ZONE_ID_THEVOIDD", EQ_ZONE_ID_THEVOIDD);
    state->set("EQ_ZONE_ID_THEVOIDE", EQ_ZONE_ID_THEVOIDE);
    state->set("EQ_ZONE_ID_THEVOIDF", EQ_ZONE_ID_THEVOIDF);
    state->set("EQ_ZONE_ID_THEVOIDG", EQ_ZONE_ID_THEVOIDG);
    state->set("EQ_ZONE_ID_OCEANGREENHILLS", EQ_ZONE_ID_OCEANGREENHILLS);
    state->set("EQ_ZONE_ID_OCEANGREENVILLAGE", EQ_ZONE_ID_OCEANGREENVILLAGE);
    state->set("EQ_ZONE_ID_OLDBLACKBURROW", EQ_ZONE_ID_OLDBLACKBURROW);
    state->set("EQ_ZONE_ID_BERTOXTEMPLE", EQ_ZONE_ID_BERTOXTEMPLE);
    state->set("EQ_ZONE_ID_DISCORD", EQ_ZONE_ID_DISCORD);
    state->set("EQ_ZONE_ID_DISCORDTOWER", EQ_ZONE_ID_DISCORDTOWER);
    state->set("EQ_ZONE_ID_OLDBLOODFIELD", EQ_ZONE_ID_OLDBLOODFIELD);
    state->set("EQ_ZONE_ID_PRECIPICEOFWAR", EQ_ZONE_ID_PRECIPICEOFWAR);
    state->set("EQ_ZONE_ID_OLDDRANIK", EQ_ZONE_ID_OLDDRANIK);
    state->set("EQ_ZONE_ID_TOSKIRAKK", EQ_ZONE_ID_TOSKIRAKK);
    state->set("EQ_ZONE_ID_KORASCIAN", EQ_ZONE_ID_KORASCIAN);
    state->set("EQ_ZONE_ID_RATHECHAMBER", EQ_ZONE_ID_RATHECHAMBER);
    state->set("EQ_ZONE_ID_STEAMFONTMTS", EQ_ZONE_ID_STEAMFONTMTS);
    state->set("EQ_ZONE_ID_CRAFTHALLS", EQ_ZONE_ID_CRAFTHALLS);
    state->set("EQ_ZONE_ID_BRELLSREST", EQ_ZONE_ID_BRELLSREST);
    state->set("EQ_ZONE_ID_FUNGALFOREST", EQ_ZONE_ID_FUNGALFOREST);
    state->set("EQ_ZONE_ID_UNDERQUARRY", EQ_ZONE_ID_UNDERQUARRY);
    state->set("EQ_ZONE_ID_COOLINGCHAMBER", EQ_ZONE_ID_COOLINGCHAMBER);
    state->set("EQ_ZONE_ID_SHININGCITY", EQ_ZONE_ID_SHININGCITY);
    state->set("EQ_ZONE_ID_ARTHICREX", EQ_ZONE_ID_ARTHICREX);
    state->set("EQ_ZONE_ID_FOUNDATION", EQ_ZONE_ID_FOUNDATION);
    state->set("EQ_ZONE_ID_LICHENCREEP", EQ_ZONE_ID_LICHENCREEP);
    state->set("EQ_ZONE_ID_PELLUCID", EQ_ZONE_ID_PELLUCID);
    state->set("EQ_ZONE_ID_STONESNAKE", EQ_ZONE_ID_STONESNAKE);
    state->set("EQ_ZONE_ID_BRELLSTEMPLE", EQ_ZONE_ID_BRELLSTEMPLE);
    state->set("EQ_ZONE_ID_CONVORTEUM", EQ_ZONE_ID_CONVORTEUM);
    state->set("EQ_ZONE_ID_BRELLSARENA", EQ_ZONE_ID_BRELLSARENA);
    state->set("EQ_ZONE_ID_WEDDINGCHAPEL", EQ_ZONE_ID_WEDDINGCHAPEL);
    state->set("EQ_ZONE_ID_WEDDINGCHAPELDARK", EQ_ZONE_ID_WEDDINGCHAPELDARK);
    state->set("EQ_ZONE_ID_DRAGONCRYPT", EQ_ZONE_ID_DRAGONCRYPT);
    state->set("EQ_ZONE_ID_FEERROTT2", EQ_ZONE_ID_FEERROTT2);
    state->set("EQ_ZONE_ID_THULEHOUSE1", EQ_ZONE_ID_THULEHOUSE1);
    state->set("EQ_ZONE_ID_THULEHOUSE2", EQ_ZONE_ID_THULEHOUSE2);
    state->set("EQ_ZONE_ID_HOUSEGARDEN", EQ_ZONE_ID_HOUSEGARDEN);
    state->set("EQ_ZONE_ID_THULELIBRARY", EQ_ZONE_ID_THULELIBRARY);
    state->set("EQ_ZONE_ID_WELL", EQ_ZONE_ID_WELL);
    state->set("EQ_ZONE_ID_FALLEN", EQ_ZONE_ID_FALLEN);
    state->set("EQ_ZONE_ID_MORELLCASTLE", EQ_ZONE_ID_MORELLCASTLE);
    state->set("EQ_ZONE_ID_SOMNIUM", EQ_ZONE_ID_SOMNIUM);
    state->set("EQ_ZONE_ID_ALKABORMARE", EQ_ZONE_ID_ALKABORMARE);
    state->set("EQ_ZONE_ID_MIRAGULMARE", EQ_ZONE_ID_MIRAGULMARE);
    state->set("EQ_ZONE_ID_THULEDREAM", EQ_ZONE_ID_THULEDREAM);
    state->set("EQ_ZONE_ID_NEIGHBORHOOD", EQ_ZONE_ID_NEIGHBORHOOD);
    state->set("EQ_ZONE_ID_PHYLACTERY", EQ_ZONE_ID_PHYLACTERY);
    state->set("EQ_ZONE_ID_PHINTERIOR3A1", EQ_ZONE_ID_PHINTERIOR3A1);
    state->set("EQ_ZONE_ID_PHINTERIOR3A2", EQ_ZONE_ID_PHINTERIOR3A2);
    state->set("EQ_ZONE_ID_PHINTERIOR3A3", EQ_ZONE_ID_PHINTERIOR3A3);
    state->set("EQ_ZONE_ID_PHINTERIOR1A1", EQ_ZONE_ID_PHINTERIOR1A1);
    state->set("EQ_ZONE_ID_PHINTERIOR1A2", EQ_ZONE_ID_PHINTERIOR1A2);
    state->set("EQ_ZONE_ID_PHINTERIOR1A3", EQ_ZONE_ID_PHINTERIOR1A3);
    state->set("EQ_ZONE_ID_PHINTERIOR1A3", EQ_ZONE_ID_PHINTERIOR1A3);
    state->set("EQ_ZONE_ID_PHINTERIOR1B1", EQ_ZONE_ID_PHINTERIOR1B1);
    state->set("EQ_ZONE_ID_PHINTERIOR1D1", EQ_ZONE_ID_PHINTERIOR1D1);
    state->set("EQ_ZONE_ID_ARGATH", EQ_ZONE_ID_ARGATH);
    state->set("EQ_ZONE_ID_ARELIS", EQ_ZONE_ID_ARELIS);
    state->set("EQ_ZONE_ID_SARITHCITY", EQ_ZONE_ID_SARITHCITY);
    state->set("EQ_ZONE_ID_RUBAK", EQ_ZONE_ID_RUBAK);
    state->set("EQ_ZONE_ID_BEASTDOMAIN", EQ_ZONE_ID_BEASTDOMAIN);
    state->set("EQ_ZONE_ID_RESPLENDENT", EQ_ZONE_ID_RESPLENDENT);
    state->set("EQ_ZONE_ID_PILLARSALRA", EQ_ZONE_ID_PILLARSALRA);
    state->set("EQ_ZONE_ID_WINDSONG", EQ_ZONE_ID_WINDSONG);
    state->set("EQ_ZONE_ID_CITYOFBRONZE", EQ_ZONE_ID_CITYOFBRONZE);
    state->set("EQ_ZONE_ID_SEPULCHER", EQ_ZONE_ID_SEPULCHER);
    state->set("EQ_ZONE_ID_EASTSEPULCHER", EQ_ZONE_ID_EASTSEPULCHER);
    state->set("EQ_ZONE_ID_WESTSEPULCHER", EQ_ZONE_ID_WESTSEPULCHER);
    state->set("EQ_ZONE_ID_SHADOWEDMOUNT", EQ_ZONE_ID_SHADOWEDMOUNT);
    state->set("EQ_ZONE_ID_GUILDHALLLRG", EQ_ZONE_ID_GUILDHALLLRG);
    state->set("EQ_ZONE_ID_GUILDHALLSML", EQ_ZONE_ID_GUILDHALLSML);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS1A1", EQ_ZONE_ID_PLHOGRINTERIORS1A1);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS1A2", EQ_ZONE_ID_PLHOGRINTERIORS1A2);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS3A1", EQ_ZONE_ID_PLHOGRINTERIORS3A1);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS3A2", EQ_ZONE_ID_PLHOGRINTERIORS3A2);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS3B1", EQ_ZONE_ID_PLHOGRINTERIORS3B1);
    state->set("EQ_ZONE_ID_PLHOGRINTERIORS3B2", EQ_ZONE_ID_PLHOGRINTERIORS3B2);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS1A1", EQ_ZONE_ID_PLHDKEINTERIORS1A1);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS1A2", EQ_ZONE_ID_PLHDKEINTERIORS1A2);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS1A3", EQ_ZONE_ID_PLHDKEINTERIORS1A3);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS3A1", EQ_ZONE_ID_PLHDKEINTERIORS3A1);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS3A2", EQ_ZONE_ID_PLHDKEINTERIORS3A2);
    state->set("EQ_ZONE_ID_PLHDKEINTERIORS3A3", EQ_ZONE_ID_PLHDKEINTERIORS3A3);
    state->set("EQ_ZONE_ID_GUILDHALL3", EQ_ZONE_ID_GUILDHALL3);
    state->set("EQ_ZONE_ID_KAELSHARD", EQ_ZONE_ID_KAELSHARD);
    state->set("EQ_ZONE_ID_CRYSTALSHARD", EQ_ZONE_ID_CRYSTALSHARD);
    state->set("EQ_ZONE_ID_SHARDSLANDING", EQ_ZONE_ID_SHARDSLANDING);
    state->set("EQ_ZONE_ID_XORBB", EQ_ZONE_ID_XORBB);
    state->set("EQ_ZONE_ID_BREEDINGGROUNDS", EQ_ZONE_ID_BREEDINGGROUNDS);
    state->set("EQ_ZONE_ID_EVILTREE", EQ_ZONE_ID_EVILTREE);
    state->set("EQ_ZONE_ID_GRELLETH", EQ_ZONE_ID_GRELLETH);
    state->set("EQ_ZONE_ID_CHAPTERHOUSE", EQ_ZONE_ID_CHAPTERHOUSE);
    state->set("EQ_ZONE_ID_PHINTERIORTREE", EQ_ZONE_ID_PHINTERIORTREE);
    state->set("EQ_ZONE_ID_CHELSITHREBORN", EQ_ZONE_ID_CHELSITHREBORN);
    state->set("EQ_ZONE_ID_POSHADOW", EQ_ZONE_ID_POSHADOW);
    state->set("EQ_ZONE_ID_HEARTOFFEAR", EQ_ZONE_ID_HEARTOFFEAR);
    state->set("EQ_ZONE_ID_HEARTOFFEARB", EQ_ZONE_ID_HEARTOFFEARB);
    state->set("EQ_ZONE_ID_HEARTOFFEARC", EQ_ZONE_ID_HEARTOFFEARC);
    state->set("EQ_ZONE_ID_NERIAKD", EQ_ZONE_ID_NERIAKD);
    state->set("EQ_ZONE_ID_BIXIEWARFRONT", EQ_ZONE_ID_BIXIEWARFRONT);
    state->set("EQ_ZONE_ID_DEADHILLS", EQ_ZONE_ID_DEADHILLS);
    state->set("EQ_ZONE_ID_ETHERNERE", EQ_ZONE_ID_ETHERNERE);
    state->set("EQ_ZONE_ID_THEVOIDH", EQ_ZONE_ID_THEVOIDH);
    state->set("EQ_ZONE_ID_PLHBIXIEINT", EQ_ZONE_ID_PLHBIXIEINT);
    state->set("EQ_ZONE_ID_TOWEROFROT", EQ_ZONE_ID_TOWEROFROT);
    state->set("EQ_ZONE_ID_ARGINHIZ", EQ_ZONE_ID_ARGINHIZ);
    state->set("EQ_ZONE_ID_ARXMENTIS", EQ_ZONE_ID_ARXMENTIS);
    state->set("EQ_ZONE_ID_BROTHERISLAND", EQ_ZONE_ID_BROTHERISLAND);
    state->set("EQ_ZONE_ID_KATTACASTRUMB", EQ_ZONE_ID_KATTACASTRUMB);
    state->set("EQ_ZONE_ID_DREDGE", EQ_ZONE_ID_DREDGE);
    state->set("EQ_ZONE_ID_ENDLESSCAVERNS", EQ_ZONE_ID_ENDLESSCAVERNS);
    state->set("EQ_ZONE_ID_THULIASAUR", EQ_ZONE_ID_THULIASAUR);
    state->set("EQ_ZONE_ID_DEGMAR", EQ_ZONE_ID_DEGMAR);
    state->set("EQ_ZONE_ID_TEMPESTTEMPLE", EQ_ZONE_ID_TEMPESTTEMPLE);
    state->set("EQ_ZONE_ID_PLHPIRATESHIPINT", EQ_ZONE_ID_PLHPIRATESHIPINT);
    state->set("EQ_ZONE_ID_EXALTED", EQ_ZONE_ID_EXALTED);
    state->set("EQ_ZONE_ID_COSUL", EQ_ZONE_ID_COSUL);
    state->set("EQ_ZONE_ID_CODECAYB", EQ_ZONE_ID_CODECAYB);
    state->set("EQ_ZONE_ID_EXALTEDB", EQ_ZONE_ID_EXALTEDB);
    state->set("EQ_ZONE_ID_POHEALTH", EQ_ZONE_ID_POHEALTH);
    state->set("EQ_ZONE_ID_DROGAB", EQ_ZONE_ID_DROGAB);
    state->set("EQ_ZONE_ID_SCORCHEDWOODS", EQ_ZONE_ID_SCORCHEDWOODS);
    state->set("EQ_ZONE_ID_FRONTIERMTNSB", EQ_ZONE_ID_FRONTIERMTNSB);
    state->set("EQ_ZONE_ID_KORSHAEXT", EQ_ZONE_ID_KORSHAEXT);
    state->set("EQ_ZONE_ID_KORSHAINT", EQ_ZONE_ID_KORSHAINT);
    state->set("EQ_ZONE_ID_LCEANIUM", EQ_ZONE_ID_LCEANIUM);
    state->set("EQ_ZONE_ID_CHARDOKTWO", EQ_ZONE_ID_CHARDOKTWO);
    state->set("EQ_ZONE_ID_CHARASISB", EQ_ZONE_ID_CHARASISB);
    state->set("EQ_ZONE_ID_GOROWYN", EQ_ZONE_ID_GOROWYN);
    state->set("EQ_ZONE_ID_CHARASISTWO", EQ_ZONE_ID_CHARASISTWO);
    state->set("EQ_ZONE_ID_SKYFIRETWO", EQ_ZONE_ID_SKYFIRETWO);
    state->set("EQ_ZONE_ID_OVERTHERETWO", EQ_ZONE_ID_OVERTHERETWO);
    state->set("EQ_ZONE_ID_VEESHANTWO", EQ_ZONE_ID_VEESHANTWO);
    state->set("EQ_ZONE_ID_TRIALSOFSMOKE", EQ_ZONE_ID_TRIALSOFSMOKE);
    state->set("EQ_ZONE_ID_STRATOS", EQ_ZONE_ID_STRATOS);
    state->set("EQ_ZONE_ID_AALISHAI", EQ_ZONE_ID_AALISHAI);
    state->set("EQ_ZONE_ID_EMPYR", EQ_ZONE_ID_EMPYR);
    state->set("EQ_ZONE_ID_ESIANTI", EQ_ZONE_ID_ESIANTI);
    state->set("EQ_ZONE_ID_MEARATAS", EQ_ZONE_ID_MEARATAS);
    state->set("EQ_ZONE_ID_CHAMBEROFTEARS", EQ_ZONE_ID_CHAMBEROFTEARS);
    state->set("EQ_ZONE_ID_CLZ_ANNIVERSARY", EQ_ZONE_ID_CLZ_ANNIVERSARY);
    state->set("EQ_ZONE_ID_CLZ_AUTUMN", EQ_ZONE_ID_CLZ_AUTUMN);
    state->set("EQ_ZONE_ID_CLZ_FROSTFELL", EQ_ZONE_ID_CLZ_FROSTFELL);
    state->set("EQ_ZONE_ID_CLZ_SPRING", EQ_ZONE_ID_CLZ_SPRING);
    state->set("EQ_ZONE_ID_CLZ_WINTER", EQ_ZONE_ID_CLZ_WINTER);
    state->set("EQ_ZONE_ID_POMISCHIEF", EQ_ZONE_ID_POMISCHIEF);
    state->set("EQ_ZONE_ID_BURNEDWOODS", EQ_ZONE_ID_BURNEDWOODS);
    state->set("EQ_ZONE_ID_INTERIORWALLTEST", EQ_ZONE_ID_INTERIORWALLTEST);
    state->set("EQ_ZONE_ID_GNOMEMTN", EQ_ZONE_ID_GNOMEMTN);

    // EQ functions
    state->set_function("EQ_Log", EQ_Log);

    state->set_function("EQ_CalculateDistance", EQ_CalculateDistance);
    state->set_function("EQ_CalculateDistance3D", EQ_CalculateDistance3D);
    state->set_function("EQ_IsWithinDistance", EQ_IsWithinDistance);

    state->set_function("EQ_GetBearing", EQ_GetBearing);
    state->set_function("EQ_FixHeading", EQ_FixHeadingEx);
    state->set_function("EQ_FixPitch", EQ_FixPitchEx);
    state->set_function("EQ_GetRadians", EQ_GetRadians);

    state->set_function("EQ_IsPointInsideRectangle", EQ_IsPointInsideRectangle);

    state->set_function("EQ_GetGameState", EQ_GetGameState);
    state->set_function("EQ_IsInGame", EQ_IsInGame);
    state->set_function("EQ_IsSpellIDValid", EQ_IsSpellIDValid);
    state->set_function("EQ_IsZoneIDSafe", EQ_IsZoneIDSafe);
    state->set_function("EQ_GetTimer", EQ_GetTimer);

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

    state->set_function("EQ_GetZoneID", EQ_GetZoneID);
    state->set_function("EQ_GetZoneLongName", EQ_GetZoneLongName);
    state->set_function("EQ_GetZoneShortName", EQ_GetZoneShortName);
    state->set_function("EQ_GetZoneGravity", EQ_GetZoneGravity);
    state->set_function("EQ_SetZoneGravity", EQ_SetZoneGravity);

    state->set_function("EQ_IsFogEnabled", EQ_IsFogEnabled);
    state->set_function("EQ_SetFog", EQ_SetFog);
    state->set_function("EQ_GetFogDistanceEnd", EQ_GetFogDistanceEnd);
    state->set_function("EQ_GetFarClipPlane", EQ_GetFarClipPlane);
    state->set_function("EQ_SetFogDistanceBegin", EQ_SetFogDistanceBegin);
    state->set_function("EQ_SetFogDistanceEnd", EQ_SetFogDistanceEnd);
    state->set_function("EQ_SetFarClipPlane", EQ_SetFarClipPlane);
    state->set_function("EQ_SetFarClipPlanePercent", EQ_SetFarClipPlanePercent);

    state->set_function("EQ_GetSpawnByID", EQ_GetSpawnByID);
    state->set_function("EQ_GetSpawnByName", EQ_GetSpawnByName);

    state->set_function("EQ_GetFirstSpawn", EQ_GetFirstSpawn);
    state->set_function("EQ_GetLastSpawn", EQ_GetLastSpawn);

    state->set_function("EQ_GetPlayerSpawn", EQ_GetPlayerSpawn);
    state->set_function("EQ_GetTargetSpawn", EQ_GetTargetSpawn);

    state->set_function("EQ_SetTargetSpawn", EQ_SetTargetSpawn);

    state->set_function("EQ_GetPlayerSpawnNameNumbered", EQ_GetPlayerSpawnNameNumbered);
    state->set_function("EQ_GetPlayerSpawnName", EQ_GetPlayerSpawnName);
    state->set_function("EQ_GetPlayerSpawnLastName", EQ_GetPlayerSpawnLastName);

    state->set_function("EQ_GetTargetSpawnNameNumbered", EQ_GetTargetSpawnNameNumbered);
    state->set_function("EQ_GetTargetSpawnName", EQ_GetTargetSpawnName);
    state->set_function("EQ_GetTargetSpawnLastName", EQ_GetTargetSpawnLastName);

    state->set_function("EQ_GetGroupCount", EQ_GetGroupCount);
    state->set_function("EQ_GetGroupMemberSpawn", EQ_GetGroupMemberSpawn);
    state->set_function("EQ_GetGroupLeaderSpawn", EQ_GetGroupLeaderSpawn);

    state->set_function("EQ_IsSpawnGroupMember", EQ_IsSpawnGroupMember);
    state->set_function("EQ_IsSpawnGroupLeader", EQ_IsSpawnGroupLeader);

    state->set_function("EQ_GetSpawnDistance", EQ_GetSpawnDistance);
    state->set_function("EQ_GetSpawnDistance3D", EQ_GetSpawnDistance3D);

    state->set_function("EQ_IsSpawnWithinDistance", EQ_IsSpawnWithinDistance);
    state->set_function("EQ_IsSpawnWithinDistanceOfLocation", EQ_IsSpawnWithinDistanceOfLocation);
    state->set_function("EQ_IsSpawnWithinDistanceOfSpawn", EQ_IsSpawnWithinDistanceOfSpawn);

    state->set_function("EQ_CanSpawnCastRayToLocation", EQ_CanSpawnCastRayToLocation);

    state->set_function("EQ_IsSpawnTargetable", EQ_IsSpawnTargetable);

    state->set_function("EQ_IsLocationOnScreen", EQ_IsLocationOnScreen);
    state->set_function("EQ_IsSpawnOnScreen", EQ_IsSpawnOnScreen);

    state->set_function("EQ_IsSpawnSwimming", EQ_IsSpawnSwimming);
    state->set_function("EQ_IsSpawnSwimmingUnderwater", EQ_IsSpawnSwimmingUnderwater);

    state->set_function("EQ_IsSpawnBehindSpawn", EQ_IsSpawnBehindSpawn);
    state->set_function("EQ_IsSpawnBehindSpawnEx", EQ_IsSpawnBehindSpawnEx);
    state->set_function("EQ_IsPlayerBehindTarget", EQ_IsPlayerBehindTarget);

    state->set_function("EQ_IsSpawnClassTank", EQ_IsSpawnClassTank);
    state->set_function("EQ_IsSpawnClassPriest", EQ_IsSpawnClassPriest);
    state->set_function("EQ_IsSpawnClassCaster", EQ_IsSpawnClassCaster);
    state->set_function("EQ_IsSpawnClassMelee", EQ_IsSpawnClassMelee);
    state->set_function("EQ_IsSpawnClassHybrid", EQ_IsSpawnClassHybrid);

    state->set_function("EQ_GetSpawnNumbered", EQ_GetSpawnNameNumbered);
    state->set_function("EQ_GetSpawnName", EQ_GetSpawnName);
    state->set_function("EQ_GetSpawnLastName", EQ_GetSpawnLastName);

    state->set_function("EQ_GetSpawnNext", EQ_GetSpawnNext);
    state->set_function("EQ_GetSpawnPrevious", EQ_GetSpawnPrevious);
    state->set_function("EQ_GetSpawnJumpStrength", EQ_GetSpawnJumpStrength);
    state->set_function("EQ_GetSpawnMovementSpeedBonus", EQ_GetSpawnMovementSpeedBonus);
    state->set_function("EQ_GetSpawnAreaFriction", EQ_GetSpawnAreaFriction);
    state->set_function("EQ_GetSpawnAccelerationFriction", EQ_GetSpawnAccelerationFriction);
    state->set_function("EQ_GetSpawnCollideWithActorType", EQ_GetSpawnCollideWithActorType);
    state->set_function("EQ_GetSpawnFloorZ", EQ_GetSpawnFloorZ);
    state->set_function("EQ_GetSpawnY", EQ_GetSpawnY);
    state->set_function("EQ_GetSpawnX", EQ_GetSpawnX);
    state->set_function("EQ_GetSpawnZ", EQ_GetSpawnZ);
    state->set_function("EQ_GetSpawnMovementSpeed", EQ_GetSpawnMovementSpeed);
    state->set_function("EQ_GetSpawnHeading", EQ_GetSpawnHeading);
    state->set_function("EQ_GetSpawnHeadingSpeed", EQ_GetSpawnHeadingSpeed);
    state->set_function("EQ_GetSpawnPitch", EQ_GetSpawnPitch);
    state->set_function("EQ_GetSpawnUnderwaterEnvironmentType", EQ_GetSpawnUnderwaterEnvironmentType);
    state->set_function("EQ_GetSpawnHeadEnvironmentType", EQ_GetSpawnHeadEnvironmentType);
    state->set_function("EQ_GetSpawnFeetEnvironmentType", EQ_GetSpawnFeetEnvironmentType);
    state->set_function("EQ_GetSpawnBodyEnvironmentType", EQ_GetSpawnBodyEnvironmentType);
    state->set_function("EQ_GetSpawnType", EQ_GetSpawnType);
    state->set_function("EQ_GetSpawnHeightZ", EQ_GetSpawnHeightZ);
    state->set_function("EQ_GetSpawnHeight", EQ_GetSpawnHeight);
    state->set_function("EQ_GetSpawnID", EQ_GetSpawnID);
    state->set_function("EQ_GetSpawnStateFlags", EQ_GetSpawnStateFlags);
    state->set_function("EQ_GetSpawnVehicleSpawn", EQ_GetSpawnVehicleSpawn);
    state->set_function("EQ_GetSpawnMountSpawn", EQ_GetSpawnMountSpawn);
    state->set_function("EQ_GetSpawnMountRiderSpawn", EQ_GetSpawnMountRiderSpawn);
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

    state->set_function("EQ_SetSpawnAreaFriction", EQ_SetSpawnAreaFriction);
    state->set_function("EQ_SetSpawnAccelerationFriction", EQ_SetSpawnAccelerationFriction);
    state->set_function("EQ_SetSpawnHeading", EQ_SetSpawnHeading);
    state->set_function("EQ_SetSpawnPitch", EQ_SetSpawnPitch);
    state->set_function("EQ_SetSpawnHeight", EQ_SetSpawnHeight);
    state->set_function("EQ_SetSpawnFollowSpawn", EQ_SetSpawnFollowSpawn);

    state->set_function("EQ_SetSpawnItemSlot", EQ_SetSpawnItemSlot);
    state->set_function("EQ_SetSpawnItemSlotPrimary", EQ_SetSpawnItemSlotPrimary);
    state->set_function("EQ_SetSpawnItemSlotSecondary", EQ_SetSpawnItemSlotSecondary);
    state->set_function("EQ_SetSpawnItemSlotHead", EQ_SetSpawnItemSlotHead);

    state->set_function("EQ_TurnSpawnTowardsLocation", EQ_TurnSpawnTowardsLocation);
    state->set_function("EQ_TurnSpawnAwayFromLocation", EQ_TurnSpawnAwayFromLocation);
    state->set_function("EQ_TurnSpawnTowardsSpawn", EQ_TurnSpawnTowardsSpawn);
    state->set_function("EQ_TurnSpawnAwayFromSpawn", EQ_TurnSpawnAwayFromSpawn);
    state->set_function("EQ_TurnPlayerTowardsSpawn", EQ_TurnPlayerTowardsSpawn);
    state->set_function("EQ_TurnPlayerAwayFromSpawn", EQ_TurnPlayerAwayFromSpawn);
    state->set_function("EQ_TurnPlayerTowardsTarget", EQ_TurnPlayerTowardsTarget);
    state->set_function("EQ_TurnPlayerAwayFromTarget", EQ_TurnPlayerAwayFromTarget);

    state->set_function("EQ_InterpretCommand", EQ_InterpretCommand);
    state->set_function("EQ_ExecuteCommand", EQ_ExecuteCommand);
    state->set_function("EQ_ExecuteCommandEx", EQ_ExecuteCommandEx);
    state->set_function("EQ_GetExecuteCommandIDByName", EQ_GetExecuteCommandIDByName);
    state->set_function("EQ_GetExecuteCommandNameByID", EQ_GetExecuteCommandNameByID);

    state->set_function("EQ_PrintTextToChat", EQ_PrintTextToChat);
    state->set_function("EQ_PrintTextToChatEx", EQ_PrintTextToChatEx);

    state->set_function("EQ_SetDrawTextFontStyle", EQ_SetDrawTextFontStyle);
    state->set_function("EQ_DrawText", EQ_DrawText);
    state->set_function("EQ_DrawTextByColor", EQ_DrawTextByColor);
    state->set_function("EQ_DrawTextByStyle", EQ_DrawTextByStyle);

    state->set_function("EQ_DrawLine", EQ_DrawLine);
    state->set_function("EQ_DrawLine3D", EQ_DrawLine3D);
    state->set_function("EQ_DrawRectangle", EQ_DrawRectangle);

    state->set_function("EQ_GetCameraPitch", EQ_GetCameraPitch);
    state->set_function("EQ_GetCameraFieldOfView", EQ_GetCameraFieldOfView);
    state->set_function("EQ_GetCameraDrawDistance", EQ_GetCameraDrawDistance);

    state->set_function("EQ_SetCameraPitch", EQ_SetCameraPitch);
    state->set_function("EQ_SetCameraFieldOfView", EQ_SetCameraFieldOfView);
    state->set_function("EQ_SetCameraDrawDistance", EQ_SetCameraDrawDistance);

    state->set_function("EQ_WorldLocationToScreenLocation", EQ_WorldLocationToScreenLocationAsTuple);

    state->set_function("EQ_TakeScreenshot", EQ_TakeScreenshot);

    state->set_function("EQ_PlaySound", EQ_PlaySound);
    state->set_function("EQ_StopSound", EQ_StopSound);

    state->set_function("EQ_StopFollow", EQ_StopFollow);
    state->set_function("EQ_FollowTarget", EQ_FollowTarget);

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
    state->set_function("EQ_UseAbility", EQ_UseAbility);
    state->set_function("EQ_UseItem", EQ_UseItem);

    state->set_function("EQ_UseDoor", EQ_UseDoor);
    state->set_function("EQ_UseDoorByDistance", EQ_UseDoorByDistance);
    state->set_function("EQ_UseDoorOnCollision", EQ_UseDoorOnCollision);
    state->set_function("EQ_SetStateForAllDoors", EQ_SetStateForAllDoors);
    state->set_function("EQ_OpenAllDoors", EQ_OpenAllDoors);
    state->set_function("EQ_CloseAllDoors", EQ_CloseAllDoors);

    state->set_function("EQ_BazaarWindow_IsOpen", EQ_BazaarWindow_IsOpen);
    state->set_function("EQ_BazaarWindow_ClickBeginTraderButton", EQ_BazaarWindow_ClickBeginTraderButton);
    state->set_function("EQ_BazaarWindow_ClickEndTraderButton", EQ_BazaarWindow_ClickEndTraderButton);

    state->set_function("EQ_BazaarConfirmationWindow_IsOpen", EQ_BazaarConfirmationWindow_IsOpen);
    state->set_function("EQ_BazaarConfirmationWindow_ClickToParcelsButton", EQ_BazaarConfirmationWindow_ClickToParcelsButton);
    state->set_function("EQ_BazaarConfirmationWindow_ClickCancelButton", EQ_BazaarConfirmationWindow_ClickCancelButton);

    state->set_function("EQ_BazaarSearchWindow_IsOpen", EQ_BazaarSearchWindow_IsOpen);
    state->set_function("EQ_BazaarSearchWindow_DoQuery", EQ_BazaarSearchWindow_DoQuery);
    state->set_function("EQ_BazaarSearchWindow_GetListCount", EQ_BazaarSearchWindow_GetListCount);
    state->set_function("EQ_BazaarSearchWindow_GetListIndexByItemName", EQ_BazaarSearchWindow_GetListIndexByItemName);
    state->set_function("EQ_BazaarSearchWindow_BuyItem", EQ_BazaarSearchWindow_BuyItem);
    state->set_function("EQ_BazaarSearchWindow_GetListIndex", EQ_BazaarSearchWindow_GetListIndex);
    state->set_function("EQ_BazaarSearchWindow_GetItemID", EQ_BazaarSearchWindow_GetItemID);
    state->set_function("EQ_BazaarSearchWindow_GetItemQuantity", EQ_BazaarSearchWindow_GetItemQuantity);
    state->set_function("EQ_BazaarSearchWindow_GetItemPrice", EQ_BazaarSearchWindow_GetItemPrice);
    state->set_function("EQ_BazaarSearchWindow_GetItemName", EQ_BazaarSearchWindow_GetItemName);
    state->set_function("EQ_BazaarSearchWindow_GetTraderName", EQ_BazaarSearchWindow_GetTraderName);
    state->set_function("EQ_BazaarSearchWindow_ClickFindItemsButton", EQ_BazaarSearchWindow_ClickFindItemsButton);
    state->set_function("EQ_BazaarSearchWindow_ClickUpdateTradersButton", EQ_BazaarSearchWindow_ClickUpdateTradersButton);
    state->set_function("EQ_BazaarSearchWindow_ClickResetButton", EQ_BazaarSearchWindow_ClickResetButton);

    state->set_function("EQ_TaskSelectWindow_IsOpen", EQ_TaskSelectWindow_IsOpen);
    state->set_function("EQ_TaskSelectWindow_ClickAcceptButton", EQ_TaskSelectWindow_ClickAcceptButton);
    state->set_function("EQ_TaskSelectWindow_ClickDeclineButton", EQ_TaskSelectWindow_ClickDeclineButton);
}
