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

// ******************** randomized after each patch ******************** //

#define EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER    0x250+0x08 // uint32_t pointer    "Begin Trader" button    "BZW_Start_Button"
#define EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER      0x254+0x08 // uint32_t pointer    "End Trader" button      "BZW_End_Button"

#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_ME         0x254+0x08 // uint32_t pointer    "To Me" button         "BZC_UseTokenButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS    0x260+0x08 // uint32_t pointer    "To Parcels" button    "BZC_UsePlatButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL        0x264+0x08 // uint32_t pointer    "Cancel" button        "BZC_CancelButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME          0x2BC+0x08 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME            0x31C+0x08 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID              0x370+0x08 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE           0x374+0x08 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY        0x380+0x08 // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX               0x268+0x08  // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM               0x270+0x08  // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME              0x270+0x08  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME                0x2B0+0x08  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE               0x2FC+0x08  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                  0x308+0x08  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY            0x30C+0x08  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM              0x328+0x08  // second item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS        0x9244+0x08 // uint32_t pointer    "Find Items" button        "BZR_QueryButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS    0x924C+0x08 // uint32_t pointer    "Update Traders" button    "BZR_UpdatePlayerButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET             0x9260+0x08 // uint32_t pointer    "Reset" button             "BZR_Default"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_BUY               0x9264+0x08 // uint32_t pointer    "Buy" button               "BZR_BuyButton"

#define EQ_SIZE_CBazaarSearchWnd_ITEM 0xB8 // number of bytes between _FIRST_ITEM and _SECOND_ITEM offsets

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CTaskSelectWnd_BUTTON_ACCEPT     0x240+0x08    // "Accept" button         "TSEL_AcceptButton"     "AcceptButton"
#define EQ_OFFSET_CTaskSelectWnd_BUTTON_DECLINE    0x244+0x08    // "Decline All" button    "TSEL_DeclineButton"    "DeclineButton"

// ********************************************************************* //
