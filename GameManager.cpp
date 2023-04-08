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
	ListBullet = new BulletNode;//Ϊ�ҷ��л������ڴ�
	ListBullet->pnext = NULL;
}

void Delete(int flag) {
	BulletNode* pnext;//ָ��
	BulletNode* pInRule;//ָ��Ϸ��Ľڵ�
	pnext = ListBullet->pnext;
	pInRule = ListBullet;
	switch (flag) {
	case 0:


	case 1:
		while (pnext != NULL) {//һ��Ҫ��ǰ�ж�
			if (pnext->y <= -pnext->height)//ֱ���ӵ�β��������Ļ��������ɾ��
			{
				pInRule->pnext = pnext->pnext;//ɾ��������Χ����һ���ӵ�
				free(pnext);
				pnext = nullptr;
			}
			else pInRule = pnext;//����ڷ�Χ��Ͱ���һ���ڵ���ӵ������Ϸ�����
			pnext = pInRule->pnext;
		}

	}

}

void Gaming() {
	CreateList();//��������
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
			moveBullet();//����ָ���ƶ��ӵ�

		}
		Sleep(1);

	}
}