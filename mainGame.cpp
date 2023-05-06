#include "GameManager.h"
#include "LoadResources.h"
#include "Operation.h"
int main() {

	loadResources();
	Awake();
	while (1) {
		if (gameState.startUI)
			update_StartUI();

		if (gameState.gaming)
			Gaming();
	}

}