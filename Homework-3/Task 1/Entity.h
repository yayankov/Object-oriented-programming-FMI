#pragma once
#include "Point3D.h"
#include <string>
using namespace std;

int generateID();

class Entity
{
protected:
	void setLocation(const Point2D* location);
	unsigned int id;
	string name;
	Point2D* location;
public:
	Entity();
	Entity(const string name,const Point2D* location);
	Entity(Entity const& other);
	Entity& operator=(Entity const& other);
	virtual ~Entity()=0;

	const string getName() const;
	const Point2D* getLocation() const;
	int getID() const;
	void setName(const string name);
	
	virtual bool isAlive() const;
	double getDistanceTo2D(const Entity &object) const;
	double getDistanceTo(const Entity &object);
	void MoveTo(const Point2D* location);
	void MoveTo(const Entity *object);

	//Enum
	enum Type
	{
		PLAYER,
		NPC,
		MOB
	};
	Type type;
	Type getType() const;
};