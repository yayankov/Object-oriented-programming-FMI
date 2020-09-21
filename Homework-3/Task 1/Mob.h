#pragma once
#include "Player.h"
class Mob :
	public EntityLiving
{
private:
	int damage;
	int health;
public:
	Mob();
	Mob(const string name, const Point2D* location, int damage, int health);
	void attack(Player* player);

};

