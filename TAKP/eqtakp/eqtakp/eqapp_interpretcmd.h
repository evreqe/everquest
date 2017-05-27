#pragma once

bool g_interpretCmdIsEnabled = true;

std::vector<std::string> g_interpretCmdList =
{
    "AlwaysAttack",
    "AutoLoot",
    "ESP",
    "FoodAndDrink",
    "Map",
    "Speed",
    "TargetCorpse",
    "TargetAnyCorpse",
    "TargetPlayerCorpse",
    "TargetNPCCorpse",
};

void EQAPP_InterpretCmd_Execute(std::string commandText);

void EQAPP_InterpretCmd_Execute(std::string commandText)
{
    if (commandText.size() == 0)
    {
        return;
    }

    std::cout << "InterpretCmd: " << commandText << std::endl;

    if (commandText == "//AlwaysAttack")
    {
        EQAPP_AlwaysAttack_Toggle();
        return;
    }

    if (commandText == "//AutoLoot")
    {
        EQAPP_AutoLoot_Toggle();
        return;
    }

    if (commandText == "//ESP")
    {
        EQAPP_ESP_Toggle();
        return;
    }

    if (commandText == "//FoodAndDrink")
    {
        EQAPP_FoodAndDrink_Toggle();
        return;
    }

    if (commandText == "//Map")
    {
        EQAPP_Map_Toggle();
        return;
    }

    if (commandText == "//Speed")
    {
        EQAPP_SpeedHack_Toggle();
        return;
    }

    if (commandText == "//TargetCorpse" || commandText == "//TargetAnyCorpse")
    {
        auto nearestSpawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_ANY_CORPSE, 100.0f);
        if (nearestSpawn != NULL)
        {
            EQ_SetTargetSpawn(nearestSpawn);
        }

        return;
    }

    if (commandText == "//TargetPlayerCorpse")
    {
        auto nearestSpawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_PLAYER_CORPSE, 100.0f);
        if (nearestSpawn != NULL)
        {
            EQ_SetTargetSpawn(nearestSpawn);
        }

        return;
    }

    if (commandText == "//TargetNPCCorpse")
    {
        auto nearestSpawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_NPC_CORPSE, 100.0f);
        if (nearestSpawn != NULL)
        {
            EQ_SetTargetSpawn(nearestSpawn);
        }

        return;
    }
}

