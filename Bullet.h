#pragma once
struct BulletNode
{
	float x, y;
	float vx, vy;
	int hitpoint;
	int isExist;//�ж��ӵ��Ƿ���Ҫɾ��
	BulletNode* pnext;
};
//����һ�£�����ʵ���Ͼ��൱��һ����ά����
//һάָ���൱��ָ��ĳһ���ڵ㣬��άָ����൱��ָ��ĳһ�ڵ��е�ĳһ������

void update_Bullet(BulletNode** pp_Player_Bullet_List_Head, int command, int frameBuffer);
