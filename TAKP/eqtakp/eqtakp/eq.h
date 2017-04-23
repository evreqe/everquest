#pragma once

#define EQ_ADDRESS_BASE 0x00400000

#define EQ_ADDRESS_TIMER 0x007989D4 // uint32_t ; time elapsed in milliseconds

#define EQ_ADDRESS_IS_IN_GAME 0x00798550 // uint8_t
#define EQ_ADDRESS_IS_AUTO_ATTACK_ENABLED 0x007F6FFE // uint8_t
#define EQ_ADDRESS_IS_NET_STATUS_ENABLED 0x007985EC // uint8_t
#define EQ_ADDRESS_IS_NOT_TYPING_IN_CHAT 0x0079856C // uint8_t
#define EQ_ADDRESS_IS_INSPECT_ENABLED 0x007CF28C // uint8_t ; /inspect on/off ; /toggleinspect
#define EQ_ADDRESS_IS_SHOW_NPC_NAMES_ENABLED 0x0063D6CC // uint8_t ; Options -> Display -> Show NPC Names

#define EQ_ADDRESS_DINPUT_ROOT            0x8092DC
#define EQ_ADDRESS_DINPUT_DEVICE_KEYBOARD 0x8092E0
#define EQ_ADDRESS_DINPUT_DEVICE_MOUSE    0x8092E4

#define EQ_ADDRESS_IS_KEY_PRESSED_SHIFT   0x0080931C // uint32_t
#define EQ_ADDRESS_IS_KEY_PRESSED_CONTROL 0x00809320 // uint32_t
#define EQ_ADDRESS_IS_KEY_PRESSED_ALT     0x0080932C // uint32_t

#define EQ_ADDRESS_IS_CAPSLOCK_ENABLED 0x00809324 // uint32_t
#define EQ_ADDRESS_IS_NUMLOCK_ENABLED  0x00809328 // uint32_t

#define EQ_TOOLTIP_TEXT_BACKGROUND_COLOR 0xC8000080 // ARGB 0xAARRGGBB

#define EQ_FONT_SIZE_DEFAULT 3

#define EQ_ADDRESS_POINTER_FONT_ARIAL10 0x0063D3A8
#define EQ_ADDRESS_POINTER_FONT_ARIAL12 0x0063D3AC
#define EQ_ADDRESS_POINTER_FONT_ARIAL14 0x0063D3B0
#define EQ_ADDRESS_POINTER_FONT_ARIAL15 0x0063D3B4
#define EQ_ADDRESS_POINTER_FONT_ARIAL16 0x0063D3B8
#define EQ_ADDRESS_POINTER_FONT_ARIAL20 0x0063D3BC

#define EQ_NUM_COMMANDS 277 // 0-276
#define EQ_NUM_BUFFS 15
#define EQ_NUM_SPELLS 4000
#define EQ_NUM_SPELL_GEMS 8
#define EQ_NUM_GROUP_MEMBERS 5
#define EQ_NUM_INVENTORY_SLOTS 21
#define EQ_NUM_INVENTORY_PACK_SLOTS 8
#define EQ_NUM_INVENTORY_BANK_SLOTS 8
#define EQ_NUM_SKILLS 74
#define EQ_NUM_SPELL_BOOK_SPELLS 250 // 32 pages, 8 spells per page, should be 256?
#define EQ_NUM_SPAWNS 8192
#define EQ_NUM_GUILDS 512
#define EQ_NUM_LOOT_WINDOW_SLOTS 30
#define EQ_NUM_HOTBUTTONS 10
#define EQ_NUM_HOTBUTTONS_TOTAL 100
#define EQ_NUM_CONTAINER_SLOTS 10
#define EQ_NUM_MODEL_BONE_CHILDREN 32

#define EQ_EXPERIENCE_BAR_VALUE_MAX 350 // the progress bar (0-350)
#define EQ_ALTERNATE_ADVANCEMENT_EXPERIENCE_BAR_VALUE_MAX 330 // the progress bar (0-330)

#define EQ_ITEM_SIZE_TINY   0
#define EQ_ITEM_SIZE_SMALL  1
#define EQ_ITEM_SIZE_MEDIUM 2
#define EQ_ITEM_SIZE_LARGE  3
#define EQ_ITEM_SIZE_GIANT  4

#define EQ_ITEM_NO_DROP_TRUE  0x00
#define EQ_ITEM_NO_DROP_FALSE 0xFF
#define EQ_ITEM_NO_RENT_TRUE  0x00
#define EQ_ITEM_NO_RENT_FALSE 0xFF

#define EQ_ADDRESS_ZONE_ID 0x007B9648 // uint32_t

#define EQ_ZONE_ID_FREPORTW       9   // West Freeport
#define EQ_ZONE_ID_COMMONS        21  // West Commonlands
#define EQ_ZONE_ID_ECOMMONS       22  // East Commonlands
#define EQ_ZONE_ID_CSHOME         26  // Sunset Home
#define EQ_ZONE_ID_FIELDOFBONE    78  // The Field of Bone
#define EQ_ZONE_ID_SLEEPER        128 // Sleeper's Tomb
#define EQ_ZONE_ID_BAZAAR         151 // The Bazaar
#define EQ_ZONE_ID_NEXUS          152 // The Nexus
#define EQ_ZONE_ID_SSERU          159 // Sanctus Seru
#define EQ_ZONE_ID_TUTORIAL       183 // Tutorial Zone
#define EQ_ZONE_ID_LOAD           184 // Loading
#define EQ_ZONE_ID_LOAD2          185 // Loading
#define EQ_ZONE_ID_POKNOWLEDGE    202 // The Plane of Knowledge
#define EQ_ZONE_ID_POTRANQUILITY  203 // Plane of Tranquility
#define EQ_ZONE_ID_POTIMEA        219 // Plane of Time A
#define EQ_ZONE_ID_POTIMEB        223 // Plane of Time B

#define EQ_BUFF_TYPE_DETRIMENTAL           0
#define EQ_BUFF_TYPE_BENEFICIAL            1
#define EQ_BUFF_TYPE_BENEFICIAL_GROUP_ONLY 2

#define EQ_SPAWN_TYPE_PLAYER        0
#define EQ_SPAWN_TYPE_NPC           1
#define EQ_SPAWN_TYPE_NPC_CORPSE    2
#define EQ_SPAWN_TYPE_PLAYER_CORPSE 3
#define EQ_SPAWN_TYPE_ANY_CORPSE    254 // custom unique value for hide corpse looted

#define EQ_SPAWN_TARGET_TYPE_CAN_TARGET     0x00
#define EQ_SPAWN_TARGET_TYPE_CAN_TARGET_2   0x01
#define EQ_SPAWN_TARGET_TYPE_CANNOT_TARGET  0x41

#define EQ_ADDRESS_CAMERA_VIEW 0x0063BE68 // uint32_t ; EQ_CAMERA_VIEW_x

#define EQ_CAMERA_VIEW_FIRST_PERSON  0
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

#define EQ_GUILD_ID_NULL 0xFFFF // uint16_t

#define EQ_GUILD_STATUS_MEMBER  0
#define EQ_GUILD_STATUS_OFFICER 1
#define EQ_GUILD_STATUS_LEADER  2

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
#define EQ_SKILL_SLAM                   111

#define EQ_HOTBUTTTON_TYPE1_ATTACK       1 // Melee or Range
#define EQ_HOTBUTTTON_TYPE1_SKILL1       2
#define EQ_HOTBUTTTON_TYPE1_SKILL2       3
#define EQ_HOTBUTTTON_TYPE1_SOCIAL_MACRO 4
#define EQ_HOTBUTTTON_TYPE1_ITEM         5
#define EQ_HOTBUTTTON_TYPE1_DEFAULT      6
#define EQ_HOTBUTTTON_TYPE1_SPELL_GEM    7

#define EQ_HOTBUTTTON_TYPE2_EMPTY 255

#define EQ_TEXT_COLOR_BLACK       0x00
#define EQ_TEXT_COLOR_GRAY        0x01
#define EQ_TEXT_COLOR_GREEN       0x02
#define EQ_TEXT_COLOR_GRAY2       0x03
#define EQ_TEXT_COLOR_BLUE        0x04
#define EQ_TEXT_COLOR_PINK        0x05
#define EQ_TEXT_COLOR_GRAY3       0x06
#define EQ_TEXT_COLOR_WHITE       0x07
#define EQ_TEXT_COLOR_GRAY4       0x08
#define EQ_TEXT_COLOR_GRAY5       0x09
#define EQ_TEXT_COLOR_WHITE2      0x0A
#define EQ_TEXT_COLOR_GRAY6       0x0B
#define EQ_TEXT_COLOR_LIGHT_GRAY  0x0C
#define EQ_TEXT_COLOR_RED         0x0D
#define EQ_TEXT_COLOR_LIGHT_GREEN 0x0E
#define EQ_TEXT_COLOR_YELLOW      0x0F
#define EQ_TEXT_COLOR_LIGHT_BLUE  0x10
#define EQ_TEXT_COLOR_GRAY7       0x11
#define EQ_TEXT_COLOR_CYAN        0x12
#define EQ_TEXT_COLOR_GRAY8       0x13
#define EQ_TEXT_COLOR_BLACK2      0x14

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

#define EQ_ADDRESS_MOUSE_X_REAL 0x008092E8 // DWORD ; read/write, DirectInput Mouse
#define EQ_ADDRESS_MOUSE_Y_REAL 0x008092EC // DWORD ; read/write, DirectInput Mouse

#define EQ_ADDRESS_MOUSE_X 0x00798580 // uint16_t ; read only
#define EQ_ADDRESS_MOUSE_Y 0x00798582 // uint16_t ; read-only

#define EQ_ADDRESS_MOUSE_CLICK_STATE 0x00798614 // uint32_t

#define EQ_MOUSE_CLICK_STATE_LEFT  0x01000001
#define EQ_MOUSE_CLICK_STATE_RIGHT 0x00010100
#define EQ_MOUSE_CLICK_STATE_BOTH  0x01010101

#define EQ_ADDRESS_MOUSE_LOOK_STATE 0x007985EA // uint32_t

#define EQ_MOUSE_LOOK_STATE_FALSE 0x00010000
#define EQ_MOUSE_LOOK_STATE_TRUE  0x00010001

#define EQ_ADDRESS_MOUSE_TIMER_RIGHT_CLICK 0x0079862C
#define EQ_ADDRESS_MOUSE_TIMER_LEFT_CLICK  0x00798630

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

const char* EQ_STRING_PROCESS_NAME = "eqgame.exe";

const float EQ_PI = 3.14159265358979f;

const float EQ_HEADING_MAX        = 512.0f;
const float EQ_HEADING_MAX_HALVED = 256.0f;

const float EQ_CAMERA_PITCH_DEFAULT = -8.5f; // 119.5 + 8.5 = 128 everquest degrees = 90 degrees
const float EQ_CAMERA_PITCH_MIN     = -119.5f;
const float EQ_CAMERA_PITCH_MAX     =  119.5f;

// EQ_Character::eqspa_movement_rate
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_1       = 0.08f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_2       = 0.14f;
const float EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN_3       = 0.21f;
const float EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF = 0.30f;

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
