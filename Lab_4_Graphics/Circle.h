#pragma once
#include "Point.h"
class Circle :
	public Point
{
protected:
	int radius;
public:
	Circle();
	Circle(int, int, int);

	virtual void Hide();
	virtual void Show();

	~Circle();
};

