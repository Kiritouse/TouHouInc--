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
void Interface::paintInterface() {
	BeginBatchDraw();
	cleardevice();
	putimage(0, 0, &startbackground);
	if (!buttonState.enterButtonIsHit) //���û�б�����
		transparentimage(NULL, 140, 400, 209, 64, 0, 0, 209, 64, &enterbutton);

	else//����������� 
		transparentimage(NULL, 140, 400, 209, 64, 0, 64, 209, 64, &enterbutton);



	EndBatchDraw();

}
void  update_StartUI() {
	while (E_TYPE_GAMESTATE == startUI) {//����Ϸ״̬�ڿ�ʼUI״̬��ʱ���
		OBJ_interface.paintInterface();
		MouseLisenter();
	}
}