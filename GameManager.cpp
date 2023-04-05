#include "GameManager.h"
#include "LoadResources.h"
#include <graphics.h>
#include <Windows.h>
#include "Interface.h"
#include "Map.h"
#include "Player.h"
GameState gameState;
Interface _inerface;
Map _map;
Player _player;
void Awake() {

	gameState = gaming;
	_inerface.InitGraphInterface();

}
void Gaming() {
	BeginBatchDraw();
	_map.updateMapPosition();
	_map.updatePainting();
	_player.updateImage();
	EndBatchDraw();


}