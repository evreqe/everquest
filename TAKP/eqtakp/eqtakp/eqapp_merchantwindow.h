#pragma once

bool g_merchantWindowIsEnabled = true;

unsigned int g_merchantWindowFontSize = 1;

void EQAPP_MerchantWindow_Toggle();
void EQAPP_MerchantWindow_AppendSpellLevelToToolTipText(void* this_ptr);
void EQAPP_MerchantWindow_HandleEvent_CMerchantWnd__PostDraw(void* this_ptr);

void EQAPP_MerchantWindow_Toggle()
{
    EQ_ToggleBool(g_merchantWindowIsEnabled);
    EQAPP_PrintBool("Merchant Window", g_merchantWindowIsEnabled);
}

void EQAPP_MerchantWindow_AppendSpellLevelToToolTipText(void* this_ptr)
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    uint8_t playerClass = playerSpawn->Class;
    if (playerClass == EQ_CLASS_UNKNOWN || playerClass == EQ_CLASS_WARRIOR || playerClass == EQ_CLASS_MONK || playerClass == EQ_CLASS_ROGUE)
    {
        return;
    }

    EQ::CMerchantWnd_ptr merchantWindow = (EQ::CMerchantWnd_ptr)this_ptr;
    if (merchantWindow == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_MERCHANT_SLOTS; i++)
    {
        EQ::Item_ptr item = merchantWindow->Item[i];
        if (item == NULL)
        {
            continue;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        if ((itemName.find("Spell:") == std::string::npos) && (itemName.find("Ancient:") == std::string::npos) && (itemName.find("Song:") == std::string::npos))
        {
            continue;
        }

        uint16_t spellID = item->Common.SpellID;
        if (spellID == 0 || spellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        EQ::Spell_ptr spell = EQ_POINTER_SpellList->Spell[spellID];
        if (spell == NULL)
        {
            continue;
        }

        int spellLevelNeeded = (int)spell->Level[playerClass - 1];
        if (spellLevelNeeded == EQ_SPELL_LEVEL_NEEDED_CANNOT_USE)
        {
            continue;
        }

        EQ::CsidlScreenWnd_ptr merchantSlotWnd = (EQ::CsidlScreenWnd_ptr)merchantWindow->MerchantSlotWnd[i];
        if (merchantSlotWnd == NULL)
        {
            continue;
        }

        if (merchantSlotWnd->Window.ToolTipText == NULL || merchantSlotWnd->Window.Font == NULL)
        {
            continue;
        }

        std::string originalToolTipText = merchantSlotWnd->Window.ToolTipText->Text;
        if (originalToolTipText.size() == 0)
        {
            continue;
        }

        if (originalToolTipText.find("(") == std::string::npos)
        {
            std::stringstream newToolTipText;
            newToolTipText << originalToolTipText << " (" << spellLevelNeeded;

            signed int spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellID);
            if (spellBookIndex != -1)
            {
                newToolTipText << "*";
            }

            newToolTipText << ")";

            EQ_CXStr_Set(&merchantSlotWnd->Window.ToolTipText, newToolTipText.str().c_str());
        }
    }
}

void EQAPP_MerchantWindow_HandleEvent_CMerchantWnd__PostDraw(void* this_ptr)
{
    if (EQ_IsKeyPressedAlt() == true)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    uint8_t playerClass = playerSpawn->Class;
    if (playerClass == EQ_CLASS_UNKNOWN || playerClass == EQ_CLASS_WARRIOR || playerClass == EQ_CLASS_MONK || playerClass == EQ_CLASS_ROGUE)
    {
        return;
    }

    EQ::CMerchantWnd_ptr merchantWindow = (EQ::CMerchantWnd_ptr)this_ptr;
    if (merchantWindow == NULL)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_MERCHANT_SLOTS; i++)
    {
        EQ::Item_ptr item = merchantWindow->Item[i];
        if (item == NULL)
        {
            continue;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        if ((itemName.find("Spell:") == std::string::npos) && (itemName.find("Ancient:") == std::string::npos) && (itemName.find("Song:") == std::string::npos))
        {
            continue;
        }

        uint16_t spellID = item->Common.SpellID;
        if (spellID == 0 || spellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        EQ::Spell_ptr spell = EQ_POINTER_SpellList->Spell[spellID];
        if (spell == NULL)
        {
            continue;
        }

        int spellLevelNeeded = (int)spell->Level[playerClass - 1];
        if (spellLevelNeeded == EQ_SPELL_LEVEL_NEEDED_CANNOT_USE)
        {
            continue;
        }

        EQ::CsidlScreenWnd_ptr merchantSlotWnd = (EQ::CsidlScreenWnd_ptr)merchantWindow->MerchantSlotWnd[i];
        if (merchantSlotWnd == NULL)
        {
            continue;
        }

        EQ::CsidlScreenWnd_ptr merchantSlotParentWnd = (EQ::CsidlScreenWnd_ptr)merchantSlotWnd->Window.ParentWnd;
        if (merchantSlotParentWnd == NULL)
        {
            continue;
        }

        EQClass::CXRect merchantSlotWndRect = ((EQClass::CXWnd*)merchantSlotWnd)->GetScreenRect();
        EQClass::CXRect merchantSlotParentWndRect = ((EQClass::CXWnd*)merchantSlotParentWnd)->GetScreenRect();

        if
        (
            EQ_IsPointInsideRectangle
            (
                merchantSlotWndRect.X1, merchantSlotWndRect.Y1,
                merchantSlotParentWndRect.X1, merchantSlotParentWndRect.Y1,
                merchantSlotParentWndRect.X2 - merchantSlotParentWndRect.X1,
                merchantSlotParentWndRect.Y2 - merchantSlotParentWndRect.Y1
            )
            == false
        )
        {
            continue;
        }

        if (merchantSlotWnd->Window.ToolTipText == NULL || merchantSlotWnd->Window.Font == NULL)
        {
            continue;
        }

        std::string originalToolTipText = merchantSlotWnd->Window.ToolTipText->Text;
        if (originalToolTipText.size() == 0)
        {
            continue;
        }

        std::stringstream newToolTipText;
        newToolTipText << spellLevelNeeded;

        signed int spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellID);
        if (spellBookIndex != -1)
        {
            newToolTipText << "*";
        }

        merchantSlotWnd->Window.Font->Size = g_merchantWindowFontSize;

        EQ_CXStr_Set(&merchantSlotWnd->Window.ToolTipText, newToolTipText.str().c_str());

        ((EQClass::CXWnd*)merchantSlotWnd)->DrawTooltipAtPoint(merchantSlotWndRect.X1, merchantSlotWndRect.Y1);

        EQ_CXStr_Set(&merchantSlotWnd->Window.ToolTipText, originalToolTipText.c_str());

        merchantSlotWnd->Window.Font->Size = EQ_FONT_SIZE_DEFAULT;
    }
}

