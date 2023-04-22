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
EnemyNode* createEnemy(int x0, int y0, int moveMode, double radian, double speed, EnemyName name, int health, int weaponLevel, Frame frame);
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
EnemyNode* createEnemy(int x0, int y0, int moveMode, double speed, EnemyName name, int health, int weaponLevel, Frame frame);
/// <summary>
/// �����ƶ�ʱ�ĳ�ʼ��
/// </summary>
/// <param name="x0">������</param>
/// <param name="y0">������</param>
/// <param name="moveMode">�ƶ���ʽ</param>
/// <param name="xo">Բ������</param>
/// <param name="yo">Բ������</param>
/// <param name="radian">��ʼƫת�ǣ���ˮƽx��ĽǶ�Ϊ0,��ʱ����ת�Ƕ�����</param>
/// <param name="r">�ƶ��뾶</param>
/// <param name="speed"></param>
/// <param name="name"></param>
/// <param name="health"></param>
/// <param name="weaponLevel"></param>
/// <param name="frame"></param>
/// <returns></returns>
EnemyNode* createEnemy(int x0, int y0, int moveMode, int xo, int yo, double radian, double speed, EnemyName name, int health, int weaponLevel, Frame frame);
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








