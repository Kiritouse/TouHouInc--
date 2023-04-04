#include "GameManager.h"
#include "LoadResources.h"
#include <iostream>
int main() {
	Awake();
	initgraph(WIDTH, HEIGHT);
	loadResources();

	while (state == gaming) {
		Gaming();

	}

}