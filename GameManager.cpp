#include "GameManager.h"
#define PI 3.1415926
GameState E_TYPE_GAMESTATE;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
Frame frame(0, 0, 0, 0);
BulletNode* p_Player_Bullet_List_Node = NULL;//飞机子弹列表的头节点
EnemyNode* p_Enemy_List_Node = NULL;
clock_t t_begin = clock();
clock_t t_update;
int  n_command;//
void AddItem(int framebuffer) {
	switch (framebuffer)
	{
	case 200:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(10, HEIGHT_MAP/2, DEF_MOVE_CIRCLE, 1, 1, WIDTH_MAP / 2, 1, ENEMY1, 100, 0, frame));
		break;
	case 220:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, 20, DEF_MOVE_LINE, PI / 2, 5, ENEMY0, 100, 0, frame));
		break;
	case 300:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(15, 15, DEF_MOVE_LINE, PI / 4, 5, ENEMY0, 100, 0, frame));
		break;
	case 400:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(30, 30, DEF_MOVE_RAND, 5, ENEMY0, 100, 0, frame));
		break;
	default:
		break;
	}
}
void Awake() {

	E_TYPE_GAMESTATE = gaming;
	OBJ_interface.InitGraphInterface();
}
void Update() {//帧更新
	int framebuffer;
	while (E_TYPE_GAMESTATE == gaming) {
		t_update = clock();
		if (t_update - t_begin >= 10) {
			frame.f_total++;//总帧数，10ms为一帧
			framebuffer = frame.f_total - frame.f_pause;
		}
		else continue;
		AddItem(framebuffer);
		n_command = GetInput();
		OBJ_Map.update_Map();
		OBJ_Player.update_Player(n_command, framebuffer);
		update_Bullet(&p_Player_Bullet_List_Node, n_command, framebuffer);
		update_Enemy(&p_Enemy_List_Node, frame);

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