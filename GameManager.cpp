#include "GameManager.h"
#include "LoadResources.h"
#include <graphics.h>
#include <Windows.h>
#include <time.h>
#include "Interface.h"
#include "Map.h"
#include "Player.h"
#include "Operation.h"
#include "FrameManager.h"
#include <iostream>
GameState gameState;
Interface _inerface;

Map _map;
Player _player;

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

void Gaming() {
	clock_t t0 = clock();
	clock_t t1;
	f_total = f_resume = f_zawarudo = f_pause = 0;
	while (gameState == gaming) {
		t1 = clock();
		if (t1 - t0 >= 10) {
			f_total++;
		}
		else continue;
		Paint();
		if (gameState != pause && gameState != gameOver) {
			_map.updateMapPosition();
			_player.updatePosition(GetInput());
		}
		Sleep(1);

	}
}