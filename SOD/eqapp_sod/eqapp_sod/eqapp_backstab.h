#pragma once

bool g_backstabIsEnabled = false;
unsigned int g_backstabHotbuttonNumber = 1;

void EQAPP_Backstab_Execute();
void EQAPP_Backstab_Print();
void EQAPP_Backstab_Set(unsigned buttonNumber);

void EQAPP_Backstab_Execute()
{
    if (g_backstabIsEnabled == false)
    {
        return;
    }

    DWORD playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    int spawnClass = EQ_ReadMemory<BYTE>(playerSpawn + EQ_OFFSET_SPAWN_INFO_CLASS);
    if (spawnClass != EQ_CLASS_ROGUE)
    {
        return;
    }

    EQ_DoHotButton(g_backstabHotbuttonNumber);
}

void EQAPP_Backstab_Print()
{
    std::cout << "Backstab Hotbutton: " << g_backstabHotbuttonNumber << std::endl;
}

void EQAPP_Backstab_Set(unsigned buttonNumber)
{
    if (buttonNumber < EQ_HOTBUTTON_NUMBER_MIN || buttonNumber > EQ_HOTBUTTON_NUMBER_MAX)
    {
        std::stringstream ss;
        ss << "invalid hotbutton number specified: " << buttonNumber;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    g_backstabHotbuttonNumber = buttonNumber;
}

