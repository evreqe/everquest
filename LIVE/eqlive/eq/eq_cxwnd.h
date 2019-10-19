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

// class CXWnd
uint32_t EQ_SIZE_CXWnd = 0x1F8;    // const CXWnd::`vftable'    // = &CXWnd::`vftable'

// class CSidlScreenWnd
uint32_t EQ_SIZE_CSidlScreenWnd = 0x230;    // const CSidlScreenWnd::`vftable'    // = &CSidlScreenWnd::`vftable'

// search for one of these strings to find the
// function where all of the windows are created:
// "Initializing game UI."
// "hasItems has value %d\n"
// "Loading Icons."
// "Resetting viewport."
// "Game UI Initialized."

/* CAlertWnd */

#define EQ_OFFSET_CAlertWnd_BUTTON_CLOSE    EQ_SIZE_CSidlScreenWnd + 0x14    // uint32_t    "ALW_Close_Button"

/* CBazaarWnd */

#define EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER    EQ_SIZE_CSidlScreenWnd + 0x18 // uint32_t pointer    "Begin Trader" button    "BZW_Start_Button"
#define EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER      EQ_SIZE_CSidlScreenWnd + 0x1C // uint32_t pointer    "End Trader" button      "BZW_End_Button"

/* CBazaarSearchWnd */

#define EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX               EQ_SIZE_CSidlScreenWnd + 0x30  // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM               EQ_SIZE_CSidlScreenWnd + 0x38  // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME              EQ_SIZE_CSidlScreenWnd + 0x38  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME                EQ_SIZE_CSidlScreenWnd + 0x78  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE               EQ_SIZE_CSidlScreenWnd + 0xC4  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                  EQ_SIZE_CSidlScreenWnd + 0xD0  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY            EQ_SIZE_CSidlScreenWnd + 0xD4  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM              EQ_SIZE_CSidlScreenWnd + 0xF0  // second item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS        EQ_SIZE_CSidlScreenWnd + 0x900C // uint32_t pointer    "Find Items" button        "BZR_QueryButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS    EQ_SIZE_CSidlScreenWnd + 0x9014 // uint32_t pointer    "Update Traders" button    "BZR_UpdatePlayerButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET             EQ_SIZE_CSidlScreenWnd + 0x9028 // uint32_t pointer    "Reset" button             "BZR_Default"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_BUY               EQ_SIZE_CSidlScreenWnd + 0x902C // uint32_t pointer    "Buy" button               "BZR_BuyButton"

#define EQ_SIZE_CBazaarSearchWnd_ITEM 0xB8 // number of bytes between _FIRST_ITEM and _SECOND_ITEM offsets

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

/* CBazaarConfirmationWnd */

#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_ME         EQ_SIZE_CSidlScreenWnd + 0x1C // uint32_t pointer    "To Me" button         "BZC_UseTokenButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS    EQ_SIZE_CSidlScreenWnd + 0x28 // uint32_t pointer    "To Parcels" button    "BZC_UsePlatButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL        EQ_SIZE_CSidlScreenWnd + 0x2C // uint32_t pointer    "Cancel" button        "BZC_CancelButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME          EQ_SIZE_CSidlScreenWnd + 0x84 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME            EQ_SIZE_CSidlScreenWnd + 0xE4 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID              EQ_SIZE_CSidlScreenWnd + 0x138 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE           EQ_SIZE_CSidlScreenWnd + 0x13C // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY        EQ_SIZE_CSidlScreenWnd + 0x148 // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

/* CSpellBookWnd */

// CSpellBookWnd::GetSpellMemTicksLeft()
#define EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_GEM_INDEX      EQ_SIZE_CSidlScreenWnd + 0x14    // signed int
#define EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_ID             EQ_SIZE_CSidlScreenWnd + 0x18    // signed int
#define EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_START_TIMER    EQ_SIZE_CSidlScreenWnd + 0x1C    // signed int
#define EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_TIMER          EQ_SIZE_CSidlScreenWnd + 0x20    // signed int

#define EQ_OFFSET_CSpellBookWnd_SCRIBE_SPELL_TIMER    EQ_SIZE_CSidlScreenWnd + 0x28    // uint32_t    CSpellBookWnd::GetSpellScribeTicksLeft()
