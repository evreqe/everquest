#pragma once

#include "eq_offsets.h"
#include "eq_sizes.h"

#include <string>
#include <unordered_map>

#include <cstdint>

const char* EQ_STRING_WINDOW_TITLE                = "EverQuest";
const char* EQ_STRING_PROCESS_NAME                = "eqgame.exe";
const char* EQ_STRING_GRAPHICS_DLL_NAME           = "EQGraphicsDX9.dll";
const char* EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE = "eqgraphicsdx9.dll";

#define EQ_BASE_ADDRESS 0x00400000

#define EQ_GRAPHICS_DLL_POINTER_BASE_ADDRESS 0x00B112A8 // EQGraphicsDX9.DLL

#define EQ_GRAPHICS_DLL_OFFSET_FRAMES_PER_SECOND 0x173CB0 // float

#define EQ_GRAPHICS_DLL_OFFSET_DrawLine    0x7A850
#define EQ_GRAPHICS_DLL_OFFSET_DrawQuad    0x7A560

#define EQ_GRAPHICS_DLL_ORDINAL_DrawLine    0x84
#define EQ_GRAPHICS_DLL_ORDINAL_DrawQuad    0x9C

#define EQ_WINDOW_HWND      0x00AD6974 // uint32_t
#define EQ_WINDOW_WIDTH     0x00AD6950 // uint32_t
#define EQ_WINDOW_HEIGHT    0x00AD6954 // uint32_t

#define EQ_EXIT_STATUS 0x00A60A03 // uint8_t ; 0 = not exiting, 1 or 2 = exiting

#define EQ_RESET_DEVICE_VALUE 0x00AD6DB4

#define EQ_BOOL_AUTO_ATTACK         0x00AC1196 // uint8_t
#define EQ_BOOL_AUTO_FIRE           0x00AC1197 // uint8_t
#define EQ_BOOL_AUTO_RUN            0x00A603FC // uint32_t
#define EQ_BOOL_NET_STATUS          0x00A603E1 // uint8_t
#define EQ_BOOL_SAFELOCK            0x00A96858 // uint8_t
#define EQ_BOOL_SCREENSHOT          0x00A609A1 // uint8_t ; set to 1 to force the game to take a screenshot
#define EQ_BOOL_INVITED_TO_GROUP    0x00A96858 // uint8_t

#define EQ_BOOL_KEYBOARD_SHIFT            0x00A609B0 // uint8_t
#define EQ_BOOL_KEYBOARD_CONTROL          0x00A609B1 // uint8_t
#define EQ_BOOL_KEYBOARD_ALT              0x00A609B2 // uint8_t
#define EQ_BOOL_KEYBOARD_LEFT_SHIFT       0x00A609B3 // uint8_t
#define EQ_BOOL_KEYBOARD_LEFT_CONTROL     0x00A609B4 // uint8_t
#define EQ_BOOL_KEYBOARD_LEFT_ALT         0x00A609B5 // uint8_t
#define EQ_BOOL_KEYBOARD_RIGHT_SHIFT      0x00A609B6 // uint8_t
#define EQ_BOOL_KEYBOARD_RIGHT_CONTROL    0x00A609B7 // uint8_t
#define EQ_BOOL_KEYBOARD_RIGHT_ALT        0x00A609B8 // uint8_t

#define EQ_POINTER_EQGraphicsDLL              0x00B112BC

#define EQ_POINTER_0x00B112C0                 0x00B112C0

#define EQ_POINTER_StringTable                0x00A4259C // pinstStringTable
#define EQ_POINTER_CDisplay                   0x00A42628
#define EQ_POINTER_CEverQuest                 0x00AD6DB8
#define EQ_POINTER_CSidlManager               0x00B10A40
#define EQ_POINTER_CTextOverlay               0x00877500
#define EQ_POINTER_CXWndManager               0x00B10A38
#define EQ_POINTER_EQ_Character               0x00A425E4 // pinstCharData
#define EQ_POINTER_EQPlayerManager            0x00AD3A0C // pinstSpawnManager

#define EQ_POINTER_CAAWnd                     0x00990BD4
#define EQ_POINTER_CBankWnd                   0x00990C48
#define EQ_POINTER_CBazaarWnd                 0x00990C68
#define EQ_POINTER_CBazaarSearchWnd           0x00990C6C
#define EQ_POINTER_CGiveWnd                   0x00990C70
#define EQ_POINTER_CHotButtonWnd              0x00B01C0C
#define EQ_POINTER_CHotButtonWnd1             0x00B01C0C
#define EQ_POINTER_CHotButtonWnd2             0x00B01C10
#define EQ_POINTER_CHotButtonWnd3             0x00B01C14
#define EQ_POINTER_CHotButtonWnd4             0x00B01C18
#define EQ_POINTER_CInspectWnd                0x00990C78
#define EQ_POINTER_CInventoryWnd              0x00990C44
#define EQ_POINTER_CLootWnd                   0x00990C50
#define EQ_POINTER_CMapViewWnd                0x00990C0C
#define EQ_POINTER_CMerchantWnd               0x00990C5C
#define EQ_POINTER_CSelectorWnd               0x00990C64
#define EQ_POINTER_CSkillsWnd                 0x00990BB4
#define EQ_POINTER_CSkillsSelectWnd           0x00990BB8
#define EQ_POINTER_CSocialEditWnd             0x00990C7C
#define EQ_POINTER_CSpellBookWnd              0x00990C40
#define EQ_POINTER_CTextEntryWnd              0x00990C90
#define EQ_POINTER_CTrackingWnd               0x00990C74
#define EQ_POINTER_CTradeWnd                  0x00990C60
#define EQ_POINTER_CTrainWnd                  0x00990BB0

#define EQ_POINTER_SPAWN_MANAGER              0x00AD3A0C // pinstSpawnManager
#define EQ_POINTER_SPELL_MANAGER              0x00AD3A90 // pinstSpellManager
#define EQ_POINTER_SWITCH_MANAGER             0x00A40704 // pinstSwitchManager (doors)
#define EQ_POINTER_CONTAINER_MANAGER          0x00990CD8 // psintCContainerMgr (bags)

#define EQ_POINTER_CHAR_INFO                  0x00A425E4 // pinstCharData

#define EQ_POINTER_SPAWN_INFO_PLAYER          0x00A4260C // pinstCharSpawn
#define EQ_POINTER_SPAWN_INFO_TARGET          0x00A42610 // pinstTarget

#define EQ_POINTER_GROUND_SPAWN_INFO_FIRST    0x00A425C8 // pinstEQItemList

#define EQ_POINTER_GROUP_INFO                 0x00A40ABE // pinstGroup

#define EQ_GUILDS 0x00A42640

#define EQ_EXECUTECMD_LIST 0x00851940

#define EQ_FONT_INFO_2_COLOR_ADDRESS    0x0046D8FF
#define EQ_FONT_INFO_2_COLOR_VALUE      0xFF000000

#define EQ_ZONE_INFO_CHARACTER_NAME    0x00A6057C // STRING [0x40]
#define EQ_ZONE_INFO_SHORT_NAME        0x00A605BC // STRING [0x20]
#define EQ_ZONE_INFO_LONG_NAME         0x00A6063C // STRING [0x80]
#define EQ_ZONE_INFO_FOG_MIN_CLIP      0x00A60760 // float
#define EQ_ZONE_INFO_FOG_MAX_CLIP      0x00A60770 // float
#define EQ_ZONE_INFO_GRAVITY           0x00A60780 // float
#define EQ_ZONE_INFO_MIN_CLIP          0x00A607E0 // float
#define EQ_ZONE_INFO_MAX_CLIP          0x00A607E4 // float

#define EQ_FUNCTION_Exit 0x004B06B0 // called by the "/exit" command

#define EQ_FUNCTION_ResetDevice     0x00561790
#define EQ_FUNCTION_WindowResize    0x00561840

#define EQ_FUNCTION_CastRay                      0x004C3E40 // __CastRay
#define EQ_FUNCTION_CXWnd_DrawColoredRect        0x006DBB30
#define EQ_FUNCTION_DrawNetStatus                0x00512280
#define EQ_FUNCTION_ExecuteCommand               0x004A5580 // __ExecuteCmd
#define EQ_FUNCTION_GetMeleeRange                0x004AAA20 // __get_melee_range
#define EQ_FUNCTION_GetBearing                   0x004B7BF0 // __get_bearing
#define EQ_FUNCTION_Screenshot                   0x00469CC0
#define EQ_FUNCTION_SetTarget                    0x004B2F90
#define EQ_FUNCTION_OpenAllContainers            0x005CF1A0
#define EQ_FUNCTION_CloseAllContainers           0x005CF200
#define EQ_FUNCTION_ReceivedGroupInvite          0x004E4070
#define EQ_FUNCTION_AcceptGroupInvite            0x004E4310
#define EQ_FUNCTION_InviteToGroup                0x004E3CD0
#define EQ_FUNCTION_UpdateLight                  0x004C0F70

#define EQ_FUNCTION_EQ_Guilds__GetGuildNameById    0x00421930 // GetPlayerGuildName

#define EQ_FUNCTION_CDisplay__CreatePlayerActor     0x0046E0B0
#define EQ_FUNCTION_CDisplay__DeleteActor           0x0046F2F0
#define EQ_FUNCTION_CDisplay__SetViewActor          0x0046DD30
#define EQ_FUNCTION_CDisplay__SetViewActorByName    0x0046F3E0
#define EQ_FUNCTION_CDisplay__WriteTextHD2          0x0046D880

#define EQ_FUNCTION_CEverQuest__dsp_chat                   0x004DCD60
#define EQ_FUNCTION_CEverQuest__dsp_chat__2                0x004DCF30
#define EQ_FUNCTION_CEverQuest__EnterZone                  0x004F2420
#define EQ_FUNCTION_CEverQuest__GetBodyTypeDesc            0x004D4660
#define EQ_FUNCTION_CEverQuest__GetClassDesc               0x004D3DC0
#define EQ_FUNCTION_CEverQuest__GetClassThreeLetterCode    0x004D43C0
#define EQ_FUNCTION_CEverQuest__GetDeityDesc               0x004D4CD0
#define EQ_FUNCTION_CEverQuest__GetRaceDesc                0x004D4CA0
#define EQ_FUNCTION_CEverQuest__InterpretCmd               0x004DD7C0
#define EQ_FUNCTION_CEverQuest__LMouseUp                   0x004F3200
#define EQ_FUNCTION_CEverQuest__RMouseUp                   0x004F2A20
#define EQ_FUNCTION_CEverQuest__MoveToZone                 0x004FABE0
#define EQ_FUNCTION_CEverQuest__SetGameState               0x004D7890
#define EQ_FUNCTION_CEverQuest__StartCasting               0x004E1280

#define EQ_FUNCTION_CHotButtonWnd__DoHotButton    0x005C5E80

#define EQ_FUNCTION_CLootWnd__Deactivate         0x005EAA50
#define EQ_FUNCTION_CLootWnd__RequestLootSlot    0x005EB430

#define EQ_FUNCTION_CMapViewWnd__DrawMap         0x005F7320
#define EQ_FUNCTION_CMapViewWnd__CMapViewWnd     0x005F8D60
#define EQ_FUNCTION_CMapViewWnd__dCMapViewWnd    0x005F9A50

#define EQ_FUNCTION_MapViewMap__AddLabel          0x005F7250
#define EQ_FUNCTION_MapViewMap__Clear             0x005F4430
#define EQ_FUNCTION_MapViewMap__MoveLabel         0x005F4590
#define EQ_FUNCTION_MapViewMap__RemoveLabel       0x005F4530
#define EQ_FUNCTION_MapViewMap__Save              0x005F6B10
#define EQ_FUNCTION_MapViewMap__SaveEx            0x005F4E00
#define EQ_FUNCTION_MapViewMap__SetZoneExtents    0x005F4040
#define EQ_FUNCTION_MapViewMap__SetZoom           0x005F4120

#define EQ_FUNCTION_CTextEntryWnd__Activate    0x00649060

#define EQ_FUNCTION_CTextOverlay__DisplayText     0x0041DB10

#define EQ_FUNCTION_EQ_Character__eqspa_movement_rate    0x0042D970
#define EQ_FUNCTION_EQ_Character__UseSkill               0x00441FC0

#define EQ_FUNCTION_EQPlayer__EQPlayer            0x005276F0
#define EQ_FUNCTION_EQPlayer__ChangeHeight        0x00530900
#define EQ_FUNCTION_EQPlayer__ChangePosition      0x0052E120
#define EQ_FUNCTION_EQPlayer__do_change_form      0x00527E60
#define EQ_FUNCTION_EQPlayer__FacePlayer          0x0052C170
#define EQ_FUNCTION_EQPlayer__SetRace             0x0052BE50
#define EQ_FUNCTION_EQPlayer__UpdateAppearance    0x00523D20

#define EQ_FUNCTION_EQPlayerManager__GetSpawnByID      0x5287B0
#define EQ_FUNCTION_EQPlayerManager__GetSpawnByName    0x528990

#define EQ_FUNCTION_EQSwitch__ChangeState    0x004D0430

#define EQ_FUNCTION_StringTable__getString    0x0067C470

#define EQ_MAX_FOREGROUND_FPS 0x00A61B9C // uint32_t
#define EQ_MAX_BACKGROUND_FPS 0x00A61BA0 // uint32_t

#define EQ_MAX_FOREGROUND_FPS_VALUE_MIN 10
#define EQ_MAX_FOREGROUND_FPS_VALUE_MAX 100

#define EQ_MAX_BACKGROUND_FPS_VALUE_MIN 9
#define EQ_MAX_BACKGROUND_FPS_VALUE_MAX 100

#define EQ_SWIM_SPEED_MULTIPLIER 0x0085AFC0 // float

#define EQ_CAMERA_VIEW 0x00990CF0 // uint32_t

#define EQ_CAMERA_VIEW_FIRST_PERSON             0
#define EQ_CAMERA_VIEW_THIRD_PERSON_OVERHEAD    1
#define EQ_CAMERA_VIEW_THIRD_PERSON2            2
#define EQ_CAMERA_VIEW_THIRD_PERSON3            3
#define EQ_CAMERA_VIEW_THIRD_PERSON4            4
#define EQ_CAMERA_VIEW_THIRD_PERSON_CHASE       5

#define EQ_DRAW_DISTANCE_MAX 0x00A607E4 // float

#define EQ_SPAWN_TYPE_PLAYER           0
#define EQ_SPAWN_TYPE_NPC              1
#define EQ_SPAWN_TYPE_NPC_CORPSE       2
#define EQ_SPAWN_TYPE_PLAYER_CORPSE    3

#define EQ_DOOR_STATE_OPEN      2
#define EQ_DOOR_STATE_CLOSED    3

#define EQ_GAME_STATE_CHARACTER_SELECT    1
#define EQ_GAME_STATE_ZONING              3
#define EQ_GAME_STATE_ZONING2             4
#define EQ_GAME_STATE_IN_GAME             5
#define EQ_GAME_STATE_LOADING_SCREEN      6
#define EQ_GAME_STATE_ZONING3             7

#define EQ_TEXT_COLOR_BLACK          0x00
#define EQ_TEXT_COLOR_GRAY           0x01
#define EQ_TEXT_COLOR_GREEN          0x02
#define EQ_TEXT_COLOR_GRAY2          0x03
#define EQ_TEXT_COLOR_BLUE           0x04
#define EQ_TEXT_COLOR_PINK           0x05
#define EQ_TEXT_COLOR_GRAY3          0x06
#define EQ_TEXT_COLOR_WHITE          0x07
#define EQ_TEXT_COLOR_GRAY4          0x08
#define EQ_TEXT_COLOR_GRAY5          0x09
#define EQ_TEXT_COLOR_WHITE2         0x0A
#define EQ_TEXT_COLOR_GRAY6          0x0B
#define EQ_TEXT_COLOR_LIGHT_GRAY     0x0C
#define EQ_TEXT_COLOR_RED            0x0D
#define EQ_TEXT_COLOR_LIGHT_GREEN    0x0E
#define EQ_TEXT_COLOR_YELLOW         0x0F
#define EQ_TEXT_COLOR_LIGHT_BLUE     0x10
#define EQ_TEXT_COLOR_GRAY7          0x11
#define EQ_TEXT_COLOR_CYAN           0x12
#define EQ_TEXT_COLOR_GRAY8          0x13
#define EQ_TEXT_COLOR_BLACK2         0x14

#define EQ_TOOLTIP_COLOR 0xC8000040 // ARGB color

// EQPlayer::ChangePosition(uint8_t standingState)
#define EQ_STANDING_STATE_STANDING    0x64
#define EQ_STANDING_STATE_FROZEN      0x66 // stunned / mesmerized / feared ; You lose control of yourself!
#define EQ_STANDING_STATE_LOOTING     0x69 // looting or binding wounds
#define EQ_STANDING_STATE_SITTING     0x6E
#define EQ_STANDING_STATE_DUCKING     0x6F // crouching
#define EQ_STANDING_STATE_FEIGNED     0x73 // feign death
#define EQ_STANDING_STATE_DEAD        0x78

#define EQ_ANIMATION_WALKING          17
#define EQ_ANIMATION_RUNNING          18
#define EQ_ANIMATION_JUMPING          19
#define EQ_ANIMATION_DUCKING          24
#define EQ_ANIMATION_IDLE_ANIMATED    26
#define EQ_ANIMATION_IDLE             32
#define EQ_ANIMATION_SITTING          33
#define EQ_ANIMATION_TURNING          34

#define EQ_ITEM_TYPE_CONTAINER          0x7900
#define EQ_ITEM_TYPE_CONTAINER_PLAIN    0x7953

#define EQ_GENDER_MALE       0x00
#define EQ_GENDER_FEMALE     0x01
#define EQ_GENDER_NEUTRAL    0x02

#define EQ_RACE_UNKNOWN          0
#define EQ_RACE_HUMAN            1
#define EQ_RACE_BARBARIAN        2
#define EQ_RACE_ERUDITE          3
#define EQ_RACE_WOOD_ELF         4
#define EQ_RACE_HIGH_ELF         5
#define EQ_RACE_DARK_ELF         6
#define EQ_RACE_HALF_ELF         7
#define EQ_RACE_DWARF            8
#define EQ_RACE_TROLL            9
#define EQ_RACE_OGRE             10
#define EQ_RACE_HALFLING         11
#define EQ_RACE_GNOME            12
#define EQ_RACE_INVISIBLE_MAN    127
#define EQ_RACE_IKSAR            128
#define EQ_RACE_VAH_SHIR         130
#define EQ_RACE_FROGLOK          330
#define EQ_RACE_DRAKKIN          522
//--------------------------------------------------
#define EQ_RACE_WEREWOLF         14
#define EQ_RACE_GOLEM            17
#define EQ_RACE_CYCLOPS          18
#define EQ_RACE_VENRIL_SATHIR    20
#define EQ_RACE_SOLUSEK_RO       58
#define EQ_RACE_SKELETON         60
#define EQ_RACE_TUNARE           62
#define EQ_RACE_RALLOS_ZEK       66
#define EQ_RACE_CAZIC_THULE      96
#define EQ_RACE_INNORUK          123
#define EQ_RACE_CHOKADAI         356
#define EQ_RACE_SKELETON2        367
#define EQ_RACE_SKELETON3        484
#define EQ_RACE_BOAT             550
#define EQ_RACE_BOAT2            551
#define EQ_RACE_BOAT3            552
//--------------------------------------------------
#define EQ_RACE_MIN              1
#define EQ_RACE_MAX              627

#define EQ_CLASS_UNKNOWN         0
#define EQ_CLASS_WARRIOR         1
#define EQ_CLASS_CLERIC          2
#define EQ_CLASS_PALADIN         3
#define EQ_CLASS_RANGER          4
#define EQ_CLASS_SHADOWKNIGHT    5
#define EQ_CLASS_DRUID           6
#define EQ_CLASS_MONK            7
#define EQ_CLASS_BARD            8
#define EQ_CLASS_ROGUE           9
#define EQ_CLASS_SHAMAN          10
#define EQ_CLASS_NECROMANCER     11
#define EQ_CLASS_WIZARD          12
#define EQ_CLASS_MAGICIAN        13
#define EQ_CLASS_ENCHANTER       14
#define EQ_CLASS_BEASTLORD       15
#define EQ_CLASS_BANKER          16

#define EQ_EXECUTECMD_AUTORUN                            0
#define EQ_EXECUTECMD_JUMP                               1
#define EQ_EXECUTECMD_FORWARD                            2
#define EQ_EXECUTECMD_BACK                               3
#define EQ_EXECUTECMD_RIGHT                              4
#define EQ_EXECUTECMD_LEFT                               5
#define EQ_EXECUTECMD_STRAFE_LEFT                        6
#define EQ_EXECUTECMD_STRAFE_RIGHT                       7
#define EQ_EXECUTECMD_MOUSELOOK                          8
#define EQ_EXECUTECMD_MOUSELOOK_ENGAGE                   9
#define EQ_EXECUTECMD_AUTOPRIM                           10
#define EQ_EXECUTECMD_CONSIDER                           11
#define EQ_EXECUTECMD_DUCK                               12
#define EQ_EXECUTECMD_HAIL                               13
#define EQ_EXECUTECMD_INVENTORY                          14
#define EQ_EXECUTECMD_TELL                               15
#define EQ_EXECUTECMD_USE                                16
#define EQ_EXECUTECMD_PITCHUP                            17
#define EQ_EXECUTECMD_PITCHDOWN                          18
#define EQ_EXECUTECMD_CENTERVIEW                         19
#define EQ_EXECUTECMD_ZOOMIN                             20
#define EQ_EXECUTECMD_ZOOMOUT                            21
#define EQ_EXECUTECMD_TOGGLECAM                          22
#define EQ_EXECUTECMD_FULLSCREEN                         23
#define EQ_EXECUTECMD_TARGETME                           24
#define EQ_EXECUTECMD_PARTY1                             25
#define EQ_EXECUTECMD_PARTY2                             26
#define EQ_EXECUTECMD_PARTY3                             27
#define EQ_EXECUTECMD_PARTY4                             28
#define EQ_EXECUTECMD_PARTY5                             29
#define EQ_EXECUTECMD_TARGETPC                           30
#define EQ_EXECUTECMD_CYCLEPCTARGETS                     31
#define EQ_EXECUTECMD_TARGETNPC                          32
#define EQ_EXECUTECMD_CYCLENPCTARGETS                    33
#define EQ_EXECUTECMD_TARGETCORPSE                       34
#define EQ_EXECUTECMD_CYCLECORPSETARGETS                 35
#define EQ_EXECUTECMD_NETSTAT                            36
#define EQ_EXECUTECMD_HOT1_1                             37
#define EQ_EXECUTECMD_HOT1_2                             38
#define EQ_EXECUTECMD_HOT1_3                             39
#define EQ_EXECUTECMD_HOT1_4                             40
#define EQ_EXECUTECMD_HOT1_5                             41
#define EQ_EXECUTECMD_HOT1_6                             42
#define EQ_EXECUTECMD_HOT1_7                             43
#define EQ_EXECUTECMD_HOT1_8                             44
#define EQ_EXECUTECMD_HOT1_9                             45
#define EQ_EXECUTECMD_HOT1_10                            46
#define EQ_EXECUTECMD_HOT2_1                             47
#define EQ_EXECUTECMD_HOT2_2                             48
#define EQ_EXECUTECMD_HOT2_3                             49
#define EQ_EXECUTECMD_HOT2_4                             50
#define EQ_EXECUTECMD_HOT2_5                             51
#define EQ_EXECUTECMD_HOT2_6                             52
#define EQ_EXECUTECMD_HOT2_7                             53
#define EQ_EXECUTECMD_HOT2_8                             54
#define EQ_EXECUTECMD_HOT2_9                             55
#define EQ_EXECUTECMD_HOT2_10                            56
#define EQ_EXECUTECMD_HOT3_1                             57
#define EQ_EXECUTECMD_HOT3_2                             58
#define EQ_EXECUTECMD_HOT3_3                             59
#define EQ_EXECUTECMD_HOT3_4                             60
#define EQ_EXECUTECMD_HOT3_5                             61
#define EQ_EXECUTECMD_HOT3_6                             62
#define EQ_EXECUTECMD_HOT3_7                             63
#define EQ_EXECUTECMD_HOT3_8                             64
#define EQ_EXECUTECMD_HOT3_9                             65
#define EQ_EXECUTECMD_HOT3_10                            66
#define EQ_EXECUTECMD_HOT4_1                             67
#define EQ_EXECUTECMD_HOT4_2                             68
#define EQ_EXECUTECMD_HOT4_3                             69
#define EQ_EXECUTECMD_HOT4_4                             70
#define EQ_EXECUTECMD_HOT4_5                             71
#define EQ_EXECUTECMD_HOT4_6                             72
#define EQ_EXECUTECMD_HOT4_7                             73
#define EQ_EXECUTECMD_HOT4_8                             74
#define EQ_EXECUTECMD_HOT4_9                             75
#define EQ_EXECUTECMD_HOT4_10                            76
#define EQ_EXECUTECMD_HOTPAGE1_1                         77
#define EQ_EXECUTECMD_HOTPAGE1_2                         78
#define EQ_EXECUTECMD_HOTPAGE1_3                         79
#define EQ_EXECUTECMD_HOTPAGE1_4                         80
#define EQ_EXECUTECMD_HOTPAGE1_5                         81
#define EQ_EXECUTECMD_HOTPAGE1_6                         82
#define EQ_EXECUTECMD_HOTPAGE1_7                         83
#define EQ_EXECUTECMD_HOTPAGE1_8                         84
#define EQ_EXECUTECMD_HOTPAGE1_9                         85
#define EQ_EXECUTECMD_HOTPAGE1_10                        86
#define EQ_EXECUTECMD_HOTPAGE2_1                         87
#define EQ_EXECUTECMD_HOTPAGE2_2                         88
#define EQ_EXECUTECMD_HOTPAGE2_3                         89
#define EQ_EXECUTECMD_HOTPAGE2_4                         90
#define EQ_EXECUTECMD_HOTPAGE2_5                         91
#define EQ_EXECUTECMD_HOTPAGE2_6                         92
#define EQ_EXECUTECMD_HOTPAGE2_7                         93
#define EQ_EXECUTECMD_HOTPAGE2_8                         94
#define EQ_EXECUTECMD_HOTPAGE2_9                         95
#define EQ_EXECUTECMD_HOTPAGE2_10                        96
#define EQ_EXECUTECMD_HOTPAGE3_1                         97
#define EQ_EXECUTECMD_HOTPAGE3_2                         98
#define EQ_EXECUTECMD_HOTPAGE3_3                         99
#define EQ_EXECUTECMD_HOTPAGE3_4                         100
#define EQ_EXECUTECMD_HOTPAGE3_5                         101
#define EQ_EXECUTECMD_HOTPAGE3_6                         102
#define EQ_EXECUTECMD_HOTPAGE3_7                         103
#define EQ_EXECUTECMD_HOTPAGE3_8                         104
#define EQ_EXECUTECMD_HOTPAGE3_9                         105
#define EQ_EXECUTECMD_HOTPAGE3_10                        106
#define EQ_EXECUTECMD_HOTPAGE4_1                         107
#define EQ_EXECUTECMD_HOTPAGE4_2                         108
#define EQ_EXECUTECMD_HOTPAGE4_3                         109
#define EQ_EXECUTECMD_HOTPAGE4_4                         110
#define EQ_EXECUTECMD_HOTPAGE4_5                         111
#define EQ_EXECUTECMD_HOTPAGE4_6                         112
#define EQ_EXECUTECMD_HOTPAGE4_7                         113
#define EQ_EXECUTECMD_HOTPAGE4_8                         114
#define EQ_EXECUTECMD_HOTPAGE4_9                         115
#define EQ_EXECUTECMD_HOTPAGE4_10                        116
#define EQ_EXECUTECMD_CAST1                              117
#define EQ_EXECUTECMD_CAST2                              118
#define EQ_EXECUTECMD_CAST3                              119
#define EQ_EXECUTECMD_CAST4                              120
#define EQ_EXECUTECMD_CAST5                              121
#define EQ_EXECUTECMD_CAST6                              122
#define EQ_EXECUTECMD_CAST7                              123
#define EQ_EXECUTECMD_CAST8                              124
#define EQ_EXECUTECMD_CAST9                              125
#define EQ_EXECUTECMD_CAST10                             126
#define EQ_EXECUTECMD_REPLY                              127
#define EQ_EXECUTECMD_CYCLEREPLY                         128
#define EQ_EXECUTECMD_CYCLEREPLY_BACK                    129
#define EQ_EXECUTECMD_BACKDROP                           130
#define EQ_EXECUTECMD_TOGGLETARGET                       131
#define EQ_EXECUTECMD_SPELLBOOK                          132
#define EQ_EXECUTECMD_ABILITIES                          133
#define EQ_EXECUTECMD_COMBAT                             134
#define EQ_EXECUTECMD_SOCIALS                            135
#define EQ_EXECUTECMD_MAIN                               136
#define EQ_EXECUTECMD_WHO                                137
#define EQ_EXECUTECMD_INVITE_FOLLOW                      138
#define EQ_EXECUTECMD_DISBAND                            139
#define EQ_EXECUTECMD_CAMP                               140
#define EQ_EXECUTECMD_SIT_STAND                          141
#define EQ_EXECUTECMD_RUN_WALK                           142
#define EQ_EXECUTECMD_CLIP_IN                            143
#define EQ_EXECUTECMD_CLIP_OUT                           144
#define EQ_EXECUTECMD_VOICE_ON                           145
#define EQ_EXECUTECMD_SCREENCAP                          146
#define EQ_EXECUTECMD_HISTORY_UP                         147
#define EQ_EXECUTECMD_HISTORY_DOWN                       148
#define EQ_EXECUTECMD_PAGEUP                             149
#define EQ_EXECUTECMD_PAGEDOWN                           150
#define EQ_EXECUTECMD_CMDMODE_SAY                        151
#define EQ_EXECUTECMD_CMDMODE_EMOTE                      152
#define EQ_EXECUTECMD_LOCK_WINDOWS                       153
#define EQ_EXECUTECMD_TOGGLE_PLAYERWIN                   154
#define EQ_EXECUTECMD_TOGGLE_PARTYWIN                    155
#define EQ_EXECUTECMD_TOGGLE_TARGETWIN                   156
#define EQ_EXECUTECMD_TOGGLE_SPELLSWIN                   157
#define EQ_EXECUTECMD_TOGGLE_BUFFWIN                     158
#define EQ_EXECUTECMD_TOGGLE_HOTBOX1WIN                  159
#define EQ_EXECUTECMD_TOGGLE_HOTBOX2WIN                  160
#define EQ_EXECUTECMD_TOGGLE_HOTBOX3WIN                  161
#define EQ_EXECUTECMD_TOGGLE_HOTBOX4WIN                  162
#define EQ_EXECUTECMD_TOGGLE_CHATWIN                     163
#define EQ_EXECUTECMD_TOGGLE_MAILWIN                     164
#define EQ_EXECUTECMD_TOGGLE_MAILCOMPWIN                 165
#define EQ_EXECUTECMD_TOGGLE_MAINMENUWIN                 166
#define EQ_EXECUTECMD_TOGGLE_ALTADVWIN                   167
#define EQ_EXECUTECMD_TOGGLE_BAZAARWIN                   168
#define EQ_EXECUTECMD_RTARGET                            169
#define EQ_EXECUTECMD_TOGGLE_FRIENDSWIN                  170
#define EQ_EXECUTECMD_TOGGLE_PETINFOWIN                  171
#define EQ_EXECUTECMD_TOGGLE_OPTIONSWIN                  172
#define EQ_EXECUTECMD_TOGGLE_HELPWIN                     173
#define EQ_EXECUTECMD_TOGGLE_SELECTORWIN                 174
#define EQ_EXECUTECMD_TOGGLE_VIDEOMODEWIN                175
#define EQ_EXECUTECMD_TOGGLE_BAZAARSEARCHWIN             176
#define EQ_EXECUTECMD_TOGGLE_COMPASSWIN                  177
#define EQ_EXECUTECMD_TOGGLE_RAIDWIN                     178
#define EQ_EXECUTECMD_TOGGLE_MUSICPLAYERWIN              179
#define EQ_EXECUTECMD_FORWARD_CAM                        180
#define EQ_EXECUTECMD_BACK_CAM                           181
#define EQ_EXECUTECMD_RIGHT_CAM                          182
#define EQ_EXECUTECMD_LEFT_CAM                           183
#define EQ_EXECUTECMD_PITCHUP_CAM                        184
#define EQ_EXECUTECMD_PITCHDOWN_CAM                      185
#define EQ_EXECUTECMD_TOGGLE_JOURNAL                     186
#define EQ_EXECUTECMD_TOGGLE_SDBUFFWIN                   187
#define EQ_EXECUTECMD_RELEASE_MOUSE_CURSOR               188
#define EQ_EXECUTECMD_TOGGLE_STORYWIN                    189
#define EQ_EXECUTECMD_TOGGLE_MAPWIN                      190
#define EQ_EXECUTECMD_TOGGLE_GUILDMGMTWIN                191
#define EQ_EXECUTECMD_TOGGLE_FELLOWSHIPWIN               192
#define EQ_EXECUTECMD_TOGGLE_LFGWIN                      193
#define EQ_EXECUTECMD_TOGGLETWOTARGETS                   194
#define EQ_EXECUTECMD_TOGGLE_CONTEXTMENUS                195
#define EQ_EXECUTECMD_FIRST_PERSON_CAMERA                196
#define EQ_EXECUTECMD_OVERHEAD_CAMERA                    197
#define EQ_EXECUTECMD_CHASE_CAMERA                       198
#define EQ_EXECUTECMD_USER1_CAMERA                       199
#define EQ_EXECUTECMD_USER2_CAMERA                       200
#define EQ_EXECUTECMD_TETHER_CAMERA                      201
#define EQ_EXECUTECMD_TOGGLE_ADVREQUESTWIN               202
#define EQ_EXECUTECMD_CLOSE_TOP_WINDOW                   203
#define EQ_EXECUTECMD_CLEAR_TARGET                       204
#define EQ_EXECUTECMD_CMD_TOGGLE_FIND_WINDOW             205
#define EQ_EXECUTECMD_TOGGLE_LEADERSHIPWIN               206
#define EQ_EXECUTECMD_TOGGLE_TRIBUTEBENEFITWIN           207
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK1                208
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK2                209
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK3                210
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK4                211
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK5                212
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK6                213
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK7                214
#define EQ_EXECUTECMD_CMD_OPENING_ATTACK8                215
#define EQ_EXECUTECMD_CMD_TOGGLE_COMBAT_ABILITY_WIN      216
#define EQ_EXECUTECMD_CMD_TOGGLE_DYNAMIC_ZONE_WIN        217
#define EQ_EXECUTECMD_CMD_TOGGLE_PVP_LEADERBOARD         218
#define EQ_EXECUTECMD_CMD_TOGGLETASKWIN                  219
#define EQ_EXECUTECMD_CMD_TOGGLE_TICKET_WND              220
#define EQ_EXECUTECMD_CMD_STOP_CAST                      221
#define EQ_EXECUTECMD_CMD_TOGGLEVOICEWIN                 222
#define EQ_EXECUTECMD_CMD_TOGGLE_TITLE_WND               223
#define EQ_EXECUTECMD_POTION_SLOT_1                      224
#define EQ_EXECUTECMD_POTION_SLOT_2                      225
#define EQ_EXECUTECMD_POTION_SLOT_3                      226
#define EQ_EXECUTECMD_POTION_SLOT_4                      227
#define EQ_EXECUTECMD_TOGGLE_POTION_BELT                 228
#define EQ_EXECUTECMD_TOGGLE_BANDOLIER                   229
#define EQ_EXECUTECMD_OPEN_INV_BAGS                      230
#define EQ_EXECUTECMD_CLOSE_INV_BAGS                     231
#define EQ_EXECUTECMD_TOGGLE_SKILLS_WND                  232
#define EQ_EXECUTECMD_OPEN_ETN_HELP                      233
#define EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDBUFFWIN          234
#define EQ_EXECUTECMD_CMD_TOGGLE_AUDIO_TRIGGER_WINDOW    235
#define EQ_EXECUTECMD_CMD_CLIPBOARD_PASTE                236
#define EQ_EXECUTECMD_CMD_UPDATE_EQPLAYERS               237
#define EQ_EXECUTECMD_CMD_OPEN_EQPLAYERS                 238
#define EQ_EXECUTECMD_CMD_TOGGLE_AURAWND                 239
#define EQ_EXECUTECMD_CMD_TOGGLE_BLOCKEDPETBUFFWIN       240
#define EQ_EXECUTECMD_CMD_TOGGLE_REWARD_SELECTION_WIN    241
#define EQ_EXECUTECMD_CMD_TOGGLE_CLAIM_WIN               242
#define EQ_EXECUTECMD_CMD_TOGGLE_VOICE_BAR               243
#define EQ_EXECUTECMD_CMD_TOGGLE_AS_LIST                 244
#define EQ_EXECUTECMD_CMD_PUSH_TO_TALK                   245
#define EQ_EXECUTECMD_CMD_PUSH_TO_TALK_SAY               246
#define EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GROUP             247
#define EQ_EXECUTECMD_CMD_PUSH_TO_TALK_RAID              248
#define EQ_EXECUTECMD_CMD_PUSH_TO_TALK_GUILD             249
#define EQ_EXECUTECMD_CMD_MERCENARIES                    250
#define EQ_EXECUTECMD_CMD_MARKETPLACE                    251
#define EQ_EXECUTECMD_TOGGLE_FPS                         252
#define EQ_EXECUTECMD_TOGGLE_AVATAR                      253
#define EQ_EXECUTECMD_TOGGLE_PETITION                    254
#define EQ_EXECUTECMD_TOGGLE_MEMINFO                     255
#define EQ_EXECUTECMD_FLY_UP                             256
#define EQ_EXECUTECMD_FLY_DOWN                           257
#define EQ_EXECUTECMD_ADD_ROUTE                          258
#define EQ_EXECUTECMD_LAY_PPOINT                         259
#define EQ_EXECUTECMD_LAY_LINK                           260
#define EQ_EXECUTECMD_CONFIRM_YES                        261
#define EQ_EXECUTECMD_CONFIRM_NO                         262
#define EQ_EXECUTECMD_TARGET_PREV_NPC                    263
#define EQ_EXECUTECMD_TARGET_NEXT_NPC                    264
#define EQ_EXECUTECMD_ROTATE_STATS                       265
#define EQ_EXECUTECMD_TOGGLE_NPC_TUNE                    266
#define EQ_EXECUTECMD_TOGGLEQAMARKER                     267
// commands with no string name
#define EQ_EXECUTECMD_CMD_EXITGAME                       274
// #define EQ_EXECUTECMD_                                289

#define EQ_SKILL_SWIMMING 50

#define EQ_NUM_INVENTORY_SLOTS      31      // 23 equipment slots, 8 bag slots
#define EQ_NUM_BANK_SLOTS           26      // 24 bag slots, 2 shared bag slots
#define EQ_NUM_CONTAINER_SLOTS      10      // number of items that can fit in a bag, backpack or box
#define EQ_NUM_LOOT_WINDOW_SLOTS    32
#define EQ_NUM_GUILDS               1500
#define EQ_NUM_MAP_LAYERS           3       // does not include the default map layer 0
#define EQ_NUM_SPELLS               5001
#define EQ_NUM_BONES                64      // number of bones for model info skeleton
#define EQ_NUM_GROUP_MEMBERS        6
#define EQ_NUM_EXECUTECMD           268
#define EQ_NUM_CONTAINERS           34

#define EQ_EXECUTECMD_MAX 290 // 290 total, 268 with names

#define EQ_HOTBUTTON_NUMBER_MIN 1
#define EQ_HOTBUTTON_NUMBER_MAX 10

#define EQ_LEVEL_MIN 1
#define EQ_LEVEL_MAX 100

#define EQ_SKILL_MAX 250

#define EQ_SPAWN_NAME_LENGTH_MIN 4

const float EQ_PI = 3.14159265358979f;

const float EQ_CAMERA_PITCH_DEFAULT = -8.5f;

const float EQ_HEADING_MAX        = 512.0f;
const float EQ_HEADING_MAX_HALVED = 256.0f;

const float EQ_FIELD_OF_VIEW_DEFAULT = 45.0f;

const float EQ_DRAW_DISTANCE_DEFAULT = 1000.0f;
const float EQ_DRAW_DISTANCE_MINIMUM = 100.0f;

const float EQ_SET_TARGET_DISTANCE_MAX = FLT_MAX;

// EQ_Character::eqspa_movement_rate
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN1           = 0.08f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN2           = 0.14f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN3           = 0.21f;
const float EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF    = 0.30f;

const float EQ_SWIM_SPEED_MODIFIER_DEFAULT = 2.150000095f;

const std::unordered_map<std::string, std::string> EQ_KEYVALUE_ACTOR_DEFINITIONS
{
    {"IT27_ACTORDEF",    "Book"},
    {"IT28_ACTORDEF",    "Book"},
    {"IT63_ACTORDEF",    "Small Bag"},
    {"IT64_ACTORDEF",    "Large Bag"},
    {"IT66_ACTORDEF",    "Forge"},
    {"IT69_ACTORDEF",    "Oven"},
    {"IT70_ACTORDEF",    "Brew Barrel"},
    {"IT73_ACTORDEF",    "Kiln"},
    {"IT74_ACTORDEF",    "Pottery Wheel"},
    {"IT128_ACTORDEF",   "Sewing Kit"},
    {"IT10645_ACTORDEF", "Book"},
};

const std::vector<std::string> EQ_LIST_EQUIPMENT_SLOT_NAMES =
{
    "Charm",
    "Left Ear",
    "Head",
    "Face",
    "Right Ear",
    "Neck",
    "Shoulders",
    "Arms",
    "Back",
    "Left Wrist",
    "Right Wrist",
    "Range",
    "Hands",
    "Primary",
    "Secondary",
    "Left Finger",
    "Right Finger",
    "Chest",
    "Legs",
    "Feet",
    "Waist",
    "Power Source",
    "Ammo",
    "Bag #1",
    "Bag #2",
    "Bag #3",
    "Bag #4",
    "Bag #5",
    "Bag #6",
    "Bag #7",
    "Bag #8",
};

const std::unordered_map<std::string, std::string> EQ_KEYVALUE_SHORT_ZONE_NAMES_EMU
{
    {"paludal", "abyss"},
    {"arena", "arena"},
    {"felwithea", "athicaa"},
    {"felwitheb", "athicab"},
    {"blackburrow", "blackburrow"},
    {"droga", "bloodquarry"},
    {"mmcf", "catacombs"},
    {"cauldron", "cauldron"},
    {"qeytoqrg", "centaur"},
    {"mmcg", "cesspits"},
    {"karnor", "citadel"},
    {"ssratemple", "cmalath"},
    {"mmcc", "codarkness"},
    {"sseru", "comercy"},
    {"crystal", "crystal"},
    {"beholder", "cycgorge"},
    {"nektulos", "darkwoods"},
    {"takishruins", "dojo"},
    {"templeveeshan", "dragonhorn"},
    {"frozenshadow", "dreadfang"},
    {"dreadlands", "dreadlands"},
    {"nightmareb", "dream"},
    {"eastwastes", "eastwastes"},
    {"eastkarana", "ebadlands"},
    {"burningwood", "elaeltears"},
    {"soltemple", "elaeltemple"},
    {"mistmoore", "eldenals"},
    {"soldungc", "emberflow"},
    {"emeraldjungle", "emeraldjungle"},
    {"ecommons", "eplaguelands"},
    {"paineel", "erimal"},
    {"erudnext", "erudnext"},
    {"erudnint", "erudnint"},
    {"load", "eternalwell"},
    {"permafrost", "everchill"},
    {"everfrost", "everfrost"},
    {"wakening", "faentharc"},
    {"crushbone", "fearstone"},
    {"ferubi", "ferubi"},
    {"fieldofbone", "fieldofbone"},
    {"soldungb", "firegrotto"},
    {"hole", "firstruins"},
    {"forestfallen", "forestfallen"},
    {"freporte", "freporte"},
    {"freportn", "freportn"},
    {"freportw", "freportw"},
    {"iceclad", "frosthorn"},
    {"gfaydark", "gfaydark"},
    {"butcher", "goblinskull"},
    {"greatdivide", "greatdivide"},
    {"feerrott", "greenmist"},
    {"grobb", "grobb"},
    {"halas", "halas"},
    {"hatesfury", "hatesfury"},
    {"jaggedpine", "heartland"},
    {"highkeep", "highkeep"},
    {"grimling", "hmalath"},
    {"house", "house"},
    {"kaesora", "kaesora"},
    {"kaladima", "kaladima"},
    {"kaladimb", "kaladimb"},
    {"kedge", "kedge"},
    {"highpasshold", "kingpass"},
    {"velketor", "labyrinth"},
    {"najena", "lasanth"},
    {"lfaydark", "lfaydark"},
    {"guktop", "mielecha"},
    {"gukbottom", "mielechb"},
    {"sebilis", "mielechc"},
    {"guka", "mielechd"},
    {"befallen", "misery"},
    {"tox", "mistwoods"},
    {"swampofnohope", "murk"},
    {"nadox", "nadox"},
    {"neriaka", "nagthiliana"},
    {"neriakb", "nagthilianb"},
    {"neriakc", "nagthilianc"},
    {"northkarana", "nbadlands"},
    {"qcat", "ncat"},
    {"necropolis", "necropolis"},
    {"nightmareb", "night"},
    {"qeynos2", "northnport"},
    {"nro", "northwaste"},
    {"oasis", "oasis"},
    {"nurga", "oggmines"},
    {"oggok", "oggok"},
    {"fungusgrove", "overgrowth"},
    {"paw", "paw"},
    {"commons", "plaguelands"},
    {"poair", "poair"},
    {"tutorial", "pocketplane"},
    {"growthplane", "poearth"},
    {"podisease", "poentropy"},
    {"pofire", "pofire"},
    {"mire", "pofrost"},
    {"pojustice", "pojustice"},
    {"mirj", "polore"},
    {"ponightmare", "ponightmare"},
    {"vexthal", "portals"},
    {"potorment", "potorment"},
    {"powater", "powater"},
    {"skyshrine", "prison"},
    {"firiona", "prophets"},
    {"trakanon", "remnants"},
    {"rivervale", "rivervale"},
    {"runnyeye", "runnyeye"},
    {"poinnovation", "rust"},
    {"southkarana", "sbadlands"},
    {"rujc", "scrapheap"},
    {"erudsxing", "seastorm"},
    {"oot", "seaswords"},
    {"mmce", "sepulcher"},
    {"kithicor", "shadowdale"},
    {"rathemtn", "shardmtns"},
    {"sharvahl", "sharvahl"},
    {"unrest", "shroudisle"},
    {"sirens", "sirens"},
    {"kerraridge", "smalath"},
    {"qeynos", "southnport"},
    {"sro", "southwaste"},
    {"kurn", "spires"},
    {"lakerathe", "starfall"},
    {"steamfont", "steamfont"},
    {"innothule", "stingersbog"},
    {"kal", "stormkeep"},
    {"sleeper", "stormseye"},
    {"stonebrunt", "sundermtns"},
    {"soldunga", "sunmines"},
    {"lavastorm", "sunpeaks"},
    {"qrg", "surefall"},
    {"tipt", "tarhylcrags"},
    {"bothunder", "thaztower"},
    {"thedeep", "thedeep"},
    {"thurgadina", "thurgadina"},
    {"thurgadinb", "thurgadinb"},
    {"solrotower", "towertarhyl"},
    {"chardok", "turruj"},
    {"veksar", "undercaverns"},
    {"gukg", "undercity"},
    {"akanon", "underhill"},
    {"hohonora", "valor"},
    {"hohonorb", "valorb"},
    {"citymist", "veilcity"},
    {"acrylia", "warpstone"},
    {"warrens", "warrens"},
    {"westkarana", "wbadlands"},
    {"westwastes", "westwastes"},
    {"misty", "whisperling"},
    {"torgiran", "windstone"},
    {"cobaltscar", "wyvernfang"},
    {"cazicthule", "yaralith"},
};

namespace EQ
{

    typedef struct _Line
    {
        float X;
        float Y;
        float Z = 0.0f;
        //float X1;
        //float Y1;
        //float Z1 = 0.0f;
        //float X2;
        //float Y2;
        //float Z2 = 0.0f;
    } Line, *Line_ptr;

    typedef struct _Rect
    {
        float X1;
        float Y1;
        float Z1 = 1.0f;
        float X2;
        float Y2;
        float Z2 = 1.0f;
        float X3;
        float Y3;
        float Z3 = 1.0f;
        float X4;
        float Y4;
        float Z4 = 1.0f;
    } Rect, *Rect_ptr;

    typedef struct _CXRect
    {
        INT32 X1;
        INT32 Y1;
        INT32 X2;
        INT32 Y2;
    } CXRect, *CXRect_ptr;

    typedef struct _XYZ
    {
        float X;
        float Y;
        float Z;
    } XYZ, *XYZ_ptr;

    typedef struct _YXZ
    {
        float Y;
        float X;
        float Z;
    } YXZ, *YXZ_ptr;

    typedef struct _ColorARGB
    {
        union
        {
            struct
            {
                uint8_t B;
                uint8_t G;
                uint8_t R;
                uint8_t A;
            };
            uint32_t Color;
        };
    } ColorARGB, *ColorARGB_ptr;

    typedef struct _ColorRGB
    {
        uint8_t B;
        uint8_t G;
        uint8_t R;
    } ColorRGB, *ColorRGB_ptr;

    typedef struct _MapLabel
    {
        /*0x00*/    struct _MapLabel* Next = NULL;
        /*0x04*/    struct _MapLabel* Prev;
        /*0x08*/    EQ::XYZ Location;
        /*0x14*/    EQ::ColorARGB Color;
        /*0x18*/    uint32_t Size = 2; // 1-3
        /*0x1C*/    char* Label; // text
        /*0x20*/    uint32_t Layer = 3; // 0-3
        /*0x24*/    uint32_t Width = 20;
        /*0x28*/    uint32_t Height = 12;
        /*0x2C*/    uint32_t Unknown0x2C; // uint8_t X;
        /*0x30*/    uint32_t Unknown0x30; // uint8_t Y;
        uint32_t Data = 254; // custom data for identifying labels by value
    } MapLabel, *MapLabel_ptr;

    typedef struct _MapLine
    {
        struct _MapLine* Next;
        struct _MapLine* Prev;
        EQ::XYZ Begin;
        EQ::XYZ End;
        EQ::ColorARGB Color;
        uint32_t Layer; // 0-3
    } MapLine, *MapLine_ptr;

    typedef struct _ChangeForm
    {
        uint32_t SpawnId;
        uint8_t Unknown2[63];
        uint32_t RaceId = EQ_RACE_HUMAN;
        uint8_t Gender = EQ_GENDER_MALE;
        uint8_t Unknown73;    // = 0xFF for playable races, 0x00 for unplayable races like skeletons
        uint8_t Unknown74[2];
        uint8_t Unknown76;    // = 0xFF for playable races, 0x00 for unplayable races like skeletons
        uint8_t Unknown77[3];
        uint8_t Unknown80 = 0x06;

        // bytes[00] = Spawn ID    // uint32_t
        // bytes[68] = Race ID     // uint32_t
        // bytes[72] = Gender      // uint8_t
        // bytes[73] = 0xFF        // uint8_t = 0xFF for playable races, 0x00 for unplayable races like skeletons
        // bytes[76] = 0xFF        // uint8_t = 0xFF for playable races, 0x00 for unplayable races like skeletons
        // bytes[80] = 0x06        // uint8_t

    } ChangeForm, *ChangeForm_ptr;

} // namespace EQ