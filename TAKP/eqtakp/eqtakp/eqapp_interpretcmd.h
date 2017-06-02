#pragma once

bool g_interpretCmdIsEnabled = true;

std::map<std::string, std::function<void()>> g_interpretCmdList =
{
    {"//AlwaysAttack",          &EQAPP_AlwaysAttack_Toggle},
    {"//AutoLoot",              &EQAPP_AutoLoot_Toggle},
    {"//DrawDistance",          &EQAPP_DrawDistance_Toggle},
    {"//ESP",                   &EQAPP_ESP_Toggle},
    {"//ExtendedTargets",       &EQAPP_ExtendedTargets_Toggle},
    {"//FoodAndDrink",          &EQAPP_FoodAndDrink_Toggle},
    {"//HideCorpseLooted",      &EQAPP_HideCorpseLooted_Toggle},
    {"//LoadSpellSet",          &EQAPP_SpellSet_LoadAndStartMemorizing},
    {"//SaveSpellSet",          &EQAPP_SpellSet_Save},
    {"//Map",                   &EQAPP_Map_Toggle},
    {"//NamedSpawns",           &EQAPP_NamedSpawns_Toggle},
    {"//NetworkStats",          &EQAPP_NetworkStats_Toggle},
    {"//NeverFrozen",           &EQAPP_NeverFrozen_Toggle},
    {"//Speed",                 &EQAPP_SpeedHack_Toggle},
    {"//TargetPlayer",          &EQAPP_TargetNearestPlayer},
    {"//TargetNPC",             &EQAPP_TargetNearestNPC},
    {"//TargetPlayerPet",       &EQAPP_TargetNearestPlayerPet},
    {"//TargetNPCPet",          &EQAPP_TargetNearestNPCPet},
    {"//TargetCorpse",          &EQAPP_TargetNearestAnyCorpse},
    {"//TargetAnyCorpse",       &EQAPP_TargetNearestAnyCorpse},
    {"//TargetPlayerCorpse",    &EQAPP_TargetNearestPlayerCorpse},
    {"//TargetNPCCorpse",       &EQAPP_TargetNearestNPCCorpse},
};

void EQAPP_InterpretCmd_Execute(std::string commandText);

void EQAPP_InterpretCmd_Execute(std::string commandText)
{
    if (commandText.size() == 0)
    {
        return;
    }

    std::cout << "InterpretCmd: " << commandText << std::endl;

    if (commandText == "Commands")
    {
        std::cout << "Command List: " << std::endl;

        for (auto& cmd : g_interpretCmdList)
        {
            std::cout << cmd.first << std::endl;
        }

        return;
    }

    auto cmd = g_interpretCmdList.find(commandText);
    if (cmd != g_interpretCmdList.end())
    {
        cmd->second();
        return;
    }
}

