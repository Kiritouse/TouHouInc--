#pragma once
#include "Flyers.h"
#include "GameManager.h"
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
int leverl;//����ʵ��
struct BulletNode
{
	int x, y;//�ӵ�����
	int xo, yo;//�ӵ�����ʱ��λ��
	int frame_create;//��¼����ʱ��֡��
	int fire_on, fire_off;//��¼����ʱ��֡�����
	int FireSwitch;//�Ƿ񿪻𣬶Եл�ʵ�ּ�Ъ�����
	int dx, dy;//x��y�����ϵ��ٶȣ�Ҳ��������,����ʵ�ֲַ�
	bool isExist;//�ж��ӵ��Ƿ���Ҫɾ��
	int hit;
	int width, height;
	BulletNode* pnext;//ָ����һ���ӵ��ڵ��ָ��
};
void moveBullet();
void paintBullet();
void addBullet(int flag, int x, int y);
void addBulletManager(int flag, int x, int y, int command);//�����ӵ�


