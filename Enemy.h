#pragma once
#include "FrameManager.h"
#define PI 3.1415926
#define DEF_MOVE_STOP 0
#define DEF_MOVE_LINE 1//线性的移动方式
#define DEF_MOVE_CIRCLE 2//圆弧形的移动方式
#define DEF_MOVE_RAND 3//随机线性移动


struct  EnemyNode
{
	int type_enemy0 = 0, type_enemy1 = 0;
	int x, y, x0, y0;

	int health;//生命值

	int moveMode;//初始的移动方式,沿着坐标轴
	double radian;//偏转角


	int width;//模型的宽高
	int height;
	int hitpoints;//伤害值
	double speed;
	int weaponLevel;//武器的等级，其实就是子弹的种类
	int isExist;//物体是否需要销毁

	EnemyNode* pnext;//指向下一个节点的指针
};
enum EnemyName {
	ENEMY0,
	ENEMY1,
	BOSS,
};
/// <summary>
/// 敌人链表头插法
/// </summary>
/// <param name="pp_Enemy_List_Node">二维指针，取一位表示链表节点，取二维可以访问节点中的数据</param>
/// <param name="newNode">一维指针，新建的节点</param>
EnemyNode* createEnemy(int health, int weaponLevel, int x0, int y0, double radian, int moveMode, int speed, EnemyName name, Frame frame);
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








