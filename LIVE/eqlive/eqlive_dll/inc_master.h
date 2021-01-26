#pragma once

// this is the MASTER include file

// include order is IMPORTANT

// C
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

// C++
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <filesystem>
//#include <format> // C++20
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <set>
//#include <source_location> // C++20
#include <string>
#include <string_view>
#include <sstream>
#include <thread>
#include <unordered_map>
#include <vector>

// Windows
#define _WINSOCKAPI_ // prevent windows.h from including winsock.h, we use winsock2.h instead

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "ws2_32.lib")

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

// DirectX 9
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

// DirectInput
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

// fmt
// https://github.com/fmtlib/fmt
#define FMT_UNICODE 0
#include "fmt/core.h"
#include "fmt/compile.h"
#pragma comment(lib, "fmt.lib")

// spdlog
// https://github.com/gabime/spdlog
#define SPDLOG_TRACE_ON
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#pragma comment(lib, "spdlog.lib")

// tomlplusplus
// https://github.com/marzer/tomlplusplus
#include "toml++/toml.h"

// imgui
// https://github.com/ocornut/imgui
#include "imgui.h"
#include "imgui_internal.h"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

// Microsoft Detours
// https://github.com/microsoft/Detours
#include "detours.h"
#pragma comment(lib, "detours.lib")

// EverQuest
#include "eq.h"
#include "eq_functions.h"

// EQApp
#include "eqapp_utility_ini.h"
#include "eqapp_utility_string.h"
#include "eqapp_utility_timer.h"

#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_addresses.h"

#include "eqapp_console.h"

#include "eqapp_log.h"

#include "eqapp_boxchat.h"

#include "eqapp_detours_prototypes.h"

#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_area.h"
#include "eqapp_autobank.h"
#include "eqapp_autogroup.h"
#include "eqapp_autoinventory.h"
#include "eqapp_autotrade.h"
#include "eqapp_bandolier.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_changeheight.h"
#include "eqapp_chatevent.h"
#include "eqapp_cheat.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_combatmacro.h"
#include "eqapp_followai.h"
#include "eqapp_freecamera.h"
#include "eqapp_killmobs.h"
#include "eqapp_lantern.h"
#include "eqapp_macro.h"
#include "eqapp_namecolor.h"
#include "eqapp_namedspawns.h"
#include "eqapp_noalert.h"
#include "eqapp_nodraw.h"
#include "eqapp_powerlevel.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_speed.h"
#include "eqapp_waypoint.h"
#include "eqapp_windowforeground.h"
#include "eqapp_windowtitle.h"

#include "eqapp_esp.h"

#include "eqapp_hud.h"

#include "eqapp_gui.h"

#include "eqapp_interpretcommand.h"

#include "eqapp_detours.h"

#include "eqapp_config.h"

