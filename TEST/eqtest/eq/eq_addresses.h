#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

uint32_t EQ_ADDRESS_CLIENT_VERSION_DATE = 0xABD314; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_DATE "May  7 2018"
#define EQ_SIZE_CLIENT_VERSION_DATE 12

uint32_t EQ_ADDRESS_CLIENT_VERSION_TIME = 0xABD308; // WinMain()    "Starting EverQuest (Built %s %s)"    CrashDetected()    "Client Version: %s %s\n"
#define EQ_STRING_CLIENT_VERSION_TIME "16:06:33"
#define EQ_SIZE_CLIENT_VERSION_TIME 9

uint32_t EQ_ADDRESS_AUTO_ATTACK    = 0xF09563; // uint8_t    // /attack
uint32_t EQ_ADDRESS_AUTO_FIRE      = 0xF09564; // uint8_t    // /autofire
uint32_t EQ_ADDRESS_AUTO_RUN       = 0xE6A910; // uint32_t
uint32_t EQ_ADDRESS_MOUSE_LOOK     = 0xE6A8F2; // uint8_t    // holding down right-click to look around
uint32_t EQ_ADDRESS_NET_STATUS     = 0xE6A8F5; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_FOG_DISTANCE_BEGIN    = 0xE6AD2C;    // float
uint32_t EQ_ADDRESS_FOG_DISTANCE_END      = 0xE6AD30;    // float
uint32_t EQ_ADDRESS_FAR_CLIP_PLANE        = 0xE6BD7C;    // uint32_t, values 0-20
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

uint32_t EQ_ADDRESS_POINTER_WINDOW_HWND = 0xF0CAEC; // HWND hWnd    // in IDA press G, jump to address: hWnd
/*
    PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/
/*
    _snprintf(v11, v10, "%s %s", &Dest, &v14);
    PostMessageA(hWnd, 0x4646u, 0x4246u, (LPARAM)v11);
*/

uint32_t EQ_ADDRESS_POINTER_StringTable    = 0xE5D07C; // pinstStringTable

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x89F620; // "%s (%d)"    "ERROR: String not found."

uint32_t EQ_ADDRESS_FUNCTION_build_token_string_PARAM    = 0x0; // calls StringTable__getString()
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

uint32_t EQ_ADDRESS_FUNCTION_CrashDetected    = 0x693930; // "Crash (char = %s, zone = %s)\n"    "Local Player's World location at time of crash: %f, %f, %f.\n"    "Gamestate at crash = %d\n"    "Crash Details: %s\n"
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

uint32_t EQ_ADDRESS_FUNCTION_CastRay    = 0x58CBA0; // called by CastRay2 function
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

uint32_t EQ_ADDRESS_FUNCTION_CastRay2    = 0x58CBF0; // CCollisionInfoLineSegmentVisibility::`vftable'
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

uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x615320; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x585550; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
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

uint32_t EQ_ADDRESS_FUNCTION_GetExecuteCmdIDByName    = 0x58A020; // "AUTORUN" xref    char[] array of about 520
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

uint32_t EQ_ADDRESS_FUNCTION_GetExecuteCmdNameByID    = 0x58A010; // "AUTORUN" xref    char[] array of about 520
/*
char *__cdecl GetExecuteCmdNameByID(int a1)
{
  return off_BE0088[a1];
}
*/

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager    = 0xF0B368; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x63CCA0; // "Your inventory is full!"
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x63CCC0; // "Incorrect Usage. Type /xtarget for correct usage."
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

uint32_t EQ_ADDRESS_FUNCTIOIN_EQPlayerManager__GetPlayerFromPartialName = 0x63CD50;

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_TARGET_SPAWN        = 0xE5D1FC; // pinstTarget    ExecuteCmd() case CLEAR_TARGET
uint32_t EQ_ADDRESS_POINTER_PLAYER_SPAWN        = 0xE5D1A8; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x630C50; // search for xref to autorun
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

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x644920; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
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
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot    = 0x6367F0; // "IT36" "IT159" "IT10758" "IT10742"

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager    = 0x16996C0; // pinstCXWndManager
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

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x905570; // "DoAllDrawing() failed\n"    GetTickCount()

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest    = 0xF0CC40; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone    = 0x5D3220; // "Initializing world."    "Zone initialized."
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

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x5E5F20; // "#%s %s"
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

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x4E10A0; // "You cannot purchase an item from yourself!"
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting    = 0x5CD270; // "%s <%s>"
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
uint32_t EQ_ADDRESS_POINTER_CDisplay    = 0xE5D410; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "
/*
CDisplay::CreatePlayerActor(*(float *)&a1, (int)dword_F20698, 0, 0, 1, 2, 1, 0);
*/

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x527310; // "%ldms"    "%0.2f%%"
/*
DrawNetStatus()
    sprintf(&Dest, "%0.2f%%", v8 * 100.0);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1, (unsigned __int16)a2, (void *)12);
    sprintf(&Dest, "%ldms", v16);
    CDisplay__WriteTextHD2(&Dest, (unsigned __int16)a1 + 64, (unsigned __int16)a2, (void *)12);
*/

uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x9014B0; // "MapSkin" "AtlasSkin"
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

uint32_t EQ_ADDRESS_POINTER_CPlayerWindow   = 0xDA8E6C; // "PlayerWindow"

uint32_t EQ_ADDRESS_POINTER_CBazaarSearchWnd    = 0xDA8E58; // "BazaarSearchWnd"

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__WndNotification    = 0x0; // not needed, can use VFTable index    "You cannot purchase an item from yourself!"    "9999999"

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__HandleBazaarMsg    = 0x6C9930; // "You successfully purchased %d %s(s) from %s."    "The item has been sent to your parcels."
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList    = 0x6C67A0;
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery    = 0x6C7030;
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

uint32_t EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem    = 0x6C7560;
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

uint32_t EQ_ADDRESS_POINTER_CBazaarConfirmationWnd    = 0xDA8BC0; // "BazaarConfirmationWnd"

uint32_t EQ_ADDRESS_FUNCTION_CBazaarConfirmationWnd__WndNotification    = 0x0; // not needed, can use VFTable index

// Trader window
uint32_t EQ_ADDRESS_POINTER_CBazaarWnd    = 0xDA8F54; // "BazaarWnd"

uint32_t EQ_ADDRESS_FUNCTION_CBazaarWnd__WndNotification    = 0x0; // not needed, can use VFTable index

uint32_t EQ_ADDRESS_POINTER_CCamera    = 0x0; // addresses for CCamera are calculated at run time

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // addresses for CCamera are calculated at run time

uint32_t EQ_ADDRESS_POINTER_CRender    = 0x169A608; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions
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