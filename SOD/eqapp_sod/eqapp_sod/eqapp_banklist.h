#ifndef EQAPP_BANKLIST_H
#define EQAPP_BANKLIST_H

void EQAPP_BankList_Print(const char* filterItemName);

void EQAPP_BankList_Print(const char* filterItemName)
{
    if (EQ_IsInGame() == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "not in-game");
        return;
    }

    DWORD charInfo = EQ_GetCharInfo();
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
        DWORD itemInfo = EQ_ReadMemory<DWORD>(charInfo + (EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST + (i * 4)));
        if (itemInfo == NULL)
        {
            continue;
        }

        DWORD itemSubInfo = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

        DWORD itemCount = EQ_ReadMemory<DWORD>(itemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

        PCHAR itemName = EQ_ReadMemory<PCHAR>(itemInfo + EQ_OFFSET_ITEM_INFO_NAME);
        if (itemName != NULL)
        {
            if (filterItemName != NULL)
            {
                DWORD itemSlots = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_SLOTS);
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

            int itemIsLore = EQ_ReadMemory<DWORD>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
            if (itemIsLore != 0)
            {
                std::cout << " [LORE ITEM]";
            }

            int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(itemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
            if (itemIsNotNoDrop == 0)
            {
                std::cout << " [NO DROP]";
            }

            std::cout << std::endl;
        }

        for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
        {
            DWORD containerItemInfo = EQ_ReadMemory<DWORD>(itemInfo + (EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO + (j * 4)));
            if (containerItemInfo == NULL)
            {
                continue;
            }

            DWORD containerItemSubInfo = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO);

            DWORD containerItemCount = EQ_ReadMemory<DWORD>(containerItemInfo + EQ_OFFSET_ITEM_INFO_COUNT);

            PCHAR containerItemName = EQ_ReadMemory<PCHAR>(containerItemInfo + EQ_OFFSET_ITEM_INFO_NAME);
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

                int itemIsLore = EQ_ReadMemory<DWORD>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_LORE);
                if (itemIsLore != 0)
                {
                    std::cout << " [LORE ITEM]";
                }

                int itemIsNotNoDrop = EQ_ReadMemory<BYTE>(containerItemSubInfo + EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP);
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

#endif // EQAPP_BANKLIST_H
