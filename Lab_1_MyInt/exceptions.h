#pragma once
#include <string>

class OverFlow{
protected:
	int left, right;
	std::string message;
	char *op;
public:
	OverFlow(int, char*, int);
	OverFlow(int, char*);
	OverFlow(char*, int);
	
	std::string what();
};

class DivideByZero{
protected:
	std::string message;
public:
	DivideByZero();
	std::string what();
};