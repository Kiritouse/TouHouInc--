#include "LoadResources.h"
IMAGE  background, player;
void loadResources(void) {
	loadimage(&background, _T("sources\\Background\\background.png"));//���ر���ͼƬ
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));


}