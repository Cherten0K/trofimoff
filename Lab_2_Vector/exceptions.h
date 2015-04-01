#pragma once
#include <string>

class DiscrepancySize{
protected:
	std::string message;
	size_t left, right, N1, N2;
public:
	DiscrepancySize();
	DiscrepancySize(size_t, size_t);
	DiscrepancySize(size_t, size_t, size_t, size_t);
	std::string what();
};

class OutsideRange{
protected:
	size_t index, range;
	std::string message;
public:
	OutsideRange(size_t, size_t);
	std::string what();
};
