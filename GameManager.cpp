#include "GameManager.h"
GameState E_TYPE_GAMESTATE;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
Frame frame(0, 0, 0, 0);
BulletNode* Player_Bullet_List = NULL;//飞机子弹列表的头节点
clock_t t_begin = clock();
clock_t t_update;
int  n_command;//
void Awake() {

	E_TYPE_GAMESTATE = gaming;
	OBJ_interface.InitGraphInterface();

}
void Update() {//帧更新

	while (E_TYPE_GAMESTATE == gaming) {
		t_update = clock();
		if (t_update - t_begin >= 10) {
			frame.f_total++;//总帧数，10ms为一帧
		}
		else continue;
		n_command = GetInput();

		OBJ_Map.update_MapPosition();
		OBJ_Player.update_PlayerPosition(n_command);
		update_BulletPosition(&Player_Bullet_List, n_command, frame.f_total);//计算子弹新的位置
		listRemoveNode(&Player_Bullet_List);//超出视野或者击中飞行器的子弹删除掉


		OBJ_Map.update_MapImage();
		OBJ_Player.update_PlayerImage();
		update_BulletImage();

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