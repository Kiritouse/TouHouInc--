#include "Operation.h"
#include "GameManager.h"
#include "Interface.h"
#include <graphics.h>
#include <Windows.h>
#define START_BUTTON (m.x >= 140 && m.x <= 349 && m.y >= 400 && m.y <= 464)
int GetInput() {
	int inputState = CMD_NO_INPUT;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)		inputState |= CMD_LEFT;//����Ϊ��ǰ��״̬
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)	inputState |= CMD_RIGHT;
	if (GetAsyncKeyState(VK_UP) & 0x8000)		inputState |= CMD_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)		inputState |= CMD_DOWN;
	if (GetAsyncKeyState('Z') && 0X8000) inputState |= CMD_FIRE;
	if (GetAsyncKeyState('X') && 0X8000) inputState |= CMD_SKILL;
	return inputState;
}
void MouseLisenter() {
	HWND hwnd = GetHWnd();										//��ȡ��ͼ���ھ��
	HWND hwnd_now = GetForegroundWindow();						//��ȡ��ǰ���㴰�ھ��
	MOUSEMSG m;
	HCURSOR hcur;
	if (MouseHit() && E_TYPE_GAMESTATE == startUI) {//���˵������ˣ���������Ϸ��ʼ�����UI
		//�ж��ǵ�������İ���
		m = GetMouseMsg();
		if (START_BUTTON)
			buttonState.enterButtonIsHit = 1;
		else
			buttonState.enterButtonIsHit = 0;


		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://��������������
			if (START_BUTTON)
				E_TYPE_GAMESTATE = gaming;

			else
				break;



		default:
			break;
		}



	}
}