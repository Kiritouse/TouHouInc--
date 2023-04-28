#pragma once
#include "ParticleSwarm.h"
#include <vector>
#include <list>
class Fireworks
{
public:
	Fireworks(int, int);
	void Move();

private:
	std::list<ParticleSwarm> vec;
};
