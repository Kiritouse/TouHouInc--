#pragma once
class Enemy
{
	struct  Position
	{
		int x, y;
	};
	struct Direction
	{
		int up;
		int down;
		int left;
		int right;
	};
	enum EnemyState {
		Live,
		Dead,
		Invulnerable
	};


};

