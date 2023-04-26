#pragma once
#include <graphics.h>
class Particle
{
public:
	Particle();
	static void show_particle(DWORD* imgBuffer, IMAGE* img, const int& win_wid, const int& win_hei, Particle* particles);
	static const int NUM_PARTICLE = 100;		// �����Ӹ���
private:
	float ori_x, ori_y;		// ԭʼ����
	float cur_x, cur_y;		// ��ǰ����
	float vX, vY;			// �����ٶ�
	int XAm;				// ����X�����ƶ�����
	int YAm;				// ����X�����ƶ�����
	float blink_frequency;	// ������˸Ƶ��
	float blink_count;		// ��˸���������ڿ���������˸
	int border;				// ���ڿ��ƹ��ΰ뾶,ͬʱҲ���ڿ���������˸
	int show_frequency;		// ���ڿ������ӳ���Ƶ��
	int show_count;			// ���ּ��������ڿ������ӳ���
	int particle_light_offset;		// �����������ƫ��

	static const int XAm_range = 2;		// ����x�����ʼ���ٶȷ�Χ
	static const int XAm_min = -2;		// ����x�����ʼ���ٶ���Сֵ

	static const int YAm_range = 3;		// ����y�����ʼ���ٶȷ�Χ
	static const int YAm_min = 0;		// ����y�����ʼ���ٶ���Сֵ

	static const int border_range = 15;	// ���Ӵ���γ�ʼ�뾶
	static const int small_border_range = 5;	// ����С���γ�ʼ�뾶
	static const int border_min = 1;	// ���Ӱ뾶��Сֵ

	static const float blink_frequency_max;	// ������˸Ƶ�����ֵ
	static const float blink_frequency_min;	// ������˸Ƶ����Сֵ
	static const int blink_frequency_level = 20;	// ������˸Ƶ�ʷּ�

	static const int show_frequency_min = 8;	// ���ӳ���Ƶ����Сֵ
	static const int show_frequency_range = 15;	// ���ӳ���Ƶ�����ֵ

	static const int Vx_max = 7;	// ����x��������ٶ�
	static const int Vy_max = 3;	// ����y��������ٶ�
	static const int Vx_min = -2;	// ����x������С�ٶ�
	static const int Vy_min = -3;	// ����y������С�ٶ�

};

