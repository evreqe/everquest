#pragma once

bool g_foodAndDrinkIsEnabled = false;

void EQAPP_FoodAndDrink_Toggle();
void EQAPP_FoodAndDrink_Execute();
void EQAPP_FoodAndDrink_Load();

void EQAPP_FoodAndDrink_Toggle()
{
    EQ_ToggleBool(g_foodAndDrinkIsEnabled);
    EQAPP_PrintBool("Food and Drink", g_foodAndDrinkIsEnabled);
}

void EQAPP_FoodAndDrink_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    playerSpawn->Character->Hunger = 32000;
    playerSpawn->Character->Thirst = 32000;
}

void EQAPP_FoodAndDrink_Load()
{
    g_foodAndDrinkIsEnabled = (EQ_IsZoneInList(EQ_ZONE_ID_LIST_CITY) == true);
}


