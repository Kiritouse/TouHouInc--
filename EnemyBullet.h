#pragma once
#include <graphics.h>
#include "FrameManager.h"
#include "Enemy.h"

struct  EnemyBulletNode
{
	int x, y, x0, y0;
	int r;
	int vx, vy;
	int hit;
	int isExist;

	int type;//哪个敌人的子弹
	int level;//子弹的强度是什么
	EnemyBulletNode* pnext;
};
void update_EnemyBullet(EnemyNode** pp_Enemy_List_Node_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, int framebuffer, int level, int vx, int vy);

