#pragma once

bool g_CombatMacroIsEnabled = true;

EQApp::Timer g_CombatMacroTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_CombatMacroTimerInterval = 6;

float g_CombatMacroDistance = 25.0f;

std::vector<std::string> g_CombatMacroList;
uint32_t g_CombatMacroList_reserve = 1024;

void EQAPP_CombatMacro_Toggle();
void EQAPP_CombatMacro_On();
void EQAPP_CombatMacro_Off();
void EQAPP_CombatMacro_Load();
void EQAPP_CombatMacro_Execute();

void EQAPP_CombatMacro_Toggle()
{
    EQ_ToggleBool(g_CombatMacroIsEnabled);
    EQAPP_PrintBool("Combat Macro", g_CombatMacroIsEnabled);
}

void EQAPP_CombatMacro_On()
{
    if (g_CombatMacroIsEnabled == false)
    {
        EQAPP_CombatMacro_Toggle();
    }
}

void EQAPP_CombatMacro_Off()
{
    if (g_CombatMacroIsEnabled == true)
    {
        EQAPP_CombatMacro_Toggle();
    }
}

void EQAPP_CombatMacro_Load()
{
    g_CombatMacroList.clear();
    g_CombatMacroList.reserve(g_CombatMacroList_reserve);

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.empty() == true)
    {
        return;
    }

    std::stringstream folderFileName;
    folderFileName << "combatmacros/" << playerName << ".txt";

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), g_CombatMacroList, false);
    if (result == true)
    {
        std::cout << "Combat Macro loaded from file: " << folderFileName.str() << "\n";
        return;
    }
}

void EQAPP_CombatMacro_Execute()
{
    if (EQAPP_Timer_HasTimeElapsedInSeconds(g_CombatMacroTimer, g_CombatMacroTimerInterval) == false)
    {
        return;
    }

    if (g_CombatMacroList.empty() == true)
    {
        return;
    }

    if (g_BoxChatInterpretCommandList.empty() == false)
    {
        return;
    }

    if (EQ_IsAutoAttackEnabled() == false)
    {
        return;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    auto targetSpawnType = EQ_GetSpawnType(targetSpawn);
    if (targetSpawnType != EQ_SPAWN_TYPE_NPC)
    {
        return;
    }

    float targetSpawnDistance = EQ_GetSpawnDistance(targetSpawn);
    if (targetSpawnDistance > g_CombatMacroDistance)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    auto playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn);
    if (playerSpawnStandingState != EQ_STANDING_STATE_STANDING)
    {
        return;
    }

    for (auto& command : g_CombatMacroList)
    {
        EQ_InterpretCommand(command.c_str());
    }
}
