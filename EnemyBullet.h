#pragma once
#include <graphics.h>
#include "FrameManager.h"
#include "Enemy.h"
struct  EnemyBulletNode
{
	float x, y;
	float vx, vy;

	int level;
	int hitpoint;

	int isExist;
	EnemyBulletNode* pnext;


};
void update_EnemyBullet(EnemyNode*)


