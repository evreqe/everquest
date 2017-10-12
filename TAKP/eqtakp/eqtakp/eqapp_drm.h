#pragma once

bool g_DRMIsEnabled = true;

uint32_t g_DRMTimer = 0;
uint32_t g_DRMTimerDelay = 3000;

void EQAPP_DRM_Execute();

void EQAPP_DRM_Execute()
{
    if (EQ_HasTimePassed(g_DRMTimer, g_DRMTimerDelay) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    bool bUseDRM = false;

    std::string guildName = EQ_GetGuildNameByID(playerSpawn->GuildID);
    if (guildName == "Destiny" || guildName == "Imperium" || guildName == "Temerity")
    {
        bUseDRM = true;
    }

    if (bUseDRM == false)
    {
        return;
    }

    auto rootBone = playerSpawn->Actor->Model->RootBone;
    if (rootBone != NULL)
    {
        EQ_CLASS_POINTER_CDisplay->SpurtBloodOnDag(rootBone);
    }

    auto player = (EQClass::EQPlayer*)playerSpawn;

    // lollipops
    EQ_CLASS_POINTER_CDisplay->UpdateItemSlot(player, EQ_UPDATE_ITEM_SLOT_HEAD, "IT250", true);
    EQ_CLASS_POINTER_CDisplay->UpdateItemSlot(player, EQ_UPDATE_ITEM_SLOT_PRIMARY, "IT250", true);
    EQ_CLASS_POINTER_CDisplay->UpdateItemSlot(player, EQ_UPDATE_ITEM_SLOT_SECONDARY, "IT250", true);
}

