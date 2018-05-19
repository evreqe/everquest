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
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_ATTACK);
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_FIRE);
    EQAPP_FixAddress(EQ_ADDRESS_AUTO_RUN);
    EQAPP_FixAddress(EQ_ADDRESS_MOUSE_LOOK);
    EQAPP_FixAddress(EQ_ADDRESS_NET_STATUS);

    EQAPP_FixAddress(EQ_ADDRESS_FOG_DISTANCE_BEGIN);
    EQAPP_FixAddress(EQ_ADDRESS_FOG_DISTANCE_END);
    EQAPP_FixAddress(EQ_ADDRESS_FAR_CLIP_PLANE);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_WINDOW_HWND);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_StringTable);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_StringTable__getString);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_build_token_string_PARAM);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CrashDetected);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetExecuteCmdIDByName);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetExecuteCmdNameByID);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TARGET_SPAWN);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PLAYER_SPAWN);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CPlayerWindow);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CTaskSelectWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarWnd);

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

    if (EQ_ADDRESS_POINTER_CTaskSelectWnd != 0)
    {
        EQ_CLASS_POINTER_CTaskSelectWnd_pptr = (EQClass::CTaskSelectWnd**)EQ_ADDRESS_POINTER_CTaskSelectWnd;
        EQ_CLASS_POINTER_CTaskSelectWnd = (*EQ_CLASS_POINTER_CTaskSelectWnd_pptr);
    }

    if (EQ_ADDRESS_POINTER_CBazaarSearchWnd != 0)
    {
        EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
        EQ_CLASS_POINTER_CBazaarSearchWnd = (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr);
    }

    if (EQ_ADDRESS_POINTER_CBazaarConfirmationWnd != 0)
    {
        EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr = (EQClass::CBazaarConfirmationWnd**)EQ_ADDRESS_POINTER_CBazaarConfirmationWnd;
        EQ_CLASS_POINTER_CBazaarConfirmationWnd = (*EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr);
    }

    if (EQ_ADDRESS_POINTER_CBazaarWnd != 0)
    {
        EQ_CLASS_POINTER_CBazaarWnd_pptr = (EQClass::CBazaarWnd**)EQ_ADDRESS_POINTER_CBazaarWnd;
        EQ_CLASS_POINTER_CBazaarWnd = (*EQ_CLASS_POINTER_CBazaarWnd_pptr);
    }

    if (EQ_ADDRESS_POINTER_CRender != 0)
    {
        EQ_CLASS_POINTER_CRender_pptr = (EQClass::CRender**)EQ_ADDRESS_POINTER_CRender;
        EQ_CLASS_POINTER_CRender = (*EQ_CLASS_POINTER_CRender_pptr);
    }
}
