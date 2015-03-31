#pragma once
#include <cstdlib>
#include <ostream>
#include "exceptions.h"
using namespace std;

class Vector
{
protected:
	size_t length;
	float *array;
public:
	Vector();
	Vector(size_t);
	Vector(size_t, float *);
	Vector(const Vector&);

	Vector& operator=(const Vector&);
	
	Vector operator-();
	Vector operator+(const Vector&) throw(DiscrepancySize);
	Vector operator-(const Vector&) throw(DiscrepancySize);

	double operator*(const Vector&) throw(DiscrepancySize);
	Vector operator*(const float);
	
	float& operator[](const size_t) throw(OutsideRange);

	friend Vector operator*(const float, const Vector&);
	friend ostream& operator <<(ostream&, const Vector&);
	~Vector();
};

