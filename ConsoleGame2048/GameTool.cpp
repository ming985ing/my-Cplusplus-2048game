#include <iostream>
#include "GameTool.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

//构造函数
GameTool::GameTool()
{
	newboard();
}
//操作行为
// 上
void GameTool::GameTool::up()
{
	copycheck();
	for (int i = 0; i < 4; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int j = 0; j < 3; j++) 
			{
				move(game[j][i], game[j + 1][i]);
			}
		}
		for (int j = 0; j < 3; j++)
		{
			add(game[j][i], game[j + 1][i]);
		}
		for (int a = 0; a < 3; a++)
		{
			for (int j = 0; j < 3; j++)
			{
				move(game[j][i], game[j + 1][i]);
			}
		}
	}
	check();
	return;
}
// 下
void GameTool::down()
{
	copycheck();
	for (int i = 0; i < 4; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int j = 3; j > 0; j--)
			{
				move(game[j][i], game[j - 1][i]);
			}
		}
		for (int j = 3; j > 0; j--)
		{
			add(game[j][i], game[j - 1][i]);
		}
		for (int a = 0; a < 3; a++)
		{
			for (int j = 3; j > 0; j--)
			{
				move(game[j][i], game[j - 1][i]);
			}
		}
	}
	check();
	return;
}
// 左
void GameTool::left()
{
	copycheck();
	for (int i = 0; i < 4; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int j = 0; j < 3; j++)
			{
				move(game[i][j], game[i][j + 1]);
			}
		}
		for (int j = 0; j < 3; j++)
		{
			add(game[i][j], game[i][j+1]);
		}
		for (int a = 0; a < 3; a++)
		{
			for (int j = 0; j < 3; j++)
			{
				move(game[i][j], game[i][j + 1]);
			}
		}
	}
	check();
	return;
}
// 右
void GameTool::right()
{
	copycheck();
	for (int i = 0; i < 4; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			for (int j = 3; j > 0; j--)
			{
				move(game[i][j], game[i][j - 1]);
			}
		}
		for (int j = 3; j > 0; j--)
		{
			add(game[i][j], game[i][j - 1]);
		}
		for (int a = 0; a < 3; a++)
		{
			for (int j = 3; j > 0; j--)
			{
				move(game[i][j], game[i][j - 1]);
			}
		}
	}
	check();
	return;
}

//状态检测
// 检查有无空格
bool GameTool::checkempty()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (game[i][j] == 0)
				return true;
		}
	}
	return false;
}
// 检查能否行动
bool GameTool::checkmove()
{
	if (checkempty())
		return true;
	else if(checknear())
	{
		return true;
	}
	else
	{
		return false;
	}
}
// 检查相邻元素
bool GameTool::checknear()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (near(game[i][j], game[i][j + 1]) || near(game[j][i], game[j + 1][i]))
				return true;
		}
	}
	return false;
}
// 检查有无变化
bool GameTool::checkchees()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (gamecheck[i][j] != game[i][j])
				return true;
		}
	}
	return false;
}
// 检查结果输出
void GameTool::check()
{
	if (checkchees())
	{
		addchess();
		copy();
		if (checkmove())
		{
			return ;
		}
		else
		{
			return ;
		}
	}
	else
	{
		return;
	}
}

//辅助工具
//合并
void GameTool::add(int& a, int& b)
{
	if (a == b)
	{
		a = a + b;
		b = 0;
		score += a;
	}
	return;
}
//移动
void GameTool::move(int& a, int& b)
{
	if (a == 0)
	{
		a = b;
		b = 0;
	}
	return;
}
//相邻
bool GameTool::near(int a, int b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//新棋盘生成
void GameTool::newboard()
{
	score = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			game[i][j] = 0;
		}
	}
	addchess();
	addchess();
	copy();
	copycheck();
}
//备份
void GameTool::copy()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gamecopy[i][j] = gamecheck[i][j];
		}
	}
	scorecopy = score;
}
void GameTool::copycheck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gamecheck[i][j] = game[i][j];
		}
	}
	scorecopy = score;
}
//撤回到上一步
void GameTool::last()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			game[i][j] = gamecopy[i][j];
		}
	}
	score = scorecopy;
}
//随机增加棋子
void GameTool::addchess()
{
	srand((unsigned int)time(nullptr));
	int a;
	int b;
	do {
		a = rand() % 4;
		b = rand() % 4;
	} while (game[a][b] != 0);
	if (rand() % 10 < 9)
	{
		game[a][b] = 2;
	}
	else
	{
		game[a][b] = 4;
	}
	return;
}
//棋盘展示
void GameTool::showboard()
{
	std::cout << "\n          Score: " << score << "\n";
	std::cout << "   -----------------------------\n";

	for (int i = 0; i < 4; ++i) {
		std::cout << "   |";
		for (int j = 0; j < 4; ++j) {
			if (game[i][j] == 0) 
			{
				std::cout << "      ";
			}
			else 
			{
				std::cout << std::setw(6) << game[i][j];
			}
			std::cout << "|";
		}
		std::cout << "\n";
		if (i < 3) {
			std::cout << "   |------|------|------|------|\n";
		}
	}
	std::cout << "   -----------------------------\n\n";
}
