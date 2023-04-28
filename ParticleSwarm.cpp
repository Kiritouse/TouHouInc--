#include "ParticleSwarm.h"
#include <time.h>
#include <stdlib.h>
ParticleSwarm::ParticleSwarm(int x, int y, float colorh = float(rand() % 256))
{
	// Cylindrical coordinate to xyz (parameters: len, radian_xz, radian_yx)
	hsv_h = colorh + rand() % 20;
	hsv_h = hsv_h > 255 ? hsv_h - 256 : hsv_h;

	//Z轴的负向对着人，即人对着屏幕的方向为Z轴的正向
	double vm = v_max / 2 * (rand() % 5 + 15.0) / 25.0;
	double radian_xz = (rand() % 360) * PI / 180;//X轴偏向Z轴的角度0--2*PI
	double radian_xy = (rand() % 90) * PI / 180 + PI / 2;//X轴偏向Y轴的角度PI/2--PI
	vx = vm * cos(radian_xy) * cos(radian_xz);//向量在X轴的投影
	vz = vm * cos(radian_xy) * sin(radian_xz);//向量在Z轴的投影
	double vy = vm * sin(radian_xy); //向量在Y轴的投影

	//len表示粒子运动轨迹的长度，也可以认为是装填粒子的数量
	int len = rand() % 30 + 50;//rand() % 30 + 50这个是源代码的数值，数值越大，烟花爆炸的范围，散开的范围就越大。
	//这一段刻画的是爆炸花束粒子中的其中一条线
	while (len)
	{
		// Use len as time parameter
		//目标像素位置＝初始像素位置+偏移米×10
		int xx = x + int(10 * vx * len / 200.0);
		//int zz = int(10 * vz * len / 200.0);
		double cvy = vy - g * len / 200.0;
		int yy = y + int(10 * (cvy * cvy - vy * vy) / 2 / g);
		vec.push_back(Particle(xx, yy, cvy));
		--len;
	}
}