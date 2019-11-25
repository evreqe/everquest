#pragma once

uint32_t g_EQAppFixAddressIndex = 0;

void EQAPP_FixAddress(uint32_t& address);
void EQAPP_InitializeAddresses();
bool EQAPP_IsAddressPointerValid(uint32_t addressPointer);
bool EQAPP_InitializeAddressPointers();

void EQAPP_FixAddress(uint32_t& address)
{
    if (address == 0)
    {
        std::stringstream ss;
        ss << __FUNCTION__ << ": address is null at index " << g_EQAppFixAddressIndex;

        MessageBoxA(NULL, ss.str().c_str(), "Error", MB_ICONERROR);

        g_EQAppFixAddressIndex++;

        return;
    }

    uint32_t baseAddress = (uint32_t)GetModuleHandle(NULL);

    address = (address - EQ_BASE_ADDRESS_VALUE) + baseAddress;

    g_EQAppFixAddressIndex++;
}

void EQAPP_InitializeAddresses()
{
    EQ_InitializeAddresses();

    g_EQAppFixAddressIndex = 0;

    EQAPP_FixAddress(EQ_ADDRESS_WindowHWND);

    EQAPP_FixAddress(EQ_ADDRESS_AutoAttack);
    EQAPP_FixAddress(EQ_ADDRESS_AutoFire);
    EQAPP_FixAddress(EQ_ADDRESS_AutoRun);
    EQAPP_FixAddress(EQ_ADDRESS_MouseLook);
    EQAPP_FixAddress(EQ_ADDRESS_NetStatus);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_FlushDxKeyboard);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_FlushDxMouse);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ProcessMouseEvent);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_WindowProc);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CollisionCallbackForActors);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CastRay2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DrawNetStatus);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_ExecuteCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_DoSpellEffect);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_PlaySoundAtLocation);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetTime);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_UpdateLight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ);

    EQAPP_FixAddress(EQ_ADDRESS_EQZoneInfo);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_ControlledSpawn);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_PlayerSpawn);
    EQAPP_FixAddress(EQ_ADDRESS_POINTER_TargetSpawn);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQ_Character);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__StunMe);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQ_PC);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQPlayerManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_EQSwitchManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CXWndManager);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);

    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CEverQuest);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CDisplay);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__CreateActor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__CreateLight);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CRender);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CRenderEx);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CAlertWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CAlertStackWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarSearchWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CBazaarConfirmationWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CMapViewWnd);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CSpellBookWnd);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft);
    EQAPP_FixAddress(EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft);

    EQAPP_FixAddress(EQ_ADDRESS_POINTER_CTaskSelectWnd);
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
        EQ_ADDRESS_POINTER_EQ_Character,
        EQ_ADDRESS_POINTER_EQ_PC,
        EQ_ADDRESS_POINTER_EQPlayerManager,
        EQ_ADDRESS_POINTER_EQSwitchManager,
        EQ_ADDRESS_POINTER_CXWndManager,
        EQ_ADDRESS_POINTER_CEverQuest,
        EQ_ADDRESS_POINTER_CDisplay,
        EQ_ADDRESS_POINTER_CRender,
        EQ_ADDRESS_POINTER_CRenderEx,
        EQ_ADDRESS_POINTER_CAlertWnd,
        EQ_ADDRESS_POINTER_CAlertStackWnd,
        EQ_ADDRESS_POINTER_CBazaarSearchWnd,
        EQ_ADDRESS_POINTER_CBazaarConfirmationWnd,
        EQ_ADDRESS_POINTER_CMapViewWnd,
        EQ_ADDRESS_POINTER_CSpellBookWnd,
        EQ_ADDRESS_POINTER_CTaskSelectWnd,
    };

    for (auto& addressPointer : addressPointerList)
    {
        if (EQAPP_IsAddressPointerValid(addressPointer) == false)
        {
            result = false;
        }
    }

    EQ_VTABLE_IDirect3DDevice9 = *(uintptr_t**)EQ_GetDirect3DDevicePointer();

    EQ_CLASS_POINTER_EQ_Character_pptr = (EQClass::EQ_Character**)EQ_ADDRESS_POINTER_EQ_Character;
    EQ_CLASS_POINTER_EQ_Character = (*EQ_CLASS_POINTER_EQ_Character_pptr);

    EQ_CLASS_POINTER_EQ_PC_pptr = (EQClass::EQ_PC**)EQ_ADDRESS_POINTER_EQ_PC;
    EQ_CLASS_POINTER_EQ_PC = (*EQ_CLASS_POINTER_EQ_PC_pptr);

    EQ_CLASS_POINTER_EQPlayerManager_pptr = (EQClass::EQPlayerManager**)EQ_ADDRESS_POINTER_EQPlayerManager;
    EQ_CLASS_POINTER_EQPlayerManager = (*EQ_CLASS_POINTER_EQPlayerManager_pptr);

    EQ_CLASS_POINTER_EQSwitchManager_pptr = (EQClass::EQSwitchManager**)EQ_ADDRESS_POINTER_EQSwitchManager;
    EQ_CLASS_POINTER_EQSwitchManager = (*EQ_CLASS_POINTER_EQSwitchManager_pptr);

    EQ_CLASS_POINTER_CXWndManager_pptr = (EQClass::CXWndManager**)EQ_ADDRESS_POINTER_CXWndManager;
    EQ_CLASS_POINTER_CXWndManager = (*EQ_CLASS_POINTER_CXWndManager_pptr);

    EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
    EQ_CLASS_POINTER_CEverQuest = (*EQ_CLASS_POINTER_CEverQuest_pptr);

    EQ_CLASS_POINTER_CDisplay_pptr = (EQClass::CDisplay**)EQ_ADDRESS_POINTER_CDisplay;
    EQ_CLASS_POINTER_CDisplay = (*EQ_CLASS_POINTER_CDisplay_pptr);

    EQ_CLASS_POINTER_CRender_pptr = (EQClass::CRender**)EQ_ADDRESS_POINTER_CRender;
    EQ_CLASS_POINTER_CRender = (*EQ_CLASS_POINTER_CRender_pptr);

    EQ_CLASS_POINTER_CRenderEx_pptr = (EQClass::CRenderEx**)EQ_ADDRESS_POINTER_CRenderEx;
    EQ_CLASS_POINTER_CRenderEx = (*EQ_CLASS_POINTER_CRenderEx_pptr);

    EQ_CLASS_POINTER_CAlertWnd_pptr = (EQClass::CAlertWnd**)EQ_ADDRESS_POINTER_CAlertWnd;
    EQ_CLASS_POINTER_CAlertWnd = (*EQ_CLASS_POINTER_CAlertWnd_pptr);

    EQ_CLASS_POINTER_CAlertStackWnd_pptr = (EQClass::CAlertStackWnd**)EQ_ADDRESS_POINTER_CAlertStackWnd;
    EQ_CLASS_POINTER_CAlertStackWnd = (*EQ_CLASS_POINTER_CAlertStackWnd_pptr);

    EQ_CLASS_POINTER_CBazaarSearchWnd_pptr = (EQClass::CBazaarSearchWnd**)EQ_ADDRESS_POINTER_CBazaarSearchWnd;
    EQ_CLASS_POINTER_CBazaarSearchWnd = (*EQ_CLASS_POINTER_CBazaarSearchWnd_pptr);

    EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr = (EQClass::CBazaarConfirmationWnd**)EQ_ADDRESS_POINTER_CBazaarConfirmationWnd;
    EQ_CLASS_POINTER_CBazaarConfirmationWnd = (*EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr);

    EQ_CLASS_POINTER_CMapViewWnd_pptr = (EQClass::CMapViewWnd**)EQ_ADDRESS_POINTER_CMapViewWnd;
    EQ_CLASS_POINTER_CMapViewWnd = (*EQ_CLASS_POINTER_CMapViewWnd_pptr);

    EQ_CLASS_POINTER_CSpellBookWnd_pptr = (EQClass::CSpellBookWnd**)EQ_ADDRESS_POINTER_CSpellBookWnd;
    EQ_CLASS_POINTER_CSpellBookWnd = (*EQ_CLASS_POINTER_CSpellBookWnd_pptr);

    EQ_CLASS_POINTER_CTaskSelectWnd_pptr = (EQClass::CTaskSelectWnd**)EQ_ADDRESS_POINTER_CTaskSelectWnd;
    EQ_CLASS_POINTER_CTaskSelectWnd = (*EQ_CLASS_POINTER_CTaskSelectWnd_pptr);

    return result;
}
