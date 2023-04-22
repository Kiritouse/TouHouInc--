#pragma once
#include <graphics.h>
#include "FrameManager.h"

struct  EnemyBulletNode
{
	int x, y, x0, y0;
	int r;
	int vx, vy;
	int hit;
	int isExist;

	int type;//哪个敌人的子弹
	int level;//子弹的强度是什么

	int FireSwitch;//敌机开火键位
	int fire_on;//如果总帧数与一个中间变量的插值为fire_on就切换开火状态，即每隔fire_on帧就开一次火
	int fire_temp;
	EnemyBulletNode* pnext;
};
void update_EnemyBullet(EnemyBulletNode** pp_Enemy_Bullet_List_Head, int framebuffer);

