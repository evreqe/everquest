#pragma once

template <class T>
T EQ_ReadMemory(uintptr_t address);

template <class T>
void EQ_WriteMemory(uintptr_t address, T value);

template <class T>
T EQ_ReadMemoryProtected(uint32_t address);

template <class T>
void EQ_WriteMemoryProtected(uint32_t address, T value);

void EQ_ReadMemoryString(uint32_t address, size_t size, char result[]);

void EQ_WriteMemoryString(uint32_t address, const char* value);

template <class T>
T EQ_ReadMemory(uintptr_t address)
{
#ifdef _DEBUG
    EQ_Log("EQ_ReadMemory() Address: ", address);
#endif

    T* buffer = (T*)address;
    return (*buffer);
}

template <class T>
void EQ_WriteMemory(uintptr_t address, T value)
{
#ifdef _DEBUG
    EQ_Log("EQ_WriteMemory() Address: ", address);
#endif

    T* buffer = (T*)address;
    *buffer = value;
}

template <class T>
T EQ_ReadMemoryProtected(uint32_t address)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

    T* buffer = (T*)address;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(T), oldProtect, &oldProtect);

    return (*buffer);
}

template <class T>
void EQ_WriteMemoryProtected(uint32_t address, T value)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), PAGE_EXECUTE_READWRITE, &oldProtect);

    T* buffer = (T*)address;
    *buffer = value;

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, sizeof(value), oldProtect, &oldProtect);
}

void EQ_WriteBytesProtected(uint32_t address, char* bytes, size_t size)
{
    DWORD oldProtect;
    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, size, PAGE_EXECUTE_READWRITE, &oldProtect);

    memcpy((LPVOID)address, (LPVOID)bytes, size);

    VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, size, oldProtect, &oldProtect);
}

void EQ_ReadMemoryString(uint32_t address, size_t size, char result[])
{
    char* buffer = new char[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = *(unsigned char*)(address + i);
    }

    result = buffer;

    delete[] buffer;
}

void EQ_WriteMemoryString(uint32_t address, const char* value)
{
    size_t length = strlen(value);

    size_t j = 0;

    for (size_t i = 0; i < length; i++)
    {
        *(unsigned char*)(address + j) = value[i];
        j++;
    }

    *(unsigned char*)(address + j) = '\0';
}
