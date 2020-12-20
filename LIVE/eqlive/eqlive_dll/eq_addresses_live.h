#pragma once

EQ_OFFSET_EQ_Character____ExtendedTargetList    = 0x2838;
EQ_OFFSET_EQ_Character____GroupInfo             = EQ_OFFSET_EQ_Character____ExtendedTargetList + 0x14;

EQ_OFFSET_CMapViewMap__Lines     = 0x260;
EQ_OFFSET_CMapViewMap__Labels    = 0x264;    // = EQ_OFFSET_CMapViewMap__Lines + 0x04;

// Dec  5 2020 00:41:50

EQ_SIZE_CXWnd = 0x1E8;
EQ_SIZE_CSidlScreenWnd = 0x230;

EQ_OFFSET_SPAWN_STANDING_STATE             = 0x1a4;
EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf34;
EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x1f8;
EQ_OFFSET_SPAWN_HP_MAX                     = 0x1d0;
EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x334;
EQ_OFFSET_SPAWN_MANA_MAX                   = 0x284;
EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x5ec;
EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x3f0;
EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x1c8;
EQ_OFFSET_EQ_Character____CharacterBase    = 0x28ac;
EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;
EQ_OFFSET_CMapViewWnd__CMapViewMap         = 0x368;

EQ_ADDRESS_WindowHWND = 0x00F4D100;

EQ_ADDRESS_AutoAttack              = 0x00F4472F;
EQ_ADDRESS_AutoFire                = 0x00F44730;
EQ_ADDRESS_AutoRun                 = 0x00EA5A80;
EQ_ADDRESS_MouseLook               = 0x00EA5A62;
EQ_ADDRESS_NetStatus               = 0x00EA5A65;

EQ_ADDRESS_LeftMouseHeldTime       = 0x00EA5B08;

EQ_ADDRESS_EQZoneInfo = 0x00EA5C58;

EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E9EC8C;
EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E9E824;
EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E9EC88;

EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = 0x006B0CA0;
EQ_ADDRESS_FUNCTION_FlushDxMouse                  = 0x006B0920;
EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = 0x006B2830;
EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = 0x00624E20;
EQ_ADDRESS_FUNCTION_WindowProc                    = 0x006B3290;
EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x00532010;
EQ_ADDRESS_FUNCTION_CastRay                       = 0x005C4B30;
EQ_ADDRESS_FUNCTION_CastRay2                      = 0x005C4B80;
EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00651970;
EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005BD4A0;
EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x00623D10;
EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x00552290;
EQ_ADDRESS_FUNCTION_GetTime                       = 0x008F7610;
EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x00823260;
EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x0080B240;

EQ_ADDRESS_POINTER_StringTable = 0x00E9E74C;
EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B84D0;

EQ_ADDRESS_POINTER_CDBStr = 0x00DEBC0C;
EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00547B60;

EQ_ADDRESS_POINTER_EQ_Character = 0x00E9E744;
EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D4980;
EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004DC8B0;
EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004E1700;
EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004E2580;
EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D7090;
EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D71B0;
EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004E2420;

EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004BFCF0;
EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C6BB0;

EQ_ADDRESS_POINTER_EQ_PC = 0x00E9E744;
EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x00660620;

EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F47910;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0067A740;
EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0067A7F0;

EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x00682BB0;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x006835E0;
EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x00685160;
EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005BB4F0;
EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x0066E2A0;
EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x0066E5C0;
EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x00674360;
EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0098B200;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x0066F670;
EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00670550;
EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x00676AD0;
EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005F0A70;
EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = 0x00683E90;

EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E9E258;
EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005F54B0;
EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005F5990;

EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004BF680;

EQ_ADDRESS_FUNCTION_CXStr__CXStr_const_char_p    = 0x008F39A0;

EQ_ADDRESS_POINTER_CXWndManager = 0x015DB304;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor     = 0x009284A0;
EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x009284C0;

EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00924510;
EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem       = 0x009257C0;

EQ_ADDRESS_POINTER_CEverQuest = 0x0F4A19C;
EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x00612C90;
EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x0060D5F0;
EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x00621620;
EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004EA160;
EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005F9D10;
EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005FC4A0;
EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005FD430;
EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005FDB10;
EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x00607560;
EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x006083A0;
EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005F9F80;
EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = 0x005FEA00;

EQ_ADDRESS_POINTER_CDisplay = 0x00E9ECA4;
EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x0054CF90;
EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00550090;
EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x0054BC00;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00550000;
EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x0054CF00;
EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x005506E0;
EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x005506B0;

//EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRender = 0x015DC140;
//EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
//EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

EQ_ADDRESS_POINTER_CRenderEx = EQ_ADDRESS_POINTER_CRender + 0x04;

EQ_ADDRESS_POINTER_CAlertWnd = 0x0DEC4FC;

EQ_ADDRESS_POINTER_CAlertStackWnd = 0x0DEC4E8;

EQ_ADDRESS_POINTER_CBazaarSearchWnd = 0x00DEBF48;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = 0x006E5100;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = 0x006E5EC0;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = 0x006E5990;
EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__FindItem = 0x006E85A0;

EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = 0x00DEC498;

EQ_ADDRESS_POINTER_CMapViewWnd = 0x00DEC458;

EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DEC474;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x00802950;
EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x00802AB0;

EQ_ADDRESS_POINTER_CTaskSelectWnd = 0x0F5FDA8;
