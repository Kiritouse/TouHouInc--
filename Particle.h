#pragma once
#include <graphics.h>
class Particle
{
public:
	Particle();
	static void show_particle(DWORD* imgBuffer, IMAGE* img, const int& win_wid, const int& win_hei, Particle* particles);
	static const int NUM_PARTICLE = 100;		// 总粒子个数
private:
	float ori_x, ori_y;		// 原始坐标
	float cur_x, cur_y;		// 当前坐标
	float vX, vY;			// 粒子速度
	int XAm;				// 粒子X方向移动幅度
	int YAm;				// 粒子X方向移动幅度
	float blink_frequency;	// 粒子闪烁频率
	float blink_count;		// 闪烁计数，用于控制粒子闪烁
	int border;				// 用于控制光晕半径,同时也用于控制亮度闪烁
	int show_frequency;		// 用于控制粒子出现频率
	int show_count;			// 出现计数，用于控制粒子出现
	int particle_light_offset;		// 粒子亮度随机偏移

	static const int XAm_range = 2;		// 粒子x方向初始化速度范围
	static const int XAm_min = -2;		// 粒子x方向初始化速度最小值

	static const int YAm_range = 3;		// 粒子y方向初始化速度范围
	static const int YAm_min = 0;		// 粒子y方向初始化速度最小值

	static const int border_range = 15;	// 粒子大光晕初始半径
	static const int small_border_range = 5;	// 粒子小光晕初始半径
	static const int border_min = 1;	// 粒子半径最小值

	static const float blink_frequency_max;	// 粒子闪烁频率最大值
	static const float blink_frequency_min;	// 粒子闪烁频率最小值
	static const int blink_frequency_level = 20;	// 粒子闪烁频率分级

	static const int show_frequency_min = 8;	// 粒子出现频率最小值
	static const int show_frequency_range = 15;	// 粒子出现频率最大值

	static const int Vx_max = 7;	// 粒子x方向最大速度
	static const int Vy_max = 3;	// 粒子y方向最大速度
	static const int Vx_min = -2;	// 粒子x方向最小速度
	static const int Vy_min = -3;	// 粒子y方向最小速度

};

