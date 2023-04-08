#pragma once
#include "GameManager.h"
struct Frame
{
	int f_total;
	int f_zawarudo;
	int f_resume;
	int f_pause;
	Frame(int total, int zawarudo, int resume, int pause) {
		f_total = total;
		f_zawarudo = zawarudo;
		f_resume = resume;
		f_pause = pause;
	}
};
extern Frame frame;
void ctrlFps();
