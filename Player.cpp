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
int leftOpFramebuffer, rightOpFramebuffer, upOpFramebuffer, downOpFramebuffer, tempframe;
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
void Player::update_PlayerPosition(int _cmd, int framebuffer) {
	if (_cmd & CMD_UP && Struct_Position.y >= 0) {
		Struct_Direction.up = 1;
		Struct_Position.y -= speed;
		upOpFramebuffer = framebuffer;//记录下当前按下左键操作的时间
	}
	else Struct_Direction.up = 0;
	if (_cmd & CMD_DOWN && Struct_Position.y < HEIGHT_MAP - HEIGHT_PLAYER) {
		Struct_Direction.down = 1;
		Struct_Position.y += speed;
		downOpFramebuffer = framebuffer;
	}
	else Struct_Direction.down = 0;

	if (_cmd & CMD_LEFT && Struct_Position.x >= 0) {
		Struct_Direction.left = 1;
		Struct_Position.x -= speed;
		leftOpFramebuffer = framebuffer;//记录下当前按下左键操作的时间
	}
	else Struct_Direction.left = 0;
	if (_cmd & CMD_RIGHT && Struct_Position.x < WIDTH_MAP - WIDTH_PLAYER) {
		Struct_Direction.right = 1;
		Struct_Position.x += speed;
		rightOpFramebuffer = framebuffer;
	}
	else Struct_Direction.right = 0;
}

void Player::update_PlayerImage(int frameBuffer) {//
	if (health = 0) return;
	transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
		originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	if (Struct_Direction.up - Struct_Direction.down > 0) {
		frameBuffer = frameBuffer - upOpFramebuffer;
		if (frameBuffer >= 0 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				36, 0, WIDTH_PLAYER, HEIGHT_PLAYER_RIGHT, &player);
		if (frameBuffer >= 10 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				68, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 20 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				100, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 30 && frameBuffer < 40)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				132, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 40 && frameBuffer < 50)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				164, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 50 && frameBuffer < 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				196, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
		if (frameBuffer >= 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER, HEIGHT_PLAYER,
				223, 0, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	}
	if (Struct_Direction.right - Struct_Direction.left > 0) {
		frameBuffer = frameBuffer - rightOpFramebuffer;

		if (frameBuffer >= 0 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				33, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 10 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				64, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 20 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				96, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 30 && frameBuffer < 40)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				128, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 40 && frameBuffer < 50)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				160, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 50 && frameBuffer < 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				192, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
		if (frameBuffer >= 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT,
				223, 0, WIDTH_PLAYER_RIGHT, HEIGHT_PLAYER_RIGHT, &playerRight);
	}
	else if (Struct_Direction.right - Struct_Direction.left) {
		frameBuffer = frameBuffer - leftOpFramebuffer;
		if (frameBuffer >= 0 && frameBuffer < 10)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				36, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 10 && frameBuffer < 20)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				68, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 20 && frameBuffer < 30)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				99, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 30 && frameBuffer < 40)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				132, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 40 && frameBuffer < 50)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				164, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 50 && frameBuffer < 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				196, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);
		if (frameBuffer >= 60)
			transparentimage(NULL, Struct_Position.x, Struct_Position.y, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT,
				228, 0, WIDTH_PLAYER_LEFT, HEIGHT_PLAYER_LEFT, &playerLeft);

	}



}

void Player::update_Player(int n_command, int framebuffer) {
	update_PlayerPosition(n_command, framebuffer);
	update_PlayerImage(framebuffer);
}
