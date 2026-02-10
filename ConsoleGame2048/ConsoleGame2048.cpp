#include "GameTool.h"
#include <iostream>
#include <conio.h>  
#include <windows.h>
#include <cctype>

char getarrow()
{
    int ch = _getch();
    if (ch == 0 || ch == 224) {  // 特殊键
        ch = _getch();
        switch (ch) {
        case 72: return 'W';  // 上
        case 80: return 'S';  // 下
        case 75: return 'A';  // 左
        case 77: return 'D';  // 右
        }
    }
    return ch;
}

void clearScreen() 
{
    system("cls");
}

void printmeum() {
    std::cout << "=================================\n";
    std::cout << "         ming's 2048 game\n";
    std::cout << "=================================\n";
    std::cout << "controls:\n";
    std::cout << "  W / ↑  - Move Up向上\n";
    std::cout << "  S / ↓  - Move Down向下\n";
    std::cout << "  A / ←  - Move Left向左\n";
    std::cout << "  D / →  - Move Right向右\n";
    std::cout << "  Q      - Quit退出游戏\n";
    std::cout << "  G      - Go back one step返回上一步\n";
    std::cout << "  R      - Restart重新开始\n";
    std::cout << "=================================\n";
}

int main()
{
    GameTool game;
    
    bool start = true;

    while (start)
    {
        if (game.checkmove())
        {
            clearScreen();
            printmeum();
            game.showboard();
            char input = getarrow();
            switch (toupper(input))
            {
            case 'W':
                game.up();
                break;
            case 'A':
                game.left();
                break;
            case 'S':
                game.down();
                break;
            case 'D':
                game.right();
                break;
            case 'R':
                game.newboard();
                break;
            case 'G':
                game.last();
                break;
            case 'Q':
                start = false;
                break;
            default:
                break;
            }
        }
        else
        {
            clearScreen();
            printmeum();
            game.showboard();
            std::cout << "你已无法移动\n";
            char input = getarrow();
            switch (toupper(input))
            {
            case 'R':
                game.newboard();
                break;
            case 'G':
                game.last();
                break;
            case 'Q':
                start = false;
                break;
            default:
                break;
            }
        }
        
    }
    std::cout << "\nThanks for playing!\n";
    return 0;
}


