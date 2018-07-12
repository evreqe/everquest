#pragma once

#ifndef __MQ2_H__
#define __MQ2_H__

#include <windows.h>

#ifdef EQLIB_EXPORTS
#define EQLIB_API extern "C" __declspec(dllexport)
#define EQLIB_VAR extern "C" __declspec(dllexport)
#define EQLIB_OBJECT __declspec(dllexport)
#else
#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)
#endif

#include "MQ2Main/eqgame(Test).h"
#include "MQ2Main/EQData(Test).h"
#include "MQ2Main/EQUIStructs(Test).h"

#endif // __MQ2_H__
