#include "Point.h"


Point::Point() :Base()
{
}

Point::Point(int _x, int _y) : Base(_x, _y)
{
}

void Point::Hide(){
	putpixel(x, y, 0);
}

void Point::Show(){
	putpixel(x, y, getcolor());
}

void Point::Move(int dx, int dy){
	Hide();
	x += dx;
	y += dy;
	Show();
}

Point::~Point()
{
}
