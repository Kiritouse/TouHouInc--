#pragma once
struct Frame
{
	int f_total;
	int f_zawarudo;
	int f_resume;
	int f_pause;
	Frame(int f_total, int f_zawarudo, int f_resume, int f_pause);
	Frame();
};
void cal_FPS();
