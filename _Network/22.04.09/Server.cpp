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

    //* 3   Server Address Setting
    //* 3-1 Server Address Setting
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;                //*   Use IPv4
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //*   Local IP
    servAddr.sin_port = htons(23000);             //*   PORT Setting
    if (bind(hSocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        printf("Binding ERROR \n");
    if (listen(hSocket, 5) == SOCKET_ERROR)
        printf("listen Error \n");

    //* 3-2 Wait Client Connect
    SOCKADDR_IN clientAddr;
    SOCKET clientSocket;

    int sizeClientAddr = sizeof(clientAddr);
    clientSocket = accept(hSocket, (SOCKADDR *)&clientAddr, &sizeClientAddr);
    if (clientSocket == SOCKET_ERROR)
        printf("Failed accept \n");

    //* 4   Send to Client
    char sendData[255] = "hello";
    send(clientSocket, sendData, strlen(sendData) + 1, 0);

    //* 5   Socket Close -> WinSock Close
    closesocket(clientSocket);
    closesocket(hSocket);
    WSACleanup();

    return 0;
}