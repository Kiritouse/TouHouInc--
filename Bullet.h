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
void dealInput_Fire(int command, int frameBuffer);
BulletNode* creatPlayerBullet(float vx, float vy);//�ɻ�ÿ����һ���ӵ�����һ���ڵ�,��ʼ��ÿ���ڵ������
void Bullet_listPushBack(BulletNode** pp_Player_Bullet_List_Node, BulletNode* newNode);//�������ڵ�����ݲ���������

void update_BulletPosition(BulletNode** pp_Player_Bullet_List_Node, int command, int framebuffer);//�޸����������нڵ������
void listRemoveNode(BulletNode** pp_Player_Bullet_List_Node);//ɾ��������isExistΪ0�Ľڵ�
void update_BulletImage(BulletNode* p_Player_Bullet_List_Node);
