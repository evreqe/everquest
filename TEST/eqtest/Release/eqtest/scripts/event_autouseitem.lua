g_AutoUseItemIsEnabled = 1

function AutoUseItem_Toggle()
    if g_AutoUseItemIsEnabled == 0 then
        g_AutoUseItemIsEnabled = 1
        EQ_PrintTextToChat("Auto Use Item: On")
    else
        g_AutoUseItemIsEnabled = 0
        EQ_PrintTextToChat("Auto Use Item: Off")
    end

end

function OnInterpretCommand(commandText)
    if commandText == "//AutoUseItem" then
        AutoUseItem_Toggle()
        return 1
    end

    if commandText == "//AutoUseItemOn" then
        if g_AutoUseItemIsEnabled == 0 then
            AutoUseItem_Toggle()
        end
        return 1
    end

    if commandText == "//AutoUseItemOff" then
        if g_AutoUseItemIsEnabled == 1 then
            AutoUseItem_Toggle()
        end
        return 1
    end
end

function OnDrawHUD()
    if g_AutoUseItemIsEnabled == 1 then
        return 1, "- Auto Use Item"
    end
end

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
