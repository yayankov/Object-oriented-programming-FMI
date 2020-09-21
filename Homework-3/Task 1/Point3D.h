#pragma once
#include "Point2D.h"
class Point3D :
	public Point2D
{
protected:
	double z;
public:
	Point3D();
	Point3D(double x,double y,double z);
	Point3D(const Point3D& other);
	const Point3D& operator=(const Point3D& other);
	~Point3D();
	virtual double getDistanceTo(const Point2D *point) const;
	virtual Point2D* clone() const;
	double getZ() const;
	void setZ(double z);
};

