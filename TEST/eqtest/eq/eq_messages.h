#pragma once

#include <cstdint>

namespace EQMessage
{
    typedef struct _CEverQuest__StartCasting
    {
/* 0x00 */ uint32_t SpellID;
/* 0x04 */ uint16_t SpawnID;
/* 0x06 */ uint16_t SpellCastTime;
    } CEverQuest__StartCasting, *CEverQuest__StartCasting_ptr;
} // namespace EQMessage
