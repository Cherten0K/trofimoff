#include "test.h"
#include <cstring>

void test(void){
	//унарный минус
	try{
		MyInt test_unar_minus(45);
		int result_unar_minus = -45;
		if (-(test_unar_minus).N() == result_unar_minus)
			cout << "Test for the unary subtraction passed" << endl;
		else
			cout << endl << "!!!Test fails unary subtraction" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails unary subtraction: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_unar_minus_overflow(INT_MIN);
		MyInt result_addition_overflow = -test_unar_minus_overflow;
		cout << endl << "*** Test for overflow unary subtraction fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow unary subtraction passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for overflow unary subtraction failed: unexpected exception" << endl << endl;
	}

	//сложение
	try{
		MyInt test_addition_A(45), test_addition_B(56);
		int result_addition = 101;
		if ((test_addition_A + test_addition_B).N() == result_addition)
			cout << "Test for the addition passed" << endl;
		else
			cout << endl << "!!!Test fails addition" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails addition: unexpected exception" << endl << endl;
	}
	try{
		MyInt test_addition_overflow_A(2000000000), test_addition_overflow_B(2000000000);
		MyInt result_addition_overflow = test_addition_overflow_A + test_addition_overflow_B;
		cout << endl << "*** Test for overflow when adding fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow when adding passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for overflow when adding failed: unexpected exception" << endl << endl;
	}

	//вычитание
	try{
		MyInt test_subtraction_A(45), test_subtraction_B(56);
		int result_subtraction = -11;
		if ((test_subtraction_A - test_subtraction_B).N() == result_subtraction)
			cout << "Test for the subtraction passed" << endl;
		else
			cout << endl << "!!!Test fails subtraction" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails subtraction: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_subtraction_overflow_A(-2000000000), test_subtraction_overflow_B(2000000000);
		MyInt result_subtraction_overflow = test_subtraction_overflow_A - test_subtraction_overflow_B;
		cout << endl << "*** Test for overflow in subtraction fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in subtraction passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for overflow in subtraction failed: unexpected exception" << endl << endl;
	}
	//деление
	try{
		MyInt test_division_A(45), test_division_B(5);
		int result_division = 9;
		if ((test_division_A / test_division_B).N() == result_division)
			cout << "Test for the division passed" << endl;
		else
			cout << endl << "!!!Test fails division" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails division: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
		MyInt result_subtraction_overflow = test_division_by_zero_A / test_division_by_zero_B;
		cout << endl << "*** Test for division by zero fails ***" << endl << endl;
	}
	catch (DivideByZero *of){
		cout << "Test for division by zero passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for division by zero failed: unexpected exception" << endl << endl;
	}

	//умножение
	try{
		MyInt test_multiplication_A(45), test_multiplication_B(5);
		int result_multiplication = 225;
		if ((test_multiplication_A * test_multiplication_B).N() == result_multiplication)
			cout << "Test for the multiplication passed" << endl;
		else
			cout << endl << "!!!Test fails multiplication" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails multiplication: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_multiplication_overflow_A(-2000000000), test_multiplication_overflow_B(2);
		MyInt result_multiplication_overflow = test_multiplication_overflow_A * test_multiplication_overflow_B;
		cout << endl << "*** Test for overflow in multiplition fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in multiplication passed" << endl;
	}
	catch (...){
		cout << endl << "Test for overflow in multiplication failed: unexpected exception" << endl << endl;
	}
	//деление с остатком
	try{
		MyInt test_division_with_mod_A(42), test_division_with_mod_B(5);
		int result_division_with_mod = 2;
		if ((test_division_with_mod_A % test_division_with_mod_B).N() == result_division_with_mod)
			cout << "Test for modulo passed" << endl;
		else
			cout << endl << "!!!Test fails divition" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails modulo: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
		MyInt result_division_by_zero_overflow = test_division_by_zero_A % test_division_by_zero_B;
		cout << endl << "!!!Test for modulo exceptions fails " << endl << endl;
	}
	catch (DivideByZero *of){
		cout << "Test for modulo by zero passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test modulo by zero fails: unexpected exception" << endl << endl;
	}

	//сложение с присваиванием
	try{
		MyInt test_addition_A(45), test_addition_B(56);
		int result_addition = 101;
		test_addition_A += test_addition_B;
		if (test_addition_A.N() == result_addition)
			cout << "Passed the test for the addition with assignment" << endl;
		else
			cout << endl << "!!!Test fails addition with assignment" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails addition with assignment: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_addition_overflow_A(2000000000), test_addition_overflow_B(2000000000);
		test_addition_overflow_A += test_addition_overflow_B;
		cout << endl << "*** Test for overflow when adding with assignment fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow when adding with assignment passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for overflow when adding with assignment failed" << endl << endl;
	}

	//вычитание с присваиванием
	try{
		MyInt test_subtraction_A(45), test_subtraction_B(56);
		int result_subtraction = -11;
		test_subtraction_A -= test_subtraction_B;
		if (test_subtraction_A.N() == result_subtraction)
			cout << "Passed the test for the subtraction with assignment" << endl;
		else
			cout << endl << "!!!Test fails subtraction with assignment" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails subtraction with assignment: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_subtraction_overflow_A(-2000000000), test_subtraction_overflow_B(2000000000);
		test_subtraction_overflow_A -= test_subtraction_overflow_B;
		cout << endl << "*** Test for overflow in subtraction with assignment fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in subtraction with assignment passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for overflow in substraction with assignment failed: unexpected exception" << endl << endl;
	}

	//деление с присваиванием
	try{
		MyInt test_division_A(45), test_division_B(5);
		int result_division = 9;
		test_division_A /= test_division_B;
		if (test_division_A.N() == result_division)
			cout << "Passed the test for the divition with assignment" << endl;
		else
			cout << endl << "!!!Test fails divition with assignment" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for division with assignment failed: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
		test_division_by_zero_A /= test_division_by_zero_B;
		cout << endl << "*** Test for division by zero with assignment fails ***" << endl << endl;
	}
	catch (DivideByZero *of){
		cout << "Test for division by zero with assignment passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for division by zero with assignment failed: unexpected exception" << endl << endl;
	}

	//умножение с присваиванием
	try{
		MyInt test_multiplication_A(45), test_multiplication_B(5);
		int result_multiplication = 225;
		test_multiplication_A *= test_multiplication_B;
		if (test_multiplication_A.N() == result_multiplication)
			cout << "Passed the test for the multiplication with assignment" << endl;
		else
			cout << endl << "!!!Test fails multiplication with assignment" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails multiplication with assignment: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_multiplication_overflow_A(-2000000000), test_multiplication_overflow_B(2);
		test_multiplication_overflow_A *= test_multiplication_overflow_B;
		cout << endl << "*** Test for overflow in multiplition with assignment fails ***" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in multiplication with assignment passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test for multiplication with assignment failed: unexpected exception" << endl << endl;
	}

	//деление с остатком с присваиванием
	try{
		MyInt test_division_with_mod_A(42), test_division_with_mod_B(5);
		int result_division_with_mod = 2;
		test_division_with_mod_A %= test_division_with_mod_B;
		if (test_division_with_mod_A.N() == result_division_with_mod)
			cout << "Passed the test for modulo with assignment with " << endl;
		else
			cout << endl << "!!!Test fails modulo with assignment" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails modulo with assignment" << endl << endl;
	}

	try{
		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
		MyInt result_division_by_zero_overflow = test_division_by_zero_A / test_division_by_zero_B;
		cout << endl << "*** Test for division by zero with assignment fails ***" << endl << endl;
	}
	catch (DivideByZero *of){
		cout << "Test for division by zero  with assignment passed" << endl;
	}
	catch (...){
		cout << endl << "!!!Test fails modulo with assignment" << endl << endl;
	}
	//префиксный инкремент
	try{
		MyInt test_preincr(6);
		int result_preincr = 7;
		++test_preincr;
		if (test_preincr.N() == result_preincr)
			cout << "Test for preincrement passed" << endl;
		else
			cout << endl << "!!!Test for preincrement fails" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test for preincrement fails: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_preincr(INT_MAX);
		test_preincr++;
		cout << endl << "!!!Test for overflow in preincrement fails" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in preincrement passed" << endl;
	}
	catch (...){
		cout << endl << "!!! Test for overflow in preincrement fails: unexpected exception" << endl << endl;
	}

	//постфиксный инкремент
	try{
		MyInt test_postincr(6);
		int result_postincr = 7;
		if ((test_postincr++).N() == result_postincr)
			cout << "Test for postincrement passed" << endl;
		else
			cout << endl << "!!!Test for postincrement fails" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test for postincrement fails: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_postincr(INT_MAX);
		test_postincr++;
		cout << endl << "!!!Test for overflow in postincrement fails" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in postincrement passed" << endl;
	}
	catch (...){
		cout << endl << "Test for overflow in postincrement fails: unexpected exception" << endl << endl;
	}

	//префиксный декремент
	try{
		MyInt test_predecr(6);
		int result_predecr = 5;
		--test_predecr;
		if (test_predecr.N() == result_predecr)
			cout << "Test for predecrement passed" << endl;
		else
			cout << endl << "!!!Test for predecrement fails" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test for predecrement fails: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_predecr(INT_MIN);
		test_predecr--;
		cout << endl << "!!!Test for overflow in predecrement fails" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in predecrement passed" << endl;
	}
	catch (...){
		cout << endl << "!!! Test for overflow in predecrement fails: unexpected exception" << endl << endl;
	}

	//постфиксный декремент
	try{
		MyInt test_postdecr(6);
		int result_postdecr = 5;
		if ((test_postdecr--).N() == result_postdecr)
			cout << "Test for postdecrement passed" << endl;
		else
			cout << endl << "!!!Test for postdecrement fails" << endl << endl;
	}
	catch (...){
		cout << endl << "!!!Test for postdecrement fails: unexpected exception" << endl << endl;
	}

	try{
		MyInt test_postdecr(INT_MIN);
		test_postdecr--;
		cout << endl << "!!!Test for overflow in postdecrement fails" << endl << endl;
	}
	catch (OverFlow *of){
		cout << "Test for overflow in postdecrement passed" << endl;
	}
	catch (...){
		cout << endl << "Test for overflow in postdecrement fails: unexpected exception" << endl << endl;
	}
}