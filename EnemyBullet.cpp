#include <stdlib.h>
#include "EnemyBullet.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#define DEF_TYPE_ENEMY0 0//识别敌人的标识符
#define DEF_TYPE_ENEMY1 1
#define WIDTH_ENEMYBULLET0 22
#define HEIGHT_ENEMYBULLET0 21
EnemyBulletNode* createEnemyBulletNode(EnemyNode** pp_Enemy_List_Head, float vx, float vy, int level, int hitpoint) {
	EnemyBulletNode* newEnemyBulletNode = new EnemyBulletNode;
	newEnemyBulletNode->x = (*pp_Enemy_List_Head)->x + WIDTH_ENEMY0 / 2 - 8;
	newEnemyBulletNode->y = (*pp_Enemy_List_Head)->y+HEIGHT_ENEMY0/2-10;
	newEnemyBulletNode->vx = vx;
	newEnemyBulletNode->vy = vy;
	newEnemyBulletNode->level = level;
	newEnemyBulletNode->hitpoint = hitpoint;
	newEnemyBulletNode->isExist = 1;
	newEnemyBulletNode->pnext = NULL;
	return newEnemyBulletNode;
}
void EnemyBulletListPushBack(EnemyBulletNode** pp_Enemy_Bullet_List_Head, EnemyBulletNode* newNode) {
	if (*pp_Enemy_Bullet_List_Head == NULL) {
		*pp_Enemy_Bullet_List_Head = newNode;
		return;
	}
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Head;
	while (cur->pnext != NULL) {
		cur = cur->pnext;
	}
	cur->pnext = newNode;
}
void update_EnemyBulletPosition(EnemyNode** pp_Enemy_List_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Head, float vx, float vy, int level, int hitpoint) {
	if (*pp_Enemy_List_Head == NULL) {
		return;
	}
	EnemyNode* curEnemy = *pp_Enemy_List_Head;
	while (curEnemy != NULL) {
		if (curEnemy->FireSwitch == 1)
			EnemyBulletListPushBack(pp_Enemy_Bullet_List_Head, createEnemyBulletNode(&curEnemy, vx, vy, level, hitpoint));
		else return;

		EnemyBulletNode* curEnemyBullet = *pp_Enemy_Bullet_List_Head;
		while (curEnemyBullet != NULL) {
			curEnemyBullet->x += curEnemyBullet->vx;
			curEnemyBullet->y += curEnemyBullet->vy;
			if ((curEnemyBullet->y < -20) || (curEnemyBullet->y > HEIGHT_MAP) || (curEnemyBullet->x > WIDTH_MAP) || (curEnemyBullet->x < -20))
				curEnemyBullet->isExist = 0;
			curEnemyBullet = curEnemyBullet->pnext;//指向下一个节点
		}
		curEnemy = curEnemy->pnext;
	}

}
void listRemoveNodeEnemyBullet(EnemyBulletNode** p_Enemy_Bullet_List_Head)
{
	if (p_Enemy_Bullet_List_Head == NULL)//如果链表为空，就没有可删除的节点了
		return;
	EnemyBulletNode* curP = *p_Enemy_Bullet_List_Head;//curret先指向第一个节点
	EnemyBulletNode* prevP = NULL;  //previous指向上一个节点的指针
	while (curP != NULL)//遍历链表
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
void update_EnemyBulletImage(EnemyBulletNode** pp_Enemy_Bullet_List_Head) {
	for (EnemyBulletNode* curEnemyNode = *pp_Enemy_Bullet_List_Head; curEnemyNode != NULL; curEnemyNode = curEnemyNode->pnext)
	{
		transparentimage_half(NULL, curEnemyNode->x, curEnemyNode->y, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0,
			0, 0, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0, &enemyBullet0, 150);
	}
}
void update_EnemyBullet(EnemyNode** pp_Enemy_List_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Head, float vx, float vy, int level, int hitpoint) {
	update_EnemyBulletPosition(pp_Enemy_List_Head, pp_Enemy_Bullet_List_Head, vx, vy, level, hitpoint);
	listRemoveNodeEnemyBullet(pp_Enemy_Bullet_List_Head);
	update_EnemyBulletImage(pp_Enemy_Bullet_List_Head);


}
