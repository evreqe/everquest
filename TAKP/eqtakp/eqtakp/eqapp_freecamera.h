#pragma once

bool g_freeCameraIsEnabled = false;

float g_freeCameraMultiplier = 1.0f;

void EQAPP_FreeCamera_Toggle();
void EQAPP_FreeCamera_SetEnabled(bool bEnabled);
void EQAPP_FreeCamera_Execute();
bool EQAPP_FreeCamera_HandleEvent_ProcessKey(int keyID);
bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FreeCamera_Toggle()
{
    if (g_freeCameraIsEnabled == true)
    {
        EQAPP_FreeCamera_SetEnabled(false);
    }
    else
    {
        EQAPP_FreeCamera_SetEnabled(true);
    }
}

void EQAPP_FreeCamera_SetEnabled(bool bEnabled)
{
    uint32_t baseAddress = EQ_ReadMemory<uint32_t>(EQ_ADDRESS_POINTER_EQGraphicsDLL__t3dSetCameraLocation);

    uint32_t address = 0;
    DWORD oldProtection = 0;
    DWORD tempProtection = 0;

    if (bEnabled == true)
    {
        // NOP the instructions so that the game will not update the camera position

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x90\x90\x90", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }
    else
    {
        // restore the instructions to their default values

        address = baseAddress + 0x4B; // Camera Y
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x01", 2, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 2, oldProtection, &tempProtection);

        address = baseAddress + 0x50; // Camera X
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x41\x04", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);

        address = baseAddress + 0x56; // Camera Z
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, PAGE_EXECUTE_READWRITE, &oldProtection);
        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, "\x89\x51\x08", 3, 0);
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, 3, oldProtection, &tempProtection);
    }

    if (bEnabled == true)
    {
        EQ_SetCameraView(EQ_CAMERA_VIEW_FIRST_PERSON);
    }

    g_freeCameraIsEnabled = bEnabled;

    EQAPP_PrintBool("Free Camera", g_freeCameraIsEnabled);
}

void EQAPP_FreeCamera_Execute()
{
    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        return;
    }

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

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

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

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

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

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

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        float cameraY = camera->Y;
        float cameraX = camera->X;
        float cameraZ = camera->Z;

        float cameraHeading = camera->Heading;
        float cameraPitch   = camera->Pitch;

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

        camera->Y = cameraY;
        camera->X = cameraX;
        camera->Z = cameraZ;
    }
}

bool EQAPP_FreeCamera_HandleEvent_ProcessKey(int keyID)
{
    if (keyID == EQ_KEY_UP_ARROW || keyID == EQ_KEY_DOWN_ARROW || keyID == EQ_KEY_LEFT_ARROW || keyID == EQ_KEY_RIGHT_ARROW || keyID == EQ_KEY_NUMLOCK)
    {
        return true;
    }

    return false;
}

bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1 && zero != 0)
    {
        return false;
    }

    if
    (
        commandID == EQ_EXECUTECMD_TOGGLECAM  ||
        commandID == EQ_EXECUTECMD_FORWARD    ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_JUMP       ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        return true;
    }

    return false;
}

