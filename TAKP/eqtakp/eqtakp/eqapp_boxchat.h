#pragma once

#define EQBCS_IP_ADDRESS "127.0.0.1"
#define EQBCS_PORT_NUMBER "29015"
#define EQBCS_STRING_MAX 4096

bool g_boxChatIsEnabled = true;

bool g_boxChatIsConnected = false;

uint32_t g_boxChatKeepAliveTimer = 0;
uint32_t g_boxChatKeepAliveTimerDelay = 30000; // 30 seconds

char g_boxChatServerIPAddress[EQBCS_STRING_MAX];
char g_boxChatServerPort[EQBCS_STRING_MAX];

char g_boxChatRecvBuffer[EQBCS_STRING_MAX] = {0};

WSADATA g_boxChatWSAData;
SOCKET g_boxChatConnectSocket;
fd_set g_boxChatFDSetRead;

struct addrinfo* g_boxChatAddressInfoResult = NULL;
struct addrinfo* g_boxChatAddressInfo_ptr = NULL;
struct addrinfo g_boxChatAddressInfoHints;

void EQAPP_BoxChat_Toggle();
void EQAPP_BoxChat_Load();
void EQAPP_BoxChat_Unload();
bool EQAPP_BoxChat_Connect();
void EQAPP_BoxChat_Disconnect();
void EQAPP_BoxChat_Execute();
bool EQAPP_BoxChat_SendText(std::string text);

void EQAPP_BoxChat_Toggle()
{
    EQ_ToggleBool(g_boxChatIsEnabled);
    EQAPP_PrintBool("Box Chat", g_boxChatIsEnabled);
}

void EQAPP_BoxChat_Load()
{
    EQAPP_BoxChat_Connect();
}

void EQAPP_BoxChat_Unload()
{
    if (shutdown(g_boxChatConnectSocket, SD_BOTH) == SOCKET_ERROR)
    {
        closesocket(g_boxChatConnectSocket);
    }

    closesocket(g_boxChatConnectSocket);
}

bool EQAPP_BoxChat_Connect()
{
    // functions WSAStartup() and WSACleanup() are not needed
    // because the game already calls them for us
    // if we call the functions ourselves, the game will crash

    closesocket(g_boxChatConnectSocket);

    g_boxChatIsConnected = false;

    ZeroMemory(&g_boxChatAddressInfoHints, sizeof(g_boxChatAddressInfoHints));
    g_boxChatAddressInfoHints.ai_family   = AF_INET;
    g_boxChatAddressInfoHints.ai_socktype = SOCK_STREAM;
    g_boxChatAddressInfoHints.ai_protocol = IPPROTO_TCP;

    if (strlen(g_boxChatServerIPAddress) == 0)
    {
        strncpy_s(g_boxChatServerIPAddress, sizeof(g_boxChatServerIPAddress), EQBCS_IP_ADDRESS, _TRUNCATE);
    }

    if (strlen(g_boxChatServerPort) == 0)
    {
        strncpy_s(g_boxChatServerPort, sizeof(g_boxChatServerPort), EQBCS_PORT_NUMBER, _TRUNCATE);
    }

    if (getaddrinfo(g_boxChatServerIPAddress, g_boxChatServerPort, &g_boxChatAddressInfoHints, &g_boxChatAddressInfoResult) != 0)
    {
        freeaddrinfo(g_boxChatAddressInfoResult);
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    g_boxChatAddressInfo_ptr = g_boxChatAddressInfoResult;

    g_boxChatConnectSocket = socket(g_boxChatAddressInfo_ptr->ai_family, g_boxChatAddressInfo_ptr->ai_socktype, g_boxChatAddressInfo_ptr->ai_protocol);

    if (g_boxChatConnectSocket == INVALID_SOCKET)
    {
        freeaddrinfo(g_boxChatAddressInfoResult);
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    if (connect(g_boxChatConnectSocket, g_boxChatAddressInfo_ptr->ai_addr, (int)g_boxChatAddressInfo_ptr->ai_addrlen) != SOCKET_ERROR)
    {
        if (g_boxChatConnectSocket != INVALID_SOCKET)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn == NULL)
            {
                freeaddrinfo(g_boxChatAddressInfoResult);
                EQAPP_BoxChat_Disconnect();
                return false;
            }

            std::stringstream ssConnectMessage;
            ssConnectMessage << "$ConnectName " << EQ_GetSpawnName(playerSpawn) << "\n";

            std::string strConnectMessage = ssConnectMessage.str();

            if (send(g_boxChatConnectSocket, strConnectMessage.c_str(), strConnectMessage.size(), 0) == SOCKET_ERROR)
            {
                freeaddrinfo(g_boxChatAddressInfoResult);
                EQAPP_BoxChat_Disconnect();
                return false;
            }

            std::cout << "Box Chat connected." << std::endl;

            freeaddrinfo(g_boxChatAddressInfoResult);
            g_boxChatIsConnected = true;
            return true;
        }
    }

    freeaddrinfo(g_boxChatAddressInfoResult);
    EQAPP_BoxChat_Disconnect();
    return false;
}

void EQAPP_BoxChat_Disconnect()
{
    closesocket(g_boxChatConnectSocket);

    g_boxChatIsConnected = false;

    std::cout << "Box Chat disconnected." << std::endl;
}

void EQAPP_BoxChat_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (g_boxChatIsConnected == false || g_boxChatConnectSocket == INVALID_SOCKET)
    {
        return;
    }

    if (EQ_HasTimePassed(g_boxChatKeepAliveTimer, g_boxChatKeepAliveTimerDelay) == true)
    {
        EQAPP_BoxChat_SendText("$KeepAlive\n");
    }
}

bool EQAPP_BoxChat_SendText(std::string text)
{
    if (send(g_boxChatConnectSocket, text.c_str(), text.size(), 0) == SOCKET_ERROR)
    {
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    return true;
}

