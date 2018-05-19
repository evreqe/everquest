#pragma once

void EQAPP_FixAddress(uint32_t& address);
void EQAPP_InitializeAddressesAndPointers();

void EQAPP_FixAddress(uint32_t& address)
{
    if (address == 0)
    {
        return;
    }

    uint32_t baseAddress = (uint32_t)GetModuleHandle(NULL);

    address = (address - EQ_BASE_ADDRESS_VALUE) + baseAddress;
}

void EQAPP_InitializeAddressesAndPointers()
{
    EQAPP_FixAddress(EQ_ADDRESS_AutoAttack);
    EQAPP_FixAddress(EQ_ADDRESS_AutoFire);
    EQAPP_FixAddress(EQ_ADDRESS_AutoRun);
    EQAPP_FixAddress(EQ_ADDRESS_MouseLook);
    EQAPP_FixAddress(EQ_ADDRESS_NetStatus);

    EQAPP_FixAddress(EQ_ADDRESS_FogEnabled);
    EQAPP_FixAddress(EQ_ADDRESS_FogDistanceBegin);
    EQAPP_FixAddress(EQ_ADDRESS_FogDistanceEnd);
    EQAPP_FixAddress(EQ_ADDRESS_FarClipPlane);

    EQAPP_FixAddress(EQ_ADDRESS_WindowHWND);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_StringTable);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_StringTable__getString);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CrashDetected);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetExecuteCmdIDByName);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetExecuteCmdNameByID);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TargetSpawn);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerSpawn);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQSwitchManager);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

    //EQSwitch

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CRender);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    if (EQ_ADDRESS_POINTER_EQPlayerManager != 0)
    {
        EQ_CLASS_POINTER_EQPlayerManager_pptr = (EQClass::EQPlayerManager**)EQ_ADDRESS_POINTER_EQPlayerManager;
        EQ_CLASS_POINTER_EQPlayerManager = (*EQ_CLASS_POINTER_EQPlayerManager_pptr);
    }

    if (EQ_ADDRESS_POINTER_CXWndManager != 0)
    {
        EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
        EQ_CLASS_POINTER_CXWndManager = (*EQ_CLASS_POINTER_CXWndManager_pptr);
    }

    if (EQ_ADDRESS_POINTER_CEverQuest != 0)
    {
        EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
        EQ_CLASS_POINTER_CEverQuest = (*EQ_CLASS_POINTER_CEverQuest_pptr);
    }

    if (EQ_ADDRESS_POINTER_CDisplay != 0)
    {
        EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
        EQ_CLASS_POINTER_CDisplay = (*EQ_CLASS_POINTER_CDisplay_pptr);
    }

    if (EQ_ADDRESS_POINTER_CRender != 0)
    {
        EQ_CLASS_POINTER_CRender_pptr = (EQClass::CRender**)EQ_ADDRESS_POINTER_CRender;
        EQ_CLASS_POINTER_CRender = (*EQ_CLASS_POINTER_CRender_pptr);
    }
}
