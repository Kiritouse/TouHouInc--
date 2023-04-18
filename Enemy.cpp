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
int maxNumsPoint;
std::vector< double > vec_out_x;
std::vector<double>vec_out_y;
EnemyNode* createEnemy(int health, int weaponLevel, int x0, int y0, double radian, int moveMode, int speed, EnemyName name, Frame frame) {
	EnemyNode* pNew = new EnemyNode;
	switch (name)
	{
	case ENEMY0:
		pNew->type_enemy0 = 1;
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
		pNew->type_enemy1 = 1;
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
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node_Head, EnemyNode* newNode) {
	if (*pp_Enemy_List_Node_Head == NULL)//如果链表为空，那么新增的节点就是第一个,头节点
	{
		*pp_Enemy_List_Node_Head = newNode;
		return;
	}
	newNode->pnext = (*pp_Enemy_List_Node_Head)->pnext;//让新增节点指向原先头节点指向的数据
	(*pp_Enemy_List_Node_Head)->pnext = newNode;//让原头节点指向新增节点
}
void moveLine(EnemyNode* cur, int speed, double radian, int frameBuffer, EnemyName name) {
	int xnext = cur->x + speed * cos(radian);
	int ynext = cur->y + speed * sin(radian);
	//std::cout << "ynext = " << ynext << std::endl;
	switch (name)
	{
	case ENEMY0:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0) {

			cur->x = xnext;
			cur->y = ynext;
			//std::cout << cur->y << std::endl;

		}
		else cur->isExist = 0;
		return;
	case ENEMY1:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1) {
			cur->x = xnext;
			cur->y = ynext;

		}
		else cur->isExist = 0;
		return;
	default:
		return;
	}
}
void div_circle(double x0, double y0, double r, double size) //xy对应圆心坐标,r为半径,size用于设置划分的间距
{
	vec_out_x.clear();
	vec_out_y.clear();
	double angle_step = 0; //一小步的弧度
	angle_step = size / r;
	double x_out, y_out;
	maxNumsPoint = 2 * PI / angle_step;
	std::cout << maxNumsPoint << std::endl;
	for (int i = 0; i < maxNumsPoint; i++)
	{
		x_out = x0 + r * cos(i * angle_step);
		std::cout << "xout" << x_out << std::endl;
		y_out = y0 + r * sin(i * angle_step);
		if (x_out > 0 && y_out > 0) {
			vec_out_x.push_back(x_out);
			vec_out_y.push_back(y_out);

		}

	}
}
void moveCircle(EnemyNode* cur, int r, int x0, int y0, int xo, int yo, int speed, int frameBuffer, EnemyName name) {
	double theta = 5 * PI / 4 - cur->speed * frameBuffer / 3 / (WIDTH_MAP / 2);
	int xnext = WIDTH_MAP / 2 + (WIDTH_MAP / 2) * cos(theta) - (double)WIDTH_MAP / 10;
	int ynext = (WIDTH_MAP / 2) * sin(theta);

	switch (name)
	{
	case ENEMY0:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else  cur->isExist = 0;;
		return;
	case ENEMY1:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1) {
			cur->x = xnext;
			cur->y = ynext;
		}
		else cur->isExist = 0;
		return;
	default:
		return;
	}

}
void moveRand(EnemyNode* cur, int speed, EnemyName name) {
	srand(time(0));
	int xnext = cur->x + rand() % speed - (speed / 2);
	int ynext = cur->y + rand() % speed - (speed / 3);
	switch (name)
	{
	case ENEMY0:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY0 && ynext < HEIGHT_MAP - HEIGHT_ENEMY0) {

			cur->x = xnext;
			cur->y = ynext;

		}
		else cur->isExist = 0;
		return;
	case ENEMY1:
		if (xnext < WIDTH_MAP - WIDTH_ENEMY1 && ynext < HEIGHT_MAP - HEIGHT_ENEMY1) {
			cur->x = xnext;
			cur->y = ynext;

		}
		else cur->isExist = 0;
		return;
	default:
		return;
	}

}
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, Frame frame) {//用指针遍历每个飞机节点，根据飞机的初始位置,初始方向,选择不同的更新方式
	if (*pp_Enemy_List_Node_Head == NULL) return;
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
			moveCircle(cur, WIDTH_MAP / 2, 0, 0, 0, 0, cur->speed, frameBuffer, ENEMY0);
			break;
		case DEF_MOVE_RAND:
			moveRand(cur, cur->speed, ENEMY0);
			break;
		default:
			break;
		}
		cur = cur->pnext;
	}
}
void update_EnemyImage(EnemyNode** p_Enemy_List, EnemyName name) {
	switch (name)
	{
	case ENEMY0:
		for (EnemyNode* cur = *p_Enemy_List; cur != NULL; cur = cur->pnext) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY0, HEIGHT_ENEMY0,
				0, 0, WIDTH_ENEMY0, HEIGHT_ENEMY0, &enemy0);
		}
		break;
	case ENEMY1:
		//std::cout << "12341q23" << std::endl;
		for (EnemyNode* cur = *p_Enemy_List; cur != NULL; cur = cur->pnext) {
			transparentimage(NULL, cur->x, cur->y, WIDTH_ENEMY1, HEIGHT_ENEMY1,
				0, 0, WIDTH_ENEMY1, HEIGHT_ENEMY1, &enemy1);
		}
		break;
	case BOSS:
		break;

	}

}
void listRemoveNode_Enemy(EnemyNode** pp_Enemy_List_Node_Head)
{
	if (*pp_Enemy_List_Node_Head == NULL)//如果链表为空，就没有可删除的节点了
		return;
	EnemyNode* curP_Enemy = *pp_Enemy_List_Node_Head;//curret先指向第一个节点
	EnemyNode* prevP_Enemy = NULL;  //previous指向上一个节点的指针
	while (curP_Enemy != NULL)//遍历链表
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
	update_EnemyImage(pp_Enemy_List_Node_Head, ENEMY1);
	listRemoveNode_Enemy(pp_Enemy_List_Node_Head);
}