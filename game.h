#pragma once
#include "main.h"
#include "util.h"
#include <conio.h>

#ifndef GAME
#define GAME

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define ENTER 4
#define BACK 5
#define Re 6


class Game {
private:
    char copymaze[14][56] =
    {
        {"1111111111111111111111111111111111111111111111111111111"},
        {"100l000000000000000000000000000000000000000000000000001"},
        {"1001111111111111000000000000000000000000000000000000001"},
        {"1001111111111111000000000000001111111111111110000000001"},
        {"1001100000000011000000000000001111111111111110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1k01100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"10s11000000000111111111111111111000000000001100000q0011"},
        {"1001100000000011111111111111111100000000000111111111111"},
        {"1111111111111111111111111111111111111111111111111111111"}
    };


    char easymaze[14][56] =
    {
        {"1111111111111111111111111111111111111111111111111111111"},
        {"100l000000000000000000000000000000000000000000000000001"},
        {"1001111111111111000000000000000000000000000000000000001"},
        {"1001111111111111000000000000001111111111111110000000001"},
        {"1001100000000011000000000000001111111111111110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"1k01100000000011000000000000001100000000000110000000001"},
        {"1001100000000011000000000000001100000000000110000000001"},
        {"10s11000000000111111111111111111000000000001100000q0001"},
        {"1001100000000011111111111111111100000000000111111111111"},
        {"1111111111111111111111111111111111111111111111111111111"}
    };

    char hardmaze[14][56] = { // ������  
        // ���� ���ڴ� �� �迭ũ�⿡ ���߾� 56��  
        {"1111111111111111111111111111111111111111111111111111111"}, // ���� ���̿� ���߾� 14��   
        {"100000100010001k000100000000001000100000100010100010001"},
        {"1000001010101011110101111101101010101110101010101000101"},
        {"1000101010001000k10101000101k01010101k10101000111111101"},
        {"1000100010111111110101010101111000100010101111100000001"},
        {"100011111l100000000101010100000001110110101000101011111"},
        {"1000100000101111111101010111011100000010001010001010001"},
        {"1000101111101000000001010000000111011010100010100010001"},
        {"10001010000010000001010110111100000000101010101010001l1"},
        {"10001010111010000001000000000101011110101010101011111l1"},
        {"100010101k001000000111101111000100001010101010001000001"},
        {"10s010101111111110110010100001011110100010111110100q001"},
        {"1000100000l000l0001000100011110000001010100000001000001"},
        {"1111111111111111111111111111111111111111111111111111111"}
    };

    Util util;

public:
    void titleDraw()
    {
        util.textcolor(12, 0);
        printf("\n\n\n\n");
        util.gotoxy(31, 3);
        printf("              *   *        *    *****  ****");
        util.gotoxy(31, 4);
        printf("            *  * *  *    * * *     *   *");
        util.gotoxy(31, 5);
        printf("           *   * *   *   *****    *    ****");
        util.gotoxy(31, 6);
        printf("          *    * *    *  *   *   *     *");
        util.gotoxy(31, 7);
        printf("          *     *     *  *   *  *****  ****");
        util.gotoxy(48, 9);
        printf("A�� S�� �����̼���!");
    }

    int menuDraw()
    {
        util.textcolor(15, 0);
        int x = 53;
        int y = 12;
        util.gotoxy(x - 2, y);
        printf("> ���� ���� ");
        util.gotoxy(x, y + 1);
        printf("���� ���� ");
        util.gotoxy(x, y + 2);
        printf("  ����  ");

        while (1)
        {
            int n = keyControl();
            switch (n)
            {
            case UP:
            {
                if (y > 12)
                {
                    util.gotoxy(x - 2, y);
                    printf(" ");
                    util.gotoxy(x - 2, --y);
                    printf(">");
                }
                break;
            }
            case DOWN: {
                if (y < 14)
                {
                    util.gotoxy(x - 2, y);
                    printf(" ");
                    util.gotoxy(x - 2, ++y);
                    printf(">");
                }
                break;
            }
            case ENTER: return y - 12;

            }
        }
    } // ���� ����, ����, ����

    int keyControl()
    {
        char temp = _getch();

        if (temp == 'w' || temp == 'W')
        {

            return UP;
        }
        else if (temp == 'a' || temp == 'A')
        {

            return LEFT;
        }
        else if (temp == 's' || temp == 'S')
        {
            return DOWN;
        }
        else if (temp == 'd' || temp == 'D')
        {
            return RIGHT;
        }
        else if (temp == 13)
        {
            return ENTER;
        }
        else if (temp == 8)
        {
            return BACK;
        }
        else if (temp == 'r' || temp == 'R')
        {
            return Re;
        }

    } // Ű���� Ű

    void infomenu()
    {
        system("cls");
        util.gotoxy(35, 0);
        printf("                 [ ���۹� ]\n\n");
        util.gotoxy(39, 5);
        printf("           �̵� : W A S D ");
        util.gotoxy(39, 6);
        printf("           ���� : Enter key");
        util.gotoxy(39, 7);
        printf("           ��� : Backspacebar");
        util.gotoxy(39, 8);
        printf("         ������ : ������");
        util.gotoxy(39, 11);
        printf("         ------Warning------");
        util.gotoxy(31, 13);
        printf("�� ������ ���� ������ �ƴմϴ�. �ε� ���������ñ� �ٶ��ϴ�.");
        util.gotoxy(0, 20);
        printf("----------------------------------- Backspace�ٸ� ������ ����ȭ������ �̵��մϴ� ---------------------------------------");

        while (1)
        {
            if (keyControl() == BACK)
            {
                break;
            }
        }
    } // ���� ȭ��

    void endmenu()
    {
        system("cls");
        util.gotoxy(45, 0);
        printf("������ �����Ͻðڽ��ϱ�??");
        util.gotoxy(39, 8);
        printf("yes                               no");
        util.gotoxy(0, 15);
        printf("------------------�����Ͻð� ������ EnterŰ�� �����ֽð�, �ٽ� ���ư��� �ʹٸ� Backspace�ٸ� �����ּ���-----------------");
        while (1)
        {
            if (keyControl() == ENTER)
            {
                system("cls");
                exit(0);
            }
            else if (keyControl() == BACK)
            {
                break;
            }
        }
    }

    void drawMaze(int* x, int* y)
    {

        system("cls");
        int h, w;

        for (h = 0; h < 14; h++)
        {
            for (w = 0; w < 56; w++)
            {
                char temp = copymaze[h][w];
                if (temp == '0')
                {
                    util.textcolor(0, 0);
                    printf(" ");
                }
                else if (temp == '1')
                {
                    util.textcolor(15, 15);
                    printf("#");
                }
                else if (temp == 's')
                {
                    *x = w;
                    *y = h;
                    util.textcolor(9, 0);
                    printf("@");
                }
                else if (temp == 'q')
                {
                    util.textcolor(12, 0);
                    printf("O");
                }
                else if (temp == 'k')
                {
                    util.textcolor(14, 0);
                    printf("*");
                }
                else if (temp == 'l')
                {
                    util.textcolor(6, 0);
                    printf("+");
                }
            }
            printf("\n");
        }
        util.textcolor(15, 0);
        //Sleep(3000);
    }

    int maplistDraw()
    {
        system("cls");
        util.gotoxy(48, 0);
        printf("  [ ���̵� ���� ]  ");
        int x = 53;
        int y = 5;
        util.gotoxy(x - 1, y);
        printf(">  ���� ");
        util.gotoxy(x, y + 1);
        printf(" ����� ");
        util.gotoxy(x, y + 2);
        printf("  �ڷ�  ");
        while (1)
        {
            int n = keyControl();
            switch (n)
            {
            case UP:
            {
                if (y > 5)
                {
                    util.gotoxy(x - 1, y);
                    printf(" ");
                    util.gotoxy(x - 1, --y);
                    printf(">");
                }
                break;
            }
            case DOWN: {
                if (y < 7)
                {
                    util.gotoxy(x - 1, y);
                    printf(" ");
                    util.gotoxy(x - 1, ++y);
                    printf(">");
                }
                break;
            }
            case ENTER:
                system("cls");
                return y - 5;

            }
        }

    }

    int back()
    {
        if (keyControl() == ENTER)
        {
            return 0;
        }
    }

    int gLoop(int mapCode)
    {
        int playing = 1;
        int key = 0;
        int x = 0, y = 0;

        if (mapCode == 0)
        {
            memcpy(copymaze, easymaze, sizeof(copymaze));
        }
        if (mapCode == 1)
        {
            memcpy(copymaze, hardmaze, sizeof(copymaze));
        }


        drawMaze(&x, &y);

        while (playing)
        {

            drawUi(&x, &y, &key);
            switch (keyControl())
            {
            case UP:
                move(&x, &y, 0, -1, &key, &playing);
                break;
            case DOWN:
                move(&x, &y, 0, 1, &key, &playing);
                break;
            case RIGHT:
                move(&x, &y, 1, 0, &key, &playing);
                break;
            case LEFT:
                move(&x, &y, -1, 0, &key, &playing);
                break;
            case ENTER:
                util.gotoxy(18, 7);
                util.textcolor(4, 0);
                printf("Game Over!");
                Sleep(1500);
                util.textcolor(15, 0);
                return 0;

            case Re:
                if (keyControl() == Re && mapCode == 0)
                {
                    retry(0);
                }
                else if (keyControl() == Re && mapCode == 1)
                {
                    retry(1);
                }
            }

        }
        util.gotoxy(18, 7);
        printf("Game Clear!");
        Sleep(1500);
        return 0;
    }

    void move(int* x, int* y, int _x, int _y, int* key, int* playing)
    {
        char mapobject = copymaze[*y + _y][*x + _x];
        util.textcolor(15, 0);

        if (mapobject == '0')
        {
            util.gotoxy(*x, *y);
            printf(" ");

            util.textcolor(9, 0);
            util.gotoxy(*x + _x, *y + _y);
            printf("@");

            *x += _x;
            *y += _y;
        }
        else if (mapobject == 'k')
        {
            *key += 1;
            copymaze[*y + _y][*x + _x] = '0';
            util.gotoxy(*x + _x, *y + _y);
            printf(" ");
        }
        else if (mapobject == 'l')
        {
            if (*key > 0)
            {
                *key -= 1;
                copymaze[*y + _y][*x + _x] = '0';
                util.textcolor(15, 0);
                util.gotoxy(*x + _x, *y + _y);
                printf(" ");
            }

        }
        else if (mapobject == 'q')
        {
            *playing = 0;
        }



    }

    void drawUi(int* x, int* y, int* key)
    {
        util.textcolor(15, 0);
        util.gotoxy(0, 19);
        printf(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
        util.gotoxy(0, 20);
        printf("��                                                              ��");
        util.gotoxy(0, 21);
        printf("��                                                              ��");
        util.gotoxy(0, 22);
        printf("��                                                              ��");
        util.gotoxy(0, 23);
        printf("��                                                              ��");
        util.gotoxy(0, 24);
        printf("��                                                              ��");
        util.gotoxy(0, 25);
        printf(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
        util.gotoxy(5, 20);
        printf("���� ȭ������ ���ư��� �ʹٸ� ENTERŰ�� �����ּ���.");
        util.gotoxy(5, 22);
        printf("������ �ٽ� �ϰ� �ʹٸ� RŰ�� �����ּ���!");
        util.textcolor(14, 0);
        util.gotoxy(10, 24);
        printf("���� : %d��", *key);

    }

    void gameinfo()
    {
        square();
        util.gotoxy(45, 9);
        printf("@ == player(You)");
        util.gotoxy(45, 10);
        printf("O == maze�� �ⱸ");
        util.gotoxy(45, 11);
        printf("* == �����ִ� ��(���踦 �Ծ �����ּ���.)");
        util.gotoxy(45, 12);
        printf("+ == �����ִ� ���� �� �� �ִ� ����");
        Sleep(5000);
        system("cls");
    }

    void square()
    {
        util.gotoxy(35, 7);
        printf(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");
        util.gotoxy(35, 8);
        printf("��                                                      ��");
        util.gotoxy(35, 9);
        printf("��                                                      ��");
        util.gotoxy(35, 10);
        printf("��                                                      ��");
        util.gotoxy(35, 11);
        printf("��                                                      ��");
        util.gotoxy(35, 12);
        printf("��                                                      ��");
        util.gotoxy(35, 13);
        printf("��                                                      ��");
        util.gotoxy(35, 14);
        printf(" �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�");


    }

    void retry(int mapCode)
    {
        while (1)
        {
            if (keyControl() == Re && mapCode == 0)
            {

                util.textcolor(12, 0);
                util.gotoxy(18, 7);
                printf("Retry!");
                Sleep(2000);
                printf(" ");
                gLoop(0);
            }
            else if (keyControl() == Re && mapCode == 1)
            {

                util.textcolor(12, 0);
                util.gotoxy(18, 7);
                printf("Retry!");
                Sleep(2000);
                printf(" ");
                gLoop(1);
            }
        }
    }
};

#endif // !GAME

