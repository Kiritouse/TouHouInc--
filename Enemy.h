#pragma once
#include "FrameManager.h"
#define PI 3.1415926
#define DEF_MOVE_STOP 0
#define DEF_MOVE_LINE 1//线性的移动方式
#define DEF_MOVE_CIRCLE 2//圆弧形的移动方式
#define DEF_MOVE_RAND 3//随机线性移动


struct  EnemyNode
{
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
void Enemy_listPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
/// <summary>
/// 更新敌机的位置
/// </summary>
/// <param name="pp_Enemy_List_Node_Head">所有敌机所构成的链表</param>
/// <param name="name">敌机种类</param>
/// <param name="frame">根据帧数我们会选择不同的移动方式</param>
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);
void moveLine(EnemyNode* cur, int speed, double radian, int frameBuffer, EnemyName name);
/// <summary>
/// 进行圆弧形移动
/// </summary>
/// <param name="cur"></param>
/// <param name="r">圆弧的半径</param>
/// <param name="x0">起始点</param>
/// <param name="y0">起始点</param>
/// <param name="xo">移动的圆弧的圆心</param>
/// <param name="yo">移动的圆弧的圆心</param>
/// <param name="speed">每一帧的起点和终点的直线距离</param>
/// <param name="frameBuffer"></param>
/// <param name="name"></param>
void moveCircle(EnemyNode* cur, int r, int x0, int y0, int xo, int yo, int speed, int frameBuffer, EnemyName name);
void moveRand(EnemyNode* cur, int speed, EnemyName name);
void update_EnemyImage(EnemyNode** p_Enemy_List, EnemyName name);
int num_Enemies();//获取在场敌机的数量
void listRemoveNode_Enemy(EnemyNode** pp_Enemy_List_Node_Head);







