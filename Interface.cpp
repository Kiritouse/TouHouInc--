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
	if (!buttonState.enterButtonIsHit) //如果没有被按下
		transparentimage(NULL, 140, 400, 209, 64, 0, 0, 209, 64, &enterbutton);

	else//如果被按下了 
		transparentimage(NULL, 140, 400, 209, 64, 0, 64, 209, 64, &enterbutton);



	EndBatchDraw();

}
void  update_StartUI() {
	while (E_TYPE_GAMESTATE == startUI) {//当游戏状态在开始UI状态的时候就
		OBJ_interface.paintInterface();
		MouseLisenter();
	}
}