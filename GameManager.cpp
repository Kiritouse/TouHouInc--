#include "GameManager.h"
GameState gameState;
Interface _inerface;
BulletNode* ListBullet;
Map _map;
Player _player;
Player::Position _player_position;
void Awake() {

	gameState = gaming;
	_inerface.InitGraphInterface();

}
void Paint() {
	BeginBatchDraw();
	cleardevice();
	_map.updatePainting();
	_player.updateImage();
	ctrlFps();
	EndBatchDraw();
}
void CreateList() {
	ListBullet = new BulletNode;//为我方敌机分配内存
	ListBullet->pnext = NULL;
}

void Delete(int flag) {
	BulletNode* pnext;//指向
	BulletNode* pInRule;//指向合法的节点
	pnext = ListBullet->pnext;
	pInRule = ListBullet;
	switch (flag) {
	case 0:


	case 1:
		while (pnext != NULL) {//一定要提前判断
			if (pnext->y <= -pnext->height)//直到子弹尾部超出屏幕纵坐标后才删除
			{
				pInRule->pnext = pnext->pnext;//删除超出范围的下一颗子弹
				free(pnext);
				pnext = nullptr;
			}
			else pInRule = pnext;//如果在范围里，就把下一个节点的子弹当作合法数据
			pnext = pInRule->pnext;
		}

	}

}

void Gaming() {
	CreateList();//创建链表
	clock_t t0 = clock();
	clock_t t1;
	int command;
	while (gameState == gaming) {
		t1 = clock();
		if (t1 - t0 >= 10) {
			frame.f_total++;
		}
		else continue;
		Paint();
		if (gameState != pause && gameState != gameOver) {

			command = GetInput();
			_map.updateMapPosition();
			_player.updatePosition(command);
			moveBullet();//根据指令移动子弹

		}
		Sleep(1);

	}
}