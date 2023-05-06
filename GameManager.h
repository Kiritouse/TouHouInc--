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
/// ��ʼ��һЩ����
/// </summary>
void Awake();
void Update();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


