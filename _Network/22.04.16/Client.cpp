//* 202131230 정윤혁 2022.04.09

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    SOCKET hSocket;
    SOCKADDR_IN servAddr = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("Failed WSAStartup() \n");
        return 1;
    }

    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (hSocket == INVALID_SOCKET)
    {
        printf("Failed socket() \n");
        WSACleanup();
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);
    servAddr.sin_port = htons(30002);
    if (connect(hSocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        printf("failed connect()\n");
        closesocket(hSocket);
        WSACleanup();
        return 1;
    }

    int recvSize;
    char recvData[255];
    char sendData[255];

    recvSize = recv(hSocket, recvData, sizeof(recvData), 0);
    if (recvSize == SOCKET_ERROR)
        printf("recv() error\n");
    printf("recv :%s\n", recvData);
    int count = 10;
    while (count--)
    {
        sendData[0] = count;
        send(hSocket, sendData, 1, 0);
        printf("send data :%d \n", sendData[0]);
        recvSize = recv(hSocket, recvData, sizeof(recvData), 0);
        if (recvSize == SOCKET_ERROR)
        {
            printf("recv() ERR \n");
            break;
        }
        printf("recv data :%d \n", recvData[0]);
    }

    closesocket(hSocket);
    WSACleanup();
    system("pause");

    return 0;
}