#pragma once

bool g_ReplaceRacesIsEnabled = true;

uint32_t g_ReplaceRacesTimer = 0;
uint32_t g_ReplaceRacesTimerDelay = 3000;

void EQAPP_ReplaceRaces_Toggle();
void EQAPP_ReplaceRaces_Execute();
bool EQAPP_ReplaceRaces_HandleEvent_EQPlayer__do_change_form(void* this_ptr, EQ::ChangeForm_ptr changeForm);

void EQAPP_ReplaceRaces_Toggle()
{
    EQ_ToggleBool(g_ReplaceRacesIsEnabled);
    EQAPP_PrintBool("Replace Races", g_ReplaceRacesIsEnabled);
}

void EQAPP_ReplaceRaces_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_ReplaceRacesTimer, g_ReplaceRacesTimerDelay) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        bool bSpawnIsPet = false;

        if (spawn->PetOwnerSpawnID != 0)
        {
            bSpawnIsPet = true;
        }

        if (spawn->Race == EQ_RACE_INVISIBLE_MAN)
        {
            EQ::ChangeForm changeForm;

            changeForm.SpawnID = spawn->SpawnID;
            changeForm.Race = EQ_RACE_HUMAN;

            if (bSpawnIsPet == true)
            {
                changeForm.Texture = EQ_ARMOR_TEXTURE_TYPE_PLATE;
            }
            else
            {
                changeForm.Texture = 255;
            }

            changeForm.HelmetTexture = 0;
            changeForm.Unknown07 = 255;
            changeForm.Face = 0;
            changeForm.HairType = 255;
            changeForm.HairColor = 255;
            changeForm.BeardType = 255;
            changeForm.BeardColor = 255;
            changeForm.Size = 5;
            changeForm.Unknown10 = -1;

            auto player = (EQClass::EQPlayer*)spawn;

            player->do_change_form(&changeForm);

            if (bSpawnIsPet == true)
            {
                EQ_CLASS_POINTER_CDisplay->UpdateItemSlot(player, EQ_UPDATE_ITEM_SLOT_HEAD, "IT629", true);
            }
        }

        if
        (
            spawn->Race == EQ_RACE_IKSAR_SKELETON  ||
            spawn->Race == EQ_RACE_SKELETON        ||
            spawn->Race == EQ_RACE_SARNAK_SKELETON ||
            spawn->Race == EQ_RACE_IKSAR_SKELETON
        )
        {
            EQ::ChangeForm changeForm;

            changeForm.SpawnID = spawn->SpawnID;
            changeForm.Race = EQ_RACE_HUMAN;
            changeForm.Texture = 255;
            changeForm.HelmetTexture = 0;
            changeForm.Unknown07 = 255;
            changeForm.Face = 0;
            changeForm.HairType = 255;
            changeForm.HairColor = 255;
            changeForm.BeardType = 255;
            changeForm.BeardColor = 255;
            changeForm.Size = 5;
            changeForm.Unknown10 = -1;

            ((EQClass::EQPlayer*)spawn)->do_change_form(&changeForm);
        }

        spawn = spawn->Next;
    }
}

bool EQAPP_ReplaceRaces_HandleEvent_EQPlayer__do_change_form(void* this_ptr, EQ::ChangeForm_ptr changeForm)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL && playerSpawn == (EQ::Spawn_ptr)this_ptr)
    {
        if (changeForm != NULL)
        {
            if (changeForm->Race == EQ_RACE_WOLF || changeForm->Race == EQ_RACE_BEAR)
            {
                return true;
            }
        }
    }

    return false;
}

