#include "Operation.h"
#include "GameManager.h"
#include "Interface.h"
#include <graphics.h>
#include <Windows.h>
#define START_BUTTON (m.x >= 140 && m.x <= 349 && m.y >= 400 && m.y <= 464)
int GetInput() {
	int inputState = CMD_NO_INPUT;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)		inputState |= CMD_LEFT;//更新为当前的状态
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)	inputState |= CMD_RIGHT;
	if (GetAsyncKeyState(VK_UP) & 0x8000)		inputState |= CMD_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)		inputState |= CMD_DOWN;
	if (GetAsyncKeyState('Z') && 0X8000) inputState |= CMD_FIRE;
	if (GetAsyncKeyState('X') && 0X8000) inputState |= CMD_SKILL;
	return inputState;
}
void MouseLisenter() {
	HWND hwnd = GetHWnd();										//获取绘图窗口句柄
	HWND hwnd_now = GetForegroundWindow();						//获取当前焦点窗口句柄
	MOUSEMSG m;
	HCURSOR hcur;
	if (MouseHit() && E_TYPE_GAMESTATE == startUI) {//如果说鼠标点击了，并且在游戏开始界面的UI
		//判断是点击的是哪按键
		m = GetMouseMsg();
		if (START_BUTTON)
			buttonState.enterButtonIsHit = 1;
		else
			buttonState.enterButtonIsHit = 0;


		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://当按下了鼠标左键
			if (START_BUTTON)
				E_TYPE_GAMESTATE = gaming;

			else
				break;



		default:
			break;
		}



	}
}