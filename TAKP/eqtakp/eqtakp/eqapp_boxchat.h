#pragma once

#define EQBCS_IP_ADDRESS "127.0.0.1"
#define EQBCS_PORT_NUMBER "29015"
#define EQBCS_STRING_MAX 4096

bool g_BoxChatIsEnabled = true;

bool g_BoxChatIsConnected = false;

uint32_t g_BoxChatKeepAliveTimer = 0;
uint32_t g_BoxChatKeepAliveTimerDelay = 30000; // 30 seconds

char g_BoxChatServerIPAddress[EQBCS_STRING_MAX];
char g_BoxChatServerPort[EQBCS_STRING_MAX];

char g_BoxChatRecvBuffer[EQBCS_STRING_MAX] = {0};

WSADATA g_BoxChatWSAData;
SOCKET g_BoxChatConnectSocket;
fd_set g_BoxChatFDSetRead;

struct addrinfo* g_BoxChatAddressInfoResult = NULL;
struct addrinfo* g_BoxChatAddressInfo_ptr = NULL;
struct addrinfo g_BoxChatAddressInfoHints;

void EQAPP_BoxChat_Toggle();
void EQAPP_BoxChat_Load();
void EQAPP_BoxChat_Unload();
bool EQAPP_BoxChat_Connect();
void EQAPP_BoxChat_Disconnect();
void EQAPP_BoxChat_Execute();
bool EQAPP_BoxChat_SendText(std::string text);

void EQAPP_BoxChat_Toggle()
{
    EQ_ToggleBool(g_BoxChatIsEnabled);
    EQAPP_PrintBool("Box Chat", g_BoxChatIsEnabled);
}

void EQAPP_BoxChat_Load()
{
    EQAPP_BoxChat_Connect();
}

void EQAPP_BoxChat_Unload()
{
    if (shutdown(g_BoxChatConnectSocket, SD_BOTH) == SOCKET_ERROR)
    {
        closesocket(g_BoxChatConnectSocket);
    }

    closesocket(g_BoxChatConnectSocket);
}

bool EQAPP_BoxChat_Connect()
{
    // functions WSAStartup() and WSACleanup() are not needed
    // because the game already calls them for us
    // if we call the functions ourselves, the game will crash

    closesocket(g_BoxChatConnectSocket);

    g_BoxChatIsConnected = false;

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
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    g_BoxChatAddressInfo_ptr = g_BoxChatAddressInfoResult;

    g_BoxChatConnectSocket = socket(g_BoxChatAddressInfo_ptr->ai_family, g_BoxChatAddressInfo_ptr->ai_socktype, g_BoxChatAddressInfo_ptr->ai_protocol);

    if (g_BoxChatConnectSocket == INVALID_SOCKET)
    {
        freeaddrinfo(g_BoxChatAddressInfoResult);
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    if (connect(g_BoxChatConnectSocket, g_BoxChatAddressInfo_ptr->ai_addr, (int)g_BoxChatAddressInfo_ptr->ai_addrlen) != SOCKET_ERROR)
    {
        if (g_BoxChatConnectSocket != INVALID_SOCKET)
        {
            auto playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn == NULL)
            {
                freeaddrinfo(g_BoxChatAddressInfoResult);
                EQAPP_BoxChat_Disconnect();
                return false;
            }

            std::stringstream ssConnectMessage;
            ssConnectMessage << "$ConnectName " << EQ_GetSpawnName(playerSpawn) << "\n";

            std::string strConnectMessage = ssConnectMessage.str();

            if (send(g_BoxChatConnectSocket, strConnectMessage.c_str(), strConnectMessage.size(), 0) == SOCKET_ERROR)
            {
                freeaddrinfo(g_BoxChatAddressInfoResult);
                EQAPP_BoxChat_Disconnect();
                return false;
            }

            std::cout << "Box Chat connected." << std::endl;

            freeaddrinfo(g_BoxChatAddressInfoResult);
            g_BoxChatIsConnected = true;
            return true;
        }
    }

    freeaddrinfo(g_BoxChatAddressInfoResult);
    EQAPP_BoxChat_Disconnect();
    return false;
}

void EQAPP_BoxChat_Disconnect()
{
    closesocket(g_BoxChatConnectSocket);

    g_BoxChatIsConnected = false;

    std::cout << "Box Chat disconnected." << std::endl;
}

void EQAPP_BoxChat_Execute()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    if (g_BoxChatIsConnected == false || g_BoxChatConnectSocket == INVALID_SOCKET)
    {
        return;
    }

    if (EQ_HasTimePassed(g_BoxChatKeepAliveTimer, g_BoxChatKeepAliveTimerDelay) == true)
    {
        EQAPP_BoxChat_SendText("$KeepAlive\n");
    }
}

bool EQAPP_BoxChat_SendText(std::string text)
{
    if (send(g_BoxChatConnectSocket, text.c_str(), text.size(), 0) == SOCKET_ERROR)
    {
        EQAPP_BoxChat_Disconnect();
        return false;
    }

    return true;
}

