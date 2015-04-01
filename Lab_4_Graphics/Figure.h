#pragma once
#include "Base.h"
#include <vector>

class Figure :
	public Base
{
protected:
	std::vector<Base*>* primitives;
public:
	Figure();

	void AddPrimitiv(Base*);

	virtual void Hide();
	virtual void Show();
	virtual void Move(int, int);

	~Figure();
};

