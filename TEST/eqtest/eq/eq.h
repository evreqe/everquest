#pragma once

#include <cstdint>

#include <unordered_map>
#include <string>

#include "eq_constants.h"
#include "eq_messages.h"

uint32_t EQ_ADDRESS_CLIENT_VERSION_DATE = 0xABF23C; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_DATE "Apr  9 2018"
#define EQ_SIZE_CLIENT_VERSION_DATE 12

uint32_t EQ_ADDRESS_CLIENT_VERSION_TIME = 0xABF230; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_TIME "21:46:39"
#define EQ_SIZE_CLIENT_VERSION_TIME 9

uint32_t EQ_ADDRESS_AUTO_ATTACK    = 0xF0B507; // uint8_t    // Attack
uint32_t EQ_ADDRESS_AUTO_FIRE      = 0xF0B508; // uint8_t    // Autofire
uint32_t EQ_ADDRESS_AUTO_RUN       = 0xE6C8B8; // uint32_t
uint32_t EQ_ADDRESS_MOUSE_LOOK     = 0xE6C89A; // uint8_t    // MouseLook
uint32_t EQ_ADDRESS_NET_STATUS     = 0xE6C89D; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_POINTER_WINDOW_HWND = 0xF0EA94; // HWND hWnd    // in IDA press G, jump to address: hWnd
/*
    PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/
/*
    _snprintf(v11, v10, "%s %s", &Dest, &v14);
    PostMessageA(hWnd, 0x4646u, 0x4246u, (LPARAM)v11);
*/

uint32_t EQ_ADDRESS_POINTER_StringTable    = 0xE5F024; // pinstStringTable

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x89FCB0; // "%s (%d)"    "ERROR: String not found."

uint32_t EQ_ADDRESS_POINTER_build_token_string_PARAM    = 0x58BB90; // calls StringTable__getString()
/*
_BYTE *__cdecl sub_58BB90(_BYTE *a1, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  char *v11; // eax
  int v13; // [esp+0h] [ebp-24h]
  int v14; // [esp+4h] [ebp-20h]
  int v15; // [esp+8h] [ebp-1Ch]
  int v16; // [esp+Ch] [ebp-18h]
  int v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  v13 = a3;
  v14 = a4;
  v15 = a5;
  v16 = a6;
  v17 = a7;
  v18 = a8;
  v19 = a9;
  v20 = a10;
  v21 = a11;
  v11 = StringTable__getString(dword_E5F024, a2, 0);
  sub_5ABB90(a1, v11, (int)&v13, -1, 0);
  return a1;
}
*/

uint32_t EQ_ADDRESS_FUNCTION_CrashDetected    = 0x694830; // "Crash (char = %s, zone = %s)\n"    "Local Player's World location at time of crash: %f, %f, %f.\n"    "Gamestate at crash = %d\n"    "Crash Details: %s\n"
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

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x6163A0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x586860; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
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
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager    = 0xF0D310; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x63E030; // "Your inventory is full!"
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x63E050; // "Incorrect Usage. Type /xtarget for correct usage."
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
uint32_t EQ_ADDRESS_POINTER_TARGET_SPAWN        = 0xE5F1A4; // pinstTarget    ExecuteCmd() case CLEAR_TARGET
uint32_t EQ_ADDRESS_POINTER_PLAYER_SPAWN        = 0xE5F150; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x632070; // search for xref to autorun
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x645CC0; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
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
uint32_t EQ_ADDRESS_POINTER_CXWndManager    = 0x169B650; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x905AC0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest    = 0xF0EBE8; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x5E7050; // "#%s %s"
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

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x4E1190; // "You cannot purchase an item from yourself!"
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting    = 0x5CE4D0; // "%s <%s>"
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
uint32_t EQ_ADDRESS_POINTER_CDisplay    = 0xE5F3B8; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "
/*
CDisplay::CreatePlayerActor(*(float *)&a1, (int)dword_F20698, 0, 0, 1, 2, 1, 0);
*/

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x5270B0; // "%ldms"    "%0.2f%%"
/*
DrawNetStatus()
    sprintf(&Dest, "%0.2f%%", v8 * 100.0);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1, (unsigned __int16)a2, (void *)12);
    sprintf(&Dest, "%ldms", v16);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1 + 64, (unsigned __int16)a2, (void *)12);
*/

uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x901A60; // "MapSkin" "AtlasSkin"
/*
sub_932730(3, &v47);
    v25 = (const CHAR *)sub_8D5B70(&lpMem);
    sub_90C760("Main", "MapSkin", v25);
    sub_75FE20(0);
    LOBYTE(v48) = 14;
    if ( lpMem )
      sub_8D7860(lpMem);
    lpMem = 0;
    v48 = 15;
    if ( v47 )
      sub_8D7860(v47);
  }
  v48 = -1;
LABEL_15:
  if ( (unsigned __int8)sub_8FF710(v4) )
  {
    if ( !*((_DWORD *)v4 + 206) || (v12 = *((_DWORD *)v4 + 207)) != 0 && sub_901A60(v12) ) // sub_901A60 == CXWnd__IsReallyVisible()
    {
      switch ( v7 )
      {
        case 6:
          return 0;
        case 14:
          v30 = (_BYTE *)*((_DWORD *)v4 + 193);
          if ( v6 == v30 )
          {
            (*(void (__stdcall **)(LPVOID *))(*(_DWORD *)v30 + 384))(&lpMem);
            v48 = 16;
            *((_DWORD *)v4 + 399) = sub_8D6F00(&lpMem);
            v4[1623] = 1;
            v48 = 17;
            if ( lpMem )
              sub_8D7860(lpMem);
            v48 = -1;
          }
*/

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd    = 0xDAAE04;

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__WndNotification    = 0x6C9950; // "You cannot purchase an item from yourself!"    "9999999"
/*
sub_8EB690("BazaarSearchWnd", "HideTraders", *(_BYTE *)(v26 + 492));
*/

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg    = 0x6CAA30; // "You successfully purchased %d %s(s) from %s."    "The item has been sent to your parcels."
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList    = 0x6C78A0;
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery    = 0x6C8130;
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem    = 0x6C8660;
/*
if ( dword_FBD53C <= 0 )
{
    v30 = *(_DWORD **)(v6 + 37448);
    a5 = -1;
    a3 = -1;
    sub_9B8F70(v30, (int)v7, &a5, &a3);
    v31 = sub_9B8D10((_DWORD *)*(_DWORD *)(v6 + 37448), a5);
    *(_DWORD *)(v6 + 624) = v31;
    if ( v31 <= 0xC7 )
    {
    if ( *(_DWORD *)(184 * v31 + v6 + 760) == *((_DWORD *)dword_F25F34 + 1415) )
    {
        v32 = sub_579000();
        sub_579710(v32, "You cannot purchase an item from yourself!", (void *)0xD, (void *)1, (void *)1, 0);
        return 0;
    }
    if ( *(_DWORD *)(184 * v31 + v6 + 788) <= 1 )
    {
        sub_779040((_DWORD *)v6, 1); // CBazaarSearchWnd__BuyItem()
    }
    else
    {
        (*(void (__thiscall **)(_DWORD *, int *))(*v7 + 252))(v7, &v43);
        v33 = *(_DWORD *)(184 * *(_DWORD *)(v6 + 624) + v6 + 788);
        sub_873A50(dword_E74DA8, v6, v33, v33, v43, v44, (void *)1, 0, 0, 0);
    }
    }
}
return 0;
*/
/*
char __thiscall sub_779040(_DWORD *this, int a2) // CBazaarSearchWnd__BuyItem()
{
  _DWORD *v2; // esi
  signed int v3; // eax
  char *v4; // ecx
  int v5; // eax
  int v6; // eax
  void *v7; // ecx
  int v8; // ST00_4
  void *v10; // [esp-1Ch] [ebp-34h]
  char *v11; // [esp-18h] [ebp-30h]
  int v12; // [esp-14h] [ebp-2Ch]
  void *v13; // [esp-10h] [ebp-28h]
  void *v14; // [esp-Ch] [ebp-24h]
  int v15; // [esp-8h] [ebp-20h]
  char *v16; // [esp-4h] [ebp-1Ch]
  int v17; // [esp+0h] [ebp-18h]
  int v18; // [esp+14h] [ebp-4h]

  v2 = this;
  v3 = this[156];
  if ( v3 < 0 || v3 >= 200 || !dword_E74EA0 ) // CBazaarConfirmationWnd pointer
    return 0;
  v17 = a2;
  v4 = (char *)&this[46 * v3];
  v16 = v4 + 796;
  v15 = *((_DWORD *)v4 + 196);
  v5 = *((unsigned __int16 *)v2 + 314);
  v14 = (void *)*((_DWORD *)v4 + 190);
  v13 = (void *)*((_DWORD *)v4 + 193);
  v12 = v5;
  v11 = v4;
  sub_998F70((void **)&v11, v4 + 632);
  v6 = 46 * v2[156];
  v10 = v7;
  v18 = 0;
  sub_998F70(&v10, &v2[v6 + 174]);
  v8 = v2[46 * v2[156] + 195];
  v18 = -1;
  sub_538850((char *)dword_E74EA0, v8, v10, v11, v12, v13, v14, v15, v16, v17);
  sub_9C4C80((int)v2, (int *)&v14);
  sub_9C6340((_DWORD *)dword_E74EA0, (int)v14, v15, (int)v16, v17);
  v17 = 1;
  v16 = (char *)1;
  v15 = 1;
  (*(void (__stdcall **)(signed int, signed int, signed int))(*(_DWORD *)dword_E74EA0 + 216))(1, 1, 1);
  sub_9C67A0((void *)dword_E74EA0, 1);
  return 1;
}
*/

uint32_t EQ_ADDRESS_POINTER_CBazaarConfirmationWnd    = 0xDAAB74;

uint32_t EQ_ADDRESS_FUNCTION_CBazaarConfirmationWnd__WndNotification    = 0x4A33D0;

/*
int __thiscall sub_538710(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // ebp
  int v5; // esi
  char v6; // bl

  v4 = this;
  if ( a3 != 1 )
    return sub_9D3310((void **)this, a2, a3, a4);
  v5 = a2;
  if ( a2 == this[151] || a2 == this[154] )
  {
    ++dword_FBD53C;
    a2 = 59;
    if ( (unsigned int)((*(_DWORD *)(dword_FBFD88 + 234968) - *(_DWORD *)(dword_FBFD88 + 234964)) >> 2) < 0x14 )
      sub_732270((_DWORD *)(dword_FBFD88 + 234964), (unsigned int *)&a2);
    v4[157] = (v5 == v4[151]) + 1;
    if ( *(_DWORD *)dword_F2679C )
    {
      word_F25F48 = sub_94D430(6247, 0);
      if ( v4 != (_DWORD *)-624 )
        qmemcpy(&dword_F25F4A, v4 + 156, 0x11Cu);
      v6 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 286);
      j_j__free(0);
      --dword_10E0E94;
      if ( v6 )
        sub_8ECAD0(*(int *)dword_F2679C);
      else
        sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
    }
    else if ( !byte_F35BA4 )
    {
      sub_99D110("Attempt to send message %d on a void connection.", 103);
    }
  }
  (*(void (__thiscall **)(_DWORD *, _DWORD, signed int, signed int))(*v4 + 216))(v4, 0, 1, 1);
  return 0;
}
*/

// Trader window
uint32_t EQ_ADDRESS_POINTER_CBazaarWnd    = 0xDAAE7C;

uint32_t EQ_ADDRESS_FUNCTION_CBazaarWnd__WndNotification    = 0x6CC530;
/*
int __thiscall sub_77D300(int this, int a2, int a3, void **a4)
{
  int v4; // ebx
  int v5; // ebp
  int v6; // esi
  char v7; // cl
  char v8; // bl
  char *v9; // eax
  int result; // eax
  int v11; // esi
  int *v12; // edi
  int v13; // esi
  _DWORD *v14; // ecx
  char *v15; // eax
  char v16; // bl
  char *v17; // eax
  char v18; // bl
  signed int v19; // eax
  char *v20; // eax
  char v21; // bl
  char *v22; // eax
  char v23; // bl
  char *v24; // eax
  _DWORD *v25; // ecx
  void *v26; // ecx
  char v27; // [esp+13h] [ebp-A5h]
  int v28; // [esp+14h] [ebp-A4h]
  int v29; // [esp+18h] [ebp-A0h]
  int v30; // [esp+1Ch] [ebp-9Ch]
  char v31; // [esp+20h] [ebp-98h]
  char v32; // [esp+24h] [ebp-94h]
  char v33; // [esp+28h] [ebp-90h]
  int v34; // [esp+2Ch] [ebp-8Ch]
  char v35; // [esp+30h] [ebp-88h]
  int v36; // [esp+48h] [ebp-70h]
  int v37; // [esp+4Ch] [ebp-6Ch]
  char v38; // [esp+50h] [ebp-68h]
  int v39; // [esp+68h] [ebp-50h]
  int v40; // [esp+6Ch] [ebp-4Ch]
  char v41; // [esp+70h] [ebp-48h]
  int v42; // [esp+88h] [ebp-30h]
  int v43; // [esp+8Ch] [ebp-2Ch]
  char v44; // [esp+90h] [ebp-28h]
  int v45; // [esp+A8h] [ebp-10h]
  int v46; // [esp+B4h] [ebp-4h]

  v4 = 0;
  v5 = this;
  v29 = 0;
  if ( a3 == 1 )
  {
    if ( a2 == *(_DWORD *)(this + 612) )
    {
      v6 = sub_7811B0((volatile signed __int32 ***)this);
      if ( *(_DWORD *)(v5 + 580) == -1 )
        goto LABEL_18;
      if ( !sub_77E380((_DWORD *)v5) )
        goto LABEL_18;
      v7 = *(_BYTE *)(v5 + 2548);
      if ( !v7 )
        goto LABEL_18;
      if ( *(_BYTE *)(*(_DWORD *)(v5 + 580) + v5 + 2284) )
      {
        sub_781330(&v34);
        sub_9A0EC0(&v35, (char *)(*(_DWORD *)(v5 + 596) + 52));
        v36 = v6;
        v34 = 3;
        if ( *(_DWORD *)dword_F2679C )
        {
          word_F25F48 = sub_94D430(31402, 0);
          qmemcpy(&dword_F25F4A, &v34, 0x20u);
          v8 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 34);
          j_j__free(0);
          --dword_10E0E94;
          if ( v8 )
            sub_8ECAD0(*(int *)dword_F2679C);
          else
            sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
          v9 = StringTable__getString(dword_F26798, 0x1A60u, 0);
        }
        else
        {
          if ( !byte_F35BA4 )
            sub_99D110("Attempt to send message %d on a void connection.", 170);
          v9 = StringTable__getString(dword_F26798, 0x1A60u, 0);
        }
      }
      else
      {
        if ( !v7 )
        {
LABEL_18:
          sub_77C8F0((_DWORD *)v5);
          return 0;
        }
        v9 = StringTable__getString(dword_F26798, 0x1A61u, 0);
      }
      sub_77FF30((char **)v5, v9, (void *)0xF);
      goto LABEL_18;
    }
    if ( a2 == *(_DWORD *)(this + 624) )
    {
      v11 = sub_7811B0((volatile signed __int32 ***)this);
      if ( v11 )
      {
        v12 = (int *)(v5 + 596);
        if ( *(_DWORD *)(v5 + 596) )
        {
          if ( *(_BYTE *)(v5 + 2548) )
          {
            sub_781330(&v40);
            v42 = v11;
            v13 = 0;
            v40 = 3;
            v30 = 0;
            do
            {
              v4 |= 1u;
              v28 = v4;
              if ( !*sub_781430((_DWORD *)v5, &v31, v13)
                || *(_BYTE *)(v13 + v5 + 2284)
                || (v14 = (_DWORD *)*sub_781430((_DWORD *)v5, &v32, v13),
                    v4 |= 2u,
                    v46 = 1,
                    v28 = v4,
                    v29 = v4,
                    v27 = 1,
                    !sub_94B110(v14, v12, 1)) )
              {
                v27 = 0;
              }
              v46 = 0;
              if ( v4 & 2 )
              {
                v4 &= 0xFFFFFFFD;
                v28 = v4;
                v29 = v4;
                sub_88DAD0(&v32);
              }
              v46 = -1;
              if ( v4 & 1 )
              {
                v4 &= 0xFFFFFFFE;
                v28 = v4;
                sub_88DAD0(&v31);
              }
              if ( v27 )
              {
                v15 = (char *)(*sub_781430((_DWORD *)v5, &v33, v13) + 52);
                v46 = 2;
                sub_9A0EC0(&v41, v15);
                v46 = -1;
                sub_88DAD0(&v33);
                if ( *(_DWORD *)dword_F2679C )
                {
                  word_F25F48 = sub_94D430(31402, 0);
                  qmemcpy(&dword_F25F4A, &v40, 0x20u);
                  v16 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 34);
                  j_j__free(0);
                  --dword_10E0E94;
                  if ( !v16 )
                    sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
                  v13 = v30;
                  v12 = (int *)(v5 + 596);
                  v4 = v28;
                }
                else if ( !byte_F35BA4 )
                {
                  sub_99D110("Attempt to send message %d on a void connection.", 170);
                }
              }
              v30 = ++v13;
            }
            while ( v13 < 200 );
          }
        }
      }
      sub_77C8F0((_DWORD *)v5);
      return 0;
    }
    if ( a2 == *(_DWORD *)(this + 628) )
    {
      if ( *(_DWORD *)(this + 596) && *(_BYTE *)(this + 2548) )
      {
        sub_781330(&v37);
        v17 = (char *)(*(_DWORD *)(v5 + 596) + 52);
        v37 = 3;
        sub_9A0EC0(&v38, v17);
        v39 = 0;
        if ( *(_DWORD *)dword_F2679C )
        {
          word_F25F48 = sub_94D430(31402, 0);
          qmemcpy(&dword_F25F4A, &v37, 0x20u);
          v18 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 34);
          j_j__free(0);
          --dword_10E0E94;
          if ( v18 )
            sub_8ECAD0(*(int *)dword_F2679C);
          else
            sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
        }
        else if ( !byte_F35BA4 )
        {
          sub_99D110("Attempt to send message %d on a void connection.", 170);
        }
        sub_77DAE0((_DWORD *)v5, (int *)(v5 + 596), 0);
      }
      sub_77C8F0((_DWORD *)v5);
      return 0;
    }
    if ( a2 == *(_DWORD *)(this + 600) )
    {
      v19 = sub_77F2A0((_DWORD *)this);
      if ( v19 == -1 )
      {
        v20 = StringTable__getString(dword_F26798, 0x1A57u, 0);
      }
      else
      {
        if ( v19 != -2 )
          return 0;
        v20 = StringTable__getString(dword_F26798, 0x1A62u, 0);
      }
      sub_77FF30((char **)v5, v20, (void *)0xF);
      return 0;
    }
    if ( a2 == *(_DWORD *)(this + 616) )
    {
      if ( *(_BYTE *)(this + 2548) )
      {
        if ( *(_DWORD *)dword_F2679C )
        {
          word_F25F48 = sub_94D430(31402, 0);
          dword_F25F4A = 11;
          qword_F25F4E = 0i64;
          v21 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 14);
          j_j__free(0);
          --dword_10E0E94;
          if ( v21 )
            sub_8ECAD0(*(int *)dword_F2679C);
          else
            sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
          return 0;
        }
        if ( !byte_F35BA4 )
          sub_99D110("Attempt to send message %d on a void connection.", 170);
      }
      return 0;
    }
    if ( a2 == *(_DWORD *)(this + 608) )
    {
      *(_DWORD *)(this + 588) = 0;
      sub_77E190((_DWORD *)this);
      if ( *(_DWORD *)(v5 + 580) != -1 && sub_77E380((_DWORD *)v5) && *(_BYTE *)(v5 + 2548) )
      {
        sub_781330(&v43);
        v22 = (char *)(*(_DWORD *)(v5 + 596) + 52);
        v43 = 3;
        sub_9A0EC0(&v44, v22);
        v45 = 0;
        if ( *(_DWORD *)dword_F2679C )
        {
          word_F25F48 = sub_94D430(31402, 0);
          qmemcpy(&dword_F25F4A, &v43, 0x20u);
          v23 = sub_8EF920(*(int *)dword_F2679C, 4, &word_F25F48, 34);
          j_j__free(0);
          --dword_10E0E94;
          if ( v23 )
            sub_8ECAD0(*(int *)dword_F2679C);
          else
            sub_57B3F0((_DWORD *)dword_D402C8, (LPCRITICAL_SECTION **)dword_F2679C);
        }
        else if ( !byte_F35BA4 )
        {
          sub_99D110("Attempt to send message %d on a void connection.", 170);
        }
        sub_77DAE0((_DWORD *)v5, (int *)(v5 + 596), 0);
      }
      sub_77C8F0((_DWORD *)v5);
      result = 0;
    }
    else
    {
      if ( a2 == *(_DWORD *)(this + 604) )
      {
        sub_77C830((char *)this);
        v29 = 0;
        v46 = 3;
        sub_77DAE0((_DWORD *)v5, &v29, 0);
        v46 = -1;
        sub_88DAD0(&v29);
        return 0;
      }
      if ( a2 == *(_DWORD *)(this + 648) )
      {
        if ( dword_F287A8 )
        {
          sub_6338B0(dword_F287A8, (unsigned int)Directory);
          return 0;
        }
        return 0;
      }
      v24 = 0;
      v25 = (_DWORD *)(this + 632);
      while ( a2 != *v25 )
      {
        ++v24;
        ++v25;
        if ( (signed int)v24 >= 4 )
          goto LABEL_97;
      }
      sub_77E7C0((_DWORD *)v5, v24, (void *)0xFFFFFFFF);
      result = 0;
    }
  }
  else
  {
    if ( a3 != 3 )
    {
      if ( a3 == 39 )
      {
        v26 = *(void **)(this + 592);
        if ( v26 != (void *)-1 )
        {
          sub_77E7C0((_DWORD *)v5, v26, *a4);
          *(_DWORD *)(v5 + 592) = -1;
          return 0;
        }
      }
      else if ( a3 == 10 )
      {
        sub_77C830((char *)this);
        byte_10CCD48 = 0;
        *(_BYTE *)(v5 + 2548) = 0;
        sub_7E43B0((_DWORD *)dword_E74E40, 0);
      }
    }
LABEL_97:
    result = sub_9D3310((void **)v5, a2, a3, (int)a4);
  }
  return result;
}
*/
