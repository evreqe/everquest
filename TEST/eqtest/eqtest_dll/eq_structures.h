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

typedef struct _XYZ
{
    float X;
    float Y;
    float Z;
} XYZ, *XYZ_ptr;

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

typedef struct _ColorRGB
{
    union
    {
        struct
        {
            uint8_t B;
            uint8_t G;
            uint8_t R;
            uint8_t Unused;
        };
        uint32_t RGB;
    };
} ColorRGB, *ColorRGB_ptr;

} // namespace EQ

