#include "Player.h"
#include "Draw.h"
#include "Operation.h"
#include <iostream>
#include "FrameManager.h"
#include <iostream>
#include <time.h>

struct orimg {
	int x = 3, y = 0;
}originPoint_img;
Player::Position position;
Player::Direction direction;
Player::ObjectState playerState;
int leftbuffer, rightbuffer, tempframe;
Player::Player() {
	Flyers Wingman[4]{};//4¸öÁÅ»ú
	speed = 5;
	position.x = 240;
	position.y = 670;
	health = 100;
	playerState = Live;
	direction.up = 0;
	direction.down = 0;
	direction.left = 0;
	direction.right = 0;
}
void Player::updatePosition(int _cmd) {
	tempframe = frame.f_total - frame.f_pause;
	if (_cmd & CMD_UP && position.y >= 0) {
		direction.up = 1;
		position.y -= speed;
	}
	else direction.up = 0;
	if (_cmd & CMD_DOWN && position.y < HEIGHT_MAP - HEIGHT_PLAYER) {
		direction.down = 1;
		position.y += speed;
	}
	else direction.down = 0;

	if (_cmd & CMD_LEFT && position.x >= 0) {
		direction.left = 1;
		position.x -= speed;
		leftbuffer = tempframe;
	}
	else direction.left = 0;
	if (_cmd & CMD_RIGHT && position.x < WIDTH_MAP - WIDTH_PLAYER) {
		direction.right = 1;
		position.x += speed;
		rightbuffer = tempframe;
	}
	else direction.right = 0;
}

void Player::updateImage() {
	if (health = 0) return;
	int t2 = frame.f_total - frame.f_pause;
	int frameBuffer = t2 - tempframe;
	transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
		originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	if (direction.up - direction.down > 0) {
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				36, 0, WIDTH_PLAYER, HEIGHT_PLAYER_RIGHT, &player);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				68, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				100, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				132, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				164, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				196, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				223, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	}
	if (direction.right - direction.left > 0) {
		frameBuffer = t2 - rightbuffer;

		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				33, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				64, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				96, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				128, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				160, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				192, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				223, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
	}
	else if (direction.right - direction.left) {
		frameBuffer = t2 - leftbuffer;
		if (frameBuffer >= 0 && frameBuffer < 5)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				36, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 5 && frameBuffer < 10)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				68, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 10 && frameBuffer < 15)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				99, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 15 && frameBuffer < 20)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				132, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 20 && frameBuffer < 25)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				164, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 25 && frameBuffer < 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				196, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 30)
			transparentimage(NULL, position.x, position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				228, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);

	}



}
