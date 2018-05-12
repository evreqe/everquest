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

    if playerClass == EQ_CLASS_BEASTLORD then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            -- return 1, "IT10029" -- epic prim
            return 1, "IT10736" -- epic 1.5
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            -- return 1, "IT10015" -- epic sec
            return 1, "IT10736" -- epic 1.5
        end

    end

    if playerClass == EQ_CLASS_BERSERKER then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            -- return 1, "IT80" -- epic
            return 1, "IT10727" -- epic
            -- return 1, "IT10737" -- epic 1.5
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
            return 1, "IT27" -- closed book
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

    if playerClass == EQ_CLASS_MAGICIAN then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT32" -- broom
            -- return 1, "IT32" -- shovel
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT27" -- closed book
            -- return 1, "IT36" -- torch
        end

    end

    if playerClass == EQ_CLASS_MONK then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT10523" -- epic
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT"
        end

    end

    if playerClass == EQ_CLASS_NECROMANCER then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT125" -- sarnak skull staff
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT216" -- sarnak shield
        end

    end

    if playerClass == EQ_CLASS_PALADIN then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT62" -- fire sword
            -- return 1, "IT160" -- epic
        end

    end

    if playerClass == EQ_CLASS_RANGER then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT149" -- epic
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT149" -- epic
        end

    end


    if playerClass == EQ_CLASS_ROGUE then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT11842"
            -- return 1, "IT12496" -- kitchen knife
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT11842"
            -- return 1, "IT12496" -- kitchen knife
        end

    end
    if playerClass == EQ_CLASS_SHADOWKNIGHT then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT145" -- epic
        end

    end

    if playerClass == EQ_CLASS_SHAMAN then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT154" -- epic
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            return 1, "IT221" -- sarnak shield
            --return 1, "IT101237" -- sarnak shield modern
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

    if playerClass == EQ_CLASS_WIZARD then

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_PRIMARY then
            return 1, "IT45" -- caster staff
        end

        if updateItemSlot == EQ_UPDATE_ITEM_SLOT_SECONDARY then
            -- return 1, "IT210" -- white glowing shield
            -- return 1, "IT56" -- white cup
            return 1, "IT72" -- glowing orb
        end

    end

end
