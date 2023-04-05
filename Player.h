#pragma once
#include <time.h>
#include "GameManager.h"
#include "Flyers.h"
class Player :public Flyers {
public:
	Player();//构造函数，初始化数据
	int health;
	int speed;
	void updatePosition();
	void updateImage();
	//void updatePosition();
	//void hit();//被击中状态
	enum Direction {
		left,
		up,
		right,
		down,
		idle
	};


};

