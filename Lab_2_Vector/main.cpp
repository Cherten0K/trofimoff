#include "Vector.h"
#include <iostream>

int main(){
	Vector a(5);
	float ar[] = { 1, 3, 4 };
	Vector b(3, (float*)ar);
	for (int i = 0; i < 3; i++){
		cout << b[i];
	}
	cout << b;
	system("pause");
	return 0;
}