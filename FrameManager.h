#pragma once
struct Frame
{
	int f_total;
	int f_zawarudo;
	int f_resume;
	int f_pause;
	int f_create;
	Frame(int f_total, int f_zawarudo, int f_resume, int f_pause, int f_create) {
		this->f_total = f_total;
		this->f_zawarudo = f_zawarudo;
		this->f_resume = f_resume;
		this->f_pause = f_pause;
		this->f_create = f_create;
	}
};
void cal_FPS();
