#include "GameManager.h"
#include "LoadResources.h"
#include <graphics.h>
#include <Windows.h>
State state;
double mapy = 0;
void Awake() {
	State state;
	state = gaming;
}
void painting() {
	//BeginBatchDraw();
	//cleardevice();
	putimage(0, mapy - HEIGHT_MAP, &background);
	putimage(0, mapy, &background);//实现地图滚动
}
void moveMap() {
	mapy++;
	if (mapy >= HEIGHT_MAP) mapy = 0;
}
void Gaming() {
	painting();
	if (state != pause) {
		moveMap();
		Sleep(1);//防止地图滚动太快
	}
}