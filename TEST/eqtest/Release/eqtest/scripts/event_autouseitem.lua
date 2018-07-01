function OnOneSecond()
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerHPPercent = EQ_GetSpawnHPPercent(playerSpawn)

    if playerHPPercent > 0 then
        if playerHPPercent <= 20 then
            EQ_InterpretCommand("/useitem Scale of Rodcet Nife")
        end
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    if playerClass == EQ_CLASS_WARRIOR then
        if playerHPPercent > 0 then
            if playerHPPercent <= 50 then
                EQ_InterpretCommand("/useitem Castaway Breastplate of Havok")
            end
        end
    end
end
