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
/// ��ʼ��һЩ����
/// </summary>
void Awake();
/// <summary>
/// ���»�ͼ
/// </summary>
void DrawImage();
/// <summary>
/// ����FPS
/// </summary>
/// <param name="start_time"></param>
void ctrlFps(int start_time);

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


