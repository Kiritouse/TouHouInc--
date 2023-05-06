#include "Enemy.h"
#include "FrameManager.h"
#include "Operation.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#include "MathAndPhysics.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <random>
const double MOVE_FACTOR = 0.1;
Enemy::EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, double radian, double speed, Enemy::EnemyName name, int health, int weaponLevel, Frame frame) {
	Enemy::EnemyNode* pNew = new Enemy::EnemyNode;
	switch (name)
	{
	case Enemy::EnemyName::ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case Enemy::EnemyName::ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	//std::cout << "asdasd" << std::endl;
	pNew->x = x0;
	pNew->y = y0;
	pNew->x0 = x0;
	pNew->y0 = y0;
	pNew->moveMode = moveMode;
	pNew->radian = radian;
	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->FireSwitch = FireSwitch;
	pNew->fire_on = fire_on;
	pNew->pnext = NULL;
	return pNew;
}
Enemy::EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, double speed, Enemy::EnemyName name, int health, int weaponLevel, Frame frame) {
	Enemy::EnemyNode* pNew = new Enemy::EnemyNode;
	switch (name)
	{
	case Enemy::EnemyName::ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case Enemy::EnemyName::ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	pNew->FireSwitch = FireSwitch;
	pNew->fire_on = fire_on;
	pNew->x = x0;
	pNew->y = y0;
	pNew->x0 = x0;
	pNew->y0 = y0;
	pNew->moveMode = moveMode;
	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}
Enemy::EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, int xo, int yo, double radian, double speed, Enemy::EnemyName name, int health, int weaponLevel, Frame frame) {
	Enemy::EnemyNode* pNew = new Enemy::EnemyNode;
	switch (name)
	{
	case Enemy::EnemyName::ENEMY0:
		pNew->type_enemy0 = 1;
		break;
	case Enemy::EnemyName::ENEMY1:
		pNew->type_enemy1 = 1;
		break;
	}
	pNew->FireSwitch = FireSwitch;
	pNew->fire_on = fire_on;
	pNew->x = x0;
	pNew->y = y0;
	pNew->x0 = x0;
	pNew->y0 = y0;
	pNew->moveMode = moveMode;
	pNew->radian = radian;
	pNew->xo = xo;
	pNew->yo = yo;
	pNew->r = y0 - yo;

	pNew->speed = speed;
	pNew->health = health;
	pNew->weaponLevel = weaponLevel;
	pNew->f_create = frame.f_total - frame.f_pause;
	pNew->isExist = 1;
	pNew->pnext = NULL;
	return pNew;
}

void Enemy::Enemy_ListPushHead(Enemy::EnemyNode** pp_Enemy_List_Node_Head, Enemy::EnemyNode* newNode) {
	if (*pp_Enemy_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��,ͷ�ڵ�
	{
		*pp_Enemy_List_Node_Head = newNode;
		return;
	}
	newNode->pnext = (*pp_Enemy_List_Node_Head)->pnext;//�������ڵ�ָ��ԭ��ͷ�ڵ�ָ�������
	(*pp_Enemy_List_Node_Head)->pnext = newNode;//��ԭͷ�ڵ�ָ�������ڵ�
}
void Enemy::update_EnemyImage(Enemy::EnemyNode** p_Enemy_List) {
	for (EnemyNode* cur = *p_Enemy_List; cur != NULL; cur = cur->pnext) {
		if (cur->type_enemy0 == 1) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY0, HEIGHT_ENEMY0,
				0, 0, WIDTH_ENEMY0, HEIGHT_ENEMY0, &enemy0);
		}
		else if (cur->type_enemy1 == 1) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY1, HEIGHT_ENEMY1,
				0, 0, WIDTH_ENEMY1, HEIGHT_ENEMY1, &enemy1);
		}
		else if (cur->type_boss == 1) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_BOSS, HEIGHT_BOSS,
				0, 0, WIDTH_BOSS, HEIGHT_BOSS, &enemy1);
		}
	}
}

void moveLine(Enemy::EnemyNode* cur) {

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
void moveCircle(Enemy::EnemyNode* cur, int framebuffer, int type) {
	int xnext, ynext;
	if (type == 0) {
		xnext = cur->x0 + cur->r * sin(cur->radian);
		ynext = cur->y0 - (cur->r - cur->r * cos(cur->radian));
		cur->radian = cur->radian + cur->speed;
	}
	else if (type == 1) {
		xnext = cur->x0 - cur->r * sin(cur->radian);
		ynext = cur->y0 - (cur->r - cur->r * cos(cur->radian));
		cur->radian = cur->radian + cur->speed;

	}
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
void moveRand(Enemy::EnemyNode* cur, int framebuffer) {
	srand((unsigned int)time(NULL));
	int xnext = cur->x + rand() % ((int)cur->speed + 1) - (cur->speed) / 2;
	int ynext = cur->y + rand() % ((int)cur->speed + 1) - (cur->speed) / 20;
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
void moveBoss(Enemy::EnemyNode* cur) {
	if (cur->type_boss == 1) {
		if (cur->y <= HEIGHT_MAP / 3) {
			cur->y += cur->speed;
		}
		else {
			srand(time(0));
			int xnext = cur->x + rand() % (int)cur->speed - (cur->speed / 2);//��������ƶ�
			if (xnext < 2 || xnext >= WIDTH_MAP - WIDTH_BOSS) {
				cur->x = xnext;//ֻ�ѷ���Ҫ���x��λ��ֵ��cur->x
			}
		}
	}
}
void update_EnemyPosition(Enemy::EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {//��ָ�����ÿ���ɻ��ڵ㣬���ݷɻ��ĳ�ʼλ��,��ʼ����,ѡ��ͬ�ĸ��·�ʽ
	if (*pp_Enemy_List_Node_Head == NULL) return;
	Enemy::EnemyNode* cur = *pp_Enemy_List_Node_Head;
	int framebuffer = frame.f_total - frame.f_pause;
	while (cur != NULL)
	{
		if (cur->isExist == 0) return;//����Ѿ���ɾ���˾Ͳ���Ҫ���ƶ���
		if (cur->type_boss == 1) moveBoss(cur);
		else {
			switch (cur->moveMode)
			{
			case DEF_MOVE_LINE:
				moveLine(cur);
				break;
			case DEF_MOVE_CIRCLE_RIGHT:
				moveCircle(cur, framebuffer, 0);
				break;
			case DEF_MOVE_CIRCLE_LEFT:
				moveCircle(cur, framebuffer, 1);
				break;
			case DEF_MOVE_RAND:
				moveRand(cur, framebuffer);
				break;
			default:
				break;
			}
		}
		cur = cur->pnext;
	}
}
void listRemoveNode_Enemy(Enemy::EnemyNode** pp_Enemy_List_Node_Head)
{
	if (*pp_Enemy_List_Node_Head == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	Enemy::EnemyNode* curP_Enemy = *pp_Enemy_List_Node_Head;//curret��ָ���һ���ڵ�
	Enemy::EnemyNode* prevP_Enemy = NULL;  //previousָ����һ���ڵ��ָ��
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

void Enemy::update_Enemy(Enemy::EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {
	update_EnemyPosition(pp_Enemy_List_Node_Head, frame);
	listRemoveNode_Enemy(pp_Enemy_List_Node_Head);



}