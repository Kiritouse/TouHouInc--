#include "GameManager.h"
#include "LoadResources.h"
#include <iostream>


int main() {

	loadResources();
	Awake();
	while (1) {
		Gaming();
	}

}