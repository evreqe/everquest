#pragma once

bool g_replaceRacesIsEnabled = true;

uint32_t g_replaceRacesTimer = 0;
uint32_t g_replaceRacesTimerDelay = 3000;

void EQAPP_ReplaceRaces_Toggle();
void EQAPP_ReplaceRaces_Execute();
bool EQAPP_ReplaceRaces_HandleEvent_EQPlayer__do_change_form(void* this_ptr, EQ::ChangeForm_ptr changeForm);

void EQAPP_ReplaceRaces_Toggle()
{
    EQ_ToggleBool(g_replaceRacesIsEnabled);
    EQAPP_PrintBool("Replace Races", g_replaceRacesIsEnabled);
}

void EQAPP_ReplaceRaces_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (EQ_HasTimePassed(g_replaceRacesTimer, g_replaceRacesTimerDelay) == false)
    {
        return;
    }

    auto spawn = EQ_GetFirstSpawn();
    while (spawn != NULL)
    {
        if
        (
            spawn->Race == EQ_RACE_INVISIBLE_MAN   ||
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

