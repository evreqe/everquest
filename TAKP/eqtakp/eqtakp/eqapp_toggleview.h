#pragma once

bool g_toggleViewIsEnabled = true;

void EQAPP_ToggleView_HandleEvent_CDisplay__ToggleView(void* this_ptr);

void EQAPP_ToggleView_HandleEvent_CDisplay__ToggleView(void* this_ptr)
{
    // force camera to toggle between first person and third person 3 only

    uint32_t cameraView = EQ_GetCameraView();

    if (cameraView == EQ_CAMERA_VIEW_FIRST_PERSON || cameraView == EQ_CAMERA_VIEW_THIRD_PERSON_1 || cameraView == EQ_CAMERA_VIEW_THIRD_PERSON_2)
    {
        EQ_SetCameraView(EQ_CAMERA_VIEW_THIRD_PERSON_3);
    }
}

