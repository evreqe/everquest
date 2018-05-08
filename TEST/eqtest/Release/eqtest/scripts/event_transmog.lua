function OnUpdateItemSlot(updateItemSlot, itemDefinition)

    if string.find(itemDefinition, "IT") == nil then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    if playerClass == EQ_CLASS_BARD then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT148" -- epic
        end

    end

    if playerClass == EQ_CLASS_BERSERKER then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            -- return 1, "IT80" -- epic
            return 1, "IT10727" -- epic
            -- return 1, "IT11109" -- orange glowing axe
            -- return 1, "IT11113" -- orange lightsaber sword
            -- return 1, "IT13925" -- huge axe
        end

    end

    if playerClass == EQ_CLASS_CLERIC then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT156" -- epic
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT227" -- epic shield
        end

    end

    if playerClass == EQ_CLASS_DRUID then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT150" -- epic
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT27" -- book
        end

    end

    if playerClass == EQ_CLASS_ENCHANTER then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT157" -- epic
            -- return 1, "IT12" -- fancy staff
            -- return 1, "IT56" -- white cup
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT56" -- white cup
            -- return 1, "IT11530" -- blue shield
        end

    end

    if playerClass == EQ_CLASS_WARRIOR then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT101227"
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT101242" -- wurmslayer
            -- return 1, "IT12610" -- purple axe
        end

    end

end
