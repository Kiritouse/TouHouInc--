#include "Interface.h"
#include "GameManager.h"
#include "Draw.h"
#include <graphics.h>
#include "LoadResources.h"
#include "Operation.h"
#define WIDTH 500
#define HEIGHT 720
ButtonState buttonState;
void Interface::InitGraphInterface() {
	initgraph(WIDTH, HEIGHT);
}
void Interface::paintStartInterface() {
	BeginBatchDraw();
	cleardevice();
	putimage(0, 0, &startbackground);
	if (!buttonState.enterButtonIsHit) //���û�б��ƶ�������
		transparentimage(NULL, 140, 400, 209, 64, 0, 0, 209, 64, &enterbutton);

	else//����Ѿ��ƶ���������
		transparentimage(NULL, 140, 400, 209, 64, 0, 64, 209, 64, &enterbutton);

	if (!buttonState.continueButtonIsHit)
		transparentimage(NULL, 150, 500, 180, 59, 0, 0, 180, 59, &continuebutton);
	else
		transparentimage(NULL, 150, 500, 180, 50, 0, 86, 180, 59, &continuebutton);



	EndBatchDraw();

}
void Interface::paintGameInterface() {
	transparentimage(NULL, 0, HEIGHT - 44, 44, 44, 0, 0, 44, 44, &pausebutton);
}
void Interface::paintPauseInterface() {
	if (!buttonState.saveButtonIsHit) //���û���ƶ�������
		transparentimage(NULL, 120, 400, 256, 57, 0, 0, 256, 57, &savebutton);

	else {//����Ѿ��ƶ���������

		transparentimage(NULL, 120, 400, 256, 50, 0, 80, 256, 50, &savebutton);

	}
}
void  update_StartUI() {
	while (gameState.startUI) {//����Ϸ״̬�ڿ�ʼUI״̬��ʱ���
		OBJ_interface.paintStartInterface();
		MouseLisenter();
	}
}
