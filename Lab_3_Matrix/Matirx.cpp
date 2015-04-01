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
	array = new Vector*[M];
	for (size_t i = 0; i < M; i++){
		array[i] = new Vector(N);
	}
}

Matrix::Matrix(size_t _M, size_t _N, float * matrix) :Matrix(_M, _N){
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++){
			(*array[i])[j] = matrix[i*N + j];
		}
}

Matrix::Matrix(size_t _M, size_t _N, float ** matrix) :Matrix(_M, _N){
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
			array[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix &matrix):Matrix(matrix.M, matrix.N){
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N;j++)
			(*array[i])[j] = (*matrix.array[i])[j];
}

Vector& Matrix::operator[](size_t index){
	if (index < 0 || index >= M)
		throw new OutsideRange(index, M);
	return *(array[index]);
}

Matrix Matrix::operator-(){
	Matrix buf(*this);
	for (size_t i = 0; i < M; i++){
		buf[i] = -buf[i];
	}
	return buf;
}

Matrix Matrix::operator+(const Matrix& matrix){
	if (M != matrix.M || N!=matrix.N){
		throw new DiscrepancySize(M, N, matrix.M, matrix.N);
	}
	Matrix buf(*this);
	for (size_t i = 0; i < M; i++){
		buf[i] = (*this)[i]+buf[i];
	}
	return buf;
}

Matrix Matrix::operator-(const Matrix& matrix){
	if (M != matrix.M || N != matrix.N){
		throw new DiscrepancySize(M, N, matrix.M, matrix.N);
	}
	Matrix buf(*this);
	for (size_t i = 0; i < M; i++){
		buf[i] = (*this)[i] - buf[i];
	}
	return buf;
}

Matrix Matrix::operator~(){
	Matrix buf(this->N, this->M);
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
			buf[i][j] = (*this)[j][i];
	return buf;
}

Vector Matrix::operator*(Vector &vector){
	if (N != vector.Length()){
		throw new DiscrepancySize(N, vector.Length());
	}
	Vector buf(M);
	for (size_t i = 0; i < M; i++){
		buf[i] = (*this)[i] * vector;
	}
	return buf;
}

Matrix Matrix::operator*(Matrix& matrix){
	if (N != matrix.M){
		throw new DiscrepancySize(N, matrix.M);
	}
	Matrix matrixT = ~matrix;
	Matrix buf(M, matrix.N);
	for (size_t i = 0; i < M; i++){
		buf[i] = (*this) * *(matrixT.array[i]);
	}
	return ~buf;
}

Matrix Matrix::operator*(const float number){
	Matrix buf(*this);
	for (size_t i = 0; i < M; i++){
		buf[i] = (*this)[i] * number;
	}
	return buf;
}

Matrix operator*(const float number, const Matrix& matrix){
	Matrix buf(matrix);
	for (size_t i = 0; i < matrix.M; i++){
		buf[i] = *(matrix.array[i]) * number;
	}
	return buf;
}

ostream& operator <<(ostream& out, const Matrix& matrix){
	for (size_t i = 0; i < matrix.M; i++)
		out << *(matrix.array[i]) << endl;
	return out;
}

Matrix::~Matrix(){
	delete[] array;
}