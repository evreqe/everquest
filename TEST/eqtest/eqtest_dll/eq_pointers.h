#pragma once

#include "eq.h"
#include "eq_structures.h"
#include "eq_classes.h"

/* CEverQuest */

EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr = (EQClass::CEverQuest**)EQ_ADDRESS_POINTER_CEverQuest;
#define EQ_CLASS_POINTER_CEverQuest (*EQ_CLASS_POINTER_CEverQuest_pptr)
