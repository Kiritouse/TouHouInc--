#include "GameManager.h"
GameState gameState;
Interface _inerface;
BulletNode* ListBullet;
Map _map;
Player _player;
BulletNode* plane_bullet_list = NULL;//飞机子弹列表的头节点
void Awake() {

	gameState = gaming;
	_inerface.InitGraphInterface();

}
void Paint() {

	cleardevice();



}



void Gaming() {
	clock_t t0 = clock();
	clock_t t1;
	int command;
	BeginBatchDraw();
	while (gameState == gaming) {
		t1 = clock();
		if (t1 - t0 >= 10) {
			frame.f_total++;
		}
		else continue;
		//if (gameState != pause && gameState != gameOver) {
		_map.updatePainting();
		_player.updateImage();
		paintBullet();
		ctrlFps();
		command = GetInput();
		_map.updateMapPosition();
		_player.updatePosition(command);
		dealInput_Fire(command, frame.f_total);
		FlushBatchDraw();
		//} 
		Sleep(1);

	}
	EndBatchDraw();
}