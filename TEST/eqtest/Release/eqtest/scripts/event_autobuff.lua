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

function OnOneSecond()
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn)
    if playerSpawnStandingState ~= EQ_STANDING_STATE_STANDING then
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

    local playerSpawnName = EQ_GetSpawnName(playerSpawn)

    local playerSpawnClass = EQ_GetSpawnClass(playerSpawn)

    if playerSpawnClass == EQ_CLASS_BARD then
        AuraMe("Aura of Sionachie Rk. II")
    end

    if playerSpawnClass == EQ_CLASS_BEASTLORD then
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

        -- if BuffMe("Growl of the Lion Rk. II") == 1 then return end
        if BuffMe("Shared Brutal Ferocity Rk. II") == 1 then return end
    end

    if playerSpawnClass == EQ_CLASS_BERSERKER then
        AuraMeDiscipline("Bloodlust Aura")
    end

    if playerSpawnClass == EQ_CLASS_CLERIC then
        AuraMeEx("Aura of the Reverent", "Reverent Aura")
        AuraMe("Circle of Divinity")

        if playerSpawnName == "Elricc" then
            AuraMe("Aura of the Pious")
            BuffMe("Armor of the Zealous Rk. II")
            BuffMe("Vow of Veneration Rk. II")
        end
    end

    if playerSpawnClass == EQ_CLASS_DRUID then
        AuraMe("Aura of Life")
        BuffMe("Mask of the Copsetender Rk. II")
        BuffMe("Pack Spirit")
    end

    if playerSpawnClass == EQ_CLASS_ENCHANTER then
        AuraMe("Enticer's Aura Rk. II")
        AuraMe("Runic Torrent Aura Rk. II")
        BuffMeEx("Enticer's Unity Rk. II", "Enticer's Rune Rk. II")
    end

    if playerSpawnClass == EQ_CLASS_MAGICIAN then
        BuffMe("Splendrous Guardian Rk. II")
        BuffPet("Burnout X Rk. II")
    end

    if playerSpawnClass == EQ_CLASS_RANGER then
        BuffMe("Protection of the Copse Rk. II")
        BuffMe("Eyes of the Raptor Rk. II")
        BuffMe("Veil of Alaris Rk. II")
        BuffMe("Galvanized by the Hunt Rk. II")
        BuffMe("Jolting Impact Rk. II")
    end

    if playerSpawnClass == EQ_CLASS_SHADOWKNIGHT then
        BuffMe("Drape of the Sepulcher Rk. II")
        BuffMe("Shroud of the Shadeborne Rk. II")
        BuffMe("Sholothian Horror Rk. II")
    end

    if playerSpawnClass == EQ_CLASS_SHAMAN then
        BuffMe("Pack of Hilnaah Rk. II")
        BuffMe("Spirit of Bih`Li")
        -- BuffMe("Champion")
    end

    if playerSpawnClass == EQ_CLASS_WARRIOR then
        AuraMeDiscipline("Myrmidon's Aura")
    end
end
