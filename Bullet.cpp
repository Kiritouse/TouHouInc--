#include "Bullet.h"
#include "Operation.h"
#include "FrameManager.h"
#include "Player.h"
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
void addBullet(int flag, int x, int y) {

}
void addBulletManager(int command) {//���������ӵ�������
	if (command & CMD_FIRE) {//���˵һֱ�����λ
		int FrameData_Bullet = frame.f_total - frame.f_pause;
		int xleft, xright, xmid;//�����ӵ������м����µ�����
		int ymin, ymax;

		xleft = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 - 5;
		xright = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2 + 5;
		xmid = _player.x + WIDTH_PLAYER / 2 - WIDTH_BULLET0 / 2;

	}
	else return;
}