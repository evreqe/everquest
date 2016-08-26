#ifndef EQAPP_IMGUI_H
#define EQAPP_IMGUI_H

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <imgui.h>
#include "imgui_impl_glfw.h"

#define IM_NEWLINE "\r\n"
#define IM_ARRAYSIZE(_ARR)  ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define IM_MAX(_A,_B)       (((_A) >= (_B)) ? (_A) : (_B))

bool g_bImguiShow = true;
bool g_bImguiHide = false;

#endif // EQAPP_IMGUI_H
