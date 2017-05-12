#pragma once

/* CDisplay */

#define EQ_OFFSET_CDisplay_IS_CURSOR_ITEM      0x0040 // uint8_t     when you pick up and hold an item on your mouse cursor
#define EQ_OFFSET_CDisplay_IS_CURSOR_HOTKEY    0x0042 // uint8_t     when you pick up and hold a hotkey button on your mouse cursor
#define EQ_OFFSET_CDisplay_TIMER               0x00C8 // uint32_t    global timer in milliseconds, 1000 milliseconds = 1 second

#define EQ_OFFSET_CDisplay_STRING_SPRITE_FONT_TEXTURE_POINTER 0x2E08 // S3D_FONTTEXTURE* for CDisplay::ChangeDagStringSprite

/* CEverQuest */

#define EQ_OFFSET_CEverQuest_GAME_STATE 0x5AC // uint32_t
