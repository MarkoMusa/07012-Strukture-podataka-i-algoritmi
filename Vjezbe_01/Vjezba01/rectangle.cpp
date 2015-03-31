#ifndef _rectangle_h_
#define _rectangle_h_

#include "rectangle.h"

Rectangle::Rectangle() 
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(double width, double height) 
{
	this->width = width;
	this->height = height;
}

void Rectangle::set(double width, double height)
{
	this->width = width;
	this->height = height;
}

double Rectangle::getWidth() { return width; }
double Rectangle::getHeight() { return height; }
double Rectangle::getArea() { return width * height; }



#endif