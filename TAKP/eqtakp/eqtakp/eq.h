#pragma once

#define EQ_ADDRESS_BASE 0x00400000

#define EQ_ADDRESS_TIMER 0x007989D4 // uint32_t ; time elapsed in milliseconds

#define EQ_ADDRESS_IS_IN_GAME 0x00798550 // uint8_t
#define EQ_ADDRESS_IS_AUTO_ATTACK_ENABLED 0x007F6FFE // uint8_t
#define EQ_ADDRESS_IS_NET_STATUS_ENABLED 0x007985EC // uint8_t
#define EQ_ADDRESS_IS_NOT_TYPING_IN_CHAT 0x0079856C // uint8_t
#define EQ_ADDRESS_IS_INSPECT_ENABLED 0x007CF28C // uint8_t ; /inspect on/off ; /toggleinspect
#define EQ_ADDRESS_IS_SHOW_NPC_NAMES_ENABLED 0x0063D6CC // uint8_t ; Options -> Display -> Show NPC Names
#define EQ_ADDRESS_IS_RUN_ENABLED 0x0079856D // uint8_t ; 0 = Walk, 1 = Run
#define EQ_ADDRESS_IS_ACTOR_COLLISION_ENABLED 0x0079856E // uint8_t ; walk through or collide with players, npcs, doors

#define EQ_ADDRESS_GROUP_COUNT 0x007912B0 // number of players currently in group

#define EQ_ADDRESS_DINPUT_ROOT            0x008092DC
#define EQ_ADDRESS_DINPUT_DEVICE_KEYBOARD 0x008092E0
#define EQ_ADDRESS_DINPUT_DEVICE_MOUSE    0x008092E4

#define EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT 0x005EA6FC
// used in EQ function 0x0055B60C that initalizes the direct input mouse
// IDirectInputDevice8::SetDataFormat() is (DINPUT_DEVICE_MOUSE + 0x2C)()
// ONLY allows for 3 mouse buttons in this state (DIMOUSESTATE / c_dfDIMouse)
// 0x005EA6FC 24    0x18    // uint32_t
// 0x005EA700 16    0x10    // uint32_t
// 0x005EA704 2     0x02    // uint32_t
// 0x005EA708 16    0x10    // uint32_t
// 0x005EA70C 7     0x07    // uint32_t
// allows for 7 mouse buttons in this state (DIMOUSESTATE2 / c_dfDIMouse2)
// 0x005EA6FC 24    0x18    // uint32_t
// 0x005EA700 16    0x10    // uint32_t
// 0x005EA704 2     0x02    // uint32_t
// 0x005EA708 20    0x14    // uint32_t
// 0x005EA70C 11    0x0B    // uint32_t

#define EQ_ADDRESS_IS_KEY_PRESSED_SHIFT   0x0080931C // uint32_t
#define EQ_ADDRESS_IS_KEY_PRESSED_CONTROL 0x00809320 // uint32_t
#define EQ_ADDRESS_IS_KEY_PRESSED_ALT     0x0080932C // uint32_t

#define EQ_ADDRESS_IS_CAPSLOCK_ENABLED 0x00809324 // uint32_t
#define EQ_ADDRESS_IS_NUMLOCK_ENABLED  0x00809328 // uint32_t

#define EQ_FONT_SIZE_DEFAULT 3

#define EQ_ADDRESS_POINTER_FONT_ARIAL10 0x0063D3A8
#define EQ_ADDRESS_POINTER_FONT_ARIAL12 0x0063D3AC
#define EQ_ADDRESS_POINTER_FONT_ARIAL14 0x0063D3B0
#define EQ_ADDRESS_POINTER_FONT_ARIAL15 0x0063D3B4
#define EQ_ADDRESS_POINTER_FONT_ARIAL16 0x0063D3B8
#define EQ_ADDRESS_POINTER_FONT_ARIAL20 0x0063D3BC

#define EQ_NUM_COMMANDS 277 // 0-276
#define EQ_NUM_ZONES 224
#define EQ_NUM_CLASSES 32
#define EQ_NUM_BUFFS 15
#define EQ_NUM_SPELLS 4000
#define EQ_NUM_SPELL_GEMS 8
#define EQ_NUM_GROUP_MEMBERS 5
#define EQ_NUM_INVENTORY_EQUIPMENT_SLOTS 21
#define EQ_NUM_INVENTORY_PACK_SLOTS 8 // bags or backpacks
#define EQ_NUM_INVENTORY_BANK_SLOTS 8
#define EQ_NUM_INVENTORY_SLOTS_TOTAL // 21 + 8 + 8, inventory + bags + bank
#define EQ_NUM_MERCHANT_SLOTS 80
#define EQ_NUM_SKILLS 74
#define EQ_NUM_SPELL_BOOK_SPELLS 256 // 0-255, 32 pages with 8 spells each
#define EQ_NUM_SPELL_BOOK_SPELLS_PER_PAGE 8
#define EQ_NUM_SPELL_BOOK_PAGES 32
#define EQ_NUM_SPAWNS 8192
#define EQ_NUM_GUILDS 512
#define EQ_NUM_LOOT_WINDOW_SLOTS 30
#define EQ_NUM_HOTBUTTONS 10
#define EQ_NUM_HOTBUTTONS_TOTAL 100
#define EQ_NUM_CONTAINER_SLOTS 10
#define EQ_NUM_MODEL_BONE_CHILDREN 32

#define EQ_EXPERIENCE_BAR_VALUE_MAX 350 // the progress bar (0-350)
#define EQ_ALTERNATE_ADVANCEMENT_EXPERIENCE_BAR_VALUE_MAX 330 // the progress bar (0-330)

#define EQ_ITEM_NO_DROP_TRUE  0x00
#define EQ_ITEM_NO_DROP_FALSE 0xFF
#define EQ_ITEM_NO_RENT_TRUE  0x00
#define EQ_ITEM_NO_RENT_FALSE 0xFF

#define EQ_ITEM_SIZE_TINY   0
#define EQ_ITEM_SIZE_SMALL  1
#define EQ_ITEM_SIZE_MEDIUM 2
#define EQ_ITEM_SIZE_LARGE  3
#define EQ_ITEM_SIZE_GIANT  4

#define EQ_ITEM_TYPE_1H_SLASHING           0
#define EQ_ITEM_TYPE_PIERCING              2
#define EQ_ITEM_TYPE_2H_SLASHING           1
#define EQ_ITEM_TYPE_1H_BLUNT              3
#define EQ_ITEM_TYPE_2H_BLUNT              4
#define EQ_ITEM_TYPE_BOW                   5
#define EQ_ITEM_TYPE_SHIELD                8
#define EQ_ITEM_TYPE_EFFECT                10 // haste
#define EQ_ITEM_TYPE_MISCELLANEOUS         11 // misc
#define EQ_ITEM_TYPE_FOOD                  14
#define EQ_ITEM_TYPE_DRINK                 15
#define EQ_ITEM_TYPE_COMBINABLE            17 // stackable gems, silks, etc
#define EQ_ITEM_TYPE_THROWING              19
#define EQ_ITEM_TYPE_SPELL_SCROLL          20
#define EQ_ITEM_TYPE_POTION                21 // potion
#define EQ_ITEM_TYPE_WIND_INSTRUMENT       23
#define EQ_ITEM_TYPE_STRINGED_INSTRUMENT   24
#define EQ_ITEM_TYPE_BRASS_INSTRUMENT      25
#define EQ_ITEM_TYPE_PERCUSSION_INSTRUMENT 26
#define EQ_ITEM_TYPE_ARROW                 27
#define EQ_ITEM_TYPE_JEWELRY               29
#define EQ_ITEM_TYPE_2H_PIERCING           35
#define EQ_ITEM_TYPE_ALCOHOL               38
#define EQ_ITEM_TYPE_SINGING               50
#define EQ_ITEM_TYPE_ALL_INSTRUMENT_TYPES  51

#define EQ_ITEM_EFFECT_FLAG_COMBAT     0
#define EQ_ITEM_EFFECT_FLAG_WORN       2
#define EQ_ITEM_EFFECT_FLAG_MUST_EQUIP 4

#define EQ_ITEM_MATERIAL_NONE    0
#define EQ_ITEM_MATERIAL_LEATHER 1
#define EQ_ITEM_MATERIAL_CHAIN   2
#define EQ_ITEM_MATERIAL_PLATE   3
#define EQ_ITEM_MATERIAL_SILK    4

#define EQ_BUFF_TYPE_DETRIMENTAL           0
#define EQ_BUFF_TYPE_BENEFICIAL            1
#define EQ_BUFF_TYPE_BENEFICIAL_GROUP_ONLY 2

#define EQ_SPAWN_TYPE_PLAYER        0
#define EQ_SPAWN_TYPE_NPC           1
#define EQ_SPAWN_TYPE_NPC_CORPSE    2
#define EQ_SPAWN_TYPE_PLAYER_CORPSE 3
#define EQ_SPAWN_TYPE_PLAYER_PET    252 // custom unique value for pets
#define EQ_SPAWN_TYPE_NPC_PET       253 // custom unique value for pets
#define EQ_SPAWN_TYPE_ANY_CORPSE    254 // custom unique value for hide corpse looted

#define EQ_SPAWN_TARGET_TYPE_CAN_TARGET     0x00
#define EQ_SPAWN_TARGET_TYPE_CAN_TARGET_2   0x01
#define EQ_SPAWN_TARGET_TYPE_CANNOT_TARGET  0x41

#define EQ_ADDRESS_POINTER_CAMERA_DATA 0x0063B924 // pass this as first argument to graphics DLL world space to screen space funtion

#define EQ_ADDRESS_POINTER_CAMERA_ACTOR_INSTANCE 0x0063BE88 // pCamActor

// all three camera view values must be set to same value at same time or client will crash
#define EQ_ADDRESS_CAMERA_VIEW       0x0063BE68 // uint32_t ; EQ_CAMERA_VIEW_x
#define EQ_ADDRESS_CAMERA_VIEW_EX    0x0063B8EC // uint32_t
#define EQ_ADDRESS_CAMERA_VIEW_EX_EX 0x006EC6E4 // uint8_t

#define EQ_CAMERA_VIEW_FIRST_PERSON   0
#define EQ_CAMERA_VIEW_THIRD_PERSON_1 1
#define EQ_CAMERA_VIEW_THIRD_PERSON_2 2
#define EQ_CAMERA_VIEW_THIRD_PERSON_3 3
#define EQ_CAMERA_VIEW_THIRD_PERSON_4 4

#define EQ_ADDRESS_CAMERA_VIEW_THIRD_PERSON2_ZOOM 0x007996C0 // FLOAT ; min is spawn model height offset, max is 200.0f
#define EQ_ADDRESS_CAMERA_VIEW_THIRD_PERSON3_ZOOM 0x007996DC // FLOAT ; min is spawn model height offset, max is 200.0f
#define EQ_ADDRESS_CAMERA_VIEW_THIRD_PERSON4_ZOOM 0x007996F8 // FLOAT ; min is spawn model height offset, max is 200.0f

#define EQ_ADDRESS_CAMERA_VIEW_THIRD_PERSON_ZOOM_MAX 0x005E8538 // FLOAT ; equals 200.0f

#define EQ_ADDRESS_IS_HIDING_OR_TRACKING 0x007989E2 // uint16_t

#define EQ_IS_HIDING_OR_TRACKING_EQUALS_NONE     0xFFFF
#define EQ_IS_HIDING_OR_TRACKING_EQUALS_HIDING   0x001D
#define EQ_IS_HIDING_OR_TRACKING_EQUALS_TRACKING 0x0035

#define EQ_SPELL_ID_NULL 0xFFFF // uint16_t
#define EQ_SPELL_ID_HASTE 998 // uint16_t

#define EQ_SPELL_LEVEL_NEEDED_CANNOT_USE 0xFF // uint8_t

#define EQ_BUFF_TYPE_DETRIMENTAL           0
#define EQ_BUFF_TYPE_BENEFICIAL            1
#define EQ_BUFF_TYPE_BENEFICIAL_GROUP_ONLY 2

#define EQ_GENDER_MALE   0x00
#define EQ_GENDER_FEMALE 0x01

#define EQ_RACE_UNKNOWN   0
#define EQ_RACE_HUMAN     1
#define EQ_RACE_BARBARIAN 2
#define EQ_RACE_ERUDITE   3
#define EQ_RACE_WOOD_ELF  4
#define EQ_RACE_HIGH_ELF  5
#define EQ_RACE_DARK_ELF  6
#define EQ_RACE_HALF_ELF  7
#define EQ_RACE_DWARF     8
#define EQ_RACE_TROLL     9
#define EQ_RACE_OGRE      10
#define EQ_RACE_HALFLING  11
#define EQ_RACE_GNOME     12
#define EQ_RACE_IKSAR     128
#define EQ_RACE_VAH_SHIR  130
#define EQ_RACE_FROGLOK   330
//
#define EQ_RACE_WEREWOLF 14
#define EQ_RACE_WOLF 42
#define EQ_RACE_BEAR 43
#define EQ_RACE_SKELETON 60
#define EQ_RACE_INVISIBLE_MAN 127
#define EQ_RACE_SARNAK_SKELETON 155
#define EQ_RACE_IKSAR_SKELETON 161

#define EQ_CLASS_UNKNOWN                  0
#define EQ_CLASS_WARRIOR                  1
#define EQ_CLASS_CLERIC                   2
#define EQ_CLASS_PALADIN                  3
#define EQ_CLASS_RANGER                   4
#define EQ_CLASS_SHADOWKNIGHT             5
#define EQ_CLASS_DRUID                    6
#define EQ_CLASS_MONK                     7
#define EQ_CLASS_BARD                     8
#define EQ_CLASS_ROGUE                    9
#define EQ_CLASS_SHAMAN                   10
#define EQ_CLASS_NECROMANCER              11
#define EQ_CLASS_WIZARD                   12
#define EQ_CLASS_MAGICIAN                 13
#define EQ_CLASS_ENCHANTER                14
#define EQ_CLASS_BEASTLORD                15
#define EQ_CLASS_BANKER                   16
#define EQ_CLASS_WARRIOR_GUILDMASTER      17 // EQ_CLASS_WARRIOR + 16
#define EQ_CLASS_CLERIC_GUILDMASTER       18
#define EQ_CLASS_PALADIN_GUILDMASTER      19
#define EQ_CLASS_RANGER_GUILDMASTER       20
#define EQ_CLASS_SHADOWKNIGHT_GUILDMASTER 21
#define EQ_CLASS_DRUID_GUILDMASTER        22
#define EQ_CLASS_MONK_GUILDMASTER         23
#define EQ_CLASS_BARD_GUILDMASTER         24
#define EQ_CLASS_ROGUE_GUILDMASTER        25
#define EQ_CLASS_SHAMAN_GUILDMASTER       26
#define EQ_CLASS_NECROMANCER_GUILDMASTER  27
#define EQ_CLASS_WIZARD_GUILDMASTER       28
#define EQ_CLASS_MAGICIAN_GUILDMASTER     29
#define EQ_CLASS_ENCHANTER_GUILDMASTER    30
#define EQ_CLASS_BEASTLORD_GUILDMASTER    31 // EQ_CLASS_BEASTLORD + 16
#define EQ_CLASS_MERCHANT                 32
#define EQ_CLASS_GUILDMASTER_BEGIN        17
#define EQ_CLASS_GUILDMASTER_END          31

#define EQ_OFFSET_CLASS_GUILDMASTER 16 // EQ_CLASS_x + 16 = EQ_CLASS_x_GUILDMASTER

#define EQ_DEITY_BERTOXXULOUS  0x00C9
#define EQ_DEITY_BRELL_SERILIS 0x00CA
#define EQ_DEITY_CAZIC_THULE   0x00CB
#define EQ_DEITY_INNORUK       0x00CE
#define EQ_DEITY_KARANA        0x00CF
#define EQ_DEITY_QUELLIOUS     0x00D2
#define EQ_DEITY_RALLOS_ZEK    0x00D3
#define EQ_DEITY_THE_TRIBUNAL  0x00D6
#define EQ_DEITY_TUNARE        0x00D7
#define EQ_DEITY_AGNOSTIC      0x018C

#define EQ_GUILD_ID_NULL 0xFFFF // uint16_t

#define EQ_GUILD_STATUS_MEMBER  0
#define EQ_GUILD_STATUS_OFFICER 1
#define EQ_GUILD_STATUS_LEADER  2

// EQPlayer::ChangePosition(uint8_t standingState)
#define EQ_STANDING_STATE_STANDING    0x64
#define EQ_STANDING_STATE_FROZEN      0x66 // stunned / mesmerized / feared ; You lose control of yourself!
#define EQ_STANDING_STATE_LOOTING     0x69 // looting or binding wounds
#define EQ_STANDING_STATE_SITTING     0x6E
#define EQ_STANDING_STATE_DUCKING     0x6F // crouching
#define EQ_STANDING_STATE_FEIGN_DEATH 0x73 // pretending to be dead
#define EQ_STANDING_STATE_DEAD        0x78

#define EQ_STUNNED_STATE_FALSE       0x00
#define EQ_STUNNED_STATE_TRUE        0x01
#define EQ_STUNNED_STATE_UNCONSCIOUS 0x03
#define EQ_STUNNED_STATE_DEAD        0x04

#define EQ_LEVITATION_STATE_FALSE 0x00
#define EQ_LEVITATION_STATE_TRUE  0x02
#define EQ_LEVITATION_STATE_NPC   0x03

#define EQ_ANONYMOUS_STATE_FALSE    0x00
#define EQ_ANONYMOUS_STATE_TRUE     0x01
#define EQ_ANONYMOUS_STATE_ROLEPLAY 0x02
#define EQ_ANONYMOUS_STATE_BOTH     0x03

#define EQ_GAME_STATE_CHARACTER_SELECT 1
#define EQ_GAME_STATE_ZONING           3
#define EQ_GAME_STATE_ZONING2          4
#define EQ_GAME_STATE_IN_GAME          5
#define EQ_GAME_STATE_LOADING_SCREEN   6
#define EQ_GAME_STATE_ZONING3          7

#define EQ_MOVEMENT_TYPE_NONE         0
#define EQ_MOVEMENT_TYPE_CROUCHING    1
#define EQ_MOVEMENT_TYPE_WALKING      4
#define EQ_MOVEMENT_TYPE_RUNNING      6
#define EQ_MOVEMENT_TYPE_SWIMMING     7
#define EQ_MOVEMENT_TYPE_SWIMMING_EX  16
#define EQ_MOVEMENT_TYPE_BACKWARDS    253

#define EQ_HOTBUTTTON_TYPE1_ATTACK       1 // Melee or Range
#define EQ_HOTBUTTTON_TYPE1_SKILL1       2
#define EQ_HOTBUTTTON_TYPE1_SKILL2       3
#define EQ_HOTBUTTTON_TYPE1_SOCIAL_MACRO 4
#define EQ_HOTBUTTTON_TYPE1_ITEM         5
#define EQ_HOTBUTTTON_TYPE1_DEFAULT      6
#define EQ_HOTBUTTTON_TYPE1_SPELL_GEM    7

#define EQ_HOTBUTTTON_TYPE2_EMPTY 255

#define EQ_SKILL_1H_BLUNT               0
#define EQ_SKILL_1H_SLASHING            1
#define EQ_SKILL_2H_BLUNT               2
#define EQ_SKILL_2H_SLASHING            3
#define EQ_SKILL_ABJURATION             4
#define EQ_SKILL_ALTERATION             5
#define EQ_SKILL_APPLY_POISON           6
#define EQ_SKILL_ARCHERY                7
#define EQ_SKILL_BACKSTAB               8
#define EQ_SKILL_BIND_WOUND             9
#define EQ_SKILL_BASH                   10
#define EQ_SKILL_BLOCK                  11
#define EQ_SKILL_BRASS_INSTRUMENTS      12
#define EQ_SKILL_CHANNELING             13
#define EQ_SKILL_CONJURATION            14
#define EQ_SKILL_DEFENSE                15
#define EQ_SKILL_DISARM                 16
#define EQ_SKILL_DISARM_TRAPS           17
#define EQ_SKILL_DIVINATION             18
#define EQ_SKILL_DODGE                  19
#define EQ_SKILL_DOUBLE_ATTACK          20
#define EQ_SKILL_DRAGON_PUNCH           21
#define EQ_SKILL_TAIL_RAKE              21
#define EQ_SKILL_DUAL_WIELD             22
#define EQ_SKILL_EAGLE_STRIKE           23
#define EQ_SKILL_EVOCATION              24
#define EQ_SKILL_FEIGN_DEATH            25
#define EQ_SKILL_FLYING_KICK            26
#define EQ_SKILL_FORAGE                 27
#define EQ_SKILL_HAND_TO_HAND           28
#define EQ_SKILL_HIDE                   29
#define EQ_SKILL_KICK                   30
#define EQ_SKILL_MEDITATE               31
#define EQ_SKILL_MEND                   32
#define EQ_SKILL_OFFENSE                33
#define EQ_SKILL_PARRY                  34
#define EQ_SKILL_PICK_LOCK              35
#define EQ_SKILL_PIERCING               36
#define EQ_SKILL_RIPOSTE                37
#define EQ_SKILL_ROUND_KICK             38
#define EQ_SKILL_SAFE_FALL              39
#define EQ_SKILL_SENSE_HEADING          40
#define EQ_SKILL_SINGING                41
#define EQ_SKILL_SNEAK                  42
#define EQ_SKILL_SPECIALIZE_ABJURATION  43
#define EQ_SKILL_SPECIALIZE_ALTERATION  44
#define EQ_SKILL_SPECIALIZE_CONJURATION 45
#define EQ_SKILL_SPECIALIZE_DIVINATION  46
#define EQ_SKILL_SPECIALIZE_EVOCATION   47
#define EQ_SKILL_PICK_POCKETS           48
#define EQ_SKILL_STRINGED_INSTRUMENTS   49
#define EQ_SKILL_SWIMMING               50
#define EQ_SKILL_THROWING               51
#define EQ_SKILL_TIGER_CLAW             52
#define EQ_SKILL_TRACKING               53
#define EQ_SKILL_WIND_INSTRUMENTS       54
#define EQ_SKILL_FISHING                55
#define EQ_SKILL_MAKE_POISON            56
#define EQ_SKILL_TINKERING              57
#define EQ_SKILL_RESEARCH               58
#define EQ_SKILL_ALCHEMY                59
#define EQ_SKILL_BAKING                 60
#define EQ_SKILL_TAILORING              61
#define EQ_SKILL_SENSE_TRAPS            62
#define EQ_SKILL_BLACKSMITHING          63
#define EQ_SKILL_FLETCHING              64
#define EQ_SKILL_BREWING                65
#define EQ_SKILL_ALCOHOL_TOLERANCE      66
#define EQ_SKILL_BEGGING                67
#define EQ_SKILL_JEWELRY_MAKING         68
#define EQ_SKILL_POTTERY                69
#define EQ_SKILL_PERCUSSION_INSTRUMENTS 70
#define EQ_SKILL_INTIMIDATION           71
#define EQ_SKILL_BERSERKING             72
#define EQ_SKILL_TAUNT                  73
#define EQ_SKILL_FRENZY                 74
#define EQ_SKILL_GENERIC_TRADESKILL     75
//
#define EQ_SKILL_SLAM                   111
//
#define EQ_SKILL_NULL                   255

#define EQ_TEXT_COLOR_BLACK       0
#define EQ_TEXT_COLOR_GRAY        1
#define EQ_TEXT_COLOR_GREEN       2
#define EQ_TEXT_COLOR_GRAY2       3
#define EQ_TEXT_COLOR_BLUE        4
#define EQ_TEXT_COLOR_PINK        5
#define EQ_TEXT_COLOR_GRAY3       6
#define EQ_TEXT_COLOR_WHITE       7
#define EQ_TEXT_COLOR_GRAY4       8
#define EQ_TEXT_COLOR_GRAY5       9
#define EQ_TEXT_COLOR_WHITE2      10
#define EQ_TEXT_COLOR_GRAY6       11
#define EQ_TEXT_COLOR_LIGHT_GRAY  12
#define EQ_TEXT_COLOR_RED         13
#define EQ_TEXT_COLOR_LIGHT_GREEN 14
#define EQ_TEXT_COLOR_YELLOW      15
#define EQ_TEXT_COLOR_LIGHT_BLUE  16
#define EQ_TEXT_COLOR_GRAY7       17
#define EQ_TEXT_COLOR_CYAN        18
#define EQ_TEXT_COLOR_GRAY8       19
#define EQ_TEXT_COLOR_BLACK2      20

// based on HTML specification color names (Web colors)
#define EQ_COLOR_ARGB_WHITE      0xFFFFFFFF
#define EQ_COLOR_ARGB_SILVER     0xFFC0C0C0 // light gray
#define EQ_COLOR_ARGB_GRAY       0xFF808080
#define EQ_COLOR_ARGB_BLACK      0xFF000000
#define EQ_COLOR_ARGB_RED        0xFFFF0000
#define EQ_COLOR_ARGB_MAROON     0xFF800000 // dark red
#define EQ_COLOR_ARGB_YELLOW     0xFFFFFF00
#define EQ_COLOR_ARGB_OLIVE      0xFF808000 // dark yellow
#define EQ_COLOR_ARGB_LIME       0xFF00FF00 // light green
#define EQ_COLOR_ARGB_GREEN      0xFF008000 // dark green
#define EQ_COLOR_ARGB_AQUA       0xFF00FFFF // light blue or cyan
#define EQ_COLOR_ARGB_TEAL       0xFF008080 // dark aqua
#define EQ_COLOR_ARGB_BLUE       0xFF0000FF
#define EQ_COLOR_ARGB_NAVY       0xFF000080 // dark blue
#define EQ_COLOR_ARGB_FUCHSIA    0xFFFF00FF // dark pink
#define EQ_COLOR_ARGB_PURPLE     0xFF800080

// custom colors
#define EQ_COLOR_ARGB_GRAY_DARK      0xFF404040
#define EQ_COLOR_ARGB_PINK           0xFFFF80FF
#define EQ_COLOR_ARGB_MAGENTA        0xFFFF0080 // RED_BLUE
#define EQ_COLOR_ARGB_ORANGE         0xFFFF8000 // RED_GREEN
#define EQ_COLOR_ARGB_RED_GREEN      0xFFFF8000
#define EQ_COLOR_ARGB_RED_BLUE       0xFFFF0080
#define EQ_COLOR_ARGB_GREEN_RED      0xFF80FF00
#define EQ_COLOR_ARGB_GREEN_BLUE     0xFF00FF80
#define EQ_COLOR_ARGB_BLUE_RED       0xFF8000FF
#define EQ_COLOR_ARGB_BLUE_GREEN     0xFF0080FF
#define EQ_COLOR_ARGB_RED_WHITE      0xFFFF8080
#define EQ_COLOR_ARGB_GREEN_WHITE    0xFF80FF80
#define EQ_COLOR_ARGB_BLUE_WHITE     0xFF8080FF
#define EQ_COLOR_ARGB_YELLOW_WHITE   0xFFFFFF80

#define EQ_COLOR_ARGB_TOOLTIP_TEXT_BACKGROUND 0xC8000080

// ExecuteCmd() function
#define EQ_EXECUTECMD_NULL                      0
#define EQ_EXECUTECMD_AUTORUN                   1
#define EQ_EXECUTECMD_JUMP                      2
#define EQ_EXECUTECMD_FORWARD                   3
#define EQ_EXECUTECMD_BACK                      4
#define EQ_EXECUTECMD_RIGHT                     5
#define EQ_EXECUTECMD_LEFT                      6
#define EQ_EXECUTECMD_MOUSELOOK                 7
#define EQ_EXECUTECMD_AUTOPRIM                  8
#define EQ_EXECUTECMD_CONSIDER                  9
#define EQ_EXECUTECMD_DUCK                      10
#define EQ_EXECUTECMD_HAIL                      11
#define EQ_EXECUTECMD_INVENTORY                 12
#define EQ_EXECUTECMD_TELL                      13
#define EQ_EXECUTECMD_UNKNOWN_14                14
#define EQ_EXECUTECMD_PITCHUP                   15
#define EQ_EXECUTECMD_PITCHDOWN                 16
#define EQ_EXECUTECMD_CENTERVIEW                17
#define EQ_EXECUTECMD_ZOOMIN                    18
#define EQ_EXECUTECMD_ZOOMOUT                   19
#define EQ_EXECUTECMD_TOGGLECAM                 20
#define EQ_EXECUTECMD_FULLSCREEN                21
#define EQ_EXECUTECMD_TARGETME                  22
#define EQ_EXECUTECMD_PARTY1                    23
#define EQ_EXECUTECMD_PARTY2                    24
#define EQ_EXECUTECMD_PARTY3                    25
#define EQ_EXECUTECMD_PARTY4                    26
#define EQ_EXECUTECMD_PARTY5                    27
#define EQ_EXECUTECMD_TARGETPC                  28
#define EQ_EXECUTECMD_TARGETNPC                 29
#define EQ_EXECUTECMD_NETSTAT                   30
#define EQ_EXECUTECMD_HOT1                      31
#define EQ_EXECUTECMD_HOT2                      32
#define EQ_EXECUTECMD_HOT3                      33
#define EQ_EXECUTECMD_HOT4                      34
#define EQ_EXECUTECMD_HOT5                      35
#define EQ_EXECUTECMD_HOT6                      36
#define EQ_EXECUTECMD_HOT7                      37
#define EQ_EXECUTECMD_HOT8                      38
#define EQ_EXECUTECMD_HOT9                      39
#define EQ_EXECUTECMD_HOT10                     40
#define EQ_EXECUTECMD_HOTPAGE1                  41
#define EQ_EXECUTECMD_HOTPAGE2                  42
#define EQ_EXECUTECMD_HOTPAGE3                  43
#define EQ_EXECUTECMD_HOTPAGE4                  44
#define EQ_EXECUTECMD_HOTPAGE5                  45
#define EQ_EXECUTECMD_HOTPAGE6                  46
#define EQ_EXECUTECMD_HOTPAGE7                  47
#define EQ_EXECUTECMD_HOTPAGE8                  48
#define EQ_EXECUTECMD_HOTPAGE9                  49
#define EQ_EXECUTECMD_HOTPAGE10                 50
#define EQ_EXECUTECMD_CAST1                     51
#define EQ_EXECUTECMD_CAST2                     52
#define EQ_EXECUTECMD_CAST3                     53
#define EQ_EXECUTECMD_CAST4                     54
#define EQ_EXECUTECMD_CAST5                     55
#define EQ_EXECUTECMD_CAST6                     56
#define EQ_EXECUTECMD_CAST7                     57
#define EQ_EXECUTECMD_CAST8                     58
#define EQ_EXECUTECMD_REPLY                     59
#define EQ_EXECUTECMD_CYCLEREPLY                60
#define EQ_EXECUTECMD_CYCLEREPLY_BACK           61
#define EQ_EXECUTECMD_BACKDROP                  62
#define EQ_EXECUTECMD_TOGGLETARGET              63
#define EQ_EXECUTECMD_SPELLBOOK                 64
#define EQ_EXECUTECMD_ABILITIES                 65
#define EQ_EXECUTECMD_COMBAT                    66
#define EQ_EXECUTECMD_SOCIALS                   67
#define EQ_EXECUTECMD_MAIN                      68
#define EQ_EXECUTECMD_UNKNOWN_69                69
#define EQ_EXECUTECMD_INVITE_FOLLOW             70
#define EQ_EXECUTECMD_DISBAND                   71
#define EQ_EXECUTECMD_CAMP                      72
#define EQ_EXECUTECMD_SIT_STAND                 73
#define EQ_EXECUTECMD_RUN_WALK                  74
#define EQ_EXECUTECMD_CLIP_IN                   75
#define EQ_EXECUTECMD_CLIP_OUT                  76
#define EQ_EXECUTECMD_VOICE_ON                  77
#define EQ_EXECUTECMD_SCREENCAP                 78
#define EQ_EXECUTECMD_HISTORY_UP                79
#define EQ_EXECUTECMD_HISTORY_DOWN              80
#define EQ_EXECUTECMD_CHATLEFT                  81
#define EQ_EXECUTECMD_CHATRIGHT                 82
#define EQ_EXECUTECMD_CHATBEGIN                 83
#define EQ_EXECUTECMD_CHATEND                   84
#define EQ_EXECUTECMD_PAGEUP                    85
#define EQ_EXECUTECMD_PAGEDOWN                  86
#define EQ_EXECUTECMD_CMDMODE_SAY               87
#define EQ_EXECUTECMD_CMDMODE_EMOTE             88
#define EQ_EXECUTECMD_LOCK_WINDOWS              89
#define EQ_EXECUTECMD_TOGGLE_PLAYERWIN          90
#define EQ_EXECUTECMD_TOGGLE_PARTYWIN           91
#define EQ_EXECUTECMD_TOGGLE_TARGETWIN          92
#define EQ_EXECUTECMD_TOGGLE_SPELLSWIN          93
#define EQ_EXECUTECMD_TOGGLE_BUFFWIN            94
#define EQ_EXECUTECMD_TOGGLE_HOTBOXWIN          95
#define EQ_EXECUTECMD_TOGGLE_CHATWIN            96
#define EQ_EXECUTECMD_TOGGLE_MAINMENUWIN        97
#define EQ_EXECUTECMD_TOGGLE_ALTADVWIN          98
#define EQ_EXECUTECMD_TOGGLE_BAZAARWIN          99
#define EQ_EXECUTECMD_RTARGET                   100
#define EQ_EXECUTECMD_TOGGLE_FRIENDSWIN         101
#define EQ_EXECUTECMD_TOGGLE_PETINFOWIN         102
#define EQ_EXECUTECMD_TOGGLE_OPTIONSWIN         103
#define EQ_EXECUTECMD_TOGGLE_HELPWIN            104
#define EQ_EXECUTECMD_TOGGLE_SELECTORWIN        105
#define EQ_EXECUTECMD_TOGGLE_VIDEOMODEWIN       106
#define EQ_EXECUTECMD_TOGGLE_BAZAARSEARCHWIN    107
#define EQ_EXECUTECMD_TOGGLE_COMPASSWIN         108
#define EQ_EXECUTECMD_TOGGLE_RAIDWIN            109
#define EQ_EXECUTECMD_TOGGLE_MUSICPLAYERWIN     110
#define EQ_EXECUTECMD_FORWARD_CAM               111
#define EQ_EXECUTECMD_BACK_CAM                  112
#define EQ_EXECUTECMD_RIGHT_CAM                 113
#define EQ_EXECUTECMD_LEFT_CAM                  114
#define EQ_EXECUTECMD_PITCHUP_CAM               115
#define EQ_EXECUTECMD_PITCHDOWN_CAM             116
#define EQ_EXECUTECMD_TOGGLE_FPS                117
#define EQ_EXECUTECMD_TOGGLE_AVATAR             118
#define EQ_EXECUTECMD_TOGGLE_PETITION           119
#define EQ_EXECUTECMD_TOGGLE_MEMINFO            120
#define EQ_EXECUTECMD_FLY_UP                    121
#define EQ_EXECUTECMD_FLY_DOWN                  122
#define EQ_EXECUTECMD_TOGGLE_DEV_WINDOW         123
#define EQ_EXECUTECMD_ADD_ROUTE                 124
#define EQ_EXECUTECMD_LAY_PPOINT                125
#define EQ_EXECUTECMD_LAY_LINK                  126
//
#define EQ_EXECUTECMD_ESCAPE                    200 // void CDisplay::NewUIProcessEscape()

// direct input key scan codes (DIK_*)
#define EQ_KEY_NULL            0x00
#define EQ_KEY_ESCAPE          0x01
#define EQ_KEY_1               0x02
#define EQ_KEY_2               0x03
#define EQ_KEY_3               0x04
#define EQ_KEY_4               0x05
#define EQ_KEY_5               0x06
#define EQ_KEY_6               0x07
#define EQ_KEY_7               0x08
#define EQ_KEY_8               0x09
#define EQ_KEY_9               0x0A
#define EQ_KEY_0               0x0B
#define EQ_KEY_MINUS           0x0C
#define EQ_KEY_DASH            EQ_KEY_MINUS
#define EQ_KEY_EQUALS          0x0D
#define EQ_KEY_BACK            0x0E
#define EQ_KEY_BACKSPACE       EQ_KEY_BACK
#define EQ_KEY_TAB             0x0F
#define EQ_KEY_Q               0x10
#define EQ_KEY_W               0x11
#define EQ_KEY_E               0x12
#define EQ_KEY_R               0x13
#define EQ_KEY_T               0x14
#define EQ_KEY_Y               0x15
#define EQ_KEY_U               0x16
#define EQ_KEY_I               0x17
#define EQ_KEY_O               0x18
#define EQ_KEY_P               0x19
#define EQ_KEY_LBRACKET        0x1A
#define EQ_KEY_LEFT_BRACKET    EQ_KEY_LBRACKET
#define EQ_KEY_RBRACKET        0x1B
#define EQ_KEY_RIGHT_BRACKET   EQ_KEY_RBRACKET
#define EQ_KEY_RETURN          0x1C
#define EQ_KEY_ENTER           EQ_KEY_RETURN
#define EQ_KEY_LCONTROL        0x1D
#define EQ_KEY_LEFT_CONTROL    EQ_KEY_LCONTROL
#define EQ_KEY_A               0x1E
#define EQ_KEY_S               0x1F
#define EQ_KEY_D               0x20
#define EQ_KEY_F               0x21
#define EQ_KEY_G               0x22
#define EQ_KEY_H               0x23
#define EQ_KEY_J               0x24
#define EQ_KEY_K               0x25
#define EQ_KEY_L               0x26
#define EQ_KEY_SEMICOLON       0x27
#define EQ_KEY_APOSTROPHE      0x28
#define EQ_KEY_GRAVE           0x29
#define EQ_KEY_TILDE           EQ_KEY_GRAVE
#define EQ_KEY_LSHIFT          0x2A
#define EQ_KEY_LEFT_SHIFT      EQ_KEY_LSHIFT
#define EQ_KEY_BACKSLASH       0x2B
#define EQ_KEY_Z               0x2C
#define EQ_KEY_X               0x2D
#define EQ_KEY_C               0x2E
#define EQ_KEY_V               0x2F
#define EQ_KEY_B               0x30
#define EQ_KEY_N               0x31
#define EQ_KEY_M               0x32
#define EQ_KEY_COMMA           0x33
#define EQ_KEY_PERIOD          0x34
#define EQ_KEY_SLASH           0x35
#define EQ_KEY_RSHIFT          0x36
#define EQ_KEY_RIGHT_SHIFT     EQ_KEY_RSHIFT
#define EQ_KEY_MULTIPLY        0x37
#define EQ_KEY_NUMPADSTAR      EQ_KEY_NUMPAD_MULTIPLY
#define EQ_KEY_NUMPAD_MULTIPLY EQ_KEY_NUMPAD_MULTIPLY
#define EQ_KEY_LMENU           0x38
#define EQ_KEY_LALT            EQ_KEY_LMENU
#define EQ_KEY_LEFT_LALT       EQ_KEY_LMENU
#define EQ_KEY_SPACE           0x39
#define EQ_KEY_SPACEBAR        EQ_KEY_SPACE
#define EQ_KEY_CAPITAL         0x3A
#define EQ_KEY_CAPSLOCK        EQ_KEY_CAPITAL
#define EQ_KEY_CAPS_LOCK       EQ_KEY_CAPITAL
#define EQ_KEY_F1              0x3B
#define EQ_KEY_F2              0x3C
#define EQ_KEY_F3              0x3D
#define EQ_KEY_F4              0x3E
#define EQ_KEY_F5              0x3F
#define EQ_KEY_F6              0x40
#define EQ_KEY_F7              0x41
#define EQ_KEY_F8              0x42
#define EQ_KEY_F9              0x43
#define EQ_KEY_F10             0x44
#define EQ_KEY_NUMLOCK         0x45
#define EQ_KEY_NUM_LOCK        EQ_KEY_NUMLOCK
#define EQ_KEY_SCROLL          0x46
#define EQ_KEY_SCROLL_LOCK     EQ_KEY_SCROLL
#define EQ_KEY_NUMPAD7         0x47
#define EQ_KEY_NUMPAD8         0x48
#define EQ_KEY_NUMPAD9         0x49
#define EQ_KEY_SUBTRACT        0x4A
#define EQ_KEY_NUMPADMINUS     EQ_KEY_SUBTRACT
#define EQ_KEY_NUMPAD_SUBTRACT EQ_KEY_SUBTRACT
#define EQ_KEY_NUMPAD4         0x4B
#define EQ_KEY_NUMPAD5         0x4C
#define EQ_KEY_NUMPAD6         0x4D
#define EQ_KEY_ADD             0x4E
#define EQ_KEY_NUMPADPLUS      0x4E
#define EQ_KEY_NUMPAD_ADD      0x4E
#define EQ_KEY_NUMPAD1         0x4F
#define EQ_KEY_NUMPAD2         0x50
#define EQ_KEY_NUMPAD3         0x51
#define EQ_KEY_NUMPAD0         0x52
#define EQ_KEY_DECIMAL         0x53
#define EQ_KEY_NUMPADPERIOD    EQ_KEY_DECIMAL
#define EQ_KEY_NUMPAD_PERIOD   EQ_KEY_DECIMAL
#define EQ_KEY_OEM_102         0x56
#define EQ_KEY_F11             0x57
#define EQ_KEY_F12             0x58
#define EQ_KEY_F13             0x64
#define EQ_KEY_F14             0x65
#define EQ_KEY_F15             0x66
#define EQ_KEY_KANA            0x70
#define EQ_KEY_ABNT_C1         0x73
#define EQ_KEY_CONVERT         0x79
#define EQ_KEY_NOCONVERT       0x7B
#define EQ_KEY_NO_CONVERT      EQ_KEY_NOCONVERT
#define EQ_KEY_YEN             0x7D
#define EQ_KEY_ABNT_C2         0x7E
#define EQ_KEY_NUMPADEQUALS    0x8D
#define EQ_KEY_NUMPAD_EQUALS   EQ_KEY_NUMPADEQUALS
#define EQ_KEY_PREVTRACK       0x90
#define EQ_KEY_CIRCUMFLEX      EQ_KEY_PREVTRACK
#define EQ_KEY_PREV_TRACK      EQ_KEY_PREVTRACK
#define EQ_KEY_AT              0x91
#define EQ_KEY_COLON           0x92
#define EQ_KEY_UNDERLINE       0x93
#define EQ_KEY_KANJI           0x94
#define EQ_KEY_STOP            0x95
#define EQ_KEY_AX              0x96
#define EQ_KEY_UNLABELED       0x97
#define EQ_KEY_NEXTTRACK       0x99
#define EQ_KEY_NEXT_TRACK      EQ_KEY_NEXTTRACK
#define EQ_KEY_NUMPADENTER     0x9C
#define EQ_KEY_NUMPAD_ENTER    EQ_KEY_NUMPADENTER
#define EQ_KEY_RCONTROL        0x9D
#define EQ_KEY_RIGHT_CONTROL   EQ_KEY_RCONTROL
#define EQ_KEY_MUTE            0xA0
#define EQ_KEY_CALCULATOR      0xA1
#define EQ_KEY_PLAYPAUSE       0xA2
#define EQ_KEY_PLAY_PAUSE      EQ_KEY_PLAYPAUSE
#define EQ_KEY_MEDIASTOP       0xA4
#define EQ_KEY_MEDIA_STOP      EQ_KEY_MEDIASTOP
#define EQ_KEY_VOLUMEDOWN      0xAE
#define EQ_KEY_VOLUME_DOWN     EQ_KEY_VOLUMEDOWN
#define EQ_KEY_VOLUMEUP        0xB0
#define EQ_KEY_VOLUME_UP       EQ_KEY_VOLUMEUP
#define EQ_KEY_WEBHOME         0xB2
#define EQ_KEY_WEB_HOME        EQ_KEY_WEBHOME
#define EQ_KEY_NUMPADCOMMA     0xB3
#define EQ_KEY_NUMPAD_COMMA    EQ_KEY_NUMPADCOMMA
#define EQ_KEY_DIVIDE          0xB5
#define EQ_KEY_NUMPADSLASH     EQ_KEY_DIVIDE
#define EQ_KEY_NUMPAD_DIVIDE   EQ_KEY_DIVIDE
#define EQ_KEY_SYSRQ           0xB7
#define EQ_KEY_RMENU           0xB8
#define EQ_KEY_RALT            EQ_KEY_RMENU
#define EQ_KEY_RIGHT_ALT       EQ_KEY_RMENU
#define EQ_KEY_PAUSE           0xC5
#define EQ_KEY_HOME            0xC7
#define EQ_KEY_UP              0xC8
#define EQ_KEY_UPARROW         EQ_KEY_UP
#define EQ_KEY_UP_ARROW        EQ_KEY_UP
#define EQ_KEY_PRIOR           0xC9
#define EQ_KEY_PGUP            EQ_KEY_PRIOR
#define EQ_KEY_PAGE_UP         EQ_KEY_PRIOR
#define EQ_KEY_LEFT            0xCB
#define EQ_KEY_LEFTARROW       EQ_KEY_LEFT
#define EQ_KEY_LEFT_ARROW      EQ_KEY_LEFT
#define EQ_KEY_RIGHT           0xCD
#define EQ_KEY_RIGHTARROW      EQ_KEY_RIGHT
#define EQ_KEY_RIGHT_ARROW     EQ_KEY_RIGHT
#define EQ_KEY_END             0xCF
#define EQ_KEY_DOWN            0xD0
#define EQ_KEY_DOWNARROW       EQ_KEY_DOWN
#define EQ_KEY_DOWN_ARROW      EQ_KEY_DOWN
#define EQ_KEY_NEXT            0xD1
#define EQ_KEY_PGDN            EQ_KEY_NEXT
#define EQ_KEY_PAGE_DOWN       EQ_KEY_NEXT
#define EQ_KEY_INSERT          0xD2
#define EQ_KEY_DELETE          0xD3
#define EQ_KEY_LWIN            0xDB
#define EQ_KEY_LEFT_START      EQ_KEY_LWIN
#define EQ_KEY_RWIN            0xDC
#define EQ_KEY_RIGHT_START     EQ_KEY_RWIN
#define EQ_KEY_APPS            0xDD
#define EQ_KEY_POWER           0xDE
#define EQ_KEY_SLEEP           0xDF
#define EQ_KEY_WAKE            0xE3
#define EQ_KEY_WEBSEARCH       0xE5
#define EQ_KEY_WEB_SEARCH      EQ_KEY_WEBSEARCH
#define EQ_KEY_WEBFAVORITES    0xE6
#define EQ_KEY_WEB_FAVORITES   EQ_KEY_WEBFAVORITES
#define EQ_KEY_WEBREFRESH      0xE7
#define EQ_KEY_WEB_REFRESH     EQ_KEY_WEBREFRESH
#define EQ_KEY_WEBSTOP         0xE8
#define EQ_KEY_WEB_STOP        EQ_KEY_WEBSTOP
#define EQ_KEY_WEBFORWARD      0xE9
#define EQ_KEY_WEB_FORWARD     EQ_KEY_WEBFORWARD
#define EQ_KEY_WEBBACK         0xEA
#define EQ_KEY_WEB_BACK        EQ_KEY_WEBBACK
#define EQ_KEY_MYCOMPUTER      0xEB
#define EQ_KEY_MY_COMPUTER     EQ_KEY_MYCOMPUTER
#define EQ_KEY_MAIL            0xEC
#define EQ_KEY_MEDIASELECT     0xED
#define EQ_KEY_MEDIA_SELECT    EQ_KEY_MEDIASELECT

#define EQ_ADDRESS_ZONE_ID 0x007B9648 // uint32_t

#define EQ_ZONE_ID_NULL          0   // no zone at zero index
#define EQ_ZONE_ID_QEYNOS        1   // South Qeynos
#define EQ_ZONE_ID_QEYNOS2       2   // North Qeynos
#define EQ_ZONE_ID_QRG           3   // Surefall Glade
#define EQ_ZONE_ID_QEYTOQRG      4   // Qeynos Hills
#define EQ_ZONE_ID_HIGHPASS      5   // Highpass Hold
#define EQ_ZONE_ID_HIGHKEEP      6   // HighKeep
#define EQ_ZONE_ID_FREPORTN      8   // North Freeport
#define EQ_ZONE_ID_FREPORTW      9   // West Freeport
#define EQ_ZONE_ID_FREPORTE      10  // East Freeport
#define EQ_ZONE_ID_RUNNYEYE      11  // Clan RunnyEye
#define EQ_ZONE_ID_QEY2HH1       12  // West Karana
#define EQ_ZONE_ID_NORTHKARANA   13  // North Karana
#define EQ_ZONE_ID_SOUTHKARANA   14  // South Karana
#define EQ_ZONE_ID_EASTKARANA    15  // East Karana
#define EQ_ZONE_ID_BEHOLDER      16  // Gorge of King Xorbb
#define EQ_ZONE_ID_BLACKBURROW   17  // BlackBurrow
#define EQ_ZONE_ID_PAW           18  // Infected Paw
#define EQ_ZONE_ID_RIVERVALE     19  // Rivervale
#define EQ_ZONE_ID_KITHICOR      20  // Kithicor Forest
#define EQ_ZONE_ID_COMMONS       21  // West Commonlands
#define EQ_ZONE_ID_ECOMMONS      22  // East Commonlands
#define EQ_ZONE_ID_ERUDNINT      23  // Erudin Palace
#define EQ_ZONE_ID_ERUDNEXT      24  // Erudin
#define EQ_ZONE_ID_NEKTULOS      25  // Nektulos Forest
#define EQ_ZONE_ID_CSHOME        26  // Sunset Home
#define EQ_ZONE_ID_LAVASTORM     27  // Lavastorm Mountains
#define EQ_ZONE_ID_NEKTROPOS     28  // Nektropos
#define EQ_ZONE_ID_HALAS         29  // Halas
#define EQ_ZONE_ID_EVERFROST     30  // Everfrost Peaks
#define EQ_ZONE_ID_SOLDUNGA      31  // Solusek's Eye
#define EQ_ZONE_ID_SOLDUNGB      32  // Nagafen's Lair
#define EQ_ZONE_ID_MISTY         33  // Misty Thicket
#define EQ_ZONE_ID_NRO           34  // North Ro
#define EQ_ZONE_ID_SRO           35  // South Ro
#define EQ_ZONE_ID_BEFALLEN      36  // Befallen
#define EQ_ZONE_ID_OASIS         37  // Oasis of Marr
#define EQ_ZONE_ID_TOX           38  // Toxxulia Forest
#define EQ_ZONE_ID_HOLE          39  // The Hole
#define EQ_ZONE_ID_NERIAKA       40  // Neriak Foreign Quarter
#define EQ_ZONE_ID_NERIAKB       41  // Neriak Commons
#define EQ_ZONE_ID_NERIAKC       42  // Neriak Third Gate
#define EQ_ZONE_ID_NERIAKD       43  // Neriak Palace
#define EQ_ZONE_ID_NAJENA        44  // Najena
#define EQ_ZONE_ID_QCAT          45  // Qeynos Catacombs
#define EQ_ZONE_ID_INNOTHULE     46  // Innothule Swamp
#define EQ_ZONE_ID_FEERROTT      47  // The Feerrott
#define EQ_ZONE_ID_CAZICTHULE    48  // Cazic-Thule
#define EQ_ZONE_ID_OGGOK         49  // Oggok
#define EQ_ZONE_ID_RATHEMTN      50  // Mountains of Rathe
#define EQ_ZONE_ID_LAKERATHE     51  // Lake Rathetear
#define EQ_ZONE_ID_GROBB         52  // Grobb
#define EQ_ZONE_ID_AVIAK         53  // Aviak Village
#define EQ_ZONE_ID_GFAYDARK      54  // Greater Faydark
#define EQ_ZONE_ID_AKANON        55  // Ak'Anon
#define EQ_ZONE_ID_STEAMFONT     56  // Steamfont Mountains
#define EQ_ZONE_ID_LFAYDARK      57  // Lesser Faydark
#define EQ_ZONE_ID_CRUSHBONE     58  // Clan Crushbone
#define EQ_ZONE_ID_MISTMOORE     59  // Castle Mistmoore
#define EQ_ZONE_ID_KALADIMA      60  // Kaladim
#define EQ_ZONE_ID_FELWITHEA     61  // Felwithe
#define EQ_ZONE_ID_FELWITHEB     62  // Felwithe
#define EQ_ZONE_ID_UNREST        63  // Estate of Unrest
#define EQ_ZONE_ID_KEDGE         64  // Kedge Keep
#define EQ_ZONE_ID_GUKTOP        65  // Upper Guk
#define EQ_ZONE_ID_GUKBOTTOM     66  // Lower Guk
#define EQ_ZONE_ID_KALADIMB      67  // Kaladim
#define EQ_ZONE_ID_BUTCHER       68  // Butcherblock Mountains
#define EQ_ZONE_ID_OOT           69  // Ocean of Tears
#define EQ_ZONE_ID_CAULDRON      70  // Dagnor's Cauldron
#define EQ_ZONE_ID_AIRPLANE      71  // Plane of Sky
#define EQ_ZONE_ID_FEARPLANE     72  // Plane of Fear
#define EQ_ZONE_ID_PERMAFROST    73  // Permafrost Keep
#define EQ_ZONE_ID_KERRARIDGE    74  // Kerra Isle
#define EQ_ZONE_ID_PAINEEL       75  // Paineel
#define EQ_ZONE_ID_HATEPLANE     76  // The Plane of Hate
#define EQ_ZONE_ID_ARENA         77  // The Arena
#define EQ_ZONE_ID_FIELDOFBONE   78  // The Field of Bone
#define EQ_ZONE_ID_WARSLIKSWOOD  79  // Warsliks Wood
#define EQ_ZONE_ID_SOLTEMPLE     80  // Temple of Solusek Ro
#define EQ_ZONE_ID_DROGA         81  // Temple of Droga
#define EQ_ZONE_ID_CABWEST       82  // West Cabilis
#define EQ_ZONE_ID_SWAMPOFNOHOPE 83  // Swamp of No Hope
#define EQ_ZONE_ID_FIRIONA       84  // Firiona Vie
#define EQ_ZONE_ID_LAKEOFILLOMEN 85  // Lake of Ill Omen
#define EQ_ZONE_ID_DREADLANDS    86  // Dreadlands
#define EQ_ZONE_ID_BURNINGWOOD   87  // Burning Woods
#define EQ_ZONE_ID_KAESORA       88  // Kaesora
#define EQ_ZONE_ID_SEBILIS       89  // Old Sebilis
#define EQ_ZONE_ID_CITYMIST      90  // City of Mist
#define EQ_ZONE_ID_SKYFIRE       91  // Skyfire Mountains
#define EQ_ZONE_ID_FRONTIERMTNS  92  // Frontier Mountains
#define EQ_ZONE_ID_OVERTHERE     93  // The Overthere
#define EQ_ZONE_ID_EMERALDJUNGLE 94  // The Emerald Jungle
#define EQ_ZONE_ID_TRAKANON      95  // Trakanon's Teeth
#define EQ_ZONE_ID_TIMOROUS      96  // Timorous Deep
#define EQ_ZONE_ID_KURN          97  // Kurn's Tower
#define EQ_ZONE_ID_ERUDSXING     98  // Erud's Crossing
#define EQ_ZONE_ID_STONEBRUNT    100 // Stonebrunt Mountains
#define EQ_ZONE_ID_WARRENS       101 // The Warrens
#define EQ_ZONE_ID_KARNOR        102 // Karnor's Castle
#define EQ_ZONE_ID_CHARDOK       103 // Chardok
#define EQ_ZONE_ID_DALNIR        104 // Dalnir
#define EQ_ZONE_ID_CHARASIS      105 // Howling Stones
#define EQ_ZONE_ID_CABEAST       106 // East Cabilis
#define EQ_ZONE_ID_NURGA         107 // Mines of Nurga
#define EQ_ZONE_ID_VEESHAN       108 // Veeshan's Peak
#define EQ_ZONE_ID_VEKSAR        109 // Veksar
#define EQ_ZONE_ID_ICECLAD       110 // Iceclad Ocean
#define EQ_ZONE_ID_FROZENSHADOW  111 // Tower of Frozen Shadow
#define EQ_ZONE_ID_VELKETOR      112 // Velketor's Labyrinth
#define EQ_ZONE_ID_KAEL          113 // Kael Drakkal
#define EQ_ZONE_ID_SKYSHRINE     114 // Skyshrine
#define EQ_ZONE_ID_THURGADINA    115 // Thurgadin
#define EQ_ZONE_ID_EASTWASTES    116 // Eastern Wastes
#define EQ_ZONE_ID_COBALTSCAR    117 // Cobalt Scar
#define EQ_ZONE_ID_GREATDIVIDE   118 // Great Divide
#define EQ_ZONE_ID_WAKENING      119 // The Wakening Land
#define EQ_ZONE_ID_WESTWASTES    120 // Western Wastes
#define EQ_ZONE_ID_CRYSTAL       121 // Crystal Caverns
#define EQ_ZONE_ID_NECROPOLIS    123 // Dragon Necropolis
#define EQ_ZONE_ID_TEMPLEVEESHAN 124 // Temple of Veeshan
#define EQ_ZONE_ID_SIRENS        125 // Siren's Grotto
#define EQ_ZONE_ID_MISCHIEFPLANE 126 // Plane of Mischief
#define EQ_ZONE_ID_GROWTHPLANE   127 // Plane of Growth
#define EQ_ZONE_ID_SLEEPER       128 // Sleeper's Tomb
#define EQ_ZONE_ID_THURGADINB    129 // Icewell Keep
#define EQ_ZONE_ID_ERUDSXING2    130 // Marauder's Mire
#define EQ_ZONE_ID_SHADOWHAVEN   150 // Shadow Haven
#define EQ_ZONE_ID_BAZAAR        151 // The Bazaar
#define EQ_ZONE_ID_NEXUS         152 // The Nexus
#define EQ_ZONE_ID_ECHO          153 // Echo Caverns
#define EQ_ZONE_ID_ACRYLIA       154 // Acrylia Caverns
#define EQ_ZONE_ID_SHARVAHL      155 // Shar Vahl
#define EQ_ZONE_ID_PALUDAL       156 // Paludal Caverns
#define EQ_ZONE_ID_FUNGUSGROVE   157 // Fungus Grove
#define EQ_ZONE_ID_VEXTHAL       158 // Vex Thal
#define EQ_ZONE_ID_SSERU         159 // Sanctus Seru
#define EQ_ZONE_ID_KATTA         160 // Katta Castellum
#define EQ_ZONE_ID_NETHERBIAN    161 // Netherbian Lair
#define EQ_ZONE_ID_SSRATEMPLE    162 // Ssraeshza Temple
#define EQ_ZONE_ID_GRIEGSEND     163 // Grieg's End
#define EQ_ZONE_ID_THEDEEP       164 // The Deep
#define EQ_ZONE_ID_SHADEWEAVER   165 // Shadeweaver's Thicket
#define EQ_ZONE_ID_HOLLOWSHADE   166 // Hollowshade Moor
#define EQ_ZONE_ID_GRIMLING      167 // Grimling Forest
#define EQ_ZONE_ID_MSERU         168 // Marus Seru
#define EQ_ZONE_ID_LETALIS       169 // Mons Letalis
#define EQ_ZONE_ID_TWILIGHT      170 // The Twilight Sea
#define EQ_ZONE_ID_THEGREY       171 // The Grey
#define EQ_ZONE_ID_TENEBROUS     172 // The Tenebrous Mountains
#define EQ_ZONE_ID_MAIDEN        173 // The Maiden's Eye
#define EQ_ZONE_ID_DAWNSHROUD    174 // Dawnshroud Peaks
#define EQ_ZONE_ID_SCARLET       175 // The Scarlet Desert
#define EQ_ZONE_ID_UMBRAL        176 // The Umbral Plains
#define EQ_ZONE_ID_AKHEVA        179 // Akheva Ruins
#define EQ_ZONE_ID_ARENA2        180 // The Arena
#define EQ_ZONE_ID_JAGGEDPINE    181 // The Jaggedpine Forest
#define EQ_ZONE_ID_TUTORIAL      183 // Tutorial Zone
#define EQ_ZONE_ID_LOAD          184 // Loading
#define EQ_ZONE_ID_LOAD2         185 // Loading
#define EQ_ZONE_ID_CODECAY       200 // Ruins of Lxanvom
#define EQ_ZONE_ID_POJUSTICE     201 // Plane of Justice
#define EQ_ZONE_ID_POKNOWLEDGE   202 // Plane of Knowledge
#define EQ_ZONE_ID_POTRANQUILITY 203 // Plane of Tranquility
#define EQ_ZONE_ID_PONIGHTMARE   204 // Plane of Nightmare
#define EQ_ZONE_ID_PODISEASE     205 // Plane of Disease
#define EQ_ZONE_ID_POINNOVATION  206 // Plane of Innovation
#define EQ_ZONE_ID_POTORMENT     207 // Plane of Torment
#define EQ_ZONE_ID_POVALOR       208 // Plane of Valor
#define EQ_ZONE_ID_BOTHUNDER     209 // Torden, The Bastion of Thunder
#define EQ_ZONE_ID_POSTORMS      210 // Plane of Storms
#define EQ_ZONE_ID_HOHONORA      211 // Halls of Honor
#define EQ_ZONE_ID_SOLROTOWER    212 // Solusek Ro's Tower
#define EQ_ZONE_ID_POWAR         213 // Plane of War
#define EQ_ZONE_ID_POTACTICS     214 // Drunder, Fortress of Zek
#define EQ_ZONE_ID_POAIR         215 // Eryslai, the Kingdom of Wind
#define EQ_ZONE_ID_POWATER       216 // Reef of Coirnav
#define EQ_ZONE_ID_POFIRE        217 // Doomfire, The Burning Lands
#define EQ_ZONE_ID_POEARTHA      218 // Vegarlson, The Earthen Badlands
#define EQ_ZONE_ID_POTIMEA       219 // Plane of Time
#define EQ_ZONE_ID_HOHONORB      220 // Temple of Marr
#define EQ_ZONE_ID_NIGHTMAREB    221 // Lair of Terris Thule
#define EQ_ZONE_ID_POEARTHB      222 // Ragrax, Stronghold of the Twelve
#define EQ_ZONE_ID_POTIMEB       223 // Plane of Time

#define EQ_ZONE_TYPE_INDOORS  0x01
#define EQ_ZONE_TYPE_OUTDOORS 0x02
#define EQ_ZONE_TYPE_ANY      0xFF

// CDisplay::UpdateItemSlot()
#define EQ_ITEM_SLOT_HEAD      0
#define EQ_ITEM_SLOT_PRIMARY   7
#define EQ_ITEM_SLOT_SECONDARY 8

// equipment
#define EQ_INVENTORY_SLOT_EAR_LEFT    0
#define EQ_INVENTORY_SLOT_HEAD        1
#define EQ_INVENTORY_SLOT_FACE        2
#define EQ_INVENTORY_SLOT_EAR_RIGHT   3
#define EQ_INVENTORY_SLOT_NECK        4
#define EQ_INVENTORY_SLOT_SHOULDERS   5
#define EQ_INVENTORY_SLOT_ARMS        6
#define EQ_INVENTORY_SLOT_BACK        7
#define EQ_INVENTORY_SLOT_WRIST_LEFT  8
#define EQ_INVENTORY_SLOT_WRIST_RIGHT 9
#define EQ_INVENTORY_SLOT_RANGED      10
#define EQ_INVENTORY_SLOT_HANDS       11
#define EQ_INVENTORY_SLOT_PRIMARY     12
#define EQ_INVENTORY_SLOT_SECONDARY   13
#define EQ_INVENTORY_SLOT_RING_LEFT   14
#define EQ_INVENTORY_SLOT_RING_RIGHT  15
#define EQ_INVENTORY_SLOT_CHEST       16
#define EQ_INVENTORY_SLOT_LEGS        17
#define EQ_INVENTORY_SLOT_FEET        18
#define EQ_INVENTORY_SLOT_WAIST       19
#define EQ_INVENTORY_SLOT_AMMO        20
// pack
#define EQ_INVENTORY_SLOT_BAG1        21
#define EQ_INVENTORY_SLOT_BAG2        22
#define EQ_INVENTORY_SLOT_BAG3        23
#define EQ_INVENTORY_SLOT_BAG4        24
#define EQ_INVENTORY_SLOT_BAG5        25
#define EQ_INVENTORY_SLOT_BAG6        26
#define EQ_INVENTORY_SLOT_BAG7        27
#define EQ_INVENTORY_SLOT_BAG8        28
#define EQ_INVENTORY_SLOT_FIRST       EQ_INVENTORY_SLOT_EAR_LEFT
#define EQ_INVENTORY_SLOT_LAST        EQ_INVENTORY_SLOT_BAG8

#define EQ_ADDRESS_UI_STATE 0x0063B918 // uint16_t

#define EQ_UI_STATE_CLASSIC    0x01 // old UI from the year 1999
#define EQ_UI_STATE_DEFAULT    0x02
#define EQ_UI_STATE_FULLSCREEN 0x03

#define EQ_ADDRESS_WINDOW_HWND 0x00798540 // HWND

#define EQ_ADDRESS_RESOLUTION_WIDTH  0x00798564 // uint32_t
#define EQ_ADDRESS_RESOLUTION_HEIGHT 0x00798568 // uint32_t

#define EQ_MOUSE_CURSOR_WIDTH  16 // pixels
#define EQ_MOUSE_CURSOR_HEIGHT 16 // pixels

#define EQ_ADDRESS_MOUSE_X       0x008092E8 // uint32_t ; read/write, DirectInput Mouse
#define EQ_ADDRESS_MOUSE_Y       0x008092EC // uint32_t ; read/write, DirectInput Mouse
#define EQ_ADDRESS_MOUSE_SPEED_X 0x008092F0 // signed int
#define EQ_ADDRESS_MOUSE_SPEED_Y 0x008092F4 // signed int

#define EQ_ADDRESS_MOUSE_X_READ_ONLY 0x00798580 // uint16_t ; read-only
#define EQ_ADDRESS_MOUSE_Y_READ_ONLY 0x00798582 // uint16_t ; read-only

#define EQ_ADDRESS_MOUSE_CLICK_STATE 0x00798614 // uint32_t

#define EQ_MOUSE_CLICK_STATE_LEFT  0x01000001
#define EQ_MOUSE_CLICK_STATE_RIGHT 0x00010100
#define EQ_MOUSE_CLICK_STATE_BOTH  0x01010101

#define EQ_ADDRESS_MOUSE_LOOK_STATE 0x007985EA // uint32_t

#define EQ_MOUSE_LOOK_STATE_FALSE 0x00010000
#define EQ_MOUSE_LOOK_STATE_TRUE  0x00010001

#define EQ_ADDRESS_MOUSE_TIMER_RIGHT_CLICK 0x0079862C // uint32_t
#define EQ_ADDRESS_MOUSE_TIMER_LEFT_CLICK  0x00798630 // uint32_t

#define EQ_ADDRESS_CXWND_MOUSE_X 0x00809DD0 // uint32_t
#define EQ_ADDRESS_CXWND_MOUSE_Y 0x00809DD4 // uint32_t

#define EQ_ADDRESS_CXWND_MANAGER_MOUSE_HOVER_WINDOW 0x00809DD8 // uint32_t

#define EQ_MOUSE_WHEEL_DELTA_UP    120
#define EQ_MOUSE_WHEEL_DELTA_DOWN -120

#define EQ_MOUSE_ICON_ARROW             0
#define EQ_MOUSE_ICON_SIZE_ALL          1
#define EQ_MOUSE_ICON_SIZE_LEFT         2
#define EQ_MOUSE_ICON_SIZE_TOP          3
#define EQ_MOUSE_ICON_SIZE_RIGHT        4
#define EQ_MOUSE_ICON_SIZE_BOTTOM       5
#define EQ_MOUSE_ICON_SIZE_TOP_LEFT     6
#define EQ_MOUSE_ICON_SIZE_TOP_RIGHT    7
#define EQ_MOUSE_ICON_SIZE_BOTTOM_LEFT  8
#define EQ_MOUSE_ICON_SIZE_BOTTOM_RIGHT 9

// clip lines within a rectangle
// Cohen-Sutherland algorithm
// http://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
#define EQ_LINECLIP_INSIDE 0 // 0000
#define EQ_LINECLIP_LEFT   1 // 0001
#define EQ_LINECLIP_RIGHT  2 // 0010
#define EQ_LINECLIP_BOTTOM 4 // 0100
#define EQ_LINECLIP_TOP    8 // 1000

#define EQ_STRINGSPRITE_TYPE_1 0x51
#define EQ_STRINGSPRITE_TYPE_2 0x14

#define EQ_BAZAAR_ACTION_SEARCH_RESULTS 7
#define EQ_BAZAAR_ACTION_SEARCH_DONE    12

#define EQ_BAZAAR_COLUMN_INDEX_ITEM_NAME 1
#define EQ_BAZAAR_COLUMN_INDEX_PRICE     2
#define EQ_BAZAAR_COLUMN_INDEX_SELLER    3

#define EQ_ADDRESS_FOLLOW_DISTANCE 0x005E3840 // float
#define EQ_ADDRESS_FOLLOW_DISTANCE_ADD_1 0x005E44D4 // float
#define EQ_ADDRESS_FOLLOW_DISTANCE_ADD_2 0x005E86D0 // float

const char* EQ_STRING_PROCESS_NAME = "eqgame.exe";

const float EQ_PI = 3.14159265358979f;

const float EQ_HEADING_MAX        = 512.0f;
const float EQ_HEADING_MAX_HALVED = 256.0f;

const float EQ_CAMERA_PITCH_DEFAULT = -8.5f; // 119.5 + 8.5 = 128 everquest degrees = 90 degrees
const float EQ_CAMERA_PITCH_MIN     = -119.5f;
const float EQ_CAMERA_PITCH_MAX     =  119.5f;

const float EQ_FOLLOW_DISTANCE_MIN     = 5.0f;
const float EQ_FOLLOW_DISTANCE_DEFAULT = 20.0f;

const float EQ_FOLLOW_DISTANCE_ADD_1_DEFAULT = 15.0f;
const float EQ_FOLLOW_DISTANCE_ADD_2_DEFAULT = 30.0f;

// EQ_Character::eqspa_movement_rate
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_1       = 0.08f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_2       = 0.14f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_3       = 0.21f;
const float EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF = 0.30f;

std::vector<std::string> EQ_STRING_LIST_CLASS_NAME =
{
    "Unknown",
    "Warrior",
    "Cleric",
    "Paladin",
    "Ranger",
    "Shadowknight",
    "Druid",
    "Monk",
    "Bard",
    "Rogue",
    "Shaman",
    "Necromancer",
    "Wizard",
    "Magician",
    "Enchanter",
    "Beastlord",
    "Banker",
    "Warrior",
    "Cleric",
    "Paladin",
    "Ranger",
    "Shadowknight",
    "Druid",
    "Monk",
    "Bard",
    "Rogue",
    "Shaman",
    "Necromancer",
    "Wizard",
    "Magician",
    "Enchanter",
    "Beastlord",
    "Merchant",
};

std::vector<std::string> EQ_STRING_LIST_CLASS_SHORT_NAME =
{
    "UNK",
    "WAR",
    "CLR",
    "PAL",
    "RNG",
    "SHD",
    "DRU",
    "MNK",
    "BRD",
    "ROG",
    "SHM",
    "NEC",
    "WIZ",
    "MAG",
    "ENC",
    "BST",
    "BANKER",
    "WAR",
    "CLR",
    "PAL",
    "RNG",
    "SHD",
    "DRU",
    "MNK",
    "BRD",
    "ROG",
    "SHM",
    "NEC",
    "WIZ",
    "MAG",
    "ENC",
    "BST",
    "MERCHANT",
};

std::unordered_map<std::string, std::string> EQ_STRING_MAP_GROUND_SPAWN_NAME
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

std::unordered_map<std::string, std::string> EQ_STRING_MAP_DOOR_SPAWN_NAME =
{
    {"POKTELE500",    "Plane of Knowledge"}, // POK book

    {"POKAAPORT500",  "Ak'Anon"},
    {"POKCABPORT500", "Cabilis"},
    {"POKERPORT500",  "Erudin"},
    {"POKFELPORT500", "Felwithe"},
    {"POKFVPORT500",  "Firiona Vie"},
    {"POKFPTPORT500", "Freeport"},
    {"POKGROPORT500", "Grobb"},
    {"POKHALPORT500", "Halas"},
    {"POKKALPORT500", "Kaladim"},
    {"POKKELPORT500", "Kelethin"},
    {"POKNRKPORT500", "Neriak"},
    {"POKOGPORT500",  "Oggok"},
    {"POKOVPORT500",  "Overthere"},
    {"POKPPORT500",   "Paineel"},
    {"POKPTPORT500",  "Plane of Tranquility"},
    {"POKQNSPORT500", "Qeynos"},
    {"POKRVPORT500",  "Rivervale"},
    {"POKSHPORT500",  "Shar Vahl"},
    {"POKTGDPORT500", "The Great Divide"},
    {"POKTNPORT500",  "The Nexus"},

    {"TELECRYS200",   "Crystal Caverns"},

    ////{"FAYLEVATOR",    "Faydark Elevator"},
};

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_INVENTORY_EQUIPMENT_NAME =
{
    {0, "Left Ear"},
    {1, "Head"},
    {2, "Face"},
    {3, "Right Ear"},
    {4, "Neck"},
    {5, "Shoulders"},
    {6, "Arms"},
    {7, "Back"},
    {8, "Left Wrist"},
    {9, "Right Wrist"},
    {10, "Ranged"},
    {11, "Hands"},
    {12, "Primary"},
    {13, "Secondary"},
    {14, "Right Ring"},
    {15, "Left Ring"},
    {16, "Chest"},
    {17, "Legs"},
    {18, "Feet"},
    {19, "Waist"},
    {20, "Ammo"},
};

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_ITEM_TYPE_NAME =
{
    {1, "1H Sword"},
    {2, "2H Sword"},
    {3, "Axe"},
    {4, "Bow"},
    {5, "Dagger"},
    {6, "Flute"},
    {7, "Mace"},
    {8, "Staff"},
    {9, "Dwarven Axe"},
    {10, "Arrow"},
    {14, "War Hammer"},
    {15, "Trumpet"},
    {16, "Spear"},
    {17, "Short Spear"},
    {18, "Club"},
    {19, "Morning Star"},
    {20, "Rapier"},
    {21, "Lute"},
    {23, "Halberd"},
    {24, "2H Hammer"},
    {25, "2H Battle Axe"},
    {26, "Icy Blade(P)"},
    {27, "Book"},
    {28, "Open Book"},
    {29, "Writhing Staff"},
    {31, "Spike Club"},
    {32, "Broom"},
    {33, "Hamm Flat"},
    {34, "Shortsword"},
    {35, "Scepter"},
    {36, "Torch"},
    {37, "Cudgel"},
    {38, "Fishing Pole"},
    {39, "Scythe"},
    {40, "Harvester"},
    {41, "Scimitar"},
    {42, "Falchion"},
    {43, "Pick"},
    {45, "Crystal Staff"},
    {46, "Bone Wand"},
    {47, "Wand"},
    {48, "Lantern"},
    {49, "Maul"},
    {50, "Dirk"},
    {51, "Gold Scepter"},
    {52, "Shovel"},
    {53, "Flamberge"},
    {56, "Stein"},
    {57, "Broad Sword"},
    {58, "Bastard Sword"},
    {59, "Mining Pick"},
    {60, "Battle Axe"},
    {61, "Whip"},
    {62, "Flame Sword"},
    {63, "Generic (sm)"},
    {64, "Generic (lg)"},
    {65, "Letter"},
    {66, "Forge"},
    {67, "Idol"},
    {68, "Glowing Red Orb"},
    {69, "Oven"},
    {70, "Brew Barrel"},
    {71, "Claws"},
    {72, "Glowing Blue Cone"},
    {73, "Kiln"},
    {74, "Pottery Wheel"},
    {75, "Wooden Crook"},
    {76, "Vah Shir Sword"},
    {80, "Executioner Axe"},
    {81, "Lamentation"},
    {82, "Fer'Esh"},
    {83, "Silver 2H Axe"},
    {84, "Great Cleaver"},
    {85, "Serrated Sword"},
    {86, "Falchion"},
    {87, "Ykesha SS"},
    {88, "Swarmcaller"},
    {90, "Sword Passage"},
    {91, "Ulak"},
    {92, "Wurmslayer"},
    {94, "Duster Sapper"},
    {95, "Throneblade Ykesha"},
    {98, "Tooth"},
    {99, "Bladecatcher"},
    {100, "Sheer Blade"},
    {101, "Ketchata"},
    {102, "Spiked Club"},
    {103, "Partisan Spear"},
    {104, "KunzarKu'juch"},
    {105, "Shan'Tok"},
    {110, "Legchopper"},
    {115, "Mallet"},
    {118, "Envy"},
    {119, "Lupine Dagger"},
    {120, "Black Translucent Blade"},
    {121, "White Translucent Blade"},
    {122, "Velium 2H Staff"},
    {125, "Sarnak Skull Staff"},
    {126, "Wood Staff"},
    {128, "Loom"},
    {130, "Morning Star"},
    {131, "Defiance"},
    {132, "Harpoon"},
    {133, "Bowl"},
    {136, "Claw"},
    {140, "Ragebringer"},
    {141, "WAR Epic Blue"},
    {142, "WAR Epic Red"},
    {148, "BRD Epic"},
    {149, "RNG Epic"},
    {150, "DRU Epic"},
    {151, "MAG Epic"},
    {153, "NEC Epic"},
    {154, "SHM Epic"},
    {155, "WIZ Epic"},
    {156, "CLR Epic"},
    {157, "ENC Epic"},
    {159, "MNK Epic"},
    {160, "PAL Epic"},
    {163, "Red Jeweled Sword"},
    {164, "Blue Jeweled Sword"},
    {165, "Green Jeweled Sword"},
    {167, "Jeweled Dirk"},
    {168, "Velium Sword"},
    {170, "Velium 2H Axe"},
    {171, "Velium Axe"},
    {172, "Velium Spear"},
    {178, "Velium Alt Hammer"},
    {179, "Velium Hammer"},
    {180, "Crystal Sword"},
    {185, "Gold Hammer"},
    {186, "Velium Great Staff"},
    {187, "Velium Spear"},
    {188, "Velium Long Sword"},
    {189, "Velium Morning Star"},
    {190, "Velium 2H Sword"},
    {191, "Velium Short Sword"},
    {192, "Velium Scimitar"},
    {193, "Velium Warhammer"},
    {194, "Velium Dagger"},
    {195, "Velium Rapier"},
    {197, "Velium Lance"},
    {198, "BFG"},
    {199, "Crossbow"},
    {200, "Qeynos Shield"},
    {201, "Wooden Shield"},
    {202, "Kite Shield"},
    {203, "Small Round Shield"},
    {204, "Darkwood Shield"},
    {205, "Bone Shield"},
    {206, "Dark Shield"},
    {207, "Marrs Promise"},
    {209, "Shell Shield1"},
    {210, "Glowing White Shield"},
    {211, "Unicorn Shield"},
    {212, "Nautilus Shield"},
    {213, "Mistmoore Shield"},
    {214, "Chitin Shield"},
    {215, "Fear Shield"},
    {216, "Iksar Targ Shield"},
    {217, "Frogskin Shield"},
    {218, "Turtle Shell Shield"},
    {219, "Shell Shield2"},
    {221, "Sarnak Shield"},
    {222, "Ornate Runed Shield"},
    {223, "Ornate Runed Shield"},
    {226, "Grey Shield"},
    {228, "Velium Round Shield"},
    {230, "Vah Shir Shield"},
    {10201, "Book Staff"},
    {11501, "Drum"},
};

typedef std::vector<uint32_t> EQ_ZoneIDList_t;

// zones that have multiple levels going up and down
EQ_ZoneIDList_t EQ_ZONE_ID_LIST_VERTICAL =
{
    EQ_ZONE_ID_BEFALLEN,
    EQ_ZONE_ID_BLACKBURROW,
    EQ_ZONE_ID_CRYSTAL,
    EQ_ZONE_ID_HIGHKEEP,
    EQ_ZONE_ID_KURN,
    EQ_ZONE_ID_UNREST,
    EQ_ZONE_ID_WARRENS,
};

// zones that are indoors
EQ_ZoneIDList_t EQ_ZONE_ID_LIST_INDOORS =
{
    EQ_ZONE_ID_BEFALLEN,
    EQ_ZONE_ID_HIGHKEEP,
    EQ_ZONE_ID_KURN,
};

// zones that are safe cities with mostly no monsters
EQ_ZoneIDList_t EQ_ZONE_ID_LIST_CITY =
{
    EQ_ZONE_ID_POKNOWLEDGE,
    EQ_ZONE_ID_NEXUS,
    EQ_ZONE_ID_BAZAAR,
    EQ_ZONE_ID_FELWITHEA,
    EQ_ZONE_ID_FELWITHEB,
    EQ_ZONE_ID_GROBB,
    EQ_ZONE_ID_HALAS,
    EQ_ZONE_ID_OGGOK,
    EQ_ZONE_ID_RIVERVALE,
};

// font glyph sizes use ASCII table indexes
// used to get width of string when using font text

#define EQ_ASCII_TABLE_SIZE 128

int EQ_FONT_GLYPH_SIZES_ARIAL10[EQ_ASCII_TABLE_SIZE] =
{
    6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,
    2 ,3 ,3 ,4 ,4 ,7 ,5 ,2 ,3 ,3 ,3 ,5 ,2 ,3 ,2 ,2 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,2 ,2 ,5 ,5 ,5 ,4 ,
    8 ,5 ,5 ,6 ,6 ,5 ,5 ,6 ,6 ,2 ,4 ,5 ,4 ,7 ,6 ,6 ,5 ,6 ,6 ,5 ,5 ,6 ,5 ,7 ,5 ,5 ,5 ,2 ,2 ,2 ,3 ,4 ,
    3 ,4 ,4 ,4 ,4 ,4 ,2 ,5 ,4 ,2 ,2 ,3 ,2 ,6 ,4 ,4 ,4 ,5 ,3 ,4 ,2 ,4 ,3 ,5 ,3 ,3 ,4 ,3 ,3 ,3 ,5 ,6 ,
};

int EQ_FONT_GLYPH_SIZES_ARIAL12[EQ_ASCII_TABLE_SIZE] =
{
    7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,
    3 ,3 ,3 ,5 ,5 ,8 ,6 ,2 ,3 ,3 ,4 ,5 ,3 ,3 ,3 ,3 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,3 ,3 ,5 ,5 ,5 ,5 ,
    9 ,6 ,6 ,7 ,7 ,6 ,6 ,7 ,7 ,3 ,5 ,6 ,5 ,7 ,7 ,7 ,6 ,7 ,7 ,6 ,5 ,7 ,6 ,9 ,5 ,7 ,6 ,3 ,3 ,3 ,3 ,5 ,
    3 ,5 ,5 ,5 ,5 ,5 ,4 ,5 ,5 ,2 ,2 ,5 ,2 ,8 ,5 ,5 ,5 ,5 ,3 ,5 ,3 ,5 ,6 ,6 ,5 ,6 ,4 ,3 ,3 ,3 ,5 ,7 ,
};

int EQ_FONT_GLYPH_SIZES_ARIAL14[EQ_ASCII_TABLE_SIZE] =
{
    8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,
    3 ,2 ,4 ,6 ,6 ,10,7 ,2 ,4 ,4 ,4 ,6 ,3 ,4 ,3 ,3 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,3 ,3 ,6 ,6 ,6 ,6 ,
    11,8 ,7 ,7 ,7 ,6 ,6 ,8 ,7 ,2 ,5 ,7 ,6 ,8 ,7 ,8 ,6 ,8 ,7 ,7 ,6 ,7 ,8 ,10,7 ,8 ,7 ,3 ,3 ,3 ,5 ,6 ,
    4 ,6 ,6 ,6 ,6 ,6 ,4 ,6 ,6 ,2 ,2 ,5 ,2 ,8 ,6 ,6 ,6 ,6 ,4 ,6 ,3 ,6 ,6 ,10,6 ,6 ,6 ,4 ,2 ,4 ,6 ,8 ,
};

int EQ_FONT_GLYPH_SIZES_ARIAL15[EQ_ASCII_TABLE_SIZE] =
{
    9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,
    3 ,3 ,4 ,7 ,7 ,11,8 ,2 ,4 ,4 ,5 ,7 ,3 ,4 ,3 ,3 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,3 ,3 ,7 ,7 ,7 ,7 ,
    12,7 ,8 ,9 ,9 ,8 ,7 ,9 ,9 ,3 ,6 ,8 ,7 ,9 ,9 ,9 ,8 ,9 ,9 ,8 ,7 ,9 ,7 ,11,7 ,7 ,7 ,3 ,3 ,3 ,5 ,7 ,
    4 ,7 ,7 ,6 ,7 ,7 ,3 ,7 ,7 ,3 ,3 ,6 ,3 ,11,7 ,7 ,7 ,7 ,4 ,7 ,3 ,7 ,5 ,9 ,5 ,5 ,5 ,4 ,3 ,4 ,7 ,9 ,
};

int EQ_FONT_GLYPH_SIZES_ARIAL16[EQ_ASCII_TABLE_SIZE] =
{
    10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    4 ,3 ,5 ,7 ,7 ,12,9 ,2 ,4 ,4 ,5 ,8 ,4 ,4 ,4 ,4 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,4 ,4 ,8 ,8 ,8 ,7 ,
    13,9 ,9 ,9 ,9 ,9 ,8 ,10,9 ,3 ,6 ,9 ,7 ,11,9 ,10,9 ,10,9 ,9 ,7 ,9 ,9 ,13,7 ,9 ,7 ,4 ,4 ,4 ,5 ,7 ,
    4 ,7 ,7 ,7 ,7 ,7 ,3 ,7 ,7 ,3 ,3 ,7 ,3 ,11,7 ,7 ,7 ,7 ,4 ,7 ,4 ,7 ,5 ,9 ,7 ,7 ,7 ,4 ,3 ,4 ,8 ,10,
};

int EQ_FONT_GLYPH_SIZES_ARIAL20[EQ_ASCII_TABLE_SIZE] =
{
    13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,
    5 ,5 ,6 ,9 ,9 ,15,11,3 ,6 ,6 ,7 ,10,5 ,6 ,5 ,5 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,5 ,5 ,10,10,10,9 ,
    17,11,11,12,12,11,10,12,11,5 ,9 ,11,9 ,13,11,12,11,12,11,11,9 ,11,11,17,11,11,9 ,5 ,5 ,5 ,7 ,9 ,
    6 ,9 ,9 ,9 ,9 ,9 ,5 ,9 ,9 ,4 ,3 ,8 ,3 ,13,9 ,9 ,9 ,9 ,6 ,8 ,4 ,9 ,7 ,11,7 ,9 ,8 ,6 ,5 ,6 ,10,13,
};
