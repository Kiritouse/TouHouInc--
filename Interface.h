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
	int enterButtonIsHit;//����Ϊ1��û����Ϊ0

};
void update_StartUI();
extern ButtonState buttonState;
