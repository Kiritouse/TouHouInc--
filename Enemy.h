#pragma once
#include "FrameManager.h"
#define PI 3.1415926
#define DEF_MOVE_STOP 0
#define DEF_MOVE_LINE 1//���Ե��ƶ���ʽ
#define DEF_MOVE_CIRCLE 2//Բ���ε��ƶ���ʽ
#define DEF_MOVE_RAND 3//��������ƶ�


struct  EnemyNode
{
	int type_enemy0 = 0, type_enemy1 = 0;
	int x, y;//��ʼ������ɫ��λ����Ϣ,x,yΪÿ���ƶ���λ��

	int moveMode;//��ʼ���ƶ���ʽ,����������
	int xo, yo, r;//���ڻ����ƶ������������xo��yoΪԲ��,rΪ�뾶
	double radian;//ƫת�ǣ�����ֱ���ƶ�������ƶ�

	int health;//����ֵ

	int f_create;//�����ý�ɫʱ��֡��

	int width;//ģ�͵Ŀ��
	int height;

	int hitpoints;//�˺�ֵ
	int speed;
	int weaponLevel;//�����ĵȼ�����ʵ�����ӵ�������

	int isExist;//�����Ƿ���Ҫ����

	EnemyNode* pnext;//ָ����һ���ڵ��ָ��
};
enum EnemyName {
	ENEMY0,
	ENEMY1,
	BOSS,
};
/// <summary>
/// ֱ���ƶ�ʱ�ĳ�ʼ��
/// </summary>
/// <param name="x0">��������ʱ����ʼ��</param>
/// <param name="y0">��������ʱ����ʼ��</param>
/// <param name="moveMode">�ƶ���ʽ</param>
/// <param name="radian">ֱ���ƶ���ƫת�ǣ���ˮƽ����Ϊ��㣬��ʱ����ת</param>
/// <param name="speed">�ٶ�</param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, double radian, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
/// <summary>
/// ����ƶ�ʱ�ĳ�ʼ��
/// </summary>
/// <param name="x0"></param>
/// <param name="y0"></param>
/// <param name="moveMode"></param>
/// <param name="speed"></param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
/// <summary>
/// �����ƶ�ʱ�ĳ�ʼ��
/// </summary>
/// <param name="x0">��������ʱ����ʼ��</param>
/// <param name="y0">��������ʱ����ʼ��</param>
/// <param name="moveMode">�ƶ���ʽ</param>
/// <param name="xo">�����ƶ�ʱ��Բ��</param>
/// <param name="yo">�����ƶ�ʱ��Բ��</param>
/// <param name="r">Բ���ƶ��İ뾶</param>
/// <param name="speed">ÿ���ƶ����ٶ�</param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, int xo, int yo, int r, int speed, EnemyName name, int health, int weaponLevel, Frame frame);
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








