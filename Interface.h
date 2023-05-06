#pragma once
class Interface
{
public:
	void putButton();
	void InitGraphInterface();
	void paintStartInterface();
	void paintGameInterface();
	void paintPauseInterface();
	struct ButtonState
	{
		int enterButtonIsHit;//按下为1，没按下为0
		int saveButtonIsHit;
		int continueButtonIsHit;

	};


};

void update_StartUI();
extern Interface::ButtonState buttonState;
