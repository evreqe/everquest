function OnOneSecond()

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    if playerClass == EQ_CLASS_WARRIOR then

        local playerHPPercent = EQ_GetSpawnHPPercent(playerSpawn)
        if playerHPPercent > 0 then

            if playerHPPercent <= 50 then
                EQ_InterpretCommand("/useitem Boreal Breastplate of Havok")
            end

            if playerHPPercent <= 25 then
                EQ_InterpretCommand("/useitem Potion of Healing")
                EQ_InterpretCommand("/useitem Scale of Rodcet Nife")
            end

        end

    end

end
