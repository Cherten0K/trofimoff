#include <cstdio>
#include <cstdlib>

class OverFlow{
protected:
	int left, right;
	char *message;
	char *op;
public:
	OverFlow(int, char*, int);
	OverFlow(int, char*);
	OverFlow(char*, int);
	
	char* what();
};

class DivideByZero{
protected:
	char* message;
public:
	DivideByZero();
	char* what();
};