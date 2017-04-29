#pragma once

bool g_buffTimersIsEnabled = true;

unsigned int g_buffTimersFontSize = 1;

void EQAPP_BuffTimers_RefreshBuffDisplay(void* this_ptr);
void EQAPP_BuffTimers_PostDraw(void* this_ptr);

void EQAPP_BuffTimers_RefreshBuffDisplay(void* this_ptr)
{
    EQ::CBuffWindow_ptr buffWindow = (EQ::CBuffWindow_ptr)this_ptr;

    for (size_t i = 0; i < EQ_NUM_BUFFS; i++)
    {
        uint16_t spellID = EQ_POINTER_PlayerCharacter->Buff[i].SpellID;
        if (spellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        uint16_t buffTicks = EQ_POINTER_PlayerCharacter->Buff[i].Ticks;
        if (buffTicks == 0)
        {
            continue;
        }

        std::string buffTimeText = EQ_GetTickTimeString(buffTicks);EQ_GetTickTimeString(buffTicks);

        std::stringstream ssBuffTimeText;
        ssBuffTimeText << " (" << buffTimeText << ")";

        EQ::CsidlScreenWnd_ptr buffButtonWnd = (EQ::CsidlScreenWnd_ptr)buffWindow->BuffButtonWnd[i];

        if (buffButtonWnd != nullptr)
        {
            if (buffButtonWnd->Window.ToolTipText != nullptr)
            {
                EQ_CXStr_Append(&buffButtonWnd->Window.ToolTipText, (char*)ssBuffTimeText.str().c_str());
            }
        }
    }
}

void EQAPP_BuffTimers_PostDraw(void* this_ptr)
{
    EQ::CBuffWindow_ptr buffWindow = (EQ::CBuffWindow_ptr)this_ptr;

    for (size_t i = 0; i < EQ_NUM_BUFFS; i++)
    {
        uint16_t spellID = EQ_POINTER_PlayerCharacter->Buff[i].SpellID;
        if (spellID == EQ_SPELL_ID_NULL)
        {
            continue;
        }

        uint16_t buffTicks = EQ_POINTER_PlayerCharacter->Buff[i].Ticks;
        if (buffTicks == 0)
        {
            continue;
        }

        std::string buffTimeText = EQ_GetTickTimeString(buffTicks);

        EQ::CsidlScreenWnd_ptr buffButtonWnd = (EQ::CsidlScreenWnd_ptr)buffWindow->BuffButtonWnd[i];

        if (buffButtonWnd != nullptr)
        {
            if (buffButtonWnd->Window.ToolTipText != nullptr && buffButtonWnd->Window.Font != nullptr)
            {
                buffButtonWnd->Window.Font->Size = g_buffTimersFontSize;

                std::string originalToolTipText = buffButtonWnd->Window.ToolTipText->Text;

                EQ_CXStr_Set(&buffButtonWnd->Window.ToolTipText, (char*)buffTimeText.c_str());

                EQClass::CXRect screenRect = ((EQClass::CXWnd*)buffButtonWnd)->GetScreenRect();

                ((EQClass::CXWnd*)buffButtonWnd)->DrawTooltipAtPoint(screenRect.X1, screenRect.Y1);

                EQ_CXStr_Set(&buffButtonWnd->Window.ToolTipText, (char*)originalToolTipText.c_str());

                buffButtonWnd->Window.Font->Size = EQ_FONT_SIZE_DEFAULT;
            }
        }
    }
}

