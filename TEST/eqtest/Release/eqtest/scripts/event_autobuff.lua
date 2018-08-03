function BuffMe(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return 0
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return 0
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return 0
    end

    if EQ_BuffWindows_FindBuffSpellName(spellName) == false then
        EQ_StopFollow()
        EQ_SetTargetSpawn(playerSpawn)
        EQ_CastSpellByName(spellName)
        return 1
    end
end

function BuffPet(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return 0
    end

    if EQ_PetInfoWindow_IsOpen() == false then
        return 0
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return 0
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return 0
    end

    if EQ_PetInfoWindow_FindBuffSpellName(spellName) == false then
        EQ_StopFollow()
        EQ_TargetPet()
        EQ_CastSpellByName(spellName)
        return 1
    end
end

function AuraMe(spellName)
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return 0
    end

    if EQ_IsSpellNameMemorized(spellName) == false then
        return 0
    end

    if EQ_IsSpellNameReadyToCast(spellName) == false then
        return 0
    end

    if EQ_IsAuraNameActive(spellName) == false then
        EQ_StopFollow()
        EQ_CastSpellByName(spellName)
        return 1
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

    if playerSpawnClass == EQ_CLASS_CLERIC then
        if playerSpawnName == "Elricc" then
            if AuraMe("Circle of Divinity") == 1 then return end
            if AuraMe("Aura of the Pious") == 1 then return end
            if BuffMe("Armor of the Zealous Rk. II") == 1 then return end
            if BuffMe("Vow of Veneration Rk. II") == 1 then return end
        end
    end

    if playerSpawnClass == EQ_CLASS_MAGICIAN then
        if BuffMe("Splendrous Guardian Rk. II") == 1 then return end
        if BuffPet("Burnout X Rk. II") == 1 then return end
    end

    if playerSpawnClass == EQ_CLASS_RANGER then
        if BuffMe("Protection of the Copse Rk. II") == 1 then return end
        if BuffMe("Eyes of the Raptor Rk. II") == 1 then return end
        if BuffMe("Veil of Alaris Rk. II") == 1 then return end
        if BuffMe("Galvanized by the Hunt Rk. II") == 1 then return end
        if BuffMe("Jolting Impact Rk. II") == 1 then return end
    end

    if playerSpawnClass == EQ_CLASS_SHADOWKNIGHT then
        if BuffMe("Drape of the Sepulcher Rk. II") == 1 then return end
        if BuffMe("Shroud of the Shadeborne Rk. II") == 1 then return end
        if BuffMe("Sholothian Horror Rk. II") == 1 then return end
    end

    if playerSpawnClass == EQ_CLASS_SHAMAN then
        if BuffMe("Pack of Hilnaah Rk. II") == 1 then return end
        if BuffMe("Spirit of Bih`Li") == 1 then return end
        -- if BuffMe("Champion") == 1 then return end
    end
end
