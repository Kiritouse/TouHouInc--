#include "Player.h"
#include "Draw.h"
#include "Operation.h"
#define WIDTH_PLAYER  28
#define HEIGHT_PLAYER  50
struct orimg {
	int x = 3, y = 0;
}originPoint_img;
Player playerObject;
Player::Position position;
Player::Direction direction;
Player::ObjectState playerState;
Player::Player() {
	Flyers Wingman[4]{};//4¸öÁÅ»ú
	position.x = 300;
	position.y = 970;
	health = 100;
	playerState = Live;
	playerObject.speed = 5;
	direction.up = 0;
	direction.down = 0;
	direction.left = 0;
	direction.right = 0;

}
void updatePosition(int _cmd) {
	if (_cmd & CMD_UP && position.y >= 0) {
		direction.up = 1;
		position.y -= playerObject.speed;
	}
	else direction.up = 0;
	if (_cmd & CMD_DOWN && position.y < HEIGHT_MAP - HEIGHT_PLAYER) {
		direction.down = 1;
		position.y += playerObject.speed;
	}
	else direction.down = 0;

	if (_cmd & CMD_LEFT && position.x >= 0) {
		direction.left = 1;
		position.x -= playerObject.speed;
	}
	else direction.left = 0;
	if (_cmd & CMD_RIGHT && position.x < WIDTH_MAP - WIDTH_PLAYER) {
		direction.right = 1;
		position.x += playerObject.speed;
	}
	else direction.right = 0;

}
void Player::updateImage() {

	transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER, originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	//putimage(position.x, position.y, &RenderTexture);

}
