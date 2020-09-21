#pragma once
#include "Entity.h"

class EntityLiving :
	public Entity
{
protected:
	int damage;
	int health;

public:
	EntityLiving();
	EntityLiving(const string name, const Point2D* location, int damage, int health);
	virtual bool isAlive() const;
	virtual void attack(EntityLiving* player);
	int getDamage() const;
	int getHealth() const;
	void setDamage(int damage);
	void setHealth(int health);
};






