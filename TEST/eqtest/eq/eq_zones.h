#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#define EQ_ZONE_ID_QEYNOS 1 // South Qeynos
#define EQ_ZONE_ID_QEYNOS2 2 // North Qeynos
#define EQ_ZONE_ID_QRG 3 // Surefall Glade
#define EQ_ZONE_ID_QEYTOQRG 4 // Qeynos Hills
#define EQ_ZONE_ID_HIGHKEEP 6 // High Keep
#define EQ_ZONE_ID_FREPORTN 8 // North Freeport
#define EQ_ZONE_ID_FREPORTW 9 // West Freeport
#define EQ_ZONE_ID_FREPORTE 10 // East Freeport
#define EQ_ZONE_ID_RUNNYEYE 11 // Clan Runnyeye
#define EQ_ZONE_ID_QEY2HH1 12 // West Karana
#define EQ_ZONE_ID_NORTHKARANA 13 // North Karana
#define EQ_ZONE_ID_SOUTHKARANA 14 // South Karana
#define EQ_ZONE_ID_EASTKARANA 15 // East Karana
#define EQ_ZONE_ID_BEHOLDER 16 // Gorge of King Xorbb
#define EQ_ZONE_ID_BLACKBURROW 17 // BlackBurrow
#define EQ_ZONE_ID_PAW 18 // Infected Paw
#define EQ_ZONE_ID_RIVERVALE 19 // Rivervale
#define EQ_ZONE_ID_KITHICOR 20 // Kithicor Forest
#define EQ_ZONE_ID_COMMONS 21 // West Commonlands
#define EQ_ZONE_ID_ECOMMONS 22 // East Commonlands
#define EQ_ZONE_ID_COMMONLANDS 408 // Commonlands
#define EQ_ZONE_ID_OCEANOFTEARS 409 // Ocean of Tears
#define EQ_ZONE_ID_KITHFOREST 410 // Kithicor Forest
#define EQ_ZONE_ID_BEFALLENB 411 // Befallen
#define EQ_ZONE_ID_HIGHPASSKEEP 412 // High Keep
#define EQ_ZONE_ID_INNOTHULEB 413 // Innothule Swamp
#define EQ_ZONE_ID_TOXXULIA 414 // Toxxulia Forest
#define EQ_ZONE_ID_MISTYTHICKET 415 // Misty Thicket
#define EQ_ZONE_ID_ERUDNINT 23 // Erudin Palace
#define EQ_ZONE_ID_ERUDNEXT 24 // Erudin
#define EQ_ZONE_ID_NEKTULOS 25 // Nektulos Forest
#define EQ_ZONE_ID_CSHOME 26 // Sunset Home
#define EQ_ZONE_ID_LAVASTORM 27 // Lavastorm Mountains
#define EQ_ZONE_ID_NEKTROPOS 28 // Nektropos
#define EQ_ZONE_ID_HALAS 29 // Halas
#define EQ_ZONE_ID_EVERFROST 30 // Everfrost Peaks
#define EQ_ZONE_ID_SOLDUNGA 31 // Solusek's Eye
#define EQ_ZONE_ID_SOLDUNGB 32 // Nagafen's Lair
#define EQ_ZONE_ID_MISTY 33 // Misty Thicket
#define EQ_ZONE_ID_NRO 34 // North Ro
#define EQ_ZONE_ID_SRO 35 // South Ro
#define EQ_ZONE_ID_BEFALLEN 36 // Befallen
#define EQ_ZONE_ID_OASIS 37 // Oasis of Marr
#define EQ_ZONE_ID_TOX 38 // Toxxulia Forest
#define EQ_ZONE_ID_HOLE 39 // The Ruins of Old Paineel
#define EQ_ZONE_ID_NERIAKA 40 // Neriak - Foreign Quarter
#define EQ_ZONE_ID_NERIAKB 41 // Neriak - Commons
#define EQ_ZONE_ID_NERIAKC 42 // Neriak - Third Gate
#define EQ_ZONE_ID_NAJENA 44 // Najena
#define EQ_ZONE_ID_QCAT 45 // Qeynos Catacombs
#define EQ_ZONE_ID_INNOTHULE 46 // Innothule Swamp
#define EQ_ZONE_ID_FEERROTT 47 // The Feerrott
#define EQ_ZONE_ID_CAZICTHULE 48 // Cazic-Thule
#define EQ_ZONE_ID_OGGOK 49 // Oggok
#define EQ_ZONE_ID_RATHEMTN 50 // Mountains of Rathe
#define EQ_ZONE_ID_LAKERATHE 51 // Lake Rathetear
#define EQ_ZONE_ID_GROBB 52 // Grobb
#define EQ_ZONE_ID_AVIAK 53 // Aviak Village
#define EQ_ZONE_ID_GFAYDARK 54 // Greater Faydark
#define EQ_ZONE_ID_AKANON 55 // Ak'Anon
#define EQ_ZONE_ID_STEAMFONT 56 // Steamfont Mountains
#define EQ_ZONE_ID_LFAYDARK 57 // Lesser Faydark
#define EQ_ZONE_ID_CRUSHBONE 58 // Clan Crushbone
#define EQ_ZONE_ID_MISTMOORE 59 // Castle Mistmoore
#define EQ_ZONE_ID_KALADIMA 60 // Kaladim
#define EQ_ZONE_ID_FELWITHEA 61 // Felwithe
#define EQ_ZONE_ID_FELWITHEB 62 // Felwithe
#define EQ_ZONE_ID_UNREST 63 // Estate of Unrest
#define EQ_ZONE_ID_KEDGE 64 // Kedge Keep
#define EQ_ZONE_ID_GUKTOP 65 // Upper Guk
#define EQ_ZONE_ID_GUKBOTTOM 66 // Lower Guk
#define EQ_ZONE_ID_KALADIMB 67 // Kaladim
#define EQ_ZONE_ID_BUTCHER 68 // Butcherblock Mountains
#define EQ_ZONE_ID_OOT 69 // Ocean of Tears
#define EQ_ZONE_ID_CAULDRON 70 // Dagnor's Cauldron
#define EQ_ZONE_ID_AIRPLANE 71 // Plane of Sky
#define EQ_ZONE_ID_FEARPLANE 72 // Plane of Fear
#define EQ_ZONE_ID_PERMAFROST 73 // Permafrost Keep
#define EQ_ZONE_ID_KERRARIDGE 74 // Kerra Isle
#define EQ_ZONE_ID_PAINEEL 75 // Paineel
#define EQ_ZONE_ID_HATEPLANE 76 // The Plane of Hate
#define EQ_ZONE_ID_ARENA 77 // The Arena
#define EQ_ZONE_ID_FIELDOFBONE 78 // The Field of Bone
#define EQ_ZONE_ID_WARSLIKSWOOD 79 // Warsliks Woods
#define EQ_ZONE_ID_SOLTEMPLE 80 // Temple of Solusek Ro
#define EQ_ZONE_ID_DROGA 81 // Temple of Droga
#define EQ_ZONE_ID_CABWEST 82 // West Cabilis
#define EQ_ZONE_ID_SWAMPOFNOHOPE 83 // Swamp of No Hope
#define EQ_ZONE_ID_FIRIONA 84 // Firiona Vie
#define EQ_ZONE_ID_LAKEOFILLOMEN 85 // Lake of Ill Omen
#define EQ_ZONE_ID_DREADLANDS 86 // Dreadlands
#define EQ_ZONE_ID_BURNINGWOOD 87 // Burning Woods
#define EQ_ZONE_ID_KAESORA 88 // Kaesora
#define EQ_ZONE_ID_SEBILIS 89 // Old Sebilis
#define EQ_ZONE_ID_CITYMIST 90 // City of Mist
#define EQ_ZONE_ID_SKYFIRE 91 // Skyfire Mountains
#define EQ_ZONE_ID_FRONTIERMTNS 92 // Frontier Mountains
#define EQ_ZONE_ID_OVERTHERE 93 // The Overthere
#define EQ_ZONE_ID_EMERALDJUNGLE 94 // The Emerald Jungle
#define EQ_ZONE_ID_TRAKANON 95 // Trakanon's Teeth
#define EQ_ZONE_ID_TIMOROUS 96 // Timorous Deep
#define EQ_ZONE_ID_KURN 97 // Kurn's Tower
#define EQ_ZONE_ID_ERUDSXING 98 // Erud's Crossing
#define EQ_ZONE_ID_STONEBRUNT 100 // Stonebrunt Mountains
#define EQ_ZONE_ID_WARRENS 101 // The Warrens
#define EQ_ZONE_ID_KARNOR 102 // Karnor's Castle
#define EQ_ZONE_ID_CHARDOK 103 // Chardok
#define EQ_ZONE_ID_DALNIR 104 // Dalnir
#define EQ_ZONE_ID_CHARASIS 105 // Howling Stones
#define EQ_ZONE_ID_CABEAST 106 // East Cabilis
#define EQ_ZONE_ID_NURGA 107 // Mines of Nurga
#define EQ_ZONE_ID_VEESHAN 108 // Veeshan's Peak
#define EQ_ZONE_ID_VEKSAR 109 // Veksar
#define EQ_ZONE_ID_ICECLAD 110 // Iceclad Ocean
#define EQ_ZONE_ID_FROZENSHADOW 111 // Tower of Frozen Shadow
#define EQ_ZONE_ID_VELKETOR 112 // Velketor's Labyrinth
#define EQ_ZONE_ID_KAEL 113 // Kael Drakkel
#define EQ_ZONE_ID_SKYSHRINE 114 // Skyshrine
#define EQ_ZONE_ID_THURGADINA 115 // Thurgadin
#define EQ_ZONE_ID_EASTWASTES 116 // Eastern Wastes
#define EQ_ZONE_ID_COBALTSCAR 117 // Cobalt Scar
#define EQ_ZONE_ID_GREATDIVIDE 118 // Great Divide
#define EQ_ZONE_ID_WAKENING 119 // The Wakening Land
#define EQ_ZONE_ID_WESTWASTES 120 // Western Wastes
#define EQ_ZONE_ID_CRYSTAL 121 // Crystal Caverns
#define EQ_ZONE_ID_NECROPOLIS 123 // Dragon Necropolis
#define EQ_ZONE_ID_TEMPLEVEESHAN 124 // Temple of Veeshan
#define EQ_ZONE_ID_SIRENS 125 // Siren's Grotto
#define EQ_ZONE_ID_MISCHIEFPLANE 126 // Plane of Mischief
#define EQ_ZONE_ID_GROWTHPLANE 127 // Plane of Growth
#define EQ_ZONE_ID_SLEEPER 128 // Sleeper's Tomb
#define EQ_ZONE_ID_THURGADINB 129 // Icewell Keep
#define EQ_ZONE_ID_ERUDSXING2 130 // Marauder's Mire
#define EQ_ZONE_ID_SHADOWHAVEN 150 // Shadow Haven
#define EQ_ZONE_ID_BAZAAR 151 // The Bazaar
#define EQ_ZONE_ID_NEXUS 152 // The Nexus
#define EQ_ZONE_ID_ECHO 153 // Echo Caverns
#define EQ_ZONE_ID_ACRYLIA 154 // Acrylia Caverns
#define EQ_ZONE_ID_SHARVAHL 155 // Shar Vahl
#define EQ_ZONE_ID_PALUDAL 156 // Paludal Caverns
#define EQ_ZONE_ID_FUNGUSGROVE 157 // Fungus Grove
#define EQ_ZONE_ID_VEXTHAL 158 // Vex Thal
#define EQ_ZONE_ID_SSERU 159 // Sanctus Seru
#define EQ_ZONE_ID_KATTA 160 // Katta Castellum
#define EQ_ZONE_ID_NETHERBIAN 161 // Netherbian Lair
#define EQ_ZONE_ID_SSRATEMPLE 162 // Ssraeshza Temple
#define EQ_ZONE_ID_GRIEGSEND 163 // Grieg's End
#define EQ_ZONE_ID_THEDEEP 164 // The Deep
#define EQ_ZONE_ID_SHADEWEAVER 165 // Shadeweaver's Thicket
#define EQ_ZONE_ID_HOLLOWSHADE 166 // Hollowshade Moor
#define EQ_ZONE_ID_GRIMLING 167 // Grimling Forest
#define EQ_ZONE_ID_MSERU 168 // Marus Seru
#define EQ_ZONE_ID_LETALIS 169 // Mons Letalis
#define EQ_ZONE_ID_TWILIGHT 170 // The Twilight Sea
#define EQ_ZONE_ID_THEGREY 171 // The Grey
#define EQ_ZONE_ID_TENEBROUS 172 // The Tenebrous Mountains
#define EQ_ZONE_ID_MAIDEN 173 // The Maiden's Eye
#define EQ_ZONE_ID_DAWNSHROUD 174 // Dawnshroud Peaks
#define EQ_ZONE_ID_SCARLET 175 // The Scarlet Desert
#define EQ_ZONE_ID_UMBRAL 176 // The Umbral Plains
#define EQ_ZONE_ID_AKHEVA 179 // Akheva Ruins
#define EQ_ZONE_ID_ARENA2 180 // The Arena
#define EQ_ZONE_ID_JAGGEDPINE 181 // The Jaggedpine Forest
#define EQ_ZONE_ID_NEDARIA 182 // Nedaria's Landing
#define EQ_ZONE_ID_SHADOWREST 187 // Shadowrest
#define EQ_ZONE_ID_TUTORIAL 183 // Tutorial Zone
#define EQ_ZONE_ID_TUTORIALA 188 // The Mines of Gloomingdeep
#define EQ_ZONE_ID_TUTORIALB 189 // The Mines of Gloomingdeep
#define EQ_ZONE_ID_CLZ 190 // Loading
#define EQ_ZONE_ID_LOAD 184 // Loading
#define EQ_ZONE_ID_LOAD2 185 // Loading
#define EQ_ZONE_ID_ARTTEST 996 // Art Testing Domain
#define EQ_ZONE_ID_APPRENTICE 999 // Designer Apprentice
#define EQ_ZONE_ID_POKNOWLEDGE 202 // Plane of Knowledge
#define EQ_ZONE_ID_POTRANQUILITY 203 // Plane of Tranquility
#define EQ_ZONE_ID_CODECAY 200 // Ruins of Lxanvom
#define EQ_ZONE_ID_POJUSTICE 201 // Plane of Justice
#define EQ_ZONE_ID_PONIGHTMARE 204 // Plane of Nightmare
#define EQ_ZONE_ID_NIGHTMAREB 221 // Lair of Terris Thule
#define EQ_ZONE_ID_PODISEASE 205 // Plane of Disease
#define EQ_ZONE_ID_POINNOVATION 206 // Plane of Innovation
#define EQ_ZONE_ID_POTORMENT 207 // Plane of Torment
#define EQ_ZONE_ID_POVALOR 208 // Plane of Valor
#define EQ_ZONE_ID_BOTHUNDER 209 // Torden, The Bastion of Thunder
#define EQ_ZONE_ID_POSTORMS 210 // Plane of Storms
#define EQ_ZONE_ID_HOHONORA 211 // Halls of Honor
#define EQ_ZONE_ID_HOHONORB 220 // Temple of Marr
#define EQ_ZONE_ID_SOLROTOWER 212 // Solusek Ro's Tower
#define EQ_ZONE_ID_POWAR 213 // Plane of War
#define EQ_ZONE_ID_POTACTICS 214 // Drunder, Fortress of Zek
#define EQ_ZONE_ID_POAIR 215 // Eryslai, the Kingdom of Wind
#define EQ_ZONE_ID_POWATER 216 // Reef of Coirnav
#define EQ_ZONE_ID_POFIRE 217 // Doomfire, The Burning Lands
#define EQ_ZONE_ID_POEARTHA 218 // Vegarlson, The Earthen Badlands
#define EQ_ZONE_ID_POEARTHB 222 // Stronghold of the Twelve
#define EQ_ZONE_ID_POTIMEA 219 // Plane of Time
#define EQ_ZONE_ID_POTIMEB 223 // Plane of Time
#define EQ_ZONE_ID_TORGIRAN 226 // Torgiran Mines
#define EQ_ZONE_ID_NADOX 227 // Crypt of Nadox
#define EQ_ZONE_ID_GUNTHAK 224 // Gulf of Gunthak
#define EQ_ZONE_ID_DULAK 225 // Dulak's Harbor
#define EQ_ZONE_ID_HATESFURY 228 // Hate's Fury, The Scorned Maiden
#define EQ_ZONE_ID_HATEPLANEB 186 // The Plane of Hate
#define EQ_ZONE_ID_CHARDOKB 277 // The Halls of Betrayal
#define EQ_ZONE_ID_SOLDUNGC 278 // The Caverns of Exile
#define EQ_ZONE_ID_GUKA 229 // The Cauldron of Lost Souls
#define EQ_ZONE_ID_RUJA 230 // The Bloodied Quarries
#define EQ_ZONE_ID_TAKA 231 // The Sunken Library
#define EQ_ZONE_ID_MIRA 232 // The Silent Gallery
#define EQ_ZONE_ID_MMCA 233 // The Forlorn Caverns
#define EQ_ZONE_ID_GUKB 234 // The Drowning Crypt
#define EQ_ZONE_ID_RUJB 235 // The Halls of War
#define EQ_ZONE_ID_TAKB 236 // The Shifting Tower
#define EQ_ZONE_ID_MIRB 237 // The Maw of the Menagerie
#define EQ_ZONE_ID_MMCB 238 // The Dreary Grotto
#define EQ_ZONE_ID_GUKC 239 // The Ancient Aqueducts
#define EQ_ZONE_ID_RUJC 240 // The Wind Bridges
#define EQ_ZONE_ID_TAKC 241 // The Fading Temple
#define EQ_ZONE_ID_MIRC 242 // The Spider Den
#define EQ_ZONE_ID_MMCC 243 // The Asylum of Invoked Stone
#define EQ_ZONE_ID_GUKD 244 // The Mushroom Grove
#define EQ_ZONE_ID_RUJD 245 // The Gladiator Pits
#define EQ_ZONE_ID_TAKD 246 // The Royal Observatory
#define EQ_ZONE_ID_MIRD 247 // The Hushed Banquet
#define EQ_ZONE_ID_MMCD 248 // The Chambers of Eternal Affliction
#define EQ_ZONE_ID_GUKE 249 // The Foreboding Prison
#define EQ_ZONE_ID_RUJE 250 // The Drudge Hollows
#define EQ_ZONE_ID_TAKE 251 // The River of Recollection
#define EQ_ZONE_ID_MIRE 252 // The Frosted Halls
#define EQ_ZONE_ID_MMCE 253 // The Sepulcher of the Damned
#define EQ_ZONE_ID_GUKF 254 // The Chapel of the Witnesses
#define EQ_ZONE_ID_RUJF 255 // The Fortified Lair of the Taskmasters
#define EQ_ZONE_ID_TAKF 256 // The Sandfall Corridors
#define EQ_ZONE_ID_MIRF 257 // The Forgotten Wastes
#define EQ_ZONE_ID_MMCF 258 // The Ritualistic Summoning Grounds
#define EQ_ZONE_ID_GUKG 259 // The Root Garden
#define EQ_ZONE_ID_RUJG 260 // The Hidden Vale
#define EQ_ZONE_ID_TAKG 261 // The Balancing Chamber
#define EQ_ZONE_ID_MIRG 262 // The Heart of the Menagerie
#define EQ_ZONE_ID_MMCG 263 // The Cesspits of Putrescence
#define EQ_ZONE_ID_GUKH 264 // The Accursed Sanctuary
#define EQ_ZONE_ID_RUJH 265 // The Blazing Forge
#define EQ_ZONE_ID_TAKH 266 // The Sweeping Tides
#define EQ_ZONE_ID_MIRH 267 // The Morbid Laboratory
#define EQ_ZONE_ID_MMCH 268 // The Aisles of Blood
#define EQ_ZONE_ID_RUJI 269 // The Arena of Chance
#define EQ_ZONE_ID_TAKI 270 // The Antiquated Palace
#define EQ_ZONE_ID_MIRI 271 // The Theater of Imprisoned Horrors
#define EQ_ZONE_ID_MMCI 272 // The Halls of Sanguinary Rites
#define EQ_ZONE_ID_RUJJ 273 // The Barracks of War
#define EQ_ZONE_ID_TAKJ 274 // The Prismatic Corridors
#define EQ_ZONE_ID_MIRJ 275 // The Grand Library
#define EQ_ZONE_ID_MMCJ 276 // The Infernal Sanctuary
#define EQ_ZONE_ID_ARENA 77 // The Arena
#define EQ_ZONE_ID_ABYSMAL 279 // Abysmal Sea
#define EQ_ZONE_ID_NATIMBI 280 // Natimbi, The Broken Shores
#define EQ_ZONE_ID_QINIMI 281 // Qinimi, Court of Nihilia
#define EQ_ZONE_ID_RIWWI 282 // Riwwi, Coliseum of Games
#define EQ_ZONE_ID_BARINDU 283 // Barindu, Hanging Gardens
#define EQ_ZONE_ID_SNPOOL 285 // Sewers of Nihilia, Pool of Sludge
#define EQ_ZONE_ID_TIPT 289 // Tipt, Treacherous Crags
#define EQ_ZONE_ID_VXED 290 // Vxed, The Crumbling Caverns
#define EQ_ZONE_ID_YXTTA 291 // Yxtta, Pulpit of Exiles
#define EQ_ZONE_ID_UQUA 292 // Uqua, The Ocean God Chantry
#define EQ_ZONE_ID_KODTAZ 293 // Kod'Taz, Broken Trial Grounds
#define EQ_ZONE_ID_IKKINZ 294 // Ikkinz, Chambers of Destruction
#define EQ_ZONE_ID_INKTUTA 296 // Inktu`Ta, The Unmasked Chapel
#define EQ_ZONE_ID_TXEVU 297 // Txevu, Lair of the Elite
#define EQ_ZONE_ID_TACVI 298 // Tacvi, Seat of the Slaver
#define EQ_ZONE_ID_QVIC 295 // Qvic, Prayer Grounds of Calling
#define EQ_ZONE_ID_QVICB 299 // Qvic, the Hidden Vault
#define EQ_ZONE_ID_WALLOFSLAUGHTER 300 // Wall of Slaughter
#define EQ_ZONE_ID_BLOODFIELDS 301 // The Bloodfields
#define EQ_ZONE_ID_DRANIKSSCAR 302 // Dranik's Scar
#define EQ_ZONE_ID_CAUSEWAY 303 // Nobles' Causeway
#define EQ_ZONE_ID_CHAMBERSA 304 // Muramite Proving Grounds
#define EQ_ZONE_ID_CHAMBERSB 305 // Muramite Proving Grounds
#define EQ_ZONE_ID_CHAMBERSC 306 // Muramite Proving Grounds
#define EQ_ZONE_ID_CHAMBERSD 307 // Muramite Proving Grounds
#define EQ_ZONE_ID_CHAMBERSE 308 // Muramite Proving Grounds
#define EQ_ZONE_ID_CHAMBERSF 309 // Muramite Proving Grounds
#define EQ_ZONE_ID_PROVINGGROUNDS 316 // Muramite Proving Grounds
#define EQ_ZONE_ID_ANGUISH 317 // Anguish, the Fallen Palace
#define EQ_ZONE_ID_DRANIKHOLLOWSA 318 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSB 319 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSC 320 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSD 321 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSE 322 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSF 323 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSG 324 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSH 325 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSI 326 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKHOLLOWSJ 327 // Dranik's Hollows
#define EQ_ZONE_ID_DRANIKCATACOMBSA 328 // Catacombs of Dranik
#define EQ_ZONE_ID_DRANIKCATACOMBSB 329 // Catacombs of Dranik
#define EQ_ZONE_ID_DRANIKCATACOMBSC 330 // Catacombs of Dranik
#define EQ_ZONE_ID_DRANIKSEWERSA 331 // Sewers of Dranik
#define EQ_ZONE_ID_DRANIKSEWERSB 332 // Sewers of Dranik
#define EQ_ZONE_ID_DRANIKSEWERSC 333 // Sewers of Dranik
#define EQ_ZONE_ID_RIFTSEEKERS 334 // Riftseekers' Sanctum
#define EQ_ZONE_ID_HARBINGERS 335 // Harbingers' Spire
#define EQ_ZONE_ID_DRANIK 336 // The Ruined City of Dranik
#define EQ_ZONE_ID_FHALLS 998 // The Forgotten Halls
#define EQ_ZONE_ID_BROODLANDS 337 // The Broodlands
#define EQ_ZONE_ID_STILLMOONA 338 // Stillmoon Temple
#define EQ_ZONE_ID_STILLMOONB 339 // The Ascent
#define EQ_ZONE_ID_THUNDERCREST 340 // Thundercrest Isles
#define EQ_ZONE_ID_DELVEA 341 // Lavaspinner's Lair
#define EQ_ZONE_ID_DELVEB 342 // Tirranun's Delve
#define EQ_ZONE_ID_THENEST 343 // The Accursed Nest
#define EQ_ZONE_ID_GUILDLOBBY 344 // The Guild Lobby
#define EQ_ZONE_ID_GUILDHALL 345 // Guild Hall
#define EQ_ZONE_ID_BARTER 346 // The Barter Hall
#define EQ_ZONE_ID_ILLSALIN 347 // Ruins of Illsalin
#define EQ_ZONE_ID_ILLSALINA 348 // Imperial Bazaar
#define EQ_ZONE_ID_ILLSALINB 349 // Temple of the Korlach
#define EQ_ZONE_ID_ILLSALINC 350 // The Nargilor Pits
#define EQ_ZONE_ID_DREADSPIRE 351 // Dreadspire Keep
#define EQ_ZONE_ID_DRACHNIDHIVE 354 // The Hive
#define EQ_ZONE_ID_DRACHNIDHIVEA 355 // Living Larder
#define EQ_ZONE_ID_DRACHNIDHIVEB 356 // Coven of the Skinwalkers
#define EQ_ZONE_ID_DRACHNIDHIVEC 357 // Queen Sendaii's Lair
#define EQ_ZONE_ID_WESTKORLACH 358 // Stoneroot Falls
#define EQ_ZONE_ID_WESTKORLACHA 359 // Chambers of Xill
#define EQ_ZONE_ID_WESTKORLACHB 360 // Caverns of the Lost
#define EQ_ZONE_ID_WESTKORLACHC 361 // Lair of the Korlach
#define EQ_ZONE_ID_EASTKORLACH 362 // Undershore
#define EQ_ZONE_ID_EASTKORLACHA 363 // Snarlstone Dens
#define EQ_ZONE_ID_SHADOWSPINE 364 // Shadowspine
#define EQ_ZONE_ID_CORATHUS 365 // Corathus Creep
#define EQ_ZONE_ID_CORATHUSA 366 // Sporali Caverns
#define EQ_ZONE_ID_CORATHUSB 367 // Corathus Lair
#define EQ_ZONE_ID_NEKTULOSA 368 // Shadowed Grove
#define EQ_ZONE_ID_ARCSTONE 369 // Arcstone
#define EQ_ZONE_ID_RELIC 370 // Relic
#define EQ_ZONE_ID_SKYLANCE 371 // Skylance
#define EQ_ZONE_ID_DEVASTATION 372 // The Devastation
#define EQ_ZONE_ID_DEVASTATIONA 373 // The Seething Wall
#define EQ_ZONE_ID_RAGE 374 // Sverag, Stronghold of Rage
#define EQ_ZONE_ID_RAGEA 375 // Razorthorn, Tower of Sullon Zek
#define EQ_ZONE_ID_TAKISHRUINS 376 // Ruins of Takish-Hiz
#define EQ_ZONE_ID_TAKISHRUINSA 377 // The Root of Ro
#define EQ_ZONE_ID_ELDDAR 378 // The Elddar Forest
#define EQ_ZONE_ID_ELDDARA 379 // Tunare's Shrine
#define EQ_ZONE_ID_THEATER 380 // Theater of Blood
#define EQ_ZONE_ID_THEATERA 381 // Deathknell, Tower of Dissonance
#define EQ_ZONE_ID_FREEPORTEAST 382 // East Freeport
#define EQ_ZONE_ID_FREEPORTWEST 383 // West Freeport
#define EQ_ZONE_ID_FREEPORTSEWERS 384 // Freeport Sewers
#define EQ_ZONE_ID_FREEPORTACADEMY 385 // Academy of Arcane Sciences
#define EQ_ZONE_ID_FREEPORTTEMPLE 386 // Temple of Marr
#define EQ_ZONE_ID_FREEPORTMILITIA 387 // Freeport Militia House
#define EQ_ZONE_ID_FREEPORTARENA 388 // Arena
#define EQ_ZONE_ID_FREEPORTCITYHALL 389 // City Hall
#define EQ_ZONE_ID_FREEPORTTHEATER 390 // Theater
#define EQ_ZONE_ID_FREEPORTHALL 391 // Hall of Truth
#define EQ_ZONE_ID_NORTHRO 392 // North Ro
#define EQ_ZONE_ID_SOUTHRO 393 // South Ro
#define EQ_ZONE_ID_CRESCENT 394 // Crescent Reach
#define EQ_ZONE_ID_MOORS 395 // Blightfire Moors
#define EQ_ZONE_ID_STONEHIVE 396 // Stone Hive
#define EQ_ZONE_ID_MESA 397 // Goru`kar Mesa
#define EQ_ZONE_ID_ROOST 398 // Blackfeather Roost
#define EQ_ZONE_ID_STEPPES 399 // The Steppes
#define EQ_ZONE_ID_ICEFALL 400 // Icefall Glacier
#define EQ_ZONE_ID_VALDEHOLM 401 // Valdeholm
#define EQ_ZONE_ID_SUNDEROCK 403 // Sunderock Springs
#define EQ_ZONE_ID_VERGALID 404 // Vergalid Mines
#define EQ_ZONE_ID_DIREWIND 405 // Direwind Cliffs
#define EQ_ZONE_ID_ASHENGATE 406 // Ashengate, Reliquary of the Scale
#define EQ_ZONE_ID_HIGHPASSHOLD 407 // Highpass Hold
#define EQ_ZONE_ID_KATTACASTRUM 416 // Katta Castrum
#define EQ_ZONE_ID_THALASSIUS 417 // Thalassius, the Coral Keep
#define EQ_ZONE_ID_ATIIKI 418 // Jewel of Atiiki
#define EQ_ZONE_ID_ZHISZA 419 // Zhisza, the Shissar Sanctuary
#define EQ_ZONE_ID_SILYSSAR 420 // Silyssar, New Chelsith
#define EQ_ZONE_ID_SOLTERIS 421 // Solteris, the Throne of Ro
#define EQ_ZONE_ID_BARREN 422 // Barren Coast
#define EQ_ZONE_ID_BURIEDSEA 423 // The Buried Sea
#define EQ_ZONE_ID_JARDELSHOOK 424 // Jardel's Hook
#define EQ_ZONE_ID_MONKEYROCK 425 // Monkey Rock
#define EQ_ZONE_ID_SUNCREST 426 // Suncrest Isle
#define EQ_ZONE_ID_DEADBONE 427 // Deadbone Reef
#define EQ_ZONE_ID_BLACKSAIL 428 // Blacksail Folly
#define EQ_ZONE_ID_MAIDENSGRAVE 429 // Maiden's Grave
#define EQ_ZONE_ID_REDFEATHER 430 // Redfeather Isle
#define EQ_ZONE_ID_SHIPMVP 431 // The Open Sea
#define EQ_ZONE_ID_SHIPMVU 432 // The Open Sea
#define EQ_ZONE_ID_SHIPPVU 433 // The Open Sea
#define EQ_ZONE_ID_SHIPUVU 434 // The Open Sea
#define EQ_ZONE_ID_SHIPMVM 435 // The Open Sea
#define EQ_ZONE_ID_MECHANOTUS 436 // Fortress Mechanotus
#define EQ_ZONE_ID_MANSION 437 // Meldrath's Majestic Mansion
#define EQ_ZONE_ID_STEAMFACTORY 438 // The Steam Factory
#define EQ_ZONE_ID_SHIPWORKSHOP 439 // S.H.I.P. Workshop
#define EQ_ZONE_ID_GYROSPIREB 440 // Gyrospire Beza
#define EQ_ZONE_ID_GYROSPIREZ 441 // Gyrospire Zeka
#define EQ_ZONE_ID_DRAGONSCALE 442 // Dragonscale Hills
#define EQ_ZONE_ID_LOPINGPLAINS 443 // Loping Plains
#define EQ_ZONE_ID_HILLSOFSHADE 444 // Hills of Shade
#define EQ_ZONE_ID_BLOODMOON 445 // Bloodmoon Keep
#define EQ_ZONE_ID_CRYSTALLOS 446 // Crystallos, Lair of the Awakened
#define EQ_ZONE_ID_GUARDIAN 447 // The Mechamatic Guardian
#define EQ_ZONE_ID_CRYPTOFSHADE 449 // Crypt of Shade
#define EQ_ZONE_ID_DRAGONSCALEA 450 // Tinmizer's Wunderwerks
#define EQ_ZONE_ID_DRAGONSCALEB 451 // Deepscar's Den
#define EQ_ZONE_ID_OLDFIELDOFBONE 452 // Field of Scale
#define EQ_ZONE_ID_OLDFIELDOFBONEB 478 // Field of Scale
#define EQ_ZONE_ID_OLDKAESORAA 453 // Kaesora Library
#define EQ_ZONE_ID_OLDKAESORAB 454 // Hatchery Wing
#define EQ_ZONE_ID_OLDKURN 455 // Kurn's Tower
#define EQ_ZONE_ID_OLDKITHICOR 456 // Bloody Kithicor
#define EQ_ZONE_ID_OLDCOMMONS 457 // Old Commonlands
#define EQ_ZONE_ID_OLDHIGHPASS 458 // Highpass Hold
#define EQ_ZONE_ID_THEVOIDA 459 // The Void
#define EQ_ZONE_ID_THEVOIDB 460 // The Void
#define EQ_ZONE_ID_THEVOIDC 461 // The Void
#define EQ_ZONE_ID_THEVOIDD 462 // The Void
#define EQ_ZONE_ID_THEVOIDE 463 // The Void
#define EQ_ZONE_ID_THEVOIDF 464 // The Void
#define EQ_ZONE_ID_THEVOIDG 465 // The Void
#define EQ_ZONE_ID_OCEANGREENHILLS 466 // Oceangreen Hills
#define EQ_ZONE_ID_OCEANGREENVILLAGE 467 // Oceangreen Village
#define EQ_ZONE_ID_OLDBLACKBURROW 468 // Blackburrow
#define EQ_ZONE_ID_BERTOXTEMPLE 469 // Temple of Bertoxxulous
#define EQ_ZONE_ID_DISCORD 470 // Korafax, Home of the Riders
#define EQ_ZONE_ID_DISCORDTOWER 471 // Citadel of the Worldslayer
#define EQ_ZONE_ID_OLDBLOODFIELD 472 // Old Bloodfields
#define EQ_ZONE_ID_PRECIPICEOFWAR 473 // The Precipice of War
#define EQ_ZONE_ID_OLDDRANIK 474 // City of Dranik
#define EQ_ZONE_ID_TOSKIRAKK 475 // Toskirakk
#define EQ_ZONE_ID_KORASCIAN 476 // Korascian Warrens
#define EQ_ZONE_ID_RATHECHAMBER 477 // Rathe Council Chambers
#define EQ_ZONE_ID_STEAMFONTMTS 448 // Steamfont Mountains
#define EQ_ZONE_ID_CRAFTHALLS 479 // Ngreth's Den
#define EQ_ZONE_ID_BRELLSREST 480 // Brell's Rest
#define EQ_ZONE_ID_FUNGALFOREST 481 // Fungal Forest
#define EQ_ZONE_ID_UNDERQUARRY 482 // The Underquarry
#define EQ_ZONE_ID_COOLINGCHAMBER 483 // The Cooling Chamber
#define EQ_ZONE_ID_SHININGCITY 484 // Kernagir, The Shining City
#define EQ_ZONE_ID_ARTHICREX 485 // Arthicrex
#define EQ_ZONE_ID_FOUNDATION 486 // The Foundation
#define EQ_ZONE_ID_LICHENCREEP 487 // Lichen Creep
#define EQ_ZONE_ID_PELLUCID 488 // Pellucid Grotto
#define EQ_ZONE_ID_STONESNAKE 489 // Volska's Husk
#define EQ_ZONE_ID_BRELLSTEMPLE 490 // Brell's Temple
#define EQ_ZONE_ID_CONVORTEUM 491 // The Convorteum
#define EQ_ZONE_ID_BRELLSARENA 492 // Brell's Arena
#define EQ_ZONE_ID_WEDDINGCHAPEL 493 // Wedding Chapel
#define EQ_ZONE_ID_WEDDINGCHAPELDARK 494 // Wedding Chapel
#define EQ_ZONE_ID_DRAGONCRYPT 495 // Lair of the Fallen
#define EQ_ZONE_ID_FEERROTT2 700 // The Feerrott
#define EQ_ZONE_ID_THULEHOUSE1 701 // House of Thule
#define EQ_ZONE_ID_THULEHOUSE2 702 // House of Thule, Upper Floors
#define EQ_ZONE_ID_HOUSEGARDEN 703 // The Grounds
#define EQ_ZONE_ID_THULELIBRARY 704 // The Library
#define EQ_ZONE_ID_WELL 705 // The Well
#define EQ_ZONE_ID_FALLEN 706 // Erudin Burning
#define EQ_ZONE_ID_MORELLCASTLE 707 // Morell's Castle
#define EQ_ZONE_ID_SOMNIUM 708 // Sanctum Somnium
#define EQ_ZONE_ID_ALKABORMARE 709 // Al'Kabor's Nightmare
#define EQ_ZONE_ID_MIRAGULMARE 710 // Miragul's Nightmare
#define EQ_ZONE_ID_THULEDREAM 711 // Fear Itself
#define EQ_ZONE_ID_NEIGHBORHOOD 712 // Sunrise Hills
#define EQ_ZONE_ID_PHYLACTERY 713 // Miragul's Phylactery
#define EQ_ZONE_ID_PHINTERIOR3A1 714 // House Interior
#define EQ_ZONE_ID_PHINTERIOR3A2 716 // House Interior
#define EQ_ZONE_ID_PHINTERIOR3A3 717 // House Interior
#define EQ_ZONE_ID_PHINTERIOR1A1 715 // House Interior
#define EQ_ZONE_ID_PHINTERIOR1A2 718 // House Interior
#define EQ_ZONE_ID_PHINTERIOR1A3 719 // House Interior
#define EQ_ZONE_ID_PHINTERIOR1A3 719 // House Interior
#define EQ_ZONE_ID_PHINTERIOR1B1 720 // Dragon House Interior
#define EQ_ZONE_ID_PHINTERIOR1D1 723 // Dragon House Interior
#define EQ_ZONE_ID_ARGATH 724 // Argath, Bastion of Illdaera
#define EQ_ZONE_ID_ARELIS 725 // Valley of Lunanyn
#define EQ_ZONE_ID_SARITHCITY 726 // Sarith, City of Tides
#define EQ_ZONE_ID_RUBAK 727 // Rubak Oseka, Temple of the Sea
#define EQ_ZONE_ID_BEASTDOMAIN 728 // Beasts' Domain
#define EQ_ZONE_ID_RESPLENDENT 729 // The Resplendent Temple
#define EQ_ZONE_ID_PILLARSALRA 730 // Pillars of Alra
#define EQ_ZONE_ID_WINDSONG 731 // Windsong Sanctuary
#define EQ_ZONE_ID_CITYOFBRONZE 732 // Erillion, City of Bronze
#define EQ_ZONE_ID_SEPULCHER 733 // Sepulcher of Order
#define EQ_ZONE_ID_EASTSEPULCHER 734 // Sepulcher East
#define EQ_ZONE_ID_WESTSEPULCHER 735 // Sepulcher West
#define EQ_ZONE_ID_SHADOWEDMOUNT 736 // Shadowed Mount
#define EQ_ZONE_ID_GUILDHALLLRG 737 // Grand Guild Hall
#define EQ_ZONE_ID_GUILDHALLSML 738 // Greater Guild Hall
#define EQ_ZONE_ID_PLHOGRINTERIORS1A1 739 // One Bedroom House Interior
#define EQ_ZONE_ID_PLHOGRINTERIORS1A2 740 // One Bedroom House Interior
#define EQ_ZONE_ID_PLHOGRINTERIORS3A1 741 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHOGRINTERIORS3A2 742 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHOGRINTERIORS3B1 743 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHOGRINTERIORS3B2 744 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS1A1 745 // One Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS1A2 746 // One Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS1A3 747 // One Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS3A1 748 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS3A2 749 // Three Bedroom House Interior
#define EQ_ZONE_ID_PLHDKEINTERIORS3A3 750 // Three Bedroom House Interior
#define EQ_ZONE_ID_GUILDHALL3 751 // Modest Guild Hall
#define EQ_ZONE_ID_KAELSHARD 754 // Kael Drakkel: The King's Madness
#define EQ_ZONE_ID_CRYSTALSHARD 756 // The Crystal Caverns: Fragment of Fear
#define EQ_ZONE_ID_SHARDSLANDING 752 // Shard's Landing
#define EQ_ZONE_ID_XORBB 753 // Valley of King Xorbb
#define EQ_ZONE_ID_BREEDINGGROUNDS 757 // The Breeding Grounds
#define EQ_ZONE_ID_EVILTREE 758 // Evantil, the Vile Oak
#define EQ_ZONE_ID_GRELLETH 759 // Grelleth's Palace, the Chateau of Filth
#define EQ_ZONE_ID_CHAPTERHOUSE 760 // Chapterhouse of the Fallen
#define EQ_ZONE_ID_PHINTERIORTREE 766 // Evantil's Abode
#define EQ_ZONE_ID_CHELSITHREBORN 763 // Chelsith Reborn
#define EQ_ZONE_ID_POSHADOW 764 // Plane of Shadow
#define EQ_ZONE_ID_HEARTOFFEAR 765 // Heart of Fear: The Threshold
#define EQ_ZONE_ID_HEARTOFFEARB 768 // Heart of Fear: The Rebirth
#define EQ_ZONE_ID_HEARTOFFEARC 769 // Heart of Fear: The Epicenter
#define EQ_ZONE_ID_NERIAKD 43 // Neriak - Fourth Gate
#define EQ_ZONE_ID_BIXIEWARFRONT 770 // Bixie Warfront
#define EQ_ZONE_ID_DEADHILLS 771 // The Dead Hills
#define EQ_ZONE_ID_ETHERNERE 772 // Ethernere Tainted West Karana
#define EQ_ZONE_ID_THEVOIDH 773 // The Void
#define EQ_ZONE_ID_PLHBIXIEINT 774 // Bixie Hive
#define EQ_ZONE_ID_TOWEROFROT 775 // Tower of Rot
#define EQ_ZONE_ID_ARGINHIZ 776 // Argin-Hiz
#define EQ_ZONE_ID_ARXMENTIS 778 // Arx Mentis
#define EQ_ZONE_ID_BROTHERISLAND 779 // Brother Island
#define EQ_ZONE_ID_KATTACASTRUMB 780 // Katta Castrum: Deluge
#define EQ_ZONE_ID_DREDGE 781 // Combine Dredge
#define EQ_ZONE_ID_ENDLESSCAVERNS 782 // Caverns of Endless Song
#define EQ_ZONE_ID_THULIASAUR 783 // Thuliasaur Island
#define EQ_ZONE_ID_DEGMAR 784 // Degmar, the Lost Castle
#define EQ_ZONE_ID_TEMPESTTEMPLE 785 // Tempest Temple
#define EQ_ZONE_ID_PLHPIRATESHIPINT 786 // Pirate Ship
#define EQ_ZONE_ID_EXALTED 777 // Sul Vius: Demiplane of Life
#define EQ_ZONE_ID_COSUL 795 // Crypt of Sul
#define EQ_ZONE_ID_CODECAYB 796 // Ruins of Lxanvom
#define EQ_ZONE_ID_EXALTEDB 797 // Sul Vius: Demiplane of Decay
#define EQ_ZONE_ID_POHEALTH 798 // The Plane of Health
#define EQ_ZONE_ID_DROGAB 788 // The Temple of Droga
#define EQ_ZONE_ID_SCORCHEDWOODS 790 // Scorched Woods
#define EQ_ZONE_ID_FRONTIERMTNSB 791 // Frontier Mountains
#define EQ_ZONE_ID_KORSHAEXT 793 // Gates of Kor-Sha
#define EQ_ZONE_ID_KORSHAINT 799 // Kor-Sha Laboratory
#define EQ_ZONE_ID_LCEANIUM 794 // Lceanium
#define EQ_ZONE_ID_CHARDOKTWO 800 // Chardok
#define EQ_ZONE_ID_CHARASISB 789 // Sathir's Tomb
#define EQ_ZONE_ID_GOROWYN 792 // Gorowyn
#define EQ_ZONE_ID_CHARASISTWO 813 // Howling Stones
#define EQ_ZONE_ID_SKYFIRETWO 814 // Skyfire Mountains
#define EQ_ZONE_ID_OVERTHERETWO 815 // The Overthere
#define EQ_ZONE_ID_VEESHANTWO 816 // Veeshan's Peak
#define EQ_ZONE_ID_TRIALSOFSMOKE 817 // Trials of Smoke
#define EQ_ZONE_ID_STRATOS 818 // Stratos: Zephyr's Flight
#define EQ_ZONE_ID_AALISHAI 819 // Aalishai: Palace of Embers
#define EQ_ZONE_ID_EMPYR 820 // Empyr: Realms of Ash
#define EQ_ZONE_ID_ESIANTI 821 // Esianti: Palace of the Winds
#define EQ_ZONE_ID_MEARATAS 822 // Mearatas: The Stone Demesne
#define EQ_ZONE_ID_CHAMBEROFTEARS 823 // The Chamber of Tears
#define EQ_ZONE_ID_CLZ_ANNIVERSARY 825 // Loading
#define EQ_ZONE_ID_CLZ_AUTUMN 827 // Loading
#define EQ_ZONE_ID_CLZ_FROSTFELL 828 // Loading
#define EQ_ZONE_ID_CLZ_SPRING 826 // Loading
#define EQ_ZONE_ID_CLZ_WINTER 824 // Loading
#define EQ_ZONE_ID_POMISCHIEF 761 // The Plane of Mischief
#define EQ_ZONE_ID_BURNEDWOODS 762 // The Burned Woods
#define EQ_ZONE_ID_INTERIORWALLTEST 767 // Wall Wall Wall
#define EQ_ZONE_ID_GNOMEMTN 787 // Gnome Memorial Mountain

std::unordered_map<uint32_t, std::string> EQ_ZONE_ID_LongName_Strings =
{
    {EQ_ZONE_ID_QEYNOS, "South Qeynos"},
    {EQ_ZONE_ID_QEYNOS2, "North Qeynos"},
    {EQ_ZONE_ID_QRG, "Surefall Glade"},
    {EQ_ZONE_ID_QEYTOQRG, "Qeynos Hills"},
    {EQ_ZONE_ID_HIGHKEEP, "High Keep"},
    {EQ_ZONE_ID_FREPORTN, "North Freeport"},
    {EQ_ZONE_ID_FREPORTW, "West Freeport"},
    {EQ_ZONE_ID_FREPORTE, "East Freeport"},
    {EQ_ZONE_ID_RUNNYEYE, "Clan Runnyeye"},
    {EQ_ZONE_ID_QEY2HH1, "West Karana"},
    {EQ_ZONE_ID_NORTHKARANA, "North Karana"},
    {EQ_ZONE_ID_SOUTHKARANA, "South Karana"},
    {EQ_ZONE_ID_EASTKARANA, "East Karana"},
    {EQ_ZONE_ID_BEHOLDER, "Gorge of King Xorbb"},
    {EQ_ZONE_ID_BLACKBURROW, "BlackBurrow"},
    {EQ_ZONE_ID_PAW, "Infected Paw"},
    {EQ_ZONE_ID_RIVERVALE, "Rivervale"},
    {EQ_ZONE_ID_KITHICOR, "Kithicor Forest"},
    {EQ_ZONE_ID_COMMONS, "West Commonlands"},
    {EQ_ZONE_ID_ECOMMONS, "East Commonlands"},
    {EQ_ZONE_ID_COMMONLANDS, "Commonlands"},
    {EQ_ZONE_ID_OCEANOFTEARS, "Ocean of Tears"},
    {EQ_ZONE_ID_KITHFOREST, "Kithicor Forest"},
    {EQ_ZONE_ID_BEFALLENB, "Befallen"},
    {EQ_ZONE_ID_HIGHPASSKEEP, "High Keep"},
    {EQ_ZONE_ID_INNOTHULEB, "Innothule Swamp"},
    {EQ_ZONE_ID_TOXXULIA, "Toxxulia Forest"},
    {EQ_ZONE_ID_MISTYTHICKET, "Misty Thicket"},
    {EQ_ZONE_ID_ERUDNINT, "Erudin Palace"},
    {EQ_ZONE_ID_ERUDNEXT, "Erudin"},
    {EQ_ZONE_ID_NEKTULOS, "Nektulos Forest"},
    {EQ_ZONE_ID_CSHOME, "Sunset Home"},
    {EQ_ZONE_ID_LAVASTORM, "Lavastorm Mountains"},
    {EQ_ZONE_ID_NEKTROPOS, "Nektropos"},
    {EQ_ZONE_ID_HALAS, "Halas"},
    {EQ_ZONE_ID_EVERFROST, "Everfrost Peaks"},
    {EQ_ZONE_ID_SOLDUNGA, "Solusek's Eye"},
    {EQ_ZONE_ID_SOLDUNGB, "Nagafen's Lair"},
    {EQ_ZONE_ID_MISTY, "Misty Thicket"},
    {EQ_ZONE_ID_NRO, "North Ro"},
    {EQ_ZONE_ID_SRO, "South Ro"},
    {EQ_ZONE_ID_BEFALLEN, "Befallen"},
    {EQ_ZONE_ID_OASIS, "Oasis of Marr"},
    {EQ_ZONE_ID_TOX, "Toxxulia Forest"},
    {EQ_ZONE_ID_HOLE, "The Ruins of Old Paineel"},
    {EQ_ZONE_ID_NERIAKA, "Neriak - Foreign Quarter"},
    {EQ_ZONE_ID_NERIAKB, "Neriak - Commons"},
    {EQ_ZONE_ID_NERIAKC, "Neriak - Third Gate"},
    {EQ_ZONE_ID_NAJENA, "Najena"},
    {EQ_ZONE_ID_QCAT, "Qeynos Catacombs"},
    {EQ_ZONE_ID_INNOTHULE, "Innothule Swamp"},
    {EQ_ZONE_ID_FEERROTT, "The Feerrott"},
    {EQ_ZONE_ID_CAZICTHULE, "Cazic-Thule"},
    {EQ_ZONE_ID_OGGOK, "Oggok"},
    {EQ_ZONE_ID_RATHEMTN, "Mountains of Rathe"},
    {EQ_ZONE_ID_LAKERATHE, "Lake Rathetear"},
    {EQ_ZONE_ID_GROBB, "Grobb"},
    {EQ_ZONE_ID_AVIAK, "Aviak Village"},
    {EQ_ZONE_ID_GFAYDARK, "Greater Faydark"},
    {EQ_ZONE_ID_AKANON, "Ak'Anon"},
    {EQ_ZONE_ID_STEAMFONT, "Steamfont Mountains"},
    {EQ_ZONE_ID_LFAYDARK, "Lesser Faydark"},
    {EQ_ZONE_ID_CRUSHBONE, "Clan Crushbone"},
    {EQ_ZONE_ID_MISTMOORE, "Castle Mistmoore"},
    {EQ_ZONE_ID_KALADIMA, "Kaladim"},
    {EQ_ZONE_ID_FELWITHEA, "Felwithe"},
    {EQ_ZONE_ID_FELWITHEB, "Felwithe"},
    {EQ_ZONE_ID_UNREST, "Estate of Unrest"},
    {EQ_ZONE_ID_KEDGE, "Kedge Keep"},
    {EQ_ZONE_ID_GUKTOP, "Upper Guk"},
    {EQ_ZONE_ID_GUKBOTTOM, "Lower Guk"},
    {EQ_ZONE_ID_KALADIMB, "Kaladim"},
    {EQ_ZONE_ID_BUTCHER, "Butcherblock Mountains"},
    {EQ_ZONE_ID_OOT, "Ocean of Tears"},
    {EQ_ZONE_ID_CAULDRON, "Dagnor's Cauldron"},
    {EQ_ZONE_ID_AIRPLANE, "Plane of Sky"},
    {EQ_ZONE_ID_FEARPLANE, "Plane of Fear"},
    {EQ_ZONE_ID_PERMAFROST, "Permafrost Keep"},
    {EQ_ZONE_ID_KERRARIDGE, "Kerra Isle"},
    {EQ_ZONE_ID_PAINEEL, "Paineel"},
    {EQ_ZONE_ID_HATEPLANE, "The Plane of Hate"},
    {EQ_ZONE_ID_ARENA, "The Arena"},
    {EQ_ZONE_ID_FIELDOFBONE, "The Field of Bone"},
    {EQ_ZONE_ID_WARSLIKSWOOD, "Warsliks Woods"},
    {EQ_ZONE_ID_SOLTEMPLE, "Temple of Solusek Ro"},
    {EQ_ZONE_ID_DROGA, "Temple of Droga"},
    {EQ_ZONE_ID_CABWEST, "West Cabilis"},
    {EQ_ZONE_ID_SWAMPOFNOHOPE, "Swamp of No Hope"},
    {EQ_ZONE_ID_FIRIONA, "Firiona Vie"},
    {EQ_ZONE_ID_LAKEOFILLOMEN, "Lake of Ill Omen"},
    {EQ_ZONE_ID_DREADLANDS, "Dreadlands"},
    {EQ_ZONE_ID_BURNINGWOOD, "Burning Woods"},
    {EQ_ZONE_ID_KAESORA, "Kaesora"},
    {EQ_ZONE_ID_SEBILIS, "Old Sebilis"},
    {EQ_ZONE_ID_CITYMIST, "City of Mist"},
    {EQ_ZONE_ID_SKYFIRE, "Skyfire Mountains"},
    {EQ_ZONE_ID_FRONTIERMTNS, "Frontier Mountains"},
    {EQ_ZONE_ID_OVERTHERE, "The Overthere"},
    {EQ_ZONE_ID_EMERALDJUNGLE, "The Emerald Jungle"},
    {EQ_ZONE_ID_TRAKANON, "Trakanon's Teeth"},
    {EQ_ZONE_ID_TIMOROUS, "Timorous Deep"},
    {EQ_ZONE_ID_KURN, "Kurn's Tower"},
    {EQ_ZONE_ID_ERUDSXING, "Erud's Crossing"},
    {EQ_ZONE_ID_STONEBRUNT, "Stonebrunt Mountains"},
    {EQ_ZONE_ID_WARRENS, "The Warrens"},
    {EQ_ZONE_ID_KARNOR, "Karnor's Castle"},
    {EQ_ZONE_ID_CHARDOK, "Chardok"},
    {EQ_ZONE_ID_DALNIR, "Dalnir"},
    {EQ_ZONE_ID_CHARASIS, "Howling Stones"},
    {EQ_ZONE_ID_CABEAST, "East Cabilis"},
    {EQ_ZONE_ID_NURGA, "Mines of Nurga"},
    {EQ_ZONE_ID_VEESHAN, "Veeshan's Peak"},
    {EQ_ZONE_ID_VEKSAR, "Veksar"},
    {EQ_ZONE_ID_ICECLAD, "Iceclad Ocean"},
    {EQ_ZONE_ID_FROZENSHADOW, "Tower of Frozen Shadow"},
    {EQ_ZONE_ID_VELKETOR, "Velketor's Labyrinth"},
    {EQ_ZONE_ID_KAEL, "Kael Drakkel"},
    {EQ_ZONE_ID_SKYSHRINE, "Skyshrine"},
    {EQ_ZONE_ID_THURGADINA, "Thurgadin"},
    {EQ_ZONE_ID_EASTWASTES, "Eastern Wastes"},
    {EQ_ZONE_ID_COBALTSCAR, "Cobalt Scar"},
    {EQ_ZONE_ID_GREATDIVIDE, "Great Divide"},
    {EQ_ZONE_ID_WAKENING, "The Wakening Land"},
    {EQ_ZONE_ID_WESTWASTES, "Western Wastes"},
    {EQ_ZONE_ID_CRYSTAL, "Crystal Caverns"},
    {EQ_ZONE_ID_NECROPOLIS, "Dragon Necropolis"},
    {EQ_ZONE_ID_TEMPLEVEESHAN, "Temple of Veeshan"},
    {EQ_ZONE_ID_SIRENS, "Siren's Grotto"},
    {EQ_ZONE_ID_MISCHIEFPLANE, "Plane of Mischief"},
    {EQ_ZONE_ID_GROWTHPLANE, "Plane of Growth"},
    {EQ_ZONE_ID_SLEEPER, "Sleeper's Tomb"},
    {EQ_ZONE_ID_THURGADINB, "Icewell Keep"},
    {EQ_ZONE_ID_ERUDSXING2, "Marauder's Mire"},
    {EQ_ZONE_ID_SHADOWHAVEN, "Shadow Haven"},
    {EQ_ZONE_ID_BAZAAR, "The Bazaar"},
    {EQ_ZONE_ID_NEXUS, "The Nexus"},
    {EQ_ZONE_ID_ECHO, "Echo Caverns"},
    {EQ_ZONE_ID_ACRYLIA, "Acrylia Caverns"},
    {EQ_ZONE_ID_SHARVAHL, "Shar Vahl"},
    {EQ_ZONE_ID_PALUDAL, "Paludal Caverns"},
    {EQ_ZONE_ID_FUNGUSGROVE, "Fungus Grove"},
    {EQ_ZONE_ID_VEXTHAL, "Vex Thal"},
    {EQ_ZONE_ID_SSERU, "Sanctus Seru"},
    {EQ_ZONE_ID_KATTA, "Katta Castellum"},
    {EQ_ZONE_ID_NETHERBIAN, "Netherbian Lair"},
    {EQ_ZONE_ID_SSRATEMPLE, "Ssraeshza Temple"},
    {EQ_ZONE_ID_GRIEGSEND, "Grieg's End"},
    {EQ_ZONE_ID_THEDEEP, "The Deep"},
    {EQ_ZONE_ID_SHADEWEAVER, "Shadeweaver's Thicket"},
    {EQ_ZONE_ID_HOLLOWSHADE, "Hollowshade Moor"},
    {EQ_ZONE_ID_GRIMLING, "Grimling Forest"},
    {EQ_ZONE_ID_MSERU, "Marus Seru"},
    {EQ_ZONE_ID_LETALIS, "Mons Letalis"},
    {EQ_ZONE_ID_TWILIGHT, "The Twilight Sea"},
    {EQ_ZONE_ID_THEGREY, "The Grey"},
    {EQ_ZONE_ID_TENEBROUS, "The Tenebrous Mountains"},
    {EQ_ZONE_ID_MAIDEN, "The Maiden's Eye"},
    {EQ_ZONE_ID_DAWNSHROUD, "Dawnshroud Peaks"},
    {EQ_ZONE_ID_SCARLET, "The Scarlet Desert"},
    {EQ_ZONE_ID_UMBRAL, "The Umbral Plains"},
    {EQ_ZONE_ID_AKHEVA, "Akheva Ruins"},
    {EQ_ZONE_ID_ARENA2, "The Arena"},
    {EQ_ZONE_ID_JAGGEDPINE, "The Jaggedpine Forest"},
    {EQ_ZONE_ID_NEDARIA, "Nedaria's Landing"},
    {EQ_ZONE_ID_SHADOWREST, "Shadowrest"},
    {EQ_ZONE_ID_TUTORIAL, "Tutorial Zone"},
    {EQ_ZONE_ID_TUTORIALA, "The Mines of Gloomingdeep"},
    {EQ_ZONE_ID_TUTORIALB, "The Mines of Gloomingdeep"},
    {EQ_ZONE_ID_CLZ, "Loading"},
    {EQ_ZONE_ID_LOAD, "Loading"},
    {EQ_ZONE_ID_LOAD2, "Loading"},
    {EQ_ZONE_ID_ARTTEST, "Art Testing Domain"},
    {EQ_ZONE_ID_APPRENTICE, "Designer Apprentice"},
    {EQ_ZONE_ID_POKNOWLEDGE, "Plane of Knowledge"},
    {EQ_ZONE_ID_POTRANQUILITY, "Plane of Tranquility"},
    {EQ_ZONE_ID_CODECAY, "Ruins of Lxanvom"},
    {EQ_ZONE_ID_POJUSTICE, "Plane of Justice"},
    {EQ_ZONE_ID_PONIGHTMARE, "Plane of Nightmare"},
    {EQ_ZONE_ID_NIGHTMAREB, "Lair of Terris Thule"},
    {EQ_ZONE_ID_PODISEASE, "Plane of Disease"},
    {EQ_ZONE_ID_POINNOVATION, "Plane of Innovation"},
    {EQ_ZONE_ID_POTORMENT, "Plane of Torment"},
    {EQ_ZONE_ID_POVALOR, "Plane of Valor"},
    {EQ_ZONE_ID_BOTHUNDER, "Torden, The Bastion of Thunder"},
    {EQ_ZONE_ID_POSTORMS, "Plane of Storms"},
    {EQ_ZONE_ID_HOHONORA, "Halls of Honor"},
    {EQ_ZONE_ID_HOHONORB, "Temple of Marr"},
    {EQ_ZONE_ID_SOLROTOWER, "Solusek Ro's Tower"},
    {EQ_ZONE_ID_POWAR, "Plane of War"},
    {EQ_ZONE_ID_POTACTICS, "Drunder, Fortress of Zek"},
    {EQ_ZONE_ID_POAIR, "Eryslai, the Kingdom of Wind"},
    {EQ_ZONE_ID_POWATER, "Reef of Coirnav"},
    {EQ_ZONE_ID_POFIRE, "Doomfire, The Burning Lands"},
    {EQ_ZONE_ID_POEARTHA, "Vegarlson, The Earthen Badlands"},
    {EQ_ZONE_ID_POEARTHB, "Stronghold of the Twelve"},
    {EQ_ZONE_ID_POTIMEA, "Plane of Time"},
    {EQ_ZONE_ID_POTIMEB, "Plane of Time"},
    {EQ_ZONE_ID_TORGIRAN, "Torgiran Mines"},
    {EQ_ZONE_ID_NADOX, "Crypt of Nadox"},
    {EQ_ZONE_ID_GUNTHAK, "Gulf of Gunthak"},
    {EQ_ZONE_ID_DULAK, "Dulak's Harbor"},
    {EQ_ZONE_ID_HATESFURY, "Hate's Fury, The Scorned Maiden"},
    {EQ_ZONE_ID_HATEPLANEB, "The Plane of Hate"},
    {EQ_ZONE_ID_CHARDOKB, "The Halls of Betrayal"},
    {EQ_ZONE_ID_SOLDUNGC, "The Caverns of Exile"},
    {EQ_ZONE_ID_GUKA, "The Cauldron of Lost Souls"},
    {EQ_ZONE_ID_RUJA, "The Bloodied Quarries"},
    {EQ_ZONE_ID_TAKA, "The Sunken Library"},
    {EQ_ZONE_ID_MIRA, "The Silent Gallery"},
    {EQ_ZONE_ID_MMCA, "The Forlorn Caverns"},
    {EQ_ZONE_ID_GUKB, "The Drowning Crypt"},
    {EQ_ZONE_ID_RUJB, "The Halls of War"},
    {EQ_ZONE_ID_TAKB, "The Shifting Tower"},
    {EQ_ZONE_ID_MIRB, "The Maw of the Menagerie"},
    {EQ_ZONE_ID_MMCB, "The Dreary Grotto"},
    {EQ_ZONE_ID_GUKC, "The Ancient Aqueducts"},
    {EQ_ZONE_ID_RUJC, "The Wind Bridges"},
    {EQ_ZONE_ID_TAKC, "The Fading Temple"},
    {EQ_ZONE_ID_MIRC, "The Spider Den"},
    {EQ_ZONE_ID_MMCC, "The Asylum of Invoked Stone"},
    {EQ_ZONE_ID_GUKD, "The Mushroom Grove"},
    {EQ_ZONE_ID_RUJD, "The Gladiator Pits"},
    {EQ_ZONE_ID_TAKD, "The Royal Observatory"},
    {EQ_ZONE_ID_MIRD, "The Hushed Banquet"},
    {EQ_ZONE_ID_MMCD, "The Chambers of Eternal Affliction"},
    {EQ_ZONE_ID_GUKE, "The Foreboding Prison"},
    {EQ_ZONE_ID_RUJE, "The Drudge Hollows"},
    {EQ_ZONE_ID_TAKE, "The River of Recollection"},
    {EQ_ZONE_ID_MIRE, "The Frosted Halls"},
    {EQ_ZONE_ID_MMCE, "The Sepulcher of the Damned"},
    {EQ_ZONE_ID_GUKF, "The Chapel of the Witnesses"},
    {EQ_ZONE_ID_RUJF, "The Fortified Lair of the Taskmasters"},
    {EQ_ZONE_ID_TAKF, "The Sandfall Corridors"},
    {EQ_ZONE_ID_MIRF, "The Forgotten Wastes"},
    {EQ_ZONE_ID_MMCF, "The Ritualistic Summoning Grounds"},
    {EQ_ZONE_ID_GUKG, "The Root Garden"},
    {EQ_ZONE_ID_RUJG, "The Hidden Vale"},
    {EQ_ZONE_ID_TAKG, "The Balancing Chamber"},
    {EQ_ZONE_ID_MIRG, "The Heart of the Menagerie"},
    {EQ_ZONE_ID_MMCG, "The Cesspits of Putrescence"},
    {EQ_ZONE_ID_GUKH, "The Accursed Sanctuary"},
    {EQ_ZONE_ID_RUJH, "The Blazing Forge"},
    {EQ_ZONE_ID_TAKH, "The Sweeping Tides"},
    {EQ_ZONE_ID_MIRH, "The Morbid Laboratory"},
    {EQ_ZONE_ID_MMCH, "The Aisles of Blood"},
    {EQ_ZONE_ID_RUJI, "The Arena of Chance"},
    {EQ_ZONE_ID_TAKI, "The Antiquated Palace"},
    {EQ_ZONE_ID_MIRI, "The Theater of Imprisoned Horrors"},
    {EQ_ZONE_ID_MMCI, "The Halls of Sanguinary Rites"},
    {EQ_ZONE_ID_RUJJ, "The Barracks of War"},
    {EQ_ZONE_ID_TAKJ, "The Prismatic Corridors"},
    {EQ_ZONE_ID_MIRJ, "The Grand Library"},
    {EQ_ZONE_ID_MMCJ, "The Infernal Sanctuary"},
    {EQ_ZONE_ID_ARENA, "The Arena"},
    {EQ_ZONE_ID_ABYSMAL, "Abysmal Sea"},
    {EQ_ZONE_ID_NATIMBI, "Natimbi, The Broken Shores"},
    {EQ_ZONE_ID_QINIMI, "Qinimi, Court of Nihilia"},
    {EQ_ZONE_ID_RIWWI, "Riwwi, Coliseum of Games"},
    {EQ_ZONE_ID_BARINDU, "Barindu, Hanging Gardens"},
    {EQ_ZONE_ID_SNPOOL, "Sewers of Nihilia, Pool of Sludge"},
    {EQ_ZONE_ID_TIPT, "Tipt, Treacherous Crags"},
    {EQ_ZONE_ID_VXED, "Vxed, The Crumbling Caverns"},
    {EQ_ZONE_ID_YXTTA, "Yxtta, Pulpit of Exiles"},
    {EQ_ZONE_ID_UQUA, "Uqua, The Ocean God Chantry"},
    {EQ_ZONE_ID_KODTAZ, "Kod'Taz, Broken Trial Grounds"},
    {EQ_ZONE_ID_IKKINZ, "Ikkinz, Chambers of Destruction"},
    {EQ_ZONE_ID_INKTUTA, "Inktu`Ta, The Unmasked Chapel"},
    {EQ_ZONE_ID_TXEVU, "Txevu, Lair of the Elite"},
    {EQ_ZONE_ID_TACVI, "Tacvi, Seat of the Slaver"},
    {EQ_ZONE_ID_QVIC, "Qvic, Prayer Grounds of Calling"},
    {EQ_ZONE_ID_QVICB, "Qvic, the Hidden Vault"},
    {EQ_ZONE_ID_WALLOFSLAUGHTER, "Wall of Slaughter"},
    {EQ_ZONE_ID_BLOODFIELDS, "The Bloodfields"},
    {EQ_ZONE_ID_DRANIKSSCAR, "Dranik's Scar"},
    {EQ_ZONE_ID_CAUSEWAY, "Nobles' Causeway"},
    {EQ_ZONE_ID_CHAMBERSA, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_CHAMBERSB, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_CHAMBERSC, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_CHAMBERSD, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_CHAMBERSE, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_CHAMBERSF, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_PROVINGGROUNDS, "Muramite Proving Grounds"},
    {EQ_ZONE_ID_ANGUISH, "Anguish, the Fallen Palace"},
    {EQ_ZONE_ID_DRANIKHOLLOWSA, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSB, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSC, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSD, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSE, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSF, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSG, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSH, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSI, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKHOLLOWSJ, "Dranik's Hollows"},
    {EQ_ZONE_ID_DRANIKCATACOMBSA, "Catacombs of Dranik"},
    {EQ_ZONE_ID_DRANIKCATACOMBSB, "Catacombs of Dranik"},
    {EQ_ZONE_ID_DRANIKCATACOMBSC, "Catacombs of Dranik"},
    {EQ_ZONE_ID_DRANIKSEWERSA, "Sewers of Dranik"},
    {EQ_ZONE_ID_DRANIKSEWERSB, "Sewers of Dranik"},
    {EQ_ZONE_ID_DRANIKSEWERSC, "Sewers of Dranik"},
    {EQ_ZONE_ID_RIFTSEEKERS, "Riftseekers' Sanctum"},
    {EQ_ZONE_ID_HARBINGERS, "Harbingers' Spire"},
    {EQ_ZONE_ID_DRANIK, "The Ruined City of Dranik"},
    {EQ_ZONE_ID_FHALLS, "The Forgotten Halls"},
    {EQ_ZONE_ID_BROODLANDS, "The Broodlands"},
    {EQ_ZONE_ID_STILLMOONA, "Stillmoon Temple"},
    {EQ_ZONE_ID_STILLMOONB, "The Ascent"},
    {EQ_ZONE_ID_THUNDERCREST, "Thundercrest Isles"},
    {EQ_ZONE_ID_DELVEA, "Lavaspinner's Lair"},
    {EQ_ZONE_ID_DELVEB, "Tirranun's Delve"},
    {EQ_ZONE_ID_THENEST, "The Accursed Nest"},
    {EQ_ZONE_ID_GUILDLOBBY, "The Guild Lobby"},
    {EQ_ZONE_ID_GUILDHALL, "Guild Hall"},
    {EQ_ZONE_ID_BARTER, "The Barter Hall"},
    {EQ_ZONE_ID_ILLSALIN, "Ruins of Illsalin"},
    {EQ_ZONE_ID_ILLSALINA, "Imperial Bazaar"},
    {EQ_ZONE_ID_ILLSALINB, "Temple of the Korlach"},
    {EQ_ZONE_ID_ILLSALINC, "The Nargilor Pits"},
    {EQ_ZONE_ID_DREADSPIRE, "Dreadspire Keep"},
    {EQ_ZONE_ID_DRACHNIDHIVE, "The Hive"},
    {EQ_ZONE_ID_DRACHNIDHIVEA, "Living Larder"},
    {EQ_ZONE_ID_DRACHNIDHIVEB, "Coven of the Skinwalkers"},
    {EQ_ZONE_ID_DRACHNIDHIVEC, "Queen Sendaii's Lair"},
    {EQ_ZONE_ID_WESTKORLACH, "Stoneroot Falls"},
    {EQ_ZONE_ID_WESTKORLACHA, "Chambers of Xill"},
    {EQ_ZONE_ID_WESTKORLACHB, "Caverns of the Lost"},
    {EQ_ZONE_ID_WESTKORLACHC, "Lair of the Korlach"},
    {EQ_ZONE_ID_EASTKORLACH, "Undershore"},
    {EQ_ZONE_ID_EASTKORLACHA, "Snarlstone Dens"},
    {EQ_ZONE_ID_SHADOWSPINE, "Shadowspine"},
    {EQ_ZONE_ID_CORATHUS, "Corathus Creep"},
    {EQ_ZONE_ID_CORATHUSA, "Sporali Caverns"},
    {EQ_ZONE_ID_CORATHUSB, "Corathus Lair"},
    {EQ_ZONE_ID_NEKTULOSA, "Shadowed Grove"},
    {EQ_ZONE_ID_ARCSTONE, "Arcstone"},
    {EQ_ZONE_ID_RELIC, "Relic"},
    {EQ_ZONE_ID_SKYLANCE, "Skylance"},
    {EQ_ZONE_ID_DEVASTATION, "The Devastation"},
    {EQ_ZONE_ID_DEVASTATIONA, "The Seething Wall"},
    {EQ_ZONE_ID_RAGE, "Sverag, Stronghold of Rage"},
    {EQ_ZONE_ID_RAGEA, "Razorthorn, Tower of Sullon Zek"},
    {EQ_ZONE_ID_TAKISHRUINS, "Ruins of Takish-Hiz"},
    {EQ_ZONE_ID_TAKISHRUINSA, "The Root of Ro"},
    {EQ_ZONE_ID_ELDDAR, "The Elddar Forest"},
    {EQ_ZONE_ID_ELDDARA, "Tunare's Shrine"},
    {EQ_ZONE_ID_THEATER, "Theater of Blood"},
    {EQ_ZONE_ID_THEATERA, "Deathknell, Tower of Dissonance"},
    {EQ_ZONE_ID_FREEPORTEAST, "East Freeport"},
    {EQ_ZONE_ID_FREEPORTWEST, "West Freeport"},
    {EQ_ZONE_ID_FREEPORTSEWERS, "Freeport Sewers"},
    {EQ_ZONE_ID_FREEPORTACADEMY, "Academy of Arcane Sciences"},
    {EQ_ZONE_ID_FREEPORTTEMPLE, "Temple of Marr"},
    {EQ_ZONE_ID_FREEPORTMILITIA, "Freeport Militia House"},
    {EQ_ZONE_ID_FREEPORTARENA, "Arena"},
    {EQ_ZONE_ID_FREEPORTCITYHALL, "City Hall"},
    {EQ_ZONE_ID_FREEPORTTHEATER, "Theater"},
    {EQ_ZONE_ID_FREEPORTHALL, "Hall of Truth"},
    {EQ_ZONE_ID_NORTHRO, "North Ro"},
    {EQ_ZONE_ID_SOUTHRO, "South Ro"},
    {EQ_ZONE_ID_CRESCENT, "Crescent Reach"},
    {EQ_ZONE_ID_MOORS, "Blightfire Moors"},
    {EQ_ZONE_ID_STONEHIVE, "Stone Hive"},
    {EQ_ZONE_ID_MESA, "Goru`kar Mesa"},
    {EQ_ZONE_ID_ROOST, "Blackfeather Roost"},
    {EQ_ZONE_ID_STEPPES, "The Steppes"},
    {EQ_ZONE_ID_ICEFALL, "Icefall Glacier"},
    {EQ_ZONE_ID_VALDEHOLM, "Valdeholm"},
    {EQ_ZONE_ID_SUNDEROCK, "Sunderock Springs"},
    {EQ_ZONE_ID_VERGALID, "Vergalid Mines"},
    {EQ_ZONE_ID_DIREWIND, "Direwind Cliffs"},
    {EQ_ZONE_ID_ASHENGATE, "Ashengate, Reliquary of the Scale"},
    {EQ_ZONE_ID_HIGHPASSHOLD, "Highpass Hold"},
    {EQ_ZONE_ID_KATTACASTRUM, "Katta Castrum"},
    {EQ_ZONE_ID_THALASSIUS, "Thalassius, the Coral Keep"},
    {EQ_ZONE_ID_ATIIKI, "Jewel of Atiiki"},
    {EQ_ZONE_ID_ZHISZA, "Zhisza, the Shissar Sanctuary"},
    {EQ_ZONE_ID_SILYSSAR, "Silyssar, New Chelsith"},
    {EQ_ZONE_ID_SOLTERIS, "Solteris, the Throne of Ro"},
    {EQ_ZONE_ID_BARREN, "Barren Coast"},
    {EQ_ZONE_ID_BURIEDSEA, "The Buried Sea"},
    {EQ_ZONE_ID_JARDELSHOOK, "Jardel's Hook"},
    {EQ_ZONE_ID_MONKEYROCK, "Monkey Rock"},
    {EQ_ZONE_ID_SUNCREST, "Suncrest Isle"},
    {EQ_ZONE_ID_DEADBONE, "Deadbone Reef"},
    {EQ_ZONE_ID_BLACKSAIL, "Blacksail Folly"},
    {EQ_ZONE_ID_MAIDENSGRAVE, "Maiden's Grave"},
    {EQ_ZONE_ID_REDFEATHER, "Redfeather Isle"},
    {EQ_ZONE_ID_SHIPMVP, "The Open Sea"},
    {EQ_ZONE_ID_SHIPMVU, "The Open Sea"},
    {EQ_ZONE_ID_SHIPPVU, "The Open Sea"},
    {EQ_ZONE_ID_SHIPUVU, "The Open Sea"},
    {EQ_ZONE_ID_SHIPMVM, "The Open Sea"},
    {EQ_ZONE_ID_MECHANOTUS, "Fortress Mechanotus"},
    {EQ_ZONE_ID_MANSION, "Meldrath's Majestic Mansion"},
    {EQ_ZONE_ID_STEAMFACTORY, "The Steam Factory"},
    {EQ_ZONE_ID_SHIPWORKSHOP, "S.H.I.P. Workshop"},
    {EQ_ZONE_ID_GYROSPIREB, "Gyrospire Beza"},
    {EQ_ZONE_ID_GYROSPIREZ, "Gyrospire Zeka"},
    {EQ_ZONE_ID_DRAGONSCALE, "Dragonscale Hills"},
    {EQ_ZONE_ID_LOPINGPLAINS, "Loping Plains"},
    {EQ_ZONE_ID_HILLSOFSHADE, "Hills of Shade"},
    {EQ_ZONE_ID_BLOODMOON, "Bloodmoon Keep"},
    {EQ_ZONE_ID_CRYSTALLOS, "Crystallos, Lair of the Awakened"},
    {EQ_ZONE_ID_GUARDIAN, "The Mechamatic Guardian"},
    {EQ_ZONE_ID_CRYPTOFSHADE, "Crypt of Shade"},
    {EQ_ZONE_ID_DRAGONSCALEA, "Tinmizer's Wunderwerks"},
    {EQ_ZONE_ID_DRAGONSCALEB, "Deepscar's Den"},
    {EQ_ZONE_ID_OLDFIELDOFBONE, "Field of Scale"},
    {EQ_ZONE_ID_OLDFIELDOFBONEB, "Field of Scale"},
    {EQ_ZONE_ID_OLDKAESORAA, "Kaesora Library"},
    {EQ_ZONE_ID_OLDKAESORAB, "Hatchery Wing"},
    {EQ_ZONE_ID_OLDKURN, "Kurn's Tower"},
    {EQ_ZONE_ID_OLDKITHICOR, "Bloody Kithicor"},
    {EQ_ZONE_ID_OLDCOMMONS, "Old Commonlands"},
    {EQ_ZONE_ID_OLDHIGHPASS, "Highpass Hold"},
    {EQ_ZONE_ID_THEVOIDA, "The Void"},
    {EQ_ZONE_ID_THEVOIDB, "The Void"},
    {EQ_ZONE_ID_THEVOIDC, "The Void"},
    {EQ_ZONE_ID_THEVOIDD, "The Void"},
    {EQ_ZONE_ID_THEVOIDE, "The Void"},
    {EQ_ZONE_ID_THEVOIDF, "The Void"},
    {EQ_ZONE_ID_THEVOIDG, "The Void"},
    {EQ_ZONE_ID_OCEANGREENHILLS, "Oceangreen Hills"},
    {EQ_ZONE_ID_OCEANGREENVILLAGE, "Oceangreen Village"},
    {EQ_ZONE_ID_OLDBLACKBURROW, "Blackburrow"},
    {EQ_ZONE_ID_BERTOXTEMPLE, "Temple of Bertoxxulous"},
    {EQ_ZONE_ID_DISCORD, "Korafax, Home of the Riders"},
    {EQ_ZONE_ID_DISCORDTOWER, "Citadel of the Worldslayer"},
    {EQ_ZONE_ID_OLDBLOODFIELD, "Old Bloodfields"},
    {EQ_ZONE_ID_PRECIPICEOFWAR, "The Precipice of War"},
    {EQ_ZONE_ID_OLDDRANIK, "City of Dranik"},
    {EQ_ZONE_ID_TOSKIRAKK, "Toskirakk"},
    {EQ_ZONE_ID_KORASCIAN, "Korascian Warrens"},
    {EQ_ZONE_ID_RATHECHAMBER, "Rathe Council Chambers"},
    {EQ_ZONE_ID_STEAMFONTMTS, "Steamfont Mountains"},
    {EQ_ZONE_ID_CRAFTHALLS, "Ngreth's Den"},
    {EQ_ZONE_ID_BRELLSREST, "Brell's Rest"},
    {EQ_ZONE_ID_FUNGALFOREST, "Fungal Forest"},
    {EQ_ZONE_ID_UNDERQUARRY, "The Underquarry"},
    {EQ_ZONE_ID_COOLINGCHAMBER, "The Cooling Chamber"},
    {EQ_ZONE_ID_SHININGCITY, "Kernagir, The Shining City"},
    {EQ_ZONE_ID_ARTHICREX, "Arthicrex"},
    {EQ_ZONE_ID_FOUNDATION, "The Foundation"},
    {EQ_ZONE_ID_LICHENCREEP, "Lichen Creep"},
    {EQ_ZONE_ID_PELLUCID, "Pellucid Grotto"},
    {EQ_ZONE_ID_STONESNAKE, "Volska's Husk"},
    {EQ_ZONE_ID_BRELLSTEMPLE, "Brell's Temple"},
    {EQ_ZONE_ID_CONVORTEUM, "The Convorteum"},
    {EQ_ZONE_ID_BRELLSARENA, "Brell's Arena"},
    {EQ_ZONE_ID_WEDDINGCHAPEL, "Wedding Chapel"},
    {EQ_ZONE_ID_WEDDINGCHAPELDARK, "Wedding Chapel"},
    {EQ_ZONE_ID_DRAGONCRYPT, "Lair of the Fallen"},
    {EQ_ZONE_ID_FEERROTT2, "The Feerrott"},
    {EQ_ZONE_ID_THULEHOUSE1, "House of Thule"},
    {EQ_ZONE_ID_THULEHOUSE2, "House of Thule, Upper Floors"},
    {EQ_ZONE_ID_HOUSEGARDEN, "The Grounds"},
    {EQ_ZONE_ID_THULELIBRARY, "The Library"},
    {EQ_ZONE_ID_WELL, "The Well"},
    {EQ_ZONE_ID_FALLEN, "Erudin Burning"},
    {EQ_ZONE_ID_MORELLCASTLE, "Morell's Castle"},
    {EQ_ZONE_ID_SOMNIUM, "Sanctum Somnium"},
    {EQ_ZONE_ID_ALKABORMARE, "Al'Kabor's Nightmare"},
    {EQ_ZONE_ID_MIRAGULMARE, "Miragul's Nightmare"},
    {EQ_ZONE_ID_THULEDREAM, "Fear Itself"},
    {EQ_ZONE_ID_NEIGHBORHOOD, "Sunrise Hills"},
    {EQ_ZONE_ID_PHYLACTERY, "Miragul's Phylactery"},
    {EQ_ZONE_ID_PHINTERIOR3A1, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR3A2, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR3A3, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1A1, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1A2, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1A3, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1A3, "House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1B1, "Dragon House Interior"},
    {EQ_ZONE_ID_PHINTERIOR1D1, "Dragon House Interior"},
    {EQ_ZONE_ID_ARGATH, "Argath, Bastion of Illdaera"},
    {EQ_ZONE_ID_ARELIS, "Valley of Lunanyn"},
    {EQ_ZONE_ID_SARITHCITY, "Sarith, City of Tides"},
    {EQ_ZONE_ID_RUBAK, "Rubak Oseka, Temple of the Sea"},
    {EQ_ZONE_ID_BEASTDOMAIN, "Beasts' Domain"},
    {EQ_ZONE_ID_RESPLENDENT, "The Resplendent Temple"},
    {EQ_ZONE_ID_PILLARSALRA, "Pillars of Alra"},
    {EQ_ZONE_ID_WINDSONG, "Windsong Sanctuary"},
    {EQ_ZONE_ID_CITYOFBRONZE, "Erillion, City of Bronze"},
    {EQ_ZONE_ID_SEPULCHER, "Sepulcher of Order"},
    {EQ_ZONE_ID_EASTSEPULCHER, "Sepulcher East"},
    {EQ_ZONE_ID_WESTSEPULCHER, "Sepulcher West"},
    {EQ_ZONE_ID_SHADOWEDMOUNT, "Shadowed Mount"},
    {EQ_ZONE_ID_GUILDHALLLRG, "Grand Guild Hall"},
    {EQ_ZONE_ID_GUILDHALLSML, "Greater Guild Hall"},
    {EQ_ZONE_ID_PLHOGRINTERIORS1A1, "One Bedroom House Interior"},
    {EQ_ZONE_ID_PLHOGRINTERIORS1A2, "One Bedroom House Interior"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3A1, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3A2, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3B1, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3B2, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A1, "One Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A2, "One Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A3, "One Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A1, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A2, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A3, "Three Bedroom House Interior"},
    {EQ_ZONE_ID_GUILDHALL3, "Modest Guild Hall"},
    {EQ_ZONE_ID_KAELSHARD, "Kael Drakkel: The King's Madness"},
    {EQ_ZONE_ID_CRYSTALSHARD, "The Crystal Caverns: Fragment of Fear"},
    {EQ_ZONE_ID_SHARDSLANDING, "Shard's Landing"},
    {EQ_ZONE_ID_XORBB, "Valley of King Xorbb"},
    {EQ_ZONE_ID_BREEDINGGROUNDS, "The Breeding Grounds"},
    {EQ_ZONE_ID_EVILTREE, "Evantil, the Vile Oak"},
    {EQ_ZONE_ID_GRELLETH, "Grelleth's Palace, the Chateau of Filth"},
    {EQ_ZONE_ID_CHAPTERHOUSE, "Chapterhouse of the Fallen"},
    {EQ_ZONE_ID_PHINTERIORTREE, "Evantil's Abode"},
    {EQ_ZONE_ID_CHELSITHREBORN, "Chelsith Reborn"},
    {EQ_ZONE_ID_POSHADOW, "Plane of Shadow"},
    {EQ_ZONE_ID_HEARTOFFEAR, "Heart of Fear: The Threshold"},
    {EQ_ZONE_ID_HEARTOFFEARB, "Heart of Fear: The Rebirth"},
    {EQ_ZONE_ID_HEARTOFFEARC, "Heart of Fear: The Epicenter"},
    {EQ_ZONE_ID_NERIAKD, "Neriak - Fourth Gate"},
    {EQ_ZONE_ID_BIXIEWARFRONT, "Bixie Warfront"},
    {EQ_ZONE_ID_DEADHILLS, "The Dead Hills"},
    {EQ_ZONE_ID_ETHERNERE, "Ethernere Tainted West Karana"},
    {EQ_ZONE_ID_THEVOIDH, "The Void"},
    {EQ_ZONE_ID_PLHBIXIEINT, "Bixie Hive"},
    {EQ_ZONE_ID_TOWEROFROT, "Tower of Rot"},
    {EQ_ZONE_ID_ARGINHIZ, "Argin-Hiz"},
    {EQ_ZONE_ID_ARXMENTIS, "Arx Mentis"},
    {EQ_ZONE_ID_BROTHERISLAND, "Brother Island"},
    {EQ_ZONE_ID_KATTACASTRUMB, "Katta Castrum: Deluge"},
    {EQ_ZONE_ID_DREDGE, "Combine Dredge"},
    {EQ_ZONE_ID_ENDLESSCAVERNS, "Caverns of Endless Song"},
    {EQ_ZONE_ID_THULIASAUR, "Thuliasaur Island"},
    {EQ_ZONE_ID_DEGMAR, "Degmar, the Lost Castle"},
    {EQ_ZONE_ID_TEMPESTTEMPLE, "Tempest Temple"},
    {EQ_ZONE_ID_PLHPIRATESHIPINT, "Pirate Ship"},
    {EQ_ZONE_ID_EXALTED, "Sul Vius: Demiplane of Life"},
    {EQ_ZONE_ID_COSUL, "Crypt of Sul"},
    {EQ_ZONE_ID_CODECAYB, "Ruins of Lxanvom"},
    {EQ_ZONE_ID_EXALTEDB, "Sul Vius: Demiplane of Decay"},
    {EQ_ZONE_ID_POHEALTH, "The Plane of Health"},
    {EQ_ZONE_ID_DROGAB, "The Temple of Droga"},
    {EQ_ZONE_ID_SCORCHEDWOODS, "Scorched Woods"},
    {EQ_ZONE_ID_FRONTIERMTNSB, "Frontier Mountains"},
    {EQ_ZONE_ID_KORSHAEXT, "Gates of Kor-Sha"},
    {EQ_ZONE_ID_KORSHAINT, "Kor-Sha Laboratory"},
    {EQ_ZONE_ID_LCEANIUM, "Lceanium"},
    {EQ_ZONE_ID_CHARDOKTWO, "Chardok"},
    {EQ_ZONE_ID_CHARASISB, "Sathir's Tomb"},
    {EQ_ZONE_ID_GOROWYN, "Gorowyn"},
    {EQ_ZONE_ID_CHARASISTWO, "Howling Stones"},
    {EQ_ZONE_ID_SKYFIRETWO, "Skyfire Mountains"},
    {EQ_ZONE_ID_OVERTHERETWO, "The Overthere"},
    {EQ_ZONE_ID_VEESHANTWO, "Veeshan's Peak"},
    {EQ_ZONE_ID_TRIALSOFSMOKE, "Trials of Smoke"},
    {EQ_ZONE_ID_STRATOS, "Stratos: Zephyr's Flight"},
    {EQ_ZONE_ID_AALISHAI, "Aalishai: Palace of Embers"},
    {EQ_ZONE_ID_EMPYR, "Empyr: Realms of Ash"},
    {EQ_ZONE_ID_ESIANTI, "Esianti: Palace of the Winds"},
    {EQ_ZONE_ID_MEARATAS, "Mearatas: The Stone Demesne"},
    {EQ_ZONE_ID_CHAMBEROFTEARS, "The Chamber of Tears"},
    {EQ_ZONE_ID_CLZ_ANNIVERSARY, "Loading"},
    {EQ_ZONE_ID_CLZ_AUTUMN, "Loading"},
    {EQ_ZONE_ID_CLZ_FROSTFELL, "Loading"},
    {EQ_ZONE_ID_CLZ_SPRING, "Loading"},
    {EQ_ZONE_ID_CLZ_WINTER, "Loading"},
    {EQ_ZONE_ID_POMISCHIEF, "The Plane of Mischief"},
    {EQ_ZONE_ID_BURNEDWOODS, "The Burned Woods"},
    {EQ_ZONE_ID_INTERIORWALLTEST, "Wall Wall Wall"},
    {EQ_ZONE_ID_GNOMEMTN, "Gnome Memorial Mountain"},
};

std::unordered_map<uint32_t, std::string> EQ_ZONE_ID_ShortName_Strings =
{
    {EQ_ZONE_ID_QEYNOS, "qeynos"},
    {EQ_ZONE_ID_QEYNOS2, "qeynos2"},
    {EQ_ZONE_ID_QRG, "qrg"},
    {EQ_ZONE_ID_QEYTOQRG, "qeytoqrg"},
    {EQ_ZONE_ID_HIGHKEEP, "highkeep"},
    {EQ_ZONE_ID_FREPORTN, "freportn"},
    {EQ_ZONE_ID_FREPORTW, "freportw"},
    {EQ_ZONE_ID_FREPORTE, "freporte"},
    {EQ_ZONE_ID_RUNNYEYE, "runnyeye"},
    {EQ_ZONE_ID_QEY2HH1, "qey2hh1"},
    {EQ_ZONE_ID_NORTHKARANA, "northkarana"},
    {EQ_ZONE_ID_SOUTHKARANA, "southkarana"},
    {EQ_ZONE_ID_EASTKARANA, "eastkarana"},
    {EQ_ZONE_ID_BEHOLDER, "beholder"},
    {EQ_ZONE_ID_BLACKBURROW, "blackburrow"},
    {EQ_ZONE_ID_PAW, "paw"},
    {EQ_ZONE_ID_RIVERVALE, "rivervale"},
    {EQ_ZONE_ID_KITHICOR, "kithicor"},
    {EQ_ZONE_ID_COMMONS, "commons"},
    {EQ_ZONE_ID_ECOMMONS, "ecommons"},
    {EQ_ZONE_ID_COMMONLANDS, "commonlands"},
    {EQ_ZONE_ID_OCEANOFTEARS, "oceanoftears"},
    {EQ_ZONE_ID_KITHFOREST, "kithforest"},
    {EQ_ZONE_ID_BEFALLENB, "befallenb"},
    {EQ_ZONE_ID_HIGHPASSKEEP, "highpasskeep"},
    {EQ_ZONE_ID_INNOTHULEB, "innothuleb"},
    {EQ_ZONE_ID_TOXXULIA, "toxxulia"},
    {EQ_ZONE_ID_MISTYTHICKET, "mistythicket"},
    {EQ_ZONE_ID_ERUDNINT, "erudnint"},
    {EQ_ZONE_ID_ERUDNEXT, "erudnext"},
    {EQ_ZONE_ID_NEKTULOS, "nektulos"},
    {EQ_ZONE_ID_CSHOME, "cshome"},
    {EQ_ZONE_ID_LAVASTORM, "lavastorm"},
    {EQ_ZONE_ID_NEKTROPOS, "nektropos"},
    {EQ_ZONE_ID_HALAS, "halas"},
    {EQ_ZONE_ID_EVERFROST, "everfrost"},
    {EQ_ZONE_ID_SOLDUNGA, "soldunga"},
    {EQ_ZONE_ID_SOLDUNGB, "soldungb"},
    {EQ_ZONE_ID_MISTY, "misty"},
    {EQ_ZONE_ID_NRO, "nro"},
    {EQ_ZONE_ID_SRO, "sro"},
    {EQ_ZONE_ID_BEFALLEN, "befallen"},
    {EQ_ZONE_ID_OASIS, "oasis"},
    {EQ_ZONE_ID_TOX, "tox"},
    {EQ_ZONE_ID_HOLE, "hole"},
    {EQ_ZONE_ID_NERIAKA, "neriaka"},
    {EQ_ZONE_ID_NERIAKB, "neriakb"},
    {EQ_ZONE_ID_NERIAKC, "neriakc"},
    {EQ_ZONE_ID_NAJENA, "najena"},
    {EQ_ZONE_ID_QCAT, "qcat"},
    {EQ_ZONE_ID_INNOTHULE, "innothule"},
    {EQ_ZONE_ID_FEERROTT, "feerrott"},
    {EQ_ZONE_ID_CAZICTHULE, "cazicthule"},
    {EQ_ZONE_ID_OGGOK, "oggok"},
    {EQ_ZONE_ID_RATHEMTN, "rathemtn"},
    {EQ_ZONE_ID_LAKERATHE, "lakerathe"},
    {EQ_ZONE_ID_GROBB, "grobb"},
    {EQ_ZONE_ID_AVIAK, "aviak"},
    {EQ_ZONE_ID_GFAYDARK, "gfaydark"},
    {EQ_ZONE_ID_AKANON, "akanon"},
    {EQ_ZONE_ID_STEAMFONT, "steamfont"},
    {EQ_ZONE_ID_LFAYDARK, "lfaydark"},
    {EQ_ZONE_ID_CRUSHBONE, "crushbone"},
    {EQ_ZONE_ID_MISTMOORE, "mistmoore"},
    {EQ_ZONE_ID_KALADIMA, "kaladima"},
    {EQ_ZONE_ID_FELWITHEA, "felwithea"},
    {EQ_ZONE_ID_FELWITHEB, "felwitheb"},
    {EQ_ZONE_ID_UNREST, "unrest"},
    {EQ_ZONE_ID_KEDGE, "kedge"},
    {EQ_ZONE_ID_GUKTOP, "guktop"},
    {EQ_ZONE_ID_GUKBOTTOM, "gukbottom"},
    {EQ_ZONE_ID_KALADIMB, "kaladimb"},
    {EQ_ZONE_ID_BUTCHER, "butcher"},
    {EQ_ZONE_ID_OOT, "oot"},
    {EQ_ZONE_ID_CAULDRON, "cauldron"},
    {EQ_ZONE_ID_AIRPLANE, "airplane"},
    {EQ_ZONE_ID_FEARPLANE, "fearplane"},
    {EQ_ZONE_ID_PERMAFROST, "permafrost"},
    {EQ_ZONE_ID_KERRARIDGE, "kerraridge"},
    {EQ_ZONE_ID_PAINEEL, "paineel"},
    {EQ_ZONE_ID_HATEPLANE, "hateplane"},
    {EQ_ZONE_ID_ARENA, "arena"},
    {EQ_ZONE_ID_FIELDOFBONE, "fieldofbone"},
    {EQ_ZONE_ID_WARSLIKSWOOD, "warslikswood"},
    {EQ_ZONE_ID_SOLTEMPLE, "soltemple"},
    {EQ_ZONE_ID_DROGA, "droga"},
    {EQ_ZONE_ID_CABWEST, "cabwest"},
    {EQ_ZONE_ID_SWAMPOFNOHOPE, "swampofnohope"},
    {EQ_ZONE_ID_FIRIONA, "firiona"},
    {EQ_ZONE_ID_LAKEOFILLOMEN, "lakeofillomen"},
    {EQ_ZONE_ID_DREADLANDS, "dreadlands"},
    {EQ_ZONE_ID_BURNINGWOOD, "burningwood"},
    {EQ_ZONE_ID_KAESORA, "kaesora"},
    {EQ_ZONE_ID_SEBILIS, "sebilis"},
    {EQ_ZONE_ID_CITYMIST, "citymist"},
    {EQ_ZONE_ID_SKYFIRE, "skyfire"},
    {EQ_ZONE_ID_FRONTIERMTNS, "frontiermtns"},
    {EQ_ZONE_ID_OVERTHERE, "overthere"},
    {EQ_ZONE_ID_EMERALDJUNGLE, "emeraldjungle"},
    {EQ_ZONE_ID_TRAKANON, "trakanon"},
    {EQ_ZONE_ID_TIMOROUS, "timorous"},
    {EQ_ZONE_ID_KURN, "kurn"},
    {EQ_ZONE_ID_ERUDSXING, "erudsxing"},
    {EQ_ZONE_ID_STONEBRUNT, "stonebrunt"},
    {EQ_ZONE_ID_WARRENS, "warrens"},
    {EQ_ZONE_ID_KARNOR, "karnor"},
    {EQ_ZONE_ID_CHARDOK, "chardok"},
    {EQ_ZONE_ID_DALNIR, "dalnir"},
    {EQ_ZONE_ID_CHARASIS, "charasis"},
    {EQ_ZONE_ID_CABEAST, "cabeast"},
    {EQ_ZONE_ID_NURGA, "nurga"},
    {EQ_ZONE_ID_VEESHAN, "veeshan"},
    {EQ_ZONE_ID_VEKSAR, "veksar"},
    {EQ_ZONE_ID_ICECLAD, "iceclad"},
    {EQ_ZONE_ID_FROZENSHADOW, "frozenshadow"},
    {EQ_ZONE_ID_VELKETOR, "velketor"},
    {EQ_ZONE_ID_KAEL, "kael"},
    {EQ_ZONE_ID_SKYSHRINE, "skyshrine"},
    {EQ_ZONE_ID_THURGADINA, "thurgadina"},
    {EQ_ZONE_ID_EASTWASTES, "eastwastes"},
    {EQ_ZONE_ID_COBALTSCAR, "cobaltscar"},
    {EQ_ZONE_ID_GREATDIVIDE, "greatdivide"},
    {EQ_ZONE_ID_WAKENING, "wakening"},
    {EQ_ZONE_ID_WESTWASTES, "westwastes"},
    {EQ_ZONE_ID_CRYSTAL, "crystal"},
    {EQ_ZONE_ID_NECROPOLIS, "necropolis"},
    {EQ_ZONE_ID_TEMPLEVEESHAN, "templeveeshan"},
    {EQ_ZONE_ID_SIRENS, "sirens"},
    {EQ_ZONE_ID_MISCHIEFPLANE, "mischiefplane"},
    {EQ_ZONE_ID_GROWTHPLANE, "growthplane"},
    {EQ_ZONE_ID_SLEEPER, "sleeper"},
    {EQ_ZONE_ID_THURGADINB, "thurgadinb"},
    {EQ_ZONE_ID_ERUDSXING2, "erudsxing2"},
    {EQ_ZONE_ID_SHADOWHAVEN, "shadowhaven"},
    {EQ_ZONE_ID_BAZAAR, "bazaar"},
    {EQ_ZONE_ID_NEXUS, "nexus"},
    {EQ_ZONE_ID_ECHO, "echo"},
    {EQ_ZONE_ID_ACRYLIA, "acrylia"},
    {EQ_ZONE_ID_SHARVAHL, "sharvahl"},
    {EQ_ZONE_ID_PALUDAL, "paludal"},
    {EQ_ZONE_ID_FUNGUSGROVE, "fungusgrove"},
    {EQ_ZONE_ID_VEXTHAL, "vexthal"},
    {EQ_ZONE_ID_SSERU, "sseru"},
    {EQ_ZONE_ID_KATTA, "katta"},
    {EQ_ZONE_ID_NETHERBIAN, "netherbian"},
    {EQ_ZONE_ID_SSRATEMPLE, "ssratemple"},
    {EQ_ZONE_ID_GRIEGSEND, "griegsend"},
    {EQ_ZONE_ID_THEDEEP, "thedeep"},
    {EQ_ZONE_ID_SHADEWEAVER, "shadeweaver"},
    {EQ_ZONE_ID_HOLLOWSHADE, "hollowshade"},
    {EQ_ZONE_ID_GRIMLING, "grimling"},
    {EQ_ZONE_ID_MSERU, "mseru"},
    {EQ_ZONE_ID_LETALIS, "letalis"},
    {EQ_ZONE_ID_TWILIGHT, "twilight"},
    {EQ_ZONE_ID_THEGREY, "thegrey"},
    {EQ_ZONE_ID_TENEBROUS, "tenebrous"},
    {EQ_ZONE_ID_MAIDEN, "maiden"},
    {EQ_ZONE_ID_DAWNSHROUD, "dawnshroud"},
    {EQ_ZONE_ID_SCARLET, "scarlet"},
    {EQ_ZONE_ID_UMBRAL, "umbral"},
    {EQ_ZONE_ID_AKHEVA, "akheva"},
    {EQ_ZONE_ID_ARENA2, "arena2"},
    {EQ_ZONE_ID_JAGGEDPINE, "jaggedpine"},
    {EQ_ZONE_ID_NEDARIA, "nedaria"},
    {EQ_ZONE_ID_SHADOWREST, "shadowrest"},
    {EQ_ZONE_ID_TUTORIAL, "tutorial"},
    {EQ_ZONE_ID_TUTORIALA, "tutoriala"},
    {EQ_ZONE_ID_TUTORIALB, "tutorialb"},
    {EQ_ZONE_ID_CLZ, "clz"},
    {EQ_ZONE_ID_LOAD, "load"},
    {EQ_ZONE_ID_LOAD2, "load2"},
    {EQ_ZONE_ID_ARTTEST, "arttest"},
    {EQ_ZONE_ID_APPRENTICE, "apprentice"},
    {EQ_ZONE_ID_POKNOWLEDGE, "poknowledge"},
    {EQ_ZONE_ID_POTRANQUILITY, "potranquility"},
    {EQ_ZONE_ID_CODECAY, "codecay"},
    {EQ_ZONE_ID_POJUSTICE, "pojustice"},
    {EQ_ZONE_ID_PONIGHTMARE, "ponightmare"},
    {EQ_ZONE_ID_NIGHTMAREB, "nightmareb"},
    {EQ_ZONE_ID_PODISEASE, "podisease"},
    {EQ_ZONE_ID_POINNOVATION, "poinnovation"},
    {EQ_ZONE_ID_POTORMENT, "potorment"},
    {EQ_ZONE_ID_POVALOR, "povalor"},
    {EQ_ZONE_ID_BOTHUNDER, "bothunder"},
    {EQ_ZONE_ID_POSTORMS, "postorms"},
    {EQ_ZONE_ID_HOHONORA, "hohonora"},
    {EQ_ZONE_ID_HOHONORB, "hohonorb"},
    {EQ_ZONE_ID_SOLROTOWER, "solrotower"},
    {EQ_ZONE_ID_POWAR, "powar"},
    {EQ_ZONE_ID_POTACTICS, "potactics"},
    {EQ_ZONE_ID_POAIR, "poair"},
    {EQ_ZONE_ID_POWATER, "powater"},
    {EQ_ZONE_ID_POFIRE, "pofire"},
    {EQ_ZONE_ID_POEARTHA, "poeartha"},
    {EQ_ZONE_ID_POEARTHB, "poearthb"},
    {EQ_ZONE_ID_POTIMEA, "potimea"},
    {EQ_ZONE_ID_POTIMEB, "potimeb"},
    {EQ_ZONE_ID_TORGIRAN, "torgiran"},
    {EQ_ZONE_ID_NADOX, "nadox"},
    {EQ_ZONE_ID_GUNTHAK, "gunthak"},
    {EQ_ZONE_ID_DULAK, "dulak"},
    {EQ_ZONE_ID_HATESFURY, "hatesfury"},
    {EQ_ZONE_ID_HATEPLANEB, "hateplaneb"},
    {EQ_ZONE_ID_CHARDOKB, "chardokb"},
    {EQ_ZONE_ID_SOLDUNGC, "soldungc"},
    {EQ_ZONE_ID_GUKA, "guka"},
    {EQ_ZONE_ID_RUJA, "ruja"},
    {EQ_ZONE_ID_TAKA, "taka"},
    {EQ_ZONE_ID_MIRA, "mira"},
    {EQ_ZONE_ID_MMCA, "mmca"},
    {EQ_ZONE_ID_GUKB, "gukb"},
    {EQ_ZONE_ID_RUJB, "rujb"},
    {EQ_ZONE_ID_TAKB, "takb"},
    {EQ_ZONE_ID_MIRB, "mirb"},
    {EQ_ZONE_ID_MMCB, "mmcb"},
    {EQ_ZONE_ID_GUKC, "gukc"},
    {EQ_ZONE_ID_RUJC, "rujc"},
    {EQ_ZONE_ID_TAKC, "takc"},
    {EQ_ZONE_ID_MIRC, "mirc"},
    {EQ_ZONE_ID_MMCC, "mmcc"},
    {EQ_ZONE_ID_GUKD, "gukd"},
    {EQ_ZONE_ID_RUJD, "rujd"},
    {EQ_ZONE_ID_TAKD, "takd"},
    {EQ_ZONE_ID_MIRD, "mird"},
    {EQ_ZONE_ID_MMCD, "mmcd"},
    {EQ_ZONE_ID_GUKE, "guke"},
    {EQ_ZONE_ID_RUJE, "ruje"},
    {EQ_ZONE_ID_TAKE, "take"},
    {EQ_ZONE_ID_MIRE, "mire"},
    {EQ_ZONE_ID_MMCE, "mmce"},
    {EQ_ZONE_ID_GUKF, "gukf"},
    {EQ_ZONE_ID_RUJF, "rujf"},
    {EQ_ZONE_ID_TAKF, "takf"},
    {EQ_ZONE_ID_MIRF, "mirf"},
    {EQ_ZONE_ID_MMCF, "mmcf"},
    {EQ_ZONE_ID_GUKG, "gukg"},
    {EQ_ZONE_ID_RUJG, "rujg"},
    {EQ_ZONE_ID_TAKG, "takg"},
    {EQ_ZONE_ID_MIRG, "mirg"},
    {EQ_ZONE_ID_MMCG, "mmcg"},
    {EQ_ZONE_ID_GUKH, "gukh"},
    {EQ_ZONE_ID_RUJH, "rujh"},
    {EQ_ZONE_ID_TAKH, "takh"},
    {EQ_ZONE_ID_MIRH, "mirh"},
    {EQ_ZONE_ID_MMCH, "mmch"},
    {EQ_ZONE_ID_RUJI, "ruji"},
    {EQ_ZONE_ID_TAKI, "taki"},
    {EQ_ZONE_ID_MIRI, "miri"},
    {EQ_ZONE_ID_MMCI, "mmci"},
    {EQ_ZONE_ID_RUJJ, "rujj"},
    {EQ_ZONE_ID_TAKJ, "takj"},
    {EQ_ZONE_ID_MIRJ, "mirj"},
    {EQ_ZONE_ID_MMCJ, "mmcj"},
    {EQ_ZONE_ID_ARENA, "arena"},
    {EQ_ZONE_ID_ABYSMAL, "abysmal"},
    {EQ_ZONE_ID_NATIMBI, "natimbi"},
    {EQ_ZONE_ID_QINIMI, "qinimi"},
    {EQ_ZONE_ID_RIWWI, "riwwi"},
    {EQ_ZONE_ID_BARINDU, "barindu"},
    {EQ_ZONE_ID_SNPOOL, "snpool"},
    {EQ_ZONE_ID_TIPT, "tipt"},
    {EQ_ZONE_ID_VXED, "vxed"},
    {EQ_ZONE_ID_YXTTA, "yxtta"},
    {EQ_ZONE_ID_UQUA, "uqua"},
    {EQ_ZONE_ID_KODTAZ, "kodtaz"},
    {EQ_ZONE_ID_IKKINZ, "ikkinz"},
    {EQ_ZONE_ID_INKTUTA, "inktuta"},
    {EQ_ZONE_ID_TXEVU, "txevu"},
    {EQ_ZONE_ID_TACVI, "tacvi"},
    {EQ_ZONE_ID_QVIC, "qvic"},
    {EQ_ZONE_ID_QVICB, "qvicb"},
    {EQ_ZONE_ID_WALLOFSLAUGHTER, "wallofslaughter"},
    {EQ_ZONE_ID_BLOODFIELDS, "bloodfields"},
    {EQ_ZONE_ID_DRANIKSSCAR, "draniksscar"},
    {EQ_ZONE_ID_CAUSEWAY, "causeway"},
    {EQ_ZONE_ID_CHAMBERSA, "chambersa"},
    {EQ_ZONE_ID_CHAMBERSB, "chambersb"},
    {EQ_ZONE_ID_CHAMBERSC, "chambersc"},
    {EQ_ZONE_ID_CHAMBERSD, "chambersd"},
    {EQ_ZONE_ID_CHAMBERSE, "chamberse"},
    {EQ_ZONE_ID_CHAMBERSF, "chambersf"},
    {EQ_ZONE_ID_PROVINGGROUNDS, "provinggrounds"},
    {EQ_ZONE_ID_ANGUISH, "anguish"},
    {EQ_ZONE_ID_DRANIKHOLLOWSA, "dranikhollowsa"},
    {EQ_ZONE_ID_DRANIKHOLLOWSB, "dranikhollowsb"},
    {EQ_ZONE_ID_DRANIKHOLLOWSC, "dranikhollowsc"},
    {EQ_ZONE_ID_DRANIKHOLLOWSD, "dranikhollowsd"},
    {EQ_ZONE_ID_DRANIKHOLLOWSE, "dranikhollowse"},
    {EQ_ZONE_ID_DRANIKHOLLOWSF, "dranikhollowsf"},
    {EQ_ZONE_ID_DRANIKHOLLOWSG, "dranikhollowsg"},
    {EQ_ZONE_ID_DRANIKHOLLOWSH, "dranikhollowsh"},
    {EQ_ZONE_ID_DRANIKHOLLOWSI, "dranikhollowsi"},
    {EQ_ZONE_ID_DRANIKHOLLOWSJ, "dranikhollowsj"},
    {EQ_ZONE_ID_DRANIKCATACOMBSA, "dranikcatacombsa"},
    {EQ_ZONE_ID_DRANIKCATACOMBSB, "dranikcatacombsb"},
    {EQ_ZONE_ID_DRANIKCATACOMBSC, "dranikcatacombsc"},
    {EQ_ZONE_ID_DRANIKSEWERSA, "draniksewersa"},
    {EQ_ZONE_ID_DRANIKSEWERSB, "draniksewersb"},
    {EQ_ZONE_ID_DRANIKSEWERSC, "draniksewersc"},
    {EQ_ZONE_ID_RIFTSEEKERS, "riftseekers"},
    {EQ_ZONE_ID_HARBINGERS, "harbingers"},
    {EQ_ZONE_ID_DRANIK, "dranik"},
    {EQ_ZONE_ID_FHALLS, "fhalls"},
    {EQ_ZONE_ID_BROODLANDS, "broodlands"},
    {EQ_ZONE_ID_STILLMOONA, "stillmoona"},
    {EQ_ZONE_ID_STILLMOONB, "stillmoonb"},
    {EQ_ZONE_ID_THUNDERCREST, "thundercrest"},
    {EQ_ZONE_ID_DELVEA, "delvea"},
    {EQ_ZONE_ID_DELVEB, "delveb"},
    {EQ_ZONE_ID_THENEST, "thenest"},
    {EQ_ZONE_ID_GUILDLOBBY, "guildlobby"},
    {EQ_ZONE_ID_GUILDHALL, "guildhall"},
    {EQ_ZONE_ID_BARTER, "barter"},
    {EQ_ZONE_ID_ILLSALIN, "illsalin"},
    {EQ_ZONE_ID_ILLSALINA, "illsalina"},
    {EQ_ZONE_ID_ILLSALINB, "illsalinb"},
    {EQ_ZONE_ID_ILLSALINC, "illsalinc"},
    {EQ_ZONE_ID_DREADSPIRE, "dreadspire"},
    {EQ_ZONE_ID_DRACHNIDHIVE, "drachnidhive"},
    {EQ_ZONE_ID_DRACHNIDHIVEA, "drachnidhivea"},
    {EQ_ZONE_ID_DRACHNIDHIVEB, "drachnidhiveb"},
    {EQ_ZONE_ID_DRACHNIDHIVEC, "drachnidhivec"},
    {EQ_ZONE_ID_WESTKORLACH, "westkorlach"},
    {EQ_ZONE_ID_WESTKORLACHA, "westkorlacha"},
    {EQ_ZONE_ID_WESTKORLACHB, "westkorlachb"},
    {EQ_ZONE_ID_WESTKORLACHC, "westkorlachc"},
    {EQ_ZONE_ID_EASTKORLACH, "eastkorlach"},
    {EQ_ZONE_ID_EASTKORLACHA, "eastkorlacha"},
    {EQ_ZONE_ID_SHADOWSPINE, "shadowspine"},
    {EQ_ZONE_ID_CORATHUS, "corathus"},
    {EQ_ZONE_ID_CORATHUSA, "corathusa"},
    {EQ_ZONE_ID_CORATHUSB, "corathusb"},
    {EQ_ZONE_ID_NEKTULOSA, "nektulosa"},
    {EQ_ZONE_ID_ARCSTONE, "arcstone"},
    {EQ_ZONE_ID_RELIC, "relic"},
    {EQ_ZONE_ID_SKYLANCE, "skylance"},
    {EQ_ZONE_ID_DEVASTATION, "devastation"},
    {EQ_ZONE_ID_DEVASTATIONA, "devastationa"},
    {EQ_ZONE_ID_RAGE, "rage"},
    {EQ_ZONE_ID_RAGEA, "ragea"},
    {EQ_ZONE_ID_TAKISHRUINS, "takishruins"},
    {EQ_ZONE_ID_TAKISHRUINSA, "takishruinsa"},
    {EQ_ZONE_ID_ELDDAR, "elddar"},
    {EQ_ZONE_ID_ELDDARA, "elddara"},
    {EQ_ZONE_ID_THEATER, "theater"},
    {EQ_ZONE_ID_THEATERA, "theatera"},
    {EQ_ZONE_ID_FREEPORTEAST, "freeporteast"},
    {EQ_ZONE_ID_FREEPORTWEST, "freeportwest"},
    {EQ_ZONE_ID_FREEPORTSEWERS, "freeportsewers"},
    {EQ_ZONE_ID_FREEPORTACADEMY, "freeportacademy"},
    {EQ_ZONE_ID_FREEPORTTEMPLE, "freeporttemple"},
    {EQ_ZONE_ID_FREEPORTMILITIA, "freeportmilitia"},
    {EQ_ZONE_ID_FREEPORTARENA, "freeportarena"},
    {EQ_ZONE_ID_FREEPORTCITYHALL, "freeportcityhall"},
    {EQ_ZONE_ID_FREEPORTTHEATER, "freeporttheater"},
    {EQ_ZONE_ID_FREEPORTHALL, "freeporthall"},
    {EQ_ZONE_ID_NORTHRO, "northro"},
    {EQ_ZONE_ID_SOUTHRO, "southro"},
    {EQ_ZONE_ID_CRESCENT, "crescent"},
    {EQ_ZONE_ID_MOORS, "moors"},
    {EQ_ZONE_ID_STONEHIVE, "stonehive"},
    {EQ_ZONE_ID_MESA, "mesa"},
    {EQ_ZONE_ID_ROOST, "roost"},
    {EQ_ZONE_ID_STEPPES, "steppes"},
    {EQ_ZONE_ID_ICEFALL, "icefall"},
    {EQ_ZONE_ID_VALDEHOLM, "valdeholm"},
    {EQ_ZONE_ID_SUNDEROCK, "sunderock"},
    {EQ_ZONE_ID_VERGALID, "vergalid"},
    {EQ_ZONE_ID_DIREWIND, "direwind"},
    {EQ_ZONE_ID_ASHENGATE, "ashengate"},
    {EQ_ZONE_ID_HIGHPASSHOLD, "highpasshold"},
    {EQ_ZONE_ID_KATTACASTRUM, "kattacastrum"},
    {EQ_ZONE_ID_THALASSIUS, "thalassius"},
    {EQ_ZONE_ID_ATIIKI, "atiiki"},
    {EQ_ZONE_ID_ZHISZA, "zhisza"},
    {EQ_ZONE_ID_SILYSSAR, "silyssar"},
    {EQ_ZONE_ID_SOLTERIS, "solteris"},
    {EQ_ZONE_ID_BARREN, "barren"},
    {EQ_ZONE_ID_BURIEDSEA, "buriedsea"},
    {EQ_ZONE_ID_JARDELSHOOK, "jardelshook"},
    {EQ_ZONE_ID_MONKEYROCK, "monkeyrock"},
    {EQ_ZONE_ID_SUNCREST, "suncrest"},
    {EQ_ZONE_ID_DEADBONE, "deadbone"},
    {EQ_ZONE_ID_BLACKSAIL, "blacksail"},
    {EQ_ZONE_ID_MAIDENSGRAVE, "maidensgrave"},
    {EQ_ZONE_ID_REDFEATHER, "redfeather"},
    {EQ_ZONE_ID_SHIPMVP, "shipmvp"},
    {EQ_ZONE_ID_SHIPMVU, "shipmvu"},
    {EQ_ZONE_ID_SHIPPVU, "shippvu"},
    {EQ_ZONE_ID_SHIPUVU, "shipuvu"},
    {EQ_ZONE_ID_SHIPMVM, "shipmvm"},
    {EQ_ZONE_ID_MECHANOTUS, "mechanotus"},
    {EQ_ZONE_ID_MANSION, "mansion"},
    {EQ_ZONE_ID_STEAMFACTORY, "steamfactory"},
    {EQ_ZONE_ID_SHIPWORKSHOP, "shipworkshop"},
    {EQ_ZONE_ID_GYROSPIREB, "gyrospireb"},
    {EQ_ZONE_ID_GYROSPIREZ, "gyrospirez"},
    {EQ_ZONE_ID_DRAGONSCALE, "dragonscale"},
    {EQ_ZONE_ID_LOPINGPLAINS, "lopingplains"},
    {EQ_ZONE_ID_HILLSOFSHADE, "hillsofshade"},
    {EQ_ZONE_ID_BLOODMOON, "bloodmoon"},
    {EQ_ZONE_ID_CRYSTALLOS, "crystallos"},
    {EQ_ZONE_ID_GUARDIAN, "guardian"},
    {EQ_ZONE_ID_CRYPTOFSHADE, "cryptofshade"},
    {EQ_ZONE_ID_DRAGONSCALEA, "dragonscalea"},
    {EQ_ZONE_ID_DRAGONSCALEB, "dragonscaleb"},
    {EQ_ZONE_ID_OLDFIELDOFBONE, "oldfieldofbone"},
    {EQ_ZONE_ID_OLDFIELDOFBONEB, "oldfieldofboneb"},
    {EQ_ZONE_ID_OLDKAESORAA, "oldkaesoraa"},
    {EQ_ZONE_ID_OLDKAESORAB, "oldkaesorab"},
    {EQ_ZONE_ID_OLDKURN, "oldkurn"},
    {EQ_ZONE_ID_OLDKITHICOR, "oldkithicor"},
    {EQ_ZONE_ID_OLDCOMMONS, "oldcommons"},
    {EQ_ZONE_ID_OLDHIGHPASS, "oldhighpass"},
    {EQ_ZONE_ID_THEVOIDA, "thevoida"},
    {EQ_ZONE_ID_THEVOIDB, "thevoidb"},
    {EQ_ZONE_ID_THEVOIDC, "thevoidc"},
    {EQ_ZONE_ID_THEVOIDD, "thevoidd"},
    {EQ_ZONE_ID_THEVOIDE, "thevoide"},
    {EQ_ZONE_ID_THEVOIDF, "thevoidf"},
    {EQ_ZONE_ID_THEVOIDG, "thevoidg"},
    {EQ_ZONE_ID_OCEANGREENHILLS, "oceangreenhills"},
    {EQ_ZONE_ID_OCEANGREENVILLAGE, "oceangreenvillage"},
    {EQ_ZONE_ID_OLDBLACKBURROW, "oldblackburrow"},
    {EQ_ZONE_ID_BERTOXTEMPLE, "bertoxtemple"},
    {EQ_ZONE_ID_DISCORD, "discord"},
    {EQ_ZONE_ID_DISCORDTOWER, "discordtower"},
    {EQ_ZONE_ID_OLDBLOODFIELD, "oldbloodfield"},
    {EQ_ZONE_ID_PRECIPICEOFWAR, "precipiceofwar"},
    {EQ_ZONE_ID_OLDDRANIK, "olddranik"},
    {EQ_ZONE_ID_TOSKIRAKK, "toskirakk"},
    {EQ_ZONE_ID_KORASCIAN, "korascian"},
    {EQ_ZONE_ID_RATHECHAMBER, "rathechamber"},
    {EQ_ZONE_ID_STEAMFONTMTS, "steamfontmts"},
    {EQ_ZONE_ID_CRAFTHALLS, "crafthalls"},
    {EQ_ZONE_ID_BRELLSREST, "brellsrest"},
    {EQ_ZONE_ID_FUNGALFOREST, "fungalforest"},
    {EQ_ZONE_ID_UNDERQUARRY, "underquarry"},
    {EQ_ZONE_ID_COOLINGCHAMBER, "coolingchamber"},
    {EQ_ZONE_ID_SHININGCITY, "shiningcity"},
    {EQ_ZONE_ID_ARTHICREX, "arthicrex"},
    {EQ_ZONE_ID_FOUNDATION, "foundation"},
    {EQ_ZONE_ID_LICHENCREEP, "lichencreep"},
    {EQ_ZONE_ID_PELLUCID, "pellucid"},
    {EQ_ZONE_ID_STONESNAKE, "stonesnake"},
    {EQ_ZONE_ID_BRELLSTEMPLE, "brellstemple"},
    {EQ_ZONE_ID_CONVORTEUM, "convorteum"},
    {EQ_ZONE_ID_BRELLSARENA, "brellsarena"},
    {EQ_ZONE_ID_WEDDINGCHAPEL, "weddingchapel"},
    {EQ_ZONE_ID_WEDDINGCHAPELDARK, "weddingchapeldark"},
    {EQ_ZONE_ID_DRAGONCRYPT, "dragoncrypt"},
    {EQ_ZONE_ID_FEERROTT2, "feerrott2"},
    {EQ_ZONE_ID_THULEHOUSE1, "thulehouse1"},
    {EQ_ZONE_ID_THULEHOUSE2, "thulehouse2"},
    {EQ_ZONE_ID_HOUSEGARDEN, "housegarden"},
    {EQ_ZONE_ID_THULELIBRARY, "thulelibrary"},
    {EQ_ZONE_ID_WELL, "well"},
    {EQ_ZONE_ID_FALLEN, "fallen"},
    {EQ_ZONE_ID_MORELLCASTLE, "morellcastle"},
    {EQ_ZONE_ID_SOMNIUM, "somnium"},
    {EQ_ZONE_ID_ALKABORMARE, "alkabormare"},
    {EQ_ZONE_ID_MIRAGULMARE, "miragulmare"},
    {EQ_ZONE_ID_THULEDREAM, "thuledream"},
    {EQ_ZONE_ID_NEIGHBORHOOD, "neighborhood"},
    {EQ_ZONE_ID_PHYLACTERY, "phylactery"},
    {EQ_ZONE_ID_PHINTERIOR3A1, "phinterior3a1"},
    {EQ_ZONE_ID_PHINTERIOR3A2, "phinterior3a2"},
    {EQ_ZONE_ID_PHINTERIOR3A3, "phinterior3a3"},
    {EQ_ZONE_ID_PHINTERIOR1A1, "phinterior1a1"},
    {EQ_ZONE_ID_PHINTERIOR1A2, "phinterior1a2"},
    {EQ_ZONE_ID_PHINTERIOR1A3, "phinterior1a3"},
    {EQ_ZONE_ID_PHINTERIOR1A3, "phinterior1a3"},
    {EQ_ZONE_ID_PHINTERIOR1B1, "phinterior1b1"},
    {EQ_ZONE_ID_PHINTERIOR1D1, "phinterior1d1"},
    {EQ_ZONE_ID_ARGATH, "argath"},
    {EQ_ZONE_ID_ARELIS, "arelis"},
    {EQ_ZONE_ID_SARITHCITY, "sarithcity"},
    {EQ_ZONE_ID_RUBAK, "rubak"},
    {EQ_ZONE_ID_BEASTDOMAIN, "beastdomain"},
    {EQ_ZONE_ID_RESPLENDENT, "resplendent"},
    {EQ_ZONE_ID_PILLARSALRA, "pillarsalra"},
    {EQ_ZONE_ID_WINDSONG, "windsong"},
    {EQ_ZONE_ID_CITYOFBRONZE, "cityofbronze"},
    {EQ_ZONE_ID_SEPULCHER, "sepulcher"},
    {EQ_ZONE_ID_EASTSEPULCHER, "eastsepulcher"},
    {EQ_ZONE_ID_WESTSEPULCHER, "westsepulcher"},
    {EQ_ZONE_ID_SHADOWEDMOUNT, "shadowedmount"},
    {EQ_ZONE_ID_GUILDHALLLRG, "guildhalllrg"},
    {EQ_ZONE_ID_GUILDHALLSML, "guildhallsml"},
    {EQ_ZONE_ID_PLHOGRINTERIORS1A1, "plhogrinteriors1a1"},
    {EQ_ZONE_ID_PLHOGRINTERIORS1A2, "plhogrinteriors1a2"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3A1, "plhogrinteriors3a1"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3A2, "plhogrinteriors3a2"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3B1, "plhogrinteriors3b1"},
    {EQ_ZONE_ID_PLHOGRINTERIORS3B2, "plhogrinteriors3b2"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A1, "plhdkeinteriors1a1"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A2, "plhdkeinteriors1a2"},
    {EQ_ZONE_ID_PLHDKEINTERIORS1A3, "plhdkeinteriors1a3"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A1, "plhdkeinteriors3a1"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A2, "plhdkeinteriors3a2"},
    {EQ_ZONE_ID_PLHDKEINTERIORS3A3, "plhdkeinteriors3a3"},
    {EQ_ZONE_ID_GUILDHALL3, "guildhall3"},
    {EQ_ZONE_ID_KAELSHARD, "kaelshard"},
    {EQ_ZONE_ID_CRYSTALSHARD, "crystalshard"},
    {EQ_ZONE_ID_SHARDSLANDING, "shardslanding"},
    {EQ_ZONE_ID_XORBB, "xorbb"},
    {EQ_ZONE_ID_BREEDINGGROUNDS, "breedinggrounds"},
    {EQ_ZONE_ID_EVILTREE, "eviltree"},
    {EQ_ZONE_ID_GRELLETH, "grelleth"},
    {EQ_ZONE_ID_CHAPTERHOUSE, "chapterhouse"},
    {EQ_ZONE_ID_PHINTERIORTREE, "phinteriortree"},
    {EQ_ZONE_ID_CHELSITHREBORN, "chelsithreborn"},
    {EQ_ZONE_ID_POSHADOW, "poshadow"},
    {EQ_ZONE_ID_HEARTOFFEAR, "heartoffear"},
    {EQ_ZONE_ID_HEARTOFFEARB, "heartoffearb"},
    {EQ_ZONE_ID_HEARTOFFEARC, "heartoffearc"},
    {EQ_ZONE_ID_NERIAKD, "neriakd"},
    {EQ_ZONE_ID_BIXIEWARFRONT, "bixiewarfront"},
    {EQ_ZONE_ID_DEADHILLS, "deadhills"},
    {EQ_ZONE_ID_ETHERNERE, "ethernere"},
    {EQ_ZONE_ID_THEVOIDH, "thevoidh"},
    {EQ_ZONE_ID_PLHBIXIEINT, "plhbixieint"},
    {EQ_ZONE_ID_TOWEROFROT, "towerofrot"},
    {EQ_ZONE_ID_ARGINHIZ, "arginhiz"},
    {EQ_ZONE_ID_ARXMENTIS, "arxmentis"},
    {EQ_ZONE_ID_BROTHERISLAND, "brotherisland"},
    {EQ_ZONE_ID_KATTACASTRUMB, "kattacastrumb"},
    {EQ_ZONE_ID_DREDGE, "dredge"},
    {EQ_ZONE_ID_ENDLESSCAVERNS, "endlesscaverns"},
    {EQ_ZONE_ID_THULIASAUR, "thuliasaur"},
    {EQ_ZONE_ID_DEGMAR, "degmar"},
    {EQ_ZONE_ID_TEMPESTTEMPLE, "tempesttemple"},
    {EQ_ZONE_ID_PLHPIRATESHIPINT, "plhpirateshipint"},
    {EQ_ZONE_ID_EXALTED, "exalted"},
    {EQ_ZONE_ID_COSUL, "cosul"},
    {EQ_ZONE_ID_CODECAYB, "codecayb"},
    {EQ_ZONE_ID_EXALTEDB, "exaltedb"},
    {EQ_ZONE_ID_POHEALTH, "pohealth"},
    {EQ_ZONE_ID_DROGAB, "drogab"},
    {EQ_ZONE_ID_SCORCHEDWOODS, "scorchedwoods"},
    {EQ_ZONE_ID_FRONTIERMTNSB, "frontiermtnsb"},
    {EQ_ZONE_ID_KORSHAEXT, "korshaext"},
    {EQ_ZONE_ID_KORSHAINT, "korshaint"},
    {EQ_ZONE_ID_LCEANIUM, "lceanium"},
    {EQ_ZONE_ID_CHARDOKTWO, "chardoktwo"},
    {EQ_ZONE_ID_CHARASISB, "charasisb"},
    {EQ_ZONE_ID_GOROWYN, "gorowyn"},
    {EQ_ZONE_ID_CHARASISTWO, "charasistwo"},
    {EQ_ZONE_ID_SKYFIRETWO, "skyfiretwo"},
    {EQ_ZONE_ID_OVERTHERETWO, "overtheretwo"},
    {EQ_ZONE_ID_VEESHANTWO, "veeshantwo"},
    {EQ_ZONE_ID_TRIALSOFSMOKE, "trialsofsmoke"},
    {EQ_ZONE_ID_STRATOS, "stratos"},
    {EQ_ZONE_ID_AALISHAI, "aalishai"},
    {EQ_ZONE_ID_EMPYR, "empyr"},
    {EQ_ZONE_ID_ESIANTI, "esianti"},
    {EQ_ZONE_ID_MEARATAS, "mearatas"},
    {EQ_ZONE_ID_CHAMBEROFTEARS, "chamberoftears"},
    {EQ_ZONE_ID_CLZ_ANNIVERSARY, "clz-anniversary"},
    {EQ_ZONE_ID_CLZ_AUTUMN, "clz-autumn"},
    {EQ_ZONE_ID_CLZ_FROSTFELL, "clz-frostfell"},
    {EQ_ZONE_ID_CLZ_SPRING, "clz-spring"},
    {EQ_ZONE_ID_CLZ_WINTER, "clz-winter"},
    {EQ_ZONE_ID_POMISCHIEF, "pomischief"},
    {EQ_ZONE_ID_BURNEDWOODS, "burnedwoods"},
    {EQ_ZONE_ID_INTERIORWALLTEST, "interiorwalltest"},
    {EQ_ZONE_ID_GNOMEMTN, "gnomemtn"},
};
