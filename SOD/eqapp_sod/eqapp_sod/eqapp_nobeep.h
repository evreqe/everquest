#ifndef EQAPP_NOBEEP_H
#define EQAPP_NOBEEP_H

std::vector<std::string> g_noBeepList;

void EQAPP_NoBeep_Load();
void EQAPP_NoBeep_Print();

void EQAPP_NoBeep_Load()
{
    std::cout << "Loading No Beep..." << std::endl;

    g_noBeepList.clear();

    std::string filePathStr = "eqapp/nobeep.txt";

    std::ifstream file;
    file.open(filePathStr.c_str(), std::ios::in);
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

        g_noBeepList.push_back(line);
    }

    file.close();
}

void EQAPP_NoBeep_Print()
{
    std::cout << "No Beep List:" << std::endl;

    for (auto& noBeep : g_noBeepList)
    {
        std::cout << noBeep << std::endl;
    }
}

#endif // EQAPP_NOBEEP_H
