#include "Enemy.h"
#include "Operation.h"
#include <iostream>
#include <math.h>
#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59
#define WDITH_ENEMY1 43
#define HEIGT_ENEMY1 58
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
void update_EnemyPosition(EnemyNode* pp_Enemy_List_Node_Head, Frame frame) {//��ָ�����ÿ���ɻ��ڵ㣬���ݷɻ��ĳ�ʼλ��,��ʼ����,ѡ��ͬ�ĸ��·�ʽ
	if (pp_Enemy_List_Node_Head == NULL) return;
	EnemyNode* cur = pp_Enemy_List_Node_Head;
	while (cur != NULL)
	{
		switch (cur->moveMode)
		{
		case DEF_MOVE_LINE:
			int frameBuffer = frame.f_total - frame.f_pause - frame.f_create;
			moveLine(cur, cur->x, cur->y, cur->speed, cur->radian, frameBuffer);
			break;

		case DEF_MOVE_CIRCLE:

			break;
		case DEF_MOVE_STOP:


			break;
		default:
			break;
		}
		break;
	}
}
void moveLine(EnemyNode* cur, int x, int y, int speed, double radian, int frameBuffer) {
	cur->x = cur->x + speed * frameBuffer * cos(radian);
	cur->y = cur->y + speed * frameBuffer * sin(radian);
}
void moveCircle(EnemyNode* cur, int x, int y, int speed, double radian, int frameBuffer) {


}