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
/// ��ʼ��һЩ����
/// </summary>
void Awake();
void Update();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


