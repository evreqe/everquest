function Transmog()
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)

    if playerClass == EQ_CLASS_WARRIOR then
        if EQ_GetSpawnEquipmentPrimaryID(playerSpawn) ~= 0 then
            if EQ_GetSpawnEquipmentSecondaryID(playerSpawn) ~= 0 then
                EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, "IT60018") -- The Lion
                EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, "IT13958") -- Inny Star Shield
                --EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_SECONDARY, "IT10537") -- Vallon Zek Shield
            else
                EQ_SetSpawnItemSlot(playerSpawn, EQ_UPDATE_ITEM_SLOT_PRIMARY, "IT12221") -- Resplendent Great Sword
            end
        end
    end
end

function OnTick()
    Transmog()
end

function OnLoad()
    Transmog()
end

function OnEnterZone(zoneID)
    Transmog()
end
