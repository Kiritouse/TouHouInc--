#pragma once
#include "GameManager.h"
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
//补充一下，链表实际上就相当于一个二维数组
//一维指针相当于指向某一个节点，二维指针就相当于指向某一节点中的某一个数据
void listPushBack(BulletNode* pplist, BulletNode* newNode);//尾插一个数据
BulletNode* creatPlaneBullet(float vx, float vy);//飞机每发射一颗子弹增加一个节点
void listChangeXY(BulletNode** pplist);//修改链表中所有节点的坐标
void listRemoveNode(BulletNode** pplist);//删除链表中isExist为0的节点
void paintBullet();
