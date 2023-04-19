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
	int x, y;//初始创建角色的位置信息,x,y为每次移动的位置

	int moveMode;//初始的移动方式,沿着坐标轴
	int xo, yo, r;//对于弧形移动的所需参数，xo和yo为圆心,r为半径
	double radian;//偏转角，用于直线移动和随机移动

	int health;//生命值

	int f_create;//创建该角色时的帧数

	int width;//模型的宽高
	int height;

	int hitpoints;//伤害值
	int speed;
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
/// 直线移动时的初始化
/// </summary>
/// <param name="x0">创建物体时的起始点</param>
/// <param name="y0">创建物体时的起始点</param>
/// <param name="moveMode">移动方式</param>
/// <param name="radian">直线移动的偏转角，以水平方向为起点，逆时针旋转</param>
/// <param name="speed">速度</param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, double radian, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
/// <summary>
/// 随机移动时的初始化
/// </summary>
/// <param name="x0"></param>
/// <param name="y0"></param>
/// <param name="moveMode"></param>
/// <param name="speed"></param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
/// <summary>
/// 弧形移动时的初始化
/// </summary>
/// <param name="x0">创建物体时的起始点</param>
/// <param name="y0">创建物体时的起始点</param>
/// <param name="moveMode">移动方式</param>
/// <param name="xo">弧形移动时的圆心</param>
/// <param name="yo">弧形移动时的圆心</param>
/// <param name="r">圆形移动的半径</param>
/// <param name="speed">每次移动的速度</param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, int xo, int yo, int r, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








