#pragma once
#include "FrameManager.h"
#define PI 3.1415926
#define DEF_MOVE_STOP 0
#define DEF_MOVE_LINE 1 //���Ե��ƶ���ʽ
#define DEF_MOVE_CIRCLE_RIGHT 2//Բ���ε��ƶ���ʽ�����ұ��ƶ�
#define DEF_MOVE_CIRCLE_LEFT 3//Բ���ε��ƶ���ʽ��������ƶ�
#define DEF_MOVE_RAND 4//��������ƶ�

#define WIDTH_ENEMY0 40
#define HEIGHT_ENEMY0 59

#define WIDTH_ENEMY1 43
#define HEIGHT_ENEMY1 58

#define WIDTH_BOSS 36
#define HEIGHT_BOSS 56

struct  EnemyNode
{
	int FireSwitch;//�л������λ
	int fire_on;//�����֡����һ���м�����Ĳ�ֵΪfire_on���л�����״̬����ÿ��fire_on֡�Ϳ�һ�λ�

	int type_enemy0 = 0, type_enemy1 = 0, type_boss = 0;
	int x, y, x0, y0;//��ʼ������ɫ��λ����Ϣ,x,yΪÿ���ƶ���λ�ã�x0��y0Ϊ��ʼλ��

	int moveMode;//��ʼ���ƶ���ʽ,����������
	int xo, yo, r;//���ڻ����ƶ������������xo��yoΪԲ��,rΪ�뾶
	double radian;//ƫת�ǣ�����ֱ���ƶ�������ƶ�

	int health;//����ֵ

	int f_create;//�����ý�ɫʱ��֡��

	int width;//ģ�͵Ŀ��
	int height;

	int hitpoints;//�˺�ֵ
	double speed;
	int weaponLevel;//�����ĵȼ�����ʵ�����ӵ�������

	int isExist;//�����Ƿ���Ҫ����

	EnemyNode* pnext;//ָ����һ���ڵ��ָ��
};
enum EnemyName {
	ENEMY0,
	ENEMY1,
	BOSS,
};

EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, double radian, double speed, EnemyName name, int health, int weaponLevel, Frame frame);

EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, double speed, EnemyName name, int health, int weaponLevel, Frame frame);

EnemyNode* createEnemy(int FireSwitch, int fire_on, int x0, int y0, int moveMode, int xo, int yo, double radian, double speed, EnemyName name, int health, int weaponLevel, Frame frame);
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(int ylimit, EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








