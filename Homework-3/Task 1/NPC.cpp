#include "NPC.h"

NPC::NPC()
{
	type = Entity::NPC;
	this->id = generateID();
}

NPC::NPC(const string name, const Point2D* location):Entity(name,location)
{
	type = Entity::NPC;
	this->id = generateID();
}

bool NPC::isAlive()
{
	return true;
}
