#pragma once

#include "eqapp.h"

template <class T>
void EQAPP_Log(const char* text, T number);

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);
bool EQAPP_String_StartsWith(std::string& subject, const std::string& search);
std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end);

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName);
bool EQAPP_IsForegroundWindowCurrentProcessId();

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_PrintErrorMessage(const char* functionName, const std::string& text);
void EQAPP_PrintDebugMessage(const char* functionName, const std::string& text);

bool EQAPP_IsKeyDown(int vkKey);

void EQAPP_Mouse_Load();
void EQAPP_Mouse_Unload();
void EQAPP_Mouse_Unacquire();
void EQAPP_Mouse_Acquire();

void EQAPP_Keyboard_Load();
void EQAPP_Keyboard_Unload();
void EQAPP_Keyboard_Unacquire();
void EQAPP_Keyboard_Acquire();

void EQAPP_PlaySound(const char* filename);
void EQAPP_Beep();
void EQAPP_BeepEx(UINT beepType);
bool EQAPP_FileExists(const char *fileName);
void EQAPP_DeleteFileContents(const char* filename);
std::string EQAPP_ReadFileContents(const char* filename);
void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list);

uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high);

float EQAPP_GetTargetMeleeDistance();
void EQAPP_PrintTargetMeleeDistance();

void EQAPP_TargetNearestPlayer();
void EQAPP_TargetNearestPlayerPet();
void EQAPP_TargetNearestNPC();
void EQAPP_TargetNearestNPCPet();
void EQAPP_TargetNearestAnyCorpse();
void EQAPP_TargetNearestPlayerCorpse();
void EQAPP_TargetNearestNPCCorpse();

void EQAPP_PrintBankInventory();
void EQAPP_WriteInventoryToFile();

void EQAPP_Levitate_On();
void EQAPP_Levitate_Off();
void EQAPP_Fly_On();
void EQAPP_Fly_Off();

template <class T>
void EQAPP_Log(const char* text, T number)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/log.txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
    std::size_t position = 0;
    while ((position = subject.find(search, position)) != std::string::npos)
    {
         subject.replace(position, search.length(), replace);
         position += replace.length();
    }
}

bool EQAPP_String_StartsWith(std::string& subject, const std::string& search)
{
    return (subject.compare(0, search.size(), search) == 0);
}

std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end)
{
    std::size_t beginPosition;
    if ((beginPosition = subject.find(begin)) != std::string::npos)
    {
        beginPosition = beginPosition + begin.length();

        std::size_t endPosition;
        if ((endPosition = subject.find(end, beginPosition)) != std::string::npos && endPosition != beginPosition)
        {
            return subject.substr(beginPosition, endPosition - beginPosition);
        }
    }

    return std::string();
}

void EQAPP_EnableDebugPrivileges()
{
    HANDLE token;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
    {
        TOKEN_PRIVILEGES tp;
        TOKEN_PRIVILEGES tpPrevious;

        DWORD cbPrevious = sizeof(TOKEN_PRIVILEGES);

        LUID luid;

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
        {
            tp.PrivilegeCount           = 1;
            tp.Privileges[0].Luid       = luid;
            tp.Privileges[0].Attributes = 0;

            AdjustTokenPrivileges(token, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), &tpPrevious, &cbPrevious);

            tpPrevious.PrivilegeCount            = 1;
            tpPrevious.Privileges[0].Luid        = luid;
            tpPrevious.Privileges[0].Attributes |= (SE_PRIVILEGE_ENABLED);

            AdjustTokenPrivileges(token, FALSE, &tpPrevious, cbPrevious, NULL, NULL);
        }
    }

    CloseHandle(token);
}

DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName)
{
    DWORD moduleBaseAddress = 0;
    DWORD processId = GetCurrentProcessId();
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 ModuleEntry32 = {0};
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(snapshot, &ModuleEntry32))
        {
            do
            {
                if (wcscmp(ModuleEntry32.szModule, moduleName) == 0)
                {
                    moduleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                    break;
                }
            } while (Module32Next(snapshot, &ModuleEntry32));
        }

        CloseHandle(snapshot);
    }

    return moduleBaseAddress;
}

bool EQAPP_IsForegroundWindowCurrentProcessId()
{
    HWND foregroundHwnd = GetForegroundWindow();

    DWORD foregroundProcessId;
    GetWindowThreadProcessId(foregroundHwnd, &foregroundProcessId);

    return (foregroundProcessId == GetCurrentProcessId());
}

void EQAPP_PrintBool(const char* text, bool& b)
{
    std::cout << text << ": " << (b ? "On" : "Off") << std::endl;
}

void EQAPP_PrintErrorMessage(const char* functionName, const std::string& text)
{
    if (g_EQAppErrorMessageIsEnabled == false)
    {
        return;
    }

    std::cout << "[ERROR] " << functionName << ": " << text << std::endl;
}

void EQAPP_PrintDebugMessage(const char* functionName, const std::string& text)
{
    if (g_EQAppDebugMessageIsEnabled == false)
    {
        return;
    }

    std::cout << "[DEBUG] " << functionName << ": " << text << std::endl;
}

bool EQAPP_IsKeyDown(int vkKey)
{
    if (GetAsyncKeyState(vkKey) & 0x8000)
    {
        return true;
    }

    return false;
}

void EQAPP_Mouse_Load()
{
    // allow 7 mouse buttons
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x00, 0x18);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x04, 0x10);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x08, 0x02);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x0C, 0x14); // 0x14
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x10, 0x0B); // 0x0B

    EQ_CLASS_POINTER_DInputMouse->Unacquire();

    EQ_CLASS_POINTER_DInputMouse->SetDataFormat(&c_dfDIMouse2);
    ////EQ_CLASS_POINTER_DInputMouse->SetCooperativeLevel(EQ_GetWindow(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    EQ_CLASS_POINTER_DInputMouse->Acquire();
}

void EQAPP_Mouse_Unload()
{
    // only allow 3 mouse buttons
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x00, 0x18);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x04, 0x10);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x08, 0x02);
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x0C, 0x10); // 0x10
    EQ_WriteMemoryProtected<uint32_t>(EQ_ADDRESS_DINPUT_DEVICE_MOUSE_DIOBJECTDATAFORMAT + 0x10, 0x07); // 0x07

    EQ_CLASS_POINTER_DInputMouse->Unacquire();

    EQ_CLASS_POINTER_DInputMouse->SetDataFormat(&c_dfDIMouse);
    ////EQ_CLASS_POINTER_DInputMouse->SetCooperativeLevel(EQ_GetWindow(), DISCL_FOREGROUND | DISCL_EXCLUSIVE);

    EQ_CLASS_POINTER_DInputMouse->Acquire();
}

void EQAPP_Mouse_Unacquire()
{
    EQ_CLASS_POINTER_DInputMouse->Unacquire();
}

void EQAPP_Mouse_Acquire()
{
    if (EQ_CLASS_POINTER_IDirectInput8 == NULL || EQ_CLASS_POINTER_DInputMouse == NULL)
    {
        return;
    }

    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        return;
    }

    DIMOUSESTATE2 mouseState;
    HRESULT result = EQ_CLASS_POINTER_DInputMouse->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)&mouseState);
    if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
    {
        EQ_CLASS_POINTER_DInputMouse->SetDataFormat(&c_dfDIMouse2);

        if (EQ_CLASS_POINTER_DInputMouse->Acquire() == DI_OK)
        {
            SetCapture(GetForegroundWindow());
            ////std::cout << "Mouse Acquired." << std::endl;
        }
    }
}

void EQAPP_Keyboard_Load()
{
    EQ_CLASS_POINTER_DInputKeyboard->Unacquire();

    EQ_CLASS_POINTER_DInputKeyboard->SetDataFormat(&c_dfDIKeyboard);
    ////EQ_CLASS_POINTER_DInputKeyboard->SetCooperativeLevel(EQ_GetWindow(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

    EQ_CLASS_POINTER_DInputKeyboard->Acquire();
}

void EQAPP_Keyboard_Unload()
{
    EQ_CLASS_POINTER_DInputKeyboard->Unacquire();

    EQ_CLASS_POINTER_DInputKeyboard->SetDataFormat(&c_dfDIKeyboard);
    ////EQ_CLASS_POINTER_DInputKeyboard->SetCooperativeLevel(EQ_GetWindow(), DISCL_FOREGROUND | DISCL_EXCLUSIVE);

    EQ_CLASS_POINTER_DInputKeyboard->Acquire();
}

void EQAPP_Keyboard_Unacquire()
{
    EQ_CLASS_POINTER_DInputKeyboard->Unacquire();
}

void EQAPP_Keyboard_Acquire()
{
    if (EQ_CLASS_POINTER_IDirectInput8 == NULL || EQ_CLASS_POINTER_DInputKeyboard == NULL)
    {
        return;
    }

    if (EQAPP_IsForegroundWindowCurrentProcessId() == false)
    {
        return;
    }

    char keyboardState[256];
    HRESULT result = EQ_CLASS_POINTER_DInputKeyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);
    if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
    {
        EQ_CLASS_POINTER_DInputKeyboard->SetDataFormat(&c_dfDIKeyboard);

        if (EQ_CLASS_POINTER_DInputKeyboard->Acquire() == DI_OK)
        {
            SetCapture(GetForegroundWindow());
            ////std::cout << "Keyboard Acquired." << std::endl;
        }
    }
}

void EQAPP_PlaySound(const char* filename)
{
    PlaySoundA(filename, 0, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQAPP_Beep()
{
    MessageBeep(0);
}

void EQAPP_BeepEx(UINT beepType)
{
    MessageBeep(beepType);
}

bool EQAPP_FileExists(const char *fileName)
{
    std::ifstream file(fileName);
    return file.good();
}

void EQAPP_DeleteFileContents(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::out | std::fstream::trunc);
    file.close();
}

std::string EQAPP_ReadFileContents(const char* filename)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << filename;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return std::string();
    }

    std::string fileContents((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    file.close();

    return fileContents;
}

void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list)
{
    std::stringstream filePath;
    filePath << g_EQAppName << "/" << filename;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        std::cout << filename << ": " << line << std::endl;

        list.push_back(line);
    }

    file.close();
}

uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high)
{
    std::uniform_int_distribution<uint32_t> uid;
    std::uniform_int_distribution<uint32_t>::param_type uidpt(low, high);

    return uid(g_EQAppRandomEngine, uidpt);
}

float EQAPP_GetTargetMeleeDistance()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return -1.0f;
    }

    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return -1.0f;
    }

    return EQ_FUNCTION_get_melee_range((EQClass::EQPlayer*)playerSpawn, (EQClass::EQPlayer*)targetSpawn);
}

void EQAPP_PrintTargetMeleeDistance()
{
    std::cout << "Target Melee Distance: " << EQAPP_GetTargetMeleeDistance() << std::endl;
}

void EQAPP_TargetNearestPlayer()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_PLAYER, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestNPC()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_NPC, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestPlayerPet()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_PLAYER_PET, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestNPCPet()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_NPC_PET, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestAnyCorpse()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_ANY_CORPSE, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestPlayerCorpse()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_PLAYER_CORPSE, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_TargetNearestNPCCorpse()
{
    auto spawn = EQ_GetNearestSpawn(EQ_SPAWN_TYPE_NPC_CORPSE, 400.0f, 20.0f, NULL);
    if (spawn != NULL)
    {
        EQ_SetTargetSpawn(spawn);
    }
}

void EQAPP_PrintBankInventory()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::cout << "Bank:" << std::endl;

    bool bIsBankEmpty = true;

    std::cout << (int)playerSpawn->Character->BankPlatinum << "p "
              << (int)playerSpawn->Character->BankGold     << "g "
              << (int)playerSpawn->Character->BankSilver   << "s "
              << (int)playerSpawn->Character->BankCopper   << "c"
              << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_BANK_SLOTS; i++)
    {
        EQ::Item_ptr item = (EQ::Item_ptr)playerSpawn->Character->InventoryBankItem[i];
        if (item == NULL)
        {
            continue;
        }
        else
        {
            bIsBankEmpty = false;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        if (item->IsContainer == 0)
        {
            std::cout << "- ";
        }

        std::cout << itemName;

        if (item->IsContainer == 0)
        {
            if (item->Common.IsStackable == 1 && item->Common.StackCount > 1)
            {
                std::cout << " x " << (int)item->Common.StackCount;
            }
        }

        std::cout << std::endl;

        if (item->IsContainer == 1)
        {
            for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
            {
                EQ::Item_ptr containerItem = (EQ::Item_ptr)playerSpawn->Character->InventoryBankItem[i]->Container.Item[j];
                if (containerItem == NULL)
                {
                    continue;
                }

                std::string containerItemName = containerItem->Name;
                if (containerItemName.size() == 0)
                {
                    continue;
                }

                std::cout << "- " << containerItemName;

                if (containerItem->IsContainer == 0)
                {
                    if (containerItem->Common.IsStackable == 1 && containerItem->Common.StackCount > 1)
                    {
                        std::cout << " x " << (int)containerItem->Common.StackCount;
                    }
                }

                std::cout << std::endl;
            }
        }
    }

    if (bIsBankEmpty == true)
    {
        std::cout << "Your bank is empty." << std::endl;
    }
}

void EQAPP_WriteInventoryToFile()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    std::string spawnName = EQ_GetSpawnName(playerSpawn);
    if (spawnName.size() == 0)
    {
        return;
    }

    std::stringstream filePath;
    filePath << g_EQAppName << "/inventory/" << spawnName << ".txt";

    std::string filePathStr = filePath.str();

    std::cout << "Saving inventory to file: " << filePathStr << std::endl;

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    file << "---------- BANK ----------" << std::endl;

    bool bIsBankEmpty = true;

    file << "Platinum: " << (uint32_t)playerSpawn->Character->BankPlatinum << std::endl;
    file << "Gold: " << (uint32_t)playerSpawn->Character->BankGold << std::endl;
    file << "Silver: " << (uint32_t)playerSpawn->Character->BankSilver << std::endl;
    file << "Copper: " << (uint32_t)playerSpawn->Character->BankCopper << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_BANK_SLOTS; i++)
    {
        EQ::Item_ptr item = (EQ::Item_ptr)playerSpawn->Character->InventoryBankItem[i];
        if (item == NULL)
        {
            continue;
        }
        else
        {
            bIsBankEmpty = false;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        file << i + 1 << ": " << itemName;

        if (item->IsContainer == 0)
        {
            if (item->Common.IsStackable == 1 && item->Common.StackCount > 1)
            {
                file << " x " << (int)item->Common.StackCount;
            }
        }

        file << std::endl;

        if (item->IsContainer == 1)
        {
            for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
            {
                EQ::Item_ptr containerItem = (EQ::Item_ptr)playerSpawn->Character->InventoryBankItem[i]->Container.Item[j];
                if (containerItem == NULL)
                {
                    continue;
                }

                std::string containerItemName = containerItem->Name;
                if (containerItemName.size() == 0)
                {
                    continue;
                }

                file << "- " << containerItemName;

                if (containerItem->IsContainer == 0)
                {
                    if (containerItem->Common.IsStackable == 1 && containerItem->Common.StackCount > 1)
                    {
                        file << " x " << (int)containerItem->Common.StackCount;
                    }
                }

                file << std::endl;
            }
        }
    }

    if (bIsBankEmpty == true)
    {
        file << "Your bank is empty." << std::endl;
    }

    file << std::endl;

    file << "---------- INVENTORY ----------" << std::endl;

    file << "Platinum: " << (uint32_t)playerSpawn->Character->InventoryPlatinum << std::endl;
    file << "Gold: " << (uint32_t)playerSpawn->Character->InventoryGold << std::endl;
    file << "Silver: " << (uint32_t)playerSpawn->Character->InventorySilver << std::endl;
    file << "Copper: " << (uint32_t)playerSpawn->Character->InventoryCopper << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_PACK_SLOTS; i++)
    {
        EQ::Item_ptr item = (EQ::Item_ptr)playerSpawn->Character->InventoryPackItem[i];
        if (item == NULL)
        {
            continue;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        file << i + 1 << ": " << itemName;

        if (item->IsContainer == 0)
        {
            if (item->Common.IsStackable == 1 && item->Common.StackCount > 1)
            {
                file << " x " << (int)item->Common.StackCount;
            }
        }

        file << std::endl;

        if (item->IsContainer == 1)
        {
            for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
            {
                EQ::Item_ptr containerItem = (EQ::Item_ptr)playerSpawn->Character->InventoryPackItem[i]->Container.Item[j];
                if (containerItem == NULL)
                {
                    continue;
                }

                std::string containerItemName = containerItem->Name;
                if (containerItemName.size() == 0)
                {
                    continue;
                }

                file << "- " << containerItemName;

                if (containerItem->IsContainer == 0)
                {
                    if (containerItem->Common.IsStackable == 1 && containerItem->Common.StackCount > 1)
                    {
                        file << " x " << (int)containerItem->Common.StackCount;
                    }
                }

                file << std::endl;
            }
        }
    }

    file << std::endl;

    file << "---------- EQUIPMENT ----------" << std::endl;

    for (size_t i = 0; i < EQ_NUM_INVENTORY_EQUIPMENT_SLOTS; i++)
    {
        EQ::Item_ptr item = (EQ::Item_ptr)playerSpawn->Character->InventoryEquipmentItem[i];
        if (item == NULL)
        {
            continue;
        }

        std::string itemName = item->Name;
        if (itemName.size() == 0)
        {
            continue;
        }

        file << EQ_STRING_MAP_INVENTORY_EQUIPMENT_NAME[i] << ": " << itemName;

        if (item->IsContainer == 0)
        {
            if (item->Common.IsStackable == 1 && item->Common.StackCount > 1)
            {
                file << " x " << (int)item->Common.StackCount;
            }
        }

        file << std::endl;

        if (item->IsContainer == 1)
        {
            for (size_t j = 0; j < EQ_NUM_CONTAINER_SLOTS; j++)
            {
                EQ::Item_ptr containerItem = (EQ::Item_ptr)playerSpawn->Character->InventoryEquipmentItem[i]->Container.Item[j];
                if (containerItem == NULL)
                {
                    continue;
                }

                std::string containerItemName = containerItem->Name;
                if (containerItemName.size() == 0)
                {
                    continue;
                }

                file << "- " << containerItemName;

                if (containerItem->IsContainer == 0)
                {
                    if (containerItem->Common.IsStackable == 1 && containerItem->Common.StackCount > 1)
                    {
                        file << " x " << (int)containerItem->Common.StackCount;
                    }
                }

                file << std::endl;
            }
        }
    }

    file.close();
}

void EQAPP_Levitate_On()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        ((EQClass::EQPlayer*)playerSpawn)->SetNoGrav(EQ_GRAVITY_TYPE_LEVITATING);
    }
}

void EQAPP_Levitate_Off()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        ((EQClass::EQPlayer*)playerSpawn)->SetNoGrav(EQ_GRAVITY_TYPE_DEFAULT);
    }
}

void EQAPP_Fly_On()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        ((EQClass::EQPlayer*)playerSpawn)->SetNoGrav(EQ_GRAVITY_TYPE_NONE);
    }
}

void EQAPP_Fly_Off()
{
    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn != NULL)
    {
        ((EQClass::EQPlayer*)playerSpawn)->SetNoGrav(EQ_GRAVITY_TYPE_DEFAULT);
    }
}
