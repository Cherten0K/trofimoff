#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix()
{
	M = N = 0;
	*array = NULL;
}

Matrix::Matrix(size_t _M, size_t _N){
	M = _M;
	N = _N;
	array = new Vector*[N];
	for (size_t i = 0; i < M; i++){
		array[i] = new Vector(N);
	}
}

Matrix::Matrix(size_t _M, size_t _N, float * matrix) :Matrix(_M, _N){
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++){
			(*array[i])[j] = matrix[i*M + j];
		}
}

Matrix::Matrix(size_t _M, size_t _N, float ** matrix) :Matrix(_M, _N){
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			array[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix &matrix):Matrix(matrix.M, matrix.N){
	for (size_t i = 0; i < M; i++)
		array[i] = matrix.array[i];
}

Vector* Matrix::operator[](size_t index){
	if (index < 0 || index >= M)
		throw new OutsideRange(index, M);
	return array[index];
}

ostream& operator <<(ostream& out, const Matrix& matrix){
	for (size_t i = 0; i < matrix.M; i++)
		out << *(matrix.array[i]) << endl;
	return out;
}

//Matrix Matrix::operator-(){
//	
//}

Matrix::~Matrix(){
}