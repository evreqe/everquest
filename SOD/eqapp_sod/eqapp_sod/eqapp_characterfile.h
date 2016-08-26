#ifndef EQAPP_CHARACTERFILE_H
#define EQAPP_CHARACTERFILE_H

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
    DWORD charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info is NULL");
        return;
    }

    DWORD charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info 2 is NULL");
        return;
    }

    std::string characterName = EQ_GetCharacterName();

    std::stringstream filePath;
    filePath << "eqapp/characters/" << characterName << ".txt";

    std::cout << "Writing character file: " << filePath.str() << std::endl;

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    file << "Name: " << characterName << std::endl << std::endl;

    file << "---------- BANK ----------" << std::endl << std::endl;

    DWORD bankPlatinum = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_PLATINUM);
    DWORD bankGold     = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_GOLD);
    DWORD bankSilver   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_SILVER);
    DWORD bankCopper   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_COPPER);

    file << "Platinum: " << bankPlatinum << std::endl;
    file << "Gold:     " << bankGold     << std::endl;
    file << "Silver:   " << bankSilver   << std::endl;
    file << "Copper:   " << bankCopper   << std::endl;

    file << std::endl;

    for (size_t i = 0; i < EQ_NUM_BANK_SLOTS; i++)
    {
        DWORD itemInfo = EQ_ReadMemory<DWORD>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << ": EMPTY" << std::endl;
            continue;
        }

        DWORD itemSubInfo = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        DWORD itemCount = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << ": ";

            if (itemCount > 1)
            {
                file << itemCount << " x ";
            }

            file << itemName;

            int itemIsLore = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                file << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                file << " [NO DROP]";
            }

            file << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            DWORD containerItemInfo = EQ_ReadMemory<DWORD>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                //file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": EMPTY" << std::endl;
                continue;
            }

            DWORD containerItemSubInfo = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            DWORD containerItemCount = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            PCHAR containerItemName = EQ_ReadMemory<PCHAR>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": ";

                if (containerItemCount > 1)
                {
                    file << containerItemCount << " x ";
                }

                file << containerItemName;

                int itemIsLore = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    file << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
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

    DWORD inventoryPlatinum = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM);
    DWORD inventoryGold     = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD);
    DWORD inventorySilver   = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER);
    DWORD inventoryCopper   = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER);

    file << "Platinum: " << inventoryPlatinum << std::endl;
    file << "Gold:     " << inventoryGold     << std::endl;
    file << "Silver:   " << inventorySilver   << std::endl;
    file << "Copper:   " << inventoryCopper   << std::endl;

    file << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_SLOTS; i++)
    {
        std::string slotName = EQ_LIST_EQUIPMENT_SLOT_NAMES.at(i);

        DWORD itemInfo = EQ_ReadMemory<DWORD>(charInfo2 + (EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << "(" << slotName << "): EMPTY" << std::endl;
            continue;
        }

        DWORD itemSubInfo = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        DWORD itemCount = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            file << std::setfill('0') << std::setw(2) << i + 1 << "(" << slotName << "): ";

            if (itemCount > 1)
            {
                file << itemCount << " x ";
            }

            file << itemName;

            int itemIsLore = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                file << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                file << " [NO DROP]";
            }

            file << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            DWORD containerItemInfo = EQ_ReadMemory<DWORD>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                //file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": EMPTY" << std::endl;
                continue;
            }

            DWORD containerItemSubInfo = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            DWORD containerItemCount = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            PCHAR containerItemName = EQ_ReadMemory<PCHAR>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                file << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": ";

                if (containerItemCount > 1)
                {
                    file << containerItemCount << " x ";
                }

                file << containerItemName;

                int itemIsLore = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    file << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
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
    DWORD charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info is NULL");
        return;
    }

    DWORD charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info 2 is NULL");
        return;
    }

    char characterName[EQ_SIZE_CHAR_INFO_CHARACTER_NAME] = {0};
    memcpy(characterName, (LPVOID)(charInfo + EQ_OFFSET_CHAR_INFO_CHARACTER_NAME), sizeof(characterName));

    std::stringstream filePath;
    filePath << "eqapp/characters/" << characterName << ".json";

    std::cout << "Writing character file: " << filePath.str() << std::endl;

    json_t* j_root = json_object();

    json_object_set_new(j_root, "name", json_string(characterName));

    json_t* j_bank_root = json_object();
    json_object_set_new(j_root, "bank", j_bank_root);

    DWORD bankPlatinum = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_PLATINUM);
    DWORD bankGold     = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_GOLD);
    DWORD bankSilver   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_SILVER);
    DWORD bankCopper   = EQ_ReadMemory<DWORD>(charInfo + EQ_OFFSET_CHAR_INFO_BANK_COPPER);

    json_t* j_bank_currency_node = json_pack("{s: i, s: i, s: i, s: i}", "platinum", bankPlatinum, "gold", bankGold, "silver", bankSilver, "copper", bankCopper);
    json_object_set_new(j_bank_root, "currency", j_bank_currency_node);

    json_t* j_bank_items_root = json_array();
    json_object_set_new(j_bank_root, "items", j_bank_items_root);

    for (size_t i = 0; i < EQ_NUM_BANK_SLOTS; i++)
    {
        json_t* j_bank_item_node = json_object();

        DWORD itemInfo = EQ_ReadMemory<DWORD>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            j_bank_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", i + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
            json_array_append_new(j_bank_items_root, j_bank_item_node);
            continue;
        }

        DWORD itemSubInfo = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            DWORD itemCount = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            DWORD itemId = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
            DWORD itemIcon = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

            int itemIsLore = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

            j_bank_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", i + 1, "name", itemName, "count", itemCount, "id", itemId, "icon", itemIcon, "lore", (itemIsLore != 0), "nodrop", (itemIsNotNoDrop == 0));
            json_array_append_new(j_bank_items_root, j_bank_item_node);
        }

        json_t* j_bank_item_node_container_items_root = json_array();
        json_object_set_new(j_bank_item_node, "container_items", j_bank_item_node_container_items_root);

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            json_t* j_bank_container_item_node = json_object();

            DWORD containerItemInfo = EQ_ReadMemory<DWORD>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                j_bank_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", j + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
                json_array_append_new(j_bank_item_node_container_items_root, j_bank_container_item_node);
                continue;
            }

            DWORD containerItemSubInfo = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            PCHAR containerItemName = EQ_ReadMemory<PCHAR>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                DWORD containerItemCount = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

                DWORD containerItemId = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
                DWORD containerItemIcon = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

                int containerItemIsLore = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                int containerItemIsNotNoDrop = EQ_ReadMemory<BYTE>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

                j_bank_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", j + 1, "name", containerItemName, "count", containerItemCount, "id", containerItemId, "icon", containerItemIcon, "lore", (containerItemIsLore != 0), "nodrop", (containerItemIsNotNoDrop == 0));
                json_array_append_new(j_bank_item_node_container_items_root, j_bank_container_item_node);
            }
        }
    }

    json_t* j_inventory_root = json_object();
    json_object_set_new(j_root, "inventory", j_inventory_root);

    DWORD inventoryPlatinum = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM);
    DWORD inventoryGold     = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD);
    DWORD inventorySilver   = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER);
    DWORD inventoryCopper   = EQ_ReadMemory<DWORD>(charInfo2 + EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER);

    json_t* j_inventory_currency_node = json_pack("{s: i, s: i, s: i, s: i}", "platinum", inventoryPlatinum, "gold", inventoryGold, "silver", inventorySilver, "copper", inventoryCopper);
    json_object_set_new(j_inventory_root, "currency", j_inventory_currency_node);

    json_t* j_inventory_items_root = json_array();
    json_object_set_new(j_inventory_root, "items", j_inventory_items_root);

    for (size_t i = 0; i < EQ_NUM_INVENTORY_SLOTS; i++)
    {
        json_t* j_inventory_item_node = json_object();

        std::string slotName = EQ_LIST_EQUIPMENT_SLOT_NAMES.at(i);

        DWORD itemInfo = EQ_ReadMemory<DWORD>(charInfo2 + (EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            j_inventory_item_node = json_pack("{s: i, s: s, s: s, s: i, s: i, s: i}", "slot", i + 1, "slot_name", slotName.c_str(), "name", "(empty)", "count", -1, "id", -1, "icon", -1);
            json_array_append_new(j_inventory_items_root, j_inventory_item_node);
            continue;
        }

        DWORD itemSubInfo = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            DWORD itemCount = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            DWORD itemId = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
            DWORD itemIcon = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

            int itemIsLore = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

            j_inventory_item_node = json_pack("{s: i, s: s, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", i + 1, "slot_name", slotName.c_str(), "name", itemName, "count", itemCount, "id", itemId, "icon", itemIcon, "lore", (itemIsLore != 0), "nodrop", (itemIsNotNoDrop == 0));
            json_array_append_new(j_inventory_items_root, j_inventory_item_node);
        }

        json_t* j_inventory_item_node_container_items_root = json_array();
        json_object_set_new(j_inventory_item_node, "container_items", j_inventory_item_node_container_items_root);

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            json_t* j_inventory_container_item_node = json_object();

            DWORD containerItemInfo = EQ_ReadMemory<DWORD>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                j_inventory_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i}", "slot", j + 1, "name", "(empty)", "count", -1, "id", -1, "icon", -1);
                json_array_append_new(j_inventory_item_node_container_items_root, j_inventory_container_item_node);
                continue;
            }

            DWORD containerItemSubInfo = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            PCHAR containerItemName = EQ_ReadMemory<PCHAR>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                DWORD containerItemCount = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

                DWORD containerItemId = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ID);
                DWORD containerItemIcon = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_ICON);

                int containerItemIsLore = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                int containerItemIsNotNoDrop = EQ_ReadMemory<BYTE>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);

                j_inventory_container_item_node = json_pack("{s: i, s: s, s: i, s: i, s: i, s: i, s: i}", "slot", j + 1, "name", containerItemName, "count", containerItemCount, "id", containerItemId, "icon", containerItemIcon, "lore", (containerItemIsLore != 0), "nodrop", (containerItemIsNotNoDrop == 0));
                json_array_append_new(j_inventory_item_node_container_items_root, j_inventory_container_item_node);
            }
        }
    }

    json_dump_file(j_root, filePath.str().c_str(), JSON_PRESERVE_ORDER | JSON_INDENT(4));

    json_decref(j_root);
}

#endif // EQAPP_CHARACTERFILE_H
