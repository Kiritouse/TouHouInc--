#include "LoadResources.h"
#include "Bullet.h"
#include "Music.h"
IMAGE  background, player, playerRight, playerLeft, normalBullets, enemy0, enemyBullet0, enemy1, boss;
SOUND bgm;

void loadResources(void) {
	//加载背景图片
	loadimage(&background, _T("sources\\Background\\background.png"));


	//加载人物动画
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));
	loadimage(&playerRight, _T("sources\\Players\\PlayerRight.png"));
	loadimage(&playerLeft, _T("sources\\Players\\PlayerLeft.png"));

	//加载子弹
	loadimage(&normalBullets, _T("sources\\Players\\Bullets\\Player\\normalBullets.png"));

	//加载敌人
	loadimage(&enemy0, _T("sources\\Enemy\\Enemy0.png"));
	loadimage(&enemy1, _T("sources\\Enemy\\Enemy1.png"));
	loadimage(&boss, _T("sources\\Enemy\\Boss.png"));
	loadimage(&enemyBullet0, _T("sources\\Enemy\\EnemyBullets\\EnemyBullet0.png"));

	//加载背景音乐
	loadsound(&bgm, _T("sources\\Music\\BGM\\Weight_of_the_World.mp3"));




}