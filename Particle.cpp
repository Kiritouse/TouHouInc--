#include "Particle.h"
#include <thread>
void Particle::show_particle(DWORD* imgBuffer, IMAGE* img, const int& win_wid, const int& win_hei, Particle* particles)
{
	SetWorkingImage(img);
	cleardevice();
	setlinecolor(BLACK);
	// ��ʾ����
	for (int i = 0; i < NUM_PARTICLE; i++)
	{
		if ((abs(static_cast<int>(particles[i].border * sin(particles[i].blink_count))) % particles[i].border) == 0)		// ���Ƴ���
		{
			particles[i].show_count++;										// �����ӹ��ΰ뾶Ϊ0ʱ�����г��ּ���
			if ((particles[i].show_count % particles[i].show_frequency))	// ��������ʱ�����֣�������ʱ��particles[i].blink_count���仯
				continue;
			else
				particles[i].show_count = 1;								// ���ּ�����1��ֱ�ӹ���Ļ���������������ʱ�����ֵ�ʱ�����
		}

		particles[i].blink_count += particles[i].blink_frequency;
		int border = (abs(static_cast<int>(particles[i].border * sin(particles[i].blink_count))) % particles[i].border);	// ���ƹ��ΰ뾶���ﵽ��˸Ч��

		COLORREF nowColor = getlinecolor();

		int light = 40 + rand() % (4 * particles[i].border);	// ����������˸
		particles[i].particle_light_offset = light - 40;
		COLORREF stepColor = RGB(light - 15, light - 17, light - 31);

		for (int j = 0; j < border; border--) {					// �����Ƚ���Բ����ƽ���ÿ�һЩ
			setlinecolor(stepColor);
			fillcircle(static_cast<int>(particles[i].cur_x), static_cast<int>(particles[i].cur_y), border);
			min(light++, 255);
			stepColor = RGB(light - 15, light - 17, light - 31);
		}
		setlinecolor(nowColor);
	}

	std::thread t1(Blur_step_weight_25_float, imgBuffer, 3, win_wid, win_hei);
	std::thread t2(Blur_step_weight_25_float, imgBuffer, 3, win_wid, win_hei);
	std::thread t3(Blur_step_weight_25_float, imgBuffer, 3, win_wid, win_hei);

	t1.join();
	t2.join();
	t3.join();

	// �������ӵ�λ��
	for (int i = 0; i < NUM_PARTICLE; i++)
	{
		float x = particles[i].cur_x;
		float y = particles[i].cur_y;

		float p_v = 1;

		float vX = (1 - p_v) * particles[i].vX + particles[i].XAm;
		float vY = (1 - p_v) * particles[i].vY + particles[i].YAm;

		float nextX = x - vX;
		float nextY = y - vY;

		if (Particle::Vx_min > vX || vX < Particle::Vx_max)
			vX = 0;
		if (Particle::Vy_min > vY || vY < Particle::Vy_max)
			vY = 0;

		particles[i].vX = vX;
		particles[i].vY = vY;

		if (nextX > win_wid) { nextX = 0; }
		else if (nextX < 0) { nextX = static_cast<float>(win_wid); }
		if (nextY > win_hei) { nextY = 0; }
		else if (nextY < 0) { nextY = static_cast<float>(win_hei); }

		if ((abs(static_cast<int>(particles[i].border * sin(particles[i].blink_count))) % particles[i].border) == 0)		// �������ӳ��֣�������ΰ뾶Ϊ0����ֻ��������λ�ö�����������
		{
			if ((particles[i].show_count % particles[i].show_frequency))			// ����������ʱ���ó��ֵ�ʱ����Ȼ�ܸ���λ��
			{
				particles[i].cur_x = nextX;
				particles[i].cur_y = nextY;
				continue;
			}
		}

		int light = min(15 * (abs(static_cast<int>(10 * sin(particles[i].blink_count))) % 10) + 7 * particles[i].particle_light_offset, 254);
		COLORREF stepColor = RGB(light, light, light);
		setlinecolor(stepColor);
		setfillcolor(stepColor);
		int particle_wid = max(particles[i].border - 10, 1);
		particle_wid = min(particle_wid, 2);

		if (particle_wid < 2)
			fillrectangle(static_cast<int>(particles[i].cur_x), static_cast<int>(particles[i].cur_y), static_cast<int>(particles[i].cur_x) + particle_wid, static_cast<int>(particles[i].cur_y) + particle_wid);
		else
			fillrectangle(static_cast<int>(particles[i].cur_x) - 1, static_cast<int>(particles[i].cur_y) - 1, static_cast<int>(particles[i].cur_x) + 1, static_cast<int>(particles[i].cur_y) + 1);

		particles[i].cur_x = nextX;
		particles[i].cur_y = nextY;
	}

	SetWorkingImage();
	myputimage(0, 0, img, 0);	// ������Ⱦ����
}