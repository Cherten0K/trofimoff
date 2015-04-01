#include "Line.h"


Line::Line() :Base()
{
	x2 = y2 = 0;
}

Line::Line(int _x1, int _y1, int _x2, int _y2) : Base(_x1, _y1)
{
	x2 = _x2;
	y2 = _y2;
}

void Line::Hide(){
	int oldColor = getcolor();
	setcolor(0);
	line(x, y, x2, y2);
	setcolor(oldColor);
}

void Line::Show(){
	line(x, y, x2, y2);
}

void Line::Move(int dx, int dy){
	Hide();
	x += dx;
	x2 += dx;
	y += dy;
	y2 += dy;
	Show();
}

Line::~Line()
{
}
