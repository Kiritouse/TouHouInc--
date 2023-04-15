#pragma once
#include "FrameManager.h"
#define PI 3.1415926
//����������ķ��򣬶������������ᣬͨ����ͬ��ƫת�Ƕ���ϳɸ��ַ���
#define DEF_LINEMOVE 0
#define DEF_CIRCLEMOVE 1
struct  EnemyNode
{
	int x, y, x0, y0;

	int health;//����ֵ

	int moveMode;//��ʼ���ƶ���ʽ,����������
	double angle;//ƫת��


	int width;//ģ�͵Ŀ��
	int height;
	int hitpoints;//�˺�ֵ
	int vx, vy;//��x,y�����ϵ�������ʵ���Ͼ����ٶ�
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
EnemyNode* createEnemy(int x0, int y0, double angle, int vx, int vy, EnemyName name);
void Enemy_listPushHead(EnemyNode** pp_Enemy_List_Node, EnemyNode* newNode);
/// <summary>
/// ���µл���λ��
/// </summary>
/// <param name="pp_Enemy_List_Node_Head">���ел������ɵ�����</param>
/// <param name="name">�л�����</param>
/// <param name="frame">����֡�����ǻ�ѡ��ͬ���ƶ���ʽ</param>
void update_EnemyPosition(EnemyNode** pp_Enemy_List_Node_Head, EnemyName name, Frame frame);
void update_EnemyImage(EnemyName name);
int num_Enemies();//��ȡ�ڳ��л�������





