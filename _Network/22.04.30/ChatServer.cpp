//* 202131230 정윤혁 2022.04.30

#pragma comment(lib, "ws2_32") //* 소켓을 사용하기 위해서 라이브러리 참조해야 한다.
#pragma warning(disable : 4996) //* inet_ntoa가 deprecated가 되었는데, 사용하려면 아래 설정을 해야 한다.

#include <WinSock2.h> //* 소켓을 사용하기 위한 라이브러리
#include <iostream>
#include <stdio.h>
#include <thread>
#include <vector>

//* 수신 버퍼 사이즈
#define BUFFERSIZE 1024

using namespace std;

//* 수신 했을 때, 콘솔 출력 및 echo 데이터 만드는 함수
char *print(vector<char> *str)
{
    int p = 0;                              //* 포인트 위치
    char out[BUFFERSIZE + 1];               //* 버퍼 설정. +1은 \0를 넣기 위한 크기
    char *ret = new char[str->size() + 10]; //* return을 하기 위해서는 힙에 데이터를 선언 해야 한다.

    memcpy(ret, "echo - ", 7); //* 메모리 복사 "echo - "를 붙힌다.

    cout << "From Client message : ";

    //* buffer사이지를 넘어서는 데이터일 경우 반복을 통해서 받는다.
    for (int n = 0; n < (str->size() / BUFFERSIZE) + 1; n++)
    {
        int size = str->size(); //* 버퍼 사이즈 설정

        //* 수신 데이터가 버퍼 사이즈를 넘었을 경우.
        if (size > BUFFERSIZE)
        {
            if (str->size() < (n + 1) * BUFFERSIZE)
                size = str->size() % BUFFERSIZE;
            else
                size = BUFFERSIZE;
        }

        //* echo 메시지와 콘솔 메시지를 작성한다.
        for (int i = 0; i < size; i++, p++)
        {
            out[i] = *(str->begin() + p);
            if (out[i] == '\0')
                out[i] = ' ';
            *(ret + p + 7) = out[i];
        }
        out[size] = '\0';

        cout << out;
    }
    cout << endl;

    memcpy(ret + p + 7, "\n>\0", 3); //* 에코 메시지는 끝에 개행 + ">"를 넣는다.
    return ret;
}

//* 접속되는 client별 쓰레드
void client(SOCKET clientSock, SOCKADDR_IN clientAddr, vector<thread *> *clientlist)
{
    //* 접속 정보를 콘솔에 출력한다.
    cout << "Client connected IP address = " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port)
         << endl;

    //* client로 메시지를 보낸다.
    const char *message = "Welcome server!\r\n>\0";
    send(clientSock, message, strlen(message) + 1, 0);

    vector<char> buffer; //* telent은 한글자씩 데이터가 오기 때문에 글자를 모을 buffer가 필요하다.

    char x; //* 수신 데이터

    while (1)
    {
        //* 데이터를 받는다. 에러가 발생하면 멈춘다.
        if (recv(clientSock, &x, sizeof(char), 0) == SOCKET_ERROR)
        {
            cout << "error" << endl; //* 에러 콘솔 출력
            break;
        }

        //* 만약 buffer의 끝자리가 개행일 경우
        if (buffer.size() > 0 && *(buffer.end() - 1) == '\r' && x == '\n')
        {
            //* 메시지가 exit일 경우는 수신대기를 멈춘다.
            if (*buffer.begin() == 'e' && *(buffer.begin() + 1) == 'x' && *(buffer.begin() + 2) == 'i' &&
                *(buffer.begin() + 3) == 't')
            {
                break;
            }
            const char *echo = print(&buffer);             //* 콘솔에 출력하고 에코 메시지를 받는다.
            send(clientSock, echo, buffer.size() + 10, 0); //* client로 에코 메시지 보낸다.
            delete echo; //* 에코 메시지를 힙(new을 사용한 선언)에 선언했기 때문에 메모리 해지한다.
            buffer.clear(); //* 버퍼를 비운다.
            continue;       //* 다음 메시지 수신 대기
        }
        buffer.push_back(x); //* 버퍼에 글자를 하나 넣는다.
    }

    closesocket(clientSock); //* 수신 대기가 끝나면 client와 소켓 통신을 끊는다.

    //* 접속 정보를 콘솔에 출력한다.
    cout << "Client disconnected IP address = " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port)
         << endl;

    //* threadlist에서 현재 쓰레드를 제거한다.
    for (auto ptr = clientlist->begin(); ptr < clientlist->end(); ptr++)
    {
        //* thread 아이디가 같은 것을 찾아서
        if ((*ptr)->get_id() == this_thread::get_id())
        {
            clientlist->erase(ptr); //* 리스트에서 뺀다.
            break;
        }
    }
    //* thread 메모리 해지는 thread가 종료 됨으로 자동으로 처리된다.
}

//* 실행 함수
int main()
{
    vector<thread *> clientlist; //* 클라이언트 접속 중인 client list
    WSADATA wsaData;             //* 소켓 정보 데이터 설정

    //* 소켓 실행.
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        return 1;
    }

    SOCKET serverSock = socket(PF_INET, SOCK_STREAM, 0); //* Internet의 Stream 방식으로 소켓 생성
    SOCKADDR_IN addr;                                    //* 소켓 주소 설정

    memset(&addr, 0, sizeof(addr)); //* 구조체 초기화

    addr.sin_family = AF_INET;                //* 소켓은 Internet 타입
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //* 서버이기 때문에 local 설정한다.
                                              //* Any인 경우는 호스트를 127.0.0.1로 잡아도 되고 localhost로 잡아도 되고
                                              //* 양쪽 다 허용하게 할 수 있다. 그것이 INADDR_ANY이다.
    addr.sin_port = htons(9090); //* 서버 포트 설정...저는 9090으로 설정함.

    //* 설정된 소켓 정보를 소켓에 바인딩한다.
    if (bind(serverSock, (SOCKADDR *)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        cout << "error" << endl; //* 에러 콘솔 출력
        return 1;
    }

    //* 소켓을 대기 상태로 기다린다.
    if (listen(serverSock, SOMAXCONN) == SOCKET_ERROR)
    {
        cout << "error" << endl; //* 에러 콘솔 출력
        return 1;
    }

    //* 서버를 시작한다.
    cout << "Server Start" << endl;

    //* 다중 접속을 위해 while로 소켓을 대기한다.
    while (1)
    {
        int len = sizeof(SOCKADDR_IN); //* 접속 설정 구조체 사이즈

        SOCKADDR_IN clientAddr;                                                //* 접속 설정 구조체
        SOCKET clientSock = accept(serverSock, (SOCKADDR *)&clientAddr, &len); //* client가 접속을 하면 SOCKET을 받는다.

        //* 쓰레드를 실행하고 쓰레드 리스트에 넣는다.
        clientlist.push_back(new thread(client, clientSock, clientAddr, &clientlist));
    }

    //* 종료가 되면 쓰레드 리스트에 남아 있는 쓰레드를 종료할 때까지 기다린다.
    for (auto ptr = clientlist.begin(); ptr < clientlist.end(); ptr++)
    {
        (*ptr)->join();
    }

    closesocket(serverSock); //* 서버 소켓 종료

    WSACleanup(); //* 소켓 종료

    return 0;
}