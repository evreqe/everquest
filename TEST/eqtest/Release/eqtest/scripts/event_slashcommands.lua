function OnInterpretCommand(commandText)

    if commandText == "//BZOn" then
        EQ_InterpretCommand("//BazaarFilterOn")
        EQ_InterpretCommand("//BazaarBotOn")
        EQ_InterpretCommand("//SleepOn")
        return 1
    end

    if commandText == "//BZOff" then
        EQ_InterpretCommand("//SleepOff")
        EQ_InterpretCommand("//BazaarBotOff")
        EQ_InterpretCommand("//BazaarFilterOff")
        return 1
    end

    if commandText == "//Guise" then
        EQ_InterpretCommand("/useitem Guise of the Deceiver")
        return 1
    end

    if commandText == "//DarkElf" then
        local playerSpawn = EQ_GetPlayerSpawn()
        if playerSpawn ~= 0 then
            local playerRace = EQ_GetSpawnRace(playerSpawn)
            if playerRace == EQ_RACE_OGRE or playerRace == EQ_RACE_TROLL or playerRace == EQ_RACE_BARBARIAN then
                EQ_InterpretCommand("/useitem Guise of the Deceiver")
            end
        end
        return 1
    end

    if commandText == "//Drum" or commandText == "//Mount" then
        EQ_InterpretCommand("/useitem Glowing Black Drum")
        return 1
    end

    if commandText == "//Dismount" then
        EQ_InterpretCommand("/dismount")
        return 1
    end

    if commandText == "//Skeleton" then
        EQ_InterpretCommand("/useitem Amulet of Necropotence")
        return 1
    end

    if commandText == "//Rocket" then
        EQ_InterpretCommand("/useitem Rocketeer Boots")
        return 1
    end

    if commandText == "//Stein" or commandText == "//POK" then
        EQ_InterpretCommand("/useitem Drunkard's Stein")
        return 1
    end

    if commandText == "//Brell"  or commandText == "//Brells" then
        EQ_InterpretCommand("/useitem Mark of Brell")
        return 1
    end

    if commandText == "//Crescent" then
        EQ_InterpretCommand("/useitem Sceptre of Draconic Calling")
        return 1
    end

    if commandText == "//Campfire" then
        EQ_InterpretCommand("/useitem Fellowship Registration Insignia")
        return 1
    end

    if commandText == "//Origin" then
        EQ_InterpretCommand("/alt activate 331")
        return 1
    end

    if commandText == "//Gate" then
        EQ_InterpretCommand("/alt activate 1217")
        return 1
    end

    if commandText == "//MassGroupBuff" or commandText == "//MGB" then
        local playerSpawn = EQ_GetPlayerSpawn()
        if playerSpawn ~= 0 then
            local playerClass = EQ_GetSpawnClass(playerSpawn)

            if EQ_IsSpawnClassPriest(playerClass) == true then
                EQ_InterpretCommand("/alt activate 35")
                return 1
            elseif EQ_IsSpawnClassCaster(playerClass) == true then
                EQ_InterpretCommand("/alt activate 264")
                return 1
            end
        end
    end

    if commandText == "//TranquilBlessings" or commandText == "//MGB2" then
        EQ_InterpretCommand("/alt activate 992")
        return 1
    end

    if commandText == "//ThroneOfHeroes" or commandText == "//GuildLobby" or commandText == "//GL" then
        EQ_InterpretCommand("/alt activate 511")
        return 1
    end

    if commandText == "//BindAffinity" then
        EQ_InterpretCommand("/alt activate 679")
        return 1
    end

    if commandText == "//Identify" then
        EQ_InterpretCommand("/alt activate 356")
        return 1
    end

    if commandText == "//LessonOfTheDevoted" or commandText == "//LOTD" then
        EQ_InterpretCommand("/alt activate 481")
        return 1
    end

    if commandText == "//ExpendientRecovery" or commandText == "//EXPR" then
        EQ_InterpretCommand("/alt activate 484")
        return 1
    end

    if commandText == "//ArmorOfExperience" or commandText == "//AOEXP" then
        EQ_InterpretCommand("/alt activate 2000")
        return 1
    end

    if commandText == "//InfusionOfTheFaithful" or commandText == "//IOTF" then
        EQ_InterpretCommand("/alt activate 482")
        return 1
    end

    if commandText == "//IntensityOfTheResolute" or commandText == "//IOTR" then
        EQ_InterpretCommand("/alt activate 487")
        return 1
    end

    if commandText == "//SteadfastServant" then
        EQ_InterpretCommand("/alt activate 485")
        return 1
    end

    if commandText == "//ChaoticJester" then
        EQ_InterpretCommand("/alt activate 483")
        return 1
    end

    if commandText == "//SummonClockworkBanker" or commandText == "//SCB" then
        EQ_InterpretCommand("/alt activate 8130")
        return 1
    end

    if commandText == "//SummonPermutationPeddler" or commandText == "//SPP" then
        EQ_InterpretCommand("/alt activate 453")
        return 1
    end

    if commandText == "//SummonPersonalTributeMaster" or commandText == "//SPTM" then
        EQ_InterpretCommand("/alt activate 182")
        return 1
    end

    if commandText == "//SummonResupplyAgent" or commandText == "//SRA" then
        EQ_InterpretCommand("/alt activate 8081")
        return 1
    end

    if commandText == "//RemoveLevitation" or commandText == "//RemoveLev" then
        EQ_InterpretCommand("//RemoveBuff Levitate")
        EQ_InterpretCommand("//RemoveBuff Levitation")
        EQ_InterpretCommand("//RemoveBuff Group Perfected Levitation")
        EQ_InterpretCommand("//RemoveBuff Flight of Eagles")
        EQ_InterpretCommand("//RemoveBuff Flight of Falcons")
        EQ_InterpretCommand("//RemoveBuff Shauri's Levitation")
        EQ_InterpretCommand("//RemoveBuff Shauri's Levitation I")
        EQ_InterpretCommand("//RemoveBuff Shauri's Levitation II")
        EQ_InterpretCommand("//RemoveBuff Shauri's Levitation III")
        EQ_InterpretCommand("//RemoveBuff Selo's Song of Travel")
        return 1
    end

    if commandText == "//RemoveCamouflage" or commandText == "//RemoveCamo" then
        EQ_InterpretCommand("//RemoveBuff Camouflage")
        EQ_InterpretCommand("//RemoveBuff Shared Perfected Camouflage")
        EQ_InterpretCommand("//RemoveBuff Shauri's Sonorous Clouding")
        EQ_InterpretCommand("//RemoveBuff Shauri's Sonorous Clouding I")
        EQ_InterpretCommand("//RemoveBuff Shauri's Sonorous Clouding II")
        EQ_InterpretCommand("//RemoveBuff Shauri's Sonorous Clouding III")
        EQ_InterpretCommand("//RemoveBuff Selo's Song of Travel")
        EQ_InterpretCommand("//RemoveBuff Cloak of Shadows")
        EQ_InterpretCommand("//RemoveBuff Cloak of Shadows I")
        EQ_InterpretCommand("//RemoveBuff Cloak of Shadows II")
        EQ_InterpretCommand("//RemoveBuff Cloak of Shadows III")
        return 1
    end

end
