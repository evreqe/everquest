#pragma once

bool g_BoxChatIsEnabled = true;

bool g_BoxChatAutoConnectIsEnabled = true;

bool g_BoxChatIsConnected = false;

const char* g_BoxChatProcessFileName = "eqlivebcs.exe";

const wchar_t g_BoxChatProcessFileNameWide[] = L"eqlivebcs.exe";

std::string g_BoxChatClientName = "UNKNOWN";
std::string g_BoxChatGlobalChannelName = "Global1";
std::string g_BoxChatChannelName = "Default";

std::list<std::string> g_BoxChatInterpretCommandList;

EQApp::Timer g_BoxChatInterpretCommandTimer = EQAPP_Timer_GetTimeNow();

EQApp::Timer g_BoxChatKeepAliveTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BoxChatKeepAliveTimerInterval = 3;

EQApp::Timer g_BoxChatAutoConnectTimer = EQAPP_Timer_GetTimeNow();
EQApp::TimerInterval g_BoxChatAutoConnectTimerInterval = 3;

std::string g_BoxChatServerIPAddress = "127.0.0.1";
std::string g_BoxChatServerPort = "29015";

char g_BoxChatRecvBuffer[4096] = {0};

WSADATA g_BoxChatWSAData;
SOCKET g_BoxChatSocket;
fd_set g_BoxChatFDSetRead;

struct addrinfo* g_BoxChatAddressInfoResult = NULL;
struct addrinfo* g_BoxChatAddressInfo_ptr = NULL;
struct addrinfo g_BoxChatAddressInfoHints;

void EQAPP_BoxChat_Toggle();
void EQAPP_BoxChat_On();
void EQAPP_BoxChat_Off();
void EQAPP_BoxChat_AutoConnect_Toggle();
void EQAPP_BoxChat_AutoConnect_On();
void EQAPP_BoxChat_AutoConnect_Off();
void EQAPP_BoxChat_Load();
void EQAPP_BoxChat_Unload();
bool EQAPP_BoxChat_Connect(std::string clientName);
void EQAPP_BoxChat_Disconnect();
void EQAPP_BoxChat_DisconnectEx();
bool EQAPP_BoxChat_SendText(std::string text);
bool EQAPP_BoxChat_SetGlobalChannel(std::string channelName);
bool EQAPP_BoxChat_SetChannel(std::string channelName);
void EQAPP_BoxChat_Execute();
void EQAPP_BoxChat_InterpretCommands();
bool EQAPP_BoxChat_IsServerRunning();

void EQAPP_BoxChat_Toggle()
{
    EQ_ToggleBool(g_BoxChatIsEnabled);
    EQAPP_PrintBool("Box Chat", g_BoxChatIsEnabled);
}

void EQAPP_BoxChat_On()
{
    if (g_BoxChatIsEnabled == false)
    {
        EQAPP_BoxChat_Toggle();
    }
}

void EQAPP_BoxChat_Off()
{
    if (g_BoxChatIsEnabled == true)
    {
        EQAPP_BoxChat_Toggle();
    }
}

void EQAPP_BoxChat_AutoConnect_Toggle()
{
    EQ_ToggleBool(g_BoxChatAutoConnectIsEnabled);
    EQAPP_PrintBool("Box Chat Auto Connect", g_BoxChatAutoConnectIsEnabled);
}

void EQAPP_BoxChat_AutoConnect_On()
{
    if (g_BoxChatAutoConnectIsEnabled == false)
    {
        EQAPP_BoxChat_AutoConnect_Toggle();
    }
}

void EQAPP_BoxChat_AutoConnect_Off()
{
    if (g_BoxChatAutoConnectIsEnabled == true)
    {
        EQAPP_BoxChat_AutoConnect_Toggle();
    }
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

bool EQAPP_BoxChat_Connect(std::string clientName)
{
    EQAPP_BoxChat_Load();

    // functions WSAStartup() and WSACleanup() are not needed
    // because the game already calls them for us
    // if we call the functions ourselves, the game will crash

    EQAPP_BoxChat_DisconnectEx();

    ZeroMemory(&g_BoxChatAddressInfoHints, sizeof(g_BoxChatAddressInfoHints));
    g_BoxChatAddressInfoHints.ai_family   = AF_INET;
    g_BoxChatAddressInfoHints.ai_socktype = SOCK_STREAM;
    g_BoxChatAddressInfoHints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(g_BoxChatServerIPAddress.c_str(), g_BoxChatServerPort.c_str(), &g_BoxChatAddressInfoHints, &g_BoxChatAddressInfoResult) != 0)
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
            std::stringstream ssClientNameMessage;
            ssClientNameMessage << "$ClientName " << clientName << "\n";

            std::string strClientNameMessage = ssClientNameMessage.str();

            if (send(g_BoxChatSocket, strClientNameMessage.c_str(), strClientNameMessage.size(), 0) == SOCKET_ERROR)
            {
                freeaddrinfo(g_BoxChatAddressInfoResult);
                EQAPP_BoxChat_DisconnectEx();
                return false;
            }

            std::cout << "Box Chat connected." << "\n";

            g_BoxChatClientName = clientName;

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
    EQAPP_BoxChat_DisconnectEx();

    std::cout << "Box Chat disconnected." << "\n";
}

void EQAPP_BoxChat_DisconnectEx()
{
    closesocket(g_BoxChatSocket);

    g_BoxChatIsConnected = false;

    g_BoxChatClientName = "UNKNOWN";
    g_BoxChatGlobalChannelName = "Global1";
    g_BoxChatChannelName = "Default";
}

bool EQAPP_BoxChat_SendText(std::string text)
{
    if (text[text.size()] != '\n')
    {
        text.append("\n");
    }

    if (send(g_BoxChatSocket, text.c_str(), text.size(), 0) == SOCKET_ERROR)
    {
        std::cout << "Box Chat failed to send text: " << text << "\n";

        EQAPP_BoxChat_Disconnect();
        return false;
    }

    return true;
}

bool EQAPP_BoxChat_SetGlobalChannel(std::string channelName)
{
    if (channelName.size() == 0)
    {
        g_BoxChatGlobalChannelName = "Global1";
    }

    std::stringstream ss;
    ss << "$ClientGlobalChannel " << channelName;

    if (EQAPP_BoxChat_SendText(ss.str()) == true)
    {
        g_BoxChatGlobalChannelName = channelName;
        return true;
    }

    return false;
}

bool EQAPP_BoxChat_SetChannel(std::string channelName)
{
    if (channelName.size() == 0)
    {
        g_BoxChatChannelName = "Default";
    }

    std::stringstream ss;
    ss << "$ClientChannel " << channelName;

    if (EQAPP_BoxChat_SendText(ss.str()) == true)
    {
        g_BoxChatChannelName = channelName;
        return true;
    }

    return false;
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
        memset(g_BoxChatRecvBuffer, 0, sizeof(g_BoxChatRecvBuffer));

        int recvResult = recv(g_BoxChatSocket, g_BoxChatRecvBuffer, sizeof(g_BoxChatRecvBuffer), 0);
        if (recvResult <= 0)
        {
            return;
        }

        std::string recvText = g_BoxChatRecvBuffer;
        if (recvText.size() == 0)
        {
            ////std::cout << "recvText size() == 0" << "\n";
            return;
        }

        ////std::cout << "recvText: " << recvText << "\n";

        std::vector<std::string> recvTokens = EQAPP_String_Split(recvText, '\n');

        if (recvTokens.size() == 0)
        {
            ////std::cout << "recvTokens size() == 0" << "\n";
            return;
        }

        for (auto& recvToken : recvTokens)
        {
            std::vector<std::string> textTokens = EQAPP_String_Split(recvToken, ' ');

            if (textTokens.size() == 0)
            {
                ////std::cout << "textTokens size() == 0" << "\n";
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
                        ////std::cout << "textTokensEx size() == 0" << "\n";
                        continue;
                    }

                    std::string commandText = EQAPP_String_JoinStrings(textTokensEx, " ");
                    if (commandText.size() == 0)
                    {
                        ////std::cout << "commandText size() == 0" << "\n";
                        break;
                    }

                    ////std::cout << "commandText: " << commandText << "\n";

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

    if (EQAPP_String_Contains(commandText, "/") == false)
    {
        return;
    }

    bool bUseTimer = false;

    bool bHasTimeElapsed = false;

    EQApp::TimerInterval timeInterval = 1;

    if (EQAPP_String_BeginsWith(commandText, "//Pause ") == true)
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

    std::stringstream ss;
    ss << "commandText=" << commandText;

    EQAPP_PrintDebugText(__FUNCTION__, ss.str().c_str());

    EQ_InterpretCommand(commandText.c_str());
}

bool EQAPP_BoxChat_IsServerRunning()
{
    return EQAPP_IsProcessRunning(g_BoxChatProcessFileNameWide);
}
