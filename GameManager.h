#pragma once
#include <iostream>
#include <graphics.h>
#include <Windows.h>
#include <time.h>
#include "LoadResources.h"
#include "Interface.h"
#include "Map.h"
#include "Player.h"
#include "Operation.h"
#include "FrameManager.h"
#include "Draw.h"
#include "Bullet.h"
enum GameState
{
	gaming, pause, gameOver
};
struct BulletNode
{
	float x, y;
	float vx, vy;
	int hitpoint;
	int isExist;//判断子弹是否需要删除
	BulletNode* pnext;
};
class Player {
public:
	Player();//构造函数，初始化数据
	int health;
	int speed;
	void updatePosition(int _cmd);
	void updateImage();
	struct Position
	{
		int x, y;
	};
	enum ObjectState
	{
		Live,
		Dead,
		Invulnerable
	};
	struct Direction
	{
		int up;
		int down;
		int left;
		int right;
	};
};
extern GameState gameState;
extern Player _player;
extern Player::Position _player_position;
extern BulletNode* plane_bullet_list;
/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
void Paint();

/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


