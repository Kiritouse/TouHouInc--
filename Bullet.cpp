#include "Bullet.h"
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
void addBulletPlayer(int flag, int x, int y) {//在子弹链表中插入子弹
	BulletNode* pNew;
	pNew = new BulletNode;//为生成的新子弹分配内存
	pNew->pnext = ListBullet->pnext;
	pNew->x = x;
	pNew->y = y;
	pNew->width = WIDTH_BULLET0;
	pNew->height = HEIGHT_BULLET0;
	ListBullet->pnext = pNew;

}
void addBulletManagerPlayer(int command) {//控制所有子弹的生成
	//如果说一直开火键位
	if (command & CMD_FIRE) {
		int FrameData_Bullet = frame.f_total - frame.f_pause;
		int xleft, xright, xmid;//定义子弹左右中间上下的坐标
		int ymin, ymax;

		xleft = _player_position.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 - 5;
		xright = _player_position.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 + 5;
		xmid = _player_position.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2;
		ymax = _player_position.y - HEIGHT_BULLET0 + 5;
		ymin = _player_position.y - HEIGHT_BULLET0;
		if ((FrameData_Bullet & 17) == 0) {
			addBulletPlayer(1, xmid, ymin);
		}
	}
	else return;

}

