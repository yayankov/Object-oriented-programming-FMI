#pragma once
class Point2D
{
protected:
	double x;
	double y;
public:
	Point2D();
	Point2D(double x, double y);
	virtual double getDistanceTo(const Point2D* point) const;
	virtual Point2D* clone() const;
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	virtual ~Point2D() = default;
};

