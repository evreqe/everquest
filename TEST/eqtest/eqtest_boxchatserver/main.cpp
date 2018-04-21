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

#define EQ_BCS_PORT_NUMBER 29015

#define EQ_BCS_CLIENTS_MAX 32

#define EQ_BCS_STRING_MAX 4096

std::string EQ_BCS_JoinStrings(const std::vector<std::string> &elements, const std::string &separator)
{       
    if (elements.empty() == false)
    {
        std::stringstream ss;

        auto it = elements.cbegin();
        while (true)
        {
            ss << *it++;

            if (it != elements.cend())
            {
                ss << separator;
            }
            else
            {
                return ss.str();
            }
        }
    }

    return std::string();
}

std::vector<std::string> EQ_BCS_SplitString(const std::string& subject, char delimiter)
{
    std::vector<std::string> tokens;

    std::istringstream iss(subject);
    for (std::string token; std::getline(iss, token, delimiter); tokens.push_back(token));

    return tokens;
}

int main(int argc , char *argv[])
{
    std::cout << "EverQuest Box Chat Server" << std::endl;

    std::cout << "Port: " << EQ_BCS_PORT_NUMBER << std::endl;

    WSADATA wsaData;

    SOCKET clientSocket[EQ_BCS_CLIENTS_MAX];
    char clientName[EQ_BCS_CLIENTS_MAX][EQ_BCS_STRING_MAX];
    char clientChannel[EQ_BCS_CLIENTS_MAX][EQ_BCS_STRING_MAX];

    SOCKET listenSocket;
    SOCKET acceptSocket;
    SOCKET recvSocket;
    SOCKET sendSocket;

    struct sockaddr_in server;
    struct sockaddr_in serverAddress;

    int addressLength = sizeof(struct sockaddr_in);

    fd_set fdSetRead;

    char recvBuffer[EQ_BCS_STRING_MAX];

    for (size_t i = 0 ; i < EQ_BCS_CLIENTS_MAX; i++)
    {
        clientSocket[i] = 0;

        memset(clientName[i], 0, EQ_BCS_STRING_MAX);
        strcpy_s(clientName[i], EQ_BCS_STRING_MAX, "UNKNOWN");

        memset(clientChannel[i], 0, EQ_BCS_STRING_MAX);
        strcpy_s(clientChannel[i], EQ_BCS_STRING_MAX, "Default");
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
    server.sin_port        = htons(EQ_BCS_PORT_NUMBER);

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

        for (size_t i = 0 ; i < EQ_BCS_CLIENTS_MAX; i++)
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

            for (size_t i = 0; i < EQ_BCS_CLIENTS_MAX; i++)
            {
                if (clientSocket[i] == 0)
                {
                    clientSocket[i] = acceptSocket;
                    std::cout << "Client assigned to socket index: " << i << std::endl;
                    break;
                }
            }
        }

        for (size_t i = 0; i < EQ_BCS_CLIENTS_MAX; i++)
        {
            recvSocket = clientSocket[i];

            if (FD_ISSET(recvSocket, &fdSetRead))
            {
                getpeername(recvSocket, (struct sockaddr*)&serverAddress, (int*)&addressLength);

                const char* keepAliveMessage = "$KeepAlive\n";
                if (send(recvSocket, keepAliveMessage, strlen(keepAliveMessage), 0) == SOCKET_ERROR)
                {
                    std::cout << "Client disconnected because keep alive failed."
                                << " Socket: " << clientSocket[i]
                                << ", Name: " << clientName[i]
                                << std::endl;

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientName[i], EQ_BCS_STRING_MAX, "UNKNOWN");

                    memset(clientChannel[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientChannel[i], EQ_BCS_STRING_MAX, "Default");
                }

                memset(recvBuffer, 0, EQ_BCS_STRING_MAX);

                int recvResult = recv(recvSocket, recvBuffer, EQ_BCS_STRING_MAX, 0);

                int errorCode = WSAGetLastError();
                if (errorCode == WSAECONNRESET)
                {
                    std::cout << "Client disconnected unexpectedly."
                                << " Socket: " << clientSocket[i]
                                << ", Name: " << clientName[i]
                                << ", Channel: " << clientChannel[i]
                                << std::endl;

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientName[i], EQ_BCS_STRING_MAX, "UNKNOWN");

                    memset(clientChannel[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientChannel[i], EQ_BCS_STRING_MAX, "Default");
                }

                if (recvResult == SOCKET_ERROR)
                {
                    std::cout << "Client disconnected."
                              << " Socket: " << clientSocket[i]
                              << ", Name: " << clientName[i]
                              << std::endl;

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientName[i], EQ_BCS_STRING_MAX, "UNKNOWN");

                    memset(clientChannel[i], 0, EQ_BCS_STRING_MAX);
                    strcpy_s(clientChannel[i], EQ_BCS_STRING_MAX, "Default");
                }
                else
                {
                    recvBuffer[recvResult] = '\0'; // append null terminator

                    std::string recvText = recvBuffer;
                    if (recvText.size() == 0)
                    {
                        continue;
                    }

                    ////std::cout << "recvText: " << recvText << std::endl;

                    std::vector<std::string> recvTokens = EQ_BCS_SplitString(recvText, '\n');

                    for (auto& token : recvTokens)
                    {
                        std::cout << "#" << clientName[i] << " (" << clientChannel[i] << "): " << token << std::endl;

                        std::vector<std::string> textTokens = EQ_BCS_SplitString(token, ' ');

                        if (textTokens.size() > 1)
                        {
                            if (textTokens.at(0) == "$ClientName")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQ_BCS_CLIENTS_MAX; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Name '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << std::endl;

                                        strcpy_s(clientName[k], EQ_BCS_STRING_MAX, name.c_str());

                                        break;
                                    }
                                }
                            }

                            if (textTokens.at(0) == "$ClientChannel")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQ_BCS_CLIENTS_MAX; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Channel '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << std::endl;

                                        strcpy_s(clientChannel[k], EQ_BCS_STRING_MAX, name.c_str());

                                        break;
                                    }
                                }
                            }

                            bool bBCT  = false;
                            bool bBCTC = false;
                            bool bBCA  = false;
                            bool bBCAA = false;

                            bool bBroadcast = false;

                            if (textTokens.at(0) == "//BCT" || textTokens.at(0) == "//BoxChatTell")
                            {
                                bBCT  = true;
                                bBCTC = false;
                                bBCA  = false;
                                bBCAA = false;

                                bBroadcast = true;
                            }

                            if (textTokens.at(0) == "//BCTC" || textTokens.at(0) == "//BoxChatTellChannel")
                            {
                                bBCT  = false;
                                bBCTC = true;
                                bBCA  = false;
                                bBCAA = false;

                                bBroadcast = true;
                            }
 
                            if (textTokens.at(0) == "//BCA" || textTokens.at(0) == "//BoxChatOthers")
                            {
                                bBCT  = false;
                                bBCTC = false;
                                bBCA  = true;
                                bBCAA = false;

                                bBroadcast = true;
                            }

                            if (textTokens.at(0) == "//BCAA" || textTokens.at(0) == "//BoxChatAll")
                            {
                                bBCT  = false;
                                bBCTC = false;
                                bBCA  = false;
                                bBCAA = true;

                                bBroadcast = true;
                            }

                            if (bBroadcast == true)
                            {
                                for (size_t j = 0; j < EQ_BCS_CLIENTS_MAX; j++)
                                {
                                    if (clientSocket[j] == 0)
                                    {
                                        continue;
                                    }

                                    // skip clients with empty names or UNKNOWN
                                    if (bBCT == true || bBCTC == true)
                                    {
                                        if (strlen(clientName[j]) == 0)
                                        {
                                            continue;
                                        }

                                        if (strcmp(clientName[j], "UNKNOWN") == 0)
                                        {
                                            continue;
                                        }
                                    }

                                    sendSocket = clientSocket[j];

                                    // do not send BCA broadcasts to the sender
                                    if (sendSocket == recvSocket)
                                    {
                                        if (bBCT == false && bBCTC == false && bBCA == true && bBCAA == false)
                                        {
                                            continue;
                                        }
                                    }

                                    std::vector<std::string>::const_iterator textTokenFirst = textTokens.begin();
                                    std::vector<std::string>::const_iterator textTokenLast  = textTokens.end();

                                    if (bBCT == true)
                                    {
                                        std::string sendToClientName = textTokens.at(1);
                                        if (sendToClientName.size() == 0)
                                        {
                                            continue;
                                        }

                                        // skip clients that do not match the BCT tell name
                                        if (clientName[j] != sendToClientName)
                                        {
                                            continue;
                                        }

                                        if (textTokens.size() > 2)
                                        {
                                            textTokenFirst = textTokens.begin() + 2;
                                            textTokenLast  = textTokens.end();
                                        }
                                    }
                                    if (bBCTC == true)
                                    {
                                        std::string sendToChannelName = textTokens.at(1);
                                        if (sendToChannelName.size() == 0)
                                        {
                                            continue;
                                        }

                                        // skip clients that do not match the BCTC tell name
                                        if (clientChannel[j] != sendToChannelName)
                                        {
                                            continue;
                                        }

                                        if (textTokens.size() > 2)
                                        {
                                            textTokenFirst = textTokens.begin() + 2;
                                            textTokenLast  = textTokens.end();
                                        }
                                    }
                                    else
                                    {
                                        if (textTokens.size() > 1)
                                        {
                                            textTokenFirst = textTokens.begin() + 1;
                                            textTokenLast  = textTokens.end();
                                        }
                                    }

                                    std::vector<std::string> textTokensEx(textTokenFirst, textTokenLast);
                                    if (textTokensEx.size() == 0)
                                    {
                                        continue;
                                    }

                                    std::string textTokensExStr = EQ_BCS_JoinStrings(textTokensEx, " ");
                                    if (textTokensExStr.size() == 0)
                                    {
                                        continue;
                                    }

                                    std::vector<std::string> commandTokens = EQ_BCS_SplitString(textTokensExStr, ';');
                                    if (commandTokens.size() == 0)
                                    {
                                        continue;
                                    }

                                    for (auto& commandToken : commandTokens)
                                    {
                                        if (commandToken.size() == 0)
                                        {
                                             continue;
                                        }

                                        std::stringstream ssCommandText;
                                        ssCommandText << "$InterpretCommand " << commandToken << "\n";

                                        std::string commandText = ssCommandText.str();
                                        if (commandText.size() == 0)
                                        {
                                             continue;
                                        }

                                        ////std::cout << "commandText: " << commandText << std::endl;

                                        send(sendSocket, commandText.c_str(), commandText.size(), 0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    closesocket(listenSocket);
    closesocket(acceptSocket);
    closesocket(recvSocket);
    closesocket(sendSocket);

    for (size_t i = 0; i < EQ_BCS_CLIENTS_MAX; i++)
    {
        closesocket(clientSocket[i]);
    }

    WSACleanup();

    return 0;
}
