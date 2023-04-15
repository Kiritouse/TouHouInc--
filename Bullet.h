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
void dealInput_Fire(int command, int frameBuffer);
BulletNode* creatPlayerBullet(float vx, float vy);//飞机每发射一颗子弹增加一个节点,初始化每个节点的数据
void Bullet_listPushBack(BulletNode** pp_Player_Bullet_List_Node, BulletNode* newNode);//把新增节点的数据插入链表当中

void update_BulletPosition(BulletNode** pp_Player_Bullet_List_Node, int command, int framebuffer);//修改链表中所有节点的坐标
void listRemoveNode(BulletNode** pp_Player_Bullet_List_Node);//删除链表中isExist为0的节点
void update_BulletImage(BulletNode* p_Player_Bullet_List_Node);
