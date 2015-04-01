#pragma once
#include "Base.h"
class Line :
	public Base
{
protected:
	int x2, y2;
public:
	Line();
	Line(int, int, int, int);

	virtual void Hide();
	virtual void Show();
	virtual void Move(int, int);

	~Line();
};

