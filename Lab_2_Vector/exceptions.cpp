#include "exceptions.h"
#include <cstdio>

DiscrepancySize::DiscrepancySize(size_t _left, size_t _right){
	left = _left;
	right = _right;
	message = new char[128];
	sprintf(message, "The discrepancy between the size of arrays: %i!=%i", left, right);
}

char* DiscrepancySize::what(){
	return message;
}

OutsideRange::OutsideRange(size_t _index, size_t _range){
	index = _index;
	range = _range;
	message = new char[128];
	sprintf(message, "Outside the range of the array: %i not in [0..%i]", index, range);
}

char* OutsideRange::what(){
	return message;
}
