#ifndef EQAPP_DETOURS_H
#define EQAPP_DETOURS_H

EQ_FUNCTION_TYPE_Exit EQAPP_REAL_Exit = NULL;
EQ_FUNCTION_TYPE_DrawNetStatus EQAPP_REAL_DrawNetStatus = NULL;
EQ_FUNCTION_TYPE_ExecuteCmd EQAPP_REAL_ExecuteCmd = NULL;
EQ_FUNCTION_TYPE_SetTarget EQAPP_REAL_SetTarget = NULL;

EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor EQAPP_REAL_CDisplay__CreatePlayerActor = NULL;
EQ_FUNCTION_TYPE_CDisplay__DeleteActor EQAPP_REAL_CDisplay__DeleteActor = NULL;
//EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteState EQAPP_REAL_CDisplay__SetNameSpriteState = NULL;
//EQ_FUNCTION_TYPE_CDisplay__SetNameSpriteTint EQAPP_REAL_CDisplay__SetNameSpriteTint = NULL;

EQ_FUNCTION_TYPE_CEverQuest__dsp_chat EQAPP_REAL_CEverQuest__dsp_chat = NULL;
EQ_FUNCTION_TYPE_CEverQuest__EnterZone EQAPP_REAL_CEverQuest__EnterZone = NULL;
//EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd EQAPP_REAL_CEverQuest__InterpretCmd = NULL;
EQ_FUNCTION_TYPE_CEverQuest__MoveToZone EQAPP_REAL_CEverQuest__MoveToZone = NULL;
EQ_FUNCTION_TYPE_CEverQuest__SetGameState EQAPP_REAL_CEverQuest__SetGameState = NULL;
EQ_FUNCTION_TYPE_CEverQuest__StartCasting EQAPP_REAL_CEverQuest__StartCasting = NULL;

//EQ_FUNCTION_TYPE_CMapViewWnd__dCMapViewWnd EQAPP_REAL_CMapViewWnd__dCMapViewWnd = NULL;
EQ_FUNCTION_TYPE_CMapViewWnd__DrawMap EQAPP_REAL_CMapViewWnd__DrawMap = NULL;

EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate EQAPP_REAL_EQ_Character__eqspa_movement_rate = NULL;

EQ_FUNCTION_TYPE_EQPlayer__ChangePosition EQAPP_REAL_EQPlayer__ChangePosition = NULL;
EQ_FUNCTION_TYPE_EQPlayer__do_change_form EQAPP_REAL_EQPlayer__do_change_form = NULL;
EQ_FUNCTION_TYPE_EQPlayer__SetRace EQAPP_REAL_EQPlayer__SetRace = NULL;

EQ_FUNCTION_TYPE_MapViewMap__Save EQAPP_REAL_MapViewMap__Save = NULL;
EQ_FUNCTION_TYPE_MapViewMap__SaveEx EQAPP_REAL_MapViewMap__SaveEx = NULL;

void EQAPP_Detours_Add();
void EQAPP_Detours_Remove();

int __cdecl EQAPP_DETOUR_Exit();
int __cdecl EQAPP_DETOUR_DrawNetStatus(int a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned long a8, long a9, unsigned long a10);
int __cdecl EQAPP_DETOUR_ExecuteCmd(DWORD a1, BOOL a2, PVOID a3);
int __cdecl EQAPP_DETOUR_SetTarget(DWORD a1, const char* a2);

int __fastcall EQAPP_DETOUR_CDisplay__CreatePlayerActor(void* pThis, void* not_used, int a1, int a2, int a3, int a4, int a5);
int __fastcall EQAPP_DETOUR_CDisplay__DeleteActor(void* pThis, void* not_used, DWORD a1);

int __fastcall EQAPP_DETOUR_CEverQuest__dsp_chat(void* pThis, void* not_used, const char* a1, int a2, bool a3);
int __fastcall EQAPP_DETOUR_CEverQuest__EnterZone(void* pThis, void* not_used, struct HWND__* a1);
//int __fastcall EQAPP_DETOUR_CEverQuest__InterpretCmd(void* pThis, void* not_used, DWORD a1, const char* a2);
int __fastcall EQAPP_DETOUR_CEverQuest__MoveToZone(void* pThis, void* not_used, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
int __fastcall EQAPP_DETOUR_CEverQuest__SetGameState(void* pThis, void* not_used, int a1);
int __fastcall EQAPP_DETOUR_CEverQuest__StartCasting(void* pThis, void* not_used, int a1);

//int __fastcall EQAPP_DETOUR_CMapViewWnd__dCMapViewWnd(void* pThis, void* not_used);
int __fastcall EQAPP_DETOUR_CMapViewWnd__DrawMap(void* pThis, void* not_used, int a1, int a2, int a3, int a4);

int __fastcall EQAPP_DETOUR_EQ_Character__eqspa_movement_rate(void* pThis, void* not_used, int a1);

int __fastcall EQAPP_DETOUR_EQPlayer__ChangePosition(void* pThis, void* not_used, BYTE a1);
int __fastcall EQAPP_DETOUR_EQPlayer__do_change_form(void* pThis, void* not_used, PEQCHANGEFORM a1);
int __fastcall EQAPP_DETOUR_EQPlayer__SetRace(void* pThis, void* not_used, int a1);

int __fastcall EQAPP_DETOUR_MapViewMap__Save(void* pThis, void* not_used, char* a1);
int __fastcall EQAPP_DETOUR_MapViewMap__SaveEx(void* pThis, void* not_used, char* a1, int a2);

void EQAPP_Detours_Add()
{
    EQAPP_REAL_Exit = (EQ_FUNCTION_TYPE_Exit)DetourFunction((PBYTE)EQ_FUNCTION_Exit, (PBYTE)EQAPP_DETOUR_Exit);
    EQAPP_REAL_DrawNetStatus = (EQ_FUNCTION_TYPE_DrawNetStatus)DetourFunction((PBYTE)EQ_FUNCTION_DrawNetStatus, (PBYTE)EQAPP_DETOUR_DrawNetStatus);
    EQAPP_REAL_ExecuteCmd = (EQ_FUNCTION_TYPE_ExecuteCmd)DetourFunction((PBYTE)EQ_FUNCTION_ExecuteCmd, (PBYTE)EQAPP_DETOUR_ExecuteCmd);
    EQAPP_REAL_SetTarget = (EQ_FUNCTION_TYPE_SetTarget)DetourFunction((PBYTE)EQ_FUNCTION_SetTarget, (PBYTE)EQAPP_DETOUR_SetTarget);

    EQAPP_REAL_CDisplay__CreatePlayerActor = (EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)DetourFunction((PBYTE)EQ_FUNCTION_CDisplay__CreatePlayerActor, (PBYTE)EQAPP_DETOUR_CDisplay__CreatePlayerActor);
    EQAPP_REAL_CDisplay__DeleteActor = (EQ_FUNCTION_TYPE_CDisplay__DeleteActor)DetourFunction((PBYTE)EQ_FUNCTION_CDisplay__DeleteActor, (PBYTE)EQAPP_DETOUR_CDisplay__DeleteActor);

    EQAPP_REAL_CEverQuest__dsp_chat = (EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__dsp_chat, (PBYTE)EQAPP_DETOUR_CEverQuest__dsp_chat);
    EQAPP_REAL_CEverQuest__EnterZone = (EQ_FUNCTION_TYPE_CEverQuest__EnterZone)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__EnterZone, (PBYTE)EQAPP_DETOUR_CEverQuest__EnterZone);
    //EQAPP_REAL_CEverQuest__InterpretCmd = (EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__InterpretCmd, (PBYTE)EQAPP_DETOUR_CEverQuest__InterpretCmd);
    EQAPP_REAL_CEverQuest__MoveToZone = (EQ_FUNCTION_TYPE_CEverQuest__MoveToZone)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__MoveToZone, (PBYTE)EQAPP_DETOUR_CEverQuest__MoveToZone);
    EQAPP_REAL_CEverQuest__SetGameState = (EQ_FUNCTION_TYPE_CEverQuest__SetGameState)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__SetGameState, (PBYTE)EQAPP_DETOUR_CEverQuest__SetGameState);
    EQAPP_REAL_CEverQuest__StartCasting = (EQ_FUNCTION_TYPE_CEverQuest__StartCasting)DetourFunction((PBYTE)EQ_FUNCTION_CEverQuest__StartCasting, (PBYTE)EQAPP_DETOUR_CEverQuest__StartCasting);

    //EQAPP_REAL_CMapViewWnd__dCMapViewWnd = (EQ_FUNCTION_TYPE_CMapViewWnd__dCMapViewWnd)DetourFunction((PBYTE)EQ_FUNCTION_CMapViewWnd__dCMapViewWnd, (PBYTE)EQAPP_DETOUR_CMapViewWnd__dCMapViewWnd);
    EQAPP_REAL_CMapViewWnd__DrawMap = (EQ_FUNCTION_TYPE_CMapViewWnd__DrawMap)DetourFunction((PBYTE)EQ_FUNCTION_CMapViewWnd__DrawMap, (PBYTE)EQAPP_DETOUR_CMapViewWnd__DrawMap);

    EQAPP_REAL_EQ_Character__eqspa_movement_rate = (EQ_FUNCTION_TYPE_EQ_Character__eqspa_movement_rate)DetourFunction((PBYTE)EQ_FUNCTION_EQ_Character__eqspa_movement_rate, (PBYTE)EQAPP_DETOUR_EQ_Character__eqspa_movement_rate);

    EQAPP_REAL_EQPlayer__ChangePosition = (EQ_FUNCTION_TYPE_EQPlayer__ChangePosition)DetourFunction((PBYTE)EQ_FUNCTION_EQPlayer__ChangePosition, (PBYTE)EQAPP_DETOUR_EQPlayer__ChangePosition);
    EQAPP_REAL_EQPlayer__do_change_form = (EQ_FUNCTION_TYPE_EQPlayer__do_change_form)DetourFunction((PBYTE)EQ_FUNCTION_EQPlayer__do_change_form, (PBYTE)EQAPP_DETOUR_EQPlayer__do_change_form);
    EQAPP_REAL_EQPlayer__SetRace = (EQ_FUNCTION_TYPE_EQPlayer__SetRace)DetourFunction((PBYTE)EQ_FUNCTION_EQPlayer__SetRace, (PBYTE)EQAPP_DETOUR_EQPlayer__SetRace);

    EQAPP_REAL_MapViewMap__Save = (EQ_FUNCTION_TYPE_MapViewMap__Save)DetourFunction((PBYTE)EQ_FUNCTION_MapViewMap__Save, (PBYTE)EQAPP_DETOUR_MapViewMap__Save);
    EQAPP_REAL_MapViewMap__SaveEx = (EQ_FUNCTION_TYPE_MapViewMap__SaveEx)DetourFunction((PBYTE)EQ_FUNCTION_MapViewMap__SaveEx, (PBYTE)EQAPP_DETOUR_MapViewMap__SaveEx);
}

void EQAPP_Detours_Remove()
{
    DetourRemove((PBYTE)EQAPP_REAL_Exit, (PBYTE)EQAPP_DETOUR_Exit);
    DetourRemove((PBYTE)EQAPP_REAL_DrawNetStatus, (PBYTE)EQAPP_DETOUR_DrawNetStatus);
    DetourRemove((PBYTE)EQAPP_REAL_ExecuteCmd, (PBYTE)EQAPP_DETOUR_ExecuteCmd);
    DetourRemove((PBYTE)EQAPP_REAL_SetTarget, (PBYTE)EQAPP_DETOUR_SetTarget);

    DetourRemove((PBYTE)EQAPP_REAL_CDisplay__CreatePlayerActor, (PBYTE)EQAPP_DETOUR_CDisplay__CreatePlayerActor);
    DetourRemove((PBYTE)EQAPP_REAL_CDisplay__DeleteActor, (PBYTE)EQAPP_DETOUR_CDisplay__DeleteActor);

    DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__dsp_chat, (PBYTE)EQAPP_DETOUR_CEverQuest__dsp_chat);
    DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__EnterZone, (PBYTE)EQAPP_DETOUR_CEverQuest__EnterZone);
    //DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__InterpretCmd, (PBYTE)EQAPP_DETOUR_CEverQuest__InterpretCmd);
    DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__MoveToZone, (PBYTE)EQAPP_DETOUR_CEverQuest__MoveToZone);
    DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__SetGameState, (PBYTE)EQAPP_DETOUR_CEverQuest__SetGameState);
    DetourRemove((PBYTE)EQAPP_REAL_CEverQuest__StartCasting, (PBYTE)EQAPP_DETOUR_CEverQuest__StartCasting);

    //DetourRemove((PBYTE)EQAPP_REAL_CMapViewWnd__dCMapViewWnd, (PBYTE)EQAPP_DETOUR_CMapViewWnd__dCMapViewWnd);
    DetourRemove((PBYTE)EQAPP_REAL_CMapViewWnd__DrawMap, (PBYTE)EQAPP_DETOUR_CMapViewWnd__DrawMap);

    DetourRemove((PBYTE)EQAPP_REAL_EQ_Character__eqspa_movement_rate, (PBYTE)EQAPP_DETOUR_EQ_Character__eqspa_movement_rate);

    DetourRemove((PBYTE)EQAPP_REAL_EQPlayer__ChangePosition, (PBYTE)EQAPP_DETOUR_EQPlayer__ChangePosition);
    DetourRemove((PBYTE)EQAPP_REAL_EQPlayer__do_change_form, (PBYTE)EQAPP_DETOUR_EQPlayer__do_change_form);
    DetourRemove((PBYTE)EQAPP_REAL_EQPlayer__SetRace, (PBYTE)EQAPP_DETOUR_EQPlayer__SetRace);

    DetourRemove((PBYTE)EQAPP_REAL_MapViewMap__Save, (PBYTE)EQAPP_DETOUR_MapViewMap__Save);
    DetourRemove((PBYTE)EQAPP_REAL_MapViewMap__SaveEx, (PBYTE)EQAPP_DETOUR_MapViewMap__SaveEx);
}

#endif // EQAPP_DETOURS_H
