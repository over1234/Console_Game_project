#include "main.h"

int main()
{
    Game game;
    Util util;


    util.init();
    util.Cursor();
    while (1)
    {
        game.titleDraw();

        int menuCode = game.menuDraw();
        if (menuCode == 0)
        {

            int n = game.maplistDraw();

            if (n == 0)
            {
                util.gotoxy(50, 5);
                printf("쉬움 난이도 선택함");
                Sleep(500);
                game.gameinfo();
                game.gLoop(0);

            }
            else if (n == 1)
            {
                util.gotoxy(50, 5);
                printf("어려움 난이도 선택함");
                Sleep(1000);
                game.gameinfo();
                game.gLoop(1);

            }
            else if (n == 2)
            {
                game.back();

            }
        }
        else if (menuCode == 1)
        {

            game.infomenu();
        }
        else if (menuCode == 2)
        {
            game.endmenu();

        }
        system("cls");


    }
    return 0;
}
