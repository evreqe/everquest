#pragma once

bool g_interpretCmdIsEnabled = true;

std::map<std::string, std::function<void()>> g_interpretCmdList =
{
    {"//AlwaysAttack",              &EQAPP_AlwaysAttack_Toggle},
    {"//AutoLoot",                  &EQAPP_AutoLoot_Toggle},
    {"//LoadAutoLoot",              &EQAPP_AutoLoot_Load},
    {"//ChangeHeight",              &EQAPP_ChangeHeight_Toggle},
    {"//DrawDistance",              &EQAPP_DrawDistance_Toggle},
    {"//ESP",                       &EQAPP_ESP_Toggle},
    {"//ExtendedTargets",           &EQAPP_ExtendedTargets_Toggle},
    {"//FoodAndDrink",              &EQAPP_FoodAndDrink_Toggle},
    {"//GetTargetMeleeDistance",    &EQAPP_PrintTargetMeleeDistance},
    {"//HideCorpseLooted",          &EQAPP_HideCorpseLooted_Toggle},
    {"//LoadSpellSet",              &EQAPP_SpellSet_LoadAndStartMemorizing},
    {"//SaveSpellSet",              &EQAPP_SpellSet_Save},
    {"//Map",                       &EQAPP_Map_Toggle},
    {"//LoadMap",                   &EQAPP_Map_Load},
    {"//MaxSkills",                 &EQAPP_MaxSkills_Toggle},
    {"//NamedSpawns",               &EQAPP_NamedSpawns_Toggle},
    {"//LoadNamedSpawns",           &EQAPP_NamedSpawns_Load},
    {"//NetworkStats",              &EQAPP_NetworkStats_Toggle},
    {"//NeverFrozen",               &EQAPP_NeverFrozen_Toggle},
    {"//Speed",                     &EQAPP_SpeedHack_Toggle},
    {"//SpeedRun1",                 &EQAPP_SpeedHack_SetSpeedRun1},
    {"//SpeedRun2",                 &EQAPP_SpeedHack_SetSpeedRun2},
    {"//SpeedRun3",                 &EQAPP_SpeedHack_SetSpeedRun3},
    {"//SpeedSOW",                  &EQAPP_SpeedHack_SetSpeedSpiritOfWolf},
    {"//SpeedFast",                 &EQAPP_SpeedHack_SetSpeedFast},
    {"//TargetPlayer",              &EQAPP_TargetNearestPlayer},
    {"//TargetNPC",                 &EQAPP_TargetNearestNPC},
    {"//TargetPlayerPet",           &EQAPP_TargetNearestPlayerPet},
    {"//TargetNPCPet",              &EQAPP_TargetNearestNPCPet},
    {"//TargetCorpse",              &EQAPP_TargetNearestAnyCorpse},
    {"//TargetAnyCorpse",           &EQAPP_TargetNearestAnyCorpse},
    {"//TargetPlayerCorpse",        &EQAPP_TargetNearestPlayerCorpse},
    {"//TargetNPCCorpse",           &EQAPP_TargetNearestNPCCorpse},
    {"//UseSkills",                 &EQAPP_UseSkills_Toggle},
};

void EQAPP_InterpretCmd_Execute(std::string commandText);

void EQAPP_InterpretCmd_Execute(std::string commandText)
{
    if (commandText.size() == 0)
    {
        return;
    }

    std::cout << "InterpretCmd: " << commandText << std::endl;

    if (commandText == "//Commands")
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

