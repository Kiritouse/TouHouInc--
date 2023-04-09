#include "Interface.h"
#include <graphics.h>
#define WIDTH 500
#define HEIGHT 720
void Interface::InitGraphInterface() {
	initgraph(WIDTH, HEIGHT);
}