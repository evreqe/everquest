#pragma once

EQ_OFFSET_EQ_Character____ExtendedTargetList    = 0x2868;
EQ_OFFSET_EQ_Character____GroupInfo             = EQ_OFFSET_EQ_Character____ExtendedTargetList + 0x14;

EQ_OFFSET_CMapViewMap__Lines     = 0x250;
EQ_OFFSET_CMapViewMap__Labels    = 0x254;    // = EQ_OFFSET_CMapViewMap__Lines + 0x04;

// Jan 12 2021 12:07:13

EQ_SIZE_CXWnd = 0x1D8;
EQ_SIZE_CSidlScreenWnd = 0x220;

EQ_OFFSET_SPAWN_STANDING_STATE             = 0x4ec;
EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf28;
EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x5c8;
EQ_OFFSET_SPAWN_HP_MAX                     = 0x298;
EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x60c;
EQ_OFFSET_SPAWN_MANA_MAX                   = 0x418;
EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x28c;
EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x3e4;
EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x594;
EQ_OFFSET_EQ_Character____CharacterBase    = 0x28ac;
EQ_OFFSET_CharInfo2__Bandolier             = 0x742c;
EQ_OFFSET_CMapViewWnd__CMapViewMap         = 0x358;

EQ_ADDRESS_WindowHWND = 0x00F3E8B8;

EQ_ADDRESS_AutoAttack              = 0x00F361FF;
EQ_ADDRESS_AutoFire                = 0x00F36200;
EQ_ADDRESS_AutoRun                 = 0x00E97550;
EQ_ADDRESS_MouseLook               = 0x00E97532;
EQ_ADDRESS_NetStatus               = 0x00E97535;

EQ_ADDRESS_LeftMouseHeldTime       = 0x00E975D8;

EQ_ADDRESS_EQZoneInfo = 0x00E97728;

EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E9075C;
EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E90704;
EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E90758;

EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = 0x006ABF00;
EQ_ADDRESS_FUNCTION_FlushDxMouse                  = 0x006ABB80;
EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = 0x006ADA90;
EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = 0x00622590;
EQ_ADDRESS_FUNCTION_WindowProc                    = 0x006AE4F0;
EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x00530270;
EQ_ADDRESS_FUNCTION_CastRay                       = 0x005C2340;
EQ_ADDRESS_FUNCTION_CastRay2                      = 0x005C2390;
EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x0064E420;
EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005BACF0;
EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x00621480;
EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x005505E0;
EQ_ADDRESS_FUNCTION_GetTime                       = 0x008EDFA0;
EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x0081C500;
EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x008045C0;

EQ_ADDRESS_POINTER_StringTable = 0x00E901B0;
EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008AF020;

EQ_ADDRESS_POINTER_CDBStr = 0x00DDD6DC;
EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00545EA0;

EQ_ADDRESS_POINTER_EQ_Character = 0x00E901A8;
EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D2610;
EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004DA540;
EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DF390;
EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004E0210;
EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D4D10;
EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D4E30;
EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004E00B0;

EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004BD960;
EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C4820;

EQ_ADDRESS_POINTER_EQ_PC = 0x00E901A8;
EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x0065D2A0;

EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F39320;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x006774A0;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x00677550;

EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight            = 0x0067F880;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition          = 0x006802B0;
EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel                = 0x00681E30;
EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient          = 0x005B8DF0;
EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI          = 0x0066B040;
EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow       = 0x0066B360;
EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot          = 0x006710E0;
EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable            = 0x00981770;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState      = 0x0066C3F0;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint       = 0x0066D2D0;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight             = 0x00673850;
EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading      = 0x005EE180;
EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack         = 0x00680B60;
EQ_ADDRESS_FUNCTION_EQPlayer__RightClickedOnPlayer    = 0x005FC090;

EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E8FD28;
EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005F2B60;
EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005F3040;

EQ_ADDRESS_POINTER_EQSpellManager = 0x00F3AAB8;
EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004BD300;

EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p    = 0x008EA2F0;

EQ_ADDRESS_POINTER_CXWndManager = 0x015CC87C;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor     = 0x0091F1A0;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091F1C0;

EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x0091B230;
EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem       = 0x0091C490;

EQ_ADDRESS_POINTER_CEverQuest = 0x0F3B950;
EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x00610300;
EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x0060AC80;
EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x0061ED90;
EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E7FB0;
EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005F73A0;
EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005F9B30;
EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005FAAC0;
EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005FB1A0;
EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x00604BF0;
EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x00605A30;
EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005F7610;

EQ_ADDRESS_POINTER_CDisplay = 0x00E90780;
EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x0054B2E0;
EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x0054E3E0;
EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00549F50;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x0054E350;
EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x0054B250;
EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x0054EA30;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x0054EA00;

//EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRender = 0x015CD6B8;
//EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRenderEx = EQ_ADDRESS_POINTER_CRender + 0x04;

EQ_ADDRESS_POINTER_CAlertWnd = 0x0DDDF34;

EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0DDDF10;

EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00DDD99C;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006E02E0;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006E10B0;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006E0B80;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem = 0x006E3790;

EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00DDDEE8;

EQ_ADDRESS_POINTER_CMapViewWnd = 0x00DDDEB4;

EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DDDEC4;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007FBD30;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007FBE90;

EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0F51520;
