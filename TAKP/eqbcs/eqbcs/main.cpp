#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "ws2_32.lib")

#define EQBCS_PORT_NUMBER 29015

#define EQBCS_CLIENTS_MAX 32

#define EQBCS_STRING_MAX 4096

int main(int argc , char *argv[])
{
    std::cout << "EverQuest Box Chat Server" << std::endl;

    std::cout << "Port: " << EQBCS_PORT_NUMBER << std::endl;

    WSADATA wsaData;

    SOCKET clientSocket[EQBCS_CLIENTS_MAX];
    char clientSocketName[EQBCS_CLIENTS_MAX][EQBCS_STRING_MAX];

    SOCKET listenSocket;
    SOCKET acceptSocket;
    SOCKET recvSocket;
    SOCKET sendSocket;

    struct sockaddr_in server;
    struct sockaddr_in serverAddress;

    int addressLength = sizeof(struct sockaddr_in);

    fd_set fdSetRead;

    char recvBuffer[EQBCS_STRING_MAX];

    for (size_t i = 0 ; i < EQBCS_CLIENTS_MAX; i++)
    {
        clientSocket[i] = 0;
        memset(clientSocketName[i], 0, EQBCS_STRING_MAX);
        strcpy_s(clientSocketName[i], EQBCS_STRING_MAX, "UNKNOWN");
    }

    std::cout << "Initializing Winsock..." << std::endl;

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
    {
        std::cout << "WSAStartup() failed. Error Code: " << WSAGetLastError() << std::endl;
        return 1;
    }

    std::cout << "Creating listen socket..." << std::endl;

    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        std::cout << "socket() failed. Error Code: " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        return 1;
    }

    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port        = htons(EQBCS_PORT_NUMBER);

    std::cout << "Binding listen socket..." << std::endl;

    if (bind(listenSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        std::cout << "bind() failed. Error Code: " << WSAGetLastError() << std::endl;
        return 1;
    }

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "listen() failed. Error Code: " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        return 1;
    }

    std::cout << "Waiting for incoming connections..." << std::endl;

    while (true)
    {
        FD_ZERO(&fdSetRead);
        FD_SET(listenSocket, &fdSetRead);

        for (size_t i = 0 ; i < EQBCS_CLIENTS_MAX; i++)
        {
            recvSocket = clientSocket[i];

            if (recvSocket > 0)
            {
                FD_SET(recvSocket , &fdSetRead);
            }
        }

        int selectResult = select(0, &fdSetRead, NULL, NULL, NULL);
        if (selectResult == SOCKET_ERROR)
        {
            std::cout << "select() failed. Error Code: " << WSAGetLastError() << std::endl;
            return 1;
        }

        if (FD_ISSET(listenSocket, &fdSetRead))
        {
            if ((acceptSocket = accept(listenSocket, (struct sockaddr*)&serverAddress, (int*)&addressLength)) < 0)
            {
                std::cout << "accept() failed." << std::endl;
                return 1;
            }

            std::cout << "Client connected. Socket: " << acceptSocket
                      << ", IP: " << inet_ntoa(serverAddress.sin_addr)
                      << ", Port: " << ntohs(serverAddress.sin_port)
                      << std::endl;

            //const char* connectMessage = "Connected to EverQuest Box Chat Server\n";
            //send(acceptSocket, connectMessage, strlen(connectMessage), 0);

            for (size_t i = 0; i < EQBCS_CLIENTS_MAX; i++)
            {
                if (clientSocket[i] == 0)
                {
                    clientSocket[i] = acceptSocket;
                    std::cout << "Client assigned to socket index: " << i << std::endl;
                    break;
                }
            }
        }

        for (size_t i = 0; i < EQBCS_CLIENTS_MAX; i++)
        {
            recvSocket = clientSocket[i];

            if (FD_ISSET(recvSocket, &fdSetRead))
            {
                getpeername(recvSocket, (struct sockaddr*)&serverAddress, (int*)&addressLength);

                int recvResult = recv(recvSocket, recvBuffer, EQBCS_STRING_MAX, 0);

                int errorCode = WSAGetLastError();
                if (errorCode == WSAECONNRESET)
                {
                    std::cout << "Client disconnected unexpectedly."
                                << " Socket: " << clientSocket[i]
                                << ", Name: " << clientSocketName[i]
                                << std::endl;

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);

                    clientSocket[i] = 0;
                    memset(clientSocketName[i], 0, EQBCS_STRING_MAX);
                    strcpy_s(clientSocketName[i], EQBCS_STRING_MAX, "UNKNOWN");
                }

                if (recvResult == SOCKET_ERROR)
                {
                    std::cout << "Client disconnected."
                              << " Socket: " << clientSocket[i]
                              << ", Name: " << clientSocketName[i]
                              << std::endl;

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);
                    clientSocket[i] = 0;
                    memset(clientSocketName[i], 0, EQBCS_STRING_MAX);
                    strcpy_s(clientSocketName[i], EQBCS_STRING_MAX, "UNKNOWN");
                }
                else
                {
                    recvBuffer[recvResult] = '\0'; // append null terminator

                    std::string recvText = recvBuffer;

                    std::istringstream recvSplit(recvText);
                    std::vector<std::string> recvTokens;
                    for (std::string recvToken; std::getline(recvSplit, recvToken, '\n'); recvTokens.push_back(recvToken));

                    for (auto& token : recvTokens)
                    {
                        std::cout << "#" << clientSocketName[i] << ": " << token << std::endl;

                        std::istringstream textSplit(token);
                        std::vector<std::string> textTokens;
                        for (std::string textToken; std::getline(textSplit, textToken, ' '); textTokens.push_back(textToken));

                        if (textTokens.size() == 2)
                        {
                            if (textTokens.at(0) == "$ConnectName")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQBCS_CLIENTS_MAX; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Name '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << std::endl;

                                        strcpy_s(clientSocketName[k], EQBCS_STRING_MAX, name.c_str());

                                        break;
                                    }
                                }
                            }
                        }
                    }

/*
                    char* token     = NULL;
                    char* tokenNext = NULL;

                    token = strtok_s(receivedText, "\n", &tokenNext);
                    while (token != NULL)
                    {
                        //printf("token: %s\n", token);

                        size_t commandLength = 0;

                        if (strncmp(token, "Name: ", 6) == 0)
                        {
                            char name[EQBCS_STRING_MAX];
                            strcpy_s(name, token + 6);

                            //printf("name: %s\n", name);

                            for (size_t k = 0; k < EQBCS_CLIENTS_MAX; k++)
                            {
                                if (clientSocket[k] == recvSocket)
                                {
                                    printf("Name: %s, linked to client socket %d from receive socket %d\n", name, clientSocket[k], recvSocket);

                                    strcpy_s(clientSocketName[k], name);

                                    //acceptSocket = INVALID_SOCKET;

                                    break;
                                }
                            }
                        }

                        bool bBCT  = false;
                        bool bBCA  = false;
                        bool bBCAA = false;

                        bool bBroadcast = false;

                        if (strncmp(token, "/bct", 4) == 0)
                        {
                            commandLength = strlen("/bct") + 1;

                            bBCT  = true;
                            bBCA  = false;
                            bBCAA = false;

                            bBroadcast = true;
                        }
 
                        if (strncmp(token, "/bca", 4) == 0)
                        {
                            commandLength = strlen("/bca") + 1;

                            bBCT  = false;
                            bBCA  = true;
                            bBCAA = false;

                            bBroadcast = true;

                            if (strncmp(token, "/bcaa", 5) == 0)
                            {
                                commandLength = strlen("/bcaa") + 1;

                                bBCT  = false;
                                bBCA  = false;
                                bBCAA = true;

                                bBroadcast = true;
                            }
                        }

                        if (bBroadcast == true)
                        {
                            for (size_t j = 0; j < EQBCS_CLIENTS_MAX; j++)
                            {
                                if (clientSocket[j] == 0)
                                {
                                    continue;
                                }

                                if (bBCT == true)
                                {
                                    //printf("bBCT == true\n");

                                    if (strlen(clientSocketName[j]) == 0)
                                    {
                                        continue;
                                    }
                                }

                                sendSocket = clientSocket[j];

                                if (bBCT == false && bBCA == true && bBCAA == false && sendSocket == recvSocket)
                                {
                                    //printf("bBCA == true, sendSocket == recvSocket\n");

                                    continue;
                                }

                                char bcText[EQBCS_STRING_MAX] = {0};
                                strcpy_s(bcText, token + commandLength);

                                char name2[EQBCS_STRING_MAX];

                                char* token2     = NULL;
                                char* token2Next = NULL;

                                if (bBCT == true)
                                {
                                    token2 = strtok_s(bcText, " ", &token2Next);

                                    // token2 == Name
                                    strcpy_s(name2, token2);

                                    token2 = strtok_s(NULL, "", &token2Next);

                                    token2 = strtok_s(token2, ";", &token2Next);

                                    //printf("bBCT token2: %s\n", token2);
                                }
                                else
                                {
                                    token2 = strtok_s(bcText, ";", &token2Next);
                                }

                                //printf("name2: %s\n", name2);

                                if (bBCT == true)
                                {
                                    if (strlen(name2) == 0)
                                    {
                                        continue;
                                    }

                                    if (strcmp(name2, clientSocketName[j]) != 0)
                                    {
                                        //printf("strcmp(name2, clientSocketName[j]) != 0, %s != %s\n", name2, clientSocketName[j]);
                                        continue;
                                    }
                                }

                                while (token2 != NULL)
                                {
                                    //printf("token2: %s\n", token2);

                                    if (token2[0] != '/')
                                    {
                                         continue;
                                    }

                                    char commandText[EQBCS_STRING_MAX] = {0};
                                    sprintf_s(commandText, "Command: %s\n", token2);

                                    //printf("commandText: %s\n", commandText);

                                    send(sendSocket, commandText, strlen(commandText), 0);

                                    token2 = strtok_s(NULL, ";", &token2Next);
                                }
                            }
                        }

                        token = strtok_s(NULL, "\n", &tokenNext);
                    }
*/
                }
            }
        }
    }

    closesocket(listenSocket);
    closesocket(acceptSocket);
    closesocket(recvSocket);
    closesocket(sendSocket);

    for (size_t i = 0; i < EQBCS_CLIENTS_MAX; i++)
    {
        closesocket(clientSocket[i]);
    }

    WSACleanup();

    return 0;
}
