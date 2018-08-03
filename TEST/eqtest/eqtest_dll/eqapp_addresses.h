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

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_WindowProc);

    EQAPP_FixAddress(EQ_ADDRESS_AutoAttack);
    EQAPP_FixAddress(EQ_ADDRESS_AutoFire);
    EQAPP_FixAddress(EQ_ADDRESS_AutoRun);
    EQAPP_FixAddress(EQ_ADDRESS_MouseLook);
    EQAPP_FixAddress(EQ_ADDRESS_NetStatus);

    EQAPP_FixAddress(EQ_ADDRESS_CameraType);

    EQAPP_FixAddress(EQ_ADDRESS_LeftMouseHeldTime);
    EQAPP_FixAddress(EQ_ADDRESS_RightMouseHeldTime);

    EQAPP_FixAddress(EQ_ADDRESS_GroupAggro);

    EQAPP_FixAddress(EQ_ADDRESS_EQZoneInfo);

    EQAPP_FixAddress(EQ_ADDRESS_FogEnabled);
    EQAPP_FixAddress(EQ_ADDRESS_FogDistanceBegin);
    EQAPP_FixAddress(EQ_ADDRESS_FogDistanceEnd);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CrashDetected);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CollisionCallbackForActors);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_StringTable);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_StringTable__getString);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TargetIndicator);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerPath);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerCharacter);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerSpawn);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TargetSpawn);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQSwitchManager);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_AuraManager);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_SpellManager);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CRender);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__CXStr);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__CXStr1);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__CXStr3);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__dCXStr);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__operator_equal);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__operator_equal1);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal1);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__BringToTop);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__IsActive);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarWnd);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CTaskSelectWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CLargeDialogWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CLargeDialogWnd__Open);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CPlayerWnd);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CTargetWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CPetInfoWindow);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBuffWnd_Long);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBuffWnd_Short);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CCastSpellWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CCastingWnd);
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
    std::vector<uint32_t> addressPointerList =
    {
        EQ_ADDRESS_POINTER_EQPlayerManager,
        EQ_ADDRESS_POINTER_CXWndManager,
        EQ_ADDRESS_POINTER_CEverQuest,
        EQ_ADDRESS_POINTER_CDisplay,
        EQ_ADDRESS_POINTER_CRender,
        EQ_ADDRESS_POINTER_CBazaarWnd,
        EQ_ADDRESS_POINTER_CBazaarConfirmationWnd,
        EQ_ADDRESS_POINTER_CBazaarSearchWnd,
        EQ_ADDRESS_POINTER_CTaskSelectWnd,
        EQ_ADDRESS_POINTER_CLargeDialogWnd,
    };

    for (auto& addressPointer : addressPointerList)
    {
        if (EQAPP_IsAddressPointerValid(addressPointer) == false)
        {
            return false;
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

    EQ_CLASS_POINTER_CBazaarWnd_pptr = (EQClass::CBazaarWnd**)EQ_ADDRESS_POINTER_CBazaarWnd;
    EQ_CLASS_POINTER_CBazaarWnd = (*EQ_CLASS_POINTER_CBazaarWnd_pptr);

    EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr = (EQClass::CBazaarConfirmationWnd**)EQ_ADDRESS_POINTER_CBazaarConfirmationWnd;
    EQ_CLASS_POINTER_CBazaarConfirmationWnd = (*EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr);

    EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
    EQ_CLASS_POINTER_CBazaarSearchWnd = (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr);

    EQ_CLASS_POINTER_CTaskSelectWnd_pptr = (EQClass::CTaskSelectWnd**)EQ_ADDRESS_POINTER_CTaskSelectWnd;
    EQ_CLASS_POINTER_CTaskSelectWnd = (*EQ_CLASS_POINTER_CTaskSelectWnd_pptr);

    EQ_CLASS_POINTER_CLargeDialogWnd_pptr = (EQClass::CLargeDialogWnd**)EQ_ADDRESS_POINTER_CLargeDialogWnd;
    EQ_CLASS_POINTER_CLargeDialogWnd = (*EQ_CLASS_POINTER_CLargeDialogWnd_pptr);

    return true;
}
