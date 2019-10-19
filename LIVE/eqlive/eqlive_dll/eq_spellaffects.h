#pragma once

#define EQ_SPELL_AFFECT_MOVEMENT_RATE                       3      // sow / snared
#define EQ_SPELL_AFFECT_HASTE                               11     // melee attack speed
#define EQ_SPELL_AFFECT_INVISIBILITY                        12
#define EQ_SPELL_AFFECT_SEE_INVISIBLE                       13
#define EQ_SPELL_AFFECT_ENDURING_BREATH                     14     // breathe underwater
#define EQ_SPELL_AFFECT_BLIND                               20
#define EQ_SPELL_AFFECT_STUN                                21
#define EQ_SPELL_AFFECT_CHARM                               22
#define EQ_SPELL_AFFECT_FEAR                                23
#define EQ_SPELL_AFFECT_FATIGUE                             24
#define EQ_SPELL_AFFECT_INVIS_VS_UNDEAD                     28
#define EQ_SPELL_AFFECT_INVIS_VS_ANIMALS                    29
#define EQ_SPELL_AFFECT_ENTHRALL                            31     // mez
#define EQ_SPELL_AFFECT_DISEASE                             35
#define EQ_SPELL_AFFECT_POISON                              36
#define EQ_SPELL_AFFECT_INVULNERABILITY                     40
#define EQ_SPELL_AFFECT_LEVITATION                          57
#define EQ_SPELL_AFFECT_CHANGE_FORM                         58     // illusion
#define EQ_SPELL_AFFECT_SPIN_STUN                           64
#define EQ_SPELL_AFFECT_INFRAVISION                         65
#define EQ_SPELL_AFFECT_ULTRAVISION                         66
#define EQ_SPELL_AFFECT_FIELD_OF_VIEW                       87
#define EQ_SPELL_AFFECT_HEIGHT                              89
#define EQ_SPELL_AFFECT_SILENCE                             96
#define EQ_SPELL_AFFECT_ROOT                                99
#define EQ_SPELL_AFFECT_SUMMON_MOUNT                        113    // horse
#define EQ_SPELL_AFFECT_HUNGER_AND_THIRST                   115
#define EQ_SPELL_AFFECT_CURSE                               116
#define EQ_SPELL_AFFECT_FEARLESS                            181
#define EQ_SPELL_AFFECT_ILLUSION_OTHER                      202
#define EQ_SPELL_AFFECT_MASS_BUFF                           203
#define EQ_SPELL_AFFECT_REDUCE_WEIGHT                       221
#define EQ_SPELL_AFFECT_METABOLISM                          233
#define EQ_SPELL_AFFECT_PERMANENT_ILLUSION                  238
#define EQ_SPELL_AFFECT_LUNG_CAPACITY                       246
#define EQ_SPELL_AFFECT_NO_FIZZLE                           265
#define EQ_SPELL_AFFECT_INCREASED_MOVEMENT_CAP              290
#define EQ_SPELL_AFFECT_HEIGHT_SMALL                        298
#define EQ_SPELL_AFFECT_IMPROVED_INVISIBILITY               314
#define EQ_SPELL_AFFECT_IMPROVED_INVIS_VS_UNDEAD            315
#define EQ_SPELL_AFFECT_IMPROVED_INVIS_VS_ANIMALS           316
#define EQ_SPELL_AFFECT_SPELL_SLOTS                         326
#define EQ_SPELL_AFFECT_BUFF_SLOTS                          327
#define EQ_SPELL_AFFECT_BANDOLIER_SLOTS                     363
#define EQ_SPELL_AFFECT_SLOW                                371
#define EQ_SPELL_AFFECT_GRAVITATE                           424
#define EQ_SPELL_AFFECT_FLY                                 425
#define EQ_SPELL_AFFECT_ADD_EXTENDED_TARGET_SLOTS           426
#define EQ_SPELL_AFFECT_ADD_MERCENARY_SLOTS                 445
#define EQ_SPELL_AFFECT_FEAR_STUN                           502

std::vector<std::string> EQ_SPELL_AFFECT_Strings =
{
    {"HP"},
    {"AC"},
    {"Attack Power"},
    {"Movement Rate"},
    {"STR"},
    {"DEX"},
    {"AGI"},
    {"STA"},
    {"INT"},
    {"WIS"},
    {"CHA"},
    {"Melee Speed"},
    {"Invisibility"},
    {"See Invis"},
    {"Enduring Breath"},
    {"Mana"},
    {"NPC-Frenzy"},
    {"NPC-Awareness"},
    {"NPC Aggro"},
    {"NPC Faction"},
    {"Blindness"},
    {"Stun"},
    {"Charm"},
    {"Fear"},
    {"Fatigue"},
    {"Bind Affinity"},
    {"Gate"},
    {"Dispel Magic"},
    {"Invis Vs Undead"},
    {"Invis Vs Animals"},
    {"NPC-ReactRange"},
    {"Enthrall (Mez)"},
    {"Create Item"},
    {"Spawn NPC"},
    {"Confuse"},
    {"Disease"},
    {"Poison"},
    {"DetectHostile"},
    {"DetectMagic"},
    {"NoTwincast"},
    {"Invulnerability"},
    {"Banish"},
    {"Shadow Step"},
    {"Berserk"},
    {"Lycanthropy"},
    {"Vampirism"},
    {"Resist Fire"},
    {"Resist Cold"},
    {"Resist Poison"},
    {"Resist Disease"},
    {"Resist Magic"},
    {"Detect (Switch) Traps"},
    {"Detect Undead"},
    {"Detect Summoned"},
    {"Detect Animals"},
    {"Stoneskin"},
    {"True North"},
    {"Levitation"},
    {"Change Form"},
    {"Damage Attackers (DS)"},
    {"TransferItem"},
    {"Identify"},
    {"Item ID"},
    {"NPC-WipeHatelist"},
    {"Spin Stun"},
    {"Infravision"},
    {"Ultravision"},
    {"NPC-POV"},
    {"Reclaim Energy"},
    {"Max HP"},
    {"CorpseBomb"},
    {"Create Undead"},
    {"PreserveCorpse"},
    {"TargetsView"},
    {"FeignDeath"},
    {"Ventriloquism"},
    {"Sentinel"},
    {"LocateCorpse"},
    {"SpellShield"},
    {"InstantHP"},
    {"Enchant:Light"},
    {"Resurrect"},
    {"Summon Target"},
    {"Portal"},
    {"Hp-NPC-ONLY"},
    {"Contact Ability (Melee Proc)"},
    {"NPC-Help-Radius"},
    {"Telescope"},
    {"Combat Portal"},
    {"Height"},
    {"IgnorePet"},
    {"SummonCorpse"},
    {"Hate (On Spell Land)"},
    {"WeatherControl"},
    {"Fragile"},
    {"Sacrifice"},
    {"Silence"},
    {"Max Mana"},
    {"Bard Haste"},
    {"Root"},
    {"HP Duration Only"},
    {"Complete Heal (Residual Buff)"},
    {"Pet No Fear"},
    {"Summon Pet"},
    {"Translocate"},
    {"Anti-Gate (NPC Only)"},
    {"BeastLordPet"},
    {"Alter Pet Level"},
    {"Familiar"},
    {"CreateItemInBag"},
    {"Removed (Archery RNG Acc%)"},
    {"Resistances"},
    {"Adjust Casting Skill (Fizzles)"},
    {"SummonMount"},
    {"Modify Hate"},
    {"Cornucopia"},
    {"Curse"},
    {"HitMagic"},
    {"Amplification"},
    {"BardHaste2"},
    {"HealMod"},
    {"IronMaiden"},
    {"ReduceSkill"},
    {"Immunity"},
    {"Fc_Damage_%"},
    {"Fc_HealMod"},
    {"Fc_ResistMod"},
    {"Fc_CastTimeMod1"},
    {"Fc_DurationMod"},
    {"Fc_RangeMod"},
    {"Fc_HateMod"},
    {"Fc_ReagentMod"},
    {"Fc_ManaMod"},
    {"Fc_StunTimeMod"},
    {"Ff_LevelMax"},
    {"Ff_ResistType"},
    {"Ff_TargetType"},
    {"Ff_WhichSPA"},
    {"Ff_Beneficial"},
    {"Ff_WhichSpellID"},
    {"Ff_DurationMin"},
    {"Ff_InstantOnly"},
    {"Ff_LevelMin"},
    {"Ff_CastTimeMin"},
    {"Ff_CastTimeMax"},
    {"Portal NPC Warder Banish"},
    {"Portal Locations"},
    {"Percent Heal"},
    {"StackingBlocker"},
    {"StripVirtualSlot"},
    {"Divine Intervention/Death Pact"},
    {"PocketPet"},
    {"PetSwarm"},
    {"Damage Balance"},
    {"Cancel Negative"},
    {"PoP Resurrect"},
    {"Mirror Form"},
    {"Feedback"},
    {"Reflect"},
    {"Mod all Stats"},
    {"Inebriation | Sobriety"},
    {"Spell Guard"},
    {"Melee Guard"},
    {"Absorb Hit"},
    {"Object - Sense Trap"},
    {"Object - Disarm Trap"},
    {"Object - Picklock"},
    {"Fc_Pet"},
    {"Defensive"},
    {"Critical Melee (PC Only)"},
    {"Spell Crit Damage"},
    {"Crippling Blow"},
    {"Evasion"},
    {"Riposte"},
    {"Dodge"},
    {"Parry"},
    {"Dual Wield"},
    {"Double Attack"},
    {"Melee Resource Drain"},
    {"Puretone"},
    {"Sanctification"},
    {"Fearless"},
    {"Hundred Hands"},
    {"UNUSED - Skill Increase Chance"},
    {"Accuracy %"},
    {"Skill Damage Mod 1"},
    {"Min Damage Done Mod"},
    {"Mana Balance"},
    {"Block"},
    {"Endurance"},
    {"Max Endurance"},
    {"Amnesia"},
    {"Hate (Duration Only)"},
    {"Skill Attack"},
    {"Fade"},
    {"Stun Resist (Melee+Spell)"},
    {"Deprecated (strikethrough)"},
    {"Skill Damage Taken Incoming"},
    {"Instant Endurance"},
    {"Taunt"},
    {"Weapon Proc Chance"},
    {"Ranged Proc"},
    {"IllusionOther"},
    {"MassBuff"},
    {"Group Fear Immunity"},
    {"AE Rampage Instant (PC Only)"},
    {"AE Taunt"},
    {"Flesh to Bone"},
    {"Purge Poison"},
    {"Cancel Beneficial"},
    {"Shield Caster"},
    {"AE Melee (PC Only)"},
    {"Fc_FrenziedDevastation"},
    {"Pet % HP"},
    {"HP Max Percent"},
    {"Pet Avoidance %"},
    {"Melee Accuracy Amt"},
    {"Headshot"},
    {"Pet Crit Melee Chance (Owner)"},
    {"Slay Undead"},
    {"Skill Min_Damage Amt 1"},
    {"ReduceWeight"},
    {"BlockBehind"},
    {"Double Riposte"},
    {"AddRiposte"},
    {"Give Double Attack"},
    {"2hbash"},
    {"ReduceSkillTimer"},
    {"ReduceFallDmg"},
    {"CastThroughStun"},
    {"Increase Shield Distance"},
    {"StunBashChance"},
    {"Divine Save"},
    {"Metabolism"},
    {"Poison Mastery"},
    {"FocusChannelling"},
    {"Free Pet"},
    {"PetAffinity"},
    {"Permanent Illusion"},
    {"Stonewall"},
    {"String Unbreakable"},
    {"Improve Reclaim Energy"},
    {"IncreaseChanceMemwipe"},
    {"NoBreakCharmChance"},
    {"RootBreakChance"},
    {"Trap Circumvention"},
    {"Lung Capacity"},
    {"IncreaseSkillCap"},
    {"ExtraSpecialization"},
    {"Offhand Weapon MinDamage Bonus"},
    {"Increase ContactAbility Chance"},
    {"EndlessQuiver"},
    {"Backstab FullDamage From Front"},
    {"Chaotic Stab"},
    {"NoSpell"},
    {"Shielding Duration Mod"},
    {"Shroud of Stealth"},
    {"DEPRECATED - GivePetHold"},
    {"Triple Backstab"},
    {"ACLimitMod"},
    {"AddInstrumentMod"},
    {"SongModCap"},
    {"StatsCap"},
    {"TradeskillMasteries"},
    {"ReduceAATimer"},
    {"NoFizzle"},
    {"AddExtraAttack% (2h)"},
    {"AddPetCommands"},
    {"AlcFailRate"},
    {"Bandage Max HP Limit %"},
    {"Bard Song Beneficial Radius %"},
    {"BaseRunMod"},
    {"Bard Song Level"},
    {"Critical DoT"},
    {"CriticalHeal"},
    {"Critical Mend %"},
    {"DualWieldAmt"},
    {"ExtraDIChance"},
    {"FinishingBlow"},
    {"FlurryChance (PC Only)"},
    {"Pet Flurry Chance (Owner)"},
    {"GivePetFeign"},
    {"Increase Bandage Heal %"},
    {"SpecialAttackChain"},
    {"LoHSetHeal"},
    {"Allow Hide/Evade While Moving"},
    {"Fc_Damage_Amt"},
    {"Fc_DurationMod (static)"},
    {"Add Proc Hit (AA)"},
    {"Doom Duration"},
    {"Increase Movement Cap"},
    {"Purify"},
    {"Strikethrough"},
    {"StunResist2 (Melee)"},
    {"Spell Crit Chance"},
    {"ReduceTimerSpecial"},
    {"Fc_Spell_Damage_%_Incoming"},
    {"Fc_Spell_Damage_Amt_Incoming"},
    {"Height (Small)"},
    {"Wake the Dead 1 (Corpse Class)"},
    {"Doppelganger"},
    {"Increase Range Damage"},
    {"Fc_Damage_%_Crit"},
    {"Fc_Damage_Amt_Crit"},
    {"Secondary Riposte Mod"},
    {"Mitigate Damage Shield Offhand"},
    {"Wake the Dead 2 (File Class)"},
    {"Appraisal"},
    {"Zone Suspend Minion"},
    {"Teleport Caster's Bindpoint"},
    {"Fc_ReuseTimer"},
    {"Ff_CombatSkill"},
    {"Observer"},
    {"Forage Master"},
    {"Improved Invis"},
    {"Improved Invis Undead"},
    {"Improved Invis Animals"},
    {"Worn Regen Cap"},
    {"Worn Mana Regen Cap"},
    {"Critical HP Regen"},
    {"Shield Block Chance"},
    {"Reduce Target Hate"},
    {"Gate Starting City"},
    {"Defensive Proc"},
    {"HP for Mana"},
    {"No Break AE Sneak"},
    {"Spell Slots"},
    {"Buff Slots"},
    {"Negative HP Limit"},
    {"Mana Absorb % Damage"},
    {"Critical Melee Damage Mod"},
    {"Alchemy Item Recovery"},
    {"Summon to Corpse"},
    {"Doom Rune Consumed"},
    {"HP No Move"},
    {"Fc_Immunity_Focus"},
    {"Illusionary Target"},
    {"Increase Exp %"},
    {"Expedient Recovery"},
    {"Fc_CastProc"},
    {"Chance Spell"},
    {"Worn Attack Cap"},
    {"No Panic"},
    {"Spell Interrupt"},
    {"Item Channeling"},
    {"Assassinate Max Level / Chance"},
    {"Headshot Max"},
    {"Double Ranged Attack"},
    {"Ff_Mana_Min"},
    {"Increase Damage With Shield"},
    {"Manaburn"},
    {"Spawn Interactive Object"},
    {"Increase Trap Count"},
    {"Increase SOI Count"},
    {"Deactivate All Traps"},
    {"Learn Trap"},
    {"Change Trigger Type"},
    {"Fc_Mute"},
    {"Instant Mana"},
    {"Passive Sense Trap"},
    {"Proc On Kill Shot"},
    {"Proc On Death"},
    {"Potion Belt"},
    {"Bandolier"},
    {"AddTripleAttackChance"},
    {"Proc On Spell Kill Shot"},
    {"Group Shielding"},
    {"Modify Body Type"},
    {"Modify Faction"},
    {"Corruption"},
    {"ResistCorruption"},
    {"Slow"},
    {"Grant Foraging"},
    {"Doom Always"},
    {"Trigger Spell"},
    {"Critical DoT Damage Mod %"},
    {"Fling"},
    {"Removed (Doom Entity)"},
    {"Resist Other SPA"},
    {"Directional Shadowstep"},
    {"Knockback Explosive (PC Only)"},
    {"Fling Target to Caster"},
    {"Suppression"},
    {"Fc_CastProcNormalized"},
    {"Fling Caster to Target"},
    {"Ff_WhichSpellGroup"},
    {"Doom Dispeller"},
    {"Doom Dispelled"},
    {"Summon All Corpses"},
    {"Fc_Timer_Refresh"},
    {"Fc_Timer_Lockout"},
    {"Ff_Mana_Max"},
    {"Fc_Heal_Amt"},
    {"Fc_Heal_%_Incoming"},
    {"Fc_Heal_Amt_Incoming"},
    {"Fc_Heal_%_Crit"},
    {"Fc_Heal_Amt_Crit"},
    {"Pet Add AC"},
    {"Fc_Swarm_Pet_Duration"},
    {"Fc_Twincast"},
    {"Healburn"},
    {"Mana Ignite"},
    {"Endurance Ignite"},
    {"Ff_SpellClass"},
    {"Ff_SpellSubclass"},
    {"Staff Block Chance"},
    {"Doom Limit Use"},
    {"Doom Focus Used"},
    {"Limit HP"},
    {"Limit Mana"},
    {"Limit Endurance"},
    {"Ff_ClassPlayer"},
    {"Ff_Race"},
    {"Fc_BaseEffects"},
    {"Ff_CastingSkill"},
    {"Ff_ItemClass"},
    {"AC_2"},
    {"Mana_2"},
    {"Skill Min_Damage Amt 2"},
    {"Contact Ability 2 (Melee Proc)"},
    {"Fc_Limit_Use"},
    {"Fc_Limit_Use_Amt"},
    {"Ff_Limit_Use_Min"},
    {"Ff_Limit_Use_Type"},
    {"Gravitate"},
    {"Fly"},
    {"AddExtTargetSlots"},
    {"Skill Proc (Attempt)"},
    {"Proc Skill Modifier"},
    {"Skill Proc (Success)"},
    {"PostEffect"},
    {"PostEffectData"},
    {"ExpandMaxActiveTrophyBenefits"},
    {"Normalized Skill Min_Dmg Amt 1"},
    {"Normalized Skill Min_Dmg Amt 2"},
    {"Fragile Defense"},
    {"Toggle Freeze Buff Timers"},
    {"Teleport to Anchor"},
    {"Translocate to Anchor"},
    {"Assassinate Chance / DMG"},
    {"FinishingBlowMax"},
    {"Distance Removal"},
    {"Doom Req Bearer"},
    {"Doom Req Caster"},
    {"Improved Taunt"},
    {"Add Merc Slot"},
    {"A_Stacker"},
    {"B_Stacker"},
    {"C_Stacker"},
    {"D_Stacker"},
    {"DoT Guard"},
    {"Melee Threshold Guard"},
    {"Spell Threshold Guard"},
    {"Doom Melee Threshold"},
    {"Doom Spell Threshold"},
    {"Add Hate % (On Land)"},
    {"Add Hate Over Time %"},
    {"Resource Tap"},
    {"Faction Mod %"},
    {"Skill Damage Mod 2"},
    {"Ff_Override_NotFocusable"},
    {"Fc_Damage_%_Crit 2"},
    {"Fc_Damage_Amt 2"},
    {"Shield Target"},
    {"PC Pet Rampage"},
    {"PC Pet AE Rampage"},
    {"PC Pet Flurry Chance"},
    {"DS Mitigation Amount"},
    {"DS Mitigation Percentage"},
    {"Chance Best in Spell Group"},
    {"Trigger Best in Spell Group"},
    {"Double Melee Round (PC Only)"},
    {"Buy AA Rank"},
    {"Double Backstab From Front"},
    {"Pet Crit Melee Damage% (Owner)"},
    {"Trigger Spell Non-Item"},
    {"Weapon Stance"},
    {"Hatelist To Top Index"},
    {"Hatelist To Tail Index"},
    {"Ff_Value_Min"},
    {"Ff_Value_Max"},
    {"Fc_Cast_Spell_On_Land"},
    {"Skill Base Damage Mod"},
    {"Fc_Spell_Damage_%_IncomingPC"},
    {"Fc_Spell_Damage_Amt_IncomingPC"},
    {"Ff_CasterClass"},
    {"Ff_Same_Caster"},
    {"Extend Tradeskill Cap"},
    {"Defender Melee Force % (PC)"},
    {"Worn Endurance Regen Cap"},
    {"Ff_ReuseTimeMin"},
    {"Ff_ReuseTimeMax"},
    {"Ff_Endurance_Min"},
    {"Ff_Endurance_Max"},
    {"Pet Add Atk"},
    {"Ff_DurationMax"},
    {"Critical Melee Damage Mod Max"},
    {"Ff_FocusCastProcNoBypass"},
    {"AddExtraAttack% (1h-Primary)"},
    {"AddExtraAttack% (1h-Secondary)"},
    {"Fc_CastTimeMod2"},
    {"Fc_CastTimeAmt"},
    {"Fearstun"},
    {"Melee Damage Position Mod"},
    {"Melee Damage Position Amt"},
    {"Damage Taken Position Mod"},
    {"Damage Taken Position Amt"},
    {"Fc_Amplify_Mod"},
    {"Fc_Amplify_Amt"},
    {"Health Transfer"},
    {"Fc_ResistIncoming"},
    {"Ff_FocusTimerMin"},
    {"Proc Timer Modifier"},
    {"Mana Max Percent"},
    {"Endurance Max Percent"},
    {"AC Avoidance Max Percent"},
    {"AC Mitigation Max Percent"},
    {"Attack Offense Max Percent"},
    {"Attack Accuracy Max Percent"},
    {"Luck Amount"},
    {"Luck Percent"},
};
