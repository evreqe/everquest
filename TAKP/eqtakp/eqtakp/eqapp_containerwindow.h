#pragma once

bool g_ContainerWindowIsEnabled = true;

unsigned int g_ContainerWindowFontSize = 1;

void EQAPP_ContainerWindow_Toggle();
void EQAPP_ContainerWindow_AppendSpellLevelToToolTipText_HandleEvent_CContainerWnd__PostDraw(void* this_ptr);
void EQAPP_ContainerWindow_AppendSpellLevelToItemSlot_HandleEvent_CContainerWnd__PostDraw(void* this_ptr);

void EQAPP_ContainerWindow_Toggle()
{
    EQ_ToggleBool(g_ContainerWindowIsEnabled);
    EQAPP_PrintBool("Container Window", g_ContainerWindowIsEnabled);
}

void EQAPP_ContainerWindow_AppendSpellLevelToToolTipText_HandleEvent_CContainerWnd__PostDraw(void* this_ptr)
{
    EQ::CContainerWnd_ptr containerWindow = (EQ::CContainerWnd_ptr)this_ptr;
    if (containerWindow == NULL)
    {
        return;
    }

    EQ::Item_ptr containerItem = containerWindow->ContainerItem;
    if (containerItem == NULL)
    {
        return;
    }

    if (containerItem->IsContainer == 0)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_CONTAINER_SLOTS; i++)
    {
        EQ::Item_ptr item = containerItem->Container.Item[i];
        if (item == NULL)
        {
            continue;
        }

        if (item->Common.Type != EQ_ITEM_TYPE_SPELL_SCROLL)
        {
            continue;
        }

        EQ_SpellID_t spellID = item->Common.SpellID;
        if (EQ_IsSpellIDValid(spellID) == false)
        {
            continue;
        }

        EQ::Spell_ptr spell = EQ_POINTER_SpellList->Spell[spellID];
        if (spell == NULL)
        {
            continue;
        }

        std::stringstream spellLevelNeededBuffer;

        for (int i = 0; i < (EQ_NUM_CLASSES + 1); i++)
        {
            int spellClass = i + 1;

            uint8_t spellLevel = spell->Level[spellClass];

            if (spellLevel != 0 && spellLevel != EQ_SPELL_LEVEL_NEEDED_CANNOT_USE)
            {
                std::string spellClassName = EQ_GetClassShortName(spellClass + 1);
                if (spellClassName.size() != 0)
                {
                    spellLevelNeededBuffer << spellClassName << " " << (int)spellLevel << " ";
                }
            }
        }

        std::string spellLevelNeededText = spellLevelNeededBuffer.str();
        spellLevelNeededText.pop_back(); // remove trailing space

        EQ::CsidlScreenWnd_ptr containerSlotWnd = (EQ::CsidlScreenWnd_ptr)containerWindow->ContainerSlotWnd[i];
        if (containerSlotWnd == NULL)
        {
            continue;
        }

        if (containerSlotWnd->Window.ToolTipText == NULL || containerSlotWnd->Window.Font == NULL)
        {
            continue;
        }

        std::string originalToolTipText = containerSlotWnd->Window.ToolTipText->Text;
        if (originalToolTipText.size() == 0)
        {
            continue;
        }

        if (originalToolTipText.find("(") == std::string::npos)
        {
            std::stringstream newToolTipText;
            newToolTipText << originalToolTipText << " (" << spellLevelNeededText;

            signed int spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellID);
            if (spellBookIndex != -1)
            {
                newToolTipText << "*";
            }

            newToolTipText << ")";

            EQ_CXStr_Set(&containerSlotWnd->Window.ToolTipText, newToolTipText.str().c_str());
        }
    }
}

void EQAPP_ContainerWindow_AppendSpellLevelToItemSlot_HandleEvent_CContainerWnd__PostDraw(void* this_ptr)
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

    auto playerClass = playerSpawn->Class;
    if (EQ_IsClassSpellCaster(playerClass) == false)
    {
        return;
    }

    EQ::CContainerWnd_ptr containerWindow = (EQ::CContainerWnd_ptr)this_ptr;
    if (containerWindow == NULL)
    {
        return;
    }

    EQ::Item_ptr containerItem = containerWindow->ContainerItem;
    if (containerItem == NULL)
    {
        return;
    }

    if (containerItem->IsContainer == 0)
    {
        return;
    }

    for (size_t i = 0; i < EQ_NUM_CONTAINER_SLOTS; i++)
    {
        EQ::Item_ptr item = containerItem->Container.Item[i];
        if (item == NULL)
        {
            continue;
        }

        if (item->Common.Type != EQ_ITEM_TYPE_SPELL_SCROLL)
        {
            continue;
        }

        EQ_SpellID_t spellID = item->Common.SpellID;
        if (EQ_IsSpellIDValid(spellID) == false)
        {
            continue;
        }

        EQ::Spell_ptr spell = EQ_POINTER_SpellList->Spell[spellID];
        if (spell == NULL)
        {
            continue;
        }

        auto spellLevelNeeded = spell->Level[playerClass - 1];
        if (spellLevelNeeded == EQ_SPELL_LEVEL_NEEDED_CANNOT_USE)
        {
            continue;
        }

        EQ::CsidlScreenWnd_ptr containerSlotWnd = (EQ::CsidlScreenWnd_ptr)containerWindow->ContainerSlotWnd[i];
        if (containerSlotWnd == NULL)
        {
            continue;
        }

        EQ::CsidlScreenWnd_ptr containerSlotParentWnd = (EQ::CsidlScreenWnd_ptr)containerSlotWnd->Window.ParentWnd;
        if (containerSlotParentWnd == NULL)
        {
            continue;
        }

        EQClass::CXRect containerSlotWndRect = ((EQClass::CXWnd*)containerSlotWnd)->GetScreenRect();
        EQClass::CXRect containerSlotParentWndRect = ((EQClass::CXWnd*)containerSlotParentWnd)->GetScreenRect();

        if
        (
            EQ_IsPointInsideRectangle
            (
                containerSlotWndRect.X1, containerSlotWndRect.Y1,
                containerSlotParentWndRect.X1, containerSlotParentWndRect.Y1,
                containerSlotParentWndRect.X2 - containerSlotParentWndRect.X1,
                containerSlotParentWndRect.Y2 - containerSlotParentWndRect.Y1
            )
            == false
        )
        {
            continue;
        }

        if (containerSlotWnd->Window.ToolTipText == NULL || containerSlotWnd->Window.Font == NULL)
        {
            continue;
        }

        std::string originalToolTipText = containerSlotWnd->Window.ToolTipText->Text;
        if (originalToolTipText.size() == 0)
        {
            continue;
        }

        std::stringstream newToolTipText;
        newToolTipText << (int)spellLevelNeeded;

        signed int spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(spellID);
        if (spellBookIndex != -1)
        {
            newToolTipText << " *";
        }

        containerSlotWnd->Window.Font->Size = g_ContainerWindowFontSize;

        EQ_CXStr_Set(&containerSlotWnd->Window.ToolTipText, newToolTipText.str().c_str());

        ((EQClass::CXWnd*)containerSlotWnd)->DrawTooltipAtPoint(containerSlotWndRect.X1, containerSlotWndRect.Y1);

        EQ_CXStr_Set(&containerSlotWnd->Window.ToolTipText, originalToolTipText.c_str());

        containerSlotWnd->Window.Font->Size = EQ_FONT_SIZE_DEFAULT;
    }
}
