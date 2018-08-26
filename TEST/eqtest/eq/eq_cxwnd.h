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

#define EQ_OFFSET_CXWnd_PADDING -0x8

// sizeof(EQUIStructs::_CSIDLWND) + 0x18 == 0x250+EQ_OFFSET_CXWnd_PADDING
#define EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER    0x250+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Begin Trader" button    "BZW_Start_Button"
#define EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER      0x254+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "End Trader" button      "BZW_End_Button"

#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_ME         0x254+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "To Me" button         "BZC_UseTokenButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS    0x260+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "To Parcels" button    "BZC_UsePlatButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL        0x264+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Cancel" button        "BZC_CancelButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME          0x2BC+EQ_OFFSET_CXWnd_PADDING // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME            0x31C+EQ_OFFSET_CXWnd_PADDING // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID              0x370+EQ_OFFSET_CXWnd_PADDING // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE           0x374+EQ_OFFSET_CXWnd_PADDING // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY        0x380+EQ_OFFSET_CXWnd_PADDING // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX               0x268+EQ_OFFSET_CXWnd_PADDING  // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM               0x270+EQ_OFFSET_CXWnd_PADDING  // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME              0x270+EQ_OFFSET_CXWnd_PADDING  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME                0x2B0+EQ_OFFSET_CXWnd_PADDING  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE               0x2FC+EQ_OFFSET_CXWnd_PADDING  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                  0x308+EQ_OFFSET_CXWnd_PADDING  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY            0x30C+EQ_OFFSET_CXWnd_PADDING  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM              0x328+EQ_OFFSET_CXWnd_PADDING  // second item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS        0x9244+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Find Items" button        "BZR_QueryButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS    0x924C+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Update Traders" button    "BZR_UpdatePlayerButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET             0x9260+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Reset" button             "BZR_Default"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_BUY               0x9264+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Buy" button               "BZR_BuyButton"

#define EQ_SIZE_CBazaarSearchWnd_ITEM 0xB8 // number of bytes between _FIRST_ITEM and _SECOND_ITEM offsets

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CTaskSelectWnd_BUTTON_ACCEPT     0x240+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Accept" button         "TSEL_AcceptButton"     "AcceptButton"
#define EQ_OFFSET_CTaskSelectWnd_BUTTON_DECLINE    0x244+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Decline All" button    "TSEL_DeclineButton"    "DeclineButton"

#define EQ_OFFSET_CLargeDialogWnd_BUTTON_OK     0x23C+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Ok" button     "LDW_OkButton"
#define EQ_OFFSET_CLargeDialogWnd_BUTTON_YES    0x240+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Yes" button    "LDW_YesButton"
#define EQ_OFFSET_CLargeDialogWnd_BUTTON_NO     0x244+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "No" button     "LDW_NoButton"

#define EQ_OFFSET_CConfirmationDialog_BUTTON_YES        0x23C+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Yes" button       "Yes_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_NO         0x240+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "No" button        "No_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_CANCEL     0x244+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "Cancel" button    "Cancel_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_OK         0x248+EQ_OFFSET_CXWnd_PADDING // uint32_t pointer    "OK" button        "OK_Button"

// ********************************************************************* //

#define EQ_OFFSET_CPlayerWnd_COMBAT_STATE    offsetof(EQUIStructs::_CPLAYERWND, CombatState) // uint32_t
// "A_PWCSInCombat"    "You are in combat and cannot rest currently."
// "A_PWCSDebuff"      "You are weakened and cannot rest currently."
// "A_PWCSTimer"       "You are recovering from combat and cannot rest currently."
// "A_PWCSStanding"    "You are not in combat and may rest at any time."
// "A_PWCSRegen"       "You are resting and recovering health, mana and endurance at an increased rate."

#define EQ_OFFSET_CTargetWnd_BUFF_SPELL_IDS    offsetof(EQUIStructs::_CTARGETWND, BuffSpellID) // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CTargetWnd_BUFF_TIMERS       offsetof(EQUIStructs::_CTARGETWND, BuffTimer)   // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CPetInfoWindow_SPAWN_ID          offsetof(EQUIStructs::_EQPETINFOWINDOW, PetSpawnID)     // uint32_t
#define EQ_OFFSET_CPetInfoWindow_BUFF_SPELL_IDS    offsetof(EQUIStructs::_EQPETINFOWINDOW, Buff)           // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CPetInfoWindow_BUFF_TIMERS       offsetof(EQUIStructs::_EQPETINFOWINDOW, PetBuffTimer)   // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CBuffWnd_BUFF_BUTTONS      offsetof(EQUIStructs::_EQBUFFWINDOW, pBuff)       // uint32_t pointer[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS    offsetof(EQUIStructs::_EQBUFFWINDOW, BuffId)      // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CBuffWnd_BUFF_TIMERS       offsetof(EQUIStructs::_EQBUFFWINDOW, BuffTimer)   // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CCastSpellWnd_SPELL_GEMS    offsetof(EQUIStructs::_EQCASTSPELLWINDOW, SpellSlots) // uint32_t pointer[EQ_NUM_SPELL_GEMS_IN_WINDOW]

#define EQ_OFFSET_CSpellGemWnd_ICON     offsetof(EQUIStructs::_EQCASTSPELLGEM, spellicon)     // uint32_t
#define EQ_OFFSET_CSpellGemWnd_STATE    offsetof(EQUIStructs::_EQCASTSPELLGEM, spellstate)    // uint32_t

#define EQ_OFFSET_CMapViewWnd_LINES     offsetof(EQUIStructs::_EQMAPWINDOW, pLines)     // uint32_t pointer
#define EQ_OFFSET_CMapViewWnd_LABELS    offsetof(EQUIStructs::_EQMAPWINDOW, pLabels)    // uint32_t pointer
