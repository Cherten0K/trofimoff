#include "exceptions.h"
#include <sstream>

DiscrepancySize::DiscrepancySize(size_t _left, size_t _right){
	left = _left;
	right = _right;
	std::stringstream stream;
	stream << "The discrepancy between the size of arrays: " << left << " != " << right;
	message = stream.str();
}

std::string DiscrepancySize::what(){
	return message;
}

OutsideRange::OutsideRange(size_t _index, size_t _range){
	index = _index;
	range = _range;
	message = new char[128];
	std::stringstream stream;
	stream << "Outside the range of the array: " << index << " not in [0.." << range << "]";
	message = stream.str();
}

std::string OutsideRange::what(){
	return message;
}
