#pragma once
#include "graphics.h"

class Base
{
protected:
	int x, y;
public:	
	Base();
	Base(int, int);

	virtual void Hide() = 0;
	virtual void Show() = 0;
	virtual void Move(int, int) = 0;
	~Base();
};

