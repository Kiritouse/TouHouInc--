#pragma once
#include <graphics.h>
#include <Windows.h>
#include "LoadResources.h"
#include "TextureBuffer.h"
#include "Draw.h"
#include  <time.h>
enum GameState
{
	gaming, pause, gameOver
};
extern GameState gameState;
/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
/// <summary>
/// 更新绘图
/// </summary>
void DrawImage();
/// <summary>
/// 计算FPS
/// </summary>
/// <param name="start_time"></param>
void ctrlFps(int start_time);

/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


