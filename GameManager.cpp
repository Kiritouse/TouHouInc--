#include <Windows.h>
#include <time.h>
#include "GameManager.h"
#include "LoadResources.h"
#include "Interface.h"
#include "Map.h"
#include "Player.h"
#include "Operation.h"
#include "FrameManager.h"
#include "Draw.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Music.h"
#include "ParticleManager.h"
#define PI 3.1415926
GameState E_TYPE_GAMESTATE;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
Frame frame(0, 0, 0, 0);
BulletNode* p_Player_Bullet_List_Node = NULL;//飞机子弹列表的头节点
EnemyBulletNode* p_Enemy_Bullet_List_Node = NULL;//敌机子弹列表头节点
EnemyNode* p_Enemy_List_Node = NULL;
clock_t t_begin = clock();
clock_t t_update;
int  n_command;//获取操作
int deltaFrame_LineMove = 0;
int deltaFrame_CircleMove = 0;
int tempFrame_LineMove = 0;
int tempFrame_CircleMove = 0;
void AddItem(int framebuffer) {
	srand(framebuffer);
	int randFireOn = rand() % 31 + 20;
	int randHeight = rand() % (HEIGHT_MAP / 4 * 3 - HEIGHT_MAP / 4 + 1) + HEIGHT_MAP / 4;
	int randDelta = rand() % 100 - 50;
	deltaFrame_LineMove = framebuffer - tempFrame_LineMove;//tempframe记录上一次调用AddItem函数的时间
	deltaFrame_CircleMove = framebuffer - tempFrame_CircleMove;
	if (deltaFrame_LineMove == 40) {
		tempFrame_LineMove = framebuffer;
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, randFireOn, rand() % (WIDTH_MAP / 5 * 4 - WIDTH_MAP / 5 + 1) + WIDTH_MAP / 5, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 50, 0, frame));
	}
	if (deltaFrame_CircleMove == 100) {
		tempFrame_CircleMove = framebuffer;
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, randFireOn, 10, randHeight, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, randFireOn, 400, randHeight + randDelta, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
	}

	switch (framebuffer)
	{
		//每隔40帧创建敌人从天上随机移动下来
		//开局先直线移动
	case 100:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP / 5 * 1, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 50, 0, frame));
		break;
	case 120:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP / 5 * 2, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 50, 0, frame));
		break;
	case 140:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP / 5 * 3, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 50, 0, frame));
		break;
	case 160:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP / 5 * 4, 3, DEF_MOVE_LINE, PI / 2, 2, ENEMY0, 50, 0, frame));
		break;
		//左边出来敌机
	case 300:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 1, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 50, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 2, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 50, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 3, DEF_MOVE_LINE, 0.0f, 2, ENEMY0, 50, 0, frame));
		break;
		//右边出来敌机
	case 500:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 4, DEF_MOVE_LINE, PI, 2, ENEMY0, 50, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 5, DEF_MOVE_LINE, PI, 2, ENEMY0, 50, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 6, DEF_MOVE_LINE, PI, 2, ENEMY0, 50, 0, frame));
		break;

		//飞机向着右边和向着左边弧形移动
	case 600:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 620:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 640:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 660:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 680:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 700:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
	case 720:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, ENEMY1, 100, 0, frame));
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, ENEMY1, 100, 0, frame));
		break;
		//开始随机移动
	case 800:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 50, rand() % (WIDTH_MAP / 3 * 2 - WIDTH_MAP / 3 + 1) + WIDTH_MAP / 3, 20, DEF_MOVE_RAND, 6.0f, ENEMY0, 100, 0, frame));
		break;
	case 840:
		Enemy_ListPushHead(&p_Enemy_List_Node, createEnemy(1, 50, rand() % (WIDTH_MAP / 3 * 2 - WIDTH_MAP / 3 + 1) + WIDTH_MAP / 3, 20, DEF_MOVE_RAND, 6.0f, ENEMY0, 100, 0, frame));
		break;








	}
}

void Awake() {

	E_TYPE_GAMESTATE = gaming;
	OBJ_interface.InitGraphInterface();
}
void update_Paintings(int framebuffer) {
	BeginBatchDraw();
	cleardevice();
	OBJ_Map.update_MapImage();
	OBJ_Player.update_PlayerImage(framebuffer);
	update_BulletImage(&p_Player_Bullet_List_Node);
	update_EnemyImage(&p_Enemy_List_Node);
	update_EnemyBulletImage(&p_Enemy_Bullet_List_Node);
	update_Particle();
	EndBatchDraw();
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
		update_Bullet(&p_Enemy_List_Node, &p_Player_Bullet_List_Node, n_command, framebuffer, 0, -10, 10);
		update_Enemy(&p_Enemy_List_Node, frame);
		update_EnemyBullet(&p_Enemy_List_Node, &p_Enemy_Bullet_List_Node, 0, 6, 0, 10, framebuffer);

		update_Paintings(framebuffer);

		//cal_FPS();

		//FlushBatchDraw();
		Sleep(20);
	}
}



void Gaming() {
	BeginBatchDraw();
	playsound(0, 1);
	Update();

	EndBatchDraw();
}