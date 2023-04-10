#include "GameManager.h"
GameState E_TYPE_GAMESTATE;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
Frame frame(0, 0, 0, 0);
BulletNode* p_Player_Bullet_List_Node = NULL;//�ɻ��ӵ��б��ͷ�ڵ�
clock_t t_begin = clock();
clock_t t_update;
int  n_command;//
void Awake() {

	E_TYPE_GAMESTATE = gaming;
	OBJ_interface.InitGraphInterface();

}
void Update() {//֡����

	while (E_TYPE_GAMESTATE == gaming) {
		t_update = clock();
		if (t_update - t_begin >= 10) {
			frame.f_total++;//��֡����10msΪһ֡
		}
		else continue;
		n_command = GetInput();

		OBJ_Map.update_MapPosition();
		OBJ_Player.update_PlayerPosition(n_command, frame.f_total, frame.f_pause);
		update_BulletPosition(&p_Player_Bullet_List_Node, n_command, frame.f_total);//�����ӵ��µ�λ��
		listRemoveNode(&p_Player_Bullet_List_Node);//������Ұ���߻��з��������ӵ�ɾ����


		OBJ_Map.update_MapImage();
		OBJ_Player.update_PlayerImage(frame.f_total, frame.f_pause);
		update_BulletImage(p_Player_Bullet_List_Node);

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