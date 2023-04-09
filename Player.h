#pragma once
#define WIDTH_PLAYER  28
#define HEIGHT_PLAYER  50
#define WIDTH_PLAYER_RIGHT 28
#define HEIGHT_PLAYER_RIGHT 47
#define WIDTH_PLAYER_LEFT 28
#define HEIGHT_PLAYER_LEFT 47
class Player {
public:
	Player();//构造函数，初始化数据
	int health;
	int speed;
	void updatePosition(int _cmd);
	void updateImage();
	struct Position
	{
		int x, y;
	};
	enum ObjectState
	{
		Live,
		Dead,
		Invulnerable
	};
	struct Direction
	{
		int up;
		int down;
		int left;
		int right;
	};
};
extern Player::Position position;



