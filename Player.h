#pragma once
#include <time.h>
#include "GameManager.h"
#include "Flyers.h"
#include "Map.h"
class Player :public Flyers {
public:
	Player();//���캯������ʼ������
	int health;
	int speed;
	void updatePosition();
	void updateImage();
	//void updatePosition();
	//void hit();//������״̬
	struct Direction
	{
		int up;
		int down;
		int left;
		int right;
	};


};

