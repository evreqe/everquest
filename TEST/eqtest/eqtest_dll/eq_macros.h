#pragma once

#define EQ_MACRO_FUNCTION_FunctionAtAddress(function,offset) __declspec(naked) function\
{\
    __asm{mov eax, offset};\
    __asm{jmp eax};\
}

#define EQ_MACRO_FUNCTION_FunctionAtVariableAddress(function,variable) __declspec(naked) function\
{\
    __asm{mov eax, [variable]};\
    __asm{jmp eax};\
}

#define EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(function,virtualoffset) __declspec(naked) function\
{\
    __asm{mov eax, [ecx]};\
    __asm{lea eax, [eax+virtualoffset]};\
    __asm{mov eax, [eax]};\
    __asm{jmp eax};\
}

#define EQ_MACRO_FUNCTION_DefineDetour(functionName) EQ_FUNCTION_TYPE_##functionName EQAPP_REAL_FUNCTION_##functionName = NULL

#define EQ_MACRO_FUNCTION_AddDetour(functionName) EQAPP_REAL_FUNCTION_##functionName =\
(EQ_FUNCTION_TYPE_##functionName)DetourFunction((PBYTE)EQ_ADDRESS_FUNCTION_##functionName, (PBYTE)EQAPP_DETOURED_FUNCTION_##functionName)

#define EQ_MACRO_FUNCTION_RemoveDetour(functionName) DetourRemove((PBYTE)EQAPP_REAL_FUNCTION_##functionName, (PBYTE)EQAPP_DETOURED_FUNCTION_##functionName)
