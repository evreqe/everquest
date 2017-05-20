#pragma once

bool g_foodAndDrinkIsEnabled = true;

void EQAPP_FoodAndDrink_Execute();

void EQAPP_FoodAndDrink_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (EQ_IsZoneCity() == true)
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

