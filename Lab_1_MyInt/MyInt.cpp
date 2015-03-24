#include "MyInt.h"

MyInt::MyInt(void){
	n = 0;
}

MyInt::MyInt(const int &N){
	n = N;
}

MyInt::MyInt(const MyInt &right){
	this->n = right.n;
}

int MyInt::N(){
	return n;
}

MyInt& MyInt::operator -(){
	if (this->n == INT_MIN){
		throw new OverFlow(this->n, "-");
	}
	this->n = -this->n;
	return *this;
}

MyInt MyInt::operator +(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a + b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "+", right.n);
	}
	return MyInt(this->n + right.n);
}

MyInt MyInt::operator -(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a - b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "-", right.n);
	}
	return MyInt(this->n - right.n);
}

MyInt MyInt::operator /(const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	return MyInt(this->n / right.n);
}

MyInt MyInt::operator *(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a * b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "*", right.n);
	}
	return MyInt(this->n * right.n);
}

MyInt MyInt::operator %(const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	return MyInt(this->n % right.n);
}

MyInt& MyInt::operator +=(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a + b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "+", right.n);
	}
	this->n += right.n;
	return *this;
}

MyInt& MyInt::operator -=(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a - b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "-", right.n);
	}
	this->n -= right.n;
	return *this;
}

MyInt& MyInt::operator /=(const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	this->n /= right.n;
	return *this;
}

MyInt& MyInt::operator *=(const MyInt &right){
	long long a = this->n, b = right.n;
	long long c = a * b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(this->n, "*", right.n);
	}
	this->n *= right.n;
	return *this;
}

MyInt& MyInt::operator %=(const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	this->n %= right.n;
	return *this;
}

MyInt& MyInt::operator ++(){
	if (this->n == INT_MAX)
		throw new OverFlow("++", this->n);
	this->n++;
	return *this;
}

MyInt MyInt::operator ++(int _t){
	if (this->n == INT_MAX)
		throw new OverFlow(this->n, "++");
	MyInt t(*this);
	++t;
	return t;
}

MyInt & MyInt::operator --(){
	if (this->n == INT_MIN)
		throw new OverFlow("--", this->n);
	this->n--;
	return *this;
}

MyInt MyInt::operator --(int _t){
	if (this->n == INT_MIN)
		throw new OverFlow(this->n, "--");
	MyInt t(*this);
	--t;
	return t;
}

bool MyInt::operator ==(const MyInt &right){
	return this->n == right.n;
}

bool MyInt::operator !=(const MyInt &right){
	return !(*this == right);
}

bool MyInt::operator <(const MyInt &right){
	return this->n<right.n;
}

bool MyInt::operator >(const MyInt &right){
	return this->n > right.n;
}

bool MyInt::operator <=(const MyInt &right){
	return !(*this > right);
}

bool MyInt::operator >=(const MyInt &right){
	return !(*this < right);
}

bool MyInt::operator &&(const MyInt &right){
	return this->n && right.n;
}

bool MyInt::operator ||(const MyInt &right){
	return this->n || right.n;
}

bool MyInt::operator !(){
	return !this->n;
}

MyInt MyInt::operator &(const MyInt &right){
	return MyInt(this->n & right.n);
}

MyInt MyInt::operator |(const MyInt &right){
	return MyInt(this->n | right.n);
}

MyInt MyInt::operator ^(const MyInt &right){
	return MyInt(this->n ^ right.n);
}

MyInt& MyInt::operator ~(){
	this->n = ~this->n;
	return *this;
}

MyInt& MyInt::operator &=(const MyInt &right){
	this->n &= right.n;
	return *this;
}

MyInt& MyInt::operator |=(const MyInt &right){
	this->n |= right.n;
	return *this;
}

MyInt& MyInt::operator ^=(const MyInt &right){
	this->n ^= right.n;
	return *this;
}

MyInt MyInt::operator <<(const MyInt &right){
	long long a = this->n;
	for (size_t i = 0; i < right; i++){
		a *= 2;
		if (a >= INT_MAX)
			throw new OverFlow(this->n, "<<", right.n);
	}
	return MyInt(this->n << right.n);
}

MyInt MyInt::operator >>(const MyInt &right){
	return MyInt(this->n >> right.n);
}

MyInt& MyInt::operator <<=(const MyInt &right){
	long long a = this->n;
	for (size_t i = 0; i < right; i++){
		a *= 2;
		if (a >= INT_MAX)
			throw new OverFlow(this->n, "<<", right.n);
	}
	this->n <<= right.n;
	return *this;
}

MyInt& MyInt::operator >>=(const MyInt &right){
	this->n >>= right.n;
	return *this;
}

MyInt& MyInt::operator =(const MyInt &right){
	if (this != &right){
		this->n = right.n;
	}
	return *this;
}

MyInt operator +(const int left, const MyInt &right){
	long long a = left, b = right.n;
	long long c = a + b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(left, "+", right.n);
	}
	return MyInt(left + right.n);
}

MyInt operator -(const int left, const MyInt &right){
	long long a = left, b = right.n;
	long long c = a - b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(left, "-", right.n);
	}
	return MyInt(left - right.n);
}

MyInt operator /(const int left, const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	return MyInt(left / right.n);
}

MyInt operator *(const int left, const MyInt &right){
	long long a = left, b = right.n;
	long long c = a * b;
	if (c <= INT_MIN || c >= INT_MAX){
		throw new OverFlow(left, "*", right.n);
	}
	return MyInt(left * right.n);
}

MyInt operator %(const int left, const MyInt &right){
	if (right.n == 0){
		throw new DivideByZero();
	}
	return MyInt(left % right.n);
}

bool operator ==(const int left, const MyInt &right){
	return left == right.n;
}

bool operator !=(const int left, const MyInt &right){
	return !(left == right);
}

bool operator <(const int left, const MyInt &right){
	return left<right.n;
}

bool operator >(const int left, const MyInt &right){
	return left > right.n;
}

bool operator <=(const int left, const MyInt &right){
	return !(left > right);
}

bool operator >=(const int left, const MyInt &right){
	return !(left < right);
}

bool operator &&(const int left, const MyInt &right){
	return left && right.n;
}

bool operator ||(const int left, const MyInt &right){
	return left || right.n;
}

MyInt operator &(const int left, const MyInt &right){
	return MyInt(left & right.n);
}

MyInt operator |(const int left, const MyInt &right){
	return MyInt(left | right.n);
}

MyInt operator ^(const int left, const MyInt &right){
	return MyInt(left ^ right.n);
}

MyInt::~MyInt(void)
{
}
