#include "Player.h"
#include <graphics.h>
#include "FrameManager.h"
#include "Operation.h"
#include "Map.h"
#include "Draw.h"
#include "LoadResources.h"
struct orimg {
	int x = 3, y = 0;
}originPoint_img;
Player::Position  Struct_Position;
;
Player::Direction Struct_Direction;
Player::ObjectState E_TYPE_PlayerState;
int leftbuffer, rightbuffer, tempframe;
Player::Player() {
	speed = 6;
	Struct_Position.x = 240;
	Struct_Position.y = 670;
	health = 100;
	E_TYPE_PlayerState = Live;
	Struct_Direction.up = 0;
	Struct_Direction.down = 0;
	Struct_Direction.left = 0;
	Struct_Direction.right = 0;
}
void Player::update_PlayerPosition(int _cmd, int f_total, int f_pause) {
	tempframe = f_total - f_pause;
	if (_cmd & CMD_UP && Struct_Position.y >= 0) {
		Struct_Direction.up = 1;
		Struct_Position.y -= speed;
	}
	else Struct_Direction.up = 0;
	if (_cmd & CMD_DOWN && Struct_Position.y < HEIGHT_MAP - HEIGHT_PLAYER) {
		Struct_Direction.down = 1;
		Struct_Position.y += speed;
	}
	else Struct_Direction.down = 0;

	if (_cmd & CMD_LEFT && Struct_Position.x >= 0) {
		Struct_Direction.left = 1;
		Struct_Position.x -= speed;
		leftbuffer = tempframe;
	}
	else Struct_Direction.left = 0;
	if (_cmd & CMD_RIGHT && Struct_Position.x < WIDTH_MAP - WIDTH_PLAYER) {
		Struct_Direction.right = 1;
		Struct_Position.x += speed;
		rightbuffer = tempframe;
	}
	else Struct_Direction.right = 0;
}

void Player::update_PlayerImage(int f_total, int f_pause) {
	if (health = 0) return;
	int t2 = f_total - f_pause;
	int frameBuffer = t2 - tempframe;
	transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
		originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	if (Struct_Direction.up - Struct_Direction.down > 0) {
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				36, 0, WIDTH_PLAYER, HEIGHT_PLAYER_RIGHT, &player);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				68, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				100, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				132, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				164, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				196, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				223, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	}
	if (Struct_Direction.right - Struct_Direction.left > 0) {
		frameBuffer = t2 - rightbuffer;

		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				33, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				64, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				96, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				128, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				160, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				192, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				223, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
	}
	else if (Struct_Direction.right - Struct_Direction.left) {
		frameBuffer = t2 - leftbuffer;
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				36, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				68, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				99, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				132, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				164, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				196, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				228, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);

	}



}
