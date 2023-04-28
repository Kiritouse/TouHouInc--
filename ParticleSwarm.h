#pragma once
class ParticleSwarm
{
	struct Particle
	{
		int x;			//表示粒子的运动过程的x坐标
		int y;			//表示粒子的运动过程的y坐标
		int z = 0;		// Z轴垂直屏幕输入
		double vy;		//  结构体里面的vy是每个粒子的y方向速度
		Particle(int xx, int yy, double vv) :x(xx), y(yy), vy(vv) {}//初始化
	};
public:
	ParticleSwarm(int, int, float);
	void Draw() const;
	void Move();
};

