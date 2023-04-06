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
GameState gameState;
Interface _inerface;
FrameManager _frameManager;
Map _map;
Player _player;

void Awake() {

	gameState = gaming;
	_inerface.InitGraphInterface();

}
void DrawImage() {
	_map.updateMapPosition();
	_map.updatePainting();
	_player.updatePosition(GetInput());
	_player.updateImage();
	_frameManager.ctrlFps();
	FlushBatchDraw();
}

void Gaming() {

}