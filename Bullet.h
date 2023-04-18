#pragma once
struct BulletNode
{
	float x, y;
	float vx, vy;
	int hitpoint;
	int isExist;//判断子弹是否需要删除
	BulletNode* pnext;
};
//补充一下，链表实际上就相当于一个二维数组
//一维指针相当于指向某一个节点，二维指针就相当于指向某一节点中的某一个数据

void update_Bullet(BulletNode** pp_Player_Bullet_List_Head, int command, int frameBuffer);
