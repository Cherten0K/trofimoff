#pragma once
#include "Base.h"
class Point :
	public Base
{
public:
	Point();
	Point(int, int);
	virtual void Hide();
	virtual void Show();
	virtual void Move(int, int);
	~Point();
};

