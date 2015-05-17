#ifndef _POINT_H_
#define _POINT_H_

#include <string>
#include <sstream>

using namespace std;

struct Point {
public:
	int x;
	int y;
	string s;

	Point(int x, int y, string s): x(x), y(y), s(s) {}
	string toString()  { 
		return s;
	}
};

#endif