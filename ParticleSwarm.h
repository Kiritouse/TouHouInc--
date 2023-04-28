#pragma once
class ParticleSwarm
{
	struct Particle
	{
		int x;			//��ʾ���ӵ��˶����̵�x����
		int y;			//��ʾ���ӵ��˶����̵�y����
		int z = 0;		// Z�ᴹֱ��Ļ����
		double vy;		//  �ṹ�������vy��ÿ�����ӵ�y�����ٶ�
		Particle(int xx, int yy, double vv) :x(xx), y(yy), vy(vv) {}//��ʼ��
	};
public:
	ParticleSwarm(int, int, float);
	void Draw() const;
	void Move();
};

