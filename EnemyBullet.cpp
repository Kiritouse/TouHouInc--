#include <stdlib.h>
#include "EnemyBullet.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#define DEF_TYPE_ENEMY0 0//ʶ����˵ı�ʶ��
#define DEF_TYPE_ENEMY1 1
#define WIDTH_ENEMYBULLET0 22
#define HEIGHT_ENEMYBULLET0 21
EnemyBullet::EnemyBulletNode* createEnemyBulletNode(Enemy::EnemyNode** pp_curEnemy, float vx, float vy, int level, int hitpoint) {
	EnemyBullet::EnemyBulletNode* newEnemyBulletNode = new EnemyBullet::EnemyBulletNode;
	newEnemyBulletNode->x = (*pp_curEnemy)->x + WIDTH_ENEMY0 / 2 - 8;
	newEnemyBulletNode->y = (*pp_curEnemy)->y + HEIGHT_ENEMY0 / 2 - 10;
	newEnemyBulletNode->vx = vx;
	newEnemyBulletNode->vy = vy;
	newEnemyBulletNode->level = level;
	newEnemyBulletNode->hitpoint = hitpoint;
	newEnemyBulletNode->isExist = 1;
	newEnemyBulletNode->pnext = NULL;
	return newEnemyBulletNode;
}
void EnemyBulletListPushBack(EnemyBullet::EnemyBulletNode** pp_Enemy_Bullet_List_Head, EnemyBullet::EnemyBulletNode* newNode) {
	if (*pp_Enemy_Bullet_List_Head == NULL) {
		*pp_Enemy_Bullet_List_Head = newNode;
		return;
	}
	EnemyBullet::EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Head;
	while (cur->pnext != NULL) {
		cur = cur->pnext;
	}
	cur->pnext = newNode;
}
void update_EnemyBulletPosition(Player player, Enemy::EnemyNode** pp_Enemy_List_Head, EnemyBullet::EnemyBulletNode** pp_Enemy_Bullet_List_Head, float vx, float vy, int level, int hitpoint, int framebuffer) {
	Enemy::EnemyNode* curEnemy = *pp_Enemy_List_Head;
	while (curEnemy != NULL) {
		if (framebuffer - curEnemy->f_create == curEnemy->fire_on) {
			EnemyBulletListPushBack(pp_Enemy_Bullet_List_Head, createEnemyBulletNode(&curEnemy, vx, vy, level, hitpoint));
			curEnemy->f_create = framebuffer;;
		}
		curEnemy = curEnemy->pnext;
	}
	EnemyBullet::EnemyBulletNode* curEnemyBullet = *pp_Enemy_Bullet_List_Head;
	while (curEnemyBullet != NULL) {
		curEnemyBullet->x += curEnemyBullet->vx;
		curEnemyBullet->y += curEnemyBullet->vy;
		//	�ж��Ƿ�Խ��
		if ((curEnemyBullet->y < -20) || (curEnemyBullet->y > HEIGHT_MAP) || (curEnemyBullet->x > WIDTH_MAP) || (curEnemyBullet->x < -20))
			curEnemyBullet->isExist = 0;
		// �ж��Ƿ��������ײ
		//std::cout << playerCollider.xl << std::endl;
		if (curEnemyBullet->x > Struct_PlayerPosition.x && curEnemyBullet->x < Struct_PlayerPosition.x + WIDTH_PLAYER &&
			curEnemyBullet->y>Struct_PlayerPosition.y && curEnemyBullet->y < Struct_PlayerPosition.y + HEIGHT_PLAYER) {
			player.health -= curEnemyBullet->hitpoint;
		}
		curEnemyBullet = curEnemyBullet->pnext;//ָ����һ���ڵ�
	}

}
void listRemoveNodeEnemyBullet(EnemyBullet::EnemyBulletNode** p_Enemy_Bullet_List_Head)
{
	if (p_Enemy_Bullet_List_Head == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	EnemyBullet::EnemyBulletNode* curP = *p_Enemy_Bullet_List_Head;//curret��ָ���һ���ڵ�
	EnemyBullet::EnemyBulletNode* prevP = NULL;  //previousָ����һ���ڵ��ָ��
	while (curP != NULL)//��������
	{
		if (curP->isExist == 0)
		{
			if (*p_Enemy_Bullet_List_Head == curP)
			{
				*p_Enemy_Bullet_List_Head = curP->pnext;
				free(curP);
				curP = *p_Enemy_Bullet_List_Head;
			}
			else
			{
				prevP->pnext = curP->pnext;
				free(curP);
				curP = prevP;
			}
		}
		else
		{
			prevP = curP;
			curP = curP->pnext;
		}
	}
}
void EnemyBullet::update_EnemyBulletImage(EnemyBullet::EnemyBulletNode** pp_Enemy_Bullet_List_Head) {
	for (EnemyBullet::EnemyBulletNode* curEnemyNode = *pp_Enemy_Bullet_List_Head; curEnemyNode != NULL; curEnemyNode = curEnemyNode->pnext)
	{
		transparentimage_half(NULL, curEnemyNode->x, curEnemyNode->y, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0,
			0, 0, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0, &enemyBullet0, 255);
	}
}
void EnemyBullet::update_EnemyBullet(Player player, Enemy::EnemyNode** pp_Enemy_List_Head, EnemyBullet::EnemyBulletNode** pp_Enemy_Bullet_List_Head, float vx, float vy, int level, int hitpoint, int framebuffer) {
	update_EnemyBulletPosition(player, pp_Enemy_List_Head, pp_Enemy_Bullet_List_Head, vx, vy, level, hitpoint, framebuffer);
	listRemoveNodeEnemyBullet(pp_Enemy_Bullet_List_Head);

}
