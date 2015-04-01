#include "exceptions.h"
#include <sstream>

DiscrepancySize::DiscrepancySize(){
	left = right = N1 = N2 = 0;
	std::stringstream stream;
	stream << "The discrepancy between the size of arrays";
	message = stream.str();
}

DiscrepancySize::DiscrepancySize(size_t _left, size_t _right):DiscrepancySize(){
	left = _left;
	right = _right;
	std::stringstream stream;
	stream << "The discrepancy between the size of arrays: " << left << " != " << right;
	message = stream.str();
}

DiscrepancySize::DiscrepancySize(size_t _M1, size_t _N1, size_t _M2, size_t _N2):DiscrepancySize(_M1, _M2){
	N1 = _N1;
	N2 = _N2;
	std::stringstream stream;
	stream << "The discrepancy between the size of matrix: " << left << " != " << right  << " and " << N1 << "!=" << N2;
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
