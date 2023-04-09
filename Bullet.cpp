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
	p->x = position.x + WIDTH_PLAYER / 2 - 8;//�ɻ�ͷ����λ��
	p->y = position.y;
	p->vx = vx;
	p->vy = vy;//�ٶ�
	p->hitpoint = 1;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}
void listChangeXY(BulletNode** pplist)
{
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
	BulletNode* cur = *pplist;//curret��ָ���һ���ڵ�
	BulletNode* prev = NULL;  //previousָ����һ���ڵ��ָ��
	while (cur != NULL)//��������
	{
		if (cur->isExist == 0)//�жϽڵ��Ƿ���Ҫɾ��
		{
			if (*pplist == cur)//���ɾ�����ǵ�һ���ڵ�
			{
				*pplist = cur->pnext;  //��������ĵ�ַ������һ���ڵ���Ϊͷ��� �����û�нڵ㣬������Ϊ��
				free(cur);             //�ͷŵ�ǰ�ڵ㣨��һ���ڵ�ģ��ռ�
				cur = *pplist;         //��curָ����һ���ڵ�
			}
			else
			{
				prev->pnext = cur->pnext;  //��¼��һ���ڵ�ĵ�ַ
				free(cur);                 //�ͷŵ�ǰ�ڵ�ռ�
				cur = prev;                //��ǰ�ڵ���ǰһ���ڵ�
			}
		}
		else //�������Ҫɾ���ڵ㣬���浱ǰ�ڵ�Ϊǰһ���ڵ㣬Ȼ��ָ����һ���ڵ�
		{
			prev = cur;
			cur = cur->pnext;
		}
	}
}

void paintBullet() {
	listChangeXY(&plane_bullet_list);//�����ӵ��µ�λ��
	listRemoveNode(&plane_bullet_list);//������Ұ���߻��з��������ӵ�ɾ����
	for (BulletNode* cur = plane_bullet_list; cur != NULL; cur = cur->pnext)
	{
		std::cout << cur->y << std::endl;
		transparentimage_half(NULL, cur->x, cur->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 150);


	}
}



