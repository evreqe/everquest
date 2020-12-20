#pragma once

#include "eq_constants.h"

namespace EQ
{
    typedef struct _Vector2f
    {
        float X;
        float Y;
    } Vector2f, *Vector2f_ptr;

    typedef struct _Vector3f
    {
        float X;
        float Y;
        float Z;
    } Vector3f, *Vector3f_ptr;

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

    typedef struct _CXStr
    {
/* 0x00 */ uint32_t Font;
/* 0x04 */ uint32_t MaxLength;
/* 0x08 */ uint32_t Length;
/* 0x0C */ uint32_t Encoding; // 0 = ASCII, 1 = Unicode
/* 0x10 */ PCRITICAL_SECTION Lock;
/* 0x14 */ char Text[1];
    } CXStr, *CXStr_ptr;

    typedef struct _MouseState
    {
        uint32_t X;
        uint32_t Y;
        uint32_t Scroll;
        uint32_t RelativeX;
        uint32_t RelativeY;
        uint32_t InWindow;
    } MouseState, *MouseState_ptr;

    typedef struct _MouseInfo2
    {
        signed int X;
        signed int Y;
        signed int SpeedX;
        signed int SpeedY;
        signed int Scroll;
    } MouseInfo2, *MouseInfo2_ptr;

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
            uint32_t ARGB;
        };
    } ColorARGB, *ColorARGB_ptr;

    typedef struct _MapLabel
    {
/* 0x00 */ uint32_t Unknown;
/* 0x04 */ struct _MapLabel* Next;
/* 0x08 */ struct _MapLabel* Previous;
/* 0x0C */ Vector3f Location;
/* 0x18 */ ColorARGB Color;
/* 0x1C */ uint32_t Size; // 1-3
/* 0x20 */ char* Text;
/* 0x24 */ uint32_t Layer; // 0-3
/* 0x28 */ uint32_t Width;
/* 0x2C */ uint32_t Height;
/* 0x30 */ uint32_t X;
/* 0x34 */ uint32_t Y;
    } MapLabel, *MapLabel_ptr;

    typedef struct _MapLine
    {
/* 0x00 */ struct _MapLine* Next;
/* 0x04 */ struct _MapLine* Previous;
/* 0x08 */ Vector3f Begin;
/* 0x14 */ Vector3f End;
/* 0x20 */ ColorARGB Color;
/* 0x24 */ uint32_t Layer; // 0-3
    } MapLine, *MapLine_ptr;

    typedef struct _BandolierItemInfo
    {
/*0x00*/ int ItemID;
/*0x04*/ int IconID;
/*0x08*/ char Name[EQ_SIZE_BANDOLIER_ITEM_NAME];
/*0x48*/
    } BandolierItemInfo, *BandolierItemInfo_ptr;

    typedef struct _BandolierSet
    {
/*0x000*/ char Name[EQ_SIZE_BANDOLIER_SET_NAME];
/*0x020*/ BandolierItemInfo Items[4]; // 0x120 = 0x48 * 4
/*0x140*/
    } BandolierSet, *BandolierSet_ptr;

    typedef struct _CharInfo2Bandolier
    {
/*0x00*/ BandolierSet Bandolier[EQ_NUM_BANDOLIER_SLOTS];
    } CharInfo2Bandolier, *CharInfo2Bandolier_ptr;
} // namespace EQ
