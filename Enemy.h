#pragma once

struct  EnemyNode
{
	int x, y, x0, y0;
	int up;
	int down;
	int left;
	int right;
	double angle;//ƫת��
	int health;//����ֵ

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
EnemyNode* createEnemy(int x0, int y0, double angle, int vx, int vy, EnemyName name);
void update_EnemyPosition(EnemyName name);
void update_EnemyImage(EnemyName name);
int num_Enemies();//��ȡ�ڳ��л�������





