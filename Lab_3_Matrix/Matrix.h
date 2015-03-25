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

	Vector* operator[](size_t) throw(OutsideRange);
	Matrix operator-();
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);

	Vector operator*(const Matrix&);
	Matrix operator*(const float);
	friend ostream& operator <<(ostream&, const Matrix&);
	~Matrix();

protected:
	size_t M, N;
	Vector** array;
};

