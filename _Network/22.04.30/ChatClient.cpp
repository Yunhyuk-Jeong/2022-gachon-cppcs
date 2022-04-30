//* 202131230 정윤혁 2022.04.30

#pragma comment(lib, "ws2_32") //* 소켓을 사용하기 위해서 라이브러리 참조해야 한다.
#pragma warning(disable : 4996) //* inet_ntoa가 deprecated가 되었는데.. 사용하려면 아래 설정을 해야 한다.

#include <WinSock2.h> //* 소켓을 사용하기 위한 라이브러리
#include <iostream>
#include <stdio.h>
#include <thread>
#include <vector>

#define BUFFERSIZE 1024 //* 수신 버퍼 사이즈

using namespace std;

//* 콘솔에 메시지를 출력하는 함수
void print(vector<char> *str)
{
    int p = 0;                //* 포인트 위치
    char out[BUFFERSIZE + 1]; //* 버퍼 설정. +1은 \0를 넣기 위한 크기

    cout << "From server message : "; //* 콘솔 출력

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
            out[i] = *(str->begin() + p);

        cout << out; //* 콘솔 메시지 콘솔 출력.
    }
}

//* 실행 함수
int main()
{
    WSADATA wsaData; //* 소켓 정보 데이터 설정

    //* 소켓 실행.
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        return 1;

    SOCKET sock = socket(PF_INET, SOCK_STREAM, 0); //* Internet의 Stream 방식으로 소켓 생성
    SOCKADDR_IN addr;                              //* 소켓 주소 설정

    memset(&addr, 0, sizeof(addr)); //* 구조체 초기화

    addr.sin_family = AF_INET;                     //* 소켓은 Internet 타입
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //* 127.0.0.1(localhost)로 접속하기
    addr.sin_port = htons(9090);                   //* 포트 9090으로 접속

    //* 접속
    if (connect(sock, (SOCKADDR *)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        cout << "error" << endl; //* 에러 콘솔 출력
        return 1;
    }

    vector<char> buffer; //* telent은 한글자씩 데이터가 오기 때문에 글자를 모을 buffer가 필요하다.

    char x; //* 수신 데이터

    while (1)
    {
        //* 데이터를 받는다. 에러가 발생하면 멈춘다.
        if (recv(sock, &x, sizeof(char), 0) == SOCKET_ERROR)
        {
            cout << "error" << endl; //* 에러 콘솔 출력
            break;
        }

        buffer.push_back(x); //* 버퍼에 글자를 하나 넣는다.

        //* \r\n>\0가 나오면 콘솔에 출력하고 콘솔로 부터 메시지를 기다린다.
        if (buffer.size() > 4 && *(buffer.end() - 4) == '\r' && *(buffer.end() - 3) == '\n' &&
            *(buffer.end() - 2) == '>' && *(buffer.end() - 1) == '\0')
        {
            print(&buffer);           //* 메시지 출력
            buffer.clear();           //* 버퍼 초기화
            char input[BUFFERSIZE];   //* 콘솔로 부터 입력을 받는다.
            cin >> input;             //* 유저로 부터 입력 받기
            int size = strlen(input); //* 입력받은 길이를 받는다.

            //* 개행을 넣는다.
            *(input + size + 1) = '\r';
            *(input + size + 2) = '\n';

            send(sock, input, size + 3, 0); //* 서버로 보내기

            //* 메시지가 exit라면 종료
            if (*input == 'e' && *(input + 1) == 'x' && *(input + 2) == 'i' && *(input + 3) == 't')
                break;
            continue;
        }
    }

    closesocket(sock); //* 서버 소켓 종료

    WSACleanup(); //* 소켓 종료

    return 0;
}