#pragma once

EQ_OFFSET_EQ_Character____ExtendedTargetList    = 0x2838;
EQ_OFFSET_EQ_Character____GroupInfo             = EQ_OFFSET_EQ_Character____ExtendedTargetList + 0x14;

EQ_OFFSET_CMapViewMap__Lines     = 0x258;
EQ_OFFSET_CMapViewMap__Labels    = 0x25C;    // = EQ_OFFSET_CMapViewMap__Lines + 0x04;

// Dec 14 2020 10:19:52

EQ_SIZE_CXWnd = 0x1E0;
EQ_SIZE_CSidlScreenWnd = 0x228;

EQ_OFFSET_SPAWN_STANDING_STATE             = 0x4f5;
EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf30;
EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x608;
EQ_OFFSET_SPAWN_HP_MAX                     = 0x1a8;
EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x2e4;
EQ_OFFSET_SPAWN_MANA_MAX                   = 0x530;
EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x328;
EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x534;
EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x350;
EQ_OFFSET_EQ_Character____CharacterBase    = 0x28ac;
EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;
EQ_OFFSET_CMapViewWnd__CMapViewMap         = 0x360;

EQ_ADDRESS_WindowHWND = 0x00F4E100;

EQ_ADDRESS_AutoAttack              = 0x00F4572F;
EQ_ADDRESS_AutoFire                = 0x00F45730;
EQ_ADDRESS_AutoRun                 = 0x00EA6A80;
EQ_ADDRESS_MouseLook               = 0x00EA6A62;
EQ_ADDRESS_NetStatus               = 0x00EA6A65;

EQ_ADDRESS_LeftMouseHeldTime       = 0x00EA6B08;

EQ_ADDRESS_EQZoneInfo = 0x00EA6C58;

EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E9FC8C;
EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E9F824;
EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E9FC88;

EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = 0x006B1320;
EQ_ADDRESS_FUNCTION_FlushDxMouse                  = 0x006B0FA0;
EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = 0x006B2EB0;
EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = 0x006257B0;
EQ_ADDRESS_FUNCTION_WindowProc                    = 0x006B3910;
EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x005322E0;
EQ_ADDRESS_FUNCTION_CastRay                       = 0x005C5510;
EQ_ADDRESS_FUNCTION_CastRay2                      = 0x005C5560;
EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006522B0;
EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005BDEA0;
EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x006246A0;
EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x00552660;
EQ_ADDRESS_FUNCTION_GetTime                       = 0x008F7C20;
EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x008236C0;
EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x0080B670;

EQ_ADDRESS_POINTER_StringTable = 0x00E9F74C;
EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B8BD0;

EQ_ADDRESS_POINTER_CDBStr = 0x00DECC0C;
EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00547F40;

EQ_ADDRESS_POINTER_EQ_Character = 0x00E9F744;
EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D4810;
EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004DC730;
EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004E1580;
EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004E23F0;
EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D6F20;
EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D7040;
EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004E2290;

EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004BFC20;
EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C6AE0;

EQ_ADDRESS_POINTER_EQ_PC = 0x00E9F744;
EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x00660F80;

EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F48910;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0067B0E0;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0067B190;

EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x00683520;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00683F50;
EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x00685AC0;
EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005BBF60;
EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x0066EBB0;
EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x0066EED0;
EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x00674C70;
EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0098C130;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x0066FF80;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00670E60;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x006773E0;
EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005F13D0;
EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = 0x00684800;

EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E9F258;
EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005F5E70;
EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005F6350;

EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004BF5B0;

EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p    = 0x008F3F70;

EQ_ADDRESS_POINTER_CXWndManager = 0x015DC304;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor     = 0x009295A0;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x009295C0;

EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00925510;
EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem       = 0x00926810;

EQ_ADDRESS_POINTER_CEverQuest = 0x0F4B19C;
EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x00613620;
EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x0060DF80;
EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x00621FB0;
EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004EA150;
EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005FA6B0;
EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005FCE40;
EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005FDDC0;
EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005FE4A0;
EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x00607EF0;
EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x00608D30;
EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005FA920;
EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = 0x005FF390;

EQ_ADDRESS_POINTER_CDisplay = 0x00E9FCA4;
EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x0054D360;
EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00550460;
EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x0054BFD0;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x005503D0;
EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x0054D2D0;
EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00550AB0;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x00550A80;

//EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRender = 0x015DD140;
//EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRenderEx = EQ_ADDRESS_POINTER_CRender + 0x04;

EQ_ADDRESS_POINTER_CAlertWnd = 0x0DED4FC;

EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0DED4E8;

EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00DECF48;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006E5BE0;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006E69B0;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006E6480;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem = 0x006E9090;

EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00DED498;

EQ_ADDRESS_POINTER_CMapViewWnd = 0x00DED458;

EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DED474;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x00802CF0;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x00802E50;

EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0F60DA8;
