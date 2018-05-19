#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

uint32_t EQ_ADDRESS_ClientVersionTime = 0xABF328; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_ClientVersionTime "12:42:49"
#define EQ_SIZE_ClientVersionTime 9

uint32_t EQ_ADDRESS_ClientVersionDate = 0xABF334; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_ClientVersionDate "May 18 2018"
#define EQ_SIZE_ClientVersionDate 12

uint32_t EQ_ADDRESS_AutoAttack    = 0xF0B563; // uint8_t    // /attack
uint32_t EQ_ADDRESS_AutoFire      = 0xF0B564; // uint8_t    // /autofire
uint32_t EQ_ADDRESS_AutoRun       = 0xE6C910; // uint32_t
uint32_t EQ_ADDRESS_MouseLook     = 0xE6C8F2; // uint8_t    // holding down right-click to look around
uint32_t EQ_ADDRESS_NetStatus     = 0xE6C8F5; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_FogEnabled           = 0xE6CCBE;    // uint16_t, first byte value 0x00=Off and 0xFF=On, second byte value flags or something
uint32_t EQ_ADDRESS_FogDistanceBegin    = 0xE6CD2C;    // float
uint32_t EQ_ADDRESS_FogDistanceEnd      = 0xE6CD30;    // float
uint32_t EQ_ADDRESS_FarClipPlane        = 0xE6DD7C;    // uint32_t, values 0-20
/*
search for "ClipPlane" and "FogScale"
*/
/*
sub_90BF80("Options", "ClipPlane", (int)v134);
sub_90BFA0("Options", "FogScale", flt_E6BEB4);
result = flt_E6AD2C + (flt_E6AD30 - flt_E6AD2C) * ((double)(signed int)dword_E6BD7C * 0.050000001);

    result = flt_FOG_DISTANCE_BEGIN + (flt_FOG_DISTANCE_END - flt_FOG_DISTANCE_BEGIN) * ((double)(signed int)dword_FAR_CLIP_PLANE * 0.050000001);

v294 = result;
sub_52B3F0((float *)dword_E5D410, v294);
sub_795A10((_DWORD **)dword_DA9368, dword_E6BD7C);
*/

uint32_t EQ_ADDRESS_WindowHWND = 0xF0EAEC; // HWND hWnd    // in IDA press G, jump to address: hWnd
/*
    PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/
/*
    _snprintf(v11, v10, "%s %s", &Dest, &v14);
    PostMessageA(hWnd, 0x4646u, 0x4246u, (LPARAM)v11);
*/

uint32_t EQ_ADDRESS_POINTER_StringTable    = 0xE5F07C; // pinstStringTable

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x8A1B90; // "%s (%d)"    "ERROR: String not found."

uint32_t EQ_ADDRESS_FUNCTION_CrashDetected    = 0x694DB0; // "Crash (char = %s, zone = %s)\n"    "Local Player's World location at time of crash: %f, %f, %f.\n"    "Gamestate at crash = %d\n"    "Crash Details: %s\n"
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

uint32_t EQ_ADDRESS_FUNCTION_CastRay    = 0x58DF60; // called by CastRay2 function
/*
int __cdecl CastRay(int a1, float a2, float a3, float a4)
{
  int v5; // eax
  int v6; // [esp-4h] [ebp-14h]
  float v7; // [esp+0h] [ebp-10h]
  float v8; // [esp+4h] [ebp-Ch]
  float v9; // [esp+8h] [ebp-8h]

  if ( !a1 )
    return 0;
  v5 = *(_DWORD *)a1;
  v9 = a4;
  v8 = a3;
  v7 = a2;
  (*(void (__thiscall **)(int, int *))(v5 + 0x88))(a1, &v6);
  return CastRay2(a1, a1 + 0x64, v6, v7, v8, v9);
}
*/

uint32_t EQ_ADDRESS_FUNCTION_CastRay2    = 0x58DFB0; // CCollisionInfoLineSegmentVisibility::`vftable'
/*
.rdata:00B0116C ; const CCollisionInfoLineSegmentVisibility::`vftable'
.rdata:00B0116C ??_7CCollisionInfoLineSegmentVisibility@@6B@ dd offset sub_8729A0 // search for xref
*/
/*
has a function that has an xref to CCollisionInfoLineSegment::`vftable'
*/
/*
int __usercall CastRay2@<eax>(int a1@<esi>, int a2, int a3, float a4, float a5, float a6)
{
  double v7; // st6
  double v8; // st5
  double v9; // st2
  int v10; // eax
  signed int v11; // esi
  void **v12; // [esp+0h] [ebp-B8h]
  LPVOID lpMem; // [esp+60h] [ebp-58h]
  char v14; // [esp+66h] [ebp-52h]
  int v15; // [esp+68h] [ebp-50h]
  char v16; // [esp+6Ch] [ebp-4Ch]
  float v17; // [esp+94h] [ebp-24h]
  float v18; // [esp+98h] [ebp-20h]
  float v19; // [esp+9Ch] [ebp-1Ch]
  float v20; // [esp+A0h] [ebp-18h]
  float v21; // [esp+A4h] [ebp-14h]
  float v22; // [esp+A8h] [ebp-10h]
  int v23; // [esp+B4h] [ebp-4h]

  if ( sub_8AF080((_DWORD *)dword_E5AE14, dword_E6BA04) )
    return 1;
  v7 = *(float *)(a2 + 4);
  v8 = *(float *)(a2 + 8);
  if ( a3 == dword_BE1074 || a3 == dword_BE1078 || a3 == dword_BE1068 )
    v8 = v8 + 1.0;
  if ( flt_E59714 == a4
    && flt_E59718 == a5
    && flt_E5971C == a6
    && flt_E59708 == *(float *)a2
    && flt_E5970C == v7
    && flt_E59710 == v8 )
  {
    return dword_E59720;
  }
  v9 = *(float *)a2;
  flt_E59708 = *(float *)a2;
  v17 = v9;
  flt_E5970C = v7;
  v18 = v7;
  flt_E59710 = v8;
  v19 = v8;
  flt_E59714 = a4;
  flt_E59718 = a5;
  flt_E5971C = a6;
  v20 = a4 - v9;
  v21 = a5 - v7;
  v22 = a6 - v8;
  sub_4C4910((float *)&v12, &v17);
  v12 = &CCollisionInfoLineSegmentVisibility::`vftable';
  v15 = 1;
  v14 = 1;
  v16 = 0;
  v10 = *(_DWORD *)dword_169A5A4;
  v23 = 0;
  if ( (*(unsigned __int8 (__stdcall **)(int))(v10 + 68))(a1)
    && (**(unsigned __int8 (__stdcall ***)(void ***))dword_169A5A4)(&v12) )
  {
    dword_E59720 = 0;
    v11 = 0;
  }
  else
  {
    dword_E59720 = 1;
    v11 = 1;
  }
  v23 = 1;
  v12 = &CCollisionInfoBase::`vftable';
  LOBYTE(v23) = 4;
  if ( lpMem )
    sub_8D63D0(lpMem);
  return v11;
}
*/

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x6167A0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x5868F0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
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

uint32_t EQ_ADDRESS_FUNCTION_GetExecuteCmdIDByName    = 0x58B3F0; // "AUTORUN" xref    char[] array of about 520
/*
int __cdecl GetExecuteCmdIDByName(const char *a1)
{
  int v1; // esi
  int v2; // eax

  v1 = 0;
  while ( 1 )
  {
    v2 = strcmp(off_BE0088[v1], a1);
    if ( v2 )
      v2 = -(v2 < 0) | 1;
    if ( !v2 )
      break;
    if ( (unsigned int)++v1 >= 520 )
      return 0;
  }
  return v1;
}
*/

uint32_t EQ_ADDRESS_FUNCTION_GetExecuteCmdNameByID    = 0x58B3E0; // "AUTORUN" xref    char[] array of about 520
/*
char *__cdecl GetExecuteCmdNameByID(int a1)
{
  return off_BE0088[a1];
}
*/

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager    = 0xF0D368; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x63E350; // "Your inventory is full!"
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x63E370; // "Incorrect Usage. Type /xtarget for correct usage."
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetPlayerFromPartialName = 0x63E400;

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_TargetSpawn        = 0xE5F1FC; // pinstTarget    ExecuteCmd() case CLEAR_TARGET
uint32_t EQ_ADDRESS_POINTER_PlayerSpawn        = 0xE5F1A8; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x6322F0; // search for xref to autorun
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x646030; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
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

// this is CDisplay__UpdateItemSlot in Mac client
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot    = 0x637EA0; // "IT36" "IT159" "IT10758" "IT10742"

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager    = 0x169B6C0; // pinstCXWndManager
/*
CDisplay__WriteTextHD2():
  if ( pinstCXWndManager__dword_1699650 )
  {
    v14 = 0;
    v13 = 0;
    v12 = a3;
    v11 = a2;
    v14 = *(_DWORD *)(pinstCXWndManager__dword_1699650 + 280);
    v13 = *(_DWORD *)(pinstCXWndManager__dword_1699650 + 276);
    sub_8D3F80(&lpMem, a1);
    v8 = __OFSUB__(*(_DWORD *)(pinstCXWndManager__dword_1699650 + 284), 2);
    v6 = *(_DWORD *)(pinstCXWndManager__dword_1699650 + 284) == 2;
    v7 = *(_DWORD *)(pinstCXWndManager__dword_1699650 + 284) - 2 < 0;
    v15 = 0;
    if ( (unsigned __int8)(v7 ^ v8) | v6 || (v9 = *(_DWORD *)(pinstCXWndManager__dword_1699650 + 0x120)) == 0 )
      sub_476D30((void *)(pinstCXWndManager__dword_1699650 + 0x11C));
    CTextureFont__DrawWrappedText(
      *(_DWORD **)(v9 + 8),
      &lpMem,
      a2,
      a3,
      *(_DWORD *)(pinstCXWndManager__dword_1699650 + 0x114) - a2,
      (int)&v11,
      (int)v5,
      1,
      0);
    v15 = 1;
    if ( lpMem )
      sub_8D63D0(lpMem);
  }
  return 1;
*/

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x907BB0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest    = 0xF0EC40; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone    = 0x5D4540; // "Initializing world."    "Zone initialized."
/*
    sub_8D8140("Resetting cameras.");
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E6BEA8 + 24))(11.0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E6BEA8 + 32))(500.0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E6BEA8 + 16))(-1.0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E6BEA8 + 20))(-7.9990001);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E6BEA8 + 40))(90.0);
    sub_8D8140("Resetting overlays.");
    dword_E5D154 = 0;
    dword_E5D160 = 0;
    dword_E5D158 = 0;
    dword_E5D15C = 0;
    dword_F09510 = 0;
    sub_690AD0();
    sub_8D8140("Zone initialized.");
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x5E7240; // "#%s %s"
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

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x4E1410; // "You cannot purchase an item from yourself!"
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting    = 0x5CE590; // "%s <%s>"
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

uint32_t EQ_ADDRESS_POINTER_CDisplay    = 0xE5F410; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "
/*
CDisplay::CreatePlayerActor(*(float *)&a1, (int)dword_F20698, 0, 0, 1, 2, 1, 0);
*/

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x527960; // "%ldms"    "%0.2f%%"
/*
DrawNetStatus()
    sprintf(&Dest, "%0.2f%%", v8 * 100.0);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1, (unsigned __int16)a2, (void *)12);
    sprintf(&Dest, "%ldms", v16);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1 + 64, (unsigned __int16)a2, (void *)12);
*/

uint32_t EQ_ADDRESS_POINTER_EQSwitchManager    = 0xE5C9C8;

uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x5BCB70;
uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x5BD050;

uint32_t EQ_ADDRESS_POINTER_CCamera    = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRender    = 0x169C608; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions
/*
LPVOID __userpurge sub_53FEC0@<eax>(int a1@<ecx>, float *a2@<ebp>, int a3, int a4)
{
  int v4; // esi
  bool v5; // bl
  unsigned int v6; // edi
  char *v8; // eax

  v4 = a1;
  *(_DWORD *)(a1 + 532) = a3;
  v5 = rand() % 20 == 0;
  v6 = sub_8D7E50();
  if ( *(_DWORD *)(v4 + 532) > 100 )
    *(_DWORD *)(v4 + 532) = 100;
  if ( !a4 )
  {
    *(_BYTE *)(v4 + 20) = 0;
    return sub_53FFA0(v4, v5, a2, (float *)v4); // draw loading screen function
  }
  if ( byte_DA9F60 && dword_DA9F64 + 3000 > v6 )
    return sub_53FFA0(v4, v5, a2, (float *)v4); // draw loading screen function
  if ( !v5 )
  {
    sub_480C20(v4 + 20, (int)"%s...", a4);
    byte_DA9F60 = 0;
    return sub_53FFA0(v4, v5, a2, (float *)v4); // draw loading screen function
  }
  do
    v8 = off_BD8DE8[rand() % 92];
  while ( !v8 );
  sub_480C20(v4 + 20, (int)"%s...", (int)v8);
  dword_DA9F64 = v6;
  byte_DA9F60 = 1;
  return sub_53FFA0(v4, 92, a2, (float *)v4); // draw loading screen function
}
*/
/*

(*(void (__stdcall **)(float *, unsigned int))(v8 + 0xA0))(&v47, 0xFF000000); // CRender::DrawFilledRectangle()    t3dDeferQuad

(*(void (__stdcall **)(float *, float *, _DWORD, float *, float *, int))(*(_DWORD *)CRender__dword_169A598 + 0x88))( // CRender::DrawLine()    t3dDeferLine
          &v47,
          &v50,
          *(void **)((char *)&v40 + 3),
          v28,
          v29,
          v30);

*/