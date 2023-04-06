#include "LoadResources.h"
IMAGE  background, player, playerRight, playerLeft;
void loadResources(void) {
	loadimage(&background, _T("sources\\Background\\background.png"));//º”‘ÿ±≥æ∞Õº∆¨
	loadimage(&player, _T("sources\\Players\\PlayerUpAndDown.png"));
	loadimage(&playerRight, _T("sources\\Players\\PlayerRight.png"));
	loadimage(&playerLeft, _T("sources\\Players\\PlayerLeft.png"));



}