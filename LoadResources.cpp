#include "LoadResources.h"
IMAGE  background, player, playerRight, playerLeft, normalBullets;
void loadResources(void) {
	//���ر���ͼƬ
	loadimage(&background, _T("sources\\Background\\background.png"));

	//�������ﶯ��
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));
	loadimage(&playerRight, _T("sources\\Players\\PlayerRight.png"));
	loadimage(&playerLeft, _T("sources\\Players\\PlayerLeft.png"));

	//�����ӵ�
	loadimage(&normalBullets, _T("sources\\Bullets\\Player\\normalBullets.png"));



}