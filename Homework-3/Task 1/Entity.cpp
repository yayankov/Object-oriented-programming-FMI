#include "Entity.h"
#include <cstring>
#include <iostream>
using namespace std;
int generateID()
{
	static int i = 0;
	return ++i;
}

Entity::Entity()
{
	this->name ="";
	this->location = nullptr;
	this->id = generateID();

}

Entity::Entity(const string name,const Point2D* location)
{
	setName(name);
	setLocation(location);
	this->id = generateID();
}

Entity::Entity(Entity const& other):Entity(other.getName(),other.getLocation())
{
}

Entity& Entity::operator=(Entity const& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setLocation(other.getLocation());
	}

	return *this;
}

Entity::~Entity()
{
	delete this->location;
}

const string Entity::getName() const
{
	return this->name;
}

const Point2D* Entity::getLocation() const
{
	return this->location;
}

int Entity::getID() const
{
	return this->id;
}

void Entity::setName(const string name)
{
	this->name = name;
}

void Entity::setLocation(const Point2D* location)
{
	if (this->location)
	{
		delete this->location;
    }
	this->location = location->clone();
	
}


bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceTo2D(const Entity& object) const
{
	double distance2D = this->location->getDistanceTo(object.getLocation());

	return distance2D;
}

double Entity::getDistanceTo(const Entity &object)
{
	const Point3D* caster3D = dynamic_cast<const Point3D*>(this->location);
	const Point3D* castTo3D = dynamic_cast<const Point3D*>(object.getLocation());
	double distance;

	if (caster3D != nullptr && castTo3D != nullptr)
	{
		distance = caster3D->Point3D::getDistanceTo(castTo3D);
	}
	else
		distance = this->location->getDistanceTo(object.getLocation());

	return distance;
}

void Entity::MoveTo(const Point2D* location)
{
	const Point3D* castTo3D = dynamic_cast<const Point3D*>(this->location);
	const Point3D* caster3D = dynamic_cast<const Point3D*>(location);

	if (caster3D != nullptr && castTo3D != nullptr)
		setLocation(location);
	else
		setLocation(location);
}

void Entity::MoveTo(const Entity *object)
{
	const Point3D* castTo3D = dynamic_cast<const Point3D*>(this->location);
	const Point3D* caster3D = dynamic_cast<const Point3D*>(object->getLocation());

	if (caster3D != nullptr && castTo3D != nullptr)
		setLocation(object->getLocation());
	else
		setLocation(object->getLocation());

}

Entity::Type Entity::getType() const
{
	return this->type;
}

