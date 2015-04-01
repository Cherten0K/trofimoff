#include "Circle.h"


Circle::Circle() :Point()
{
	radius = 0;
}

Circle::Circle(int _x, int _y, int _r) : Point(_x, _y)
{
	radius = _r;
}

void Circle::Hide(){
	int oldColor = getcolor();
	setcolor(0);
	circle(x, y, radius);
	setcolor(oldColor);
}

void Circle::Show(){
	circle(x, y, radius);
}

Circle::~Circle()
{
}
