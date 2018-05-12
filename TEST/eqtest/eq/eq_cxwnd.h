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

// ******************** randomized after each patch ******************** //
// April 24 2018
#define EQ_OFFSET_CXWnd_IS_OPEN 0x3E  // uint8_t    CXWnd__IsReallyVisible()
// ********************************************************************* //

// search for one of these strings to find the
// function where all of the CXWnd windows are created:
// "Initializing game UI."
// "hasItems has value %d\n"
// "Loading Icons."
// "Resetting viewport."
// "Game UI Initialized."

#define EQ_OFFSET_CPlayerWindow_COMBAT_STATE 0x2E4 // "A_PWCSInCombat"    "A_PWCSDebuff"    "A_PWCSTimer"    "A_PWCSStanding"    "A_PWCSRegen"

#define EQ_PLAYER_WINDOW_COMBAT_STATE_IN_COMBAT     0   // "A_PWCSInCombat"
#define EQ_PLAYER_WINDOW_COMBAT_STATE_DEBUFFED      1   // "A_PWCSDebuff"
#define EQ_PLAYER_WINDOW_COMBAT_STATE_RECOVERING    2   // "A_PWCSTimer"
#define EQ_PLAYER_WINDOW_COMBAT_STATE_STANDING      3   // "A_PWCSStanding"
#define EQ_PLAYER_WINDOW_COMBAT_STATE_RESTING       4   // "A_PWCSRegen"

#define EQ_OFFSET_CBazaarSearchWnd_BUY_ITEM_LIST_INDEX      0x260  // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM               0x268  // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME              0x268  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME                0x2A8  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE               0x2F4  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                  0x300  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY            0x304  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM              0x320  // second item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS        0x923C // uint32_t pointer    "Find Items" button        "BZR_QueryButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS    0x9244 // uint32_t pointer    "Update Traders" button    "BZR_UpdatePlayerButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET             0x9258 // uint32_t pointer    "Reset" button             "BZR_Default"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_BUY               0x925C // uint32_t pointer    "Buy" button               "BZR_BuyButton"

#define EQ_SIZE_CBazaarSearchWnd_ITEM 0xB8 // number of bytes between _FIRST_ITEM and _SECOND_ITEM offsets

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_ME         0x24C // uint32_t pointer    "To Me" button         "BZC_UseTokenButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS    0x258 // uint32_t pointer    "To Parcels" button    "BZC_UsePlatButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL        0x25C // uint32_t pointer    "Cancel" button        "BZC_CancelButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME          0x2B4 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME            0x314 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID              0x368 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE           0x36C // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY        0x378 // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER    0x248 // uint32_t pointer    "Begin Trader" button    "BZW_Start_Button"
#define EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER      0x24C // uint32_t pointer    "End Trader" button      "BZW_End_Button"