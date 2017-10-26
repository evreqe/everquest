#pragma once

void EQAPP_AutoInventory_Execute();

void EQAPP_AutoInventory_Execute()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (playerSpawn->Character->CursorItem == NULL)
    {
        return;
    }

    EQ_FUNCTION_AutoInventory(playerSpawn->Character, &playerSpawn->Character->CursorItem, 0);
}
