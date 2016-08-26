#ifndef EQAPP_FREECAMERA_H
#define EQAPP_FREECAMERA_H

bool g_freeCameraIsEnabled = false;
float g_freeCameraMultiplier = 1.0f;

void EQAPP_FreeCamera_Set(bool bEnabled);
void EQAPP_FreeCamera_Toggle();
void EQAPP_FreeCamera_Keys();

void EQAPP_FreeCamera_Set(bool bEnabled)
{
    // this function uses hardcoded offsets and values

    // updates camera coordinates
    // Y = EQGraphicsDX9.DLL+591A - 89 8F BC000000        - mov [edi+000000BC],ecx
    // X = EQGraphicsDX9.DLL+5923 - 89 97 C0000000        - mov [edi+000000C0],edx
    // Z = EQGraphicsDX9.DLL+592C - 89 87 C4000000        - mov [edi+000000C4],eax

    DWORD baseAddress = EQ_ReadMemory<DWORD>(EQ_GRAPHICS_DLL_POINTER_BASE_ADDRESS);
    if (baseAddress == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "base address is NULL");
        return;
    }

    DWORD address = 0;
    DWORD oldProtection = 0;
    DWORD tempProtection = 0;

    if (bEnabled == true)
    {
        // Camera Y
        address = baseAddress + 0x591A;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90\x90\x90\x90", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);

        // Camera X
        address = baseAddress + 0x5923;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90\x90\x90\x90", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);

        // Camera Z
        address = baseAddress + 0x592C;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90\x90\x90\x90", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);

        EQ_WriteMemory<DWORD>(EQ_CAMERA_VIEW, EQ_CAMERA_VIEW_FIRST_PERSON);
    }
    else
    {
        // Camera Y
        address = baseAddress + 0x591A;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x8F\xBC\x00\x00\x00", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);

        // Camera X
        address = baseAddress + 0x5923;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x97\xC0\x00\x00\x00", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);

        // Camera Z
        address = baseAddress + 0x592C;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x87\xC4\x00\x00\x00", 6, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 6, oldProtection, &tempProtection);
    }

    g_freeCameraIsEnabled = bEnabled;
}

void EQAPP_FreeCamera_Toggle()
{
    if (g_freeCameraIsEnabled == false)
    {
        EQAPP_FreeCamera_Set(true);
    }
    else
    {
        EQAPP_FreeCamera_Set(false);
    }

    EQAPP_PrintBool("Free Camera", g_freeCameraIsEnabled);
}

void EQAPP_FreeCamera_Keys()
{
    if (g_freeCameraIsEnabled == false)
    {
        return;
    }

    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        return;
    }

    DWORD cameraData = EQ_GetCameraData();
    if (cameraData == NULL)
    {
        return;
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        FLOAT cameraY = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y);
        FLOAT cameraX = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X);
        FLOAT cameraZ = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z);

        FLOAT cameraHeading = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_HEADING);
        FLOAT cameraPitch   = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_PITCH);

        cameraHeading = cameraHeading - 128.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_freeCameraMultiplier;
            cameraX += addX * g_freeCameraMultiplier;
        }

        cameraZ += addZ * g_freeCameraMultiplier;

        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y, cameraY);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X, cameraX);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z, cameraZ);
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        FLOAT cameraY = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y);
        FLOAT cameraX = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X);
        FLOAT cameraZ = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z);

        FLOAT cameraHeading = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_HEADING);
        FLOAT cameraPitch   = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_PITCH);

        cameraHeading = cameraHeading - 128.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY += addY * g_freeCameraMultiplier;
            cameraX -= addX * g_freeCameraMultiplier;
        }

        cameraZ -= addZ * g_freeCameraMultiplier;

        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y, cameraY);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X, cameraX);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z, cameraZ);
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        FLOAT cameraY = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y);
        FLOAT cameraX = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X);
        FLOAT cameraZ = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z);

        FLOAT cameraHeading = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_HEADING);
        FLOAT cameraPitch   = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_PITCH);

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_freeCameraMultiplier;
            cameraX += addX * g_freeCameraMultiplier;
        }

        cameraZ += addZ * g_freeCameraMultiplier;

        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y, cameraY);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X, cameraX);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z, cameraZ);
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        FLOAT cameraY = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y);
        FLOAT cameraX = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X);
        FLOAT cameraZ = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z);

        FLOAT cameraHeading = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_HEADING);
        FLOAT cameraPitch   = EQ_ReadMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_PITCH);

        cameraHeading = cameraHeading + 256.0f;

        EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = (float)(cameraPitch + fabs(EQ_CAMERA_PITCH_DEFAULT)); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = sinf(cameraHeadingRadians);
        float addX = cosf(cameraHeadingRadians);
        float addZ = sinf(cameraPitchRadians);

        if (fabs(cameraPitch) < 90.0f)
        {
            cameraY -= addY * g_freeCameraMultiplier;
            cameraX += addX * g_freeCameraMultiplier;
        }

        cameraZ += addZ * g_freeCameraMultiplier;

        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Y, cameraY);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_X, cameraX);
        EQ_WriteMemory<FLOAT>(cameraData + EQ_OFFSET_CAMERA_DATA_Z, cameraZ);
    }
}

#endif // EQAPP_FREECAMERA_H
