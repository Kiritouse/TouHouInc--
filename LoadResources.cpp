#include "LoadResources.h"
#include "Bullet.h"
IMAGE  background, player, playerRight, playerLeft, normalBullets, enemy0, enemyBullet0, enemy1, boss;
void loadResources(void) {
	//���ر���ͼƬ
	loadimage(&background, _T("sources\\Background\\background.png"));

	//�������ﶯ��
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));
	loadimage(&playerRight, _T("sources\\Players\\PlayerRight.png"));
	loadimage(&playerLeft, _T("sources\\Players\\PlayerLeft.png"));

	//�����ӵ�
	loadimage(&normalBullets, _T("sources\\Players\\Bullets\\Player\\normalBullets.png"));

	//���ص���
	loadimage(&enemy0, _T("sources\\Enemy\\Enemy0.png"));
	loadimage(&enemy1, _T("sources\\Enemy\\Enemy1.png"));
	loadimage(&boss, _T("sources\\Enemy\\Boss.png"));
	loadimage(&enemyBullet0, _T("sources\\Enemy\\EnemyBullets\\EnemyBullet0.png"));




}