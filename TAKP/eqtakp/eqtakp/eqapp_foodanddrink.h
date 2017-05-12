#pragma once

bool g_foodAndDrinkIsEnabled = true;

void EQAPP_FoodAndDrink_Execute();

void EQAPP_FoodAndDrink_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == nullptr)
    {
        return;
    }

    bool bEnabled = false;

/*
    int8_t playerClass = playerSpawn->Class;

    if (playerClass == EQ_CLASS_WARRIOR || playerSpawn->Class == EQ_CLASS_MONK || playerSpawn->Class == EQ_CLASS_ROGUE)
    {
        if (playerSpawn->HPCurrent == playerSpawn->HPMax)
        {
            bEnabled = true;
        }
    }
    else
    {
        uint16_t currentMana = playerSpawn->Character->Mana;

        uint16_t maxMana = EQ_CLASS_POINTER_PlayerCharacter->Max_Mana();

        if (currentMana == maxMana)
        {
            bEnabled = true;
        }
    }
*/

    auto zoneID = EQ_GetZoneID();

    if
    (
        zoneID == EQ_ZONE_ID_POKNOWLEDGE ||
        zoneID == EQ_ZONE_ID_NEXUS ||
        zoneID == EQ_ZONE_ID_BAZAAR ||
        zoneID == EQ_ZONE_ID_FELWITHEA ||
        zoneID == EQ_ZONE_ID_FELWITHEB ||
        zoneID == EQ_ZONE_ID_HALAS ||
        zoneID == EQ_ZONE_ID_RIVERVALE
    )
    {
        bEnabled = true;
    }

    if (bEnabled == true)
    {
        playerSpawn->Character->Hunger = 32000;
        playerSpawn->Character->Thirst = 32000;
    }
    //else
    //{
        //playerSpawn->Character->Hunger = 3500;
        //playerSpawn->Character->Thirst = 3500;
    //}
}

