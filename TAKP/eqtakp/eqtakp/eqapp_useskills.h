#pragma once

bool g_UseSkillsIsEnabled = true;

bool g_UseSkillsSenseHeadingIsEnabled = false;
bool g_UseSkillsForageIsEnabled = false;
bool g_UseSkillsTauntIsEnabled = false;
bool g_UseSkillsKickIsEnabled = false;
bool g_UseSkillsBashIsEnabled = false;
bool g_UseSkillsSlamIsEnabled = false;
bool g_UseSkillsDisarmIsEnabled = false;
bool g_UseSkillsBackstabIsEnabled = false;
bool g_UseSkillsRoundKickIsEnabled = false;
bool g_UseSkillsFeignDeathIsEnabled = false;
bool g_UseSkillsMendIsEnabled = false;

uint32_t g_UseSkillsTimer = 0;
uint32_t g_UseSkillsTimerDelay = 1000;

float g_UseSkillsBackstabDistanceMaximum = 10.0f;

void EQAPP_UseSkills_Toggle();
void EQAPP_UseSkills_SenseHeading_Toggle();
void EQAPP_UseSkills_Forage_Toggle();
void EQAPP_UseSkills_Taunt_Toggle();
void EQAPP_UseSkills_Kick_Toggle();
void EQAPP_UseSkills_Bash_Toggle();
void EQAPP_UseSkills_Slam_Toggle();
void EQAPP_UseSkills_Disarm_Toggle();
void EQAPP_UseSkills_Backstab_Toggle();
void EQAPP_UseSkills_RoundKick_Toggle();
void EQAPP_UseSkills_FeignDeath_Toggle();
void EQAPP_UseSkills_Mend_Toggle();
void EQAPP_UseSkills_Load();
void EQAPP_UseSkills_Execute();

void EQAPP_UseSkills_Toggle()
{
    EQ_ToggleBool(g_UseSkillsIsEnabled);
    EQAPP_PrintBool("Use Skills", g_UseSkillsIsEnabled);
}

void EQAPP_UseSkills_SenseHeading_Toggle()
{
    EQ_ToggleBool(g_UseSkillsSenseHeadingIsEnabled);
    EQAPP_PrintBool("Use Skills (Sense Heading)", g_UseSkillsSenseHeadingIsEnabled);
}

void EQAPP_UseSkills_Forage_Toggle()
{
    EQ_ToggleBool(g_UseSkillsForageIsEnabled);
    EQAPP_PrintBool("Use Skills (Forage)", g_UseSkillsForageIsEnabled);
}

void EQAPP_UseSkills_Taunt_Toggle()
{
    EQ_ToggleBool(g_UseSkillsTauntIsEnabled);
    EQAPP_PrintBool("Use Skills (Taunt)", g_UseSkillsTauntIsEnabled);
}

void EQAPP_UseSkills_Kick_Toggle()
{
    EQ_ToggleBool(g_UseSkillsKickIsEnabled);
    EQAPP_PrintBool("Use Skills (Kick)", g_UseSkillsKickIsEnabled);

    if (g_UseSkillsKickIsEnabled == true)
    {
        g_UseSkillsBashIsEnabled = false;
        g_UseSkillsSlamIsEnabled = false;
    }
}

void EQAPP_UseSkills_Bash_Toggle()
{
    EQ_ToggleBool(g_UseSkillsBashIsEnabled);
    EQAPP_PrintBool("Use Skills (Bash)", g_UseSkillsBashIsEnabled);

    if (g_UseSkillsBashIsEnabled == true)
    {
        g_UseSkillsKickIsEnabled = false;
        g_UseSkillsSlamIsEnabled = false;
    }
}

void EQAPP_UseSkills_Slam_Toggle()
{
    EQ_ToggleBool(g_UseSkillsSlamIsEnabled);
    EQAPP_PrintBool("Use Skills (Slam)", g_UseSkillsSlamIsEnabled);

    if (g_UseSkillsSlamIsEnabled == true)
    {
        g_UseSkillsKickIsEnabled = false;
        g_UseSkillsBashIsEnabled = false;
    }
}

void EQAPP_UseSkills_Disarm_Toggle()
{
    EQ_ToggleBool(g_UseSkillsDisarmIsEnabled);
    EQAPP_PrintBool("Use Skills (Disarm): ", g_UseSkillsDisarmIsEnabled);
}

void EQAPP_UseSkills_Backstab_Toggle()
{
    EQ_ToggleBool(g_UseSkillsBackstabIsEnabled);
    EQAPP_PrintBool("Use Skills (Backstab): ", g_UseSkillsBackstabIsEnabled);
}

void EQAPP_UseSkills_RoundKick_Toggle()
{
    EQ_ToggleBool(g_UseSkillsRoundKickIsEnabled);
    EQAPP_PrintBool("Use Skills (Round Kick): ", g_UseSkillsRoundKickIsEnabled);
}

void EQAPP_UseSkills_FeignDeath_Toggle()
{
    EQ_ToggleBool(g_UseSkillsFeignDeathIsEnabled);
    EQAPP_PrintBool("Use Skills (Feign Death): ", g_UseSkillsFeignDeathIsEnabled);
}

void EQAPP_UseSkills_Mend_Toggle()
{
    EQ_ToggleBool(g_UseSkillsMendIsEnabled);
    EQAPP_PrintBool("Use Skills (Mend): ", g_UseSkillsMendIsEnabled);
}

void EQAPP_UseSkills_Load()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    g_UseSkillsSenseHeadingIsEnabled = false;
    g_UseSkillsForageIsEnabled = false;
    g_UseSkillsTauntIsEnabled = false;
    g_UseSkillsKickIsEnabled = false;
    g_UseSkillsBashIsEnabled = false;
    g_UseSkillsSlamIsEnabled = false;
    g_UseSkillsDisarmIsEnabled = false;
    g_UseSkillsBackstabIsEnabled = false;
    g_UseSkillsRoundKickIsEnabled = false;
    g_UseSkillsFeignDeathIsEnabled = false;
    g_UseSkillsMendIsEnabled = false;

    if (EQ_CanClassUseTauntSkill(playerSpawn->Class) == true)
    {
        g_UseSkillsTauntIsEnabled = true;
    }

    if (playerSpawn->Class == EQ_CLASS_WARRIOR)
    {
        g_UseSkillsKickIsEnabled = true;
        g_UseSkillsBashIsEnabled = false;
        g_UseSkillsSlamIsEnabled = false;
    }

    if
    (
        playerSpawn->Class == EQ_CLASS_SHADOWKNIGHT ||
        playerSpawn->Class == EQ_CLASS_PALADIN      ||
        playerSpawn->Class == EQ_CLASS_CLERIC       ||
        playerSpawn->Class == EQ_CLASS_SHAMAN
    )
    {
        if (EQ_CanRaceUseSlamSkill(playerSpawn->Race) == true)
        {
            g_UseSkillsKickIsEnabled = false;
            g_UseSkillsBashIsEnabled = false;
            g_UseSkillsSlamIsEnabled = true;
        }
        else
        {
            g_UseSkillsKickIsEnabled = false;
            g_UseSkillsBashIsEnabled = true;
            g_UseSkillsSlamIsEnabled = false;
        }
    }

    if (playerSpawn->Class == EQ_CLASS_ROGUE)
    {
        g_UseSkillsBackstabIsEnabled = true;
    }

    if (playerSpawn->Class == EQ_CLASS_MONK)
    {
        g_UseSkillsRoundKickIsEnabled = true;
        g_UseSkillsKickIsEnabled = false;
        g_UseSkillsBashIsEnabled = false;
        g_UseSkillsSlamIsEnabled = false;
    }
}

void EQAPP_UseSkills_Execute()
{
    if (EQ_HasTimePassed(g_UseSkillsTimer, g_UseSkillsTimerDelay) == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    if (g_UseSkillsSenseHeadingIsEnabled == true)
    {
        EQ_UseSkill(EQ_SKILL_SENSE_HEADING, NULL);
    }

    if (g_UseSkillsForageIsEnabled == true)
    {
        if (EQ_IsAutoAttackEnabled() == false && playerSpawn->StandingState == EQ_STANDING_STATE_STANDING)
        {
            EQ_UseSkill(EQ_SKILL_FORAGE, NULL);

            EQAPP_AutoInventory_Execute();
        }
    }

    if (EQ_IsAutoAttackEnabled() == true)
    {
        auto targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn != NULL && targetSpawn != playerSpawn)
        {
            float targetSpawnDistance = EQ_CalculateDistance(playerSpawn->X, playerSpawn->Y, targetSpawn->X, targetSpawn->Y);

            float targetSpawnMeleeDistance = EQ_FUNCTION_get_melee_range((EQClass::EQPlayer*)playerSpawn, (EQClass::EQPlayer*)targetSpawn);

            if (targetSpawnDistance <= targetSpawnMeleeDistance)
            {
                if (g_UseSkillsKickIsEnabled == true)
                {
                    EQ_UseSkill(EQ_SKILL_KICK, (EQClass::EQPlayer*)targetSpawn);
                }

                if (g_UseSkillsBashIsEnabled == true)
                {
                    EQ_UseSkill(EQ_SKILL_BASH, (EQClass::EQPlayer*)targetSpawn);
                }

                if (g_UseSkillsDisarmIsEnabled == true)
                {
                    EQ_UseSkill(EQ_SKILL_DISARM, (EQClass::EQPlayer*)targetSpawn);
                }

                if (EQ_CanClassUseTauntSkill(playerSpawn->Class) == true)
                {
                    if (g_UseSkillsTauntIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_TAUNT, (EQClass::EQPlayer*)targetSpawn);
                    }
                }

                if (EQ_CanRaceUseSlamSkill(playerSpawn->Race) == true)
                {
                    if (g_UseSkillsSlamIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_SLAM, (EQClass::EQPlayer*)targetSpawn);
                    }
                }

                if (playerSpawn->Class == EQ_CLASS_ROGUE)
                {
                    if (g_UseSkillsBackstabIsEnabled == true)
                    {
                        if (targetSpawnDistance <= g_UseSkillsBackstabDistanceMaximum)
                        {
                            if (EQ_IsSpawnBehindSpawn(playerSpawn, targetSpawn) == true)
                            {
                                EQ_UseSkill(EQ_SKILL_BACKSTAB, (EQClass::EQPlayer*)targetSpawn);
                            }
                        }
                    }
                }

                if (playerSpawn->Class == EQ_CLASS_MONK)
                {
                    if (g_UseSkillsRoundKickIsEnabled == true)
                    {
                        EQ_UseSkill(EQ_SKILL_ROUND_KICK, (EQClass::EQPlayer*)targetSpawn);
                    }
                }
            }
        }
    }

    if (g_UseSkillsFeignDeathIsEnabled == true)
    {
        if (playerSpawn->Class == EQ_CLASS_MONK)
        {
            EQ_UseSkill(EQ_SKILL_FEIGN_DEATH, NULL);
        }
    }

    if (EQ_IsAutoAttackEnabled() == false)
    {
        if (g_UseSkillsMendIsEnabled == true)
        {
            if (playerSpawn->Class == EQ_CLASS_MONK)
            {
                auto hpCurrent = playerSpawn->HPCurrent;
                auto hpMax = playerSpawn->HPMax;

                if (hpCurrent == hpMax)
                {
                    EQ_UseSkill(EQ_SKILL_MEND, NULL);
                }
            }
        }
    }
}

