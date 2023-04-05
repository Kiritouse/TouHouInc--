#include "GameManager.h"
#include "LoadResources.h"
#include <iostream>
int main() {
	loadResources();
	Awake();
	while (gameState == gaming) {
		Gaming();
		//putimage(0, 0, &background);
		//putimage(0, 0, &player);

	}


}