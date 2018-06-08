function OnInterpretCommand(commandText)

    if commandText == "//UpdateItemSlot" then

        if g_UpdateItemSlotIsEnabled == 0 then

            g_UpdateItemSlotIsEnabled = 1
            EQ_PrintTextToChat("UpdateItemSlot: On")

        else

            g_UpdateItemSlotIsEnabled = 0
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
        EQ_PrintTextToChat("UpdateItemSlot: Off")

        return 1

    end

end

function OnFrame()

    if g_UpdateItemSlotIsEnabled == 0 then
        return
    end

    if EQAPP_IsVKKeyDown(EQ_VK_LEFT_ALT) == true then

        UpdateItemSlot_Prev()

    end

    if EQAPP_IsVKKeyDown(EQ_VK_RIGHT_ALT) == true then

        UpdateItemSlot_Next()

    end

    EQ_DrawTextByStyle("IT" .. g_UpdateItemSlotIndex, 800, 350, EQ_DRAW_TEXT_COLOR_YELLOW, EQ_FONT_STYLE_NAME_SPRITE)

    -- UpdateItemSlot_Screenshot()

end
