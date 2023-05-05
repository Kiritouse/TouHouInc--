#pragma once
class Interface
{
public:
	void putButton();
	void InitGraphInterface();
	void paintInterface();

};
struct ButtonState
{
	int enterButtonIsHit;//按下为1，没按下为0

};
void update_StartUI();
extern ButtonState buttonState;
