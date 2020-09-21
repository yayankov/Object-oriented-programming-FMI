#pragma once
#include "Mob.h"
#include "NPC.h"
#include <vector>
#include <string>
#include "Player.h"
class Environment
{
private:
	vector<Entity*> entities;
public:
	void add(Entity* object);
	Entity* getAt(int index);
	void removeAt(int index);
	void generateEntities();
	void destroyEntities();
	Entity* getClosestAliveEntity(const Player& player, Entity::Type type);
};

