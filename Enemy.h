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
void Enemy_ListPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
void update_Enemy(EnemyNode** pp_Enemy_List_Node_Head, Frame frame);








