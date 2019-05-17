#pragma once

void EQAPP_FixAddress(uint32_t& address);
void EQAPP_InitializeAddresses();
bool EQAPP_IsAddressPointerValid(uint32_t addressPointer);
bool EQAPP_InitializeAddressPointers();

void EQAPP_FixAddress(uint32_t& address)
{
    if (address == 0)
    {
        std::stringstream ss;
        ss << __FUNCTION__ << ": address is null";

        MessageBoxA(NULL, ss.str().c_str(), "Error", MB_ICONERROR);
        return;
    }

    uint32_t baseAddress = (uint32_t)GetModuleHandle(NULL);

    address = (address - EQ_BASE_ADDRESS_VALUE) + baseAddress;
}

void EQAPP_InitializeAddresses()
{
    EQ_InitializeAddresses();

    EQAPP_FixAddress(EQ_ADDRESS_WindowHWND);

    EQAPP_FixAddress(EQ_ADDRESS_AutoAttack);
    EQAPP_FixAddress(EQ_ADDRESS_AutoRun);
    EQAPP_FixAddress(EQ_ADDRESS_MouseLook);
    EQAPP_FixAddress(EQ_ADDRESS_NetStatus);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CollisionCallbackForActors);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerSpawn);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TargetSpawn);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CRender);
}

bool EQAPP_IsAddressPointerValid(uint32_t addressPointer)
{
    if (addressPointer == 0)
    {
        return false;
    }

    auto value = EQ_ReadMemory<uint32_t>(addressPointer);
    if (value == 0)
    {
        return false;
    }

    return true;
}

bool EQAPP_InitializeAddressPointers()
{
    bool result = true;

    std::vector<uint32_t> addressPointerList =
    {
        EQ_ADDRESS_POINTER_EQPlayerManager,
        EQ_ADDRESS_POINTER_CXWndManager,
        EQ_ADDRESS_POINTER_CEverQuest,
        EQ_ADDRESS_POINTER_CDisplay,
        EQ_ADDRESS_POINTER_CRender,
    };

    for (auto& addressPointer : addressPointerList)
    {
        if (EQAPP_IsAddressPointerValid(addressPointer) == false)
        {
            result = false;
        }
    }

    EQ_CLASS_POINTER_EQPlayerManager_pptr = (EQClass::EQPlayerManager**)EQ_ADDRESS_POINTER_EQPlayerManager;
    EQ_CLASS_POINTER_EQPlayerManager = (*EQ_CLASS_POINTER_EQPlayerManager_pptr);

    EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
    EQ_CLASS_POINTER_CXWndManager = (*EQ_CLASS_POINTER_CXWndManager_pptr);

    EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
    EQ_CLASS_POINTER_CEverQuest = (*EQ_CLASS_POINTER_CEverQuest_pptr);

    EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
    EQ_CLASS_POINTER_CDisplay = (*EQ_CLASS_POINTER_CDisplay_pptr);

    EQ_CLASS_POINTER_CRender_pptr = (EQClass::CRender**)EQ_ADDRESS_POINTER_CRender;
    EQ_CLASS_POINTER_CRender = (*EQ_CLASS_POINTER_CRender_pptr);

    return result;
}
