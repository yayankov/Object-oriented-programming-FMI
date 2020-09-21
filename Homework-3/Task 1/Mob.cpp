#include "Mob.h"

Mob::Mob()
{
	type = MOB;
	damage = 0;
	health = 0;
	this->id = generateID();
}

Mob::Mob(const string name, const Point2D* location, int damage, int health)
	: EntityLiving(name,location,damage,health)
{
	type = MOB;
	Mob::setDamage(damage);
	Mob::setHealth(health);
	this->id = generateID();
}


void Mob::attack(Player* player)
{

	int newPlayerHealth = player->getHealth() - player->getDamage();
	if (this->location->getDistanceTo(player->getLocation()) < 5)
		player->setHealth(newPlayerHealth);
}
