#pragma once
#include <iostream>
#include <graphics.h>
#pragma
enum GameState
{
	gaming, pause, gameOver
};


extern GameState E_TYPE_GAMESTATE;

/// <summary>
/// ��ʼ��һЩ����
/// </summary>
void Awake();
void Update();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


