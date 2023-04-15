#include "Enemy.h"
#include "Operation.h"
#include <iostream>
#include <math.h>
#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59
#define WDITH_ENEMY1 43
#define HEIGT_ENEMY1 58
EnemyNode* createEnemy(int health, int weaponLevel, int x0, int y0, double angle, int moveMode, int vx, int vy, EnemyName name) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->health = health;
		pNew->weaponLevel = weaponLevel;
		pNew->x = x0;
		pNew->y = y0;
		pNew->vx = vx;
		pNew->vy = vy;
		pNew->angle = angle;
		pNew->moveMode = moveMode;
		break;
	case ENEMY1:
		pNew->health = health;
		pNew->weaponLevel = weaponLevel;
		pNew->x = x0;
		pNew->y = y0;
		pNew->vx = vx;
		pNew->vy = vy;
		pNew->angle = angle;
		pNew->moveMode = moveMode;
		break;
	}
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}
void Enemy_listPushHead(EnemyNode** pp_Enemy_List_Node_Head, EnemyNode* newNode) {
	if (*pp_Enemy_List_Node_Head == NULL)//如果链表为空，那么新增的节点就是第一个,头节点
	{
		*pp_Enemy_List_Node_Head = newNode;
		return;
	}
	newNode->pnext = (*pp_Enemy_List_Node_Head)->pnext;//让新增节点指向原先头节点指向的数据
	(*pp_Enemy_List_Node_Head)->pnext = newNode;//让原头节点指向新增节点
}
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, EnemyName name, Frame frame) {//用指针遍历每个飞机节点，根据飞机的初始位置,初始方向,选择不同的更新方式
	if (*pp_Enemy_List_Node_Head == NULL) return;
	EnemyNode* cur = *pp_Enemy_List_Node_Head;
	while (cur != NULL)
	{
		switch (name)
		{
		case ENEMY0:
			switch (cur->moveMode)
			{
			case DEF_LINEMOVE:

				break;
			case DEF_CIRCLEMOVE:

				break;

			default:
				break;
			}
			break;
		case ENEMY1:
			switch (cur->moveMode)
			{
			case DEF_LINEMOVE:

				break;
			case DEF_CIRCLEMOVE:

				break;

			default:
				break;
			}
			break;
		case BOSS:
			break;
		default:
			break;
		}
	}
}