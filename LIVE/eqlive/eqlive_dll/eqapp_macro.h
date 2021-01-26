#pragma once

namespace EQApp
{
    typedef struct _Macro
    {
        std::string Name;
        std::vector<std::string> CommandList;
        EQApp::Timer Timer = EQAPP_Timer_GetTimeNow();
        EQApp::TimerInterval TimerInterval = 1;
        bool bUseTimer = false;
        bool bEnabled = true;
    } Macro, *Macro_ptr;

    typedef std::vector<EQApp::Macro> MacroList;

    typedef struct _MacroFile
    {
        std::string Name;
        std::vector<std::string> CommandList;
    } MacroFile, *MacroFile_ptr;

    typedef std::vector<EQApp::MacroFile> MacroFileList;
}

bool g_MacroIsEnabled = true;

EQApp::MacroList g_MacroList;

EQApp::MacroFileList g_MacroFileList;

void EQAPP_Macro_Toggle();
void EQAPP_Macro_On();
void EQAPP_Macro_Off();
void EQAPP_Macro_Load();
void EQAPP_Macro_Unload();
std::vector<std::string> EQAPP_Macro_ReadCommandListFromFile(const char* fileName);
void EQAPP_Macro_Execute();
void EQAPP_Macro_InterpretCommandList(std::vector<std::string>& commandList);
void EQAPP_Macro_ReadAndExecuteFile(const char* fileName);
void EQAPP_Macro_ExecuteFile(const char* name);
void EQAPP_MacroList_Add(const char* name, EQApp::TimerInterval timerInterval, bool bUseTimer);
void EQAPP_MacroList_Remove(const char* name);
void EQAPP_MacroList_Toggle(const char* name);
void EQAPP_MacroList_Clear();

void EQAPP_Macro_Toggle()
{
    EQ_ToggleBool(g_MacroIsEnabled);
    EQAPP_PrintBool("Macro", g_MacroIsEnabled);
}

void EQAPP_Macro_On()
{
    if (g_MacroIsEnabled == false)
    {
        EQAPP_Macro_Toggle();
    }
}

void EQAPP_Macro_Off()
{
    if (g_MacroIsEnabled == true)
    {
        EQAPP_Macro_Toggle();
    }
}

void EQAPP_Macro_Load()
{
    g_MacroList.clear();

    g_MacroFileList.clear();

    std::stringstream folderPath;
    folderPath << g_EQAppName << "/macros/";

    for (auto& directoryEntry : std::filesystem::directory_iterator(folderPath.str()))
    {
        if (directoryEntry.path().extension().string() != ".txt")
        {
            continue;
        }

        std::string fileName = directoryEntry.path().filename().string();
        if (fileName.empty() == true)
        {
            continue;
        }

        std::string name = EQAPP_String_GetBefore(fileName, ".txt");
        if (name.empty() == true)
        {
            continue;
        }

        auto commandList = EQAPP_Macro_ReadCommandListFromFile(name.c_str());
        if (commandList.empty() == true)
        {
            continue;
        }

        //std::cout << "Macro loaded from file: " << fileName << "\n";

        EQApp::MacroFile macroFile;
        macroFile.Name = name;
        macroFile.CommandList = commandList;

        g_MacroFileList.push_back(macroFile);
    }
}

void EQAPP_Macro_Unload()
{
    //
}

std::vector<std::string> EQAPP_Macro_ReadCommandListFromFile(const char* fileName)
{
    std::stringstream folderFileName;
    folderFileName << "macros/" << fileName << ".txt";

    std::vector<std::string> commandList;
    commandList.reserve(1024);

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), commandList, false);
    if (result == false)
    {
        std::cout << "Macro failed to load from file: " << folderFileName.str() << "\n";
    }

    return commandList;
}

void EQAPP_Macro_Execute()
{
    for (auto& macro: g_MacroList)
    {
        if (macro.bEnabled == false)
        {
            continue;
        }

        if (macro.bUseTimer == false)
        {
            //std::cout << "Macro '" << macro.Name << "' executed.\n";

            EQAPP_Macro_InterpretCommandList(macro.CommandList);

            continue;
        }

        if (EQAPP_Timer_HasTimeElapsedInSeconds(macro.Timer, macro.TimerInterval) == true)
        {
            //std::cout << "Macro '" << macro.Name << "' executed using timer every " << macro.TimerInterval << " second(s).\n";

            EQAPP_Macro_InterpretCommandList(macro.CommandList);
        }
    }
}

void EQAPP_Macro_InterpretCommandList(std::vector<std::string>& commandList)
{
    for (auto& command : commandList)
    {
        EQ_InterpretCommand(command.c_str());
    }
}

void EQAPP_Macro_ReadAndExecuteFile(const char* fileName)
{
    // execute a macro by loading it directly from file

    auto commandList = EQAPP_Macro_ReadCommandListFromFile(fileName);
    if (commandList.empty() == true)
    {
        return;
    }

    EQAPP_Macro_InterpretCommandList(commandList);
}

void EQAPP_Macro_ExecuteFile(const char* name)
{
    // execute a macro that has been loaded in to memory

    for (auto& macroFile: g_MacroFileList)
    {
        if (macroFile.Name == name)
        {
            //std::cout << "Macro '" << macroFile.Name << "' executed.\n";

            EQAPP_Macro_InterpretCommandList(macroFile.CommandList);

            break;
        }
    }
}

void EQAPP_MacroList_Add(const char* name, EQApp::TimerInterval timerInterval, bool bUseTimer)
{
    // check if it already exists
    for (auto& macro : g_MacroList)
    {
        if (macro.Name == name)
        {
            for (auto& macroFile : g_MacroFileList)
            {
                if (macroFile.Name == name)
                {
                    // update it
                    macro.CommandList = macroFile.CommandList;
                    macro.TimerInterval = timerInterval;
                    macro.bUseTimer = bUseTimer;
                    macro.bEnabled = true;

                    std::cout << "Macro '" << name << "' updated.\n";

                    return;
                }
            }
        }
    }

    // add it
    for (auto& macroFile : g_MacroFileList)
    {
        if (macroFile.Name == name)
        {
            EQApp::Macro macro;
            macro.Name = macroFile.Name;
            macro.CommandList = macroFile.CommandList;
            macro.Timer = EQAPP_Timer_GetTimeNow();
            macro.TimerInterval = timerInterval;
            macro.bUseTimer = bUseTimer;
            macro.bEnabled = true;

            g_MacroList.push_back(macro);

            std::cout << "Macro '" << name << "' started.\n";

            return;
        }
    }
}

void EQAPP_MacroList_Toggle(const char* name)
{
    for (auto& macro : g_MacroList)
    {
        if (macro.Name == name)
        {
            macro.bEnabled = !macro.bEnabled;

            std::cout << "Macro '" << name << "' toggled.\n";

            return;
        }
    }

    EQAPP_MacroList_Add(name, 1, false);
}

void EQAPP_MacroList_Remove(const char* name)
{
    auto numErased = std::erase_if
    (
        g_MacroList,
    [name](const EQApp::Macro& macro) -> bool
        {
            return macro.Name == name;
        }
    );

    if (numErased > 0)
    {
        std::cout << "Macro '" << name << "' stopped.\n";
    }
}

void EQAPP_MacroList_Clear()
{
    g_MacroList.clear();

    std::cout << "All macros stopped.\n";
}
