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
	//std::cout << framebuffer << std::endl;

	switch (framebuffer)
	{
		//开局先直线移动
	/*case 100:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP / 5 * 1, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 1000, 0, frame));
		break;
	case 120:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP / 5 * 2, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 1000, 0, frame));
		break;
	case 140:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP / 5 * 3, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 1000, 0, frame));
		break;
	case 160:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP / 5 * 4, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 1000, 0, frame));
		break;
		//左边出来敌机
	case 300:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(3, HEIGHT_MAP / 7 * 1, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 1000, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(3, HEIGHT_MAP / 7 * 2, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 1000, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(3, HEIGHT_MAP / 7 * 3, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 1000, 0, frame));
		break;
		//右边出来敌机
	case 400:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP - 50, HEIGHT_MAP / 7 * 4, DEF_MOVE_LINE, PI, 2, ENEMY0, 1000, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP - 50, HEIGHT_MAP / 7 * 5, DEF_MOVE_LINE, PI, 2, ENEMY0, 1000, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(WIDTH_MAP - 50, HEIGHT_MAP / 7 * 6, DEF_MOVE_LINE, PI, 2, ENEMY0, 1000, 0, frame));
		break;

		//飞机左边出来弧形移动
	case 500:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 520:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 540:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 560:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 580:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 600:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	case 620:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(20, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, PI / 2, 0.00625, ENEMY1, 100, 0, frame));
		break;
	//飞机从右边出来的弧形移动*/
	case 10:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE, 10, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));





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