#pragma once

struct  EnemyNode
{
	int x, y, x0, y0;
	int up;
	int down;
	int left;
	int right;
	double angle;//偏转角
	int health;//生命值

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
EnemyNode* createEnemy(int x0, int y0, double angle, int vx, int vy, EnemyName name);
void update_EnemyPosition(EnemyName name);
void update_EnemyImage(EnemyName name);
int num_Enemies();//获取在场敌机的数量





