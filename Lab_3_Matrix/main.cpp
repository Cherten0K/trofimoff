#include "Matrix.h"
#include "test_matrix.h"
#include <iostream>

int main(){
	float a[2][2] = { { 1, 2 }, { 3, 4 } };
	//cout << Matrix(2, 2) << endl;
	Matrix matr(2, 2, (float*)a);
	Matrix b(matr);
	//cout << b << endl;
	//cout << matr << endl;
	Matrix amb = matr*matr;
	//cout << amb << endl;

	test();
	system("pause");
	return 0;
}