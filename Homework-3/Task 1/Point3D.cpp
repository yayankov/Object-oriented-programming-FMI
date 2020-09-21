#include "Point3D.h"
#include <cmath>
Point3D::Point3D()
{
	z = 0;
}

Point3D::Point3D(double x,double y,double z) :Point2D(x, y)
{
	setZ(z);
}

Point3D::Point3D(const Point3D& other):Point3D(other.getX(),other.getY(),other.getZ())
{
}

const Point3D& Point3D::operator=(const Point3D& other)
{
	if (this != &other)
	{
		this->x = other.getX();
		this->y = other.getY();
		this->z = other.getZ();
	}
	return *this;
}

Point3D::~Point3D()
{
}

double Point3D::getDistanceTo(const Point2D *point) const
{
	const Point3D* castTo3D = dynamic_cast<const Point3D*>(point);
	double distance3D;
	if (point != nullptr)
	{
		distance3D = sqrt((pow(fabs(this->x - point->getX()), 2) + pow(fabs(this->y - point->getY()), 2), pow(fabs(this->z - castTo3D->getZ()), 2)));
		
		return distance3D;
	}
	else
		return Point2D::getDistanceTo(point);
}

Point2D* Point3D::clone() const
{
	return new Point3D(*this);
}

double Point3D::getZ() const
{
	return this->z;
}

void Point3D::setZ(double z)
{
	this->z = z;
}
