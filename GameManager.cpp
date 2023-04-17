#include "GameManager.h"
#define PI 3.1415926
GameState E_TYPE_GAMESTATE;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
Frame frame(0, 0, 0, 0, 0);
BulletNode* p_Player_Bullet_List_Node = NULL;//�ɻ��ӵ��б��ͷ�ڵ�
EnemyNode* p_Enemy_List_Node = NULL;
clock_t t_begin = clock();
clock_t t_update;
int  n_command;//
void AddItem(int framebuffer) {
	switch (framebuffer)
	{
	case 200:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(100, 0, 0, 0, 0, DEF_MOVE_CIRCLE, 5, ENEMY0, frame));
		break;
	case 300:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(100, 0, 100, 100, PI / 4, DEF_MOVE_LINE, 7, ENEMY0, frame));
		break;
	case 400:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(100, 0, 200, 200, 0, DEF_MOVE_RAND, 7, ENEMY0, frame));
		break;
	default:
		break;
	}

}
void Awake() {

	E_TYPE_GAMESTATE = gaming;
	OBJ_interface.InitGraphInterface();
}
void Update() {//֡����
	int framebuffer;
	while (E_TYPE_GAMESTATE == gaming) {
		t_update = clock();
		if (t_update - t_begin >= 10) {
			frame.f_total++;//��֡����10msΪһ֡
			framebuffer = frame.f_total - frame.f_pause;
		}
		else continue;
		AddItem(framebuffer);

		n_command = GetInput();

		OBJ_Map.update_MapPosition();
		OBJ_Player.update_PlayerPosition(n_command, frame.f_total, frame.f_pause);

		//�ƶ����˵�λ��
		update_EnemyPosition(&p_Enemy_List_Node, frame);
		listRemoveNode_Enemy(&p_Enemy_List_Node);

		update_BulletPosition(&p_Player_Bullet_List_Node, n_command, frame.f_total);//�����ӵ��µ�λ��
		listRemoveNode_Bullet(&p_Player_Bullet_List_Node);//������Ұ���߻��з��������ӵ�ɾ����


		OBJ_Map.update_MapImage();
		OBJ_Player.update_PlayerImage(frame.f_total, frame.f_pause);
		update_BulletImage(&p_Player_Bullet_List_Node);
		update_EnemyImage(&p_Enemy_List_Node, ENEMY0);
		cal_FPS();

		FlushBatchDraw();
		Sleep(10);
	}
}



void Gaming() {
	BeginBatchDraw();
	Update();

	EndBatchDraw();
}