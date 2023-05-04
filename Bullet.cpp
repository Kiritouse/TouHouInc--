#include "Bullet.h"
#include "Player.h"
#include "Map.h"
#include "Draw.h"
#include <conio.h>
#include "LoadResources.h"
#include <cstddef>
#include <graphics.h>
#include <Windows.h>
#include "Operation.h"
#include "ParticleManager.h"

BulletNode* creatPlayerBullet(float vx, float vy, int hitpoint) {
	BulletNode* p = new BulletNode;
	p->x = Struct_PlayerPosition.x + WIDTH_PLAYER / 2 - 8;//�ɻ�ͷ����λ��
	p->y = Struct_PlayerPosition.y;
	p->vx = vx;
	p->vy = vy;//�ٶ�
	p->hitpoint = hitpoint;
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

void update_BulletPosition(BulletNode** pp_Player_Bullet_List_Node_Head, int command, int frameBuffer, int vx, int vy, int hitpoint)
{
	if (((command & CMD_FIRE) && ((frameBuffer & 1) == 0))) {
		Bullet_listPushBack(pp_Player_Bullet_List_Node_Head, creatPlayerBullet(vx, vy, hitpoint));

	}//�����������

	if (*pp_Player_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
		return;
	BulletNode* cur = *pp_Player_Bullet_List_Node_Head;//curretָ���һ���ڵ�
	while (cur != NULL)//��������
	{
		cur->x += cur->vx;
		cur->y += cur->vy;
		//�ж��ӵ��Ƿ��뿪��Ұ
		if ((cur->y < -20) || (cur->y > HEIGHT_MAP) || (cur->x > WIDTH_MAP) || (cur->x < -20))
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
void bulletCrashEnemyCheck(EnemyNode** pp_Enemy_List_Head, BulletNode** pp_Player_Bullet_List_Head) {
	BulletNode* curBullet = *pp_Player_Bullet_List_Head;
	while (curBullet != NULL) {
		EnemyNode* curEnemy = *pp_Enemy_List_Head;
		while (curEnemy != NULL) {
			//����ӵ��ڵ��˵�ͼƬ��
			int WIDTH, HEIGHT;
			if (curEnemy->type_enemy0 == 1) {
				WIDTH = WIDTH_ENEMY0;
				HEIGHT = HEIGHT_ENEMY0;
			}
			else if (curEnemy->type_enemy1 == 1) {
				WIDTH = WIDTH_ENEMY1;
				HEIGHT = HEIGHT_ENEMY1;
			}
			else return;
			if ((curBullet->x > curEnemy->x) && (curBullet->x < (curEnemy->x + WIDTH))) {
				if ((curBullet->y > curEnemy->y) && (curBullet->y < (curEnemy->y + HEIGHT))) {
					//std::cout << curEnemy->health << std::endl;
					if (curEnemy->health <= 0) {
						curEnemy->isExist = 0;
						createFireworks(&curEnemy);
					}
					else {
						//std::cout << curBullet->hitpoint << std::endl;
						curEnemy->health -= curBullet->hitpoint;
					}
					curBullet->isExist = 0;


				}
			}

			curEnemy = curEnemy->pnext;
		}


		curBullet = curBullet->pnext;
	}
}
void update_Bullet(EnemyNode** pp_Enemy_List_Head, BulletNode** pp_Player_Bullet_List_Head, int command, int frameBuffer, int vx, int vy, int hitpoint) {
	update_BulletPosition(pp_Player_Bullet_List_Head, command, frameBuffer, vx, vy, hitpoint);
	bulletCrashEnemyCheck(pp_Enemy_List_Head, pp_Player_Bullet_List_Head);
	listRemoveNode_Bullet(pp_Player_Bullet_List_Head);//������Ұ���߻��з��������ӵ�ɾ����

}




