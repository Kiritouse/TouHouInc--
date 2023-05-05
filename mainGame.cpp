#include "GameManager.h"
#include "LoadResources.h"
int main() {

	loadResources();
	Awake();
	while (1) {
		if (E_TYPE_GAMESTATE == startUI)
			update_StartUI();

		if (E_TYPE_GAMESTATE == gaming)
			Gaming();
	}

}