#include "exceptions.h"


exceptions::exceptions()
{
	message = new char[30];
	message = "Somewhere exception occurred";
}


exceptions::~exceptions()
{
	delete[] message;
}

char* exceptions::what(){
	return message;
}

DiscrepancySize::DiscrepancySize(size_t _left, size_t _right){
	left = _left;
	rigth = _right;
	message = new char[128];
	sprintf(message, "The discrepancy between the size of arrays: %i!=%i", left, right);
}