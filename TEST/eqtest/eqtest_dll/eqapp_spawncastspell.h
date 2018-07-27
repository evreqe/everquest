#pragma once

namespace EQApp
{
    typedef struct _SpawnCastSpell
    {
        uint32_t Spawn;
        std::string SpellName;
        uint16_t SpellCastTime; // time it takes to cast the spell in milliseconds
        uint32_t SpellCastTimeCountdown; // spell cast time in milliseconds that decreases until it reaches a value of 0
        uint32_t StartCastingTime = 0; // time you started to cast the spell in the global timer
    } SpawnCastSpell, *SpawnCastSpell_ptr;

    typedef std::shared_ptr<EQApp::SpawnCastSpell> SpawnCastSpell_sharedptr;
}

bool g_SpawnCastSpellIsEnabled = true;

bool g_SpawnCastSpellGroupChatIsEnabled = true;

bool g_SpawnCastSpellESPIsEnabled = true;

std::vector<EQApp::SpawnCastSpell_sharedptr> g_SpawnCastSpellList;

uint32_t g_SpawnCastSpellMinimumCastTime = 3000;

uint32_t g_SpawnCastSpellCountdownTimer = 0;
uint32_t g_SpawnCastSpellCountdownTimerInterval = 100;

uint32_t g_SpawnCastSpellDrawTextX = 1000;
uint32_t g_SpawnCastSpellDrawTextY = 200;

void EQAPP_SpawnCastSpell_Toggle();
void EQAPP_SpawnCastSpell_On();
void EQAPP_SpawnCastSpell_Off();
void EQAPP_SpawnCastSpell_ESP_Toggle();
void EQAPP_SpawnCastSpell_GroupChat_Toggle();
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

void EQAPP_SpawnCastSpell_ESP_Toggle()
{
    EQ_ToggleBool(g_SpawnCastSpellESPIsEnabled);
    EQAPP_PrintBool("Spawn Cast Spell ESP", g_SpawnCastSpellESPIsEnabled);
}

void EQAPP_SpawnCastSpell_GroupChat_Toggle()
{
    EQ_ToggleBool(g_SpawnCastSpellGroupChatIsEnabled);
    EQAPP_PrintBool("Spawn Cast Spell Group Chat", g_SpawnCastSpellGroupChatIsEnabled);
}

void EQAPP_SpawnCastSpell_Execute()
{
    if (g_SpawnCastSpellList.size() == 0)
    {
        return;
    }

    uint32_t currentTime = EQ_GetTimer();

    bool bCountdownTimerHasPassed = false;
    if (EQ_HasTimeElapsed(g_SpawnCastSpellCountdownTimer, g_SpawnCastSpellCountdownTimerInterval) == true)
    {
        bCountdownTimerHasPassed = true;
    }

    for (auto spawnCastSpellListIterator = g_SpawnCastSpellList.begin(); spawnCastSpellListIterator != g_SpawnCastSpellList.end(); spawnCastSpellListIterator++)
    {
        auto spawnCastSpell = spawnCastSpellListIterator->get();
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        uint32_t spawn = spawnCastSpell->Spawn;
        if (spawn == NULL)
        {
            spawnCastSpellListIterator = g_SpawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }

        auto standingState = EQ_GetSpawnStandingState(spawn);
        if (standingState != EQ_STANDING_STATE_STANDING)
        {
            spawnCastSpell->SpellCastTime = 0;
            spawnCastSpell->SpellCastTimeCountdown = 0;
        }

        if (bCountdownTimerHasPassed == true)
        {
            if (spawnCastSpell->SpellCastTimeCountdown > 0 && spawnCastSpell->SpellCastTimeCountdown > g_SpawnCastSpellCountdownTimerInterval)
            {
                spawnCastSpell->SpellCastTimeCountdown -= g_SpawnCastSpellCountdownTimerInterval;
            }
            else if (spawnCastSpell->SpellCastTimeCountdown <= g_SpawnCastSpellCountdownTimerInterval)
            {
                spawnCastSpell->SpellCastTimeCountdown = 0;
            }
        }

        uint32_t spellCastTime = spawnCastSpell->SpellCastTime;
        if (spellCastTime < g_SpawnCastSpellMinimumCastTime)
        {
            spellCastTime = g_SpawnCastSpellMinimumCastTime;
        }

        if ((currentTime - spawnCastSpell->StartCastingTime) > spellCastTime)
        {
            spawnCastSpellListIterator = g_SpawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }
    }
}

void EQAPP_SpawnCastSpell_DrawText()
{
    if (g_SpawnCastSpellList.size() == 0)
    {
        return;
    }

    fmt::MemoryWriter drawText;

    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        uint32_t spawn = spawnCastSpell->Spawn;
        if (spawn == NULL)
        {
            continue;
        }

        std::string spawnName = EQ_GetSpawnName(spawnCastSpell->Spawn);
        if (spawnName.size() == 0)
        {
            continue;
        }

        drawText << spawnName; 

        auto spawnClass = EQ_GetSpawnClass(spawn);

        std::string spawnClassShortName = EQ_GetClassShortNameByID(spawnClass);
        if (spawnClassShortName.size() != 0)
        {
            drawText << " (" << spawnClassShortName << ")";
        }

        if (spawnCastSpell->SpellName.size() != 0)
        {
            drawText << " <" << spawnCastSpell->SpellName << ">";
        }

        if (spawnCastSpell->SpellCastTimeCountdown > 0)
        {
            float spellCastTimeCurrentFloat = (float)(spawnCastSpell->SpellCastTimeCountdown / 1000.0f);

            //drawText.precision(1);
            //drawText << " " << std::fixed << spellCastTimeCurrentFloat;
            drawText << fmt::format(" {:.2f}", spellCastTimeCurrentFloat);
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
    if (spellName.size() == 0)
    {
        return;
    }

    if (g_SpawnCastSpellGroupChatIsEnabled == true)
    {
        auto playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn != NULL)
        {
            if (spawn == playerSpawn)
            {
                auto spawnClass = EQ_GetSpawnClass(playerSpawn);
                if (spawnClass != EQ_CLASS_BARD)
                {
                    auto spawnName = EQ_GetPlayerSpawnName();
                    if (spawnName.size() != 0)
                    {
                        std::stringstream ss;
                        ss << "/gsay casting " << spellName;

                        auto targetSpawn = EQ_GetTargetSpawn();
                        if (targetSpawn != NULL)
                        {
                            auto targetName = EQ_GetTargetSpawnName();
                            if (targetName.size() != 0)
                            {
                                ss << " on " << targetName;
                            }
                        }

                        EQ_InterpretCommand(ss.str().c_str());
                    }
                }
            }
        }
    }

    // update if spawn already exists in the list
    for (auto& spawnCastSpell : g_SpawnCastSpellList)
    {
        if (spawnCastSpell->Spawn == spawn)
        {
            spawnCastSpell->SpellName              = spellName;
            spawnCastSpell->SpellCastTime          = spellCastTime;
            spawnCastSpell->SpellCastTimeCountdown = spellCastTime;
            spawnCastSpell->StartCastingTime       = EQ_GetTimer();
            return;
        }
    }

    // add to the list
    auto spawnCastSpell = std::make_shared<EQApp::SpawnCastSpell>();
    spawnCastSpell->Spawn                  = spawn;
    spawnCastSpell->SpellName              = spellName;
    spawnCastSpell->SpellCastTime          = spellCastTime;
    spawnCastSpell->SpellCastTimeCountdown = spellCastTime;
    spawnCastSpell->StartCastingTime       = EQ_GetTimer();

    g_SpawnCastSpellList.push_back(std::move(spawnCastSpell));
}
