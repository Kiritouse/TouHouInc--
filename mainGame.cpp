#include "GameManager.h"
#include "LoadResources.h"
#include <iostream>

void update() {
	while (gameState == gaming) {

		DrawImage();
	}
}
int main() {

	loadResources();
	Awake();
	BeginBatchDraw();
	update();
	EndBatchDraw();
}