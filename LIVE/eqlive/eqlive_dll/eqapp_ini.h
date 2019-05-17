#pragma once

#include <string>

int EQAPP_INI_ReadInt(const char* fileName, const char* section, const char* key, int defaultValue);
bool EQAPP_INI_ReadBool(const char* fileName, const char* section, const char* key, int defaultValue);
float EQAPP_INI_ReadFloat(const char* fileName, const char* section, const char* key, float defaultValue);
std::string EQAPP_INI_ReadString(const char* fileName, const char* section, const char* key, const char* defaultValue);

int EQAPP_INI_ReadInt(const char* fileName, const char* section, const char* key, int defaultValue)
{
    return GetPrivateProfileIntA(section, key, defaultValue, fileName);
}

bool EQAPP_INI_ReadBool(const char* fileName, const char* section, const char* key, int defaultValue)
{
    auto result = GetPrivateProfileIntA(section, key, defaultValue, fileName);

    return (result != 0);
}

float EQAPP_INI_ReadFloat(const char* fileName, const char* section, const char* key, float defaultValue)
{
    char bufferDefault[1024];
    _snprintf_s(bufferDefault, sizeof(bufferDefault), _TRUNCATE, "%f", defaultValue);

    char bufferResult[1024];
    GetPrivateProfileStringA(section, key, bufferDefault, bufferResult, sizeof(bufferResult), fileName);

    auto result = std::stof(bufferResult);

    return result;
}

std::string EQAPP_INI_ReadString(const char* fileName, const char* section, const char* key, const char* defaultValue)
{
    char buffer[4096];
    auto result = GetPrivateProfileStringA(section, key, defaultValue, buffer, sizeof(buffer), fileName);

    return std::string(buffer, result);
}

