#pragma once

namespace EQAlternateAbilities
{

namespace Shared
{
    const uint32_t Bind_Affinity         = 679;
    const uint32_t Gate                  = 1217;
    const uint32_t Tranquil_Blessings    = 992;
} // namespace Shared

// CLR DRU SHM
namespace Priest
{
    const uint32_t Mass_Group_Buff    = 35;
} // namespace Priest


// NEC WIZ MAG ENC
namespace Caster
{
    const uint32_t Mass_Group_Buff    = 264;
} // namespace Caster

namespace General
{
    const uint32_t Identify     = 346;
    const uint32_t Origin       = 331;
} // namespace General

namespace Special
{
    const uint32_t Armor_of_Experience                    = 2000;
    const uint32_t Banestrike                             = 15073;
    const uint32_t Chaotic_Jester                         = 483;
    const uint32_t Expedient_Recovery                     = 484;
    const uint32_t Glyph_of_Angry_Thoughts                = 5004;
    const uint32_t Glyph_of_Arcane_Secrets                = 587;
    const uint32_t Glyph_of_Courage                       = 5000;
    const uint32_t Glyph_of_Destruction_I                 = 4706;
    const uint32_t Glyph_of_Destruction_II                = 7019;
    const uint32_t Glyph_of_Draconic_Potential_I          = 4705;
    const uint32_t Glyph_of_Draconic_Potential_II         = 7018;
    const uint32_t Glyph_of_Dragon_Scales_I               = 4702;
    const uint32_t Glyph_of_Dragon_Scales_II              = 7016;
    const uint32_t Glyph_of_Fireworks_I                   = 586;
    const uint32_t Glyph_of_Fireworks_II                  = 897;
    const uint32_t Glyph_of_Stored_Life                   = 5002;
    const uint32_t Harmonic_Dissonance                    = 574;
    const uint32_t Infusion_of_the_Faithful               = 482;
    const uint32_t Intensity_of_the_Resolute              = 487;
    const uint32_t Lesson_of_the_Devoted                  = 481;
    const uint32_t Staunch_Recovery                       = 486;
    const uint32_t Steadfast_Servant                      = 485;
    const uint32_t Summon_Clockwork_Banker                = 8130;
    const uint32_t Summon_Permutation_Peddler             = 453;
    const uint32_t Summon_Personal_Tribute_Master         = 182;
    const uint32_t Summon_Resupply_Agent                  = 8081;
    const uint32_t Throne_of_Heroes                       = 511;
} // namespace Special

} // namespace EQAlternateAbilities

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_ALTERNATE_ABILITY_NAME =
{
    {EQAlternateAbilities::General::Identify,    "Identify"},
    {EQAlternateAbilities::General::Origin,      "Origin"},

    {EQAlternateAbilities::Shared::Bind_Affinity,         "Bind Affinity"},
    {EQAlternateAbilities::Shared::Gate,                  "Gate"},
    {EQAlternateAbilities::Shared::Tranquil_Blessings,    "Tranquil Blessings"},

    {EQAlternateAbilities::Special::Armor_of_Experience,                 "Armor of Experience"},
    {EQAlternateAbilities::Special::Banestrike,                          "Banestrike"},
    {EQAlternateAbilities::Special::Chaotic_Jester,                      "Chaotic Jester"},
    {EQAlternateAbilities::Special::Expedient_Recovery,                  "Expedient Recovery"},
    {EQAlternateAbilities::Special::Glyph_of_Angry_Thoughts,             "Glyph of Angry Thoughts"},
    {EQAlternateAbilities::Special::Glyph_of_Arcane_Secrets,             "Glyph of Arcane Secrets"},
    {EQAlternateAbilities::Special::Glyph_of_Courage,                    "Glyph of Courage"},
    {EQAlternateAbilities::Special::Glyph_of_Destruction_I,              "Glyph of Destruction I"},
    {EQAlternateAbilities::Special::Glyph_of_Destruction_II,             "Glyph of Destruction II"},
    {EQAlternateAbilities::Special::Glyph_of_Draconic_Potential_I,       "Glyph of Draconic Potential I"},
    {EQAlternateAbilities::Special::Glyph_of_Draconic_Potential_II,      "Glyph of Draconic Potential II"},
    {EQAlternateAbilities::Special::Glyph_of_Dragon_Scales_I,            "Glyph of Dragon Scales I"},
    {EQAlternateAbilities::Special::Glyph_of_Dragon_Scales_II,           "Glyph of Dragon Scales II"},
    {EQAlternateAbilities::Special::Glyph_of_Fireworks_I,                "Glyph of Fireworks I"},
    {EQAlternateAbilities::Special::Glyph_of_Fireworks_II,               "Glyph of Fireworks II"},
    {EQAlternateAbilities::Special::Glyph_of_Stored_Life,                "Glyph of Stored Life"},
    {EQAlternateAbilities::Special::Harmonic_Dissonance,                 "Harmonic Dissonance"},
    {EQAlternateAbilities::Special::Infusion_of_the_Faithful,            "Infusion of the Faithful"},
    {EQAlternateAbilities::Special::Intensity_of_the_Resolute,           "Intensity of the Resolute"},
    {EQAlternateAbilities::Special::Lesson_of_the_Devoted,               "Lesson of the Devoted"},
    {EQAlternateAbilities::Special::Staunch_Recovery,                    "Staunch Recovery"},
    {EQAlternateAbilities::Special::Steadfast_Servant,                   "Steadfast Servant"},
    {EQAlternateAbilities::Special::Summon_Clockwork_Banker,             "Summon Clockwork Banker"},
    {EQAlternateAbilities::Special::Summon_Permutation_Peddler,          "Summon Permutation Peddler"},
    {EQAlternateAbilities::Special::Summon_Personal_Tribute_Master,      "Summon Personal Tribute Master"},
    {EQAlternateAbilities::Special::Summon_Resupply_Agent,               "Summon Resupply Agent"},
    {EQAlternateAbilities::Special::Throne_of_Heroes,                    "Throne of Heroes"},
};
