#include "Bullet.h"
#include "Player.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#include <cstddef>
#include "Operation.h"
#define NORMAL  0
#define UPDATE 1 
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
BulletNode* creatPlayerBullet(float vx, float vy) {
	BulletNode* p = new BulletNode;
	p->x = Struct_Position.x + WIDTH_PLAYER / 2 - 8;//�ɻ�ͷ����λ��
	p->y = Struct_Position.y;
	p->vx = vx;
	p->vy = vy;//�ٶ�
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void Bullet_listPushBack(BulletNode** pp_Player_Bullet_List_Node_Head, BulletNode* newNode) {
	if (*pp_Player_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
	{
		*pp_Player_Bullet_List_Node_Head = newNode;
		return;
	}
	BulletNode* cur = *pp_Player_Bullet_List_Node_Head;
	while (cur->pnext != NULL)//�ҵ����һ���ڵ�
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//�����µĽڵ�
}

void update_BulletPosition(BulletNode** pp_Player_Bullet_List_Node_Head, int command, int frameBuffer)
{
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		//std::cout << "asdsa" << std::endl;
		Bullet_listPushBack(pp_Player_Bullet_List_Node_Head, creatPlayerBullet(0, -10));

	}//�����������

	if (*pp_Player_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
		return;
	BulletNode* cur = *pp_Player_Bullet_List_Node_Head;//curretָ���һ���ڵ�
	while (cur != NULL)//��������
	{
		cur->x += cur->vx;
		cur->y += cur->vy;
		//�ж��ӵ��Ƿ��뿪��Ұ
		if ((cur->y < -20) || (cur->y > HEIGHT_MAP) || (cur->x > WIDTH_MAP) || (cur->y < -20))
			cur->isExist = 0;
		cur = cur->pnext;//ָ����һ���ڵ�
	}
}
void listRemoveNode_Bullet(BulletNode** pp_Player_Bullet_List_Node_Head)
{
	if (*pp_Player_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	BulletNode* curP = *pp_Player_Bullet_List_Node_Head;//curret��ָ���һ���ڵ�
	BulletNode* prevP = NULL;  //previousָ����һ���ڵ��ָ��
	while (curP != NULL)//��������
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

void update_BulletImage(BulletNode** pp_Player_Bullet_List) {
	for (BulletNode* cur = *pp_Player_Bullet_List; cur != NULL; cur = cur->pnext)
	{

		transparentimage_half(NULL, cur->x, cur->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 150);
	}
}
void update_Bullet(BulletNode** pp_Player_Bullet_List_Head, int command, int frameBuffer) {
	update_BulletPosition(pp_Player_Bullet_List_Head, command, frameBuffer);
	listRemoveNode_Bullet(pp_Player_Bullet_List_Head);//������Ұ���߻��з��������ӵ�ɾ����
	update_BulletImage(pp_Player_Bullet_List_Head);
}



