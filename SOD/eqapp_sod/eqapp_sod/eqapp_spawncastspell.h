#pragma once

namespace EQApp
{
    typedef struct _SpawnCastSpell
    {
        uint32_t index;
        uint32_t spawnInfo;
        std::string spellName;
        uint32_t spellId;
        uint32_t spellCastTime; // time it takes to cast the spell in milliseconds
        uint32_t spellCastTimeCountdown; // spell cast time in milliseconds that decreases until it reaches a value of 0
        uint32_t startTimer = 0; // time you started to cast the spell in the global timer
    } SpawnCastSpell, *SpawnCastSpell_ptr;

    typedef std::shared_ptr<EQApp::SpawnCastSpell> SpawnCastSpell_sharedptr;
}

bool g_spawnCastSpellIsEnabled = true;
bool g_spawnCastSpellEspIsEnabled = true;
std::vector<EQApp::SpawnCastSpell_sharedptr> g_spawnCastSpellList;
uint32_t g_spawnCastSpellTimerDelay = 5000;

bool g_spawnCastSpellDrawBarsIsEnabled = true;
bool g_spawnCastSpellDrawBarsForPlayerIsEnabled = true;
bool g_spawnCastSpellDrawBarsForNpcIsEnabled = true;
bool g_spawnCastSpellDrawBarsForHealerClassOnlyIsEnabled = false;
float g_spawnCastSpellDrawBarsX = 200.0f;
float g_spawnCastSpellDrawBarsY = 28.0f;
float g_spawnCastSpellDrawBarsOffsetX = 0.0f;
float g_spawnCastSpellDrawBarsOffsetY = 0.0f;
float g_spawnCastSpellDrawBarsWidthMultiplier = 3.0f;
float g_spawnCastSpellDrawBarsWidthOffset = 4.0f;
float g_spawnCastSpellDrawBarsHeight = 15.0f;
float g_spawnCastSpellDrawBarsHeightOffset = 5.0f;
uint32_t g_spawnCastSpellDrawBarsCount = 0;
uint32_t g_spawnCastSpellDrawBarsMax = 25;
uint32_t g_spawnCastSpellDrawBarsMinimumSpellCastTime = 1000;
uint32_t g_spawnCastSpellCountdownTimer = 0;
uint32_t g_spawnCastSpellCountdownTimerDelay = 100;

void EQAPP_SpawnCastSpell_Execute();
void EQAPP_SpawnCastSpell_Add(uint32_t spawnInfo, uint32_t spellId, uint32_t spellCastTime);

void EQAPP_SpawnCastSpell_Execute()
{
    if (g_spawnCastSpellIsEnabled == false)
    {
        return;
    }

    if (g_spawnCastSpellList.size() == 0)
    {
        return;
    }

    uint32_t currentTimer = EQ_GetTimer();

    bool countdownTimerHasPassed = false;
    if (EQ_HasTimePassed(g_spawnCastSpellCountdownTimer, g_spawnCastSpellCountdownTimerDelay) == true)
    {
        countdownTimerHasPassed = true;
    }

    g_spawnCastSpellDrawBarsOffsetX = 0.0f;
    g_spawnCastSpellDrawBarsOffsetY = 0.0f;

    g_spawnCastSpellDrawBarsCount = 0;

    for (auto spawnCastSpellListIterator = g_spawnCastSpellList.begin(); spawnCastSpellListIterator != g_spawnCastSpellList.end(); spawnCastSpellListIterator++)
    {
        EQApp::SpawnCastSpell* spawnCastSpell = spawnCastSpellListIterator->get();
        if (spawnCastSpell == nullptr)
        {
            continue;
        }

        // move high index to low index
        if (spawnCastSpell->index > g_spawnCastSpellDrawBarsMax)
        {
            uint32_t newIndex = 0;
            for (auto& spawnCastSpell_it = g_spawnCastSpellList.begin(); spawnCastSpell_it != g_spawnCastSpellList.end(); spawnCastSpell_it++)
            {
                if ((*spawnCastSpell_it)->index == newIndex)
                {
                    newIndex++;
                    spawnCastSpell_it = g_spawnCastSpellList.begin();
                }
            }

            if (newIndex < g_spawnCastSpellDrawBarsMax)
            {
                spawnCastSpell->index = newIndex;
            }
        }

        int spawnStandingState = EQ_ReadMemory<uint8_t>(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_STANDING_STATE);
        if (spawnStandingState != EQ_STANDING_STATE_STANDING)
        {
            spawnCastSpell->spellCastTime = 0;
            spawnCastSpell->spellCastTimeCountdown = 0;
        }

        if (countdownTimerHasPassed == true)
        {
            if (spawnCastSpell->spellCastTimeCountdown > 0 && spawnCastSpell->spellCastTimeCountdown > g_spawnCastSpellCountdownTimerDelay)
            {
                spawnCastSpell->spellCastTimeCountdown -= g_spawnCastSpellCountdownTimerDelay;
            }
            else if (spawnCastSpell->spellCastTimeCountdown <= g_spawnCastSpellCountdownTimerDelay)
            {
                spawnCastSpell->spellCastTimeCountdown = 0;
            }
        }

        if (g_spawnCastSpellDrawBarsIsEnabled == true)
        {
            uint32_t spellCastTimeTotal   = spawnCastSpell->spellCastTime;
            uint32_t spellCastTimeCurrent = spawnCastSpell->spellCastTimeCountdown;

            if
            (
                g_spawnCastSpellDrawBarsCount < g_spawnCastSpellDrawBarsMax &&
                spellCastTimeTotal > g_spawnCastSpellDrawBarsMinimumSpellCastTime &&
                spellCastTimeTotal > 0 && spellCastTimeCurrent > 0
            )
            {
                bool bDrawCastBar = true;

                int spawnType = EQ_ReadMemory<uint8_t>(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_TYPE);

                if (g_spawnCastSpellDrawBarsForPlayerIsEnabled == false && spawnType == EQ_SPAWN_TYPE_PLAYER)
                {
                    bDrawCastBar = false;
                }

                if (g_spawnCastSpellDrawBarsForNpcIsEnabled == false && spawnType == EQ_SPAWN_TYPE_NPC)
                {
                    bDrawCastBar = false;
                }

                int spawnClass = EQ_ReadMemory<uint8_t>(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_CLASS);

                if (g_spawnCastSpellDrawBarsForHealerClassOnlyIsEnabled == true)
                {
                    if (spawnClass != EQ_CLASS_CLERIC && spawnClass != EQ_CLASS_DRUID && spawnClass != EQ_CLASS_SHAMAN)
                    {
                        bDrawCastBar = false;
                    }
                }

                if (bDrawCastBar == true)
                {
                    char spawnName[EQ_SIZE_SPAWN_INFO_NAME] = { 0 };
                    memcpy(spawnName, (void*)(spawnCastSpell->spawnInfo + EQ_OFFSET_SPAWN_INFO_NAME), sizeof(spawnName));

                    uint32_t drawColorARGB = 0xFFFFFFFF; // white
                    uint32_t textSize = 2;

                    uint32_t targetSpawn = EQ_GetTargetSpawn();
                    if (spawnCastSpell->spawnInfo == targetSpawn)
                    {
                        drawColorARGB = 0xFFFF00FF; // pink
                    }
                    else
                    {
                        if (EQ_IsSpawnInGroup(spawnCastSpell->spawnInfo) == true)
                        {
                            drawColorARGB = 0xFF00FF00; // green
                        }
                        else
                        {
                            if (spawnType == EQ_SPAWN_TYPE_PLAYER)
                            {
                                drawColorARGB = 0xFFFF0000; // red
                            }
                            else if (spawnType == EQ_SPAWN_TYPE_NPC)
                            {
                                drawColorARGB = 0xFF00FFFF; // cyan
                            }
                        }
                    }

                    float spellCastTimeCurrentFloat = (float)(spellCastTimeCurrent / 1000.0f);

                    float spellCastTimePercent = (float)((spellCastTimeCurrent * 100) / spellCastTimeTotal);

                    std::stringstream spellCastBarText;
                    spellCastBarText.precision(1);
                    spellCastBarText << "#" << spawnCastSpell->index << " " << spawnName
                        << " (" << spawnCastSpell->spellName << ") "
                        << std::fixed << spellCastTimeCurrentFloat;

                    float spawnCastSpellDrawBarsWidth = (100.0f * g_spawnCastSpellDrawBarsWidthMultiplier);

                    g_spawnCastSpellDrawBarsOffsetY = (float)(spawnCastSpell->index * (g_spawnCastSpellDrawBarsHeight + g_spawnCastSpellDrawBarsHeightOffset));

                    EQ_DrawColoredRectangle
                    (
                        (int)(g_spawnCastSpellDrawBarsX + g_spawnCastSpellDrawBarsOffsetX),
                        (int)(g_spawnCastSpellDrawBarsY + g_spawnCastSpellDrawBarsOffsetY),
                        (int)spawnCastSpellDrawBarsWidth,
                        (int)(g_spawnCastSpellDrawBarsHeight + g_spawnCastSpellDrawBarsHeightOffset),
                        EQ_TOOLTIP_COLOR
                    );

                    EQ_DrawText
                    (
                        spellCastBarText.str().c_str(),
                        (int)(g_spawnCastSpellDrawBarsX + g_spawnCastSpellDrawBarsOffsetX),
                        (int)(g_spawnCastSpellDrawBarsY + g_spawnCastSpellDrawBarsOffsetY),
                        drawColorARGB,
                        textSize
                    );

                    g_spawnCastSpellDrawBarsOffsetY += g_spawnCastSpellDrawBarsHeight;

                    EQ_DrawLine
                    (
                        g_spawnCastSpellDrawBarsX + g_spawnCastSpellDrawBarsOffsetX,
                        g_spawnCastSpellDrawBarsY + g_spawnCastSpellDrawBarsOffsetY,
                        0.0f,
                        g_spawnCastSpellDrawBarsX + g_spawnCastSpellDrawBarsOffsetX + (spellCastTimePercent * g_spawnCastSpellDrawBarsWidthMultiplier),
                        g_spawnCastSpellDrawBarsY + g_spawnCastSpellDrawBarsOffsetY,
                        0.0f,
                        drawColorARGB
                    );

                    g_spawnCastSpellDrawBarsOffsetY += g_spawnCastSpellDrawBarsHeightOffset;

                    g_spawnCastSpellDrawBarsCount++;
                }
            }
        }

        uint32_t spellCastTime = spawnCastSpell->spellCastTime;
        if (spellCastTime < g_spawnCastSpellTimerDelay)
        {
            spellCastTime = g_spawnCastSpellTimerDelay;
        }

        if ((currentTimer - spawnCastSpell->startTimer) > spellCastTime)
        {
            spawnCastSpellListIterator = g_spawnCastSpellList.erase(spawnCastSpellListIterator);
            spawnCastSpellListIterator--;
            continue;
        }
    }
}

void EQAPP_SpawnCastSpell_Add(uint32_t spawnInfo, uint32_t spellId, uint32_t spellCastTime)
{
    if (spawnInfo == NULL)
    {
        return;
    }

    std::string spellName = EQ_GetSpellNameById(spellId);
    if (spellName.size() == 0)
    {
        return;
    }

    uint32_t index = 0;

    for (auto& spawnCastSpell : g_spawnCastSpellList)
    {
        // increment index if it already exists in the list
        if (spawnCastSpell->index == index)
        {
            index++;
        }

        // update if spawn already exists in the list
        if (spawnCastSpell->spawnInfo == spawnInfo)
        {
            spawnCastSpell->spellName              = spellName;
            spawnCastSpell->spellId                = spellId;
            spawnCastSpell->spellCastTime          = spellCastTime;
            spawnCastSpell->spellCastTimeCountdown = spellCastTime;
            spawnCastSpell->startTimer             = EQ_GetTimer();
            return;
        }
    }

    // add to the list
    EQApp::SpawnCastSpell_sharedptr spawnCastSpell = std::make_shared<EQApp::SpawnCastSpell>();
    spawnCastSpell->index                  = index;
    spawnCastSpell->spawnInfo              = spawnInfo;
    spawnCastSpell->spellName              = spellName;
    spawnCastSpell->spellId                = spellId;
    spawnCastSpell->spellCastTime          = spellCastTime;
    spawnCastSpell->spellCastTimeCountdown = spellCastTime;
    spawnCastSpell->startTimer             = EQ_GetTimer();

    g_spawnCastSpellList.push_back(std::move(spawnCastSpell));
}

