#pragma once

#define EQ_MACRO_FunctionAtAddress(function,offset) __declspec(naked) function\
{\
    __asm{mov eax, offset};\
    __asm{jmp eax};\
}

#define EQ_MACRO_FunctionAtVariableAddress(function,variable) __declspec(naked) function\
{\
    __asm{mov eax, [variable]};\
    __asm{jmp eax};\
}

#define EQ_MACRO_FunctionAtVirtualAddress(function,virtualoffset) __declspec(naked) function\
{\
    __asm{mov eax, [ecx]};\
    __asm{lea eax, [eax+virtualoffset]};\
    __asm{mov eax, [eax]};\
    __asm{jmp eax};\
}

#define EQ_MACRO_AddDetour(functionName) EQAPP_REAL_##functionName =\
(EQ_FUNCTION_TYPE_##functionName)DetourFunction((PBYTE)EQ_ADDRESS_FUNCTION_##functionName, (PBYTE)EQAPP_DETOUR_##functionName)

#define EQ_MACRO_RemoveDetour(functionName) DetourRemove((PBYTE)EQAPP_REAL_##functionName, (PBYTE)EQAPP_DETOUR_##functionName)

