#include "LoadResources.h"
#include "Bullet.h"
#include "Music.h"
IMAGE  startbackground, background, player, playerRight, playerLeft, normalBullets, enemy0, enemyBullet0, enemy1, boss, enterbutton, pausebutton, savebutton,continuebutton, powerProp;
SOUND bgm;

void loadResources(void) {
	//���ر���ͼƬ
	loadimage(&background, _T("sources\\Background\\background.png"));
	loadimage(&startbackground, _T("sources\\Background\\ui.png"));

	//����Ui
	loadimage(&pausebutton, _T("sources\\Ui\\Button\\pause.png"));
	loadimage(&enterbutton, _T("sources\\Ui\\Button\\button-enter.png"));
	loadimage(&savebutton, _T("sources\\Ui\\Button\\save.png"));
	loadimage(&continuebutton, _T("sources\\Ui\\Button\\button-continue.png"));

	//���ص���

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

	//���ر�������
	loadsound(&bgm, _T("sources\\Music\\BGM\\Weight_of_the_World.mp3"));







}