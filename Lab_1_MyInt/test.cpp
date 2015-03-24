#include "test.h"
#include <cstring>

TestOperation::TestOperation(MyInt _left, char* _operation, MyInt _right, int _desired_result, bool _need_exception){
	left = _left;
	operation = _operation;
	right = _right;
	desired_result = _desired_result;
	need_exception = _need_exception;
	prefix = false;
	unar = false;
}

TestOperation::TestOperation(char* _operation, MyInt _right, int _desired_result, bool _need_exception){
	left = MyInt(0);
	operation = _operation;
	right = _right;
	desired_result = _desired_result;
	need_exception = _need_exception;
	prefix = true;
	unar = true;
}

TestOperation::TestOperation(MyInt _left, char* _operation, int _desired_result, bool _need_exception){
	left = _left;
	operation = _operation;
	right = MyInt(0);
	desired_result = _desired_result;
	need_exception = _need_exception;
	prefix = false;
	unar = true;
}

void TestOperation::do_test(){
	if (need_exception){
		try{
			do_operation();
			cout << endl << "*** Test for overflow in " << operation << " fails" << endl << endl;
		}
		catch (OverFlow *of){
			cout << "Test for overflow in " << operation << " passed" << endl;
		}

	}
	else {
		try{
			if (do_operation().n == desired_result)
				cout << "Test for " << operation << " passed" << endl;
			else
				cout << "Test for " << operation << " fails" << endl;
		}
		catch (...){
			cout << "Test for " << operation << "fails: exception" << endl;
		}
	}
}

MyInt TestOperation::do_operation(){
	if (unar){
		if (prefix){
			if (!strcmp(operation, "++"))
				return ++right;
			if (!strcmp(operation, "--"))
				return --right;
			if (!strcmp(operation, "!"))
				return !right;
			if (!strcmp(operation, "~"))
				return ~right;
			if (!strcmp(operation, "-"))
				return -right;
		}
		else{
			if (!strcmp(operation, "++"))
				return left++;
			if (!strcmp(operation, "--"))
				return left--;
		}
	}
	else{
		if (!strcmp(operation, "addition"))
			return left + right;
		if (!strcmp(operation, "substraction"))
			return left - right;
		if (!strcmp(operation, "multiplication"))
			return left * right;
		if (!strcmp(operation, "division"))
			return left / right;
		if (!strcmp(operation, "%"))
			return left % right;
		if (!strcmp(operation, "+="))
			return left += right;
		if (!strcmp(operation, "-="))
			return left -= right;
		if (!strcmp(operation, "*="))
			return left *= right;
		if (!strcmp(operation, "/="))
			return left /= right;
		if (!strcmp(operation, "*="))
			return left *= right;
		if (!strcmp(operation, "%="))
			return left %= right;
		if (!strcmp(operation, "&"))
			return left & right;
		if (!strcmp(operation, "|"))
			return left | right;
		if (!strcmp(operation, "^"))
			return left ^ right;
		if (!strcmp(operation, "&="))
			return left &= right;
		if (!strcmp(operation, "|="))
			return left |= right;
		if (!strcmp(operation, "^="))
			return left ^= right;
		if (!strcmp(operation, "<<"))
			return left << right;
		if (!strcmp(operation, ">>"))
			return left >> right;
		if (!strcmp(operation, "<<="))
			return left <<= right;
		if (!strcmp(operation, ">>="))
			return left >>= right;
	}
}

void test(){
	TestOperation test_addition = TestOperation(MyInt(45), "addition", MyInt(56), 101, false);
	TestOperation test_addition_overflow = TestOperation(MyInt(INT_MAX), "addition", MyInt(20000000), 0, true);
	TestOperation test_substraction = TestOperation(MyInt(45), "substraction", MyInt(56), -11, false);
	TestOperation test_substraction_overflow = TestOperation(MyInt(INT_MIN), "substraction", MyInt(20000000), 0, true);
	TestOperation test_division = TestOperation(MyInt(45), "division", MyInt(5), 9, false);
	TestOperation test_division_by_zero = TestOperation(MyInt(20000000), "division", MyInt(0), 0, true);
	TestOperation test_multiplication = TestOperation(MyInt(45), "multiplication", MyInt(5), 225, false);
	TestOperation test_multiplication_overflow = TestOperation(MyInt(-20000000), "multiplication", MyInt(2), 0, true);
	test_addition.do_test();
	test_addition_overflow.do_test();
	test_substraction.do_test();
	test_substraction_overflow.do_test();
	test_division.do_test();
	test_division_by_zero.do_test();
	test_multiplication.do_test();
	test_multiplication_overflow.do_test();
}

//void test(void){
//	//унарный минус
//	try{
//		MyInt test_unar_minus(45);
//		int result_unar_minus = -45;
//		if ((test_unar_minus).n == result_unar_minus)
//			cout << "Passed the test for the unary subtraction" << endl;
//		else
//			cout << "Test fails unary subtraction" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails unary subtraction" << endl << of->message << endl;
//	}
//	
//	try{
//		MyInt test_unar_minus_overflow(INT_MIN);
//		MyInt result_addition_overflow = -test_unar_minus_overflow;
//		cout << endl << "*** Test for overflow unary subtraction fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow unary subtraction passed" << endl;
//	}
//	//сложение
//	try{
//		MyInt test_addition_A(45), test_addition_B(56);
//		int result_addition = 101;
//		if ((test_addition_A + test_addition_B).n == result_addition)
//			cout << "Passed the test for the addition" << endl;
//		else
//			cout << "Test fails addition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails addition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_addition_overflow_A(2000000000), test_addition_overflow_B(2000000000);
//		MyInt result_addition_overflow = test_addition_overflow_A + test_addition_overflow_B;
//		cout << endl << "*** Test for overflow when adding fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow when adding passed" << endl;
//	}
//	//вычитание
//	try{
//		MyInt test_subtraction_A(45), test_subtraction_B(56);
//		int result_subtraction = -11;
//		if ((test_subtraction_A - test_subtraction_B).n == result_subtraction)
//			cout << "Passed the test for the subtraction" << endl;
//		else
//			cout << "Test fails subtraction" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails subtraction" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_subtraction_overflow_A(-2000000000), test_subtraction_overflow_B(2000000000);
//		MyInt result_subtraction_overflow = test_subtraction_overflow_A - test_subtraction_overflow_B;
//		cout << endl << "*** Test for overflow in subtraction fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in subtraction passed" << endl;
//	}
//	//деление
//	try{
//		MyInt test_division_A(45), test_division_B(5);
//		int result_division = 9;
//		if ((test_division_A / test_division_B).n == result_division)
//			cout << "Passed the test for the divition" << endl;
//		else
//			cout << "Test fails divition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails divition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
//		MyInt result_subtraction_overflow = test_division_by_zero_A / test_division_by_zero_B;
//		cout << endl << "*** Test for division by zero fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for division by zero passed" << endl;
//	}
//	//умножение
//	try{
//		MyInt test_multiplication_A(45), test_multiplication_B(5);
//		int result_multiplication = 225;
//		if ((test_multiplication_A / test_multiplication_B).n == result_multiplication)
//			cout << "Passed the test for the multiplication" << endl;
//		else
//			cout << "Test fails multiplication" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails multiplication" << endl << of->message << endl;
//	}
//	
//	try{
//		MyInt test_multiplication_overflow_A(-2000000000), test_multiplication_overflow_B(2);
//		MyInt result_multiplication_overflow = test_multiplication_overflow_A * test_multiplication_overflow_B;
//		cout << endl << "*** Test for overflow in multiplition fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in multiplication passed" << endl;
//	}
//	//деление с остатком
//	try{
//		MyInt test_division_with_mod_A(42), test_division_with_mod_B(5);
//		int result_division_with_mod = 2;
//		if ((test_division_with_mod_A % test_division_with_mod_B).n == result_division_with_mod)
//			cout << "Passed the test for the divition with " << endl;
//		else
//			cout << "Test fails divition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails divition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
//		MyInt result_division_by_zero_overflow = test_division_by_zero_A / test_division_by_zero_B;
//		cout << endl << "*** Test for division by zero fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for division by zero passed" << endl;
//	}
//
//	//сложение с присваиванием
//	try{
//		MyInt test_addition_A(45), test_addition_B(56);
//		int result_addition = 101;
//		test_addition_A += test_addition_B;
//		if (test_addition_A.n == result_addition)
//			cout << "Passed the test for the addition" << endl;
//		else
//			cout << "Test fails addition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails addition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_addition_overflow_A(2000000000), test_addition_overflow_B(2000000000);
//		test_addition_overflow_A += test_addition_overflow_B;
//		cout << endl << "*** Test for overflow when adding fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow when adding passed" << endl;
//	}
//	//вычитание с присваиванием
//	try{
//		MyInt test_subtraction_A(45), test_subtraction_B(56);
//		int result_subtraction = -11;
//		test_subtraction_A -= test_subtraction_B;
//		if (test_subtraction_A.n == result_subtraction)
//			cout << "Passed the test for the subtraction" << endl;
//		else
//			cout << "Test fails subtraction" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails subtraction" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_subtraction_overflow_A(-2000000000), test_subtraction_overflow_B(2000000000);
//		test_subtraction_overflow_A -= test_subtraction_overflow_B;
//		cout << endl << "*** Test for overflow in subtraction fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in subtraction passed" << endl;
//	}
//	//деление с присваиванием
//	try{
//		MyInt test_division_A(45), test_division_B(5);
//		int result_division = 9;
//		test_division_A /= test_division_B;
//		if (test_division_A.n == result_division)
//			cout << "Passed the test for the divition" << endl;
//		else
//			cout << "Test fails divition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails divition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
//		test_division_by_zero_A /= test_division_by_zero_B;
//		cout << endl << "*** Test for division by zero fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for division by zero passed" << endl;
//	}
//	//умножение с присваиванием
//	try{
//		MyInt test_multiplication_A(45), test_multiplication_B(5);
//		int result_multiplication = 225;
//		test_multiplication_A *= test_multiplication_B;
//		if (test_multiplication_A.n == result_multiplication)
//			cout << "Passed the test for the multiplication" << endl;
//		else
//			cout << "Test fails multiplication" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails multiplication" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_multiplication_overflow_A(-2000000000), test_multiplication_overflow_B(2);
//		test_multiplication_overflow_A *= test_multiplication_overflow_B;
//		cout << endl << "*** Test for overflow in multiplition fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in multiplication passed" << endl;
//	}
//	//деление с остатком с присваиванием
//	try{
//		MyInt test_division_with_mod_A(42), test_division_with_mod_B(5);
//		int result_division_with_mod = 2;
//		test_division_with_mod_A %= test_division_with_mod_B;
//		if (test_division_with_mod_A.n == result_division_with_mod)
//			cout << "Passed the test for the divition with " << endl;
//		else
//			cout << "Test fails divition" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test fails divition" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_division_by_zero_A(15), test_division_by_zero_B(0);
//		MyInt result_division_by_zero_overflow = test_division_by_zero_A / test_division_by_zero_B;
//		cout << endl << "*** Test for division by zero fails ***" << endl << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for division by zero passed" << endl;
//	}
//	//префиксный инкремент
//	try{
//		MyInt test_preincr(6);
//		int result_preincr = 7;
//		++test_preincr;
//		if (test_preincr.n == result_preincr)
//			cout << "Test for preincrement passed" << endl;
//		else
//			cout << "Test for preincrement fails" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for preincrement fails" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_preincr(INT_MAX);
//		test_preincr++;
//		cout << "Test for overflow in preincrement fails" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in preincrement passed";
//	}
//	//постфиксный инкремент
//	try{
//		MyInt test_postincr(6);
//		int result_postincr = 7;
//		test_postincr++;
//		if (test_postincr.n == result_postincr)
//			cout << "Test for postincrement passed" << endl;
//		else
//			cout << "Test for postincrement fails" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for postincrement fails" << endl << of->message << endl;
//	}
//
//	try{
//		MyInt test_postincr(INT_MAX);
//		++test_postincr;
//		cout << "Test for overflow in postincrement fails" << endl;
//	}
//	catch (OverFlow *of){
//		cout << "Test for overflow in postincrement passed";
//	}
//}