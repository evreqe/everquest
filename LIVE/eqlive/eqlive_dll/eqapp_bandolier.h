#pragma once

bool g_BandolierIsEnabled = false;

void EQAPP_Bandolier_Toggle();
void EQAPP_Bandolier_On();
void EQAPP_Bandolier_Off();
void EQAPP_Bandolier_Load();
void EQAPP_Bandolier_Save();
void EQAPP_Bandolier_SaveEx(const std::string& fileName);
void EQAPP_Bandolier_Print();

void EQAPP_Bandolier_Toggle()
{
    EQ_ToggleBool(g_BandolierIsEnabled);
    EQAPP_PrintBool("Bandolier", g_BandolierIsEnabled);
}

void EQAPP_Bandolier_On()
{
    if (g_BandolierIsEnabled == false)
    {
        EQAPP_Bandolier_Toggle();
    }
}

void EQAPP_Bandolier_Off()
{
    if (g_BandolierIsEnabled == true)
    {
        EQAPP_Bandolier_Toggle();
    }
}

void EQAPP_Bandolier_Load()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.size() == 0)
    {
        return;
    }

    auto charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        return;
    }

    auto charInfo2Bandolier = (EQ::CharInfo2Bandolier_ptr)(charInfo2 + EQ_OFFSET_CharInfo2__Bandolier);

    std::stringstream filePath;
    filePath << g_EQAppName << "/bandolier/" << playerName << ".txt";

    std::string filePathStr = filePath.str();

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        std::vector<std::string> tokens = EQAPP_String_Split(line, '^');
        if (tokens.size() == 0)
        {
            continue;
        }

        // index, set name, item id 1, icon id 1, item name 1, 2, 2, 2, 3, 3, 3, 4, 4, 4
        if (tokens.size() == 14)
        {
            int index = std::stol(tokens.at(0));

            std::string setName = tokens.at(1);

            int itemID0 = std::stol(tokens.at(2));
            int iconID0 = std::stol(tokens.at(3));
            std::string itemName0 = tokens.at(4);

            int itemID1 = std::stol(tokens.at(5));
            int iconID1 = std::stol(tokens.at(6));
            std::string itemName1 = tokens.at(7);

            int itemID2 = std::stol(tokens.at(8));
            int iconID2 = std::stol(tokens.at(9));
            std::string itemName2 = tokens.at(10);

            int itemID3 = std::stol(tokens.at(11));
            int iconID3 = std::stol(tokens.at(12));
            std::string itemName3 = tokens.at(13);

            if (setName == "NULL")
            {
                std::memset(charInfo2Bandolier->Bandolier[index].Name, 0, EQ_SIZE_BANDOLIER_SET_NAME);
            }
            else
            {
                std::memcpy(charInfo2Bandolier->Bandolier[index].Name, setName.c_str(), EQ_SIZE_BANDOLIER_SET_NAME);
            }

            charInfo2Bandolier->Bandolier[index].Items[0].ItemID = itemID0;
            charInfo2Bandolier->Bandolier[index].Items[0].IconID = iconID0;

            if (itemName0 == "NULL")
            {
                std::memset(charInfo2Bandolier->Bandolier[index].Items[0].Name, 0, EQ_SIZE_BANDOLIER_ITEM_NAME);
            }
            else
            {
                std::memcpy(charInfo2Bandolier->Bandolier[index].Items[0].Name, itemName0.c_str(), EQ_SIZE_BANDOLIER_ITEM_NAME);
            }

            charInfo2Bandolier->Bandolier[index].Items[1].ItemID = itemID1;
            charInfo2Bandolier->Bandolier[index].Items[1].IconID = iconID1;

            if (itemName1 == "NULL")
            {
                std::memset(charInfo2Bandolier->Bandolier[index].Items[1].Name, 0, EQ_SIZE_BANDOLIER_ITEM_NAME);
            }
            else
            {
                std::memcpy(charInfo2Bandolier->Bandolier[index].Items[1].Name, itemName1.c_str(), EQ_SIZE_BANDOLIER_ITEM_NAME);
            }

            charInfo2Bandolier->Bandolier[index].Items[2].ItemID = itemID2;
            charInfo2Bandolier->Bandolier[index].Items[2].IconID = iconID2;

            if (itemName2 == "NULL")
            {
                std::memset(charInfo2Bandolier->Bandolier[index].Items[2].Name, 0, EQ_SIZE_BANDOLIER_ITEM_NAME);
            }
            else
            {
                std::memcpy(charInfo2Bandolier->Bandolier[index].Items[2].Name, itemName2.c_str(), EQ_SIZE_BANDOLIER_ITEM_NAME);
            }

            charInfo2Bandolier->Bandolier[index].Items[3].ItemID = itemID3;
            charInfo2Bandolier->Bandolier[index].Items[3].IconID = iconID3;

            if (itemName3 == "NULL")
            {
                std::memset(charInfo2Bandolier->Bandolier[index].Items[3].Name, 0, EQ_SIZE_BANDOLIER_ITEM_NAME);
            }
            else
            {
                std::memcpy(charInfo2Bandolier->Bandolier[index].Items[3].Name, itemName3.c_str(), EQ_SIZE_BANDOLIER_ITEM_NAME);
            }
        }
    }

    std::cout << "Bandolier loaded from file: " << filePathStr << std::endl;

    file.close();
}

void EQAPP_Bandolier_Save()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string playerName = EQ_GetSpawnName(playerSpawn);
    if (playerName.size() == 0)
    {
        return;
    }

    EQAPP_Bandolier_SaveEx(playerName);
}

void EQAPP_Bandolier_SaveEx(const std::string& fileName)
{
    auto charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        return;
    }

    auto charInfo2Bandolier = (EQ::CharInfo2Bandolier_ptr)(charInfo2 + EQ_OFFSET_CharInfo2__Bandolier);

    std::stringstream filePath;
    filePath << g_EQAppName << "/bandolier/" << fileName << ".txt";

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());
        return;
    }

    file << "#Index^SetName^ItemID1^IconID1^ItemName1^ItemID2^IconID2^ItemName2^ItemID3^IconID3^ItemName3^ItemID4^IconID4^ItemName4\n";

    for (unsigned int i = 0; i < EQ_NUM_BANDOLIER_SLOTS; i++)
    {
        std::string name = charInfo2Bandolier->Bandolier[i].Name;
        if (name.size() == 0)
        {
            name = "NULL";
        }

        std::string itemName0 = charInfo2Bandolier->Bandolier[i].Items[0].Name;
        if (itemName0.size() == 0)
        {
            itemName0 = "NULL";
        }

        std::string itemName1 = charInfo2Bandolier->Bandolier[i].Items[1].Name;
        if (itemName1.size() == 0)
        {
            itemName1 = "NULL";
        }

        std::string itemName2 = charInfo2Bandolier->Bandolier[i].Items[2].Name;
        if (itemName2.size() == 0)
        {
            itemName2 = "NULL";
        }

        std::string itemName3 = charInfo2Bandolier->Bandolier[i].Items[3].Name;
        if (itemName3.size() == 0)
        {
            itemName3 = "NULL";
        }

        std::stringstream ss;
        ss << i << "^"
           << name << "^"
           << charInfo2Bandolier->Bandolier[i].Items[0].ItemID << "^"
           << charInfo2Bandolier->Bandolier[i].Items[0].IconID << "^"
           << itemName0 << "^"
           << charInfo2Bandolier->Bandolier[i].Items[1].ItemID << "^"
           << charInfo2Bandolier->Bandolier[i].Items[1].IconID << "^"
           << itemName1 << "^"
           << charInfo2Bandolier->Bandolier[i].Items[2].ItemID << "^"
           << charInfo2Bandolier->Bandolier[i].Items[2].IconID << "^"
           << itemName2   << "^"
           << charInfo2Bandolier->Bandolier[i].Items[3].ItemID << "^"
           << charInfo2Bandolier->Bandolier[i].Items[3].IconID << "^"
           << itemName3;

        file << ss.str().c_str() << "\n";
    }

    std::cout << "Bandolier saved to file: " << filePathStr << std::endl;

    file.close();
}

void EQAPP_Bandolier_Print()
{
    auto charInfo2 = EQ_GetCharInfo2();
    if (charInfo2 == NULL)
    {
        return;
    }

    auto charInfo2Bandolier = (EQ::CharInfo2Bandolier_ptr)(charInfo2 + EQ_OFFSET_CharInfo2__Bandolier);

    std::cout << "Bandolier:" << std::endl;

    for (unsigned int i = 0; i < EQ_NUM_BANDOLIER_SLOTS; i++)
    {
        std::cout << "[" << i + 1 << "] " << charInfo2Bandolier->Bandolier[i].Name << std::endl;

        std::cout << "[" << i + 1 << "-1] " << charInfo2Bandolier->Bandolier[i].Items[0].Name << std::endl;
        std::cout << "[" << i + 1 << "-2] " << charInfo2Bandolier->Bandolier[i].Items[1].Name << std::endl;
        std::cout << "[" << i + 1 << "-3] " << charInfo2Bandolier->Bandolier[i].Items[2].Name << std::endl;
        std::cout << "[" << i + 1 << "-4] " << charInfo2Bandolier->Bandolier[i].Items[3].Name << std::endl;
    }
}
