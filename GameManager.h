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
extern double mapy;//ǧ������.h�ļ��ж������,
/// <summary>
/// ��ʼ��һЩ����
/// </summary>
void Awake();
/// <summary>
/// ����������е������ж��������йصĻ滭����
/// </summary>
void painting();
/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


