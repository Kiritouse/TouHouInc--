#pragma once
#include "Interface.h"
#include <iostream>
#include <graphics.h>
#pragma
enum GameState
{
	gaming, pause, gameOver, startUI
};


extern GameState E_TYPE_GAMESTATE;
extern Interface OBJ_interface;

/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
void Update();

/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


