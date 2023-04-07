#include "LoadResources.h"
IMAGE  background, player, playerRight, playerLeft, normalBullets;
void loadResources(void) {
	//加载背景图片
	loadimage(&background, _T("sources\\Background\\background.png"));

	//加载人物动画
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));
	loadimage(&playerRight, _T("sources\\Players\\PlayerRight.png"));
	loadimage(&playerLeft, _T("sources\\Players\\PlayerLeft.png"));

	//加载子弹
	loadimage(&normalBullets, _T("sources\\Bullets\\Player\\normalBullets.png"));



}