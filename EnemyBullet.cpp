#include "EnemyBullet.h"
#include "Enemy.h"
#define DEF_TYPE_ENEMY0 0//识别敌人的标识符
#define DEF_TYPE_ENEMY1 1
int isFire(EnemyBulletNode* cur, int framebuffer) {//判断是否应该开火
	if (cur->FireSwitch == 1) {
		if (framebuffer - cur->fire_temp == cur->fire_on)//如果帧数之差为一个fire_on就停止开火 {
			cur->FireSwitch = 0;
		cur->fire_temp = framebuffer;
	}
	else {
		if (framebuffer - cur->fire_temp == cur->fire_on)//如果帧数之差为一个fire_on就继续开火 {
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
	p->level = level;//选择敌人子弹的类型
}
void EnemyBullet_listPushBack(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, EnemyBulletNode* newNode) {
	if (*pp_Enemy_Bullet_List_Node_Head == NULL)//如果链表为空，那么新增的节点就是第一个
	{
		*pp_Enemy_Bullet_List_Node_Head = newNode;
		return;
	}
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head;
	while (cur->pnext != NULL)//找到最后一个节点
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//插入新的节点
}
void update_EnemyBulletPosition(EnemyBulletNode** pp_Enemy_Bullet_List_Node_Head, int command, int frameBuffer) {
	EnemyBulletNode* cur = *pp_Enemy_Bullet_List_Node_Head;
	if (cur->FireSwitch == 0) return;

}
