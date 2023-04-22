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

	int type;//�ĸ����˵��ӵ�
	int level;//�ӵ���ǿ����ʲô

	int FireSwitch;//�л������λ
	int fire_on;//�����֡����һ���м�����Ĳ�ֵΪfire_on���л�����״̬����ÿ��fire_on֡�Ϳ�һ�λ�
	int fire_temp;
	EnemyBulletNode* pnext;
};
void update_EnemyBullet(EnemyBulletNode** pp_Enemy_Bullet_List_Head, int framebuffer);

