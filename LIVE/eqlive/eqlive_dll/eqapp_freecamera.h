#pragma once

bool g_FreeCameraIsEnabled = false;

float g_FreeCameraMultiplierDefault = 1.0f;
float g_FreeCameraMultiplierFast = 4.0f;

float g_FreeCameraMultiplier = g_FreeCameraMultiplierDefault;

void EQAPP_FreeCamera_Toggle();
void EQAPP_FreeCamera_On();
void EQAPP_FreeCamera_Off();
void EQAPP_FreeCamera_Execute();
bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero);

void EQAPP_FreeCamera_Toggle()
{
    EQ_ToggleBool(g_FreeCameraIsEnabled);
    EQAPP_PrintBool("Free Camera", g_FreeCameraIsEnabled);

    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);
    EQ_CenterView();
}

void EQAPP_FreeCamera_On()
{
    if (g_FreeCameraIsEnabled == false)
    {
        EQAPP_FreeCamera_Toggle();
    }
}

void EQAPP_FreeCamera_Off()
{
    if (g_FreeCameraIsEnabled == true)
    {
        EQAPP_FreeCamera_Toggle();
    }
}

void EQAPP_FreeCamera_Execute()
{
    if (EQAPP_IsForegroundWindowCurrentProcessID() == false)
    {
        return;
    }

    auto camera = EQ_GetCamera();
    if (camera == NULL)
    {
        return;
    }

    EQ_ExecuteCommand(EQ_EXECUTECMD_FIRST_PERSON_CAMERA, 1);

    if (EQAPP_IsVKKeyDown(VK_CONTROL) == true)
    {
        g_FreeCameraMultiplier = g_FreeCameraMultiplierFast;
    }
    else
    {
        g_FreeCameraMultiplier = g_FreeCameraMultiplierDefault;
    }

    if (EQAPP_IsVKKeyDown(VK_UP) == true)
    {
        float cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
        float cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
        float cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

        float cameraHeading = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_HEADING);
        float cameraPitch   = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_PITCH);

        bool bIsLookingStraightUpOrDown = true;

        if (cameraPitch > EQ_CAMERA_PITCH_MIN && cameraPitch < EQ_CAMERA_PITCH_MAX)
        {
            bIsLookingStraightUpOrDown = false;
        }

        cameraHeading = cameraHeading + 128.0f;

        cameraHeading = EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = cameraPitch + std::fabs(EQ_CAMERA_PITCH_DEFAULT); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = std::sinf(cameraHeadingRadians);
        float addX = std::cosf(cameraHeadingRadians);
        float addZ = std::sinf(cameraPitchRadians);

        if (bIsLookingStraightUpOrDown == false)
        {
            cameraY += addY * g_FreeCameraMultiplier;
            cameraX -= addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Y, cameraY);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_X, cameraX);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Z, cameraZ);
    }

    if (EQAPP_IsVKKeyDown(VK_DOWN) == true)
    {
        float cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
        float cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
        float cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

        float cameraHeading = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_HEADING);
        float cameraPitch   = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_PITCH);

        bool bIsLookingStraightUpOrDown = true;

        if (cameraPitch > EQ_CAMERA_PITCH_MIN && cameraPitch < EQ_CAMERA_PITCH_MAX)
        {
            bIsLookingStraightUpOrDown = false;
        }

        cameraHeading = cameraHeading - 128.0f;

        cameraHeading = EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = cameraPitch + std::fabs(EQ_CAMERA_PITCH_DEFAULT); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = std::sinf(cameraHeadingRadians);
        float addX = std::cosf(cameraHeadingRadians);
        float addZ = std::sinf(cameraPitchRadians);

        if (bIsLookingStraightUpOrDown == false)
        {
            cameraY += addY * g_FreeCameraMultiplier;
            cameraX -= addX * g_FreeCameraMultiplier;
        }

        cameraZ -= addZ * g_FreeCameraMultiplier;

        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Y, cameraY);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_X, cameraX);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Z, cameraZ);
    }

    if (EQAPP_IsVKKeyDown(VK_LEFT) == true)
    {
        float cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
        float cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
        float cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

        float cameraHeading = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_HEADING);
        float cameraPitch   = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_PITCH);

        bool bIsLookingStraightUpOrDown = true;

        if (cameraPitch > EQ_CAMERA_PITCH_MIN && cameraPitch < EQ_CAMERA_PITCH_MAX)
        {
            bIsLookingStraightUpOrDown = false;
        }

        cameraHeading = EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = cameraPitch + std::fabs(EQ_CAMERA_PITCH_DEFAULT); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = std::sinf(cameraHeadingRadians);
        float addX = std::cosf(cameraHeadingRadians);
        float addZ = std::sinf(cameraPitchRadians);

        if (bIsLookingStraightUpOrDown == false)
        {
            cameraY -= addY * g_FreeCameraMultiplier;
            cameraX += addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Y, cameraY);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_X, cameraX);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Z, cameraZ);
    }

    if (EQAPP_IsVKKeyDown(VK_RIGHT) == true)
    {
        float cameraY = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Y);
        float cameraX = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_X);
        float cameraZ = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_Z);

        float cameraHeading = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_HEADING);
        float cameraPitch   = EQ_ReadMemory<float>(camera + EQ_OFFSET_CCamera_PITCH);

        bool bIsLookingStraightUpOrDown = true;

        if (cameraPitch > EQ_CAMERA_PITCH_MIN && cameraPitch < EQ_CAMERA_PITCH_MAX)
        {
            bIsLookingStraightUpOrDown = false;
        }

        cameraHeading = cameraHeading + 256.0f;

        cameraHeading = EQ_FixHeading(cameraHeading);

        float cameraHeadingRadians = EQ_GetRadians(cameraHeading);

        cameraPitch = cameraPitch + std::fabs(EQ_CAMERA_PITCH_DEFAULT); // remove negative offset from camera pitch

        float cameraPitchRadians = EQ_GetRadians(cameraPitch);

        float addY = std::sinf(cameraHeadingRadians);
        float addX = std::cosf(cameraHeadingRadians);
        float addZ = std::sinf(cameraPitchRadians);

        if (bIsLookingStraightUpOrDown == false)
        {
            cameraY -= addY * g_FreeCameraMultiplier;
            cameraX += addX * g_FreeCameraMultiplier;
        }

        cameraZ += addZ * g_FreeCameraMultiplier;

        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Y, cameraY);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_X, cameraX);
        EQ_WriteMemory<float>(camera + EQ_OFFSET_CCamera_Z, cameraZ);
    }
}

bool EQAPP_FreeCamera_HandleEvent_ExecuteCmd(uint32_t commandID, int isActive, int zero)
{
    if (isActive != 1)
    {
        return false;
    }

    if (commandID == EQ_EXECUTECMD_SIT_STAND || commandID == EQ_EXECUTECMD_DUCK || commandID == EQ_EXECUTECMD_JUMP)
    {
        EQAPP_FreeCamera_Off();
        return true;
    }

    if
    (
        commandID == EQ_EXECUTECMD_TOGGLECAM  ||
        commandID == EQ_EXECUTECMD_FORWARD    ||
        commandID == EQ_EXECUTECMD_BACK       ||
        commandID == EQ_EXECUTECMD_LEFT       ||
        commandID == EQ_EXECUTECMD_RIGHT      ||
        commandID == EQ_EXECUTECMD_AUTORUN
    )
    {
        return true;
    }

    return false;
}

