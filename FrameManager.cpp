#include <time.h>
#include <Windows.h>
#include <graphics.h>
#include "FrameManager.h"
Frame::Frame(int f_total, int f_zawarudo, int f_resume, int f_pause) {
	this->f_total = f_total;
	this->f_zawarudo = f_zawarudo;
	this->f_resume = f_resume;
	this->f_pause = f_pause;
}
Frame::Frame() {}
void cal_FPS() {
	clock_t start_time = clock();
	clock_t running_time = clock() - start_time;
	if ((5 - running_time) >= 0)//��ֹ˯�ߺ���ʹ�ø���
		Sleep(5 - running_time);//��̬˯��13ms
	TCHAR time_text[50];
	int FPS = 1000 / (clock() - start_time);
	_stprintf_s(time_text, _T("FPS:%d"), FPS);
	settextcolor(RGB(255, 255, 255));
	//settextstyle(40, 0, _T("����")); //Ϊ����ʾ����ʾfps�����С����̫��
	outtextxy(370, 0, time_text);
}