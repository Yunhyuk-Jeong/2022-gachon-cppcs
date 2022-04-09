//* 202131230 정윤혁 2022.04.09

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    SOCKET hSocket;
    SOCKADDR_IN servAddr = {0};

    //* 1   WinSock Init
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        printf("Failed WSAStartup() \n");

    //* 2   Socket Generate
    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (hSocket == INVALID_SOCKET)
        printf("Failed socket() \n");

    //* 3   Server Connecting
    //* 3-1 Set the server address to be connected
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr); //* Server IP Address
    servAddr.sin_port = htons(23000);                    //* Server Port

    //* 3-2 Try Connecting to Server
    if (connect(hSocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        printf("Failed connect() \n");

    //* 4   Waiting for communication from the server
    int recvSize;
    char recvData[255];
    recvSize = recv(hSocket, recvData, sizeof(recvData), 0);
    if (recvSize == -1)
        printf("recv() Error \n");

    printf("recv%d message : %s \n", recvSize, recvData);

    //* 5   Socket Close -> WinSock Close
    closesocket(hSocket);
    WSACleanup();
    system("pause");

    return 0;
}