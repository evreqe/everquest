g_AutoInventoryIsEnabled = 0

function AutoInventory_Toggle()
    if g_AutoInventoryIsEnabled == 0 then
        g_AutoInventoryIsEnabled = 1
        EQ_PrintTextToChat("Auto Inventory: On")
    else
        g_AutoInventoryIsEnabled = 0
        EQ_PrintTextToChat("Auto Inventory: Off")
    end

end

function OnInterpretCommand(commandText)
    if commandText == "//AutoInventory" then
        AutoInventory_Toggle()
        return 1
    end

    if commandText == "//AutoInventoryOn" then
        if g_AutoInventoryIsEnabled == 0 then
            AutoInventory_Toggle()
            return 1
        end
    end

    if commandText == "//AutoInventoryOff" then
        if g_AutoInventoryIsEnabled == 1 then
            AutoInventory_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_AutoInventoryIsEnabled == 1 then
        return 1, "- Auto Inventory"
    end
end

function OnFrame()
    if g_AutoInventoryIsEnabled == 0 then
        return
    end

    EQ_InterpretCommand("/autoinventory")
end
