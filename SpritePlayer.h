#pragma once
class SpritePlayer
{
public:
	struct PlayerState
	{
		bool isLive;
		int x;
		int y;
		int speed;
	};
	void paintPlayer();
	void move();
};

