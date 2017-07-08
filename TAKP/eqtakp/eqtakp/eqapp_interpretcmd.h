#pragma once

bool g_interpretCmdIsEnabled = true;

std::map<std::string, std::function<void()>> g_interpretCmdList =
{
    {"//AlwaysAttack",              &EQAPP_AlwaysAttack_Toggle},
    {"//AutoInventory",             &EQAPP_AutoInventory_Execute},
    {"//AutoLoot",                  &EQAPP_AutoLoot_Toggle},
    {"//LoadAutoLoot",              &EQAPP_AutoLoot_Load},
    {"//ChangeHeight",              &EQAPP_ChangeHeight_Toggle},
    {"//DrawDistance",              &EQAPP_DrawDistance_Toggle},
    {"//ESP",                       &EQAPP_ESP_Toggle},
    {"//ESPShowSpawnID",            &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ExtendedTargets",           &EQAPP_ExtendedTargets_Toggle},
    {"//FoodAndDrink",              &EQAPP_FoodAndDrink_Toggle},
    {"//FreeCamera",                &EQAPP_FreeCamera_Toggle},
    {"//GetTargetMeleeDistance",    &EQAPP_PrintTargetMeleeDistance},
    {"//HideCorpseLooted",          &EQAPP_HideCorpseLooted_Toggle},
    {"//HUDText",                   &EQAPP_HUDText_Toggle},
    {"//LoadSpellSet",              &EQAPP_SpellSet_LoadAndStartMemorizing},
    {"//SaveSpellSet",              &EQAPP_SpellSet_Save},
    {"//Map",                       &EQAPP_Map_Toggle},
    {"//LoadMap",                   &EQAPP_Map_Load},
    {"//MaxSkills",                 &EQAPP_MaxSkills_Toggle},
    {"//MerchantWindow",            &EQAPP_MerchantWindow_Toggle},
    {"//NamedSpawns",               &EQAPP_NamedSpawns_Toggle},
    {"//LoadNamedSpawns",           &EQAPP_NamedSpawns_Load},
    {"//NetworkStats",              &EQAPP_NetworkStats_Toggle},
    {"//NeverFrozen",               &EQAPP_NeverFrozen_Toggle},
    {"//SpawnAlert",                &EQAPP_SpawnAlert_Toggle},
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
    {"//TrainSpells",               &EQAPP_TrainSpells_Toggle},
    {"//UseSkills",                 &EQAPP_UseSkills_Toggle},
    {"//UseSkillsBackstab",         &EQAPP_UseSkills_Toggle_Backstab},
    {"//UseSkillsBash",             &EQAPP_UseSkills_Toggle_Bash},
    {"//UseSkillsDisarm",           &EQAPP_UseSkills_Toggle_Disarm},
    {"//UseSkillsForage",           &EQAPP_UseSkills_Toggle_Forage},
    {"//UseSkillsKick",             &EQAPP_UseSkills_Toggle_Kick},
    {"//UseSkillsSenseHeading",     &EQAPP_UseSkills_Toggle_SenseHeading},
    {"//UseSkillsSlam",             &EQAPP_UseSkills_Toggle_Slam},
    {"//UseSkillsTaunt",            &EQAPP_UseSkills_Toggle_Taunt},
};

bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText);
void EQAPP_InterpretCmd_Execute(std::string commandText);

bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText)
{
    if (commandText.find("\"") == std::string::npos && commandText.back() != '"')
    {
        std::cout << "InterpretCmd Error: Command argument missing quotes." << std::endl;
        return false;
    }

    return true;
}

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

    if (EQAPP_String_StartsWith(commandText, "//TrainSpell ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string spellName = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (spellName.size() == 0)
        {
            std::cout << "InterpretCmd Error: Spell Name not found." << std::endl;
            return;
        }

        g_trainSpellsSpellName = spellName;

        std::cout << "Train Spell Name: " << spellName << std::endl;

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//Follow ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string spawnName = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (spawnName.size() == 0)
        {
            std::cout << "InterpretCmd Error: Spawn Name not found." << std::endl;
            return;
        }

        // TODO

        std::cout << "Following: " << spawnName << std::endl;

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//Cast ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string spellName = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (spellName.size() == 0)
        {
            std::cout << "InterpretCmd Error: Spell Name not found." << std::endl;
            return;
        }

        // TODO

        std::cout << "Casting: " << spellName << std::endl;

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//ChangeHeight ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string heightStr = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (heightStr.size() == 0)
        {
            std::cout << "InterpretCmd Error: Height not not found." << std::endl;
            return;
        }

        float height = std::stof(heightStr);
        if (height >= 1.0f)
        {
            auto targetSpawn = EQ_GetTargetSpawn();
            if (targetSpawn != NULL)
            {
                EQ_SetSpawnHeight(targetSpawn, height);
            }
        }

        std::cout << "Change Height: " << std::fixed << std::setprecision(1) << height << std::endl;

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//ChangeHeightMin ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string heightStr = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (heightStr.size() == 0)
        {
            std::cout << "InterpretCmd Error: Height not not found." << std::endl;
            return;
        }

        float height = std::stof(heightStr);
        if (height >= 1.0f)
        {
            g_changeHeightMinimumHeight = height;
        }

        std::cout << "Change Height Min: " << std::fixed << std::setprecision(1) << height << std::endl;

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//ChangeHeightMax ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string heightStr = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (heightStr.size() == 0)
        {
            std::cout << "InterpretCmd Error: Height not not found." << std::endl;
            return;
        }

        float height = std::stof(heightStr);
        if (height >= 1.0f)
        {
            g_changeHeightMaximumHeight = height;
        }

        std::cout << "Change Height Max: " << std::fixed << std::setprecision(1) << height << std::endl;

        return;
    }

    auto cmd = g_interpretCmdList.find(commandText);
    if (cmd != g_interpretCmdList.end())
    {
        cmd->second();
        return;
    }
}

