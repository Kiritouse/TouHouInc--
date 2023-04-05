#include "Map.h"

Map::Map() {
	mapY = 0;
}
void Map::updateMapPosition() {
	mapY++;
	if (mapY >= HEIGHT_MAP)mapY = 0;

}
void Map::updatePainting() {
	putimage(0, mapY - HEIGHT_MAP, &background);
	Sleep(30);
	putimage(0, mapY, &background);
	//Sleep(1);
}

