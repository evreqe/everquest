#pragma once

bool g_spellBookWindowIsEnabled = true;

signed int EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__TurnToPage(void* this_ptr, signed int pageNumber);

signed int EQAPP_SpellBookWindow_HandleEvent__CSpellBookWnd__TurnToPage(void* this_ptr, signed int pageNumber)
{
    // spell book loops around between first pages and last pages

    if (EQ_IsWindowVisible(EQ_ADDRESS_POINTER_CSpellBookWnd) == false)
    {
        return pageNumber;
    }

    signed int firstPageNumber = 0;
    signed int lastPageNumber = EQ_NUM_SPELL_BOOK_PAGES - 2; // have to subtract two because pages start at 0 index and you can see two pages at a time

    if (pageNumber > lastPageNumber)
    {
        pageNumber = firstPageNumber;
    }
    else
    {
        if (pageNumber < firstPageNumber)
        {
            pageNumber = lastPageNumber;
        }
    }

    return pageNumber;
}
