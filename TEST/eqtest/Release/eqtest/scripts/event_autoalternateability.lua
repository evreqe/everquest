g_AutoAlternateAbilityIsEnabled = 1

function AutoAlternateAbility_Toggle()
    if g_AutoAlternateAbilityIsEnabled == 0 then
        g_AutoAlternateAbilityIsEnabled = 1
        EQ_PrintTextToChat("Auto Alternate Ability: On")
    else
        g_AutoAlternateAbilityIsEnabled = 0
        EQ_PrintTextToChat("Auto Alternate Ability: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//AutoAlternateAbility" or commandText == "//AAA" then
        AutoAlternateAbility_Toggle()
        return 1
    end

    if commandText == "//AutoAlternateAbilityOn" or commandText == "//AAAOn" then
        if g_AutoAlternateAbilityIsEnabled == 0 then
            AutoAlternateAbility_Toggle()
            return 1
        end
    end

    if commandText == "//AutoAlternateAbilityOff" or commandText == "//AAAOff" then
        if g_AutoAlternateAbilityIsEnabled == 1 then
            AutoAlternateAbility_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_AutoAlternateAbilityIsEnabled == 1 then
        return 1, "- Auto Alternate Ability"
    end
end

function OnThreeSeconds()
    if g_AutoAlternateAbilityIsEnabled == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerSpawnLevel = EQ_GetSpawnLevel(playerSpawn)
    if playerSpawnLevel < 50 then
        return
    end

    local playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn)
    if playerSpawnStandingState ~= EQ_STANDING_STATE_STANDING then
        return
    end

    local playerSpawnZoneID = EQ_GetSpawnZoneID(playerSpawn)
    if EQ_IsZoneIDSafe(playerSpawnZoneID) == true then
        return
    end

    local playerSpawnHPPercent = EQ_GetSpawnHPPercent(playerSpawn)
    if playerSpawnHPPercent == 0 then
        return
    end

    local playerSpawnClass = EQ_GetSpawnClass(playerSpawn)

    local targetSpawn = EQ_GetTargetSpawn()

    alternateAbilityList = {}

    if playerSpawnHPPercent < 10 then
        table.insert(alternateAbilityList, 486)       -- Staunch Recovery
    end

    if playerSpawnHPPercent < 25 then
        table.insert(alternateAbilityList, 2000)      -- Armor of Experience
        table.insert(alternateAbilityList, 482)       -- Infusion of the Faithful
        table.insert(alternateAbilityList, 487)       -- Intensity of the Resolute
    end

    if playerSpawnClass == EQ_CLASS_BARD then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            table.insert(alternateAbilityList, 212)   -- Fading Memories

            -- Class
            table.insert(alternateAbilityList, 668)   -- Hymn of the Last Stand
            table.insert(alternateAbilityList, 8204)  -- Lyrical Prankster
            table.insert(alternateAbilityList, 361)   -- Shield of Notes
            table.insert(alternateAbilityList, 8261)  -- Tune Stuck In Your Head
        end
    elseif playerSpawnClass == EQ_CLASS_BEASTLORD then
        if playerSpawnHPPercent < 50 then
            table.insert(alternateAbilityList, 128) -- Paragon of Spirit
        end
    elseif playerSpawnClass == EQ_CLASS_BERSERKER then
        if playerSpawnHPPercent < 50 then
            -- Archetype
            table.insert(alternateAbilityList, 734)   -- Hold the Line
            table.insert(alternateAbilityList, 8400)  -- Self Preservation
            table.insert(alternateAbilityList, 1109)  -- Silent Strikes

            -- Class
            table.insert(alternateAbilityList, 1141)  -- Blood Sustenance
            table.insert(alternateAbilityList, 836)   -- Juggernauts Resolve
            table.insert(alternateAbilityList, 609)   -- Uncanny Resilience
        end
    elseif playerSpawnClass == EQ_CLASS_CLERIC then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            table.insert(alternateAbilityList, 494)   -- Silent Casting

            -- Class
            table.insert(alternateAbilityList, 7689)  -- Burst of Life
            table.insert(alternateAbilityList, 38)    -- Celestial Regeneration
            table.insert(alternateAbilityList, 392)   -- Divine Retribution
            table.insert(alternateAbilityList, 255)   -- Exquisite Benediction
            table.insert(alternateAbilityList, 1472)  -- Fundament Third Spire of Divinity
            table.insert(alternateAbilityList, 396)   -- Sanctuary
        end
    elseif playerSpawnClass == EQ_CLASS_DRUID then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            table.insert(alternateAbilityList, 494)   -- Silent Casting
            table.insert(alternateAbilityList, 7003)  -- Forceful Rejuvenation

            -- Class
            table.insert(alternateAbilityList, 1482)  -- Fundament Third Spire of Nature
            table.insert(alternateAbilityList, 257)   -- Natures Boon
            table.insert(alternateAbilityList, 10426) -- Peaceful Spirit of the Wood
            table.insert(alternateAbilityList, 3714)  -- Protection of Direwood
            table.insert(alternateAbilityList, 8604)  -- Wall of Wind
        end
    elseif playerSpawnClass == EQ_CLASS_ENCHANTER then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            table.insert(alternateAbilityList, 500)   -- Silent Casting
            table.insert(alternateAbilityList, 636)   -- Arcane Whisper
            table.insert(alternateAbilityList, 1211)  -- Focus of Arcanum
            table.insert(alternateAbilityList, 7003)  -- Forceful Rejuvenation
            table.insert(alternateAbilityList, 1120)  -- Self Stasis

            -- Class
            table.insert(alternateAbilityList, 3551)  -- Beguilers Directed Banishment
            table.insert(alternateAbilityList, 261)   -- Doppleganger
            table.insert(alternateAbilityList, 173)   -- Eldritch Rune
            table.insert(alternateAbilityList, 1124)  -- Fog of Memories
            table.insert(alternateAbilityList, 1380)  -- Fundament First Spire of Enchantment
            table.insert(alternateAbilityList, 413)   -- Mind Over Matter
            table.insert(alternateAbilityList, 1122)  -- Phantasmal Opponent
            table.insert(alternateAbilityList, 791)   -- Veil of Mindshadow
        end
    elseif playerSpawnClass == EQ_CLASS_MAGICIAN then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            --table.insert(alternateAbilityList, x)   -- 

            -- Class
            table.insert(alternateAbilityList, 3516)   -- Companion of Necessity
            table.insert(alternateAbilityList, 787)   -- Heart of Stone
        end
    elseif playerSpawnClass == EQ_CLASS_RANGER then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            --table.insert(alternateAbilityList, x)   -- 

            -- Class
            table.insert(alternateAbilityList, 778)   -- Protection of the Spirit Wolf
        end
    elseif playerSpawnClass == EQ_CLASS_SHADOWKNIGHT then
        if playerSpawnHPPercent < 50 then
            -- Archetype
            --table.insert(alternateAbilityList, x)   -- 

            -- Class
            --table.insert(alternateAbilityList, x)   -- 
        end
    elseif playerSpawnClass == EQ_CLASS_SHAMAN then
        if playerSpawnHPPercent < 75 then
            -- Archetype
            --table.insert(alternateAbilityList, x)   -- 

            -- Class
            table.insert(alternateAbilityList, 528)   -- Ancestral Guard
            table.insert(alternateAbilityList, 447)   -- Ancestral Aid
        end
    elseif playerSpawnClass == EQ_CLASS_WARRIOR then
        if playerSpawnHPPercent < 50 then
            -- Archetype
            table.insert(alternateAbilityList, 734)   -- Hold the Line
            table.insert(alternateAbilityList, 3213)  -- Projection of Fury

            -- Class
            table.insert(alternateAbilityList, 967)   -- Blade Guardian
            table.insert(alternateAbilityList, 1686)  -- Brace for Impact
            table.insert(alternateAbilityList, 1402)  -- Fundament Third Spire of the Warlord
            table.insert(alternateAbilityList, 2011)  -- Imperators Command
            table.insert(alternateAbilityList, 606)   -- Mark of the Mage Hunter
            table.insert(alternateAbilityList, 130)   -- Resplendent Glory
            table.insert(alternateAbilityList, 804)   -- Warlords Bravery
            table.insert(alternateAbilityList, 911)   -- Warlords Resurgence
            table.insert(alternateAbilityList, 300)   -- Warlords Tenacity
        end
    end

    for _, alternateAbility in ipairs(alternateAbilityList) do
        EQ_UseAlternateAbility(alternateAbility)
    end
end
