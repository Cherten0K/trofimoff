#pragma once
#include "exceptions.h"
#include <climits>

class MyInt
{
protected:
	int n;
public:
	MyInt(void);//реализовано
	MyInt(const int&);//реализовано
	MyInt(const MyInt&);//реализовано
	~MyInt(void);

	int N();
	//арифметические
	MyInt& operator-() throw (OverFlow);//реализовано
	MyInt operator+(const MyInt&) throw (OverFlow);//реализовано
	MyInt operator-(const MyInt&) throw (OverFlow);//реализовано
	MyInt operator/(const MyInt&) throw (DivideByZero);//реализовано
	MyInt operator*(const MyInt&) throw (OverFlow);//реализовано
	MyInt operator%(const MyInt&) throw (DivideByZero);//реализовано
	MyInt& operator+=(const MyInt&) throw (OverFlow);//реализовано
	MyInt& operator-=(const MyInt&) throw (OverFlow);//реализовано
	MyInt& operator/=(const MyInt&) throw (DivideByZero);//реализовано
	MyInt& operator*=(const MyInt&) throw (OverFlow);//реализовано
	MyInt& operator%=(const MyInt&) throw (DivideByZero);//реализовано
	//инкремент
	MyInt & operator ++() throw (OverFlow);//реализовано
	MyInt operator ++(int) throw (OverFlow);//реализовано
	//декремент
	MyInt & operator --() throw (OverFlow);//реализовано
	MyInt operator --(int) throw (OverFlow);//реализовано
	//сравнение
	bool operator==(const MyInt&);//реализовано
	bool operator!=(const MyInt&);//реализовано
	bool operator<(const MyInt&);//реализовано
	bool operator>(const MyInt&);//реализовано
	bool operator<=(const MyInt&);//реализовано
	bool operator>=(const MyInt&);//реализовано
	//логические
	bool operator&&(const MyInt&);//реализовано
	bool operator||(const MyInt&);//реализовано
	bool operator!();//реализовано
	//побитовые
	MyInt operator&(const MyInt&);//реализовано
	MyInt operator|(const MyInt&);//реализовано
	MyInt operator^(const MyInt&);//реализовано
	MyInt& operator~();//реализовано
	MyInt& operator&=(const MyInt&);//реализовано
	MyInt& operator|=(const MyInt&);//реализовано
	MyInt& operator^=(const MyInt&);//реализовано
	//битовый сдвиг
	MyInt operator<<(const MyInt&) throw (OverFlow);//реализовано
	MyInt operator>>(const MyInt&);//реализовано
	MyInt& operator<<=(const MyInt&) throw (OverFlow);//реализовано
	MyInt& operator>>=(const MyInt&);//реализовано
	//присваивание
	MyInt& operator=(const MyInt&);//реализовано

	//friend:
	//арифметические
	friend MyInt operator+(const int, const MyInt&) throw (OverFlow);//реализовано
	friend MyInt operator-(const int, const MyInt&) throw (OverFlow);//реализовано
	friend MyInt operator/(const int, const MyInt&) throw (DivideByZero);//реализовано
	friend MyInt operator*(const int, const MyInt&) throw (OverFlow);//реализовано
	friend MyInt operator%(const int, const MyInt&) throw (DivideByZero);//реализовано
	//сравнение
	friend bool operator>(const int, const MyInt&);//реализовано
	friend bool operator<(const int, const MyInt&);//реализовано
	friend bool operator>=(const int, const MyInt&);//реализовано
	friend bool operator<=(const int, const MyInt&);//реализовано
	friend bool operator==(const int, const MyInt&);//реализовано
	friend bool operator!=(const int, const MyInt&);//реализовано
	//логические
	friend bool operator&&(const int, const MyInt&);//реализовано
	friend bool operator||(const int, const MyInt&);//реализовано
	//побитовые
	friend MyInt operator&(const int, const MyInt&);//реализовано
	friend MyInt operator|(const int, const MyInt&);//реализовано
	friend MyInt operator^(const int, const MyInt&);//реализовано
};

