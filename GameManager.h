#pragma once
#include <graphics.h>
#include <Windows.h>
#include "LoadResources.h"
#include "TextureBuffer.h"
#include "Draw.h"
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
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


