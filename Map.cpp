#include "Map.h"
#include <graphics.h>
#include "LoadResources.h"
Map::Map() {
	mapY = 0;
}
void Map::updateMapPosition() {
	mapY++;
	if (mapY >= HEIGHT_MAP)mapY = 0;

}
void Map::updatePainting() {
	putimage(0, mapY - HEIGHT_MAP, &background);
	putimage(0, mapY, &background);
}

