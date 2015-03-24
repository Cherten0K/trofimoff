#include "MyInt.h"
#include <iostream>

using namespace std;

class TestOperation{
public:
	char *operation;
	MyInt left, right;
	int desired_result;
	bool prefix;
	bool unar;
	bool need_exception;
	TestOperation(MyInt, char*, MyInt, int, bool);
	TestOperation(MyInt, char*, int, bool);
	TestOperation(char*, MyInt, int, bool);
	MyInt do_operation();
	void do_test();
};

void test_operation(MyInt, char*, MyInt);
void test();