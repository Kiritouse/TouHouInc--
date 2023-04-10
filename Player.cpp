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
Player::Position E_TYPE_Position;
Player::Direction E_TYPE_Direction;
Player::ObjectState E_TYPE_PlayerState;
int leftbuffer, rightbuffer, tempframe;
Player::Player() {
	speed = 6;
	E_TYPE_Position.x = 240;
	E_TYPE_Position.y = 670;
	health = 100;
	E_TYPE_PlayerState = Live;
	E_TYPE_Direction.up = 0;
	E_TYPE_Direction.down = 0;
	E_TYPE_Direction.left = 0;
	E_TYPE_Direction.right = 0;
}
void Player::update_PlayerPosition(int _cmd, int f_total, int f_pause) {
	tempframe = f_total - f_pause;
	if (_cmd & CMD_UP && E_TYPE_Position.y >= 0) {
		E_TYPE_Direction.up = 1;
		E_TYPE_Position.y -= speed;
	}
	else E_TYPE_Direction.up = 0;
	if (_cmd & CMD_DOWN && E_TYPE_Position.y < HEIGHT_MAP - HEIGHT_PLAYER) {
		E_TYPE_Direction.down = 1;
		E_TYPE_Position.y += speed;
	}
	else E_TYPE_Direction.down = 0;

	if (_cmd & CMD_LEFT && E_TYPE_Position.x >= 0) {
		E_TYPE_Direction.left = 1;
		E_TYPE_Position.x -= speed;
		leftbuffer = tempframe;
	}
	else E_TYPE_Direction.left = 0;
	if (_cmd & CMD_RIGHT && E_TYPE_Position.x < WIDTH_MAP - WIDTH_PLAYER) {
		E_TYPE_Direction.right = 1;
		E_TYPE_Position.x += speed;
		rightbuffer = tempframe;
	}
	else E_TYPE_Direction.right = 0;
}

void Player::update_PlayerImage(int f_total, int f_pause) {
	if (health = 0) return;
	int t2 = f_total - f_pause;
	int frameBuffer = t2 - tempframe;
	transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
		originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	if (E_TYPE_Direction.up - E_TYPE_Direction.down > 0) {
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				36, 0, WIDTH_PLAYER, HEIGHT_PLAYER_RIGHT, &player);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				68, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				100, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				132, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				164, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				196, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				223, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	}
	if (E_TYPE_Direction.right - E_TYPE_Direction.left > 0) {
		frameBuffer = t2 - rightbuffer;

		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				33, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				64, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				96, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				128, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				160, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				192, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				223, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
	}
	else if (E_TYPE_Direction.right - E_TYPE_Direction.left) {
		frameBuffer = t2 - leftbuffer;
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				36, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				68, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				99, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				132, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				164, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				196, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 30)
			transparentimage(NULL, E_TYPE_Position.x, E_TYPE_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				228, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);

	}



}
