#include "ParticleManager.h"
#include "Map.h"
#include <time.h>
#include <list>
#include <graphics.h>
long ret_useless = 0;				// Capture the _getwch() return value to eliminate warnings
const int GW = WIDTH_MAP;					// Screen width��Ļ�Ŀ��
const int GH = HEIGHT_MAP;					// Screen height��Ļ�ĸ߶�
const double g = 9.8;				// Acceleration of gravity����
//const double PI = 3.1415926;
const int len_max = 130;				// The maximum length of LightLine���ߵ���󳤶�
const int h_max = GH - len_max;		// The maximum height that LightLine can reach�����ܵ������߸߶�
const double v_max = sqrt(2 * g * h_max / 10);	// Maximum initial velocity of LightLine�����ٶ� mgh=mv^2 ��������=����  
//����10��Ե���ǹ�ʽ����m����λ,1m����10�����ص�
const int n_max = 5;				// Maximum number of fireworks on the screen�̻�����Ļ��ͬʱ������������

class ParticleSwarm
{
	struct Particle
	{
		int x;			//��ʾ���ӵ��˶����̵�x����
		int y;			//��ʾ���ӵ��˶����̵�y����
		int z = 0;		// Z axis vertical screen inword Z�ᴹֱ��Ļ����
		double vy;		//  The y axis is positiva for the velocity�ṹ�������vy��ÿ�����ӵ�y�����ٶ�
		Particle(int xx, int yy, double vv) :x(xx), y(yy), vy(vv) {}
	};
public:
	ParticleSwarm(int, int, float);
	void Draw() const;
	void Move();
	bool Finish() const { return vec.size() <= 1; }

private:
	double vx;
	double vz = 0;
	float hsv_h;
	clock_t ct = 0;
	std::list<Particle> vec;
};
ParticleSwarm::ParticleSwarm(int x, int y, float colorh = float(rand() % 256))
{
	hsv_h = colorh + rand() % 20;
	hsv_h = hsv_h > 255 ? hsv_h - 256 : hsv_h;//��֤��ɫֵ��0-255֮��

	//Z��ĸ�������ˣ����˶�����Ļ�ķ���ΪZ�������
	double vm = v_max / 2 * (rand() % 5 + 15.0) / 25.0;
	double radian_xz = (rand() % 360) * PI / 180;//X��ƫ��Z��ĽǶ�0--2*PI
	double radian_xy = (rand() % 90) * PI / 180 + PI / 2;//X��ƫ��Y��ĽǶ�PI/2--PI
	vx = vm * cos(radian_xy) * cos(radian_xz);//������X���ͶӰ
	vz = vm * cos(radian_xy) * sin(radian_xz);//������Z���ͶӰ
	double vy = vm * sin(radian_xy); //������Y���ͶӰ

	//len��ʾ�����˶��켣�ĳ��ȣ�Ҳ������Ϊ��װ�����ӵ�����
	int len = rand() % 30 + 20;//rand() % 30 + 50�����Դ�������ֵ����ֵԽ���̻���ը�ķ�Χ��ɢ���ķ�Χ��Խ��
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
void ParticleSwarm::Draw() const
{
	int n = 0;
	auto size = vec.size();
	for (auto& x : vec)
	{
		if (x.x >= 0 && x.x < GW && x.y >= 0 && x.y < GH)
		{
			//�̻�������β��������ͣ���֮�׶��ǱȽ�����
			float cv = 0.2f + 0.8f * (size - n) / size - x.z; //ԭ����float cv = 0.2f + 0.8f * (size - n) / size - x.z / 40 * 0.1f
			auto color = HSVtoRGB(hsv_h, 1.0f, cv > 0 ? cv : 0);
			if (x.z < 0)		// Z axis vertical screen inword����̻�������Ļ����ɢ�Ļ����Ͱ����ص���
			{
				setfillcolor(color);
				solidcircle(x.x, x.y, abs(x.z) / 80 > 1 ? 2 : 1);
			}
			else
				putpixel(x.x, x.y, color);
		}
		++n;
	}
}
void ParticleSwarm::Move()
{
	if (ct == 0)
	{
		ct = clock();
		Draw();
		return;
	}
	for (int i = 0; i < 3 && vec.size() > 1; i++)//
		vec.pop_back();		// Delete particles for shortening length����ÿ��ˢ��ɾ��3��ĩβ����
	clock_t t = clock() - ct;
	ct = clock();
	for (auto& x : vec)//��ը����֮��һ�����˵����ӳ����˶�
	{
		double vy_cur = x.vy - g * t / 1000.0;
		x.x += int(10 * vx * t / 1000.0);
		x.y += int(10 * (vy_cur * vy_cur - x.vy * x.vy) / 2 / g);
		x.z += int(10 * vz * t / 1000.0);
		x.vy = vy_cur;
	}
	Draw();
}



class Fireworks
{
public:
	Fireworks(int, int);
	void Move();
	bool Empty() const { return vec.empty(); }

private:
	std::list<ParticleSwarm> vec;
};
Fireworks::Fireworks(int x, int y)
{
	bool colorful = rand() % 100 < 20 ? true : false;//1/5�ļ����ж�
	float h = float(rand() % 256);
	int n = rand() % 5 + 45;//�̻���������󣬱�ը�����Ĺ�����
	for (int i = 0; i < n; i++)
	{
		if (colorful)//�����̻��ı�ը���ߣ�ÿһ���Ƿ���ͬһ��ɫ�ġ�1/5�ļ����ж�
			vec.push_back(ParticleSwarm(x, y));
		else
			vec.push_back(ParticleSwarm(x, y, h));
	}
}
void Fireworks::Move()
{
	std::list<decltype(vec.begin())> toDel;
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (it->Finish())//���������Ⱥ���������ֻʣ��һ����������
		{
			toDel.push_back(it);
			continue;
		}
		it->Move();//�������Ⱥ�����������ֻ��ʣ��һ����������軭���Ĺ켣
	}
	for (auto& x : toDel)
		vec.erase(x);
}
std::list<Fireworks> vec2;

clock_t ct = clock();
void createFireworks(EnemyNode** pp_curEnemy) {
	EnemyNode* curEnemy = *pp_curEnemy;
	if (curEnemy->health <= 0)
		vec2.push_back(Fireworks(curEnemy->x, curEnemy->y));//�ӹ��߶�����ʼ��ը,�����̻�����


}
void update_Particle() {

	if (clock() - ct > 10)
	{
		//cleardevice();
		ct = clock();
		std::list<decltype(vec2.begin())> toDel2;
		for (auto it = vec2.begin(); it != vec2.end(); ++it)
		{
			if (it->Empty())
			{
				toDel2.push_back(it);//һ�仰��˵���Ǵ����ĸ�λ����Ҫɾ��
				continue;
			}
			it->Move();
		}
		for (auto& it : toDel2)
			vec2.erase(it);
	}
}