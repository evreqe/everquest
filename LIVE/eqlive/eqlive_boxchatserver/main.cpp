#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "ws2_32.lib")

namespace EQBoxChatServer
{
    uint32_t PortNumber = 29015;

    const uint32_t ClientsMax = 64;

    const uint32_t StringMax = 4096;

    std::string JoinStrings(const std::vector<std::string> &elements, const std::string &separator)
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

    std::vector<std::string> SplitString(const std::string& subject, char delimiter)
    {
        std::vector<std::string> tokens;

        std::istringstream iss(subject);
        for (std::string token; std::getline(iss, token, delimiter); tokens.push_back(token));

        return tokens;
    }

}; // namespace EQBoxChatServer

int main(int argc , char *argv[])
{
    std::cout << "EverQuest Box Chat Server" << "\n";

    std::cout << "Build: " << __DATE__ << " " << __TIME__ << "\n";

    std::cout << "Port: " << EQBoxChatServer::PortNumber << "\n";

    WSADATA wsaData;

    SOCKET clientSocket[EQBoxChatServer::ClientsMax];
    char clientName[EQBoxChatServer::ClientsMax][EQBoxChatServer::StringMax];
    char clientGlobalChannel[EQBoxChatServer::ClientsMax][EQBoxChatServer::StringMax];
    char clientChannel[EQBoxChatServer::ClientsMax][EQBoxChatServer::StringMax];

    SOCKET listenSocket;
    SOCKET acceptSocket;
    SOCKET recvSocket;
    SOCKET sendSocket;

    struct sockaddr_in server;
    struct sockaddr_in serverAddress;

    int addressLength = sizeof(struct sockaddr_in);

    fd_set fdSetRead;

    char recvBuffer[EQBoxChatServer::StringMax];

    for (size_t i = 0 ; i < EQBoxChatServer::ClientsMax; i++)
    {
        clientSocket[i] = 0;

        memset(clientName[i], 0, EQBoxChatServer::StringMax);
        strcpy_s(clientName[i], EQBoxChatServer::StringMax, "UNKNOWN");

        memset(clientGlobalChannel[i], 0, EQBoxChatServer::StringMax);
        strcpy_s(clientGlobalChannel[i], EQBoxChatServer::StringMax, "Global1");

        memset(clientChannel[i], 0, EQBoxChatServer::StringMax);
        strcpy_s(clientChannel[i], EQBoxChatServer::StringMax, "Default");
    }

    std::cout << "Initializing Winsock..." << "\n";

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0)
    {
        std::cout << "WSAStartup() failed. Error Code: " << WSAGetLastError() << "\n";
        return 1;
    }

    std::cout << "Creating listen socket..." << "\n";

    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        std::cout << "socket() failed. Error Code: " << WSAGetLastError() << "\n";
        closesocket(listenSocket);
        return 1;
    }

    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port        = htons(EQBoxChatServer::PortNumber);

    std::cout << "Binding listen socket..." << "\n";

    if (bind(listenSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        std::cout << "bind() failed. Error Code: " << WSAGetLastError() << "\n";
        return 1;
    }

    if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cout << "listen() failed. Error Code: " << WSAGetLastError() << "\n";
        closesocket(listenSocket);
        return 1;
    }

    std::cout << "Waiting for incoming connections..." << "\n";

    while (true)
    {
        FD_ZERO(&fdSetRead);
        FD_SET(listenSocket, &fdSetRead);

        for (size_t i = 0 ; i < EQBoxChatServer::ClientsMax; i++)
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
            std::cout << "select() failed. Error Code: " << WSAGetLastError() << "\n";
            return 1;
        }

        if (FD_ISSET(listenSocket, &fdSetRead))
        {
            if ((acceptSocket = accept(listenSocket, (struct sockaddr*)&serverAddress, (int*)&addressLength)) < 0)
            {
                std::cout << "accept() failed." << "\n";
                return 1;
            }

            char strIPAddress[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(serverAddress.sin_addr), strIPAddress, INET_ADDRSTRLEN);

            std::cout << "Client connected. Socket: " << acceptSocket
                      << ", IP: " << strIPAddress
                      << ", Port: " << ntohs(serverAddress.sin_port)
                      << "\n";

            //const char* connectMessage = "Connected to EverQuest Box Chat Server\n";
            //send(acceptSocket, connectMessage, strlen(connectMessage), 0);

            for (size_t i = 0; i < EQBoxChatServer::ClientsMax; i++)
            {
                if (clientSocket[i] == 0)
                {
                    clientSocket[i] = acceptSocket;
                    std::cout << "Client assigned to socket index: " << i << "\n";
                    break;
                }
            }
        }

        for (size_t i = 0; i < EQBoxChatServer::ClientsMax; i++)
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
                                << "\n";

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientName[i], EQBoxChatServer::StringMax, "UNKNOWN");

                    memset(clientGlobalChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientGlobalChannel[i], EQBoxChatServer::StringMax, "Global1");

                    memset(clientChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientChannel[i], EQBoxChatServer::StringMax, "Default");
                }

                memset(recvBuffer, 0, EQBoxChatServer::StringMax);

                int recvResult = recv(recvSocket, recvBuffer, EQBoxChatServer::StringMax, 0);

                int errorCode = WSAGetLastError();
                if (errorCode == WSAECONNRESET)
                {
                    std::cout << "Client disconnected unexpectedly."
                                << " Socket: " << clientSocket[i]
                                << ", Name: " << clientName[i]
                                << ", Global Channel: " << clientGlobalChannel[i]
                                << ", Channel: " << clientChannel[i]
                                << "\n";

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientName[i], EQBoxChatServer::StringMax, "UNKNOWN");

                    memset(clientGlobalChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientGlobalChannel[i], EQBoxChatServer::StringMax, "Global1");

                    memset(clientChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientChannel[i], EQBoxChatServer::StringMax, "Default");
                }

                if (recvResult == SOCKET_ERROR)
                {
                    std::cout << "Client disconnected."
                              << " Socket: " << clientSocket[i]
                              << ", Name: " << clientName[i]
                              << "\n";

                    //const char* disconnectMessage = "Disconnected from EverQuest Box Chat Server\n";
                    //send(recvSocket, disconnectMessage, strlen(disconnectMessage), 0);

                    closesocket(recvSocket);

                    clientSocket[i] = 0;

                    memset(clientName[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientName[i], EQBoxChatServer::StringMax, "UNKNOWN");

                    memset(clientGlobalChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientGlobalChannel[i], EQBoxChatServer::StringMax, "Global1");

                    memset(clientChannel[i], 0, EQBoxChatServer::StringMax);
                    strcpy_s(clientChannel[i], EQBoxChatServer::StringMax, "Default");
                }
                else
                {
                    recvBuffer[EQBoxChatServer::StringMax - 1] = '\0'; // append null terminator

                    std::string recvText = recvBuffer;
                    if (recvText.size() == 0)
                    {
                        continue;
                    }

                    ////std::cout << "recvText: " << recvText << "\n";

                    std::vector<std::string> recvTokens = EQBoxChatServer::SplitString(recvText, '\n');

                    for (auto& token : recvTokens)
                    {
                        if (token != "$KeepAlive")
                        {
                            std::cout << "#" << clientName[i] << " (" << clientChannel[i] << "): " << token << "\n";
                        }

                        std::vector<std::string> textTokens = EQBoxChatServer::SplitString(token, ' ');

                        if (textTokens.size() > 1)
                        {
                            if (textTokens.at(0) == "$ClientName")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQBoxChatServer::ClientsMax; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Name '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << "\n";

                                        strcpy_s(clientName[k], EQBoxChatServer::StringMax, name.c_str());

                                        break;
                                    }
                                }
                            }

                            if (textTokens.at(0) == "$ClientGlobalChannel")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQBoxChatServer::ClientsMax; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Global Channel '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << "\n";

                                        strcpy_s(clientGlobalChannel[k], EQBoxChatServer::StringMax, name.c_str());

                                        break;
                                    }
                                }
                            }

                            if (textTokens.at(0) == "$ClientChannel")
                            {
                                std::string name = textTokens.at(1);

                                for (size_t k = 0; k < EQBoxChatServer::ClientsMax; k++)
                                {
                                    if (clientSocket[k] == recvSocket)
                                    {
                                        std::cout << "Channel '" << name
                                                  << "' has been linked to client socket " << clientSocket[k]
                                                  << "\n";

                                        strcpy_s(clientChannel[k], EQBoxChatServer::StringMax, name.c_str());

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

                            if (textTokens.at(0) == "//BCTC" || textTokens.at(0) == "//BoxChatToChannel")
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
                                int sendIndex = -1;
                                int recvIndex = -1;

                                for (size_t l = 0; l < EQBoxChatServer::ClientsMax; l++)
                                {
                                    if (clientSocket[l] == 0)
                                    {
                                        continue;
                                    }

                                    if (clientSocket[l] == sendSocket)
                                    {
                                        sendIndex = l;
                                    }

                                    if (clientSocket[l] == recvSocket)
                                    {
                                        recvIndex = l;
                                    }
                                }

                                // skip clients that do not have the same global channel as the sender
                                if (sendIndex != -1 && recvIndex != -1)
                                {
                                    if (strcmp(clientGlobalChannel[sendIndex], clientGlobalChannel[recvIndex]) != 0)
                                    {
                                        continue;
                                    }
                                }

                                for (size_t j = 0; j < EQBoxChatServer::ClientsMax; j++)
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

                                    // do not send broadcast to the sender
                                    if (sendSocket == recvSocket)
                                    {
                                        if (bBCT == true || bBCTC == true || bBCA == true)
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
                                    else if (bBCTC == true)
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

                                    std::string textTokensExStr = EQBoxChatServer::JoinStrings(textTokensEx, " ");
                                    if (textTokensExStr.size() == 0)
                                    {
                                        continue;
                                    }

                                    std::vector<std::string> commandTokens = EQBoxChatServer::SplitString(textTokensExStr, ';');
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

                                        ////std::cout << "commandText: " << commandText << "\n";

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

    for (size_t i = 0; i < EQBoxChatServer::ClientsMax; i++)
    {
        closesocket(clientSocket[i]);
    }

    WSACleanup();

    return 0;
}
