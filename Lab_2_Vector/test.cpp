#include "test.h"
#include <cstring>

void test(void){
	//унарный минус
	float array1[] = { 1, 2, 3, 4 };
	float array2[] = { 2, 3, 4, 5 };
	float array3[] = { 6, 7, 8, 9, 10 };
	size_t length1 = 4, length2 = 4, length3 = 5;
	try{
		Vector test_unar_minus(length1, (float*)array1);
		Vector result_unar_minus = -test_unar_minus;
		float desired_result_unar_minus[] = { -1, -2, -3, -4 };
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_unar_minus[i] != desired_result_unar_minus[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails unary subtraction: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails unary subtraction: unexpected exception" << endl << endl;
	}

	//сложение
	try{
		Vector test_addition_A(length1, (float*)array1), test_addition_B(length2, (float*)array2);
		Vector result_addition = test_addition_A + test_addition_B;
		float desired_result_addition[] = {3, 5, 7, 9};
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_addition[i] != desired_result_addition[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails addition: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails addition: unexpected exception" << endl << endl;
	}

	try{
		Vector test_addition_A(length1, (float*)array1), test_addition_B(length3, (float*)array3);
		test_addition_A + test_addition_B;
		cout << endl << "!!!!Test for discrepancy of size when adding fails: was not an exception" << endl << endl;
	}
	catch (DiscrepancySize *of){
	}
	catch (...){
		cout << endl << "!!!Test for discrepancy of size when adding failed: unexpected exception" << endl << endl;
	}

	//вычитание
	try{
		Vector test_substraction_A(length1, (float*)array1), test_substraction_B(length2, (float*)array2);
		Vector result_substraction = test_substraction_A - test_substraction_B;
		float desired_result_substraction[] = { -1, -1, -1, -1 };
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_substraction[i] != desired_result_substraction[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails substraction: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails substraction: unexpected exception" << endl << endl;
	}

	try{
		Vector test_substraction_A(length1, (float*)array1), test_substraction_B(length3, (float*)array3);
		test_substraction_A - test_substraction_B;
		cout << endl << "!!!Test for discrepancy of size with substraction fails: was not an exception" << endl << endl;
	}
	catch (DiscrepancySize *of){
	}
	catch (...){
		cout << endl << "!!!Test for discrepancy of size with substraction failed: unexpected exception" << endl << endl;
	}

	//умножение на вектор
	try{
		Vector test_multiplication_A(length1, (float*)array1), test_multiplication_B(length2, (float*)array2);
		double result_multiplication = test_multiplication_A * test_multiplication_B;
		double desired_result_multiplication = 40;
		if (result_multiplication!=desired_result_multiplication)
			cout << endl << "!!!Test fails multiplication: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails substraction: unexpected exception" << endl << endl;
	}

	try{
		Vector test_multiplication_A(length1, (float*)array1), test_multiplication_B(length3, (float*)array3);
		test_multiplication_A * test_multiplication_B;
		cout << endl << "!!!Test for discrepancy of size with multiplication fails: was not an exception" << endl << endl;
	}
	catch (DiscrepancySize *of){
	}
	catch (...){
		cout << endl << "!!!Test for discrepancy of size with multiplication failed: unexpected exception" << endl << endl;
	}
	//умножение на число
	try{
		Vector test_multiplication_A(length1, (float*)array1);
		float test_multiplication_B = 3;
		Vector result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[] = { 3, 6, 9, 12 };
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_multiplication[i] != desired_result_multiplication[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails multiplication on number: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails multiplication on number: unexpected exception" << endl << endl;
	}

	try{
		Vector test_multiplication_B(length1, (float*)array1);
		float test_multiplication_A = 3;
		Vector result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[] = { 3, 6, 9, 12 };
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_multiplication[i] != desired_result_multiplication[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails friend multiplication on number: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails friend multiplication on number: unexpected exception" << endl << endl;
	}
}
