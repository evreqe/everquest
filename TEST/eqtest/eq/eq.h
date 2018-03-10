#pragma once

#include <cstdint>

#include <unordered_map>
#include <string>

#include "eq_constants.h"
#include "eq_alternateabilities.h"
#include "eq_virtualkeycodes.h"
#include "eq_executecmd.h"
#include "eq_keys.h"

uint32_t EQ_ADDRESS_CLIENT_VERSION_DATE = 0xADBC88; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_DATE "Mar  9 2018"
#define EQ_SIZE_CLIENT_VERSION_DATE 12

uint32_t EQ_ADDRESS_CLIENT_VERSION_TIME = 0xADBC7C; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_TIME "14:46:10"
#define EQ_SIZE_CLIENT_VERSION_TIME 9

uint32_t EQ_BASE_ADDRESS_VALUE    = 0x400000;

uint32_t EQ_ADDRESS_AUTO_ATTACK    = 0xFBD537; // uint8_t    // Attack
uint32_t EQ_ADDRESS_AUTO_FIRE      = 0x0; // uint8_t    // Autofire
uint32_t EQ_ADDRESS_AUTO_RUN       = 0xF35C70; // uint32_t
uint32_t EQ_ADDRESS_MOUSE_LOOK     = 0xF35C52; // uint8_t    // MouseLook
uint32_t EQ_ADDRESS_NET_STATUS     = 0xF35C55; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_POINTER_WINDOW_HWND = 0xFBFF48; // HWND hWnd    // HWnd
/*
    PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/
/*
    _snprintf(v11, v10, "%s %s", &Dest, &v14);
    PostMessageA(hWnd, 0x4646u, 0x4246u, (LPARAM)v11);
*/

uint32_t EQ_ADDRESS_POINTER_StringTable    = 0xF26798; // pinstStringTable

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x964D20; // "%s (%d)"    "ERROR: String not found."

uint32_t EQ_ADDRESS_FUNCTION_CrashDetected    = 0x73FEE0; // "Crash (char = %s, zone = %s)\n"    "Local Player's World location at time of crash: %f, %f, %f.\n"    "Gamestate at crash = %d\n"    "Crash Details: %s\n"
/*
  sub_8A4150("Fatal error occurred in mainthread! (Release Client #630)\n");
  strcat(byte_FBC576, "Fatal error in mainthread! (Release Client #630)\n");
  sub_8A4150("Client Version: %s %s", "Jan 22 2018", "10:35:37");
  sprintf(v26, "Client Version: %s %s\n", "Jan 22 2018", "10:35:37");
*/
/*
  if ( DialogBoxParamA(0, (LPCSTR)0x6F, hWndParent, sub_63F5F0, 0) )
  {
    if ( &byte_F24CEC[strlen(byte_F24CEC) + 1] != &byte_F24CEC[1] )
    {
      byte_F24EEB = 0;
      sub_8A4B70(v26, 0x200u, "Crash Details: %s\n", (unsigned int)byte_F24CEC);
      sub_8A4150(v26);
      strcat(byte_FBC576, v26);
      v16 = 0;
      v17 = strlen(v26);
      if ( v17 > 0 )
      {
        do
        {
          if ( v16 >= 0x1FF )
            break;
          v18 = v26[v16++];
        }
        while ( (signed int)v16 < v17 );
      }
    }
  }
  v19 = lpFileName;
  strcat(byte_FBC576, (const char *)off_C69A98);
  v20 = CreateFileA(v19, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  v21 = v20;
  if ( v20 != (HANDLE)-1 )
  {
    NumberOfBytesRead = 0;
    ReadFile(v20, byte_FC4280, 0x100000u, &NumberOfBytesRead, 0);
    CloseHandle(v21);
    if ( NumberOfBytesRead )
    {
      byte_FC4280[NumberOfBytesRead] = 0;
      v22 = 31999 - strlen(byte_FBC576);
      if ( v22 > 0 )
        strcat(byte_FBC576, &byte_FC4280[(signed int)(NumberOfBytesRead - v22) < 0 ? 0 : NumberOfBytesRead - v22]);
    }
  }
*/

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x6B9860; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x6243B0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
/*
ExecuteCmd()
case 508:
        sub_8A22E0("ExecuteCmd has received a CMD_EXITGAME.\n", v168);
        byte_F2FB27 = 1;
        return 1;
*/
/*
sub_8A55C0(
      "*** DISCONNECTING: HitBySpell() is throwing a CMD_EXITGAME at %s:%lu\n",
      (unsigned int)"c:\\p4\\EverQuest\\test\\Common\\CharacterMagicSystem.cpp");
    sub_523550(508, 0, 0, 0); // ExecuteCmd
*/

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager    = 0xFBEBC0; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x6E27A0; // "Your inventory is full!"
/*
case 0xD:
      result = (_DWORD *)sub_5E2420((void *)dword_FB5090, *(_DWORD *)(a3 + 4)); // EQPlayerManager__GetSpawnByID and pinstSpawnManager
      if ( result )
      {
        if ( dword_F21FD4 )
        {
          result[151] = *(_BYTE *)(a3 + 72);
          if ( result == (_DWORD *)dword_F22004 )
          {
            if ( dword_10C2E68 )
            {
              dword_F22004 = 0;
              (*(void (__stdcall **)(_DWORD, signed int, signed int))(*(_DWORD *)dword_10C2E68 + 216))(0, 1, 1);
LABEL_53:
              dword_FB3A64 = 0;
              result = (_DWORD *)sub_645500();
            }
          }
        }
      }
      return result;
    case 0x16:
      if ( dword_10C2F58 )
      {
        v26 = 0;
        v35 = 3;
        sub_89F500("Your inventory is full!");
        v23 = (void *)sub_89F8E0(&v26);
        sub_676400(v23, 0);
        v24 = sub_89F8E0(&v26);
        sub_438B20(v24);
        result = v26;
        v35 = -1;
        if ( v26 )
          result = (_DWORD *)sub_89F270(v26);
      }
      return result;
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x6E27C0; // "Incorrect Usage. Type /xtarget for correct usage."
/*
if ( !sub_8A3560(&v32, 0) || (sub_89F500(&v32), v8 = sub_89E950(&v28) - 1, v8 < 0) )
      {
LABEL_67:
        v26 = 0;
        v25 = 1;
        v24 = 13;
        v23 = "Incorrect Usage. Type /xtarget for correct usage.";
        goto LABEL_68;
      }
      v26 = (char *)&v29;
      v25 = v13;
      v30 = &v25;
      sub_89F340(&v33);
      if ( !(unsigned __int8)sub_52D7C0(v25, v26) )
      {
        v16 = 0;
        sub_89F500(&v33);
        v17 = sub_89F8E0(&v27);
        v18 = sub_5E2880((_DWORD **)dword_FB5090, v17); // EQPlayerManager__GetSpawnByName
        if ( v18 )
          v16 = *(_DWORD *)(v18 + 328);
        if ( *(_DWORD *)dword_F21F64 )
        {
          word_F1FA98 = sub_854800(28233, 0);
          dword_F1FA9A = v16;
          dword_F1FA9E = v8;
          v19 = sub_7EAEA0(4, &word_F1FA98, 10);
          sub_93ADF2(0);
          --dword_10D71E0;
          if ( !v19 )
            sub_478A00(dword_F21F64);
        }
        else if ( !byte_F2F424 )
        {
          sub_8A22E0("Attempt to send message %d on a void connection.", 73);
        }
        goto LABEL_69;
      }
*/
/*
EQPlayerManager__GetSpawnByName()
for ( i = v5; sub_8A64E0((const char *)(*(_DWORD *)i + 0xA4), (const char *)a2); i = result )
{
result = *(_DWORD *)(i + 8);
if ( !result )
    goto LABEL_6;
v7 = *(_DWORD *)(i + 4);
while ( *(_DWORD *)(result + 4) != v7 )
{
    result = *(_DWORD *)(result + 8);
    if ( !result )
    return result;
}
}
*/

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_TARGET_SPAWN        = 0xF25EF0; // pinstTarget    ExecuteCmd() case 355 CLEAR_TARGET
uint32_t EQ_ADDRESS_POINTER_CONTROLLED_SPAWN    = 0x0; // pinstControlledPlayer
uint32_t EQ_ADDRESS_POINTER_LOCAL_SPAWN         = 0xF287A8; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
uint32_t EQ_ADDRESS_POINTER_PLAYER_SPAWN        = EQ_ADDRESS_POINTER_LOCAL_SPAWN;
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x6D63F0; // search for xref to autorun
/*
EQPlayer__FollowPlayerAI()
    if ( v21 + 15.0 <= *(float *)(v1 + 564) ) // Follow Distance 1
    {
      if ( v21 + 30.0 <= *(float *)(v1 + 564) // Follow Distance 2
        || *(float *)(*(_DWORD *)(v1 + 3868) + 124) >= (double)*(float *)(v1 + 124) && 0.0 != *(float *)(v1 + 124) )
      {
        byte_F2F440 = 1;
        AutoRun____dword_F2F4F4 = 1;
      }
      else
      {
        byte_F2F440 = 0;
        AutoRun____dword_F2F4F4 = 1;
      }
    }
    else
    {
      AutoRun____dword_F2F4F4 = 0;
      *(float *)(v1 + 124) = 0.0;
    }
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x6EAC30; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
/*
v25 = sub_569850(v18);
sprintf(&v59, "Changing %s to race: %s.", dword_F26020 + 164, v25);
v26 = sub_476790();
sub_476850(v26, &v59, 273, 1, 1, 0);
if ( v57 )
sub_53CF80(dword_F26020, &v57); // do_height(TargetPlayer, &x);
if ( v52 )
v27 = atoi(&v52);
else
v27 = 110;
*(_DWORD *)(dword_F26020 + 1020) = v27;
v28 = *(_DWORD *)(dword_F26020 + 328);
sprintf(&v59, "%s is now able to kill anyone (or be killed) as if they were an NPC.", dword_F26020 + 164);
v29 = sub_476790();
result = sub_476850(v29, &v59, 273, 1, 1, 0);
*/

/*
do_height():
v10 = 0.0;
  v11 = 0.0;
  v2 = (char *)dword_F26020;
  v12 = 1.0;
  v3 = sub_4A9BD0(a2, &v24, 40);
  v4 = sub_4A9BD0(v3, &v22, 40);
  sub_4A9BD0(v4, &v23, 40);
  if ( v24 )
    v10 = atof(&v24);
  if ( v22 )
    v11 = atof(&v22);
  if ( v23 )
    v12 = atof(&v23);
  if ( !v2 )
    v2 = dword_F26008;
  if ( v10 > 0.0 )
  {
    if ( byte_F33444 || dword_F3358C )
    {
      sprintf(byte_10F8BB8, "%f", *((float *)v2 + 79));
      sprintf(byte_10F8B98, "%f", v10);
      v13 = (int)(v2 + 164);
      v14 = byte_10F8BB8;
      v15 = byte_10F8B98;
      v16 = 0;
      v17 = 0;
      v18 = 0;
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v8 = sub_86DB80((int)dword_F25F9C, 12963, 0);
      sub_52D240(&v25, (int)v8, (int)&v13, -1, 0);
      v9 = sub_476790();
      sub_476850(v9, &v25, 273, 1, 1, 0);
      sub_5EFD60(v2, v10, v11, 1.0, 0); // EQPlayer__ChangeHeight()
    }
*/

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager    = 0x1739C64; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x9C96F0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest    = 0xFBFD88; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x6861C0; // "#%s %s"
/*
CEverQuest__InterpretCmd()
switch ( byte_F334A0 )
{
case 2:
    sub_52DBF0(a2, &v23);
    break;
case 0xF:
    sub_4AFBC0(&v23);
    break;
case 0:
    sub_52B450(a2, &v23);
    break;
case 7:
    sprintf(&v27, "%s %s", &byte_F334A8, &v23);
    sub_52DD60(a2, &v27);
    break;
case 4:
    sub_52DD00(a2, &v23);
    break;
case 5:
    sub_52DD30(a2, &v23);
    break;
case 0x14:
    sprintf(&v26, "#%s %s", &byte_F334A8, &v23);
    sub_53E4D0(a2, &v26);
    break;
case 0x15:
    sub_52B470(a2, &v23);
    break;
default:
    sub_54BA30(a2, &v23);
    break;
}
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x579710; // "You cannot purchase an item from yourself!"
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting    = 0x66D260; // "%s <%s>"
/*
  if ( v13 && v13 != 3 && v13 != 7 )
  {
    v14 = CDisplay__FindZoneTopZ(v51, *(float *)&v53, v52);
    v52 = v14;
    if ( -9.9999999e26 != v14 )
    {
      v56 = v51;
      v57 = v53;
      v58 = v14;
      DoParticleEffect(v3, 2, (int)&unk_E9BEF0, 61, v5, 0, 0, &v56, 0, 500);
      CDisplay__PlaySoundAtLocation(v51, *(float *)&v53, v52, 99);
    }
  }
*/

// class CDisplay
uint32_t EQ_ADDRESS_POINTER_CDisplay    = 0xF25F08; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "
/*
CDisplay::CreatePlayerActor(*(float *)&a1, (int)dword_F20698, 0, 0, 1, 2, 1, 0);
*/

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x5C2A00; // "%ldms"    "%0.2f%%"
/*
DrawNetStatus()
    sprintf(&Dest, "%0.2f%%", v8 * 100.0);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1, (unsigned __int16)a2, (void *)12);
    sprintf(&Dest, "%ldms", v16);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1 + 64, (unsigned __int16)a2, (void *)12);
*/

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd    = 0xE74DB4;

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__WndNotification    = 0x77A3A0; // "You cannot purchase an item from yourself!"    "9999999"
/*
sub_8EB690("BazaarSearchWnd", "HideTraders", *(_BYTE *)(v26 + 492));
*/

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg    = 0x77B520; // "You successfully purchased %d %s(s) from %s."    " The item has been sent to your parcels."
/*
else
{
    v24 = (volatile signed __int32 **)sub_8A3160(
                                        (int)&v39,
                                        "You successfully purchased %d %s(s) from %s.",
                                        *(_DWORD *)(a4 + 280));
    LOBYTE(v60) = 3;
    sub_8A1330((volatile signed __int32 **)&v36, v24);
    LOBYTE(v60) = 2;
    if ( v39 )
        CXStr__FreeRep((_DWORD *)v39);
    v15 = *(_DWORD *)(a4 + 4) == 1;
    v39 = 0;
    if ( v15 )
        sub_8A2480((int *)&v36, " The item has been sent to your parcels.");
    else
        sub_8A2480((int *)&v36, " The item has been added to your inventory.");
}
*/
/*
case 5514u: // 0x5D3Au
          v54 = a5;
          v53 = a4;
          v55 = 0;
          CBazaarSearchWnd__HandleBazaarMsg((_DWORD *)CBazaarSearchWnd____dword_E716E8, COERCE_FLOAT(&v53));
          break;
*/

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList    = 0x778250;
/*
  result = 0;
  v13 = this;
  v45 = 0;
  v14 = this[9360];
  v47 = 0;
  v15 = *(_DWORD *)(v14 + 500);
  if ( v15 < 200 )
  {
    v16 = Memory;
    if ( (signed int)Memory > 0 )
    {
      v17 = Str1;
      v18 = (char *)&this[46 * v15];
      *((_DWORD *)v18 + 193) = a8;
      *((_DWORD *)v18 + 194) = a9;
      *((_DWORD *)v18 + 191) = a3;
      v19 = a11;
      *((_DWORD *)v18 + 195) = v16;
      *((_DWORD *)v18 + 192) = 0;
      *((_DWORD *)v18 + 196) = v19;
      sub_9A10E0(v17);
      *((_DWORD *)v18 + 188) = a5;
      *((_DWORD *)v18 + 189) = a6;
      *((_DWORD *)v18 + 190) = a7;
      sub_99D8D0(v18 + 688, Source, 0x40u);
      sub_99D8D0(v18 + 624, a4, 0x40u);
      CComboWnd__InsertChoice(Directory);
      v20 = v13[9360];
      v21 = (void *)sub_9BC0F0((int)&Memory, -1, v15, v15 >> 31, 0, 0);
      LOBYTE(v47) = 0;
      if ( Memory )
        CXStr__FreeRep(Memory);
      v22 = sub_7AEC90(a8);
      v23 = v13[9360];
      sub_9BCD80(v21, 0, v22);
      CComboWnd__InsertChoice(Source);
      v24 = v13[9360];
      sub_9BCD00(v21, 1, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      sub_99B670((int)&v45, "%d", (char)v16);
      v25 = v13[9360];
      sub_9BCD00(v21, 2, &v45);
      v26 = (unsigned int)a3 % 1000i64;
      v46 = (unsigned __int64)((unsigned int)a3 / 1000i64) >> 32;
      v27 = _itoa((unsigned int)a3 / 1000i64, DstBuf, 10);
      CComboWnd__InsertChoice(v27);
      v28 = v13[9360];
      LOBYTE(v47) = 3;
      sub_9BCD00(v21, 3, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      v29 = v26 / 100i64;
      v30 = v26 % 100i64;
      v46 = HIDWORD(v29);
      v31 = _itoa(v29, DstBuf, 10);
      CComboWnd__InsertChoice(v31);
      v32 = v13[9360];
      LOBYTE(v47) = 4;
      sub_9BCD00(v21, 4, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      v33 = v30 / 10i64;
      v34 = v30 % 10i64;
      v46 = HIDWORD(v33);
      v35 = _itoa(v33, DstBuf, 10);
      CComboWnd__InsertChoice(v35);
      v36 = v13[9360];
      LOBYTE(v47) = 5;
      sub_9BCD00(v21, 5, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      v37 = _itoa(v34, DstBuf, 10);
      CComboWnd__InsertChoice(v37);
      v38 = v13[9360];
      LOBYTE(v47) = 6;
      sub_9BCD00(v21, 6, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      CComboWnd__InsertChoice(a4);
      v39 = v13[9360];
      LOBYTE(v47) = 7;
      sub_9BCD00(v21, 7, &a8);
      LOBYTE(v47) = 0;
      if ( a8 )
        CXStr__FreeRep(a8);
      v40 = v13[9369];
      a8 = 0;
      if ( v40 )
      {
        v41 = sub_9D6B40(*(_DWORD *)(v40 + 108));
        v42 = sub_9D9D10(v13, v41, 0);
        if ( v42 )
        {
          sub_9C5970(1, 0);
          (*(void (__thiscall **)(int, signed int, signed int, signed int))(*(_DWORD *)v42 + 216))(v42, 1, 1, 1);
          v43 = v13[9360];
          sub_9BCFA0(v21, 8, v42);
        }
      }
      if ( v45 )
        CXStr__FreeRep(v45);
      v45 = 0;
      if ( a11 )
        sub_99B670((int)&v45, "%d", a11);
      v44 = v13[9360];
      sub_9BCD00(v21, 9, &v45);
      result = v45;
    }
  }
  v47 = -1;
  if ( result )
    result = (void *)CXStr__FreeRep(result);
  return result;
}
*/
/*
CBazaarSearchWnd__HandleBazaarMsg()
do
{
    sub_77D8F0(v3);
    v11 = *(_DWORD *)(*((_DWORD *)v2 + 9356) + 4 * (0u % *((_DWORD *)v2 + 9357)));
    if ( v11 )
    {
    while ( *(_DWORD *)(v11 + 76) )
    {
        v11 = *(_DWORD *)(v11 + 80);
        if ( !v11 )
        goto LABEL_16;
    }
    sub_779C50(    // CBazaarSearchWnd__AddItemToList()
        v2,
        &Source,
        v14,
        (char *)(v11 + 12),
        0,
        *(_DWORD *)(v11 + 8),
        *(_DWORD *)v11,
        v17,
        v16,
        Memory,
        v19[0],
        &Str1);
}
*/

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery    = 0x778AF0;
/*
CBazaarSearchWnd__WndNotification()

        if ( v28 > -1 && v28 < 200 )
              {
                if ( *(_DWORD *)(184 * (v28 + 4) + v8) == *((_DWORD *)pinstCharData + 1415) )
                {
                  v29 = sub_4764A0();
                  CEverQuest__dsp_chat(v29, "You cannot purchase an item from yourself!", 13, 1, 1, 0);
                }
                else if ( *(_DWORD *)(184 * v28 + v8 + 764) <= 1 )
                {
                  sub_67B490((_DWORD *)v8, 1);
                }
                else
                {
                  (*(void (__thiscall **)(_DWORD *, int *))(*v7 + 252))(v7, &v41);
                  v30 = *(_DWORD *)(184 * *(_DWORD *)(v8 + 600) + v8 + 764);
                  sub_7738D0((_DWORD *)dword_E716C0, v8, v30, v30, v41, v42, 1, 0, 0, 0);
                }
              }
            }
          }
          else
          {
            v31 = StringTable__getString((int *)StringTable____dword_F24F9C, 0x38CAu, 0);
            v32 = sub_4764A0();
            CEverQuest__dsp_chat(v32, v31, 13, 1, 1, 0);
          }
        }
        return;
      }
LABEL_106:
      sub_8D1150(v20, 0, 0);
      *(_BYTE *)(v8 + 592) = 0;
      *(_DWORD *)(v8 + 580) = sub_8A4290();
      CBazaarSearchWnd__doQuery((_DWORD **)v8); // CBazaarSearchWnd__doQuery()
      return;
    case 14:
      goto LABEL_48;
    case 15:
      v33 = a5;
      v34 = a5 - 1;
      *(_DWORD *)(v8 + 576) = a5;
      switch ( v34 )
      {
        case 0:
          *(_DWORD *)(v8 + 556) ^= 1u;
          sub_67B8A0((_DWORD *)v8, v33);
          break;
        case 1:
          *(_DWORD *)(v8 + 560) ^= 1u;
          sub_67B8A0((_DWORD *)v8, v33);
          break;
*/

/*
  v1 = this;
  sub_77CCE0(&v54);
  v2 = (int *)v1[9360];
  v3 = -1;
  v51 = 0;
  v4 = -1;
  v48 = -1;
  v5 = 0;
  v50 = -1;
  v6 = *v2;
  v53 = -1;
  v52 = 0;
  v45 = 0;
  v46 = 1;
  v47 = 110;
  v49 = 20;
  (*(void (**)(void))(v6 + 384))();
  v7 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v1[9390] + 384))(&Memory);
  v70 = 0;
  v8 = sub_999AD0(v7);
  v9 = (char *)(v69 - (char *)v8);
  do
  {
    v10 = *(_BYTE *)v8;
    v8 = (char (*)[4])((char *)v8 + 1);
    (*v8)[(_DWORD)v9 - 1] = v10;
  }
  while ( v10 );
  v70 = -1;
  if ( Memory )
    CXStr__FreeRep(Memory);
  if ( CComboWnd__GetCurChoice(v1[9384]) )
    v53 = dword_10C4144[2 * CComboWnd__GetCurChoice(v1[9384])];
  if ( CComboWnd__GetCurChoice(v1[9385]) )
    v50 = dword_C8D7AC[2 * CComboWnd__GetCurChoice(v1[9385])];
  if ( CComboWnd__GetCurChoice(v1[9383]) )
  {
    v11 = CComboWnd__GetCurChoice(v1[9383]);
    v12 = v1[9383];
    v48 = dword_AE22E4[2 * v11];
    v13 = sub_9DEE60(&Memory);
    v14 = v1[9360];
    v70 = 1;
    sub_9BC090(9, v13);
    v70 = -1;
    if ( Memory )
      CXStr__FreeRep(Memory);
  }
  if ( CComboWnd__GetCurChoice(v1[9382]) )
    v4 = dword_AE223C[2 * CComboWnd__GetCurChoice(v1[9382])];
  if ( CComboWnd__GetCurChoice(v1[9386]) )
    v3 = dword_AE20FC[2 * CComboWnd__GetCurChoice(v1[9386])];
  v15 = v1[9391];
  if ( v15 )
  {
    v16 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v15 + 384))(&Memory);
    v70 = 2;
    v17 = sub_999AD0(v16);
    v45 = atoi((const char *)v17);
    v70 = -1;
    if ( Memory )
      CXStr__FreeRep(Memory);
  }
  v18 = v1[9392];
  if ( v18 )
  {
    v19 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v18 + 384))(&Memory);
    v70 = 3;
    v20 = sub_999AD0(v19);
    v52 = atoi((const char *)v20);
    v70 = -1;
    if ( Memory )
      CXStr__FreeRep(Memory);
  }
  v21 = v1[9393];
  if ( v21 )
  {
    v22 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v21 + 384))(&Memory);
    v70 = 4;
    v23 = sub_999AD0(v22);
    v47 = atoi((const char *)v23);
    v70 = -1;
    if ( Memory )
      CXStr__FreeRep(Memory);
  }
  v24 = v1[9394];
  if ( v24 )
  {
    v25 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v24 + 384))(&Memory);
    v70 = 5;
    v26 = sub_999AD0(v25);
    v46 = atoi((const char *)v26);
    v70 = -1;
    if ( Memory )
      CXStr__FreeRep(Memory);
  }
  v27 = v1[9395];
  if ( v27 )
  {
    v28 = (int *)(*(int (__stdcall **)(void **))(*(_DWORD *)v27 + 384))(&v44);
    v70 = 6;
    v29 = sub_999AD0(v28);
    v49 = atoi((const char *)v29);
    v70 = -1;
    if ( v44 )
      CXStr__FreeRep(v44);
    v44 = 0;
  }
  v30 = v1[9387];
  if ( v30 )
  {
    v31 = CComboWnd__GetCurChoice(v30);
    if ( v31 != -1 )
    {
      v32 = v1[9387];
      v5 = sub_9DF0B0(v31);
    }
  }
  v33 = v1[9388];
  if ( v33 && CComboWnd__GetCurChoice(v33) )
  {
    v34 = CComboWnd__GetCurChoice(v1[9388]);
    v35 = v1[9388];
    v51 = sub_9DF0B0(v34);
  }
  v36 = v1[9389];
  if ( v36 && CComboWnd__GetCurChoice(v36) )
  {
    v37 = CComboWnd__GetCurChoice(v1[9389]);
    v38 = v1[9389];
    v39 = sub_9DF0B0(v37);
  }
  else
  {
    v39 = 0;
  }
  v57 = v50;
  v58 = v53;
  v59 = v48;
  v62 = v52;
  v63 = v45;
  v64 = v46;
  v65 = v47;
  v66 = v49;
  v54 = 7;
  v60 = v4;
  v61 = v3;
  v67 = v51;
  v68 = v39;
  if ( v5 == -1 )
  {
    LOBYTE(v55) = 0;
    v56 = 0;
  }
  else
  {
    LOBYTE(v55) = 1;
    v56 = v5;
  }
  v40 = 0;
  do
  {
    v41 = v69[v40++];
    *((_BYTE *)&v61 + v40 + 3) = v41;
  }
  while ( v41 );
  if ( *(_DWORD *)dword_F20F20 )
  {
    word_F206D0 = sub_94D6F0(9449, 0);
    qmemcpy(&dword_F206D2, &v54, 0x84u);
    v42 = send_message(*(int *)dword_F20F20, 4, &word_F206D0, 134);
    j_j__free(0);
    --dword_10D83A4;
    if ( v42 )
      sub_8ED3F0(dword_F20F20[0]);
    else
      sub_57B530((_DWORD *)dword_D3AAA8, (int *)dword_F20F20);
  }
  else if ( !byte_F30384 )
  {
    sub_99D530("Attempt to send message %d on a void connection.", 233);
  }
*/

