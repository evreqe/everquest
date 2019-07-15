#pragma once

bool g_CheatAlwaysSeeInvisIsEnabled = true;
bool g_CheatAlwaysBreatheUnderwaterIsEnabled = true;
bool g_CheatNeverBlindIsEnabled = true;
bool g_CheatNeverEncumberedIsEnabled = true;
bool g_CheatNeverStunnedIsEnabled = true;
bool g_CheatNeverSlideIsEnabled = false;
bool g_CheatNoFallDamageIsEnabled = true;
bool g_CheatNoEnvironmentalDamageIsEnabled = true;
bool g_CheatLevitateIsEnabled = false;
bool g_CheatFlyIsEnabled = false;
bool g_CheatMemorizeSpellsInstantlyIsEnabled = true;
bool g_CheatScribeSpellsInstantlyIsEnabled = true;

void EQAPP_Cheat_AlwaysSeeInvis_Toggle();
void EQAPP_Cheat_AlwaysSeeInvis_On();
void EQAPP_Cheat_AlwaysSeeInvis_Off();

void EQAPP_Cheat_AlwaysBreatheUnderwater_Toggle();
void EQAPP_Cheat_AlwaysBreatheUnderwater_On();
void EQAPP_Cheat_AlwaysBreatheUnderwater_Off();

void EQAPP_Cheat_NeverBlind_Toggle();
void EQAPP_Cheat_NeverBlind_On();
void EQAPP_Cheat_NeverBlind_Off();

void EQAPP_Cheat_NeverEncumbered_Toggle();
void EQAPP_Cheat_NeverEncumbered_On();
void EQAPP_Cheat_NeverEncumbered_Off();

void EQAPP_Cheat_NeverStunned_Toggle();
void EQAPP_Cheat_NeverStunned_On();
void EQAPP_Cheat_NeverStunned_Off();

void EQAPP_Cheat_NoFallDamage_Toggle();
void EQAPP_Cheat_NoFallDamage_On();
void EQAPP_Cheat_NoFallDamage_Off();

void EQAPP_Cheat_NoEnvironmentalDamage_Toggle();
void EQAPP_Cheat_NoEnvironmentalDamage_On();
void EQAPP_Cheat_NoEnvironmentalDamage_Off();

void EQAPP_Cheat_Levitate_Toggle();
void EQAPP_Cheat_Levitate_On();
void EQAPP_Cheat_Levitate_Off();

void EQAPP_Cheat_Fly_Toggle();
void EQAPP_Cheat_Fly_On();
void EQAPP_Cheat_Fly_Off();

void EQAPP_Cheat_MemorizeSpellsInstantly_Toggle();
void EQAPP_Cheat_MemorizeSpellsInstantly_On();
void EQAPP_Cheat_MemorizeSpellsInstantly_Off();

void EQAPP_Cheat_ScribeSpellsInstantly_Toggle();
void EQAPP_Cheat_ScribeSpellsInstantly_On();
void EQAPP_Cheat_ScribeSpellsInstantly_Off();

void EQAPP_Cheat_AlwaysSeeInvis_Toggle()
{
    EQ_ToggleBool(g_CheatAlwaysSeeInvisIsEnabled);
    EQAPP_PrintBool("Always See Invis", g_CheatAlwaysSeeInvisIsEnabled);
}

void EQAPP_Cheat_AlwaysSeeInvis_On()
{
    if (g_CheatAlwaysSeeInvisIsEnabled == false)
    {
        EQAPP_Cheat_AlwaysSeeInvis_Toggle();
    }
}

void EQAPP_Cheat_AlwaysSeeInvis_Off()
{
    if (g_CheatAlwaysSeeInvisIsEnabled == true)
    {
        EQAPP_Cheat_AlwaysSeeInvis_Toggle();
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
    EQ_ToggleBool(g_CheatLevitateIsEnabled);
    EQAPP_PrintBool("Levitate", g_CheatLevitateIsEnabled);
}

void EQAPP_Cheat_Levitate_On()
{
    EQAPP_Cheat_Fly_Off();

    if (g_CheatLevitateIsEnabled == false)
    {
        EQAPP_Cheat_Levitate_Toggle();
    }

    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_LEVITATING);
}

void EQAPP_Cheat_Levitate_Off()
{
    if (g_CheatLevitateIsEnabled == true)
    {
        EQAPP_Cheat_Levitate_Toggle();
    }

    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_SINKING_TO_GROUND);
}

void EQAPP_Cheat_Fly_Toggle()
{
    EQ_ToggleBool(g_CheatFlyIsEnabled);
    EQAPP_PrintBool("Fly", g_CheatFlyIsEnabled);
}

void EQAPP_Cheat_Fly_On()
{
    EQAPP_Cheat_Levitate_Off();

    if (g_CheatFlyIsEnabled == false)
    {
        EQAPP_Cheat_Fly_Toggle();
    }

    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_FLYING);
}

void EQAPP_Cheat_Fly_Off()
{
    if (g_CheatFlyIsEnabled == true)
    {
        EQAPP_Cheat_Fly_Toggle();
    }

    EQ_SetPlayerSpawnGravityType(EQ_GRAVITY_TYPE_SINKING_TO_GROUND);
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
