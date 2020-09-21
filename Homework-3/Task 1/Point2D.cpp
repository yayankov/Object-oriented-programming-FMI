#include "Point2D.h"
#include <cmath>
Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(double x, double y)
{
	setX(x);
	setY(y);
}



double Point2D::getDistanceTo(const Point2D* point) const
{

	double distance = sqrt(pow(fabs(this->x - point->getX()), 2) + pow(fabs(this->y - point->getY()), 2));

	return distance;
}

Point2D* Point2D::clone() const
{
	return new Point2D(*this);
}

double Point2D::getX() const
{
	return this->x;
}

double Point2D::getY() const
{
	return this->y;
}

void Point2D::setX(double x)
{
	this->x = x;
}

void Point2D::setY(double y)
{
	this->y = y;
}
