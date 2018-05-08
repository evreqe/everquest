function OnTick()

    return

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    if playerClass == EQ_CLASS_BERSERKER then

        EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, 0)
        EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, "IT10727")

    end

    if playerClass == EQ_CLASS_ENCHANTER then

        EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, "IT56")
        EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, "IT12")

    end

end
