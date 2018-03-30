#pragma once

#include <cstdint>

namespace EQMessage
{
    typedef struct _CEverQuest__StartCasting
    {
        uint32_t SpellID;
        uint16_t SpawnID;
        uint16_t SpellCastTime;
    } CEverQuest__StartCasting, *CEverQuest__StartCasting_ptr;
} // namespace EQMessage
