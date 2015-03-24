#pragma once
#include <cstdlib>
#include <ostream>
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
	
	Vector operator-();
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);

	double operator*(const Vector&);
	Vector operator*(const float);
	
	float& operator[](const size_t);

	friend Vector operator*(const float, const Vector&);
	friend ostream& operator <<(ostream&, const Vector&);
	~Vector();
};

