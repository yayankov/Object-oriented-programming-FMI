#include "Environment.h"

void Environment::add(Entity* object)
{
	entities.push_back(object);
}

Entity* Environment::getAt(int index)
{
	return entities.at(index);
}

void Environment::removeAt(int index)
{
	//трябва да освободя паметта на ентитито
	entities.erase(entities.begin()+index);
}

void Environment::generateEntities()
{
	Point2D* playerLocation = new Point2D(2, 3);
	Point2D* mobLocation = new Point2D(1, 2);
	Point2D* NPCLocation = new Point3D(2, 2, 2);
	string pName = "P1";
	string mName = "m1";
	string npcName = "npc1";
	Player player(pName,playerLocation, 50, 100);
	NPC npc(npcName,NPCLocation);
	Mob mob(mName,mobLocation,30, 60);
}
void Environment::destroyEntities()
{
	entities.clear();
}

Entity* Environment::getClosestAliveEntity(const Player& player, Entity::Type type)
{
	Entity* result = nullptr;
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getType() != type || !entities[i]->isAlive()) continue;
		if (!result) result = entities[i];
		else if (player.getDistanceTo(*entities[i]) < result->getDistanceTo(player)) result = entities[i];
	}
	return result;
}
