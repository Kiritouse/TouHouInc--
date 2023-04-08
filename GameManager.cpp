#include "GameManager.h"
GameState gameState;
Interface _inerface;
BulletNode* ListBullet;
Map _map;
Player _player;
Player::Position _player_position;
BulletNode* plane_bullet_list = NULL;//飞机子弹列表的头节点
void Awake() {

	gameState = gaming;
	_inerface.InitGraphInterface();

}
void Paint() {
	BeginBatchDraw();
	cleardevice();
	_map.updatePainting();
	_player.updateImage();
	paintBullet();
	ctrlFps();

	EndBatchDraw();
}



void Gaming() {
	clock_t t0 = clock();
	clock_t t1;
	int command;
	while (gameState == gaming) {
		t1 = clock();
		if (t1 - t0 >= 10) {
			frame.f_total++;
		}
		else continue;

		//if (gameState != pause && gameState != gameOver) {

		command = GetInput();
		_map.updateMapPosition();
		_player.updatePosition(command);

		Paint();



		//} 
		Sleep(1);

	}
}