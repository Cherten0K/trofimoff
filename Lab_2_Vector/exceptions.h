#pragma once
#include <iostream>

using namespace std;

class exceptions{
protected:
	char* message;
public:
	virtual char* what();
	exceptions();
	~exceptions();
};

class DiscrepancySize: exceptions{
private:
	size_t left, rigth;
public:
	DiscrepancySize(size_t, size_t);
	virtual char* what();
};