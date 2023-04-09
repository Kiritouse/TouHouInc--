#include "Bullet.h"
#include "Player.h"
#include <cstddef>
#include "GameManager.h"
#include "Operation.h"
#define NORMAL  0
#define UPDATE 1 
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
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
	p->x = E_TYPE_Position.x + WIDTH_PLAYER / 2 - 8;//飞机头部的位置
	p->y = E_TYPE_Position.y;
	p->vx = vx;
	p->vy = vy;//速度
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void update_BulletPosition(BulletNode** pplist, int command, int frameBuffer)
{
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		listPushBack(&Player_Bullet_List, creatPlaneBullet(0, -10));
	}//处理射击操作

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
	BulletNode* curP = *pplist;//curret先指向第一个节点
	BulletNode* prevP = NULL;  //previous指向上一个节点的指针
	while (curP != NULL)//遍历链表
	{
		if (curP->isExist == 0)
		{
			if (*pplist == curP)
			{
				*pplist = curP->pnext;
				free(curP);
				curP = *pplist;
			}
			else
			{
				prevP->pnext = curP->pnext;
				free(curP);
				curP = prevP;
			}
		}
		else
		{
			prevP = curP;
			curP = curP->pnext;
		}
	}
}

void update_BulletImage() {
	for (BulletNode* cur = Player_Bullet_List; cur != NULL; cur = cur->pnext)
	{
		std::cout << cur->y << std::endl;
		transparentimage_half(NULL, cur->x, cur->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 150);


	}
}



