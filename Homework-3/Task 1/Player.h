#pragma once
#include "EntityLiving.h"
class Player :
	public EntityLiving
{
private:
	int damage;
	int health;
public:
	Player();
	Player(const string name,const Point2D* location,int damage, int health);
};

