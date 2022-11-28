#pragma once
#include "main.h"
#include <windows.h>

#ifndef UTIL
#define UTIL

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15

class Util {
    COORD pos;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
public:
    void init()
    {
        system("mode con cols = 56 lines = 20 | title MAZE");

    }

    void gotoxy(int x, int y)
    {
        pos.X = x;
        pos.Y = y;
        SetConsoleCursorPosition(consoleHandle, pos);
    }

    void textcolor(int foreground, int background)
    {
        int color = foreground + background * 16;
        SetConsoleTextAttribute(consoleHandle, color);
    }

    void Cursor()
    {
        ConsoleCursor.bVisible = 0;
        ConsoleCursor.dwSize = 1;
        SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
    }

};

#endif // !UTIL





