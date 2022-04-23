//* 202131230 정윤혁 2022.04.09

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    SOCKET listenSocket;
    SOCKADDR_IN servAddr = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        printf("Failed WSAStartup() \n");

    listenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listenSocket == INVALID_SOCKET)
    {
        printf("Failed socket() \n");
        return 1;
    }
    printf("Server Start \n");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(30002);
    if (bind(listenSocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        printf("Binding ERROR \n");
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }
    if (listen(listenSocket, 5) == SOCKET_ERROR)
    {
        printf("listen Error \n");
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN clientAddr;
    SOCKET clientSocket;
    int sizeClientAddr = sizeof(clientAddr);
    char sendData[255] = "202131230 정윤혁";
    char recvByte;
    char recvData[255];
    int recvCount = 0;
    while (1)
    {
        clientSocket = accept(listenSocket, (SOCKADDR *)&clientAddr, &sizeClientAddr);

        if (clientSocket == INVALID_SOCKET)
        {
            printf("Failed accept \n");
        }
        recvCount = 0;
        send(clientSocket, sendData, strlen(sendData) + 1, 0);

        printf("recv count:");
        while ((recvByte = recv(clientSocket, recvData, sizeof(recvData), 0)) > 0)
        {
            printf("%d", ++recvCount);
            send(clientSocket, recvData, recvByte, 0);
        }
        printf("\n");

        closesocket(listenSocket);
        printf("close socket : %d \n", clientSocket);
    }

    closesocket(listenSocket);
    WSACleanup();
    system("pause");

    return 0;
}