#include "FrameManager.h"
int f_total = 0;
int f_zawarudo = 0;
int f_resume = 0;
int f_pause = 0;
void ctrlFps() {
	clock_t start_time = clock();
	clock_t running_time = clock() - start_time;
	if ((5 - running_time) >= 0)//��ֹ˯�ߺ���ʹ�ø���
		Sleep(5 - running_time);//��̬˯��13ms
	TCHAR time_text[50];
	int FPS = 1000 / (clock() - start_time);
	_stprintf_s(time_text, _T("FPS:%d"), FPS);
	settextstyle(40, 0, _T("����")); //Ϊ����ʾ����ʾfps�����С����̫��
	outtextxy(510, 0, time_text);
}