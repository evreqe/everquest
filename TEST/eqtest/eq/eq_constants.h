#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

const char* EQ_WINDOW_TITLE_DEFAULT = "EverQuest";

const uint32_t EQ_BASE_ADDRESS_VALUE = 0x400000;

const float EQ_PI = 3.14159265358979f;

const float EQ_HEADING_MIN = 0.0f;
const float EQ_HEADING_MAX = 512.0f;
const float EQ_HEADING_MAX_HALF = 256.0f;

const float EQ_SPAWN_PITCH_DEFAULT    = 0.0f;       // center view or look forward
const float EQ_SPAWN_PITCH_MIN        = -128.0f;    // look down
const float EQ_SPAWN_PITCH_MAX        = 128.0f;     // look up

const float EQ_SPAWN_HEADING_SPEED_DEFAULT    = 0.0f;      // stop turning
const float EQ_SPAWN_HEADING_SPEED_MIN        = -12.0f;    // turning right
const float EQ_SPAWN_HEADING_SPEED_MAX        = 12.0f;     // turning left

const float EQ_MELEE_DISTANCE_MIN    = 14.0f; // get_melee_range()
const float EQ_MELEE_DISTANCE_MAX    = 75.0f; // get_melee_range()

const uint32_t EQ_FAR_CLIP_PLANE_MIN = 0;
const uint32_t EQ_FAR_CLIP_PLANE_MAX = 20;

#define EQ_NUM_HOTBARS           11    // 10 + 1, potion belt was removed and replaced with another hotbar
#define EQ_NUM_HOTBAR_BUTTONS    12
#define EQ_NUM_SPELLS            59999
#define EQ_NUM_SPELL_GEMS        18
#define EQ_NUM_BAGS              10    // number of bags you can hold in your inventory
#define EQ_NUM_BAG_SLOTS         40    // number of slots a bag can have

#define EQ_BAZAAR_SEARCH_MAX_RESULTS_PER_TRADER 200 // max number of results you can get when searching

#define EQ_SPELL_ID_NULL 0xFFFFFFFF

#define EQ_UPDATE_ITEM_SLOT_HEAD         0
#define EQ_UPDATE_ITEM_SLOT_PRIMARY      7
#define EQ_UPDATE_ITEM_SLOT_SECONDARY    8

#define EQ_OFFSET_CEverQuest_GAME_STATE    0x5C8 // uint32_t, 1480 decimal    "Gamestate at crash = %d\n"

#define EQ_GAME_STATE_IN_GAME 5

#define EQ_OFFSET_EQPlayerManager_FIRST_SPAWN    0x08
#define EQ_OFFSET_EQPlayerManager_LAST_SPAWN     0x0C

#define EQ_OFFSET_CXWndManager_FONTS_ARRAY    0x11C    // add 0x04 to get the actual array of CTextureFont objects

#define EQ_OFFSET_CTextureFont_STYLE    0x04 // uint32_t, font size and style

#define EQ_FONT_INDEX_CDisplay__WriteTextHD2    2    // the third font in the fonts array

#define EQ_FONT_STYLE_MIN    0
#define EQ_FONT_STYLE_MAX    10

// use /chatfontsize to see the font style in the chat window
#define EQ_FONT_STYLE_CDisplay__WriteTextHD2    2     // used by the CDisplay::WriteTextHD2() function
#define EQ_FONT_STYLE_DEFAULT                   3     // default size used in the chat window
#define EQ_FONT_STYLE_FIXED_WIDTH               9     // small text and all characters are the same size, courier new or fixed sys font face
#define EQ_FONT_STYLE_NAME_SPRITE               10    // big text with drop shadow, used for text above players/npcs heads

// EQPlayer
// double check offsets after patch!
#define EQ_OFFSET_SPAWN_PREVIOUS                           0x04     // uint32_t pointer
#define EQ_OFFSET_SPAWN_NEXT                               0x08     // uint32_t pointer
#define EQ_OFFSET_SPAWN_JUMP_STRENGTH                      0x10     // float    // how high up you will jump, not forward
#define EQ_OFFSET_SPAWN_SWIM_STRENGTH                      0x14     // float
#define EQ_OFFSET_SPAWN_MOVEMENT_SPEED_BONUS               0x18     // float    // spells like SoW
#define EQ_OFFSET_SPAWN_AREA_FRICTION                      0x1C     // float    // sliding on slippery surfaces or walking up slopes
#define EQ_OFFSET_SPAWN_ACCELERATION_FRICTION              0x20     // float    // sliding on slippery surfaces or walking up slopes
#define EQ_OFFSET_SPAWN_COLLIDE_WITH_ACTOR_TYPE            0x24     // uint32_t
#define EQ_OFFSET_SPAWN_FLOOR_Z                            0x28     // float    // z-axis location where feet touch the ground
#define EQ_OFFSET_SPAWN_LAST_NAME                          0x38     // char[32]
#define EQ_OFFSET_SPAWN_Y                                  0x64     // float
#define EQ_OFFSET_SPAWN_X                                  0x68     // float
#define EQ_OFFSET_SPAWN_Z                                  0x6C     // float
#define EQ_OFFSET_SPAWN_MOVEMENT_SPEED                     0x7C     // float    // how fast you are moving while walking, running, riding a mount, etc
#define EQ_OFFSET_SPAWN_HEADING                            0x80     // float    // turning
#define EQ_OFFSET_SPAWN_HEADING_SPEED                      0x8C     // float    // turning speed, -12 to 12
#define EQ_OFFSET_SPAWN_PITCH                              0x90     // float    // look down and up, -128 to 128    // look forward, 0
#define EQ_OFFSET_SPAWN_UNDERWATER_ENVIRONMENT_TYPE        0x94     // uint32_t    // touching water or lava, etc
#define EQ_OFFSET_SPAWN_HEAD_ENVIRONMENT_TYPE              0xA0     // uint8_t
#define EQ_OFFSET_SPAWN_FEET_ENVIRONMENT_TYPE              0xA1     // uint8_t
#define EQ_OFFSET_SPAWN_BODY_ENVIRONMENT_TYPE              0xA2     // uint8_t
#define EQ_OFFSET_SPAWN_NAME_NUMBERED                      0xA4     // char[64]
#define EQ_OFFSET_SPAWN_NAME                               0xE4     // char[64]
#define EQ_OFFSET_SPAWN_TYPE                               0x125    // uint8_t
#define EQ_OFFSET_SPAWN_HEIGHT_Z                           0x138    // float    // height of player in z-axis units
#define EQ_OFFSET_SPAWN_HEIGHT                             0x13C    // float    // determines height, width, length, bounding radius, etc
#define EQ_OFFSET_SPAWN_ID                                 0x148    // uint32_t
#define EQ_OFFSET_SPAWN_STATE_FLAGS                        0x14C    // uint32_t    // uses bitwise flags (AND, OR)
#define EQ_OFFSET_SPAWN_VEHICLE_SPAWN                      0x150    // uint32_t    // boats, airships, etc
#define EQ_OFFSET_SPAWN_MOUNT_SPAWN                        0x154    // uint32_t    // horses, etc
#define EQ_OFFSET_SPAWN_MOUNT_RIDER_SPAWN                  0x158    // uint32_t    // spawn that is riding the mount
#define EQ_OFFSET_SPAWN_IS_TARGETABLE                      0x160    // uint8_t
// ******************** randomized after each patch ******************** //    #define PLAYERZONECLIENT
#define EQ_OFFSET_SPAWN_ZONE_ID                    0x4C0    // uint32_t
#define EQ_OFFSET_SPAWN_LEVEL                      0x401    // uint8_t
#define EQ_OFFSET_SPAWN_RACE                       0xF8C    // uint32_t
#define EQ_OFFSET_SPAWN_CLASS                      0xF94    // uint32_t
#define EQ_OFFSET_SPAWN_STANDING_STATE             0x344    // uint8_t
#define EQ_OFFSET_SPAWN_HP_CURRENT                 0x4A8    // uint32_t
#define EQ_OFFSET_SPAWN_HP_MAX                     0x320    // uint32_t
#define EQ_OFFSET_SPAWN_MANA_CURRENT               0x240    // uint32_t
#define EQ_OFFSET_SPAWN_MANA_MAX                   0x404    // uint32_t
#define EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          0x3E8    // uint32_t
#define EQ_OFFSET_SPAWN_ENDURANCE_MAX              0x228    // uint32_t
#define EQ_OFFSET_SPAWN_FOLLOW_SPAWN               0xF1C    // uint32_t pointer    // the spawn you are auto-following
// ********************************************************************* //

#define EQ_SIZE_SPAWN_NAME         64 // 0x40
#define EQ_SIZE_SPAWN_LAST_NAME    32 // 0x20

#define EQ_SPAWN_TYPE_PLAYER    0
#define EQ_SPAWN_TYPE_NPC       1
#define EQ_SPAWN_TYPE_CORPSE    2
#define EQ_SPAWN_TYPE_UNKNOWN   254 // custom value for our use

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_SPAWN_TYPE_NAME =
{
    {EQ_SPAWN_TYPE_PLAYER,      "Player"},
    {EQ_SPAWN_TYPE_NPC,         "NPC"},
    {EQ_SPAWN_TYPE_CORPSE,      "Corpse"},
    {EQ_SPAWN_TYPE_UNKNOWN,     "Unknown"},
};

#define EQ_ACTOR_TYPE_UNDEFINED        0
#define EQ_ACTOR_TYPE_PLAYER           1
#define EQ_ACTOR_TYPE_CORPSE           2
#define EQ_ACTOR_TYPE_SWITCH           3
#define EQ_ACTOR_TYPE_DOOR             3    // doors are switches
#define EQ_ACTOR_TYPE_MISSILE          4
#define EQ_ACTOR_TYPE_OBJECT           5
#define EQ_ACTOR_TYPE_LADDER           6
#define EQ_ACTOR_TYPE_TREE             7
#define EQ_ACTOR_TYPE_WALL             8
#define EQ_ACTOR_TYPE_PLACED_OBJECT    9

#define EQ_ENVIRONMENT_TYPE_WATER    5

#define EQ_SPAWN_STATE_FLAGS_IDLE                         0
#define EQ_SPAWN_STATE_FLAGS_OPEN                         1
#define EQ_SPAWN_STATE_FLAGS_WEAPON_SHEATHED              2
#define EQ_SPAWN_STATE_FLAGS_AGGRESIVE                    4
#define EQ_SPAWN_STATE_FLAGS_FORCED_AGGRESIVE             8
#define EQ_SPAWN_STATE_FLAGS_INSTRUMENT_EQUIPPED          16
#define EQ_SPAWN_STATE_FLAGS_STUNNED                      32
#define EQ_SPAWN_STATE_FLAGS_PRIMARY_WEAPON_EQUIPPED      64
#define EQ_SPAWN_STATE_FLAGS_SECONDARY_WEAPON_EQUIPPED    128

#define EQ_STANDING_STATE_STANDING    100
#define EQ_STANDING_STATE_FROZEN      102 // stunned, mesmerized or feared    "You lose control of yourself!"
#define EQ_STANDING_STATE_KNEELING    105 // looting or binding wounds
#define EQ_STANDING_STATE_SITTING     110
#define EQ_STANDING_STATE_DUCKING     111 // crouching
#define EQ_STANDING_STATE_FEIGN_DEATH 115 // pretending to be dead
#define EQ_STANDING_STATE_DEAD        120

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_STANDING_STATE_NAME =
{
    {EQ_STANDING_STATE_STANDING,       "Standing"},
    {EQ_STANDING_STATE_FROZEN,         "Frozen"},
    {EQ_STANDING_STATE_KNEELING,       "Kneeling"},
    {EQ_STANDING_STATE_SITTING,        "Sitting"},
    {EQ_STANDING_STATE_DUCKING,        "Ducking"},
    {EQ_STANDING_STATE_FEIGN_DEATH,    "Feign Death"},
    {EQ_STANDING_STATE_DEAD,           "Dead"},
};

#define EQ_OFFSET_CDisplay_CAMERA    0x118 // uint32_t pointer (CCamera)
#define EQ_OFFSET_CDisplay_TIMER     0x154 // uint32_t

// class CCamera
#define EQ_OFFSET_CCamera_VFTABLE                       0x00 // uint32_t pointer
#define EQ_OFFSET_CCamera_FIELD_OF_VIEW                 0x04 // float
#define EQ_OFFSET_CCamera_ASPECT_RATIO                  0x08 // float
#define EQ_OFFSET_CCamera_UNKNOWN_0x0C                  0x0C // float, 0.0 to 1.0
#define EQ_OFFSET_CCamera_DRAW_DISTANCE                 0x14 // float
#define EQ_OFFSET_CCamera_ACTOR_CLIP_PLANE              0x1C // float
#define EQ_OFFSET_CCamera_SHADOW_CLIP_PLANE             0x24 // float
#define EQ_OFFSET_CCamera_DRAW_DISTANCE_EX              0x28 // float
#define EQ_OFFSET_CCamera_FAR_CLIP_PLANE                0x2C // float
#define EQ_OFFSET_CCamera_SCREEN_WIDTH_HALF             0x38 // float
#define EQ_OFFSET_CCamera_SCREEN_HEIGHT_HALF            0x3C // float
#define EQ_OFFSET_CCamera_HEADING                       0xB0 // float, yaw
#define EQ_OFFSET_CCamera_PITCH                         0xB4 // float, pitch
#define EQ_OFFSET_CCamera_ROTATION                      0xB8 // float, roll
#define EQ_OFFSET_CCamera_Y                             0xBC // float
#define EQ_OFFSET_CCamera_X                             0xC0 // float
#define EQ_OFFSET_CCamera_Z                             0xC4 // float

const float EQ_CAMERA_FIELD_OF_VIEW_DEFAULT       = 45.0f;
const float EQ_CAMERA_FIELD_OF_VIEW_DRUID_MASK    = 60.0f;

const float EQ_CAMERA_PITCH_DEFAULT    = -8.5f;      // center view or look forward
const float EQ_CAMERA_PITCH_MIN        = -136.5f;    // look down
const float EQ_CAMERA_PITCH_MAX        = 119.5f;     // look up

#define EQ_CHAT_TEXT_COLOR_WHITE_0           0
#define EQ_CHAT_TEXT_COLOR_DEFAULT           1
#define EQ_CHAT_TEXT_COLOR_DARK_GREEN        2
#define EQ_CHAT_TEXT_COLOR_DEFAULT_2         3
#define EQ_CHAT_TEXT_COLOR_DARK_BLUE         4
#define EQ_CHAT_TEXT_COLOR_PINK              5
#define EQ_CHAT_TEXT_COLOR_DARK_GRAY         6
#define EQ_CHAT_TEXT_COLOR_WHITE_2           7
#define EQ_CHAT_TEXT_COLOR_DEFAULT_3         8
#define EQ_CHAT_TEXT_COLOR_DEFAULT_4         9
#define EQ_CHAT_TEXT_COLOR_WHITE             10
#define EQ_CHAT_TEXT_COLOR_DEFAULT_5         11
#define EQ_CHAT_TEXT_COLOR_GRAY              12
#define EQ_CHAT_TEXT_COLOR_RED               13
#define EQ_CHAT_TEXT_COLOR_GREEN             14
#define EQ_CHAT_TEXT_COLOR_YELLOW            15
#define EQ_CHAT_TEXT_COLOR_BLUE              16
#define EQ_CHAT_TEXT_COLOR_BLUE_2            17
#define EQ_CHAT_TEXT_COLOR_TEAL              18
#define EQ_CHAT_TEXT_COLOR_DEFAULT_6         19
#define EQ_CHAT_TEXT_COLOR_WHITE_20          20
#define EQ_CHAT_TEXT_COLOR_ORANGE            21
#define EQ_CHAT_TEXT_COLOR_BROWN             22

// CEverQuest__WriteTextHD2()    draws text on the screen
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

#define EQ_COLOR_ARGB_RED        0xFFFF0000
#define EQ_COLOR_ARGB_ORANGE     0xFFFF8000
#define EQ_COLOR_ARGB_YELLOW     0xFFFFFF00
#define EQ_COLOR_ARGB_GREEN      0xFF00FF00
#define EQ_COLOR_ARGB_BLUE       0xFF0000FF
#define EQ_COLOR_ARGB_PURPLE     0xFF8000FF
#define EQ_COLOR_ARGB_PINK       0xFFFF80FF
#define EQ_COLOR_ARGB_MAGENTA    0xFFFF00FF
#define EQ_COLOR_ARGB_TEAL       0xFF00FFFF
#define EQ_COLOR_ARGB_BROWN      0xFF804000
#define EQ_COLOR_ARGB_JADE       0xFF00FF80
#define EQ_COLOR_ARGB_GREY       0xFF808080
#define EQ_COLOR_ARGB_SILVER     0xFFC0C0C0
#define EQ_COLOR_ARGB_WHITE      0xFFFFFFFF
#define EQ_COLOR_ARGB_BLACK      0xFF000000

#define EQ_DIRECTION_NORTH         0
#define EQ_DIRECTION_NORTH_WEST    1
#define EQ_DIRECTION_NORTH_EAST    2
#define EQ_DIRECTION_SOUTH         3
#define EQ_DIRECTION_SOUTH_WEST    4
#define EQ_DIRECTION_SOUTH_EAST    5
#define EQ_DIRECTION_WEST          6
#define EQ_DIRECTION_EAST          7
#define EQ_DIRECTION_UNKNOWN       254

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_DIRECTION_NAME =
{
    {EQ_DIRECTION_NORTH,         "North"},
    {EQ_DIRECTION_NORTH_WEST,    "Northwest"},
    {EQ_DIRECTION_NORTH_EAST,    "Northeast"},
    {EQ_DIRECTION_SOUTH,         "South"},
    {EQ_DIRECTION_SOUTH_WEST,    "Southwest"},
    {EQ_DIRECTION_SOUTH_EAST,    "Southeast"},
    {EQ_DIRECTION_WEST,          "West"},
    {EQ_DIRECTION_EAST,          "East"},
    {EQ_DIRECTION_UNKNOWN,       "Unknown"},
};

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
#define EQ_RACE_INVISIBLE_MAN    127 // enchanter pets, auras, etc
#define EQ_RACE_IKSAR            128
#define EQ_RACE_VAH_SHIR         130
#define EQ_RACE_FROGLOK          330
#define EQ_RACE_DRAKKIN          522
#define EQ_RACE_CAMPFIRE         567 // fellowship campfires, etc

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_RACE_NAME =
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

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_RACE_SHORT_NAME =
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
#define EQ_CLASS_WARRIOR_GM          20 // guildmaster
#define EQ_CLASS_CLERIC_GM           21
#define EQ_CLASS_PALADIN_GM          22
#define EQ_CLASS_RANGER_GM           23
#define EQ_CLASS_SHADOWKNIGHT_GM     24
#define EQ_CLASS_DRUID_GM            25
#define EQ_CLASS_MONK_GM             26
#define EQ_CLASS_BARD_GM             27
#define EQ_CLASS_ROGUE_GM            28
#define EQ_CLASS_SHAMAN_GM           29
#define EQ_CLASS_NECROMANCER_GM      30
#define EQ_CLASS_WIZARD_GM           31
#define EQ_CLASS_MAGICIAN_GM         32
#define EQ_CLASS_ENCHANTER_GM        33
#define EQ_CLASS_BEASTLORD_GM        34
#define EQ_CLASS_BERSERKER_GM        35
#define EQ_CLASS_BANKER              40
#define EQ_CLASS_MERCHANT            41
#define EQ_CLASS_OBJECT                      62 // auras, controllers, crates, tents, corpses, etc
#define EQ_CLASS_GUILD_BANKER                66
#define EQ_CLASS_FELLOWSHIP_REGISTRAR        69
#define EQ_CLASS_FACTION_MERCHANT            70 // faction merchant?
#define EQ_CLASS_MERCENARY_LIAISON           71
#define EQ_CLASS_REAL_ESTATE_MERCHANT        72
#define EQ_CLASS_LOYALTY_MERCHANT            73
#define EQ_CLASS_TRIBUTE_MASTER              74

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_CLASS_NAME =
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

    {EQ_CLASS_OBJECT,                      "Object"},
    {EQ_CLASS_GUILD_BANKER,                "Guild Banker"},
    {EQ_CLASS_FELLOWSHIP_REGISTRAR,        "Fellowship Registrar"},
    {EQ_CLASS_FACTION_MERCHANT,            "Faction Merchant"},
    {EQ_CLASS_MERCENARY_LIAISON,           "Mercenary Liaison"},
    {EQ_CLASS_REAL_ESTATE_MERCHANT,        "Real Estate Merchant"},
    {EQ_CLASS_LOYALTY_MERCHANT,            "Loyalty Merchant"},
    {EQ_CLASS_TRIBUTE_MASTER,              "Tribute Master"},
};

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_CLASS_SHORT_NAME =
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

namespace EQ
{
    typedef struct _Location
    {
        float Y;
        float X;
        float Z;
    } Location, *Location_ptr;

    typedef struct _Point
    {
        float X;
        float Y;
        float Z;
    } Point, *Point_ptr;

    typedef struct _Line
    {
        float X1;
        float Y1;
        float Z1;
        float X2;
        float Y2;
        float Z2;
    } Line, *Line_ptr;

    typedef struct _Rectangle
    {
        float X1;
        float Y1;
        float Z1;
        float X2;
        float Y2;
        float Z2;
        float X3;
        float Y3;
        float Z3;
        float X4;
        float Y4;
        float Z4;
    } Rectangle, *Rectangle_ptr;

    typedef struct _CXRect
    {
        uint32_t X1; // Left      // upper left x
        uint32_t Y1; // Top       // upper left y
        uint32_t X2; // Right     // lower right x
        uint32_t Y2; // Bottom    // lower right y
    } CXRect, *CXRect_ptr;
} // namespace EQ
