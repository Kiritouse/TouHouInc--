#pragma once
struct Frame
{
	int f_total;
	int f_zawarudo;
	int f_resume;
	int f_pause;
	Frame(int f_total, int f_zawarudo, int f_resume, int f_pause) {
		this->f_total = f_total;
		this->f_zawarudo = f_zawarudo;
		this->f_resume = f_resume;
		this->f_pause = f_pause;
	}
};
void cal_FPS();
