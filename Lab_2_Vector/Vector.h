#pragma once
#include <cstdlib>

class Vector
{
private:
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
	float operator*(const Vector&);
	Vector operator*(const float);
	friend Vector operator*(const int, const Vector&);
	Vector& operator[](const int);
	friend ostream operator <<(ostream, const Vector&);
	~Vector();
};

