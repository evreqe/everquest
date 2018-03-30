#pragma once

#define EQBCS_IP_ADDRESS "127.0.0.1"
#define EQBCS_PORT_NUMBER "29015"
#define EQBCS_STRING_MAX 4096

bool g_BoxChatIsEnabled = true;

bool g_BoxChatIsConnected = false;

bool g_BoxChatAutoConnect = true;

std::list<std::string> g_BoxChatInterpretCommandList;

EQApp::Timer g_BoxChatInterpretCommandTimer = EQAPP_Timer_GetTimeNow();

EQApp::Timer g_BoxChatKeepAliveTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BoxChatKeepAliveTimerInterval = 3;

EQApp::Timer g_BoxChatAutoConnectTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BoxChatAutoConnectTimerInterval = 3;

char g_BoxChatServerIPAddress[EQBCS_STRING_MAX];
char g_BoxChatServerPort[EQBCS_STRING_MAX];

char g_BoxChatRecvBuffer[EQBCS_STRING_MAX] = {0};

WSADATA g_BoxChatWSAData;
SOCKET g_BoxChatSocket;
fd_set g_BoxChatFDSetRead;

struct addrinfo* g_BoxChatAddressInfoResult = NULL;
struct addrinfo* g_BoxChatAddressInfo_ptr = NULL;
struct addrinfo g_BoxChatAddressInfoHints;

void EQAPP_BoxChat_Toggle();
void EQAPP_BoxChat_Load();
void EQAPP_BoxChat_Unload();
bool EQAPP_BoxChat_Connect(std::string connectName);
void EQAPP_BoxChat_Disconnect();
void EQAPP_BoxChat_DisconnectEx();
bool EQAPP_BoxChat_SendText(std::string text);
void EQAPP_BoxChat_Execute();
void EQAPP_BoxChat_InterpretCommands();
bool EQAPP_BoxChat_IsServerRunning();

void EQAPP_BoxChat_Toggle()
{
    EQ_ToggleBool(g_BoxChatIsEnabled);
    EQAPP_PrintBool("Box Chat", g_BoxChatIsEnabled);
}

void EQAPP_BoxChat_Load()
{
    g_BoxChatInterpretCommandList.clear();
}

void EQAPP_BoxChat_Unload()
{
    if (shutdown(g_BoxChatSocket, SD_BOTH) == SOCKET_ERROR)
    {
        closesocket(g_BoxChatSocket);
    }

    closesocket(g_BoxChatSocket);
}

bool EQAPP_BoxChat_Connect(std::string connectName)
{
    g_BoxChatInterpretCommandList.clear();

    // functions WSAStartup() and WSACleanup() are not needed
    // because the game already calls them for us
    // if we call the functions ourselves, the game will crash

    EQAPP_BoxChat_DisconnectEx();

    ZeroMemory(&g_BoxChatAddressInfoHints, sizeof(g_BoxChatAddressInfoHints));
    g_BoxChatAddressInfoHints.ai_family   = AF_INET;
    g_BoxChatAddressInfoHints.ai_socktype = SOCK_STREAM;
    g_BoxChatAddressInfoHints.ai_protocol = IPPROTO_TCP;

    if (strlen(g_BoxChatServerIPAddress) == 0)
    {
        strncpy_s(g_BoxChatServerIPAddress, sizeof(g_BoxChatServerIPAddress), EQBCS_IP_ADDRESS, _TRUNCATE);
    }

    if (strlen(g_BoxChatServerPort) == 0)
    {
        strncpy_s(g_BoxChatServerPort, sizeof(g_BoxChatServerPort), EQBCS_PORT_NUMBER, _TRUNCATE);
    }

    if (getaddrinfo(g_BoxChatServerIPAddress, g_BoxChatServerPort, &g_BoxChatAddressInfoHints, &g_BoxChatAddressInfoResult) != 0)
    {
        freeaddrinfo(g_BoxChatAddressInfoResult);
        EQAPP_BoxChat_DisconnectEx();
        return false;
    }

    g_BoxChatAddressInfo_ptr = g_BoxChatAddressInfoResult;

    g_BoxChatSocket = socket(g_BoxChatAddressInfo_ptr->ai_family, g_BoxChatAddressInfo_ptr->ai_socktype, g_BoxChatAddressInfo_ptr->ai_protocol);

    if (g_BoxChatSocket == INVALID_SOCKET)
    {
        freeaddrinfo(g_BoxChatAddressInfoResult);
        EQAPP_BoxChat_DisconnectEx();
        return false;
    }

    if (connect(g_BoxChatSocket, g_BoxChatAddressInfo_ptr->ai_addr, (int)g_BoxChatAddressInfo_ptr->ai_addrlen) != SOCKET_ERROR)
    {
        if (g_BoxChatSocket != INVALID_SOCKET)
        {
            std::stringstream ssConnectMessage;
            ssConnectMessage << "$ConnectName " << connectName << "\n";

            std::string strConnectMessage = ssConnectMessage.str();

            if (send(g_BoxChatSocket, strConnectMessage.c_str(), strConnectMessage.size(), 0) == SOCKET_ERROR)
            {
                freeaddrinfo(g_BoxChatAddressInfoResult);
                EQAPP_BoxChat_DisconnectEx();
                return false;
            }

            std::cout << "Box Chat connected." << std::endl;

            freeaddrinfo(g_BoxChatAddressInfoResult);
            g_BoxChatIsConnected = true;
            return true;
        }
    }

    freeaddrinfo(g_BoxChatAddressInfoResult);
    EQAPP_BoxChat_DisconnectEx();
    return false;
}

void EQAPP_BoxChat_Disconnect()
{
    closesocket(g_BoxChatSocket);

    g_BoxChatIsConnected = false;

    std::cout << "Box Chat disconnected." << std::endl;
}

void EQAPP_BoxChat_DisconnectEx()
{
    closesocket(g_BoxChatSocket);

    g_BoxChatIsConnected = false;
}

bool EQAPP_BoxChat_SendText(std::string text)
{
    if (send(g_BoxChatSocket, text.c_str(), text.size(), 0) == SOCKET_ERROR)
    {
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    return true;
}

void EQAPP_BoxChat_Execute()
{
    if (g_BoxChatIsConnected == false)
    {
        return;
    }

    if (g_BoxChatSocket == INVALID_SOCKET)
    {
        EQAPP_BoxChat_DisconnectEx();
        return;
    }

    if (EQAPP_Timer_HasTimeElapsed(g_BoxChatKeepAliveTimer, g_BoxChatKeepAliveTimerInterval) == true)
    {
        EQAPP_BoxChat_SendText("$KeepAlive");
    }

    FD_ZERO(&g_BoxChatFDSetRead);
    FD_SET(g_BoxChatSocket, &g_BoxChatFDSetRead);

    timeval tv;
    tv.tv_sec  = 0;
    tv.tv_usec = 0;

    int selectResult = select(0, &g_BoxChatFDSetRead, NULL, NULL, &tv);
    if (selectResult == SOCKET_ERROR)
    {
        return;
    }

    if (FD_ISSET(g_BoxChatSocket, &g_BoxChatFDSetRead))
    {
        memset(g_BoxChatRecvBuffer, 0, EQBCS_STRING_MAX);

        int recvResult = recv(g_BoxChatSocket, g_BoxChatRecvBuffer, EQBCS_STRING_MAX, 0);
        if (recvResult <= 0)
        {
            return;
        }

        std::string recvText = g_BoxChatRecvBuffer;
        if (recvText.size() == 0)
        {
            ////std::cout << "recvText size() == 0" << std::endl;
            return;
        }

        ////std::cout << "recvText: " << recvText << std::endl;

        std::vector<std::string> recvTokens = EQAPP_String_Split(recvText, '\n');

        if (recvTokens.size() == 0)
        {
            ////std::cout << "recvTokens size() == 0" << std::endl;
            return;
        }

        for (auto& recvToken : recvTokens)
        {
            std::vector<std::string> textTokens = EQAPP_String_Split(recvToken, ' ');

            if (textTokens.size() == 0)
            {
                ////std::cout << "textTokens size() == 0" << std::endl;
                continue;
            }

            if (textTokens.size() > 1)
            {
                if (textTokens.at(0) == "$InterpretCommand")
                {
                    std::vector<std::string>::const_iterator textTokenFirst = textTokens.begin() + 1;
                    std::vector<std::string>::const_iterator textTokenLast = textTokens.end();
                    std::vector<std::string> textTokensEx(textTokenFirst, textTokenLast);

                    if (textTokensEx.size() == 0)
                    {
                        ////std::cout << "textTokensEx size() == 0" << std::endl;
                        continue;
                    }

                    std::string commandText = EQAPP_String_JoinStrings(textTokensEx, " ");
                    if (commandText.size() == 0)
                    {
                        ////std::cout << "commandText size() == 0" << std::endl;
                        break;
                    }

                    ////std::cout << "commandText: " << commandText << std::endl;

                    g_BoxChatInterpretCommandList.push_back(commandText);
                }
            }
        }
    }

    EQAPP_BoxChat_InterpretCommands();
}

void EQAPP_BoxChat_InterpretCommands()
{
    if (g_BoxChatInterpretCommandList.size() == 0)
    {
        return;
    }

    std::string commandText = g_BoxChatInterpretCommandList.front();
    if (commandText.size() == 0)
    {
        return;
    }

    bool bUseTimer = false;

    bool bHasTimeElapsed = false;

    auto timeNow = EQAPP_Timer_GetTimeNow();

    EQApp::TimerInterval timeInterval = 1;

    if (EQAPP_String_StartsWith(commandText, "//Pause ") == true)
    {
        std::string timeStr = EQAPP_String_GetAfter(commandText, " ");
        if (timeStr.size() != 0)
        {
            timeInterval = std::stoll(timeStr);

            bUseTimer = true;
        }
    }

    auto timeElapsed = EQAPP_Timer_GetTimeElapsed(g_BoxChatInterpretCommandTimer);
    if (timeElapsed >= timeInterval)
    {
        bHasTimeElapsed = true;

        g_BoxChatInterpretCommandTimer = EQAPP_Timer_GetTimeNow();
    }

    if (bUseTimer == true && bHasTimeElapsed == false)
    {
        return;
    }

    g_BoxChatInterpretCommandList.pop_front();

    std::cout << "Box Chat Interpret Command: " << commandText << std::endl;

    EQ_InterpretCommand(commandText.c_str());
}

bool EQAPP_BoxChat_IsServerRunning()
{
    bool result = false;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        return result;
    }

    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof(pe32);

    if (Process32First(snapshot, &pe32))
    {
        for (;;)
        {
            if(lstrcmpi(pe32.szExeFile, L"eqbcs.exe") == 0)
            {
                result = true;
                break;
            }

            if (!Process32Next(snapshot, &pe32))
            {
                if (GetLastError() != ERROR_NO_MORE_FILES)
                {
                    result = false;
                }

                break;
            }
            else
            {
                if (GetLastError() != ERROR_NO_MORE_FILES)
                {
                    result = false;
                }
            }
        }

        CloseHandle(snapshot);
    }

    return result;
}
