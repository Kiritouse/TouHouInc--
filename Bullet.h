#pragma once
#define WIDTH_BULLET0 12
#define HEIGHT_BULLET0 44
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
void listPushBack(BulletNode** pplist, BulletNode* newNode);//β��һ������
BulletNode* creatPlaneBullet(float vx, float vy);//�ɻ�ÿ����һ���ӵ�����һ���ڵ�
void listChangeXY(BulletNode** pplist);//�޸����������нڵ������
void listRemoveNode(BulletNode** pplist);//ɾ��������isExistΪ0�Ľڵ�
void paintBullet();
