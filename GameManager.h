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


extern GameState gameState;
extern Player _player;
extern BulletNode* plane_bullet_list;
/// <summary>
/// ��ʼ��һЩ����
/// </summary>
void Awake();
void Paint();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


