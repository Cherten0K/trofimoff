#pragma once


class DiscrepancySize{
protected:
	char* message;
	size_t left, right;
public:
	DiscrepancySize(size_t, size_t);
	virtual char* what();
};

class OutsideRange{
protected:
	size_t index, range;
	char *message;
public:
	OutsideRange(size_t, size_t);
	char *what();
};
