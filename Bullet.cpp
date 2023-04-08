#include "Bullet.h"
#define NORMAL  0
#define UPDATE 1

void moveBullet() {
	BulletNode* iterator = ListBullet->pnext;//��һ��ָ�룬ָ���ӵ��ڵ����һ���ڵ�
	while (iterator != NULL) {//�������еĽڵ�
		iterator->y -= 10;//ÿ����һ���ӵ��ڵ�͸���һ���ӵ�����
		iterator = iterator->pnext;
	}
}
void paintBullet() {
	BulletNode* iterator = ListBullet->pnext;
	while (iterator != NULL) {
		transparentimage_half(NULL, iterator->x, iterator->y, WIDTH_BULLET0, HEIGHT_BULLET0,
			0, 0, WIDTH_BULLET0, HEIGHT_BULLET0, &normalBullets, 200);
		iterator = iterator->pnext;//ָ����һ���ӵ�
	}
}
void addBulletPlayer(int flag, int x, int y) {//���ӵ������в����ӵ�
	BulletNode* pNew;
	pNew = new BulletNode;//Ϊ���ɵ����ӵ������ڴ�
	pNew->pnext = ListBullet->pnext;
	pNew->x = x;
	pNew->y = y;
	pNew->width = WIDTH_BULLET0;
	pNew->height = HEIGHT_BULLET0;
	ListBullet->pnext = pNew;

}
void addBulletManagerPlayer(int command) {//���������ӵ�������
	//���˵һֱ�����λ
	if (command & CMD_FIRE) {
		int FrameData_Bullet = frame.f_total - frame.f_pause;
		int xleft, xright, xmid;//�����ӵ������м����µ�����
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

