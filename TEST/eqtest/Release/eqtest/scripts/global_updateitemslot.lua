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
