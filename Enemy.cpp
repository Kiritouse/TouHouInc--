#include "Enemy.h"
#include "Operation.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#include <iostream>
#include <math.h>
#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59
#define WIDTH_ENEMY1 43
#define HEIGHT_ENEMY1 58
EnemyNode* createEnemy(int health, int weaponLevel, int x0, int y0, double radian, int moveMode, int speed, EnemyName name, Frame frame) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->health = health;
		pNew->weaponLevel = weaponLevel;
		pNew->x = x0;
		pNew->y = y0;
		pNew->x0 = x0;
		pNew->y0 = y0;
		pNew->speed = speed;
		pNew->radian = radian;
		pNew->moveMode = moveMode;
		frame.f_create = frame.f_total - frame.f_pause;
		break;
	case ENEMY1:
		pNew->health = health;
		pNew->weaponLevel = weaponLevel;
		pNew->x = x0;
		pNew->y = y0;
		pNew->x0 = x0;
		pNew->y0 = y0;
		pNew->speed = speed;
		pNew->radian = radian;
		pNew->moveMode = moveMode;
		frame.f_create = frame.f_total - frame.f_pause;
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
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {//��ָ�����ÿ���ɻ��ڵ㣬���ݷɻ��ĳ�ʼλ��,��ʼ����,ѡ��ͬ�ĸ��·�ʽ
	if (*pp_Enemy_List_Node_Head == NULL) return;
	//std::cout << "yes" << std::endl;
	EnemyNode* cur = *pp_Enemy_List_Node_Head;
	int frameBuffer = frame.f_total - frame.f_pause - frame.f_create;
	while (cur != NULL)
	{
		switch (cur->moveMode)
		{
		case DEF_MOVE_LINE:
			moveLine(cur, cur->speed, cur->radian, frameBuffer, ENEMY0);
			break;

		case DEF_MOVE_CIRCLE:
			moveCircle(cur, WIDTH_MAP / 2, 0, 0, cur->speed, frameBuffer, ENEMY0);
			break;
		case DEF_MOVE_STOP:


			break;
		default:
			break;
		}
		break;
	}
}
void moveLine(EnemyNode* cur, int speed, double radian, int frameBuffer, EnemyName name) {
	int xnext = cur->x + speed * frameBuffer * cos(radian);
	int ynext = cur->y + speed * frameBuffer * sin(radian);
	switch (name)
	{
	case ENEMY0:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0) {
			cur->x = xnext;
			cur->y = ynext;
			cur->isExist = 0;
		}
		return;
	case ENEMY1:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1) {
			cur->x = xnext;
			cur->y = ynext;
			cur->isExist = 0;
		}
		return;
	default:
		return;
	}
}
void moveCircle(EnemyNode* cur, int r, int xo, int yo, int speed, int frameBuffer, EnemyName name) {
	int xnext = speed * frameBuffer * (1 - ((int)pow(speed, 2) / 2 * (int)pow(r, 2))) + cur->x;
	int ynext = sqrt(r * r - (cur->x) * (cur->x)) + cur->y;
	switch (name)
	{
	case ENEMY0:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0) {
			cur->x = xnext;
			cur->y = ynext;
			cur->isExist = 0;
		}
		return;
	case ENEMY1:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1) {
			cur->x = xnext;
			cur->y = ynext;
			cur->isExist = 0;
		}
		return;
	default:
		return;
	}

}
void update_EnemyImage(EnemyNode** p_Enemy_List, EnemyName name) {
	for (EnemyNode* cur = *p_Enemy_List; cur != NULL; cur = cur->pnext) {
		transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY0, HEIGHT_ENEMY0,
			0, 0, WIDTH_ENEMY0, HEIGHT_ENEMY0, &enemy0);
	}
}
void listRemoveNode_Enemy(EnemyNode** pp_Enemy_List_Node_Head)
{
	if (*pp_Enemy_List_Node_Head == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	EnemyNode* curP_Enemy = *pp_Enemy_List_Node_Head;//curret��ָ���һ���ڵ�
	EnemyNode* prevP_Enemy = NULL;  //previousָ����һ���ڵ��ָ��
	while (curP_Enemy != NULL)//��������
	{
		if (curP_Enemy->isExist == 0)
		{
			if (*pp_Enemy_List_Node_Head == curP_Enemy)
			{
				*pp_Enemy_List_Node_Head = curP_Enemy->pnext;
				free(curP_Enemy);
				curP_Enemy = *pp_Enemy_List_Node_Head;
			}
			else
			{
				prevP_Enemy->pnext = curP_Enemy->pnext;
				free(curP_Enemy);
				curP_Enemy = prevP_Enemy;
			}
		}
		else
		{
			prevP_Enemy = curP_Enemy;
			curP_Enemy = curP_Enemy->pnext;
		}
	}
}