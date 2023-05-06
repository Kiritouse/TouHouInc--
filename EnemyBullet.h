#pragma once
#include <graphics.h>
#include "FrameManager.h"
#include "Enemy.h"
#include "Player.h"
class EnemyBullet {
public:
	struct  EnemyBulletNode
	{
		float x, y;
		float vx, vy;

		int level;
		int hitpoint;

		int isExist;
		EnemyBulletNode* pnext;


	};
	EnemyBulletNode* p_Enemy_Bullet_List_Node;
	void update_EnemyBullet(Player player, Enemy::EnemyNode** pp_Enemy_List_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Head, float vx, float vy, int level, int hitpoint, int framebuffer);
	void update_EnemyBulletImage(EnemyBulletNode** pp_Enemy_Bullet_List_Head);
};


