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

    if commandText == "//Drum" or commandText == "//Mount" then
        EQ_InterpretCommand("/useitem Glowing Black Drum")
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
            local spawnClass = EQ_GetSpawnClass(playerSpawn)

            if EQ_IsSpawnClassPriest(spawnClass) == true then
                EQ_InterpretCommand("/alt activate 35")
                return 1
            elseif EQ_IsSpawnClassCaster(spawnClass) == true then
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

end
