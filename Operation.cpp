#include "Operation.h"
#include "GameManager.h"
#include "Interface.h"
#include "DataManager.h"
#include <graphics.h>
#include <Windows.h>
#define START_BUTTON (m.x >= 140 && m.x <= 349 && m.y >= 400 && m.y <= 464)
#define PAUSE_BUTTON (m.x >= 0 && m.x <= 44 && m.y >= 676 && m.y <= 720)
#define SAVE_BUTTON (m.x>=120&&m.x<=376&&m.y>=400&&m.y<=450)
#define CONTINUE_BUTTON (m.x>=150&&m.x<=339&&m.y>=500&&m.y<=559)
static int PauseFlag = 0;
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
	if (MouseHit() && gameState.startUI) {//���˵������ˣ���������Ϸ��ʼ�����UI
		//�ж��ǵ�������İ���
		m = GetMouseMsg();
		if (START_BUTTON)
			buttonState.enterButtonIsHit = 1;
		else
			buttonState.enterButtonIsHit = 0;

		if (CONTINUE_BUTTON)
			buttonState.continueButtonIsHit = 1;
		else
			buttonState.continueButtonIsHit = 0;
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://��������������
			if (START_BUTTON) {
				gameState.startUI = 0;
				gameState.gaming = 1;

			}
			if (CONTINUE_BUTTON) {//��ȡ�浵
				if (isSave == 1)//�����д浵
					loadData(OBJ_Player);
				else std::cout << "û�д浵���뿪ʼ�µ���Ϸ" << std::endl;
			}
		default:
			break;
		}
	}
	if (MouseHit() && gameState.gaming) {

		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (PAUSE_BUTTON) {

				//std::cout << "asdasdsa" << std::endl;
				if (PauseFlag) {//��һ�ε�״̬����ͣ
					gameState.pause = 0;
					PauseFlag = 0;//�����ͣ״̬
				}
				else {//��һ�ε�״̬����Ϸ��
					gameState.pause = 1;
					frame.f_zawarudo = frame.f_total;//��¼�µ�ǰ��ͣʱ��ʱ��
					PauseFlag = 1;//������ͣ״̬
				}
			}
		default:
			break;
		}
	}

	if (MouseHit() && gameState.gaming && gameState.pause) {
		m = GetMouseMsg();
		if (SAVE_BUTTON) {
			buttonState.saveButtonIsHit = 1;
		}
		else
			buttonState.saveButtonIsHit = 0;
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN://��������������
			if (SAVE_BUTTON) {
				writeData();
				isSave = 1;
			}

			else
				break;
		default:
			break;
		}


	}
}