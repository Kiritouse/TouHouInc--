#pragma once
#include <graphics.h>
#include <Windows.h>
#include "Flayers.h"
#include "LoadResources.h"
#define WIDTH  640
#define HEIGHT 1024
#define HEIGHT_MAP 1024
enum State
{
	gaming, pause, gameOver
};
extern State state;
extern double mapy;//千万不能在.h文件中定义变量,
/// <summary>
/// 初始化一些数据
/// </summary>
void Awake();
/// <summary>
/// 在这个函数中调用所有对象下面有关的绘画函数
/// </summary>
void painting();
/// <summary>
///这个函数调用GameManager中所有与游戏有关的函数
/// </summary>
void Gaming();


