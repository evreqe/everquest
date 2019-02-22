g_UpdateItemSlotIsEnabled = 0

g_UpdateItemSlotIndex = 0

function UpdateItemSlot_Set()
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, "IT" .. g_UpdateItemSlotIndex)
    EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, 0)
end

function UpdateItemSlot_Prev()
    g_UpdateItemSlotIndex = g_UpdateItemSlotIndex - 1

    if g_UpdateItemSlotIndex < 0 then
        g_UpdateItemSlotIndex = 0
    end

    UpdateItemSlot_Set()
end

function UpdateItemSlot_Next()
    g_UpdateItemSlotIndex = g_UpdateItemSlotIndex + 1

    UpdateItemSlot_Set()
end

function UpdateItemSlot_Screenshot()
    EQ_TakeScreenshot("Screenshots\\IT" .. g_UpdateItemSlotIndex .. ".jpg")
end

function OnInterpretCommand(commandText)
    if commandText == "//UpdateItemSlot" then
        if g_UpdateItemSlotIsEnabled == 0 then
            g_UpdateItemSlotIsEnabled = 1
            EQ_PrintTextToChat("UpdateItemSlot: On")
        else
            g_UpdateItemSlotIsEnabled = 0
            g_UpdateItemSlotIndex = 0
            EQ_PrintTextToChat("UpdateItemSlot: Off")
        end

        return 1
    end

    if commandText == "//UpdateItemSlotOn" then
        g_UpdateItemSlotIsEnabled = 1
        EQ_PrintTextToChat("UpdateItemSlot: On")
        return 1
    end

    if commandText == "//UpdateItemSlotOff" then
        g_UpdateItemSlotIsEnabled = 0
        g_UpdateItemSlotIndex = 0
        EQ_PrintTextToChat("UpdateItemSlot: Off")
        return 1
    end

end

function OnFrame()
    if g_UpdateItemSlotIsEnabled == 0 then
        return
    end

    -- if EQAPP_IsVKKeyDown(EQ_VK_LEFT_ALT) == true then
        -- UpdateItemSlot_Prev()
    -- end

    -- if EQAPP_IsVKKeyDown(EQ_VK_RIGHT_ALT) == true then
        -- UpdateItemSlot_Next()
    -- end

    EQ_DrawTextByStyle("IT" .. g_UpdateItemSlotIndex, 800, 350, EQ_DRAW_TEXT_COLOR_YELLOW, EQ_FONT_STYLE_NAME_SPRITE)
end

function OnOneSecond()
    if g_UpdateItemSlotIsEnabled == 0 then
        return
    end

    UpdateItemSlot_Screenshot()

    UpdateItemSlot_Next()
end

function OnUpdateItemSlot(updateItemSlot, itemDefinition)
    if string.find(itemDefinition, "IT") == nil then
        return
    end

    EQAPP_PrintTextToFileNoDuplicates("updateitemslot.txt", itemDefinition)
end