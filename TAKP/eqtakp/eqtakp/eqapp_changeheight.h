#pragma once

bool g_changeHeightIsEnabled = true;

void EQAPP_ChangeHeight_Execute();

void EQAPP_ChangeHeight_Execute()
{
    auto spawn = EQ_GetFirstSpawn();
    while (spawn != nullptr)
    {
        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawn->Height > 5.0f)
            {
                ((EQClass::EQPlayer*)spawn)->ChangeHeight(5.0f);
            }
        }

        spawn = spawn->Next;
    }
}

