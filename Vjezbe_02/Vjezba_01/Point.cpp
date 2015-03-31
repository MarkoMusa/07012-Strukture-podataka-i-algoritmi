#include "Point.h"
#include <cmath>


Point Point::origin(0,0);

Point ::Point ()
{
	init(0, 0);
}

Point ::Point (double x, double y)
{
	init(x, y);
}

void Point ::init (double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point ::getDistanceFrom(Point p) {
	// Distance formula
	return sqrt( pow( (p.getX() - this->x), 2) + pow((p.getY() - this->y),2) );
}

double Point ::getDistanceFromOrigin() { 
	return getDistanceFrom(this->origin);
}

double Point:: getX() { return x; }
double Point:: getY() { return y; }