#pragma once
#include "Interface.h"
#include "Player.h"
#include "GameManager.h"
#include "FrameManager.h"
#include "Enemy.h"
#include <iostream>
#include <graphics.h>
#pragma
struct GameState
{
	int gaming = 0, pause = 0, gameOver = 0, startUI = 1;
};


extern GameState gameState;
extern Interface OBJ_interface;
extern Player OBJ_Player;
extern Frame frame;
/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
void Update();

/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


