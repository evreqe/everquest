#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#include "windows.h"

#include "eq.h"

namespace EQ
{

typedef struct _Location
{
    float Y;
    float X;
    float Z;
} Location, *Location_ptr;

typedef struct _Line
{
    float X1;
    float Y1;
    float Z1 = 1.0f;
    float X2;
    float Y2;
    float Z2 = 1.0f;
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

typedef struct _Mouse
{
    uint32_t X;
    uint32_t Y;
    uint32_t ClickState;
    uint32_t LookState;
    uint32_t LeftClickTimer;
    uint32_t RightClickTimer;
} Mouse, *Mouse_ptr;

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

typedef struct _Font
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Size;
} Font, *Font_ptr;

typedef struct _Camera
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t RegionNumber;
/* 0x0008 */ float Y;
/* 0x000C */ float X;
/* 0x0010 */ float Z;
/* 0x0014 */ float Heading; // Yaw
/* 0x0018 */ float Pitch;
/* 0x001C */ float Roll;
/* 0x0020 */ float FieldOfView;
/* 0x0024 */ float AspectRatio;
/* 0x0028 */ float Unknown0028;
/* 0x002C */ float Unknown002C;
/* 0x0030 */ float DrawDistance;
/* 0x0034 */ uint8_t Unknown0034[20];
/* 0x0048 */ uint32_t ResolutionWidth;
/* 0x004C */ uint32_t ResolutionHeight;
/* 0x0050 */ uint8_t Unknown0050[12];
/* 0x005C */ float Unknown005C;
/* 0x0060 */ float Unknown0060;
/* 0x0064 */ float ResolutionWidthHalf;
/* 0x0068 */ float ResolutionHeightHalf;
/* ...... */ 
} Camera, *Camera_ptr;

typedef struct _LightInstance
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t Unknown000C;
/* 0x0010 */ uint32_t Unknown0010;
/* 0x0014 */ uint32_t CurrentFrame;
/* 0x0018 */ uint32_t UpdateInterval;
/* 0x001C */ uint32_t SkipFrames;
/* ...... */ 
} LightInstance, *LightInstance_ptr;

typedef struct _Light
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ uint32_t Tag;
/* 0x000C */ uint32_t Type;
/* 0x0010 */ struct _LightInstance* LightInstance;
/* 0x0014 */ float Y;
/* 0x0018 */ float X;
/* 0x001C */ float Z;
/* 0x0020 */ float RadiusOfInfluence;
/* 0x0024 */ uint32_t Unknown0024;
/* 0x0028 */ uint32_t Unknown0028;
/* 0x002C */ uint32_t Unknown002C;
/* ...... */ 
} Light, *Light_ptr;

// sizeof 0x1A0
typedef struct _EQZoneInfo
{
/* 0x000 */ uint32_t Header;
/* 0x004 */ uint32_t Expansion;
/* 0x008 */ uint32_t ID;
/* 0x00C */ char ShortName[129]; // [0x81]
/* 0x08D */ char LongName[259]; // [0x103]
union
{
struct
{
/* 0x190 */ uint8_t Flag1; // 0x2 = Is Newbie Zone, 0x4 = Unknown, 0x20 = Is No Bind Zone
/* 0x191 */ uint8_t Flag2; // 0x40 = Is No Air Zone
/* 0x192 */ uint8_t Flag3; // 0x10 = Has Minimum Level
/* 0x193 */ uint8_t Flag4;
};
/* 0x190 */ uint32_t Flags;
};
/* 0x194 */ uint32_t ID2; // ID + 2242
/* 0x198 */ uint32_t POPValue; // this has something to do with Planes of Power zones
/* 0x19C */ uint32_t MinimumLevel; // level required to access zone
/* 0x1A0 */
} EQZoneInfo, *EQZoneInfo_ptr;

typedef struct _EQWorldData
{
/*0x000*/ void* VTable;
/*0x004*/ uint8_t Hour;
/*0x005*/ uint8_t Minute;
/*0x006*/ uint8_t Day;
/*0x007*/ uint8_t Month;
/*0x008*/ uint16_t Year;
/*0x00A*/ uint8_t Unknown00A[18]; // [0x12]
/*0x01C*/ struct _EQZoneInfo* ZoneList[EQ_NUM_ZONES];
} EQWorldData, *EQWorldData_ptr;

typedef struct _Zone
{
/* 0x0000 */ char PlayerName[64]; // [0x40]
/* 0x0040 */ char ShortName[32]; // [0x20]
/* 0x0060 */ char LongName[128]; // [0x80]
/* 0x00E0 */ uint8_t Unknown00E0[150];
/* 0x0176 */ uint8_t Type;
/* 0x0177 */ uint8_t FogColorRed[4];
/* 0x017B */ uint8_t FogColorGreen[4];
/* 0x017F */ uint8_t FogColorBlue[4];
/* 0x0183 */ uint8_t Unknown0183;
/* 0x0184 */ float Unknown0184;
/* 0x0188 */ float Unknown0188;
/* 0x018C */ float Unknown018C;
/* 0x0190 */ float Unknown0190;
/* 0x0194 */ float Unknown0194;
/* 0x0198 */ float Unknown0198;
/* 0x019C */ float Unknown019C;
/* 0x01A0 */ float Unknown01A0;
/* 0x01A4 */ float Gravity;
/* 0x01A8 */ uint8_t Unknown01A8;
/* 0x01A9 */ uint8_t Unknown01A9;
/* 0x01AA */ uint8_t Unknown01AA;
/* 0x01AB */ uint8_t Unknown01AB;
/* 0x01AC */ uint8_t Unknown01AC;
/* 0x01AD */ uint8_t Unknown01AD[45];
/* 0x01DA */ uint8_t SkyType;
/* 0x01DB */ uint8_t Unknown01DB[9];
/* 0x01E4 */ float ExperienceMultiplier;
/* 0x01E8 */ float SafeCoordsY; // CDisplay::MoveLocalPlayerToSafeCoords
/* 0x01EC */ float SafeCoordsX;
/* 0x01F0 */ float SafeCoordsZ;
/* 0x01F4 */ float Unknown01F4;
/* 0x01F8 */ float Unknown01F8;
/* 0x01FC */ float MinClip; // draw distance (minimum Far Clip Plane)
/* 0x0200 */ float MaxClip; // draw distance (maximum Far Clip Plane)
/* ...... */ 
} Zone, *Zone_ptr;

// sizeof 0x0A
typedef struct _Buff
{
/* 0x0000 */ uint8_t Unknown0000;
/* 0x0001 */ uint8_t CasterLevel; // level of player who casted the buff
/* 0x0002 */ uint8_t Modifier; // divide by 10 to get Bard song modifier
/* 0x0003 */ uint8_t Unknown0003;
/* 0x0004 */ uint16_t SpellID;
/* 0x0006 */ uint16_t Ticks; //  duration in ticks ; seconds = ticks * 3
/* 0x0008 */ uint16_t Unknown0008;
/* 0x000A */
} Buff, *Buff_ptr;

typedef struct _ItemCommon
{
/* 0x00E4 */ /* 0x0000 */ int8_t Strength;       // STR
/* 0x00E5 */ /* 0x0001 */ int8_t Stamina;        // STA
/* 0x00E6 */ /* 0x0002 */ int8_t Charisma;       // CHA
/* 0x00E7 */ /* 0x0003 */ int8_t Dexterity;      // DEX
/* 0x00E8 */ /* 0x0004 */ int8_t Intelligence;   // INT
/* 0x00E9 */ /* 0x0005 */ int8_t Agility;        // AGI
/* 0x00EA */ /* 0x0006 */ int8_t Wisdom;         // WIS
/* 0x00EB */ /* 0x0007 */ int8_t SaveMagic;      // SV MAGIC
/* 0x00EC */ /* 0x0008 */ int8_t SaveFire;       // SV FIRE
/* 0x00ED */ /* 0x0009 */ int8_t SaveCold;       // SV COLD
/* 0x00EE */ /* 0x000A */ int8_t SaveDisease;    // SV DISEASE
/* 0x00EF */ /* 0x000B */ int8_t SavePoison;     // SV POISON
/* 0x00F0 */ /* 0x000C */ int16_t Health;        // HP
/* 0x00F2 */ /* 0x000E */ int16_t Mana;          // Mana
/* 0x00F4 */ /* 0x0010 */ int8_t ArmorClass;     // AC
/* 0x00F5 */ /* 0x0011 */ uint8_t Unknown0xF5;
/* 0x00F6 */ /* 0x0012 */ uint8_t Unknown0xF6;
/* 0x00F7 */ /* 0x0013 */ uint8_t Unknown0xF7;
/* 0x00F8 */ /* 0x0014 */ uint8_t Light;
/* 0x00F9 */ /* 0x0015 */ uint8_t AttackDelay;    // Atk Delay
/* 0x00FA */ /* 0x0016 */ uint8_t Damage;         // DMG
/* 0x00FB */ /* 0x0017 */ uint8_t EffectFlag; // EQ_ITEM_EFFECT_FLAG_x
/* 0x00FC */ /* 0x0018 */ uint8_t Range;
/* 0x00FD */ /* 0x0019 */ uint8_t Type; // EQ_ITEM_TYPE_x
/* 0x00FE */ /* 0x001A */ uint8_t MagicOrLore;
union
{
/* 0x00FF */ /* 0x001A */ uint8_t CastingLevelEx; // also weapon proc level
/* 0x00FF */ /* 0x001A */ uint8_t HasteEx; // need to add +1 to value
};
/* 0x0100 */ /* 0x001B */ uint8_t Material; // 0=None, 1=Leather, 2=Chain, 3=Plate, 4=Silk, etc
/* 0x0101 */ /* 0x001C */ uint8_t Unknown0258[3];
/* 0x0104 */ /* 0x001F */ uint32_t Color;
/* 0x0108 */ /* 0x0023 */ uint8_t Unknown0264[2];
/* 0x010A */ /* 0x0025 */ uint16_t SpellIDEx;
/* 0x010C */ /* 0x0027 */ uint16_t Classes; // bitwise flag
/* 0x010E */ /* 0x0029 */ uint8_t Unknown0270[2];
/* 0x0110 */ /* 0x002B */ uint16_t Races; // bitwise flag
/* 0x0112 */ /* 0x002D */ uint8_t Unknown0274[2];
/* 0x0114 */ /* 0x002F */ uint8_t IsStackable;
union
{
/* 0x0115 */ /* 0x0030 */ uint8_t CastingLevel; // also weapon proc level
/* 0x0115 */ /* 0x0030 */ uint8_t Haste; // need to add +1 to value
};
union
{
/* 0x0116 */ /* 0x0031 */ uint8_t StackCount;
/* 0x0116 */ /* 0x0031 */ uint8_t Charges;
};
/* 0x0117 */ /* 0x0032 */ uint8_t EffectType;
/* 0x0118 */ /* 0x0033 */ uint16_t SpellID;
/* 0x011A */ /* 0x0035 */ uint8_t Unknown0123[10];
/* 0x0124 */ /* 0x003E */ uint16_t SkillModID;
/* 0x0126 */ /* 0x0040 */ int8_t SkillModPercent;
/* ...... */ 
} ItemCommon, *ItemCommon_ptr;

typedef struct _ItemContainer
{
/* 0x00E4 */ struct _Item* Item[EQ_NUM_CONTAINER_SLOTS];
/* 0x010C */ uint8_t Combine;
/* 0x010D */ uint8_t Capacity; // num slots
/* 0x010E */ uint8_t IsOpen;
/* 0x010F */ uint8_t SizeCapacity;
/* 0x0110 */ uint8_t WeightReduction; // percent
/* ...... */ 
} ItemContainer, *ItemContainer_ptr;

typedef struct _ItemBook
{
/* 0x00E4 */ uint8_t Unknown0228[3];
/* 0x00E7 */ char File[15];
/* ...... */ 
} ItemBook, *ItemBook_ptr;

// class EQ_Item
typedef struct _Item
{
/* 0x0000 */ char Name[64]; // [0x40]
/* 0x0040 */ char LoreName[80]; // [0x50]
/* 0x0090 */ char IDFile[6]; // [0x06]
/* 0x0096 */ uint8_t Unknown0096[24];
/* 0x00AE */ uint8_t Weight; // multiply by 0.1 for actual decimal weight
/* 0x00AF */ uint8_t NoRent; // 0x00 = True, 0xFF = False
/* 0x00B0 */ uint8_t NoDrop; // 0x00 = True, 0xFF = False
/* 0x00B1 */ uint8_t Size; // EQ_ITEM_SIZE_x
/* 0x00B2 */ uint8_t IsContainer;
/* 0x00B3 */ uint8_t Unknown00B3;
/* 0x00B4 */ uint16_t ID;
/* 0x00B6 */ uint16_t Icon;
/* 0x00B8 */ uint32_t EquipSlot;
/* 0x00BC */ uint32_t EquippableSlots; // flag
/* 0x00C0 */ uint32_t Cost; // value in copper, sells to merchant for value
/* 0x00C4 */ uint8_t Unknown00C4[32];
union
{
/* 0x00E4 */ ItemCommon    Common;
/* 0x00E4 */ ItemContainer Container;
/* 0x00E4 */ ItemBook      Book;
};
/* ...... */ 
} Item, *Item_ptr, EQ_Item, *EQ_Item_ptr;

// class EQ_Spell
// sizeof 0x110
// reference eqemulator /common/sp.dat.h
typedef struct _Spell
{
/* 0x0000 */ uint32_t ID;
/* 0x0004 */ float Range;
/* 0x0008 */ float AOERange;
/* 0x000C */ float PushBack;
/* 0x0010 */ float PushUp;
/* 0x0014 */ uint32_t CastTime;
/* 0x0018 */ uint32_t RecoveryTime;
/* 0x001C */ uint32_t RecastTime;
/* 0x0020 */ uint32_t DurationFormula;
/* 0x0024 */ uint32_t Duration;
/* 0x0028 */ uint32_t AOEDuration;
/* 0x002C */ uint16_t Mana;
/* 0x002E */ short Base[12];
/* 0x0046 */ short Max[12];
/* 0x005E */ uint16_t BookIcon;
/* 0x0060 */ uint16_t GemIcon;
/* 0x0062 */ short ReagentID[4];
/* 0x006A */ short ReagentCount[4];
/* 0x0072 */ uint8_t Unknown0146[8];
/* 0x007A */ uint8_t Calc[12];
/* 0x0086 */ uint8_t LightType;
/* 0x0087 */ uint8_t BuffType; // EQ_BUFF_TYPE_x
/* 0x0088 */ uint8_t Activated; // unknown
/* 0x0089 */ uint8_t ResistType;
/* 0x008A */ uint8_t Attribute[12];
/* 0x0096 */ uint8_t TargetType;
/* 0x0097 */ uint8_t FizzleAdjustment;
/* 0x0098 */ uint8_t SkillType;
/* 0x0099 */ uint8_t ZoneType; // 0x01 = Outdoors, 0x02 = Dungeons, 0xFF = Any
/* 0x009A */ uint8_t ZoneType2;
/* 0x009B */ uint8_t EnvironmentType;
/* 0x009C */ uint8_t TimeOfDay;
/* 0x009D */ uint8_t Level[15]; // minimum level to cast for each class
/* 0x00AC */ uint8_t Unknown0192[36];
/* 0x00D0 */ char* Name;        // [32]
/* 0x00D4 */ char* Target;      // [16]
/* 0x00D8 */ char* Extra;       // [32] ; Teleport zone, pet name summoned or item summoned
/* 0x00DC */ char* YouCast;     // [40]
/* 0x00E0 */ char* OtherCasts;  // [40]
/* 0x00E4 */ char* CastOnYou;   // [32]
/* 0x00E8 */ char* CastOnOther; // [40]
/* 0x00EC */ char* WearOff;     // [32]
/* ...... */ 
} Spell, *Spell_ptr, EQ_Spell, *EQ_Spell_ptr;

// class SpellManager
typedef struct _SpellList
{
    struct _Spell* Spell[EQ_NUM_SPELLS];
} SpellList, *SpellList_ptr, SpellManager, *SpellManager_ptr;

// 21 inventory slots
typedef struct _Inventory
{
/* 00 */ struct _Item* EarLeft;
/* 01 */ struct _Item* Head;
/* 02 */ struct _Item* Face;
/* 03 */ struct _Item* EarRight;
/* 04 */ struct _Item* Neck;
/* 05 */ struct _Item* Shoulders;
/* 06 */ struct _Item* Arms;
/* 07 */ struct _Item* Back;
/* 08 */ struct _Item* WristLeft;
/* 09 */ struct _Item* WristRight;
/* 10 */ struct _Item* Ranged;
/* 11 */ struct _Item* Hands;
/* 12 */ struct _Item* Primary;
/* 13 */ struct _Item* Secondary;
/* 14 */ struct _Item* RingLeft;
/* 15 */ struct _Item* RingRight;
/* 16 */ struct _Item* Chest;
/* 17 */ struct _Item* Legs;
/* 18 */ struct _Item* Feet;
/* 19 */ struct _Item* Waist;
/* 20 */ struct _Item* Ammo;
} Inventory, *Inventory_ptr;

// class EQ_Character
typedef struct _Character
{
/* 0x0000 */ uint8_t Unknown0000[2];
/* 0x0002 */ char Name[64]; // [0x40]
/* 0x0042 */ char LastName[70]; // [0x46] ; surname or title
/* 0x0088 */ uint16_t Gender; // EQ_GENDER_x
/* 0x008A */ uint16_t Race; // EQ_RACE_x
/* 0x008C */ uint16_t Class; // EQ_CLASS_x
/* 0x008E */ uint16_t Unknown008E;
/* 0x0090 */ uint16_t Level;
/* 0x0092 */ uint16_t Unknown0092;
/* 0x0094 */ uint32_t Experience; // EXP
/* 0x0098 */ uint16_t PracticePoints; // Training window
/* 0x009A */ uint16_t Mana;
/* 0x009C */ uint16_t BaseHP;
/* 0x009E */ uint16_t StunnedState; // EQ_STUNNED_STATE_x
/* 0x00A0 */ uint16_t BaseSTR;
/* 0x00A2 */ uint16_t BaseSTA;
/* 0x00A4 */ uint16_t BaseCHA;
/* 0x00A6 */ uint16_t BaseDEX;
/* 0x00A8 */ uint16_t BaseINT;
/* 0x00AA */ uint16_t BaseAGI;
/* 0x00AC */ uint16_t BaseWIS;
/* 0x00AE */ uint8_t Unknown00AE[438];
/* 0x0264 */ struct _Buff Buff[EQ_NUM_BUFFS];
/* 0x02FA */ uint8_t Unknown02FA[1080];
/* 0x0732 */ uint16_t SpellBook[EQ_NUM_SPELL_BOOK_SPELLS];
/* 0x0926 */ uint8_t Unknown0926[524];

// 0x09A6 // uint16_t Unknown9A6; // equals 20000?

/* 0x0B32 */ uint16_t MemorizedSpell[EQ_NUM_SPELL_GEMS]; // spell gem spell ids
/* 0x0B42 */ uint8_t Unknown0B42[14];
/* 0x0B50 */ uint16_t Unknown0B50;
/* 0x0B52 */ uint16_t Unknown0B52;
/* 0x0B54 */ float ZoneEnterY;
/* 0x0B58 */ float ZoneEnterX;
/* 0x0B5C */ float ZoneEnterZ;
/* 0x0B60 */ float Unknown0060;
/* 0x0B64 */ uint8_t StandingState; // EQ_STANDING_STATE_x
/* 0x0B65 */ uint8_t Unknown0B65[3];
/* 0x0B68 */ uint32_t Platinum;
/* 0x0B6C */ uint32_t Gold;
/* 0x0B70 */ uint32_t Silver;
/* 0x0B74 */ uint32_t Copper;
/* 0x0B78 */ uint32_t BankPlatinum;
/* 0x0B7C */ uint32_t BankGold;
/* 0x0B80 */ uint32_t BankSilver;
/* 0x0B84 */ uint32_t BankCopper;
/* 0x0B88 */ uint32_t CursorPlatinum; // currency held on the mouse cursor
/* 0x0B8C */ uint32_t CursorGold; // currency held on the mouse cursor
/* 0x0B90 */ uint32_t CursorSilver; // currency held on the mouse cursor
/* 0x0B94 */ uint32_t CursorCopper; // currency held on the mouse cursor
/* 0x0B98 */ uint8_t Unknown0B98[16];
/* 0x0BA8 */ uint16_t Skill[EQ_NUM_SKILLS];
/* 0x0C3C */ uint8_t Unknown0C3C[64];
/* 0x0C7C */ uint16_t Vision1;
/* 0x0C7E */ uint8_t Unknown0C7E[12];
/* 0x0C8A */ uint16_t Vision2;
/* 0x0C8C */ uint8_t Unknown0C8C[120];
/* 0x0D04 */ uint32_t IsSwimmingUnderwater;
/* 0x0D08 */ uint8_t Unknown0D08[4];
/* 0x0D0C */ uint8_t Unknown0D0C[4];
/* 0x0D10 */ uint8_t IsAutoSplitEnabled;
/* 0x0D11 */ uint8_t Unknown0D11[43];
/* 0x0D3C */ uint32_t Unknown0D3C;
/* 0x0D40 */ uint8_t Unknown0D40[20];
/* 0x0D54 */ uint32_t Hunger;
/* 0x0D58 */ uint32_t Thirst;
/* 0x0D5C */ uint8_t Unknown0D5C[20];
/* 0x0D70 */ uint32_t ZoneID;
/* 0x0D74 */ struct _Spawn* Spawn;
/* 0x0D78 */ struct _Item* CursorItem;
union
{
/* 0x0D7C */ struct _Inventory Inventory;
/* 0x0D7C */ struct _Item* InventoryItem[EQ_NUM_INVENTORY_SLOTS];
};
/* 0x0DD0 */ struct _Item* InventoryPackItem[EQ_NUM_INVENTORY_PACK_SLOTS];
/* 0x0DF0 */ uint8_t Unknown0DF0[116];
/* 0x0E64 */ uint32_t Unknown0E64;
/* 0x0E68 */ uint8_t Unknown0E68[32];
/* 0x0E88 */ uint32_t Unknown0E88;
/* 0x0E8C */ uint8_t Unknown0E8C[56];
/* 0x0EC4 */ uint32_t ZoneBoundID;
/* 0x0EC8 */ uint32_t Unknown0EC8;
/* 0x0ECC */ uint32_t Unknown0ECC;
/* 0x0ED0 */ uint32_t Unknown0ED0;
/* 0x0ED4 */ uint32_t ZoneBirthID;
/* 0x0ED8 */ float ZoneBoundY;
/* 0x0EDC */ uint32_t Unknown0EDC;
/* 0x0EE0 */ uint32_t Unknown0EE0;
/* 0x0EE4 */ uint32_t Unknown0EE4;
/* 0x0EE8 */ float ZoneBirthY;
/* 0x0EEC */ float ZoneBoundX;
/* 0x0EF0 */ uint32_t Unknown0EF0;
/* 0x0EF4 */ uint32_t Unknown0EF4;
/* 0x0EF8 */ uint32_t Unknown0EF8;
/* 0x0EFC */ float ZoneBirthX;
/* 0x0F00 */ float ZoneBoundZ;
/* 0x0F04 */ uint32_t Unknown0F04;
/* 0x0F08 */ uint32_t Unknown0F08;
/* 0x0F0C */ uint32_t Unknown0F0C;
/* 0x0F10 */ float ZoneBirthZ;
/* 0x0F14 */ uint8_t Unknown0F14[1080];
/* 0x134C */ uint16_t Deity; // EQ_DEITY_x
/* 0x134E */ uint16_t GuildID;
/* 0x1350 */ uint8_t Unknown1350[8];
/* 0x1358 */ uint8_t Unknown1358;
/* 0x1359 */ uint8_t Unknown1359;
/* 0x135A */ uint8_t Unknown135A;
/* 0x135B */ uint8_t Unknown135B;
/* 0x135C */ uint8_t Unknown135C;
/* 0x135D */ uint8_t Unknown135D;
/* 0x135E */ uint8_t Stamina; // yellow endurance bar ; 100 = Empty, 0 = Full ; EQ_PC::SetFatigue(x)
/* 0x135F */ uint8_t Unknown135F;
/* 0x1360 */ uint8_t Unknown1360;
/* 0x1361 */ uint8_t AnonymousState;
/* 0x1362 */ uint8_t Unknown1362;
/* 0x1363 */ uint8_t GuildStatus; // guild rank
/* 0x1364 */ uint8_t Drunkness; // 0 = Not Drunk, counts down over time
/* 0x1365 */ uint8_t Unknown1365[451];
/* 0x1528 */ uint32_t AlternateAdvancementExperience;
/* 0x152C */ uint8_t Unknown152C[476];
/* 0x1708 */ uint8_t AirSupply; // air remaining while swimming underwater
/* 0x1709 */ uint8_t Unknown1709[2475];
/* 0x20B4 */ struct _Item* InventoryBankItem[EQ_NUM_INVENTORY_BANK_SLOTS];
/* ...... */ 
} Character, *Character_ptr, EQ_Character, *EQ_Character_ptr;

// used for name and guild name above head of each spawn
typedef struct _StringSprite
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004; // id or index?
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t Unknown000C;
/* 0x0010 */ uint32_t Unknown0010;
/* 0x0014 */ uint32_t Unknown0014;
/* 0x0018 */ char* Text;
/* 0x001C */ uint32_t TextLength;
/* 0x0020 */ uint32_t Unknown0020;
/* 0x0024 */ uint32_t MaxScaleFactor1; // s3dSetStringSpriteMaxScaleFactor
/* 0x0028 */ float MaxScaleFactor2; // s3dSetStringSpriteMaxScaleFactor
/* 0x002C */ float MaxScaleFactor3; // s3dSetStringSpriteMaxScaleFactor
/* 0x0030 */ uint32_t IsYonClipEnabled; // s3dSetStringSpriteYonClip (draw distance)
/* 0x0034 */ uint32_t YonClipDistance; // s3dSetStringSpriteYonClip (draw distance)
/* 0x0038 */ float Unknown0038; // unknown modifier for scale
/* 0x003C */ uint32_t Width; // how wide the text is stretched
/* 0x0040 */ uint32_t Height; // how tall the text is stretched
/* 0x0044 */ float Unknown0044; // unknown multiplier
/* 0x0048 */ struct _ColorRGB Color; // s3dSetStringSpriteTint
/* ...... */ 
} StringSprite, *StringSprite_ptr;

// model skeleton animation
typedef struct _ModelTrack
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ char* Name; // x_TRACK, x_POINT_TRACK, etc
/* ...... */ 
} ModelTrack, *ModelTrack_ptr;

// T3D_DAG
// model skeleton bones
typedef struct _ModelBone
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ char* Name; // x_DAG, x_POINT_DAG, etc
/* 0x0008 */ struct _StringSprite* StringSprite;
/* 0x000C */ struct _ModelBone* ParentBone;
/* 0x0010 */ struct _Model* Model;
/* 0x0014 */ struct _ModelTrack* Track1;
/* 0x0018 */ struct _ModelTrack* Track2;
/* 0x001C */ uint8_t Unknown001C[96];
/* 0x007C */ float Y;
/* 0x0080 */ float X;
/* 0x0084 */ float Z;
/* 0x0088 */ uint8_t Unknown0088[96];
/* 0x00E8 */ uint32_t NumChildren;
/* 0x00EC */ struct _ModelBoneChildren* ChildrenBones;
/* ...... */ 
} ModelBone, *ModelBone_ptr;

typedef struct _ModelBoneChildren
{
/* 0x0000 */ struct _ModelBone* Child[EQ_NUM_MODEL_BONE_CHILDREN];
} ModelBoneChildren, *ModelBoneChildren_ptr;

typedef struct _ActorCollision
{
/* 0x0000 */ uint32_t CollisionVolumeType;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ float CollisionSize;
/* ...... */ 
} ActorCollision, *ActorCollision_ptr;

// T3D_tagACTORINSTANCE
typedef struct _ActorInstance
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t Unknown000C;
/* 0x0010 */ float WorldX;
/* 0x0014 */ float WorldY;
/* 0x0018 */ float WorldZ;
/* 0x001C */ uint32_t Unknown001C;
/* 0x0020 */ uint32_t Unknown0020;
/* 0x0024 */ uint32_t Unknown0024;
/* 0x0028 */ uint32_t RegionNumber;
/* 0x002C */ struct _ActorCollision* ActorCollision;
/* 0x0030 */ uint32_t Unknown0030;
/* 0x0034 */ float ScaleFactor;
/* 0x0038 */ float BoundingRadius;
/* 0x003C */ uint8_t Unknown003C[36];
union
{
/* 0x0060 */ struct _Spawn* UserData;
/* 0x0060 */ struct _Spawn* Spawn;
};
/* ...... */ 
} ActorInstance, *ActorInstance_ptr;

typedef struct _Model
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t Unknown000C;
/* 0x0010 */ uint32_t Unknown0010;
/* 0x0014 */ uint32_t Unknown0014;
/* 0x0018 */ uint32_t Unknown0018;
/* 0x001C */ struct _ActorInstance* ActorInstance;
/* 0x0020 */ uint32_t NumBones; // includes Root
/* 0x0024 */ struct _ModelBone* RootBone; // first bone
/* ...... */ 
} Model, *Model_ptr;

typedef struct _Actor
{
/* 0x0000 */ struct _ActorInstance* ActorInstance;
/* 0x0004 */ struct _Light* Light; // PointLight
/* 0x0008 */ char ActorDef[64]; // xxx_ACTORDEF string (HUM_ACTORDEF, ELM_ACTORDEF, etc)
/* 0x0048 */ float Z;
/* 0x004C */ float ZCeiling; // Z axis of the ceiling or first collision above player
/* 0x0050 */ uint32_t Unknown0050; // EqMobileEmitter*
/* 0x0054 */ uint32_t Unknown0054;
/* 0x0058 */ uint32_t UnknownTimer1;
/* 0x005C */ uint32_t UnknownTimer2;
/* 0x0060 */ uint32_t UnknownTimer3;
/* 0x0064 */ uint32_t UnknownTimer4;
/* 0x0068 */ uint32_t Unknown0068;
/* 0x006C */ uint32_t Unknown006C;
/* 0x0070 */ uint32_t Unknown0070;
/* 0x0074 */ uint32_t UnknownTimer5;
/* 0x0078 */ uint32_t UnknownTimer6;
/* 0x007C */ uint32_t UnknownTimer7;
/* 0x0080 */ uint16_t LevitationMovementCounter; // loops from 0 to 512 while levitating, causes up/down movement, 0xFFFF = Not Levitating
/* 0x0082 */ uint16_t DrunkMovementCounter; // loops from 0 to 512 while drunk, causes left/right movement, 0xFFFF = Not Drunk
/* 0x0084 */ uint16_t Unknown0084;
/* 0x0086 */ uint16_t Unknown0086;
/* 0x0088 */ float DrunkMovementModifier; // how far left/right the player moves while drunk
/* 0x008C */ float LevitationMovementModifier; // how far up/down the player moves while levitating
/* 0x0090 */ uint8_t IsAffectedByGravity; // gravity is enabled for the player (disabled while levitating)
/* 0x0091 */ uint8_t Unknown0091; // equals 0, 11 or 13
/* 0x0092 */ uint8_t Unknown0092;
/* 0x0093 */ uint8_t Unknown0093;
/* 0x0094 */ uint32_t Unknown0094; // pointer, static address 0x006EC6E8 has same value
/* 0x0098 */ uint32_t Unknown0098; // pointer, static address 0x006EC6E8 has same value
/* 0x009C */ uint32_t Unknown009C; // pointer, static address 0x006EC6E8 has same value
/* 0x00A0 */ uint8_t IsSwimmingUnderwater;
/* 0x00A1 */ uint8_t SwimmingWaterType; // 5,6,9,10 = Water, 7 = Lava, 8 = Freezing Water (7 and 8 cause damage!)
/* 0x00A2 */ uint8_t SwimmingFeetTouchingWater; // 0 = False, 5 = True
/* 0x00A3 */ uint8_t SwimmingUnknown1; // 0 = False, 5 = True
/* 0x00A4 */ uint8_t SwimmingUnknown2;
/* 0x00A5 */ uint8_t SwimmingUnknown3;
/* 0x00A6 */ uint8_t SwimmingUnknown4;
/* 0x00A7 */ uint8_t SwimmingUnknown5;
/* 0x00A8 */ float MovementFriction1; // used for sliding on ice or slippery surfaces (Default = 0.625)
/* 0x00AC */ float MovementFriction2; // used for sliding on ice or slippery surfaces (Default = 0.8000000119)
/* 0x00B0 */ float JumpHeightModifier; // how high the player jumps (Default = 1.350000024)
/* 0x00B4 */ float Unknown00B4;
/* 0x00B8 */ float Unknown00B8;
/* 0x00BC */ float MovementSpeedModifier; // how much slower/faster you move
/* 0x00C0 */ uint8_t Unknown00C0[196];
/* 0x0184 */ uint32_t Animation;
/* 0x0188 */ uint8_t Unknown0188[44];
/* 0x01B4 */ uint32_t IsInvisible; // NPCs only? used by /hidecorpse command
/* 0x01B8 */ uint8_t Unknown01B8[168];
/* 0x0260 */ uint32_t IsHoldingBoth;
/* 0x0264 */ uint32_t IsHoldingSecondary;
/* 0x0268 */ uint32_t IsHoldingPrimary;
/* 0x026C */ uint8_t Unknown026C[4];
/* 0x0270 */ uint8_t Unknown0270[4];
/* 0x0274 */ uint8_t Unknown0274[4];
/* 0x0278 */ uint8_t Unknown0278[4];
/* 0x027C */ uint16_t CastingSpellID;
/* 0x027E */ uint8_t CastingSpellGemNumber; // 255 = Bard Singing
/* 0x027F */ uint8_t Unknown027F;
/* 0x0280 */ uint8_t Unknown0280[4];
/* 0x0284 */ struct _Model* Model;
/* 0x0288 */ struct _ModelBone* ModelBoneHeadPoint;
/* 0x028C */ struct _ModelBone* ModelBoneHead;
/* 0x0290 */ struct _ModelBone* ModelBoneUnknown;
/* 0x0294 */ struct _ModelBone* ModelBoneRightPoint;
/* 0x0298 */ struct _ModelBone* ModelBoneLeftPoint;
/* 0x029C */ struct _ModelBone* ModelBoneShieldPoint;
/* 0x02A0 */ uint8_t Unknown02A0[128];
/* 0x0320 */ uint8_t MovementType; // EQ_MOVEMENT_TYPE_x
/* 0x0321 */ uint8_t Unknown0321[12];
/* 0x032D */ uint8_t IsMovingTimer; // 0 = Moving, 1-6 = Recently Stopped Moving, 200 = Not Moving
/* 0x032E */ uint8_t Unknown032E[266];
/* 0x0438 */ uint32_t IsLookingForGroup; // LFG
/* 0x043C */ uint32_t IsTrader;
/* ...... */ 
} Actor, *Actor_ptr;

// class EQPlayer
// sizeof 0x168
typedef struct _Spawn
{
/* 0x0000 */ uint8_t Unknown0000; // always equals 0x03
/* 0x0001 */ char Name[30]; // [0x1E]
/* 0x001F */ uint8_t Unknown001F[37];
/* 0x0044 */ uint32_t ZoneID; // EQ_ZONE_ID_x
/* 0x0048 */ float Y;
/* 0x004C */ float X;
/* 0x0050 */ float Z;
/* 0x0054 */ float Heading; // camera view left/right, yaw
/* 0x0058 */ float Unknown0058;
/* 0x005C */ float MovementSpeed;
/* 0x0060 */ float MovementSpeedY;
/* 0x0064 */ float MovementSpeedX;
/* 0x0068 */ float MovementSpeedZ;
/* 0x006C */ float MovementSpeedHeading;
/* 0x0070 */ float Unknown0070;
/* 0x0074 */ float Pitch; // camera view up/down
/* 0x0078 */ struct _Spawn* Previous;
/* 0x007C */ struct _Spawn* Next;
/* 0x0080 */ uint32_t Unknown0080;
/* 0x0084 */ struct _Actor* Actor;
/* 0x0088 */ struct _Character* Character;
/* 0x008C */ float CameraHeightOffset;
/* 0x0090 */ float ModelHeightOffset;
/* 0x0094 */ uint16_t SpawnID;
/* 0x0096 */ uint16_t PetOwnerSpawnID; // spawn id of the owner of this pet spawn
/* 0x0098 */ uint32_t HPMax;
/* 0x009C */ uint32_t HPCurrent;
/* 0x00A0 */ uint16_t GuildID;
/* 0x00A2 */ uint8_t Unknown00A2[6];
/* 0x00A8 */ uint8_t Type; // EQ_SPAWN_TYPE_x
/* 0x00A9 */ uint8_t Class; // EQ_CLASS_x
/* 0x00AA */ uint16_t Race;  // EQ_RACE_x
/* 0x00AC */ uint8_t Gender; // EQ_GENDER_x
/* 0x00AD */ uint8_t Level;
/* 0x00AE */ uint8_t IsHidden; // 0 = Visible, 1 = Invisible
/* 0x00AF */ uint8_t IsSneaking; // sneaking or snared ; 0 = Normal Movement Speed, 1 = Slow Movement Speed
/* 0x00B0 */ uint8_t IsPlayerKill; // PVP flagged with red name by Priest of Discord
/* 0x00B1 */ uint8_t StandingState; // EQ_STANDING_STATE_x
/* 0x00B2 */ uint8_t LightType; // EQ_LIGHT_TYPE_x
/* 0x00B3 */ uint8_t Unknown00B3;
/* 0x00B4 */ uint16_t EquipmentMaterialType[7]; // EQ_EQUIPMENT_MATERIAL_TYPE_x ; Head,Chest,Arms,Wrist,Hands,Legs,Feet
/* 0x00C2 */ uint16_t EquipmentPrimaryItemType; // EQ_EQUIPMENT_ITEM_TYPE_x ; Primary
/* 0x00C4 */ uint16_t EquipmentSecondaryItemType; // EQ_EQUIPMENT_ITEM_TYPE_x ; Secondary
/* 0x00C6 */ uint16_t Unknown00C6;
/* 0x00C8 */ uint8_t Unknown00C8[36];
/* 0x00EC */ uint8_t Unknown00EC;
/* 0x00F0 */ float Height; // model height or size/scale (shrink, grow, etc)
/* 0x00F4 */ float Unknown00F4;
/* 0x00F8 */ float Unknown00F8;
/* 0x00FC */ float Unknown00FC;
/* 0x0100 */ float MovementBackwardSpeedMultiplier; // modifies how fast you move backwards (Default = 0.4600000083)
/* 0x0104 */ float MovementForwardSpeedMultiplier; // modifies how fast you move forwards (Default = 0.6999999881)
/* 0x0108 */ uint8_t IsLinkDead; // LD
/* 0x0109 */ uint8_t IsGameMaster; // GM
/* 0x010A */ uint16_t LevitationState; // EQ_LEVITATION_STATE_x
/* 0x010C */ uint32_t TargetType; // EQ_SPAWN_TARGET_TYPE_x
/* 0x0110 */ uint32_t Unknown0110;
/* 0x0114 */ uint32_t AnonymousState; // EQ_ANONYMOUS_STATE_x ; /anonymous and /roleplay
/* 0x0118 */ uint32_t Unknown0118;
/* 0x011C */ uint32_t IsAwayFromKeyboard; // AFK
/* 0x0120 */ uint8_t Unknown0120[4];
/* 0x0124 */ uint32_t AlternateAdvancementRank; // AA points title value (0-3) (Venerable, Baroness, etc)
/* 0x0128 */ uint8_t Unknown0128[4];
/* 0x012C */ char LastName[22]; // surname or title // [0x16]
/* 0x0142 */ uint8_t Unknown0142[10];
/* 0x014C */ uint16_t GuildStatus; // EQ_GUILD_STATUS_x ; guild rank
/* 0x014E */ uint16_t Deity; // EQ_DEITY_x
/* 0x0150 */ uint8_t Unknown0150;
/* 0x0151 */ uint8_t Unknown0151[6];
/* 0x0157 */ uint8_t Unknown0157[5];
/* 0x015C */ uint32_t Unknown015C;
/* 0x0160 */ uint32_t Unknown0160;
/* 0x0164 */ uint32_t Unknown0164;
/* 0x0168 */
} Spawn, *Spawn_ptr, EQPlayer, *EQPlayer_ptr;

// class EQItemList
typedef struct _GroundSpawn
{
/* 0x0000 */ struct _GroundSpawn* Previous;
/* 0x0004 */ struct _GroundSpawn* Next;
/* 0x0008 */ uint16_t ID;
/* 0x000A */ uint8_t Unknown000A[2];
/* 0x000C */ uint16_t DropID;
/* 0x000E */ uint8_t Unknown000E[2];
/* 0x0010 */ uint16_t Unknown0010;
/* 0x0012 */ uint8_t Unknown0012[2];
/* 0x0014 */ struct _ActorInstance* ActorInstance;
/* 0x0018 */ uint8_t Unknown0018[116];
/* 0x008C */ float Heading;
/* 0x0090 */ float Z;
/* 0x0094 */ float X;
/* 0x0098 */ float Y;
/* 0x009C */ char ActorDef[30]; // [0x1E] ; ITXX_ACTORDEF string
/* ...... */ 
} GroundSpawn, *GroundSpawn_ptr;

// class EQSwitch
// doors and switches
typedef struct _Switch
{
/* 0x0000 */ uint8_t Unknown0000[4];
/* 0x0004 */ struct _Switch* Previous;
/* 0x0008 */ struct _Switch* Next;
/* 0x000C */ uint8_t Unknown000C;
/* 0x000D */ char Name[11]; // [0x0B]
/* 0x0018 */ uint32_t Unknown0018;
/* 0x001C */ uint8_t Unknown001C[4];
/* 0x0020 */ float DefaultY;
/* 0x0024 */ float DefaultX;
/* 0x0028 */ float DefaultZ;
/* 0x002C */ float DefaultHeading;
/* 0x0030 */ float Angle;
/* 0x0034 */ float Y;
/* 0x0038 */ float X;
/* 0x003C */ float Z;
/* 0x0040 */ float Heading;
/* ...... */ 
} Switch, *Switch_ptr, DoorSpawn, *DoorSpawn_ptr, EQSwitch, *EQSwitch_ptr;

typedef struct _GroupList
{
    struct _Spawn* GroupMember[EQ_NUM_GROUP_MEMBERS];
} GroupList, *GroupList_ptr;

// sizeof 0x96
typedef struct _Guild
{
/* 0x0000 */ char Name[32];
/* 0x0032 */ uint8_t Unknown0032[64];
} Guild, *Guild_ptr;

typedef struct _GuildList
{
    struct _Guild Guild[EQ_NUM_GUILDS];
} GuildList, *GuildList_ptr;

// sizeof 0x14
typedef struct _Command
{
/* 0x0000 */ uint32_t ID;
/* 0x0004 */ char* Name;
/* 0x0008 */ char* Name2;
union
{
/* 0x000C */ void (__stdcall* Function)(Spawn_ptr, char*);
/* 0x000C */ uint32_t FunctionAddress;
};
/* 0x0010 */ uint16_t Restriction;
/* 0x0012 */ uint16_t Category;
} Command, *Command_ptr;

typedef struct _CommandList
{
    struct _Command Command[EQ_NUM_COMMANDS];
} CommandList, *CommandList_ptr;

typedef struct _HotButton
{
/* 0x0000 */ uint8_t Type1;
/* 0x0001 */ uint8_t Unknown0001;
/* 0x0002 */ uint8_t Type2;
/* 0x0003 */ uint8_t Unknown0003;
} HotButton, *HotButton_ptr;

typedef struct _HotButtonList
{
    struct _HotButton HotButton[EQ_NUM_HOTBUTTONS_TOTAL];
} HotButtonList, *HotButtonList_ptr;

// /viewport command
typedef struct _Viewport
{
/* 0x0000 */ uint16_t X1;
/* 0x0002 */ uint16_t Y1;
/* 0x0004 */ uint16_t X2;
/* 0x0006 */ uint16_t Y2;
} Viewport, *Viewport_ptr;

typedef struct _CDisplay
{
/* 0x0000 */ uint8_t Unknown0000[64];
/* 0x0040 */ uint8_t IsCursorItem; // when you pick up and hold an item on your mouse cursor
/* 0x0041 */ uint8_t Unknown0041;
/* 0x0042 */ uint8_t IsCursorHotkey; // when you pick up and hold a hotkey button on your mouse cursor
/* 0x0043 */ uint8_t Unknown0043;
/* 0x0044 */ uint8_t Unknown0044[132];
/* 0x00C8 */ uint32_t Timer;
/* 0x00CC */ uint8_t Unknown00CC[11580];
/* 0x2E08 */ uint32_t StringSpriteFontTexture; // pointer ; S3D_FONTTEXTURE* for CDisplay::ChangeDagStringSprite
} CDisplay, *CDisplay_ptr;

typedef struct _CEverQuest
{
/* 0x0000 */ uint8_t Unknown0000[1452];
/* 0x05AC */ uint32_t GameState; // EQ_GAME_STATE_x
} CEverQuest, *CEverQuest_ptr;

typedef struct _CXWndManager
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t WindowList;
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t Unknown000C;
/* 0x0010 */ uint32_t Unknown0010;
/* 0x0014 */ uint32_t LastPressedKeyCode;
/* 0x0018 */ uint32_t LastKeyboardMouseInputTimer;
/* 0x001C */ uint32_t Unknown001C;
/* 0x0020 */ uint32_t Unknown0020;
/* 0x0024 */ uint32_t Unknown0024;
/* 0x0028 */ uint32_t Unknown0028;
/* 0x002C */ uint32_t Unknown002C;
/* 0x0030 */ uint32_t FocusedWindow; // maybe last clicked window
/* 0x0034 */ uint32_t DraggedWindow; // mouse dragging
/* 0x0038 */ uint32_t Unknown0038;
/* 0x003C */ uint32_t HoveredWindow; // mouse hover over
/* 0x0040 */ uint32_t Unknown0040;
/* 0x0044 */ uint32_t Unknown0044;
/* 0x0048 */ uint32_t Unknown0048;
/* 0x004C */ uint32_t MouseX;
/* 0x0050 */ uint32_t MouseY;
/* 0x0054 */ uint32_t KeyboardModifierKeyFlags; // CTRL, SHIFT and ALT
/* 0x0058 */ uint32_t Unknown0058;
/* 0x005C */ uint32_t MouseIcon;
/* 0x0060 */ uint32_t Unknown0060;
/* 0x0064 */ uint32_t TitleBarClickedX; // window titlebar
/* 0x0068 */ uint32_t TitleBarClickedY; // window titlebar
/* ...... */
} CXWndManager, *CXWndManager_ptr;

typedef struct _CXPoint
{
    uint32_t X;
    uint32_t Y;
} CXPoint, *CXPoint_ptr;

typedef struct _CXRect
{
    uint32_t X1;
    uint32_t Y1;
    uint32_t X2;
    uint32_t Y2;
} CXRect, *CXRect_ptr;

typedef struct _CXStr
{
/* 0x0000*/ uint32_t Font; // 1,6 = Window Title or Button Text, 8 = Hot Button Small Text
/* 0x0004*/ uint32_t MaxLength;
/* 0x0008*/ uint32_t Length;
/* 0x000C*/ uint32_t Encoding; // 0 = ASCII, 1 = Unicode
/* 0x0010*/ PCRITICAL_SECTION Lock;
/* 0x0014*/ char Text[1]; // use Length and MaxLength
} CXStr, *CXStr_ptr;

// sizeof 0xAC
// CXWnd and CSidlScreenWnd share these same properties
typedef struct _CSidlWnd
{
/* 0x0000 */ uint32_t Unknown0000; // struct _CSIDLWNDVFTABLE *pvfTable; struct _CXWNDVFTABLE *pvfTable;
/* 0x0004 */ uint32_t MouseHoverTimer;
/* 0x0008 */ uint32_t Unknown0008; // usually equals 2000
/* 0x000C */ uint32_t Unknown000C; // usually equals 500
/* 0x0010 */ uint8_t Unknown0010;
/* 0x0011 */ uint8_t Unknown0011;
/* 0x0012 */ uint8_t IsLocked;
/* 0x0013 */ uint8_t Unknown0013;
/* 0x0014 */ uint32_t Unknown0014;
/* 0x0018 */ uint32_t Unknown0018;
/* 0x001C */ struct _CSidlWnd* ParentWnd;
/* 0x0020 */ struct _CSidlWnd* FirstChildWnd;
/* 0x0024 */ struct _CSidlWnd* NextSiblingWnd;
/* 0x0028 */ uint8_t HasChildren;
/* 0x0029 */ uint8_t HasSiblings;
/* 0x002A */ uint8_t Unknown0030[2];
/* 0x002C */ uint32_t Flags;
/* 0x0030 */ struct _CXRect Location;
/* 0x0040 */ struct _CXRect LocationPlaceholder; // used when minimizing the window
/* 0x0050 */ uint8_t IsVisible; // show
/* 0x0051 */ uint8_t IsEnabled;
/* 0x0052 */ uint8_t IsMinimized;
/* 0x0053 */ uint8_t Unknown0053;
/* 0x0054 */ uint8_t IsOpen;
/* 0x0055 */ uint8_t Unknown0055;
/* 0x0056 */ uint8_t IsMouseOver; // mouse is hovering over
/* 0x0057 */ uint8_t Unknown0057;
/* 0x0058 */ uint32_t WindowStyleFlags;
/* 0x005C */ struct _Font* Font;
/* 0x0060 */ CXStr_ptr Text;
/* 0x0064 */ CXStr_ptr ToolTipText;
/* 0x0068 */ uint8_t Unknown0068[28];
/* 0x0084 */ CXStr_ptr XmlToolTipText;
/* 0x0088 */ uint8_t Unknown0088[22];
/* 0x009E */ uint8_t AlphaTransparency;
/* 0x009F */ uint8_t Unknown009F;
/* 0x00A0 */ uint8_t ZLayer;
/* 0x00A1 */ uint8_t Unknown00A1[7];
/* 0x00A8 */ uint32_t DrawTemplate;
/* 0x00AC */
} CSidlWnd, *CSidlWnd_ptr;

// class CSidlScreenWnd
// sizeof 0x138
// the moveable resizable parent windows
typedef struct _CsidlScreenWnd
{
/* 0x0000 */ struct _CSidlWnd Window;
/* 0x00AC */ uint8_t Unknown00AC[140]; // skips the rest
/* 0x0138 */
} CsidlScreenWnd, *CsidlScreenWnd_ptr;

// sizeof 0x138
// usually a child window like a button or label
typedef struct _CXWnd
{
/* 0x0000 */ struct _CSidlWnd Window;
/* 0x00AC */ uint8_t Unknown00AC[140]; // skips the rest
/* 0x0138 */
} CXWnd, *CXWnd_ptr;

typedef struct _CItemDisplayWnd
{
/* 0x0000 */ struct _CsidlScreenWnd CSidlScreenWnd;
/* 0x0138 */ uint8_t Unknown0138[4];
/* 0x013C */ struct _CsidlScreenWnd* DisplayWnd; // the item stats text window
/* 0x0140 */ uint8_t Unknown0140[4];
/* 0x0144 */ CXStr_ptr DisplayText; // the item stats text
/* 0x0148 */ CXStr_ptr WindowTitle; // the item name is the title text
/* 0x014C */ struct _Item Item;
/* ...... */
} CItemDisplayWnd, *CItemDisplayWnd_ptr;

typedef struct _CBuffWindow
{
/* 0x0000 */ struct _CsidlScreenWnd CsidlScreenWnd;
/* 0x0138 */ uint8_t Unknown0138[68];
/* 0x017C */ struct _CsidlScreenWnd* BuffButtonWnd[EQ_NUM_BUFFS]; // CButtonWnd
/* 0x01B8 */
/* ...... */
} CBuffWindow, *CBuffWindow_ptr;

typedef struct _CLootWnd
{
/* 0x0000 */ struct _CsidlScreenWnd CsidlScreenWnd;
/* 0x0138 */ uint32_t ItemSlotIndex[EQ_NUM_LOOT_WINDOW_SLOTS];
/* 0x01B0 */ uint32_t Timer;
/* 0x01B4 */ uint32_t Unknown01B4;
/* 0x01B8 */ struct _Item* Item[EQ_NUM_LOOT_WINDOW_SLOTS];
/* ...... */
} CLootWnd, *CLootWnd_ptr;

typedef struct _CInvSlot
{
/* 0x0000 */ uint32_t Unknown0000;
/* 0x0004 */ uint32_t Unknown0004;
/* 0x0008 */ uint32_t Unknown0008;
/* 0x000C */ uint32_t SlotID;
/* ...... */
} CInvSlot, *CInvSlot_ptr;

} // namespace EQ

