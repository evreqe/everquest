#pragma once

bool g_FoodAndDrinkIsEnabled = false;

void EQAPP_FoodAndDrink_Toggle();
void EQAPP_FoodAndDrink_Execute();
void EQAPP_FoodAndDrink_Load();

void EQAPP_FoodAndDrink_Toggle()
{
    EQ_ToggleBool(g_FoodAndDrinkIsEnabled);
    EQAPP_PrintBool("Food and Drink", g_FoodAndDrinkIsEnabled);
}

void EQAPP_FoodAndDrink_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    playerSpawn->Character->Hunger = EQ_HUNGER_AND_THIRST_MAX;
    playerSpawn->Character->Thirst = EQ_HUNGER_AND_THIRST_MAX;
}

void EQAPP_FoodAndDrink_Load()
{
    g_FoodAndDrinkIsEnabled = (EQ_IsZoneInList(EQ_ZONE_ID_LIST_CITY) == true);
}


