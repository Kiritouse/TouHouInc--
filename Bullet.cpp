#include "Bullet.h"
#include "Player.h"
#include <cstddef>
#include "GameManager.h"
#include "Operation.h"
#define NORMAL  0
#define UPDATE 1 
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
BulletNode* creatPlayerBullet(float vx, float vy) {
	BulletNode* p = new BulletNode;
	p->x = Struct_Position.x + WIDTH_PLAYER / 2 - 8;//飞机头部的位置
	p->y = Struct_Position.y;
	p->vx = vx;
	p->vy = vy;//速度
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void Bullet_listPushBack(BulletNode** pp_Player_Bullet_List_Node_Head, BulletNode* newNode) {
	if (*pp_Player_Bullet_List_Node_Head == NULL)//如果链表为空，那么新增的节点就是第一个
	{
		*pp_Player_Bullet_List_Node_Head = newNode;
		return;
	}
	BulletNode* cur = *pp_Player_Bullet_List_Node_Head;
	while (cur->pnext != NULL)//找到最后一个节点
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//插入新的节点
}

void update_BulletPosition(BulletNode** pp_Player_Bullet_List_Node_Head, int command, int frameBuffer)
{
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		Bullet_listPushBack(pp_Player_Bullet_List_Node_Head, creatPlayerBullet(0, -10));
	}//处理射击操作

	if (*pp_Player_Bullet_List_Node_Head == NULL)//如果链表为空，那么新增的节点就是第一个
		return;
	BulletNode* cur = *pp_Player_Bullet_List_Node_Head;//curret指向第一个节点
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
void listRemoveNode_Bullet(BulletNode** pp_Player_Bullet_List_Node_Head)
{
	if (*pp_Player_Bullet_List_Node_Head == NULL)//如果链表为空，就没有可删除的节点了
		return;
	BulletNode* curP = *pp_Player_Bullet_List_Node_Head;//curret先指向第一个节点
	BulletNode* prevP = NULL;  //previous指向上一个节点的指针
	while (curP != NULL)//遍历链表
	{
		if (curP->isExist == 0)
		{
			if (*pp_Player_Bullet_List_Node_Head == curP)
			{
				*pp_Player_Bullet_List_Node_Head = curP->pnext;
				free(curP);
				curP = *pp_Player_Bullet_List_Node_Head;
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

void update_BulletImage(BulletNode** p_Player_Bullet_List) {
	for (BulletNode* cur = *p_Player_Bullet_List; cur != NULL; cur = cur->pnext)
	{
		//std::cout << cur->y << std::endl;
		transparentimage_half(NULL, cur->x, cur->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 150);


	}
}



