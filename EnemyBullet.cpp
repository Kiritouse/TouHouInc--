#include "EnemyBullet.h"
#include "Enemy.h"
#define DEF_TYPE_ENEMY0 0//ʶ����˵ı�ʶ��
#define DEF_TYPE_ENEMY1 1
int isFire(EnemyBulletNode* cur, int framebuffer) {//�ж��Ƿ�Ӧ�ÿ���
	if (cur->FireSwitch == 1) {
		if (framebuffer - cur->fire_temp == cur->fire_on)//���֡��֮��Ϊһ��fire_on��ֹͣ���� {
			cur->FireSwitch = 0;
		cur->fire_temp = framebuffer;
	}
	else {
		if (framebuffer - cur->fire_temp == cur->fire_on)//���֡��֮��Ϊһ��fire_on�ͼ������� {
			cur->FireSwitch = 1;
		cur->fire_temp = framebuffer;
	}
	return cur->FireSwitch;
}
EnemyBulletNode* createEnemyBullet(EnemyNode* enemy, int level) {
	EnemyBulletNode* p = new EnemyBulletNode;
	if (enemy->type_enemy0 == 1) p->x = enemy->x + WIDTH_ENEMY0 / 2 - 8;

	else if (enemy->type_enemy1 == 1) p->x = enemy->x + WIDTH_ENEMY1 / 2 - 8;

	p->y = enemy->y;
	p->level = level;//ѡ������ӵ�������
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
void update_EnemyBulletPosition(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, int command, int frameBuffer) {
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head;
	if (cur->FireSwitch == 0) return;

}
