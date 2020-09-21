#include "EntityLiving.h"

EntityLiving::EntityLiving()
{
	this->damage = 0;
	this->health = 0;
}

EntityLiving::EntityLiving(const string name, const Point2D* location, int damage, int health):Entity(name,location)
{
	setDamage(damage);
	setHealth(health);
}

bool EntityLiving::isAlive() const
{
	if (health > 0)
		return true;
	else
		return false;
}

void EntityLiving::attack(EntityLiving* player)
{
	int newPlayerHealth = player->getHealth() - player->getDamage();

		if (this->location->getDistanceTo(player->getLocation()) < 5)
			player->setHealth(newPlayerHealth);
}

int EntityLiving::getDamage() const
{
	return this->damage;
}

int EntityLiving::getHealth() const
{
	return this->health;
}

void EntityLiving::setDamage(int damage)
{
	this->damage = damage;
}

void EntityLiving::setHealth(int health)
{
	this->health = health;
}
