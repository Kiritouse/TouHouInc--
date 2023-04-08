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
struct BulletNode
{
	int x, y;//�ӵ�����
	int xo, yo;//�ӵ�����ʱ��λ��
	int frame_create;//��¼����ʱ��֡��
	int fire_on, fire_off;//��¼����ʱ��֡�����
	int FireSwitch;//�Ƿ񿪻𣬶Եл�ʵ�ּ�Ъ�����
	int dx, dy;//x��y�����ϵ��ٶȣ�Ҳ��������,����ʵ�ֲַ�
	bool isExist;//�ж��ӵ��Ƿ���Ҫɾ��
	int hit;
	int width, height;
	BulletNode* pnext;//ָ����һ���ӵ��ڵ��ָ��
};
class Player {
public:
	Player();//���캯������ʼ������
	int health;
	int speed;
	void updatePosition(int _cmd);
	void updateImage();
	struct Position
	{
		int x, y;
	};
	enum ObjectState
	{
		Live,
		Dead,
		Invulnerable
	};
	struct Direction
	{
		int up;
		int down;
		int left;
		int right;
	};
};
extern GameState gameState;
extern BulletNode* ListBullet;
extern Player _player;
extern Player::Position _player_position;
/// <summary>
/// ��ʼ��һЩ����
/// </summary>
void Awake();
void Paint();

/// <summary>
///�����������GameManager����������Ϸ�йصĺ���
/// </summary>
void Gaming();


