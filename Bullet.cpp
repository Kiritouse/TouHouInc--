#include "Bullet.h"
#include "Operation.h"
#include "FrameManager.h"
#include "Player.h"
#define NORMAL  0
#define UPDATE 1

void moveBullet() {
	BulletNode* iterator = ListBullet->pnext;//顶一个指针，指向子弹节点的下一个节点
	while (iterator != NULL) {//遍历所有的节点
		iterator->y -= 10;//每遍历一个子弹节点就更改一个子弹坐标
		iterator = iterator->pnext;
	}
}
void paintBullet() {
	BulletNode* iterator = ListBullet->pnext;
	while (iterator != NULL) {
		transparentimage_half(NULL, iterator->x, iterator->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 200);
		iterator = iterator->pnext;//指向下一个子弹
	}
}
void addBullet(int flag, int x, int y) {

}
void addBulletManager(int command) {//控制所有子弹的生成
	if (command & CMD_FIRE) {//如果说一直开火键位
		int FrameData_Bullet = frame.f_total - frame.f_pause;
		int xleft, xright, xmid;//定义子弹左右中间上下的坐标
		int ymin, ymax;

		xleft = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 - 5;
		xright = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 + 5;
		xmid = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2;

	}
	else return;
}