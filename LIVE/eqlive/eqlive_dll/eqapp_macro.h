#pragma once

bool g_MacroIsEnabled = true;

void EQAPP_Macro_Toggle();
void EQAPP_Macro_On();
void EQAPP_Macro_Off();
void EQAPP_Macro_Execute(const char* fileName);

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

void EQAPP_Macro_Execute(const char* fileName)
{
    if (g_MacroIsEnabled == false)
    {
        return;
    }
    std::vector<std::string> macroList;

    macroList.reserve(1024);

    std::stringstream folderFileName;
    folderFileName << "macros/" << fileName << ".txt";

    bool result = EQAPP_ReadFileToList(folderFileName.str().c_str(), macroList, false);
    if (result == false)
    {
        std::cout << "Macro failed to execute with file: " << folderFileName.str() << std::endl;
        return;
    }

    if (macroList.size() == 0)
    {
        return;
    }

    for (auto& command : macroList)
    {
        EQ_InterpretCommand(command.c_str());
    }
}
