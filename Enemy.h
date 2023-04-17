#pragma once
#include "FrameManager.h"
#define PI 3.1415926
#define DEF_MOVE_STOP 0
#define DEF_MOVE_LINE 1//���Ե��ƶ���ʽ
#define DEF_MOVE_CIRCLE 2//Բ���ε��ƶ���ʽ
#define DEF_MOVE_RAND 3//��������ƶ�


struct  EnemyNode
{
	int x, y, x0, y0;

	int health;//����ֵ

	int moveMode;//��ʼ���ƶ���ʽ,����������
	double radian;//ƫת��


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
/// ��������ͷ�巨
/// </summary>
/// <param name="pp_Enemy_List_Node">��άָ�룬ȡһλ��ʾ����ڵ㣬ȡ��ά���Է��ʽڵ��е�����</param>
/// <param name="newNode">һάָ�룬�½��Ľڵ�</param>
EnemyNode* createEnemy(int health, int weaponLevel, int x0, int y0, double radian, int moveMode, int speed, EnemyName name, Frame frame);
void Enemy_listPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
/// <summary>
/// ���µл���λ��
/// </summary>
/// <param name="pp_Enemy_List_Node_Head">���ел������ɵ�����</param>
/// <param name="name">�л�����</param>
/// <param name="frame">����֡�����ǻ�ѡ��ͬ���ƶ���ʽ</param>
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);
void moveLine(EnemyNode* cur, int speed, double radian, int frameBuffer, EnemyName name);
/// <summary>
/// ����Բ�����ƶ�
/// </summary>
/// <param name="cur"></param>
/// <param name="r">Բ���İ뾶</param>
/// <param name="x0">��ʼ��</param>
/// <param name="y0">��ʼ��</param>
/// <param name="xo">�ƶ���Բ����Բ��</param>
/// <param name="yo">�ƶ���Բ����Բ��</param>
/// <param name="speed">ÿһ֡�������յ��ֱ�߾���</param>
/// <param name="frameBuffer"></param>
/// <param name="name"></param>
void moveCircle(EnemyNode* cur, int r, int x0, int y0, int xo, int yo, int speed, int frameBuffer, EnemyName name);
void moveRand(EnemyNode* cur, int speed, EnemyName name);
void update_EnemyImage(EnemyNode** p_Enemy_List, EnemyName name);
int num_Enemies();//��ȡ�ڳ��л�������
void listRemoveNode_Enemy(EnemyNode** pp_Enemy_List_Node_Head);







