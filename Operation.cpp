#include "Operation.h"
#define CMD_UP 1
#define CMD_DOWN 2
#define CMD_LEFT 4
#define CMD_RIGHT 8
#define CMD_FIRE 16
#define CMD_SKILL 32
int GetInput() {
	int inputState = 0;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)		inputState |= CMD_LEFT;//更新为当前的状态
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)	inputState |= CMD_RIGHT;
	if (GetAsyncKeyState(VK_UP) & 0x8000)		inputState |= CMD_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)		inputState |= CMD_DOWN;
	if (GetAsyncKeyState('Z') && 0X8000) inputState |= CMD_FIRE;
	if (GetAsyncKeyState('X') && 0X8000) inputState |= CMD_SKILL;
	return inputState;
}