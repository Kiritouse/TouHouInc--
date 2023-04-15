#pragma once
#include "FrameManager.h"
#define PI 3.1415926
//几种最基础的方向，都是沿着坐标轴，通过不同的偏转角度组合成各种方向
#define DEF_LINEMOVE 0
#define DEF_CIRCLEMOVE 1
struct  EnemyNode
{
	int x, y, x0, y0;

	int health;//生命值

	int moveMode;//初始的移动方式,沿着坐标轴
	double angle;//偏转角


	int width;//模型的宽高
	int height;
	int hitpoints;//伤害值
	int vx, vy;//在x,y方向上的增量，实际上就是速度
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
EnemyNode* createEnemy(int x0, int y0, double angle, int vx, int vy, EnemyName name);
void Enemy_listPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
/// <summary>
/// 更新敌机的位置
/// </summary>
/// <param name="pp_Enemy_List_Node_Head">所有敌机所构成的链表</param>
/// <param name="name">敌机种类</param>
/// <param name="frame">根据帧数我们会选择不同的移动方式</param>
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, EnemyName name, Frame frame);
void update_EnemyImage(EnemyName name);
int num_Enemies();//获取在场敌机的数量





