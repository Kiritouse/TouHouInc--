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
	int x, y;//子弹坐标
	int xo, yo;//子弹发射时的位置
	int frame_create;//记录创建时的帧数
	int fire_on, fire_off;//记录开火时的帧数间隔
	int FireSwitch;//是否开火，对敌机实现间歇性射击
	int dx, dy;//x和y方向上的速度，也就是增量,便于实现分叉
	bool isExist;//判断子弹是否需要删除
	int hit;
	int width, height;
	BulletNode* pnext;//指向下一个子弹节点的指针
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
extern BulletNode* ListBullet;
extern Player _player;
extern Player::Position _player_position;
/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
void Paint();

/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


