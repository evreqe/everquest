#pragma once

bool g_CheatAlwaysSeeInvisibleIsEnabled = true;
bool g_CheatAlwaysBreatheUnderwaterIsEnabled = true;
bool g_CheatAlwaysHaveUltravisionIsEnabled = true;
bool g_CheatAlwaysRunFastIsEnabled = false;
bool g_CheatNeverBlindIsEnabled = true;
bool g_CheatNeverEncumberedIsEnabled = true;
bool g_CheatNeverStunnedIsEnabled = true;
bool g_CheatNeverRootedIsEnabled = true;
bool g_CheatNeverSnaredIsEnabled = true;
bool g_CheatNeverSlideIsEnabled = false;
bool g_CheatNoFallDamageIsEnabled = true;
bool g_CheatNoEnvironmentalDamageIsEnabled = true;
bool g_CheatLevitateIsEnabled = false;
bool g_CheatFlyIsEnabled = false;
bool g_CheatMemorizeSpellsInstantlyIsEnabled = true;
bool g_CheatScribeSpellsInstantlyIsEnabled = true;
bool g_CheatWallHackIsEnabled = false;

void EQAPP_Cheat_AlwaysSeeInvisible_Toggle();
void EQAPP_Cheat_AlwaysSeeInvisible_On();
void EQAPP_Cheat_AlwaysSeeInvisible_Off();

void EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle();
void EQAPP_Cheat_AlwaysBreatheUnderwater_On();
void EQAPP_Cheat_AlwaysBreatheUnderwater_Off();

void EQAPP_Cheat_AlwaysHaveUltravision_Toggle();
void EQAPP_Cheat_AlwaysHaveUltravision_On();
void EQAPP_Cheat_AlwaysHaveUltravision_Off();

void EQAPP_Cheat_AlwaysRunFast_Toggle();
void EQAPP_Cheat_AlwaysRunFast_On();
void EQAPP_Cheat_AlwaysRunFast_Off();

void EQAPP_Cheat_NeverBlind_Toggle();
void EQAPP_Cheat_NeverBlind_On();
void EQAPP_Cheat_NeverBlind_Off();

void EQAPP_Cheat_NeverEncumbered_Toggle();
void EQAPP_Cheat_NeverEncumbered_On();
void EQAPP_Cheat_NeverEncumbered_Off();

void EQAPP_Cheat_NeverStunned_Toggle();
void EQAPP_Cheat_NeverStunned_On();
void EQAPP_Cheat_NeverStunned_Off();

void EQAPP_Cheat_NeverRooted_Toggle();
void EQAPP_Cheat_NeverRooted_On();
void EQAPP_Cheat_NeverRooted_Off();

void EQAPP_Cheat_NeverSnared_Toggle();
void EQAPP_Cheat_NeverSnared_On();
void EQAPP_Cheat_NeverSnared_Off();

void EQAPP_Cheat_NoFallDamage_Toggle();
void EQAPP_Cheat_NoFallDamage_On();
void EQAPP_Cheat_NoFallDamage_Off();

void EQAPP_Cheat_NoEnvironmentalDamage_Toggle();
void EQAPP_Cheat_NoEnvironmentalDamage_On();
void EQAPP_Cheat_NoEnvironmentalDamage_Off();

void EQAPP_Cheat_Levitate_Toggle();
void EQAPP_Cheat_Levitate_On();
void EQAPP_Cheat_Levitate_Off();
void EQAPP_Cheat_Levitate_Execute();

void EQAPP_Cheat_Fly_Toggle();
void EQAPP_Cheat_Fly_On();
void EQAPP_Cheat_Fly_Off();
void EQAPP_Cheat_Fly_Execute();

void EQAPP_Cheat_MemorizeSpellsInstantly_Toggle();
void EQAPP_Cheat_MemorizeSpellsInstantly_On();
void EQAPP_Cheat_MemorizeSpellsInstantly_Off();
bool EQAPP_Cheat_MemorizeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellMemTicksLeft(void* this_ptr);

void EQAPP_Cheat_ScribeSpellsInstantly_Toggle();
void EQAPP_Cheat_ScribeSpellsInstantly_On();
void EQAPP_Cheat_ScribeSpellsInstantly_Off();
bool EQAPP_Cheat_ScribeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellScribeTicksLeft(void* this_ptr);

void EQAPP_Cheat_WallHack_Toggle();
void EQAPP_Cheat_WallHack_On();
void EQAPP_Cheat_WallHack_Off();

void EQAPP_Cheat_AlwaysSeeInvisible_Toggle()
{
    EQ_ToggleBool(g_CheatAlwaysSeeInvisibleIsEnabled);
    EQAPP_PrintBool("Always See Invisible", g_CheatAlwaysSeeInvisibleIsEnabled);
}

void EQAPP_Cheat_AlwaysSeeInvisible_On()
{
    if (g_CheatAlwaysSeeInvisibleIsEnabled == false)
    {
        EQAPP_Cheat_AlwaysSeeInvisible_Toggle();
    }
}

void EQAPP_Cheat_AlwaysSeeInvisible_Off()
{
    if (g_CheatAlwaysSeeInvisibleIsEnabled == true)
    {
        EQAPP_Cheat_AlwaysSeeInvisible_Toggle();
    }
}

void EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle()
{
    EQ_ToggleBool(g_CheatAlwaysBreatheUnderwaterIsEnabled);
    EQAPP_PrintBool("Always Breathe Underwater", g_CheatAlwaysBreatheUnderwaterIsEnabled);
}

void EQAPP_Cheat_AlwaysBreatheUnderwater_On()
{
    if (g_CheatAlwaysBreatheUnderwaterIsEnabled == false)
    {
        EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle();
    }
}

void EQAPP_Cheat_AlwaysBreatheUnderwater_Off()
{
    if (g_CheatAlwaysBreatheUnderwaterIsEnabled == true)
    {
        EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle();
    }
}

void EQAPP_Cheat_AlwaysHaveUltravision_Toggle()
{
    EQ_ToggleBool(g_CheatAlwaysHaveUltravisionIsEnabled);
    EQAPP_PrintBool("Always Have Ultravision", g_CheatAlwaysHaveUltravisionIsEnabled);
}

void EQAPP_Cheat_AlwaysHaveUltravision_On()
{
    if (g_CheatAlwaysHaveUltravisionIsEnabled == false)
    {
        EQAPP_Cheat_AlwaysHaveUltravision_Toggle();
    }
}

void EQAPP_Cheat_AlwaysHaveUltravision_Off()
{
    if (g_CheatAlwaysHaveUltravisionIsEnabled == true)
    {
        EQAPP_Cheat_AlwaysHaveUltravision_Toggle();
    }
}

void EQAPP_Cheat_AlwaysRunFast_Toggle()
{
    EQ_ToggleBool(g_CheatAlwaysRunFastIsEnabled);
    EQAPP_PrintBool("Always Run Fast", g_CheatAlwaysRunFastIsEnabled);
}

void EQAPP_Cheat_AlwaysRunFast_On()
{
    if (g_CheatAlwaysRunFastIsEnabled == false)
    {
        EQAPP_Cheat_AlwaysRunFast_Toggle();
    }
}

void EQAPP_Cheat_AlwaysRunFast_Off()
{
    if (g_CheatAlwaysRunFastIsEnabled == true)
    {
        EQAPP_Cheat_AlwaysRunFast_Toggle();
    }
}

void EQAPP_Cheat_NeverBlind_Toggle()
{
    EQ_ToggleBool(g_CheatNeverBlindIsEnabled);
    EQAPP_PrintBool("Never Blind", g_CheatNeverBlindIsEnabled);
}

void EQAPP_Cheat_NeverBlind_On()
{
    if (g_CheatNeverBlindIsEnabled == false)
    {
        EQAPP_Cheat_NeverBlind_Toggle();
    }
}

void EQAPP_Cheat_NeverBlind_Off()
{
    if (g_CheatNeverBlindIsEnabled == true)
    {
        EQAPP_Cheat_NeverBlind_Toggle();
    }
}

void EQAPP_Cheat_NeverEncumbered_Toggle()
{
    EQ_ToggleBool(g_CheatNeverEncumberedIsEnabled);
    EQAPP_PrintBool("Never Encumbered", g_CheatNeverEncumberedIsEnabled);
}

void EQAPP_Cheat_NeverEncumbered_On()
{
    if (g_CheatNeverEncumberedIsEnabled == false)
    {
        EQAPP_Cheat_NeverEncumbered_Toggle();
    }
}

void EQAPP_Cheat_NeverEncumbered_Off()
{
    if (g_CheatNeverEncumberedIsEnabled == true)
    {
        EQAPP_Cheat_NeverEncumbered_Toggle();
    }
}

void EQAPP_Cheat_NeverStunned_Toggle()
{
    EQ_ToggleBool(g_CheatNeverStunnedIsEnabled);
    EQAPP_PrintBool("Never Stunned", g_CheatNeverStunnedIsEnabled);
}

void EQAPP_Cheat_NeverStunned_On()
{
    if (g_CheatNeverStunnedIsEnabled == false)
    {
        EQAPP_Cheat_NeverStunned_Toggle();
    }
}

void EQAPP_Cheat_NeverStunned_Off()
{
    if (g_CheatNeverStunnedIsEnabled == true)
    {
        EQAPP_Cheat_NeverStunned_Toggle();
    }
}

void EQAPP_Cheat_NeverRooted_Toggle()
{
    EQ_ToggleBool(g_CheatNeverRootedIsEnabled);
    EQAPP_PrintBool("Never Rooted", g_CheatNeverRootedIsEnabled);
}

void EQAPP_Cheat_NeverRooted_On()
{
    if (g_CheatNeverRootedIsEnabled == false)
    {
        EQAPP_Cheat_NeverRooted_Toggle();
    }
}

void EQAPP_Cheat_NeverRooted_Off()
{
    if (g_CheatNeverRootedIsEnabled == true)
    {
        EQAPP_Cheat_NeverRooted_Toggle();
    }
}

void EQAPP_Cheat_NeverSnared_Toggle()
{
    EQ_ToggleBool(g_CheatNeverSnaredIsEnabled);
    EQAPP_PrintBool("Never Snared", g_CheatNeverSnaredIsEnabled);
}

void EQAPP_Cheat_NeverSnared_On()
{
    if (g_CheatNeverSnaredIsEnabled == false)
    {
        EQAPP_Cheat_NeverSnared_Toggle();
    }
}

void EQAPP_Cheat_NeverSnared_Off()
{
    if (g_CheatNeverSnaredIsEnabled == true)
    {
        EQAPP_Cheat_NeverSnared_Toggle();
    }
}

void EQAPP_Cheat_NeverSlide_Toggle()
{
    EQ_ToggleBool(g_CheatNeverSlideIsEnabled);
    EQAPP_PrintBool("Never Slide (ice, slime or slippery surfaces)", g_CheatNeverSlideIsEnabled);

    EQ_SetPlayerSpawnFrictionToDefault();
}

void EQAPP_Cheat_NeverSlide_On()
{
    if (g_CheatNeverSlideIsEnabled == false)
    {
        EQAPP_Cheat_NeverSlide_Toggle();
    }
}

void EQAPP_Cheat_NeverSlide_Off()
{
    if (g_CheatNeverSlideIsEnabled == true)
    {
        EQAPP_Cheat_NeverSlide_Toggle();
    }
}

void EQAPP_Cheat_NoFallDamage_Toggle()
{
    EQ_ToggleBool(g_CheatNoFallDamageIsEnabled);
    EQAPP_PrintBool("No Fall Damage", g_CheatNoFallDamageIsEnabled);
}

void EQAPP_Cheat_NoFallDamage_On()
{
    if (g_CheatNoFallDamageIsEnabled == false)
    {
        EQAPP_Cheat_NoFallDamage_Toggle();
    }
}

void EQAPP_Cheat_NoFallDamage_Off()
{
    if (g_CheatNoFallDamageIsEnabled == true)
    {
        EQAPP_Cheat_NoFallDamage_Toggle();
    }
}

void EQAPP_Cheat_NoEnvironmentalDamage_Toggle()
{
    EQ_ToggleBool(g_CheatNoEnvironmentalDamageIsEnabled);
    EQAPP_PrintBool("No Environmental Damage", g_CheatNoEnvironmentalDamageIsEnabled);
}

void EQAPP_Cheat_NoEnvironmentalDamage_On()
{
    if (g_CheatNoEnvironmentalDamageIsEnabled == false)
    {
        EQAPP_Cheat_NoEnvironmentalDamage_Toggle();
    }
}

void EQAPP_Cheat_NoEnvironmentalDamage_Off()
{
    if (g_CheatNoEnvironmentalDamageIsEnabled == true)
    {
        EQAPP_Cheat_NoEnvironmentalDamage_Toggle();
    }
}

void EQAPP_Cheat_Levitate_Toggle()
{
    EQAPP_Cheat_Fly_Off();

    EQ_ToggleBool(g_CheatLevitateIsEnabled);
    EQAPP_PrintBool("Levitate", g_CheatLevitateIsEnabled);

    if (g_CheatLevitateIsEnabled == true)
    {
        EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_LEVITATING);
    }
    else
    {
        EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_GROUND);
    }
}

void EQAPP_Cheat_Levitate_On()
{
    if (g_CheatLevitateIsEnabled == false)
    {
        EQAPP_Cheat_Levitate_Toggle();
    }
}

void EQAPP_Cheat_Levitate_Off()
{
    if (g_CheatLevitateIsEnabled == true)
    {
        EQAPP_Cheat_Levitate_Toggle();
    }
}

void EQAPP_Cheat_Levitate_Execute()
{
    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_LEVITATING);
}

void EQAPP_Cheat_Fly_Toggle()
{
    EQAPP_Cheat_Levitate_Off();

    EQ_ToggleBool(g_CheatFlyIsEnabled);
    EQAPP_PrintBool("Fly", g_CheatFlyIsEnabled);

    if (g_CheatFlyIsEnabled == true)
    {
        EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_FLYING);
    }
    else
    {
        EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_GROUND);
    }
}

void EQAPP_Cheat_Fly_On()
{
    if (g_CheatFlyIsEnabled == false)
    {
        EQAPP_Cheat_Fly_Toggle();
    }
}

void EQAPP_Cheat_Fly_Off()
{
    if (g_CheatFlyIsEnabled == true)
    {
        EQAPP_Cheat_Fly_Toggle();
    }
}

void EQAPP_Cheat_Fly_Execute()
{
    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_FLYING);
}

void EQAPP_Cheat_MemorizeSpellsInstantly_Toggle()
{
    EQ_ToggleBool(g_CheatMemorizeSpellsInstantlyIsEnabled);
    EQAPP_PrintBool("Memorize Spells Instantly", g_CheatMemorizeSpellsInstantlyIsEnabled);
}

void EQAPP_Cheat_MemorizeSpellsInstantly_On()
{
    if (g_CheatMemorizeSpellsInstantlyIsEnabled == false)
    {
        EQAPP_Cheat_MemorizeSpellsInstantly_Toggle();
    }
}

void EQAPP_Cheat_MemorizeSpellsInstantly_Off()
{
    if (g_CheatMemorizeSpellsInstantlyIsEnabled == true)
    {
        EQAPP_Cheat_MemorizeSpellsInstantly_Toggle();
    }
}

bool EQAPP_Cheat_MemorizeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellMemTicksLeft(void* this_ptr)
{
    // memorize spells instantly
    auto spellBookWindow = (uint32_t)this_ptr;    // EQ_GetSpellBookWindow();
    if (spellBookWindow != NULL)
    {
        auto timer = EQ_GetTimer();

        EQ_WriteMemory<signed int>(spellBookWindow + EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_START_TIMER, timer);
        EQ_WriteMemory<signed int>(spellBookWindow + EQ_OFFSET_CSpellBookWnd_MEMORIZE_SPELL_TIMER, timer);
    }

    return false;
}

void EQAPP_Cheat_ScribeSpellsInstantly_Toggle()
{
    EQ_ToggleBool(g_CheatScribeSpellsInstantlyIsEnabled);
    EQAPP_PrintBool("Scribe Spells Instantly", g_CheatScribeSpellsInstantlyIsEnabled);
}

void EQAPP_Cheat_ScribeSpellsInstantly_On()
{
    if (g_CheatScribeSpellsInstantlyIsEnabled == false)
    {
        EQAPP_Cheat_ScribeSpellsInstantly_Toggle();
    }
}

void EQAPP_Cheat_ScribeSpellsInstantly_Off()
{
    if (g_CheatScribeSpellsInstantlyIsEnabled == true)
    {
        EQAPP_Cheat_ScribeSpellsInstantly_Toggle();
    }
}

bool EQAPP_Cheat_ScribeSpellsInstantly_HandleEvent_CSpellBookWnd__GetSpellScribeTicksLeft(void* this_ptr)
{
    // scribe spells instantly
    auto spellBookWindow = (uint32_t)this_ptr;    // EQ_GetSpellBookWindow();
    if (spellBookWindow != NULL)
    {
        EQ_WriteMemory<uint32_t>(spellBookWindow + EQ_OFFSET_CSpellBookWnd_SCRIBE_SPELL_TIMER, 0);
    }

    return false;
}

void EQAPP_Cheat_WallHack_Toggle()
{
    EQ_ToggleBool(g_CheatWallHackIsEnabled);
    EQAPP_PrintBool("Wall Hack", g_CheatWallHackIsEnabled);
}

void EQAPP_Cheat_WallHack_On()
{
    if (g_CheatWallHackIsEnabled == false)
    {
        EQAPP_Cheat_WallHack_Toggle();
    }
}

void EQAPP_Cheat_WallHack_Off()
{
    if (g_CheatWallHackIsEnabled == true)
    {
        EQAPP_Cheat_WallHack_Toggle();
    }
}
