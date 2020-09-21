#include "Player.h"


Player::Player()
{
	type = PLAYER;
	damage = 0;
	health = 0;
	this->id = generateID();
}

Player::Player(const string name, const Point2D* location, int damage, int health)
	:EntityLiving(name,location,damage,health)
{
	type = PLAYER;
	setDamage(damage);
	setHealth(health);
	this->id = generateID();
}



