#pragma once
#include "Entity.h"
class NPC :
	public Entity
{
public:
	NPC();
	NPC(const string name, const Point2D* location);
	bool isAlive();
};

