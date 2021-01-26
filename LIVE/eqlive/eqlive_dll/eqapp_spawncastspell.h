#pragma once

namespace EQApp
{
    typedef struct _SpawnCastSpell
    {
        uint32_t Spawn;
        std::string SpellName;
        uint32_t SpellCastTime; // time it takes to cast the spell in milliseconds
        uint32_t SpellCastTimeCountdown; // spell cast time in milliseconds that decreases until it reaches a value of 0
        uint32_t StartCastingTime = 0; // time spawn started to cast the spell in the global timer
    } SpawnCastSpell, *SpawnCastSpell_ptr;

    typedef std::vector<EQApp::SpawnCastSpell> SpawnCastSpellList;
}

bool g_SpawnCastSpellIsEnabled = true;

bool g_SpawnCastSpellDrawTextIsEnabled = true;

bool g_SpawnCastSpellNamePlatesIsEnabled = true;

EQApp::SpawnCastSpellList g_SpawnCastSpellList;

uint32_t g_SpawnCastSpellMinimumCastTime = 2000;

EQApp::Timer g_SpawnCastSpellCountdownTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_SpawnCastSpellCountdownTimerInterval = 100;

uint32_t g_SpawnCastSpellDrawTextX = 1000;
uint32_t g_SpawnCastSpellDrawTextY = 200;

void EQAPP_SpawnCastSpell_Toggle();
void EQAPP_SpawnCastSpell_On();
void EQAPP_SpawnCastSpell_Off();
void EQAPP_SpawnCastSpell_DrawText_Toggle();
void EQAPP_SpawnCastSpell_DrawText_On();
void EQAPP_SpawnCastSpell_DrawText_Off();
void EQAPP_SpawnCastSpell_NamePlates_Toggle();
void EQAPP_SpawnCastSpell_NamePlates_On();
void EQAPP_SpawnCastSpell_NamePlates_Off();
void EQAPP_SpawnCastSpell_Execute();
void EQAPP_SpawnCastSpell_DrawText();
void EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQMessage::CEverQuest__StartCasting_ptr message);

void EQAPP_SpawnCastSpell_Toggle()
{
    EQ_ToggleBool(g_SpawnCastSpellIsEnabled);
    EQAPP_PrintBool("Spawn Cast Spell", g_SpawnCastSpellIsEnabled);
}

void EQAPP_SpawnCastSpell_On()
{
    if (g_SpawnCastSpellIsEnabled == false)
    {
        EQAPP_SpawnCastSpell_Toggle();
    }
}

void EQAPP_SpawnCastSpell_Off()
{
    if (g_SpawnCastSpellIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_Toggle();
    }
}

void EQAPP_SpawnCastSpell_DrawText_Toggle()
{
    EQ_ToggleBool(g_SpawnCastSpellDrawTextIsEnabled);
    EQAPP_PrintBool("Spawn Cast Spell Draw Text", g_SpawnCastSpellDrawTextIsEnabled);
}

void EQAPP_SpawnCastSpell_DrawText_On()
{
    if (g_SpawnCastSpellDrawTextIsEnabled == false)
    {
        EQAPP_SpawnCastSpell_DrawText_Toggle();
    }
}

void EQAPP_SpawnCastSpell_DrawText_Off()
{
    if (g_SpawnCastSpellDrawTextIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_DrawText_Toggle();
    }
}

void EQAPP_SpawnCastSpell_NamePlates_Toggle()
{
    EQ_ToggleBool(g_SpawnCastSpellNamePlatesIsEnabled);
    EQAPP_PrintBool("Spawn Cast Spell Name Plates", g_SpawnCastSpellNamePlatesIsEnabled);
}

void EQAPP_SpawnCastSpell_NamePlates_On()
{
    if (g_SpawnCastSpellNamePlatesIsEnabled == false)
    {
        EQAPP_SpawnCastSpell_NamePlates_Toggle();
    }
}

void EQAPP_SpawnCastSpell_NamePlates_Off()
{
    if (g_SpawnCastSpellNamePlatesIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_NamePlates_Toggle();
    }
}

void EQAPP_SpawnCastSpell_Execute()
{
    if (g_SpawnCastSpellList.empty() == true)
    {
        return;
    }

    bool bCountdownTimerHasPassed = false;
    if (EQAPP_Timer_HasTimeElapsedInMilliseconds(g_SpawnCastSpellCountdownTimer, g_SpawnCastSpellCountdownTimerInterval) == true)
    {
        bCountdownTimerHasPassed = true;
    }

    auto numErased = std::erase_if
    (
        g_SpawnCastSpellList,
    [](const EQApp::SpawnCastSpell& spawnCastSpell) -> bool
        {
            if (spawnCastSpell.Spawn == NULL)
            {
                return true;
            }

            auto standingState = EQ_GetSpawnStandingState(spawnCastSpell.Spawn);
            if (standingState != EQ_STANDING_STATE_STANDING)
            {
                return true;
            }

            auto spellCastTime = spawnCastSpell.SpellCastTime;
            if (spellCastTime < g_SpawnCastSpellMinimumCastTime)
            {
                spellCastTime = g_SpawnCastSpellMinimumCastTime;
            }

            auto currentTime = EQ_GetTimer();

            if ((currentTime - spawnCastSpell.StartCastingTime) > spellCastTime)
            {
                return true;
            }

            return false;
        }
    );

    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (bCountdownTimerHasPassed == true)
        {
            if (spawnCastSpell.SpellCastTimeCountdown > 0 && spawnCastSpell.SpellCastTimeCountdown > (uint32_t)g_SpawnCastSpellCountdownTimerInterval)
            {
                spawnCastSpell.SpellCastTimeCountdown -= (uint32_t)g_SpawnCastSpellCountdownTimerInterval;
            }
            else if (spawnCastSpell.SpellCastTimeCountdown <= (uint32_t)g_SpawnCastSpellCountdownTimerInterval)
            {
                spawnCastSpell.SpellCastTimeCountdown = 0;
            }
        }
    }

    if (g_SpawnCastSpellDrawTextIsEnabled == true)
    {
        EQAPP_SpawnCastSpell_DrawText();
    }
}

void EQAPP_SpawnCastSpell_DrawText()
{
    std::stringstream drawText;

    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        auto spawn = spawnCastSpell.Spawn;
        if (spawn == NULL)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawnCastSpell.Spawn);
        if (spawnName.empty() == true)
        {
            continue;
        }

        auto spawnClass = EQ_GetSpawnClass(spawn);

        std::string spawnClassShortName = EQ_GetClassShortNameByID(spawnClass);
        if (spawnClassShortName.empty() == false)
        {
            drawText << "[" << spawnClassShortName << "] ";
        }

        drawText << spawnName; 

        if (spawnCastSpell.SpellName.empty() == false)
        {
            drawText << " -> " << spawnCastSpell.SpellName;
        }

        if (spawnCastSpell.SpellCastTimeCountdown > 0)
        {
            float spellCastTimeCurrentFloat = (float)(spawnCastSpell.SpellCastTimeCountdown / 1000.0f);

            drawText << fmt::format(" ({:.2f}s)", spellCastTimeCurrentFloat);
        }

        drawText << "\n";
    }

    EQ_DrawTextByColor(drawText.str().c_str(), g_SpawnCastSpellDrawTextX, g_SpawnCastSpellDrawTextY, EQ_DRAW_TEXT_COLOR_WHITE);
}

void EQAPP_SpawnCastSpell_HandleEvent_CEverQuest__StartCasting(void* this_ptr, EQMessage::CEverQuest__StartCasting_ptr message)
{
    auto spawn = EQ_GetSpawnByID(message->SpawnID);
    if (spawn == NULL)
    {
        return;
    }

    auto spellCastTime = message->SpellCastTime;
    if (spellCastTime == 0)
    {
        return;
    }

    auto spellID = message->SpellID;
    if (EQ_IsSpellIDValid(spellID) == false)
    {
        return;
    }

    std::string spellName = EQ_GetSpellNameByID(spellID);
    if (spellName.empty() == true)
    {
        return;
    }

    // update if spawn already exists in the list
    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (spawnCastSpell.Spawn == spawn)
        {
            spawnCastSpell.SpellName              = spellName;
            spawnCastSpell.SpellCastTime          = spellCastTime;
            spawnCastSpell.SpellCastTimeCountdown = spellCastTime;
            spawnCastSpell.StartCastingTime       = EQ_GetTimer();
            return;
        }
    }

    // add to the list
    EQApp::SpawnCastSpell spawnCastSpell;
    spawnCastSpell.Spawn                  = spawn;
    spawnCastSpell.SpellName              = spellName;
    spawnCastSpell.SpellCastTime          = spellCastTime;
    spawnCastSpell.SpellCastTimeCountdown = spellCastTime;
    spawnCastSpell.StartCastingTime       = EQ_GetTimer();

    g_SpawnCastSpellList.push_back(spawnCastSpell);
}
