#pragma once
#include "Vector.h"
#include "exceptions.h"

class Matrix
{
public:
	Matrix();
	Matrix(size_t, size_t);
	Matrix(size_t, size_t, float*);
	Matrix(size_t, size_t, float**);
	Matrix(const Matrix&);

	Vector& operator[](size_t) throw(OutsideRange);
	Matrix operator-();
	Matrix operator+(const Matrix&) throw(DiscrepancySize);
	Matrix operator-(const Matrix&) throw(DiscrepancySize);

	Matrix operator~();

	Vector operator*(Vector&) throw(DiscrepancySize);
	Matrix operator*(const float) throw(DiscrepancySize);
	Matrix operator*(Matrix&) throw(DiscrepancySize);
	
	friend Matrix operator*(const float, const Matrix&) throw(DiscrepancySize);
	friend ostream& operator <<(ostream&, const Matrix&);
	~Matrix();

protected:
	size_t M, N;
	Vector** array;
};

