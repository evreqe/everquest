#pragma once

#include "eq_executecmd.h"
#include "eq_keys.h"

DWORD EQ_BASE_ADDRESS_VALUE    = 0x400000;

DWORD EQ_ADDRESS_AUTO_ATTACK    = 0xFB7A7B; // uint8_t
DWORD EQ_ADDRESS_AUTO_RUN       = 0xF33514; // uint32_t
DWORD EQ_ADDRESS_MOUSE_LOOK     = 0xF334F6; // uint8_t
/*
search for 1 and 0
*/

DWORD EQ_ADDRESS_POINTER_WINDOW_HWND = 0xFBD0C0; // HWND hWnd
/*
PostMessageA(hWnd, 0x4647u, 0x4247u, (LPARAM)v3);
*/

DWORD EQ_ADDRESS_FUNCTION_DrawNetStatus    = 0x5BBB00; // "%ldms" and "%0.2f%%"
DWORD EQ_ADDRESS_FUNCTION_ExecuteCmd       = 0x523550; // "ExecuteCmd has received a CMD_EXITGAME.\n" and "/%s %s" and "%c%s %s " and "help.html"
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
DWORD EQ_ADDRESS_POINTER_EQPlayerManager    = 0xFB90B0; // pinstSpawnManager

#define EQ_OFFSET_EQPlayerManager_FIRST_SPAWN    0x08
#define EQ_OFFSET_EQPlayerManager_LAST_SPAWN     0x0C

DWORD EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x5E4D00; // "Your inventory is full!"
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

DWORD EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x5E5160; // "Incorrect Usage. Type /xtarget for correct usage."
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
DWORD EQ_ADDRESS_POINTER_TARGET_SPAWN    = 0xF26020; // pinstTargetSpawn
DWORD EQ_ADDRESS_POINTER_PLAYER_SPAWN    = 0xF26008; // pinstCharSpawn    "Local Player's World location at time of crash: %f, %f, %f.\n"
/*
if ( dword_F21FE8 ) // PlayerSpawn
  {
    v28 = *((float *)dword_F21FE8 + 27);
    v29 = *((float *)dword_F21FE8 + 26);
    v30 = *((float *)dword_F21FE8 + 25);
    sub_8A22E0("Local Player's World location at time of crash: %f, %f, %f.\n", SLOBYTE(v30));
  }
*/

DWORD EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI    = 0x5D6AA0; // search for xref to autorun
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

DWORD EQ_ADDRESS_FOLLOW_DISTANCE_1    = 0xACBBE0; // 15.0f
DWORD EQ_ADDRESS_FOLLOW_DISTANCE_2    = 0xACBA84; // 30.0f
/*
EQPlayer__FollowPlayerAI()
*/

#define EQ_OFFSET_SPAWN_PREVIOUS         0x04     // uint32_t pointer
#define EQ_OFFSET_SPAWN_NEXT             0x08     // uint32_t pointer
#define EQ_OFFSET_SPAWN_LAST_NAME        0x38     // 32 bytes
#define EQ_OFFSET_SPAWN_Y                0x64     // float
#define EQ_OFFSET_SPAWN_X                0x68     // float
#define EQ_OFFSET_SPAWN_Z                0x6C     // float
#define EQ_OFFSET_SPAWN_HEADING          0x80     // float
#define EQ_OFFSET_SPAWN_NAME_NUMBERED    0xA4     // 64 bytes
#define EQ_OFFSET_SPAWN_NAME             0xE4     // 64 bytes
#define EQ_OFFSET_SPAWN_TYPE             0x125    // uint8_t
#define EQ_OFFSET_SPAWN_ID               0x148    // uint32_t
#define EQ_OFFSET_SPAWN_LEVEL            0x37D    // uint8_t
#define EQ_OFFSET_SPAWN_FOLLOW_SPAWN     0xF18    // uint32_t pointer, can change

#define EQ_SIZE_SPAWN_NAME         0x40 // 64 bytes
#define EQ_SIZE_SPAWN_LAST_NAME    0x20 // 32 bytes

#define EQ_SPAWN_TYPE_PLAYER    0x00
#define EQ_SPAWN_TYPE_NPC       0x01
#define EQ_SPAWN_TYPE_CORPSE    0x02

// class EQ_Character
DWORD EQ_ADDRESS_POINTER_PLAYER_CHARACTER    = 0xF25FF4; // psintCharData

DWORD EQ_ADDRESS_FUNCTION_EQ_Character__eqspa_movement_rate    = 0x450370; // "*** EXITING: I have completed camping." and "Sending up a MSG_ONVEHICLE for vehicle %s.\n"
/*
if ( v94 - *(_DWORD *)(v112 + 900) > 1000 )
    {
      v113 = v94 - *(_DWORD *)(v112 + 900);
      *(_DWORD *)(v112 + 900) = v94;
      if ( !*(_BYTE *)(*(_DWORD *)(v6 + 8) + 293) )
      {
        sub_463A90(v6);
        v114 = (*(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 4) + v6 + 4) + 64))(*(_DWORD *)(*(_DWORD *)(v6 + 4) + 4) + v6 + 4);
        sub_4B6C70(v114, v113);
        v115 = sub_44F860(99, 1, 0, 1, 1);
        v116 = v6;
        if ( v115 >= 0 )
        {
          v115 = sub_44F860(3, 1, 0, 1, 1);
          v116 = v6;
        }
        sub_450400(v116, v115); // EQ_Character__eqspa_movement_rate
        sub_5D9D20();
        HIBYTE(word_F2FB24) = 1;
        if ( (char *)dword_F21FFC != PlayerSpawn____dword_F21FE8 )
          LOBYTE(word_F2FB24) = 1;
        sub_5CC8F0(v222);
        sub_46D100(v6);
        sub_462FD0(v6);
        v117 = *(_DWORD *)(v6 + 8);
        if ( !v117 )
        {
          v135 = v215;
          v136 = v215 == 0;
          goto LABEL_478;
        }
*/

// class CXWndManager
DWORD EQ_ADDRESS_POINTER_CXWndManager    = 0x1733E90; // pinstCXWndManager

DWORD EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x8CB740; // "DoAllDrawing() failed\n"

// class CEverQuest
DWORD EQ_ADDRESS_POINTER_CEverQuest    = 0x10C5438; // pinstCEverQuest
/*
CEverQuest__InterpretCmd()
if ( *(_DWORD *)(dword_10C1418 + 1480) == 5 ) // gamestate == in-game
*/

#define EQ_OFFSET_CEverQuest_GAME_STATE    0x5C8 // 1480

#define EQ_GAME_STATE_IN_GAME 5

DWORD EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd    = 0x56D410; // "#%s %s"
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

DWORD EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat        = 0x476850;
/*
CEverQuest__InterpretCmd()
sub_4764B0(v9, v8, 273, 1, 1, 0); // CEverQuest__dsp_chat
*/

#define EQ_CHAT_TEXT_COLOR_YELLOW    15

// class CDisplay
DWORD EQ_ADDRESS_POINTER_CDisplay    = 0xF26038; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

#define EQ_OFFSET_CDisplay_CAMERA    0x118 // uint32_t pointer
#define EQ_OFFSET_CDisplay_TIMER     0x154 // uint32_t

#define EQ_OFFSET_CAMERA_FIELD_OF_VIEW                 0x04 // float
#define EQ_OFFSET_CAMERA_ASPECT_RATIO                  0x08 // float
#define EQ_OFFSET_CAMERA_UNKNOWN_0x0C                  0x0C // float, 0.0 to 1.0
#define EQ_OFFSET_CAMERA_DRAW_DISTANCE                 0x14 // float
#define EQ_OFFSET_CAMERA_SCREEN_WIDTH_HALF             0x38 // float
#define EQ_OFFSET_CAMERA_SCREEN_HEIGHT_HALF            0x3C // float
#define EQ_OFFSET_CAMERA_HEADING                       0xB0 // float
#define EQ_OFFSET_CAMERA_PITCH                         0xB4 // float
#define EQ_OFFSET_CAMERA_UNKNOWN_0xB8                  0xB8 // float, rotation?
#define EQ_OFFSET_CAMERA_Y                             0xBC // float
#define EQ_OFFSET_CAMERA_X                             0xC0 // float
#define EQ_OFFSET_CAMERA_Z                             0xC4 // float

DWORD EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x4C2620; // "%ldms" and "%0.2f%%"
/*
DrawNetStatus()
((void (__cdecl *)(char *, _DWORD, _DWORD, signed int))sub_4C2200)(
      &v11,
      (unsigned __int16)a1,
      (unsigned __int16)a2,
      12)
*/

#define EQ_DRAW_TEXT_COLOR_BLACK         0  // ARGB 0xFF000000
#define EQ_DRAW_TEXT_COLOR_DEFAULT       1  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DARK_GREEN    2  // ARGB 0xFF008000
#define EQ_DRAW_TEXT_COLOR_DEFAULT_2     3  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DARK_BLUE     4  // ARGB 0xFF000080
#define EQ_DRAW_TEXT_COLOR_PINK          5  // ARGB 0xFFF000F0
#define EQ_DRAW_TEXT_COLOR_DARK_GRAY     6  // ARGB 0xFF808080
#define EQ_DRAW_TEXT_COLOR_WHITE_2       7  // ARGB 0xFFE0E0E0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_3     8  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_DEFAULT_4     9  // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_WHITE         10 // ARGB 0xFFF0F0F0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_5     11 // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_GRAY          12 // ARGB 0xFFA0A0A0
#define EQ_DRAW_TEXT_COLOR_RED           13 // ARGB 0xFFF00000
#define EQ_DRAW_TEXT_COLOR_GREEN         14 // ARGB 0xFF00F000
#define EQ_DRAW_TEXT_COLOR_YELLOW        15 // ARGB 0xFFF0F000
#define EQ_DRAW_TEXT_COLOR_BLUE          16 // ARGB 0xFF0000F0
#define EQ_DRAW_TEXT_COLOR_BLUE_2        17 // ARGB 0xFF0000AF
#define EQ_DRAW_TEXT_COLOR_TEAL          18 // ARGB 0xFF00F0F0
#define EQ_DRAW_TEXT_COLOR_DEFAULT_6     19 // ARGB 0xFF606060
#define EQ_DRAW_TEXT_COLOR_BLACK_2       20 // ARGB 0xFF000000
