#pragma once

void EQAPP_BankList_Print(const char* filterItemName);

void EQAPP_BankList_Print(const char* filterItemName)
{
    if (EQ_IsInGame() == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "not in-game");
        return;
    }

    uint32_t charInfo = EQ_GetCharInfo();
    if (charInfo == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "char info is NULL");
        return;
    }

    EQAPP_COUT_SaveFlags();

    std::cout << "Bank List:";
    if (filterItemName != NULL)
    {
        std::cout << " " << filterItemName;
    }
    std::cout << std::endl;

    for (size_t i = 0; i < EQ_NUM_BANK_SLOTS; i++)
    {
        uint32_t itemInfo = EQ_ReadMemory<uint32_t>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            continue;
        }

        uint32_t itemSubInfo = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        uint32_t itemCount = EQ_ReadMemory<uint32_t>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        char* itemName = EQ_ReadMemory<char*>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            if (filterItemName != NULL)
            {
                int itemSlots = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_SLOTS);
                if (itemSlots == 0)
                {
                    if (strstr(itemName, filterItemName) == NULL)
                    {
                        continue;
                    }
                }
            }

            std::cout << std::setfill('0') << std::setw(2) << i + 1;

            // shared bank slots
            if (i == 24 || i == 25)
            {
                std::cout << "(Listsold)";
            }

            std::cout << ": ";

            if (itemCount > 1)
            {
                std::cout << itemCount << " x ";
            }

            std::cout << itemName;

            int itemIsLore = EQ_ReadMemory<uint32_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                std::cout << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                std::cout << " [NO DROP]";
            }

            std::cout << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            uint32_t containerItemInfo = EQ_ReadMemory<uint32_t>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                continue;
            }

            uint32_t containerItemSubInfo = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            uint32_t containerItemCount = EQ_ReadMemory<uint32_t>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            char* containerItemName = EQ_ReadMemory<char*>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
            if (containerItemName != NULL)
            {
                if (filterItemName != NULL)
                {
                    if (strstr(containerItemName, filterItemName) == NULL)
                    {
                        continue;
                    }
                }

                std::cout << std::setfill('0') << std::setw(2) << i + 1 << "-" << std::setfill('0') << std::setw(2) << j + 1 << ": ";

                if (containerItemCount > 1)
                {
                    std::cout << containerItemCount << " x ";
                }

                std::cout << containerItemName;

                int itemIsLore = EQ_ReadMemory<uint32_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    std::cout << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<uint8_t>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
                if (itemIsNotNoDrop == 0)
                {
                    std::cout << " [NO DROP]";
                }

                std::cout << std::endl;
            }
        }
    }

    EQAPP_COUT_RestoreFlags();
}

