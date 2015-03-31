#include "Vector.h"
#include "Matrix.h"
#include <iostream>

int main(){
	float a[2][2] = { { 1, 2 }, { 3, 4 } };
	cout << Matrix(2, 2);
	Matrix matr(2, 2, (float*)a);
	cout << matr;
	Matrix b(matr);
	cout << b;
	system("pause");
	return 0;
}