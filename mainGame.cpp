#include "GameManager.h"
int main() {

	loadResources();
	Awake();
	while (1) {
		if (E_TYPE_GAMESTATE == gaming)
			Gaming();
	}

}