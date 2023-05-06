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
GameState gameState;
Interface OBJ_interface;
Map OBJ_Map;
Player OBJ_Player;
EnemyBullet OBJ_EnemyBullet;
Enemy OBJ_Enemy;
Frame frame(0, 0, 0, 0);
BulletNode* p_Player_Bullet_List_Node = NULL;//飞机子弹列表的头节点
//EnemyBulletNode* p_Enemy_Bullet_List_Node = NULL;//敌机子弹列表头节点
//EnemyNode* p_Enemy_List_Node = NULL;
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
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, randFireOn, rand() % (WIDTH_MAP / 5 * 4 - WIDTH_MAP / 5 + 1) + WIDTH_MAP / 5, 3, DEF_MOVE_LINE, PI / 2, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
	}
	if (deltaFrame_CircleMove == 100) {
		tempFrame_CircleMove = framebuffer;
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, randFireOn, 10, randHeight, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, randFireOn, 400, randHeight + randDelta, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
	}

	switch (framebuffer)
	{
		//每隔40帧创建敌人从天上随机移动下来
		//开局先直线移动
	case 100:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP / 5 * 1, 3, DEF_MOVE_LINE, PI / 2, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;
	case 120:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP / 5 * 2, 3, DEF_MOVE_LINE, PI / 2, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;
	case 140:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP / 5 * 3, 3, DEF_MOVE_LINE, PI / 2, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;
	case 160:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP / 5 * 4, 3, DEF_MOVE_LINE, PI / 2, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;
		//左边出来敌机
	case 300:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 1, DEF_MOVE_LINE, 0.0f, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 2, DEF_MOVE_LINE, 0.0f, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 3, HEIGHT_MAP / 7 * 3, DEF_MOVE_LINE, 0.0f, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;
		//右边出来敌机
	case 500:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 4, DEF_MOVE_LINE, PI, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 5, DEF_MOVE_LINE, PI, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, WIDTH_MAP - 50, HEIGHT_MAP / 7 * 6, DEF_MOVE_LINE, PI, 2, OBJ_Enemy.ENEMY0, 50, 0, frame));
		break;

		//飞机向着右边和向着左边弧形移动
	case 600:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 620:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 640:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 660:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 680:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 700:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
	case 720:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 10, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_RIGHT, 10, 10, 0.0f, 0.00625, OBJ_Enemy.ENEMY1, 100, 0, frame));
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 20, 400, HEIGHT_MAP / 2, DEF_MOVE_CIRCLE_LEFT, 400, 10, 0.0f, PI / 500, OBJ_Enemy.ENEMY1, 100, 0, frame));
		break;
		//开始随机移动
	case 800:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 50, rand() % (WIDTH_MAP / 3 * 2 - WIDTH_MAP / 3 + 1) + WIDTH_MAP / 3, 20, DEF_MOVE_RAND, 6.0f, OBJ_Enemy.ENEMY0, 100, 0, frame));
		break;
	case 840:
		OBJ_Enemy.Enemy_ListPushHead(&OBJ_Enemy.p_Enemy_List_Node, OBJ_Enemy.createEnemy(1, 50, rand() % (WIDTH_MAP / 3 * 2 - WIDTH_MAP / 3 + 1) + WIDTH_MAP / 3, 20, DEF_MOVE_RAND, 6.0f, OBJ_Enemy.ENEMY0, 100, 0, frame));
		break;








	}
}

void Awake() {
	OBJ_EnemyBullet.p_Enemy_Bullet_List_Node = NULL;
	OBJ_Enemy.p_Enemy_List_Node = NULL;
	OBJ_interface.InitGraphInterface();
}
void update_Paintings(int framebuffer) {
	BeginBatchDraw();
	cleardevice();
	OBJ_Map.update_MapImage();
	OBJ_interface.paintGameInterface();
	OBJ_Player.update_PlayerImage(framebuffer);
	update_BulletImage(&p_Player_Bullet_List_Node);
	OBJ_Enemy.update_EnemyImage(&OBJ_Enemy.p_Enemy_List_Node);
	OBJ_EnemyBullet.update_EnemyBulletImage(&OBJ_EnemyBullet.p_Enemy_Bullet_List_Node);
	update_Particle();
	cal_FPS();
	EndBatchDraw();
}

void Update() {//帧更新
	int framebuffer;
	while (gameState.gaming == 1) {

		t_update = clock();
		if (t_update - t_begin >= 10) {
			t_begin = t_update;
			frame.f_total++;//总帧数，10ms为一帧
			framebuffer = frame.f_total - frame.f_pause;
		}
		else continue;
		MouseLisenter();//获取鼠标事件
		if (!gameState.pause) {
			update_Paintings(framebuffer);
			AddItem(framebuffer);
			n_command = GetInput();
			OBJ_Map.update_Map();
			OBJ_Player.update_Player(n_command, framebuffer);
			update_Bullet(&OBJ_Enemy.p_Enemy_List_Node, &p_Player_Bullet_List_Node, n_command, framebuffer, 0, -10, 10);
			OBJ_Enemy.update_Enemy(&OBJ_Enemy.p_Enemy_List_Node, frame);
			OBJ_EnemyBullet.update_EnemyBullet(OBJ_Player, &OBJ_Enemy.p_Enemy_List_Node, &OBJ_EnemyBullet.p_Enemy_Bullet_List_Node, 0, 6, 0, 10, framebuffer);
		}
		else {
			OBJ_interface.paintPauseInterface();//存档
		}






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