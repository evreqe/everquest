g_AutoBuffIsEnabled = 1

function AutoBuff_Toggle()
    if g_AutoBuffIsEnabled == 0 then
        g_AutoBuffIsEnabled = 1
        EQ_PrintTextToChat("Auto Buff: On")
    else
        g_AutoBuffIsEnabled = 0
        EQ_PrintTextToChat("Auto Buff: Off")
    end

    return 1
end

function OnInterpretCommand(commandText)
    if commandText == "//AutoBuff" then
        AutoBuff_Toggle()
        return 1
    end

    if commandText == "//AutoBuffOn" then
        if g_AutoBuffIsEnabled == 0 then
            AutoBuff_Toggle()
        end
        return 1
    end

    if commandText == "//AutoBuffOff" then
        if g_AutoBuffIsEnabled == 1 then
            AutoBuff_Toggle()
        end
        return 1
    end
end

function OnDrawHUD()
    if g_AutoBuffIsEnabled == 1 then
        return 1, "- Auto Buff"
    end
end

function BuffMe(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return
    end

    if EQ_BuffWindows_FindBuffSpellName(spellName) == false then
        EQ_StopFollow()
        EQ_SetTargetSpawn(playerSpawn)
        EQ_CastSpellByName(spellName)
    end
end

function BuffMeEx(spellName, buffName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return
    end

    if EQ_BuffWindows_FindBuffSpellName(buffName) == false then
        EQ_StopFollow()
        EQ_SetTargetSpawn(playerSpawn)
        EQ_CastSpellByName(spellName)
    end
end

function BuffPet(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_PetInfoWindow_IsOpen() == false then
        return
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return
    end

    if EQ_PetInfoWindow_FindBuffSpellName(spellName) == false then
        EQ_StopFollow()
        EQ_TargetPet()
        EQ_CastSpellByName(spellName)
    end
end

function AuraMe(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return
    end

    if EQ_IsAuraNameActive(spellName) == false then
        EQ_StopFollow()
        EQ_CastSpellByName(spellName)
    end
end

function AuraMeEx(spellName, auraName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return
    end

    if EQ_IsAuraNameActive(auraName) == false then
        EQ_StopFollow()
        EQ_CastSpellByName(spellName)
    end
end

function AuraMeDiscipline(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    if EQ_IsAuraNameActive(spellName) == false then
        EQ_StopFollow()
        EQ_InterpretCommand("/discipline " .. spellName)
    end
end

function RemoveBuffs()
    EQ_BuffWindows_RemoveBuffSpellName("Pact of the Wolf Form")
    EQ_BuffWindows_RemoveBuffSpellName("Group Pact of the Wolf Form")
end

function OnTick()
    if g_AutoBuffIsEnabled == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    RemoveBuffs()

    local playerStandingState = EQ_GetSpawnStandingState(playerSpawn)
    if playerStandingState ~= EQ_STANDING_STATE_STANDING then
        return
    end

    if EQ_IsPlayerMoving() == true then
        return
    end

    if EQ_PlayerWindow_GetCombatState() == EQ_COMBAT_STATE_IN_COMBAT then
        return
    end

    if EQ_CastingWindow_IsOpen() == true then
        return
    end

    --local playerName = EQ_GetSpawnName(playerSpawn)

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    --if playerClass == EQ_CLASS_BARD then
        --AuraMe("Aura of Sionachie Rk. II")
    --end

    if playerClass == EQ_CLASS_BEASTLORD then
        if
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine Form") == false or
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine I") == false and
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine II") == false and
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine III") == false and
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine IV") == false and
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine V") == false and
            EQ_BuffWindows_FindBuffSpellName("Pact of the Wurine VI") == false
        then
            EQ_UseAlternateAbility(3709) -- Pact of the Wurine
            return
        end

        if BuffMe("Shared Merciless Ferocity") == 1 then return end
    end

    if playerClass == EQ_CLASS_BERSERKER then
        AuraMeDiscipline("Bloodlust Aura")
    end

    if playerClass == EQ_CLASS_CLERIC then
        AuraMeEx("Aura of the Reverent", "Reverent Aura")
        AuraMe("Aura of Divinity")
        BuffMe("Armor of the Ardent Rk. II")
    end

    if playerClass == EQ_CLASS_DRUID then
        AuraMe("Aura of Life")
        BuffMe("Mask of the Copsetender Rk. II")
        --BuffMe("Pack Spirit")
    end

    if playerClass == EQ_CLASS_ENCHANTER then
        AuraMe("Enticer's Aura Rk. II")
        AuraMe("Runic Torrent Aura Rk. II")
        BuffMeEx("Enticer's Unity Rk. II", "Enticer's Rune Rk. II")
    end

    if playerClass == EQ_CLASS_MAGICIAN then
        AuraMe("Arcane Distillect")
        BuffMe("Praetorian Guardian Rk. II")
        BuffPet("Burnout XII Rk. II")
    end

    if playerClass == EQ_CLASS_RANGER then
        BuffMe("Corpsestalker's Unity Rk. II")
        BuffMe("Jolting Swords Rk. II")
    end

    if playerClass == EQ_CLASS_SHADOWKNIGHT then
        BuffMe("Drape of the Wrathforged Rk. II")
        BuffMe("Shroud of the Doomscale Rk. II")
        BuffMe("Vizat's Horror Rk. II")
    end

    if playerClass == EQ_CLASS_SHAMAN then
        BuffMe("Pack of Olesira Rk. II")
        --BuffMe("Spirit of Bih`Li")
    end

    if playerClass == EQ_CLASS_WARRIOR then
        AuraMeDiscipline("Champion's Aura")
    end
end
