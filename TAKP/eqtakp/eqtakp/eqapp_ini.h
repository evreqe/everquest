#pragma once

#include <string>

#include <windows.h>

int EQAPP_INI_ReadInt(const char* filename, const char* section, const char* key, int defaultValue);
bool EQAPP_INI_ReadBool(const char* filename, const char* section, const char* key, int defaultValue);
float EQAPP_INI_ReadFloat(const char* filename, const char* section, const char* key, float defaultValue);
std::string EQAPP_INI_ReadString(const char* filename, const char* section, const char* key, const char* defaultValue);

int EQAPP_INI_ReadInt(const char* filename, const char* section, const char* key, int defaultValue)
{
    return GetPrivateProfileIntA(section, key, defaultValue, filename);
}

bool EQAPP_INI_ReadBool(const char* filename, const char* section, const char* key, int defaultValue)
{
    int result = GetPrivateProfileIntA(section, key, defaultValue, filename);

    return (result != 0);
}

float EQAPP_INI_ReadFloat(const char* filename, const char* section, const char* key, float defaultValue)
{
    char bufferDefault[128];
    _snprintf_s(bufferDefault, sizeof(bufferDefault), _TRUNCATE, "%f", defaultValue);

    char bufferResult[128];
    GetPrivateProfileStringA(section, key, bufferDefault, bufferResult, sizeof(bufferResult), filename);

    float result = (float)atof(bufferResult);

    return result;
}

std::string EQAPP_INI_ReadString(const char* filename, const char* section, const char* key, const char* defaultValue)
{
    char buffer[1024];
    int result = GetPrivateProfileStringA(section, key, defaultValue, buffer, sizeof(buffer), filename);

    return std::string(buffer, result);
}