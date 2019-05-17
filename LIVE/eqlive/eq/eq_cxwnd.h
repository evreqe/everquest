#pragma once

#define EQ_CXWND_MESSAGE_LEFT_CLICK           1
#define EQ_CXWND_MESSAGE_LEFT_MOUSE_UP        2
#define EQ_CXWND_MESSAGE_RIGHT_CLICK          3
#define EQ_CXWND_MESSAGE_LEFT_DOUBLE_CLICK    4
#define EQ_CXWND_MESSAGE_HIT_ENTER            6
#define EQ_CXWND_MESSAGE_CLOSE                10
#define EQ_CXWND_MESSAGE_NEW_VALUE            14
#define EQ_CXWND_MESSAGE_UNKNOWN              19
#define EQ_CXWND_MESSAGE_MENU_SELECT          20
#define EQ_CXWND_MESSAGE_MOUSE_OVER           21
#define EQ_CXWND_MESSAGE_HISTORY              22
#define EQ_CXWND_MESSAGE_LEFT_CLICK_HOLD      23
#define EQ_CXWND_MESSAGE_LINK                 27
#define EQ_CXWND_MESSAGE_FOCUS                33
#define EQ_CXWND_MESSAGE_LOST_FOCUS           34

#define EQ_CXWND_KEYBOARD_FLAG_SHIFT    1
#define EQ_CXWND_KEYBOARD_FLAG_CTRL     2
#define EQ_CXWND_KEYBOARD_FLAG_LALT     4
#define EQ_CXWND_KEYBOARD_FLAG_RALT     8

// search for one of these strings to find the
// function where all of the windows are created:
// "Initializing game UI."
// "hasItems has value %d\n"
// "Loading Icons."
// "Resetting viewport."
// "Game UI Initialized."
