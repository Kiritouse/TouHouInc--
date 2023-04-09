#include "Operation.h"
#include <Windows.h>
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