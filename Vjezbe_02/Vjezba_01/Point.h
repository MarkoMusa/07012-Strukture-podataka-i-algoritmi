#ifndef _Point_h_
#define _Point_h_

class Point 
{
private:
	double x;
	double y;
	static Point origin;
public:
	Point ();
	Point (double x, double y);
	void init(double x, double y);
	double getDistanceFrom(Point p);
	double getDistanceFromOrigin();
	double getX();
	double getY();

};

#endif