#include "ParticleSwarm.h"
#include <time.h>
#include <stdlib.h>
ParticleSwarm::ParticleSwarm(int x, int y, float colorh = float(rand() % 256))
{
	// Cylindrical coordinate to xyz (parameters: len, radian_xz, radian_yx)
	hsv_h = colorh + rand() % 20;
	hsv_h = hsv_h > 255 ? hsv_h - 256 : hsv_h;

	//Z��ĸ�������ˣ����˶�����Ļ�ķ���ΪZ�������
	double vm = v_max / 2 * (rand() % 5 + 15.0) / 25.0;
	double radian_xz = (rand() % 360) * PI / 180;//X��ƫ��Z��ĽǶ�0--2*PI
	double radian_xy = (rand() % 90) * PI / 180 + PI / 2;//X��ƫ��Y��ĽǶ�PI/2--PI
	vx = vm * cos(radian_xy) * cos(radian_xz);//������X���ͶӰ
	vz = vm * cos(radian_xy) * sin(radian_xz);//������Z���ͶӰ
	double vy = vm * sin(radian_xy); //������Y���ͶӰ

	//len��ʾ�����˶��켣�ĳ��ȣ�Ҳ������Ϊ��װ�����ӵ�����
	int len = rand() % 30 + 50;//rand() % 30 + 50�����Դ�������ֵ����ֵԽ���̻���ը�ķ�Χ��ɢ���ķ�Χ��Խ��
	//��һ�ο̻����Ǳ�ը���������е�����һ����
	while (len)
	{
		// Use len as time parameter
		//Ŀ������λ�ã���ʼ����λ��+ƫ���ס�10
		int xx = x + int(10 * vx * len / 200.0);
		//int zz = int(10 * vz * len / 200.0);
		double cvy = vy - g * len / 200.0;
		int yy = y + int(10 * (cvy * cvy - vy * vy) / 2 / g);
		vec.push_back(Particle(xx, yy, cvy));
		--len;
	}
}