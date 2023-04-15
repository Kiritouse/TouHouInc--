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
	if (*pp_Enemy_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��,ͷ�ڵ�
	{
		*pp_Enemy_List_Node_Head = newNode;
		return;
	}
	newNode->pnext = (*pp_Enemy_List_Node_Head)->pnext;//�������ڵ�ָ��ԭ��ͷ�ڵ�ָ�������
	(*pp_Enemy_List_Node_Head)->pnext = newNode;//��ԭͷ�ڵ�ָ�������ڵ�
}
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, EnemyName name, Frame frame) {//��ָ�����ÿ���ɻ��ڵ㣬���ݷɻ��ĳ�ʼλ��,��ʼ����,ѡ��ͬ�ĸ��·�ʽ
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