#include "test_matrix.h"
#include <cstring>

void test(void){
	//унарный минус
	float matrix1[2][2] = { { 1, 2 }, { 3, 4 } };
	float matrix2[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	size_t M1, N1, M2, N2;
	M1 = N1 = M2 = 2;
	N2 = 3;
	float array1[] = { 1, 2 };
	float array2[] = { 2, 3, 4, 5 };
	float array3[] = { 6, 7, 8, 9, 10 };
	size_t length1 = 2, length2 = 4, length3 = 5;

	try{
		Matrix test_unar_minus(M1, N1, (float*)matrix1);
		Matrix result_unar_minus = -test_unar_minus;
		float desired_result_unar_minus[2][2] = { { -1, -2}, { -3, -4 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if ((result_unar_minus[i])[j] != desired_result_unar_minus[i][j])
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
		Matrix test_addition_A(M1, N1, (float*)matrix1), test_addition_B(M1, N1, (float*)matrix1);
		Matrix result_addition = test_addition_A + test_addition_B;
		float desired_result_addition[2][2] = { { 2, 4 }, { 6, 8 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if (result_addition[i][j] != desired_result_addition[i][j])
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
		Matrix test_addition_A(M1, N1, (float*)matrix1), test_addition_B(M2, N2, (float*)matrix2);
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
		Matrix test_substraction_A(M1, N1, (float*)matrix1), test_substraction_B(M1, N1, (float*)matrix1);
		Matrix result_substraction = test_substraction_A - test_substraction_B;
		float desired_result_substraction[2][2] = { { 0, 0 }, { 0, 0 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if (result_substraction[i][j] != desired_result_substraction[i][j])
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
		Matrix test_substraction_A(M1, N1, (float*)matrix1), test_substraction_B(M2, N2, (float*)matrix2);
		test_substraction_A + test_substraction_B;
		cout << endl << "!!!!Test for discrepancy of size when substraction fails: was not an exception" << endl << endl;
	}
	catch (DiscrepancySize *of){
	}
	catch (...){
		cout << endl << "!!!Test for discrepancy of size when substraction failed: unexpected exception" << endl << endl;
	}

	//транспонирование
	try{
		Matrix test_transposition(M2, N2, (float*)matrix2);
		Matrix result_transposition = ~test_transposition;
		float desired_result_transposition[3][2] = { { 1, 4 }, { 2, 5 }, { 3, 6 } };
		bool result = true;
		for (size_t i = 0; i < N2; i++){
			for (size_t j = 0; j < M2; j++)
				if (result_transposition[i][j] != desired_result_transposition[i][j])
					result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails transposition: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails transposition: unexpected exception" << endl << endl;
	}

	//умножение на вектор
	try{
		Matrix test_multiplication_A(M1, N1, (float*)matrix1);
		Vector test_multiplication_B(length1, (float*)array1);
		Vector result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[] = { 5, 11 };
		bool result = true;
		for (size_t i = 0; i < length1; i++){
			if (result_multiplication[i] != desired_result_multiplication[i])
				result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails multiplication: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails substraction: unexpected exception" << endl << endl;
	}

	try{
		Matrix test_multiplication_A(M1, N1, (float*)matrix1);
		Vector test_multiplication_B(length2, (float*)array2);
		test_multiplication_A * test_multiplication_B;
		cout << endl << "!!!Test for discrepancy of size with multiplication fails: was not an exception" << endl << endl;
	}
	catch (DiscrepancySize *of){
	}
	catch (...){
		cout << endl << "!!!Test for discrepancy of size with multiplication failed: unexpected exception" << endl << endl;
	}

	//умножение на матрицу
	try{
		Matrix test_multiplication_A(M1, N1, (float*)matrix1), test_multiplication_B(M1, N1, (float*)matrix1);
		Matrix result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[2][2] = { { 7, 10 }, { 15, 22 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if (result_multiplication[i][j] != desired_result_multiplication[i][j])
					result = false;
			if (!result)
				break;
		}
		if (!result)
			cout << endl << "!!!Test fails multiplication: wrong answer" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails substraction: unexpected exception" << endl << endl;
	}

	try{
		Matrix test_multiplication_A(M1, N1, (float*)matrix1);
		Vector test_multiplication_B(length2, (float*)array2);
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
		Matrix test_multiplication_A(M1, N1, (float*)matrix1);
		float test_multiplication_B = 3;
		Matrix result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[2][2] = { { 3, 6 }, { 9, 12 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if (result_multiplication[i][j] != desired_result_multiplication[i][j])
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
		Matrix test_multiplication_B(M1, N1, (float*)matrix1);
		float test_multiplication_A = 3;
		Matrix result_multiplication = test_multiplication_A * test_multiplication_B;
		float desired_result_multiplication[2][2] = { { 3, 6 }, { 9, 12 } };
		bool result = true;
		for (size_t i = 0; i < M1; i++){
			for (size_t j = 0; j < N1; j++)
				if (result_multiplication[i][j] != desired_result_multiplication[i][j])
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
