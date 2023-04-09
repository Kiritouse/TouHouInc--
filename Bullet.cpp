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
	if (*pplist == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
	{
		*pplist = newNode;
		return;
	}
	BulletNode* cur = *pplist;
	while (cur->pnext != NULL)//�ҵ����һ���ڵ�
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//�����µĽڵ�
}
BulletNode* creatPlaneBullet(float vx, float vy) {
	BulletNode* p = new BulletNode;
	p->x = E_TYPE_Position.x + WIDTH_PLAYER / 2 - 8;//�ɻ�ͷ����λ��
	p->y = E_TYPE_Position.y;
	p->vx = vx;
	p->vy = vy;//�ٶ�
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void update_BulletPosition(BulletNode** pplist, int command, int frameBuffer)
{
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		listPushBack(&Player_Bullet_List, creatPlaneBullet(0, -10));
	}//�����������

	if (*pplist == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
		return;
	BulletNode* cur = *pplist;//curretָ���һ���ڵ�
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
void listRemoveNode(BulletNode** pplist)
{
	if (*pplist == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	BulletNode* curP = *pplist;//curret��ָ���һ���ڵ�
	BulletNode* prevP = NULL;  //previousָ����һ���ڵ��ָ��
	while (curP != NULL)//��������
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



