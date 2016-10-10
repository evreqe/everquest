#pragma once

void EQAPP_CharacterFile_Write();
void EQAPP_CharacterFile_WriteTxt();
void EQAPP_CharacterFile_WriteJson();

void EQAPP_CharacterFile_Write()
{
    EQAPP_CharacterFile_WriteTxt();
    EQAPP_CharacterFile_WriteJson();
}

void EQAPP_CharacterFile_WriteTxt()
{
    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info is NULL");
        return;
    }

    uint32_t charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info 2 is NULL");
        return;
    }

    std::string characterName = EQ_GetCharacterName();

    std::stringstream filePath;
    filePath << g_applicationName << "/characters/" << characterName << ".txt";

    std::string filePathStr = filePath.str();

    std::cout << "Writing character file: " << filePathStr << std::endl;

    std::fstream file;
    file.open(filePathStr.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    file << "Name: " << characterName << std::endl << std::endl;

    file << "---------- BANK ----------" << std::endl << std::endl;

    uint32_t bankPlatinum = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_PLATINUM);
    uint32_t bankGold     = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_GOLD);
    uint32_t bankSilver   = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_SILVER);
    uint32_t bankCopper   = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_COPPER);

    file << "Platinum: " << bankPlatinum << std::endl;
    file << "Gold:     " << bankGold     << std::endl;
    file << "Silver:   " << bankSilver   << std::endl;
    file << "Copper:   " << bankCopper   << std::endl;

    file << std::endl;

    for (size_t i = 0; i < EQ_NUM_BANK_SLOTS; i++)
    {
        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << ": EMPTY" << std::endl;
            continue;
        }

        uint32_t itemSubInfo = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        uint32_t itemCount = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << ": ";

            if (itemCount > 1)
            {
                file << itemCount << " x ";
            }

            file << itemName;

            int itemIsLore = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                file << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                file << " [NO DROP]";
            }

            file << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            uint32_t containerItemInfo = EQ_ReadMemory<uint32_t>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                //file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": EMPTY" << std::endl;
                continue;
            }

            uint32_t containerItemSubInfo = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            uint32_t containerItemCount = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            char* containerItemName = EQ_ReadMemory<char*>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": ";

                if (containerItemCount > 1)
                {
                    file << containerItemCount << " x ";
                }

                file << containerItemName;

                int itemIsLore = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    file << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
                if (itemIsNotNoDrop == 0)
                {
                    file << " [NO DROP]";
                }

                file << std::endl;
            }
        }
    }

    file << std::endl;

    file << "---------- INVENTORY ----------" << std::endl << std::endl;

    uint32_t inventoryPlatinum = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM);
    uint32_t inventoryGold     = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD);
    uint32_t inventorySilver   = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER);
    uint32_t inventoryCopper   = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER);

    file << "Platinum: " << inventoryPlatinum << std::endl;
    file << "Gold:     " << inventoryGold     << std::endl;
    file << "Silver:   " << inventorySilver   << std::endl;
    file << "Copper:   " << inventoryCopper   << std::endl;

    file << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_SLOTS; i++)
    {
        std::string slotName = EQ_LIST_EQUIPMENT_SLOT_NAMES.at(i);

        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(charInfo2 + (EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << "(" << slotName << "): EMPTY" << std::endl;
            continue;
        }

        uint32_t itemSubInfo = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        uint32_t itemCount = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << "(" << slotName << "): ";

            if (itemCount > 1)
            {
                file << itemCount << " x ";
            }

            file << itemName;

            int itemIsLore = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                file << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                file << " [NO DROP]";
            }

            file << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            uint32_t containerItemInfo = EQ_ReadMemory<uint32_t>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                //file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": EMPTY" << std::endl;
                continue;
            }

            uint32_t containerItemSubInfo = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            uint32_t containerItemCount = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            char* containerItemName = EQ_ReadMemory<char*>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": ";

                if (containerItemCount > 1)
                {
                    file << containerItemCount << " x ";
                }

                file << containerItemName;

                int itemIsLore = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    file << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
                if (itemIsNotNoDrop == 0)
                {
                    file << " [NO DROP]";
                }

                file << std::endl;
            }
        }
    }

    file << std::endl;

    file.close();
}

void EQAPP_CharacterFile_WriteJson()
{
    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info is NULL");
        return;
    }

    uint32_t charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info 2 is NULL");
        return;
    }

    char characterName[EQ_SIZE_CHAR_INFO_CHARACTER_NAME] = {0};
    memcpy(characterName, (void*)(charInfo + EQ_OFFSET_CHAR_INFO_CHARACTER_NAME), sizeof(characterName));

    std::stringstream filePath;
    filePath << g_applicationName << "/characters/" << characterName << ".json";

    std::cout << "Writing character file: " << filePath.str() << std::endl;

    json_t* j_root = json_object();

    json_object_set_new(j_root, "name", json_string(characterName));

    json_t* j_bank_root = json_object();
    json_object_set_new(j_root, "bank", j_bank_root);

    uint32_t bankPlatinum = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_PLATINUM);
    uint32_t bankGold     = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_GOLD);
    uint32_t bankSilver   = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_SILVER);
    uint32_t bankCopper   = EQ_ReadMemory<uint32_t>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_COPPER);

    json_t* j_bank_currency_node = json_pack("{s: i, s: i, s: i, s: i}", "platinum", bankPlatinum, "gold", bankGold, "silver", bankSilver, "copper", bankCopper);
    json_object_set_new(j_bank_root, "currency", j_bank_currency_node);

    json_t* j_bank_items_root = json_array();
    json_object_set_new(j_bank_root, "items", j_bank_items_root);

    for (size_t i = 0; i < EQ_NUM_BANK_SLOTS; i++)
    {
        json_t* j_bank_item_node = json_object();

        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            j_bank_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", i + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
            json_array_append_new(j_bank_items_root, j_bank_item_node);
            continue;
        }

        uint32_t itemSubInfo = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            uint32_t itemCount = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            uint32_t itemId = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
            uint32_t itemIcon = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

            int itemIsLore = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

            j_bank_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", i + 1, "name", itemName, "count", itemCount, "id", itemId, "icon", itemIcon, "lore", (itemIsLore != 0), "nodrop", (itemIsNotNoDrop == 0));
            json_array_append_new(j_bank_items_root, j_bank_item_node);
        }

        json_t* j_bank_item_node_container_items_root = json_array();
        json_object_set_new(j_bank_item_node, "container_items", j_bank_item_node_container_items_root);

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            json_t* j_bank_container_item_node = json_object();

            uint32_t containerItemInfo = EQ_ReadMemory<uint32_t>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                j_bank_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", j + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
                json_array_append_new(j_bank_item_node_container_items_root, j_bank_container_item_node);
                continue;
            }

            uint32_t containerItemSubInfo = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            char* containerItemName = EQ_ReadMemory<char*>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                uint32_t containerItemCount = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

                uint32_t containerItemId = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
                uint32_t containerItemIcon = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

                int containerItemIsLore = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                int containerItemIsNotNoDrop = EQ_ReadMemory<uint8_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

                j_bank_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", j + 1, "name", containerItemName, "count", containerItemCount, "id", containerItemId, "icon", containerItemIcon, "lore", (containerItemIsLore != 0), "nodrop", (containerItemIsNotNoDrop == 0));
                json_array_append_new(j_bank_item_node_container_items_root, j_bank_container_item_node);
            }
        }
    }

    json_t* j_inventory_root = json_object();
    json_object_set_new(j_root, "inventory", j_inventory_root);

    uint32_t inventoryPlatinum = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM);
    uint32_t inventoryGold     = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD);
    uint32_t inventorySilver   = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER);
    uint32_t inventoryCopper   = EQ_ReadMemory<uint32_t>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER);

    json_t* j_inventory_currency_node = json_pack("{s: i, s: i, s: i, s: i}", "platinum", inventoryPlatinum, "gold", inventoryGold, "silver", inventorySilver, "copper", inventoryCopper);
    json_object_set_new(j_inventory_root, "currency", j_inventory_currency_node);

    json_t* j_inventory_items_root = json_array();
    json_object_set_new(j_inventory_root, "items", j_inventory_items_root);

    for (size_t i = 0; i < EQ_NUM_INVENTORY_SLOTS; i++)
    {
        json_t* j_inventory_item_node = json_object();

        std::string slotName = EQ_LIST_EQUIPMENT_SLOT_NAMES.at(i);

        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(charInfo2 + (EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            j_inventory_item_node = json_pack("{s: i, s: s, s: s, s: i, s: i, s: i}", "slot", i + 1, "slot_name", slotName.c_str(), "name", "(empty)", "count", -1, "id", -1, "icon", -1);
            json_array_append_new(j_inventory_items_root, j_inventory_item_node);
            continue;
        }

        uint32_t itemSubInfo = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            uint32_t itemCount = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            uint32_t itemId = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
            uint32_t itemIcon = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

            int itemIsLore = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

            j_inventory_item_node = json_pack("{s: i, s: s, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", i + 1, "slot_name", slotName.c_str(), "name", itemName, "count", itemCount, "id", itemId, "icon", itemIcon, "lore", (itemIsLore != 0), "nodrop", (itemIsNotNoDrop == 0));
            json_array_append_new(j_inventory_items_root, j_inventory_item_node);
        }

        json_t* j_inventory_item_node_container_items_root = json_array();
        json_object_set_new(j_inventory_item_node, "container_items", j_inventory_item_node_container_items_root);

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            json_t* j_inventory_container_item_node = json_object();

            uint32_t containerItemInfo = EQ_ReadMemory<uint32_t>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                j_inventory_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", j + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
                json_array_append_new(j_inventory_item_node_container_items_root, j_inventory_container_item_node);
                continue;
            }

            uint32_t containerItemSubInfo = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            char* containerItemName = EQ_ReadMemory<char*>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                uint32_t containerItemCount = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

                uint32_t containerItemId = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
                uint32_t containerItemIcon = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

                int containerItemIsLore = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                int containerItemIsNotNoDrop = EQ_ReadMemory<uint8_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

                j_inventory_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", j + 1, "name", containerItemName, "count", containerItemCount, "id", containerItemId, "icon", containerItemIcon, "lore", (containerItemIsLore != 0), "nodrop", (containerItemIsNotNoDrop == 0));
                json_array_append_new(j_inventory_item_node_container_items_root, j_inventory_container_item_node);
            }
        }
    }

    json_dump_file(j_root, filePath.str().c_str(), JSON_PRESERVE_ORDER | JSON_INDENT(4));

    json_decref(j_root);
}

