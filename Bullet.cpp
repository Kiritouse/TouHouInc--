#include "Bullet.h"
#include "Player.h"
#include <cstddef>
#include "GameManager.h"
#include "Operation.h"
#define NORMAL  0
#define UPDATE 1
void dealInput_Fire(int command, int frameBuffer) {
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		listPushBack(&plane_bullet_list, creatPlaneBullet(0, -10));
	}
}
void listPushBack(BulletNode** pplist, BulletNode* newNode) {
	if (*pplist == NULL)//如果链表为空，那么新增的节点就是第一个
	{
		*pplist = newNode;
		return;
	}
	BulletNode* cur = *pplist;
	while (cur->pnext != NULL)//找到最后一个节点
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//插入新的节点
}
BulletNode* creatPlaneBullet(float vx, float vy) {
	BulletNode* p = new BulletNode;
	p->x = position.x + WIDTH_PLAYER / 2 - 8;//飞机头部的位置
	p->y = position.y;
	p->vx = vx;
	p->vy = vy;//速度
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void listChangeXY(BulletNode** pplist)
{
	if (*pplist == NULL)//如果链表为空，那么新增的节点就是第一个
		return;
	BulletNode* cur = *pplist;//curret指向第一个节点
	while (cur != NULL)//遍历链表
	{
		cur->x += cur->vx;
		cur->y += cur->vy;
		//判断子弹是否离开视野
		if ((cur->y < -20) || (cur->y > HEIGHT_MAP) || (cur->x > WIDTH_MAP) || (cur->y < -20))
			cur->isExist = 0;
		cur = cur->pnext;//指向下一个节点
	}
}
void listRemoveNode(BulletNode** pplist)
{
	if (*pplist == NULL)//如果链表为空，就没有可删除的节点了
		return;
	BulletNode* cur = *pplist;//curret先指向第一个节点
	BulletNode* prev = NULL;  //previous指向上一个节点的指针
	while (cur != NULL)//遍历链表
	{
		if (cur->isExist == 0)//判断节点是否需要删除
		{
			if (*pplist == cur)//如果删除的是第一个节点
			{
				*pplist = cur->pnext;  //更改链表的地址，让下一个节点作为头结点 ，如果没有节点，则链表为空
				free(cur);             //释放当前节点（第一个节点的）空间
				cur = *pplist;         //让cur指向下一个节点
			}
			else
			{
				prev->pnext = cur->pnext;  //记录下一个节点的地址
				free(cur);                 //释放当前节点空间
				cur = prev;                //当前节点变成前一个节点
			}
		}
		else //如果不需要删除节点，储存当前节点为前一个节点，然后指向下一个节点
		{
			prev = cur;
			cur = cur->pnext;
		}
	}
}

void paintBullet() {
	listChangeXY(&plane_bullet_list);//计算子弹新的位置
	listRemoveNode(&plane_bullet_list);//超出视野或者击中飞行器的子弹删除掉
	for (BulletNode* cur = plane_bullet_list; cur != NULL; cur = cur->pnext)
	{
		std::cout << cur->y << std::endl;
		transparentimage_half(NULL, cur->x, cur->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 150);


	}
}



