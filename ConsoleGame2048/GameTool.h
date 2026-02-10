
class GameTool
{
private:
	int game[4][4];
	int gamecheck[4][4];
	int gamecopy[4][4];
	int score;
	int scorecopy;
public :
	//构造函数
	explicit GameTool();
	//操作行为
	// 上
	void up();
	// 下
	void down();
	// 左
	void left();
	// 右
	void right();

	//状态检测
	// 检查有无空格
	bool checkempty();
	// 检查能否行动
	bool checkmove();
	// 检查相邻元素
	bool checknear();
	// 检查有无变化
	bool checkchees();
	// 检查结果输出
	void check();

	//辅助工具
	//合并
	void add(int& , int& );
	//移动
	void move(int& , int& );
	//相邻
	bool near(int, int);
	//新棋盘生成
	void newboard();
	//备份
	void copy();
	void copycheck();
	//撤回到上一步
	void last();
	//随机增加棋子
	void addchess();
	//棋盘展示
	void showboard();
};