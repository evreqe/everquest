#pragma once

bool g_interpretCmdIsEnabled = true;

void EQAPP_InterpretCmd_NULL()
{
    //
}

std::map<std::string, std::function<void()>> g_interpretCmdList =
{
    {"//AlwaysAttack",              &EQAPP_AlwaysAttack_Toggle},
    {"//AutoInventory",             &EQAPP_AutoInventory_Execute},
    {"//AutoLoot",                  &EQAPP_AutoLoot_Toggle},
    {"//LoadAutoLoot",              &EQAPP_AutoLoot_Load},
    {"//Bank",                      &EQAPP_PrintBankInventory},
    {"//ChangeHeight",              &EQAPP_ChangeHeight_Toggle},
    {"//Collision",                 &EQAPP_CollisionHack_Toggle},
    {"//CollisionDebug",            &EQAPP_CollisionHack_Debug_Toggle},
    {"//DrawDistance",              &EQAPP_DrawDistance_Toggle},
    {"//ESP",                       &EQAPP_ESP_Toggle},
    {"//ESPSpawnSkeletons",         &EQAPP_ESP_SpawnSkeletons_Toggle},
    {"//ESPShowSpawnID",            &EQAPP_ESP_ShowSpawnID_Toggle},
    {"//ESPShowSpawnRace",          &EQAPP_ESP_ShowSpawnRace_Toggle},
    {"//ESPShowSpawnWeapon",        &EQAPP_ESP_ShowSpawnWeapon_Toggle},
    {"//ExtendedTargets",           &EQAPP_ExtendedTargets_Toggle},
    {"//FoodAndDrink",              &EQAPP_FoodAndDrink_Toggle},
    {"//FreeCamera",                &EQAPP_FreeCamera_Toggle},
    {"//PrintTargetMeleeDistance",  &EQAPP_PrintTargetMeleeDistance},
    {"//HideCorpseLooted",          &EQAPP_HideCorpseLooted_Toggle},
    {"//HUDText",                   &EQAPP_HUDText_Toggle},
    {"//LoadSpellSet",              &EQAPP_SpellSet_LoadAndStartMemorizing},
    {"//SaveSpellSet",              &EQAPP_SpellSet_Save_Default},
    {"//Map",                       &EQAPP_Map_Toggle},
    {"//MapLines",                  &EQAPP_Map_Lines_Toggle},
    {"//MapLabels",                 &EQAPP_Map_Labels_Toggle},
    {"//MapSpawns",                 &EQAPP_Map_Spawns_Toggle},
    {"//LoadMap",                   &EQAPP_Map_Load},
    {"//MaxSkills",                 &EQAPP_MaxSkills_Toggle},
    {"//MerchantWindow",            &EQAPP_MerchantWindow_Toggle},
    {"//NamedSpawns",               &EQAPP_NamedSpawns_Toggle},
    {"//LoadNamedSpawns",           &EQAPP_NamedSpawns_Load},
    {"//NameSpriteState",           &EQAPP_NameSpriteState_Toggle},
    {"//NameSpriteTint",            &EQAPP_NameSpriteTint_Toggle},
    {"//NetworkStats",              &EQAPP_NetworkStats_Toggle},
    {"//NeverFrozen",               &EQAPP_NeverFrozen_Toggle},
    {"//ReplaceRaces",              &EQAPP_ReplaceRaces_Toggle},
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
    {"//TrainSpellsDebug",          &EQAPP_TrainSpells_Debug_Toggle},
    {"//UseSkills",                 &EQAPP_UseSkills_Toggle},
    {"//UseSkillsRoundKick",        &EQAPP_UseSkills_RoundKick_Toggle},
    {"//UseSkillsBackstab",         &EQAPP_UseSkills_Backstab_Toggle},
    {"//UseSkillsBash",             &EQAPP_UseSkills_Bash_Toggle},
    {"//UseSkillsDisarm",           &EQAPP_UseSkills_Disarm_Toggle},
    {"//UseSkillsForage",           &EQAPP_UseSkills_Forage_Toggle},
    {"//UseSkillsKick",             &EQAPP_UseSkills_Kick_Toggle},
    {"//UseSkillsSenseHeading",     &EQAPP_UseSkills_SenseHeading_Toggle},
    {"//UseSkillsSlam",             &EQAPP_UseSkills_Slam_Toggle},
    {"//UseSkillsTaunt",            &EQAPP_UseSkills_Taunt_Toggle},
    {"//WriteInventory",            &EQAPP_WriteInventoryToFile},

    {"//Commands",                  &EQAPP_InterpretCmd_NULL},
    {"//Help",                      &EQAPP_InterpretCmd_NULL},
};

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, char* commandText_);
bool EQAPP_InterpretCmd_HasQuotes(const std::string& commandText);
void EQAPP_InterpretCmd_Execute(std::string commandText);

bool EQAPP_InterpretCmd_HandleEvent_CEverQuest__InterpretCmd(void* this_ptr, class EQPlayer* player, char* commandText_)
{
    if (player == NULL || commandText_ == NULL)
    {
        return true;
    }

    std::string commandText = commandText_;
    if (commandText.size() == 0)
    {
        return true;
    }

    std::string firstTwoCharacters = commandText.substr(0, 2);
    if (firstTwoCharacters == "//")
    {
        EQAPP_InterpretCmd_Execute(commandText);
        return true;
    }
    else
    {
        if (commandText.find("//") != std::string::npos)
        {
            return true;
        }

        if (commandText.find("/") != std::string::npos)
        {
            for (auto& cmd : g_interpretCmdList)
            {
                std::string cmdText = cmd.first;
                std::string cmdTextStripped = cmdText.substr(2, cmdText.size());

                if (commandText.find(cmdTextStripped) != std::string::npos)
                {
                    return true;
                }
            }
        }

        for (auto& cmd : g_interpretCmdList)
        {
            if (commandText == cmd.first)
            {
                return true;
            }
        }
    }

    return false;
}

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

    if (commandText == "//Help" || commandText == "//Commands")
    {
        std::cout << "Command List: " << std::endl;

        for (auto& cmd : g_interpretCmdList)
        {
            std::cout << cmd.first << std::endl;
        }

        return;
    }

    if (commandText == "//Test")
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            auto player = (EQClass::EQPlayer*)playerSpawn;

            EQ_CLASS_POINTER_CDisplay->UpdateItemSlot(player, 7, "IT145", true);
        }

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//TrainSpells ") == true)
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
            std::cout << "InterpretCmd Error: Height not found." << std::endl;
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
            std::cout << "InterpretCmd Error: Height not found." << std::endl;
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
            std::cout << "InterpretCmd Error: Height not found." << std::endl;
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

    if (EQAPP_String_StartsWith(commandText, "//LoadSpellSet ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string spellSetName = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (spellSetName.size() == 0)
        {
            std::cout << "InterpretCmd Error: Spell set name not found." << std::endl;
            return;
        }

        EQAPP_SpellSet_Load(spellSetName);

        return;
    }

    if (EQAPP_String_StartsWith(commandText, "//SaveSpellSet ") == true)
    {
        if (EQAPP_InterpretCmd_HasQuotes(commandText) == false)
        {
            return;
        }

        std::string spellSetName = EQAPP_String_GetBetween(commandText, "\"", "\"");
        if (spellSetName.size() == 0)
        {
            std::cout << "InterpretCmd Error: Spell set name not found." << std::endl;
            return;
        }

        EQAPP_SpellSet_Save(spellSetName);

        return;
    }

    // handle interpret command list functions
    auto cmd = g_interpretCmdList.find(commandText);
    if (cmd != g_interpretCmdList.end())
    {
        cmd->second();
        return;
    }
}

