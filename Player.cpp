#include "Player.h"
#include "Draw.h"
#define WIDTH_PLAYER  28
#define HEIGHT_PLAYER  50
struct orimg {
	int x = 3, y = 0;
}originPoint_img;

Player::Position position;
Player::Direction direction;
Flyers::ObjectState playerState;
Player::Player() {
	Flyers Wingman[4]{};//4¸öÁÅ»ú
	position.x = 300;
	position.y = 970;
	health = 100;
	playerState = Live;
}
void updatePosition() {

}
void Player::updateImage() {

	transparentimage(NULL, position.x, position.y, WIDTH_PLAYER, HEIGHT_PLAYER, originPoint_img.x, originPoint_img.y, WIDTH_PLAYER, HEIGHT_PLAYER, &player);
	//putimage(position.x, position.y, &RenderTexture);

}
