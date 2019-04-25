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

#define EQ_SIZE_CXWnd    sizeof(EQUIStructs::_CXWND)

#define EQ_SIZE_CSidlWnd    sizeof(EQUIStructs::_CSIDLWND)

#define EQ_OFFSET_FixWrongSize -0x08

#ifdef EQ_FEATURE_BAZAAR

#define EQ_OFFSET_CBazaarWnd_BUTTON_BEGIN_TRADER    EQ_SIZE_CSidlWnd + 0x18 // uint32_t pointer    "Begin Trader" button    "BZW_Start_Button"
#define EQ_OFFSET_CBazaarWnd_BUTTON_END_TRADER      EQ_SIZE_CSidlWnd + 0x1C // uint32_t pointer    "End Trader" button      "BZW_End_Button"

#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_ME         EQ_SIZE_CSidlWnd + 0x1C // uint32_t pointer    "To Me" button         "BZC_UseTokenButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_TO_PARCELS    EQ_SIZE_CSidlWnd + 0x28 // uint32_t pointer    "To Parcels" button    "BZC_UsePlatButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_BUTTON_CANCEL        EQ_SIZE_CSidlWnd + 0x2C // uint32_t pointer    "Cancel" button        "BZC_CancelButton"
#define EQ_OFFSET_CBazaarConfirmationWnd_TRADER_NAME          EQ_SIZE_CSidlWnd + 0x84 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_NAME            EQ_SIZE_CSidlWnd + 0xE4 // char[64]
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_ID              EQ_SIZE_CSidlWnd + 0x138 // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_PRICE           EQ_SIZE_CSidlWnd + 0x13C // uint32_t
#define EQ_OFFSET_CBazaarConfirmationWnd_ITEM_QUANTITY        EQ_SIZE_CSidlWnd + 0x148 // uint32_t

#define EQ_SIZE_CBazaarConfirmationWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarConfirmationWnd_ITEM_NAME      64 // 0x40

#define EQ_OFFSET_CBazaarSearchWnd_LIST_INDEX               EQ_SIZE_CSidlWnd + 0x30  // uint32_t    index of the item in the search list to buy
#define EQ_OFFSET_CBazaarSearchWnd_FIRST_ITEM               EQ_SIZE_CSidlWnd + 0x38  // first item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_TRADER_NAME              EQ_SIZE_CSidlWnd + 0x38  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_NAME                EQ_SIZE_CSidlWnd + 0x78  // char[64]
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_PRICE               EQ_SIZE_CSidlWnd + 0xC4  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_ID                  EQ_SIZE_CSidlWnd + 0xD0  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_ITEM_QUANTITY            EQ_SIZE_CSidlWnd + 0xD4  // uint32_t
#define EQ_OFFSET_CBazaarSearchWnd_SECOND_ITEM              EQ_SIZE_CSidlWnd + 0xF0  // second item in the search list starts here
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_FIND_ITEMS        EQ_SIZE_CSidlWnd + 0x900C // uint32_t pointer    "Find Items" button        "BZR_QueryButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_UPDATE_TRADERS    EQ_SIZE_CSidlWnd + 0x9014 // uint32_t pointer    "Update Traders" button    "BZR_UpdatePlayerButton"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_RESET             EQ_SIZE_CSidlWnd + 0x9028 // uint32_t pointer    "Reset" button             "BZR_Default"
#define EQ_OFFSET_CBazaarSearchWnd_BUTTON_BUY               EQ_SIZE_CSidlWnd + 0x902C // uint32_t pointer    "Buy" button               "BZR_BuyButton"

#define EQ_SIZE_CBazaarSearchWnd_ITEM 0xB8 // number of bytes between _FIRST_ITEM and _SECOND_ITEM offsets

#define EQ_SIZE_CBazaarSearchWnd_TRADER_NAME    64 // 0x40
#define EQ_SIZE_CBazaarSearchWnd_ITEM_NAME      64 // 0x40

#endif // EQ_FEATURE_BAZAAR

#define EQ_OFFSET_CTaskSelectWnd_BUTTON_ACCEPT     EQ_SIZE_CSidlWnd + 0x08 // uint32_t pointer    "Accept" button         "TSEL_AcceptButton"     "AcceptButton"
#define EQ_OFFSET_CTaskSelectWnd_BUTTON_DECLINE    EQ_SIZE_CSidlWnd + 0x0C // uint32_t pointer    "Decline All" button    "TSEL_DeclineButton"    "DeclineButton"

#define EQ_OFFSET_CLargeDialogWnd_BUTTON_OK     EQ_SIZE_CSidlWnd + 0x04 // uint32_t pointer    "Ok" button     "LDW_OkButton"
#define EQ_OFFSET_CLargeDialogWnd_BUTTON_YES    EQ_SIZE_CSidlWnd + 0x08 // uint32_t pointer    "Yes" button    "LDW_YesButton"
#define EQ_OFFSET_CLargeDialogWnd_BUTTON_NO     EQ_SIZE_CSidlWnd + 0x0C // uint32_t pointer    "No" button     "LDW_NoButton"

#define EQ_OFFSET_CConfirmationDialog_BUTTON_YES        EQ_SIZE_CSidlWnd + 0x04 // uint32_t pointer    "Yes" button       "Yes_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_NO         EQ_SIZE_CSidlWnd + 0x08 // uint32_t pointer    "No" button        "No_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_CANCEL     EQ_SIZE_CSidlWnd + 0x0C // uint32_t pointer    "Cancel" button    "Cancel_Button"
#define EQ_OFFSET_CConfirmationDialog_BUTTON_OK         EQ_SIZE_CSidlWnd + 0x10 // uint32_t pointer    "OK" button        "OK_Button"

// ********************************************************************* //

#define EQ_OFFSET_CPlayerWnd_COMBAT_STATE    offsetof(EQUIStructs::_CPLAYERWND, CombatState) + EQ_OFFSET_FixWrongSize // uint32_t
// "A_PWCSInCombat"    "You are in combat and cannot rest currently."
// "A_PWCSDebuff"      "You are weakened and cannot rest currently."
// "A_PWCSTimer"       "You are recovering from combat and cannot rest currently."
// "A_PWCSStanding"    "You are not in combat and may rest at any time."
// "A_PWCSRegen"       "You are resting and recovering health, mana and endurance at an increased rate."

#define EQ_OFFSET_CTargetWnd_BUFF_SPELL_IDS    offsetof(EQUIStructs::_CTARGETWND, BuffSpellID) + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CTargetWnd_BUFF_TIMERS       offsetof(EQUIStructs::_CTARGETWND, BuffTimer)   + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CPetInfoWindow_SPAWN_ID          offsetof(EQUIStructs::_EQPETINFOWINDOW, PetSpawnID)     + EQ_OFFSET_FixWrongSize // uint32_t
#define EQ_OFFSET_CPetInfoWindow_BUFF_SPELL_IDS    offsetof(EQUIStructs::_EQPETINFOWINDOW, Buff)           + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CPetInfoWindow_BUFF_TIMERS       offsetof(EQUIStructs::_EQPETINFOWINDOW, PetBuffTimer)   + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CBuffWnd_BUFF_BUTTONS      offsetof(EQUIStructs::_EQBUFFWINDOW, pBuff)       + EQ_OFFSET_FixWrongSize // uint32_t pointer[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CBuffWnd_BUFF_SPELL_IDS    offsetof(EQUIStructs::_EQBUFFWINDOW, BuffId)      + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]
#define EQ_OFFSET_CBuffWnd_BUFF_TIMERS       offsetof(EQUIStructs::_EQBUFFWINDOW, BuffTimer)   + EQ_OFFSET_FixWrongSize // uint32_t[EQ_NUM_BUFF_SLOTS]

#define EQ_OFFSET_CCastSpellWnd_SPELL_GEMS    offsetof(EQUIStructs::_EQCASTSPELLWINDOW, SpellSlots) + EQ_OFFSET_FixWrongSize // uint32_t pointer[EQ_NUM_SPELL_GEMS_IN_WINDOW]

#define EQ_OFFSET_CSpellGemWnd_ICON     offsetof(EQUIStructs::_EQCASTSPELLGEM, spellicon)     + EQ_OFFSET_FixWrongSize // uint32_t
#define EQ_OFFSET_CSpellGemWnd_STATE    offsetof(EQUIStructs::_EQCASTSPELLGEM, spellstate)    + EQ_OFFSET_FixWrongSize // uint32_t

#define EQ_OFFSET_CMapViewWnd_LINES     offsetof(EQUIStructs::_EQMAPWINDOW, pLines)     + EQ_OFFSET_FixWrongSize // uint32_t pointer
#define EQ_OFFSET_CMapViewWnd_LABELS    offsetof(EQUIStructs::_EQMAPWINDOW, pLabels)    + EQ_OFFSET_FixWrongSize // uint32_t pointer
