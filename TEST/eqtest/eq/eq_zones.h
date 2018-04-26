#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#define EQ_ZONE_ID_BAZAAR         151 // The Bazaar
#define EQ_ZONE_ID_NEXUS          152 // The Nexus
#define EQ_ZONE_ID_POKNOWLEDGE    202 // Plane of Knowledge
#define EQ_ZONE_ID_POTRANQUILITY  203 // Plane of Tranquility
#define EQ_ZONE_ID_GUILDLOBBY     344 // The Guild Lobby
#define EQ_ZONE_ID_GUILDHALL      345 // Guild Hall
#define EQ_ZONE_ID_BARTER         346 // The Barter Hall

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_ZONE_NAME =
{
    {EQ_ZONE_ID_BAZAAR,           "The Bazaar"},
    {EQ_ZONE_ID_NEXUS,            "The Nexus"},
    {EQ_ZONE_ID_POKNOWLEDGE,      "Plane of Knowledge"},
    {EQ_ZONE_ID_POTRANQUILITY,    "Plane of Tranquility"},
    {EQ_ZONE_ID_GUILDLOBBY,       "The Guild Lobby"},
    {EQ_ZONE_ID_GUILDHALL,        "Guild Hall"},
    {EQ_ZONE_ID_BARTER,           "The Barter Hall"},
};

std::unordered_map<uint32_t, std::string> EQ_STRING_MAP_ZONE_SHORT_NAME =
{
    {EQ_ZONE_ID_BAZAAR,           "bazaar"},
    {EQ_ZONE_ID_NEXUS,            "nexus"},
    {EQ_ZONE_ID_POKNOWLEDGE,      "poknowledge"},
    {EQ_ZONE_ID_POTRANQUILITY,    "potranquility"},
    {EQ_ZONE_ID_GUILDLOBBY,       "guildlobby"},
    {EQ_ZONE_ID_GUILDHALL,        "guildhall"},
    {EQ_ZONE_ID_BARTER,           "barter"},
};
