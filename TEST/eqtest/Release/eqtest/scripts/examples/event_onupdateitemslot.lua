function OnUpdateItemSlot(updateItemSlot, itemDefinition)

    local updateItemSlotName = "None"

    if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
        updateItemSlotName = "Primary"
    end

    if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
        updateItemSlotName = "Secondary"
    end

    if updateItemSlot == EQ_UPDATE_ITEM_SLOT_HEAD then
        updateItemSlotName = "Head"
    end

    EQ_PrintTextToChat("OnUpdateItemSlot: " .. updateItemSlotName .. "=" .. itemDefinition)

end
