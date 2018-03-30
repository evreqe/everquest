#pragma once

#include "eq_alternateabilities.h"
#include "eq_executecmd.h"
#include "eq_keys.h"
#include "eq_virtualkeycodes.h"
#include "eq_zones.h"

const float EQ_PI = 3.14159265358979f;

#define EQ_NUM_HOT_BARS       11    // 10 + 1, potion belt was removed and replaced with another hotbar
#define EQ_NUM_HOT_BUTTONS    12
#define EQ_NUM_SPELLS         59999
#define EQ_NUM_SPELL_GEMS     12

#define EQ_OFFSET_CEverQuest_GAME_STATE    0x5C8 // uint32_t, 1480 decimal    "Gamestate at crash = %d\n"

#define EQ_GAME_STATE_IN_GAME 5

#define EQ_OFFSET_EQPlayerManager_FIRST_SPAWN    0x08
#define EQ_OFFSET_EQPlayerManager_LAST_SPAWN     0x0C

// double check offsets after patch!
#define EQ_OFFSET_SPAWN_PREVIOUS                 0x04     // uint32_t pointer
#define EQ_OFFSET_SPAWN_NEXT                     0x08     // uint32_t pointer
#define EQ_OFFSET_SPAWN_LAST_NAME                0x38     // char[32]
#define EQ_OFFSET_SPAWN_Y                        0x64     // float
#define EQ_OFFSET_SPAWN_X                        0x68     // float
#define EQ_OFFSET_SPAWN_Z                        0x6C     // float
#define EQ_OFFSET_SPAWN_HEADING                  0x80     // float
#define EQ_OFFSET_SPAWN_NAME_NUMBERED            0xA4     // char[64]
#define EQ_OFFSET_SPAWN_NAME                     0xE4     // char[64]
#define EQ_OFFSET_SPAWN_TYPE                     0x125    // uint8_t
#define EQ_OFFSET_SPAWN_HEIGHT                   0x13C    // float
#define EQ_OFFSET_SPAWN_ID                       0x148    // uint32_t
// ******************** randomized after each patch ******************** //    #define PLAYERZONECLIENT
#define EQ_OFFSET_SPAWN_ZONE_ID                  0x240    // uint32_t
#define EQ_OFFSET_SPAWN_LEVEL                    0x500    // uint8_t
#define EQ_OFFSET_SPAWN_RACE                     0xF8C    // uint32_t
#define EQ_OFFSET_SPAWN_CLASS                    0xF94    // uint32_t
#define EQ_OFFSET_SPAWN_STANDING_STATE           0x494    // uint8_t
#define EQ_OFFSET_SPAWN_HP_CURRENT               0x3B0    // uint32_t
#define EQ_OFFSET_SPAWN_HP_MAX                   0x570    // uint32_t
#define EQ_OFFSET_SPAWN_MANA_CURRENT             0x508    // uint32_t
#define EQ_OFFSET_SPAWN_MANA_MAX                 0x3E0    // uint32_t
#define EQ_OFFSET_SPAWN_ENDURANCE_CURRENT        0x2B4    // uint32_t
#define EQ_OFFSET_SPAWN_ENDURANCE_MAX            0x490    // uint32_t
#define EQ_OFFSET_SPAWN_FOLLOW_SPAWN             0xF1C    // uint32_t pointer

#define EQ_SIZE_SPAWN_NAME         64 // 0x40
#define EQ_SIZE_SPAWN_LAST_NAME    32 // 0x20

#define EQ_SPAWN_TYPE_PLAYER    0
#define EQ_SPAWN_TYPE_NPC       1
#define EQ_SPAWN_TYPE_CORPSE    2

#define EQ_STANDING_STATE_STANDING    100
#define EQ_STANDING_STATE_FROZEN      102 // stunned, mesmerized or feared    "You lose control of yourself!"
#define EQ_STANDING_STATE_KNEELING    105 // looting or binding wounds
#define EQ_STANDING_STATE_SITTING     110
#define EQ_STANDING_STATE_DUCKING     111 // crouching
#define EQ_STANDING_STATE_FEIGN_DEATH 115 // pretending to be dead
#define EQ_STANDING_STATE_DEAD        120

#define EQ_OFFSET_CDisplay_CAMERA    0x118 // uint32_t pointer
#define EQ_OFFSET_CDisplay_TIMER     0x154 // uint32_t

#define EQ_OFFSET_CAMERA_FIELD_OF_VIEW                 0x04 // float
#define EQ_OFFSET_CAMERA_ASPECT_RATIO                  0x08 // float
#define EQ_OFFSET_CAMERA_UNKNOWN_0x0C                  0x0C // float, 0.0 to 1.0
#define EQ_OFFSET_CAMERA_DRAW_DISTANCE                 0x14 // float
#define EQ_OFFSET_CAMERA_ACTOR_CLIP_PLANE              0x1C // float
#define EQ_OFFSET_CAMERA_SHADOW_CLIP_PLANE             0x24 // float
#define EQ_OFFSET_CAMERA_SCREEN_WIDTH_HALF             0x38 // float
#define EQ_OFFSET_CAMERA_SCREEN_HEIGHT_HALF            0x3C // float
#define EQ_OFFSET_CAMERA_HEADING                       0xB0 // float, yaw
#define EQ_OFFSET_CAMERA_PITCH                         0xB4 // float, pitch
#define EQ_OFFSET_CAMERA_ROTATION                      0xB8 // float, roll
#define EQ_OFFSET_CAMERA_Y                             0xBC // float
#define EQ_OFFSET_CAMERA_X                             0xC0 // float
#define EQ_OFFSET_CAMERA_Z                             0xC4 // float

const float EQ_CAMERA_FIELD_OF_VIEW_DEFAULT       = 45.0f;
const float EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK    = 60.0f;

const float EQ_CAMERA_PITCH_DEFAULT    = -8.5f;      // center view or look forward
const float EQ_CAMERA_PITCH_MIN        = -136.5f;    // look down
const float EQ_CAMERA_PITCH_MAX        = 119.5f;     // look up

#define EQ_OFFSET_CXWnd_IS_OPEN 0x22  // uint8_t

#define EQ_OFFSET_CBazaarSearchWnd_BUY_ITEM_LIST_INDEX    0x270 // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM             0x278 // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME            0x278 // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME              0x2B8 // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE             0x304 // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                0x310 // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY          0x314 // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM            0x330 // second item in the search list starts here

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarConfirmationWnd_XWND_BUTTON_TO_ME         0x25C // uint32_t pointer    "To Me" button
#define EQ_OFFSET_CBazaarConfirmationWnd_XWND_BUTTON_TO_PARCELS    0x268 // uint32_t pointer    "To Parcels" button
#define EQ_OFFSET_CBazaarConfirmationWnd_XWND_BUTTON_CANCEL        0x26C // uint32_t pointer    "Cancel" button
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME               0x2C4 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME                 0x324 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID                   0x378 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE                0x37C // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY             0x388 // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

#define EQ_CHAT_TEXT_COLOR_YELLOW    15

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
#define EQ_RACE_INVISIBLE_MAN    127 // Enchanter pet
#define EQ_RACE_IKSAR            128
#define EQ_RACE_VAH_SHIR         130
#define EQ_RACE_FROGLOK          330
#define EQ_RACE_DRAKKIN          522

std::unordered_map<uint32_t, std::string> EQ_TABLE_RACE_NAME =
{
    {EQ_RACE_UNKNOWN,      "Unknown"},
    {EQ_RACE_HUMAN,        "Human"},
    {EQ_RACE_BARBARIAN,    "Barbarian"},
    {EQ_RACE_ERUDITE,      "Erudite"},
    {EQ_RACE_WOOD_ELF,     "Wood Elf"},
    {EQ_RACE_HIGH_ELF,     "High Elf"},
    {EQ_RACE_DARK_ELF,     "Dark Elf"},
    {EQ_RACE_HALF_ELF,     "Half Elf"},
    {EQ_RACE_DWARF,        "Dwarf"},
    {EQ_RACE_TROLL,        "Troll"},
    {EQ_RACE_OGRE,         "Ogre"},
    {EQ_RACE_HALFLING,     "Halfling"},
    {EQ_RACE_GNOME,        "Gnome"},
    {EQ_RACE_IKSAR,        "Iksar"},
    {EQ_RACE_VAH_SHIR,     "Vah Shir"},
    {EQ_RACE_FROGLOK,      "Froglok"},
    {EQ_RACE_DRAKKIN,      "Drakkin"},
};

std::unordered_map<uint32_t, std::string> EQ_TABLE_RACE_SHORT_NAME =
{
    {EQ_RACE_UNKNOWN,      "UNK"},
    {EQ_RACE_HUMAN,        "HUM"},
    {EQ_RACE_BARBARIAN,    "BAR"},
    {EQ_RACE_ERUDITE,      "ERU"},
    {EQ_RACE_WOOD_ELF,     "ELF"},
    {EQ_RACE_HIGH_ELF,     "HIE"},
    {EQ_RACE_DARK_ELF,     "DEF"},
    {EQ_RACE_HALF_ELF,     "HEF"},
    {EQ_RACE_DWARF,        "DWF"},
    {EQ_RACE_TROLL,        "TRL"},
    {EQ_RACE_OGRE,         "OGR"},
    {EQ_RACE_HALFLING,     "HFL"},
    {EQ_RACE_GNOME,        "GNM"},
    {EQ_RACE_IKSAR,        "IKS"},
    {EQ_RACE_VAH_SHIR,     "VAH"},
    {EQ_RACE_FROGLOK,      "FRG"},
    {EQ_RACE_DRAKKIN,      "DRK"},
};

#define EQ_CLASS_UNKNOWN             0
#define EQ_CLASS_WARRIOR             1
#define EQ_CLASS_CLERIC              2
#define EQ_CLASS_PALADIN             3
#define EQ_CLASS_RANGER              4
#define EQ_CLASS_SHADOWKNIGHT        5
#define EQ_CLASS_DRUID               6
#define EQ_CLASS_MONK                7
#define EQ_CLASS_BARD                8
#define EQ_CLASS_ROGUE               9
#define EQ_CLASS_SHAMAN              10
#define EQ_CLASS_NECROMANCER         11
#define EQ_CLASS_WIZARD              12
#define EQ_CLASS_MAGICIAN            13
#define EQ_CLASS_ENCHANTER           14
#define EQ_CLASS_BEASTLORD           15
#define EQ_CLASS_BERSERKER           16
#define EQ_CLASS_MERCENARY           17
#define EQ_CLASS_BANKER              40
#define EQ_CLASS_MERCHANT            41

std::unordered_map<uint32_t, std::string> EQ_TABLE_CLASS_NAME =
{
    {EQ_CLASS_UNKNOWN,         "Unknown"},
    {EQ_CLASS_WARRIOR,         "Warrior"},
    {EQ_CLASS_CLERIC,          "Cleric"},
    {EQ_CLASS_PALADIN,         "Paladin"},
    {EQ_CLASS_RANGER,          "Ranger"},
    {EQ_CLASS_SHADOWKNIGHT,    "Shadowknight"},
    {EQ_CLASS_DRUID,           "Druid"},
    {EQ_CLASS_MONK,            "Monk"},
    {EQ_CLASS_BARD,            "Bard"},
    {EQ_CLASS_ROGUE,           "Rogue"},
    {EQ_CLASS_SHAMAN,          "Shaman"},
    {EQ_CLASS_NECROMANCER,     "Necromancer"},
    {EQ_CLASS_WIZARD,          "Wizard"},
    {EQ_CLASS_MAGICIAN,        "Magician"},
    {EQ_CLASS_ENCHANTER,       "Enchanter"},
    {EQ_CLASS_BEASTLORD,       "Beastlord"},
    {EQ_CLASS_BERSERKER,       "Berserker"},
    {EQ_CLASS_MERCENARY,       "Mercenary"},
    {EQ_CLASS_BANKER,          "Banker"},
    {EQ_CLASS_MERCHANT,        "Merchant"},
};

std::unordered_map<uint32_t, std::string> EQ_TABLE_CLASS_SHORT_NAME =
{
    {EQ_CLASS_UNKNOWN,         "UNK"},
    {EQ_CLASS_WARRIOR,         "WAR"},
    {EQ_CLASS_CLERIC,          "CLR"},
    {EQ_CLASS_PALADIN,         "PAL"},
    {EQ_CLASS_RANGER,          "RNG"},
    {EQ_CLASS_SHADOWKNIGHT,    "SHD"},
    {EQ_CLASS_DRUID,           "DRU"},
    {EQ_CLASS_MONK,            "MNK"},
    {EQ_CLASS_BARD,            "BRD"},
    {EQ_CLASS_ROGUE,           "ROG"},
    {EQ_CLASS_SHAMAN,          "SHM"},
    {EQ_CLASS_NECROMANCER,     "NEC"},
    {EQ_CLASS_WIZARD,          "WIZ"},
    {EQ_CLASS_MAGICIAN,        "MAG"},
    {EQ_CLASS_ENCHANTER,       "ENC"},
    {EQ_CLASS_BEASTLORD,       "BST"},
    {EQ_CLASS_BERSERKER,       "BER"},
    {EQ_CLASS_MERCENARY,       "MERC"},
    ////{EQ_CLASS_BANKER,          "BANKER"},
    ////{EQ_CLASS_MERCHANT,        "MERCHANT"},
};

#define EQ_XWND_MESSAGE_LEFT_CLICK           1
#define EQ_XWND_MESSAGE_LEFT_MOUSE_UP        2
#define EQ_XWND_MESSAGE_RIGHT_CLICK          3
#define EQ_XWND_MESSAGE_LEFT_DOUBLE_CLICK    4
#define EQ_XWND_MESSAGE_HIT_ENTER            6
#define EQ_XWND_MESSAGE_CLOSE                10
#define EQ_XWND_MESSAGE_NEW_VALUE            14
#define EQ_XWND_MESSAGE_UNKNOWN              19
#define EQ_XWND_MESSAGE_MENU_SELECT          20
#define EQ_XWND_MESSAGE_MOUSE_OVER           21
#define EQ_XWND_MESSAGE_HISTORY              22
#define EQ_XWND_MESSAGE_LEFT_CLICK_HOLD      23
#define EQ_XWND_MESSAGE_LINK                 27
#define EQ_XWND_MESSAGE_FOCUS                33
#define EQ_XWND_MESSAGE_LOST_FOCUS           34

#define EQ_XWND_KEYBOARD_FLAG_SHIFT    1
#define EQ_XWND_KEYBOARD_FLAG_CTRL     2
#define EQ_XWND_KEYBOARD_FLAG_LALT     4
#define EQ_XWND_KEYBOARD_FLAG_RALT     8
