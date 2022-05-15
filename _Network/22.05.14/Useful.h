#pragma once

#include <conio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <process.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

//*	Useful.c

enum CURSOR_TYPE
{
    NOCURSOR,
    SOLIDCURSOR,
    NORMALCURSOR
};

void RemoveScrollbar();
void SetWindow(int Width, int Height);
void Gotoxy(int x, int y);
void Gotoxy_(int x, int y);
void TextColor(int color_number);
void SetCursorType(CURSOR_TYPE c);
void Click(int *x, int *y);
void Click_(int *x, int *y);
void Click__(int *x, int *y);
int BeInput();
int GetInput(WORD *vkey, COORD *pos);

//* textcolor(0x배경색글자색)
//* 0 = 검정색      8 = 회색
//* 1 = 파랑색      9 = 연한 파랑색
//* 2 = 초록색      A = 연한 초록색
//* 3 = 옥색        B = 연한 옥색
//* 4 = 빨강색      C = 연한 빨강색
//* 5 = 자주색      D = 연한 자주색
//* 6 = 노랑색      E = 연한 노랑색
//* 7 = 흰색        F = 밝은 흰색