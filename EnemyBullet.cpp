#include "EnemyBullet.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
#define DEF_TYPE_ENEMY0 0//ʶ����˵ı�ʶ��
#define DEF_TYPE_ENEMY1 1
#define WIDTH_ENEMYBULLET0 22
#define HEIGHT_ENEMYBULLET0 21

EnemyBulletNode* createEnemyBullet(EnemyNode** pp_Enemy_List_Node_Head, int level, int vx, int vy) {
	if (*(pp_Enemy_List_Node_Head) == NULL)return NULL;
	EnemyBulletNode* p = new EnemyBulletNode;
	if ((*pp_Enemy_List_Node_Head)->type_enemy0 == 1) p->x = (*pp_Enemy_List_Node_Head)->x + WIDTH_ENEMY0 / 2 - 8;

	else if ((*pp_Enemy_List_Node_Head)->type_enemy1 == 1) p->x = (*pp_Enemy_List_Node_Head)->x + WIDTH_ENEMY1 / 2 - 8;

	p->y = (*pp_Enemy_List_Node_Head)->y;
	p->vx = vx;
	p->level = level;//ѡ������ӵ�������
	return p;
}
void EnemyBullet_listPushBack(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, EnemyBulletNode* newNode) {
	if (*pp_Enemy_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���ô�����Ľڵ���ǵ�һ��
	{
		*pp_Enemy_Bullet_List_Node_Head = newNode;
		return;
	}
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head;
	while (cur->pnext != NULL)//�ҵ����һ���ڵ�
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//�����µĽڵ�
}
void update_EnemyBulletPosition(EnemyNode** pp_Enemy_List_Node_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, int framebuffer, int level, int vx, int vy)
{
	if (*pp_Enemy_List_Node_Head == NULL) return;
	if ((*pp_Enemy_List_Node_Head)->FireSwitch == 1) {
		EnemyBullet_listPushBack(pp_Enemy_Bullet_List_Node_Head, createEnemyBullet(pp_Enemy_List_Node_Head, level, vx, vy));
	}
	if (*pp_Enemy_Bullet_List_Node_Head == NULL) return;
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head;
	while (cur != NULL) {
		cur->x += cur->vx;
		cur->y += cur->vy;
		if (cur->y < -20 || (cur->y > HEIGHT_MAP) || (cur->x > WIDTH_MAP) || (cur->y < -20))
			cur->isExist = 0;
		cur = cur->pnext;
	}
}
void listRemoveNode_EnemyBullet(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head)
{
	if (*pp_Enemy_Bullet_List_Node_Head == NULL)//�������Ϊ�գ���û�п�ɾ���Ľڵ���
		return;
	EnemyBulletNode* curP = *pp_Enemy_Bullet_List_Node_Head;//curret��ָ���һ���ڵ�
	EnemyBulletNode* prevP = NULL;  //previousָ����һ���ڵ��ָ��
	while (curP != NULL)//��������
	{
		if (curP->isExist == 0)
		{
			if (*pp_Enemy_Bullet_List_Node_Head == curP)
			{
				*pp_Enemy_Bullet_List_Node_Head = curP->pnext;
				free(curP);
				curP = *pp_Enemy_Bullet_List_Node_Head;
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
void update_EnemyBulletImage(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head) {
	for (EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head; cur != NULL; cur = cur->pnext)
	{
		transparentimage_half(NULL, cur->x, cur->y, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0,
			0, 0, WIDTH_ENEMYBULLET0, HEIGHT_ENEMYBULLET0, &enemyBullet0, 150);
	}
}
void update_EnemyBullet(EnemyNode** pp_Enemy_List_Node_Head, EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, int framebuffer, int level, int vx, int vy) {
	update_EnemyBulletPosition(pp_Enemy_List_Node_Head, pp_Enemy_Bullet_List_Node_Head, framebuffer, level, vx, vy);
	listRemoveNode_EnemyBullet(pp_Enemy_Bullet_List_Node_Head);
	update_EnemyBulletImage(pp_Enemy_Bullet_List_Node_Head);
}
