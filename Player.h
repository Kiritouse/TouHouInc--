#pragma once
#include <time.h>
#include "GameManager.h"
#include "Flyers.h"
class Player :public Flyers {
public:
	Player();//���캯������ʼ������
	int health;
	int speed;
	void updatePosition();
	void updateImage();
	//void updatePosition();
	//void hit();//������״̬
	enum Direction {
		left,
		up,
		right,
		down,
		idle
	};


};

