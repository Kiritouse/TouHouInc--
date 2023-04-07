#pragma once
#include "Flyers.h"
#include "GameManager.h"
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
int leverl;//用于实现
struct BulletNode
{
	int x, y;//子弹坐标
	int xo, yo;//子弹发射时的位置
	int frame_create;//记录创建时的帧数
	int fire_on, fire_off;//记录开火时的帧数间隔
	int FireSwitch;//是否开火，对敌机实现间歇性射击
	int dx, dy;//x和y方向上的速度，也就是增量,便于实现分叉
	bool isExist;//判断子弹是否需要删除
	int hit;
	int width, height;
	BulletNode* pnext;//指向下一个子弹节点的指针
};
void moveBullet();
void paintBullet();
void addBullet(int flag, int x, int y);
void addBulletManager(int flag, int x, int y, int command);//增加子弹


