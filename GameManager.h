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
void Paint();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


