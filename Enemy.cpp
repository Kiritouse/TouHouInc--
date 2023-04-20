#include "Enemy.h"
#include "Operation.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#include "MathAndPhysics.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <random>
#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59
#define WIDTH_ENEMY1 43
#define HEIGHT_ENEMY1 58
EnemyNode* createEnemy(int x0, int y0, int moveMode, double radian, int speed, EnemyName name, int health, int weaponLevel, Frame frame) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	pNew->x = x0;
	pNew->y = y0;
	pNew->moveMode = moveMode;
	pNew->radian = radian;
	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}
EnemyNode* createEnemy(int x0, int y0, int moveMode, int speed, EnemyName name, int health, int weaponLevel, Frame frame) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	pNew->x = x0;
	pNew->y = y0;
	pNew->moveMode = moveMode;
	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}
EnemyNode* createEnemy(int x0, int y0, int moveMode, int xo, int yo, int r, int speed, EnemyName name, int health, int weaponLevel, Frame frame) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	pNew->x = x0;
	pNew->y = y0;
	pNew->moveMode = moveMode;
	pNew->radian = atan2(y0 - yo, x0 - xo);
	pNew->xo = xo;
	pNew->yo = yo;
	pNew->r = r;
	std::cout << r << std::endl;

	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}

void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node_Head, EnemyNode* newNode) {
	if (*pp_Enemy_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��,ͷ�ڵ�
	{
		*pp_Enemy_List_Node_Head = newNode;
		return;
	}
	newNode->pnext = (*pp_Enemy_List_Node_Head)->pnext;//�������ڵ�ָ��ԭ��ͷ�ڵ�ָ�������
	(*pp_Enemy_List_Node_Head)->pnext = newNode;//��ԭͷ�ڵ�ָ�������ڵ�
}
void update_EnemyImage(EnemyNode** p_Enemy_List) {
	for (EnemyNode* cur = *p_Enemy_List; cur != NULL; cur = cur->pnext) {
		if (cur->type_enemy0 == 1) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY0, HEIGHT_ENEMY0,
				0, 0, WIDTH_ENEMY0, HEIGHT_ENEMY0, &enemy0);
		}
		else if (cur->type_enemy1 == 1) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY1, HEIGHT_ENEMY1,
				0, 0, WIDTH_ENEMY1, HEIGHT_ENEMY1, &enemy1);
		}
	}
}
void moveLine(EnemyNode* cur) {

	int xnext = cur->x + cur->speed * cos(cur->radian);
	int ynext = cur->y + cur->speed * sin(cur->radian);
	if (cur->type_enemy0 == 1)
	{
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0 && xnext > 0 && ynext > 0) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else cur->isExist = 0;
		return;
	}
	else if (cur->type_enemy1 == 1) {
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1 && xnext >0 && ynext > 0) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else cur->isExist = 0;
		return;
	}

}
void moveCircle(EnemyNode* cur, int framebuffer) {
	int xnext, ynext;

	xnext = cur->xo + cur->r * cos(cur->radian);
	std::cout << "cur->xo =  " << cur->xo << std::endl;
	std::cout << "cur->r = " << cur->r << std::endl;
	std::cout << "cur->radian = " << cur->radian << std::endl;
	std::cout << "xnext = " << xnext << std::endl;
	ynext = cur->yo + cur->r * sin(cur->radian);
	std::cout << "ynext = " << ynext << std::endl;

	cur->radian = cur->radian + 0.05;
	if (cur->type_enemy0 == 1) {
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0 && xnext > 1 && ynext > 1) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else {
			cur->isExist = 0;
			return;
		}
	}
	else if (cur->type_enemy1 == 1) {

		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1 && xnext > 1 && ynext > 1) {
			cur->x = xnext;
			cur->y = ynext;


		}
		else {
			cur->isExist = 0;
			return;
		}
	}

}
void moveRand(EnemyNode* cur) {
	srand(time(0));
	int xnext = cur->x + rand() % cur->speed - (cur->speed / 2);
	int ynext = cur->y + rand() % cur->speed - (cur->speed / 3);
	if (cur->type_enemy0 == 1) {
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0 && xnext > 0 && ynext >0) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else {
			cur->isExist = 0;
			return;
		}
	}
	else if (cur->type_enemy1 == 1) {
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1 && xnext > 0 && ynext >0) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else {
			cur->isExist = 0;
			return;
		}

	}
}
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {//��ָ�����ÿ���ɻ��ڵ㣬���ݷɻ��ĳ�ʼλ��,��ʼ����,ѡ��ͬ�ĸ��·�ʽ
	if (*pp_Enemy_List_Node_Head == NULL) return;
	EnemyNode* cur = *pp_Enemy_List_Node_Head;
	int framebuffer = frame.f_total - frame.f_pause;
	while (cur != NULL)
	{
		if (cur->isExist == 0) return;//����Ѿ���ɾ���˾Ͳ���Ҫ���ƶ���
		switch (cur->moveMode)
		{
		case DEF_MOVE_LINE:
			moveLine(cur);
			break;
		case DEF_MOVE_CIRCLE:
			moveCircle(cur, framebuffer);
			break;
		case DEF_MOVE_RAND:
			moveRand(cur);
			break;
		default:
			break;
		}
		cur = cur->pnext;
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

void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {
	update_EnemyPosition(pp_Enemy_List_Node_Head, frame);
	listRemoveNode_Enemy(pp_Enemy_List_Node_Head);
	update_EnemyImage(pp_Enemy_List_Node_Head);

}