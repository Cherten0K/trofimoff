#pragma once
#include "exceptions.h"
#include <climits>

class MyInt
{
public:
	int n;
	MyInt(void);//�����������
	MyInt(const int&);//�����������
	MyInt(const MyInt&);//�����������
	~MyInt(void);
	//��������������
	MyInt& operator-() throw (OverFlow);//�����������
	MyInt operator+(const MyInt&) throw (OverFlow);//�����������
	MyInt operator-(const MyInt&) throw (OverFlow);//�����������
	MyInt operator/(const MyInt&) throw (DivideByZero);//�����������
	MyInt operator*(const MyInt&) throw (OverFlow);//�����������
	MyInt operator%(const MyInt&) throw (DivideByZero);//�����������
	MyInt& operator+=(const MyInt&) throw (OverFlow);//�����������
	MyInt& operator-=(const MyInt&) throw (OverFlow);//�����������
	MyInt& operator/=(const MyInt&) throw (DivideByZero);//�����������
	MyInt& operator*=(const MyInt&) throw (OverFlow);//�����������
	MyInt& operator%=(const MyInt&) throw (DivideByZero);//�����������
	//���������
	MyInt & operator ++() throw (OverFlow);//�����������
	MyInt operator ++(int) throw (OverFlow);//�����������
	//���������
	MyInt & operator --() throw (OverFlow);//�����������
	MyInt operator --(int) throw (OverFlow);//�����������
	//���������
	bool operator==(const MyInt&);//�����������
	bool operator!=(const MyInt&);//�����������
	bool operator<(const MyInt&);//�����������
	bool operator>(const MyInt&);//�����������
	bool operator<=(const MyInt&);//�����������
	bool operator>=(const MyInt&);//�����������
	//����������
	bool operator&&(const MyInt&);//�����������
	bool operator||(const MyInt&);//�����������
	bool operator!();//�����������
	//���������
	MyInt operator&(const MyInt&);//�����������
	MyInt operator|(const MyInt&);//�����������
	MyInt operator^(const MyInt&);//�����������
	MyInt& operator~();//�����������
	MyInt& operator&=(const MyInt&);//�����������
	MyInt& operator|=(const MyInt&);//�����������
	MyInt& operator^=(const MyInt&);//�����������
	//������� �����
	MyInt operator<<(const MyInt&) throw (OverFlow);//�����������
	MyInt operator>>(const MyInt&);//�����������
	MyInt& operator<<=(const MyInt&) throw (OverFlow);//�����������
	MyInt& operator>>=(const MyInt&);//�����������
	//������������
	MyInt& operator=(const MyInt&);//�����������
	
	//friend:
		//��������������
	friend MyInt operator+(const int, const MyInt&) throw (OverFlow);//�����������
	friend MyInt operator-(const int, const MyInt&) throw (OverFlow);//�����������
	friend MyInt operator/(const int, const MyInt&) throw (DivideByZero);//�����������
	friend MyInt operator*(const int, const MyInt&) throw (OverFlow);//�����������
	friend MyInt operator%(const int, const MyInt&) throw (DivideByZero);//�����������
		//���������
	friend bool operator>(const int, const MyInt&);//�����������
	friend bool operator<(const int, const MyInt&);//�����������
	friend bool operator>=(const int, const MyInt&);//�����������
	friend bool operator<=(const int, const MyInt&);//�����������
	friend bool operator==(const int, const MyInt&);//�����������
	friend bool operator!=(const int, const MyInt&);//�����������
		//����������
	friend bool operator&&(const int, const MyInt&);//�����������
	friend bool operator||(const int, const MyInt&);//�����������
		//���������
	friend MyInt operator&(const int, const MyInt&);//�����������
	friend MyInt operator|(const int, const MyInt&);//�����������
	friend MyInt operator^(const int, const MyInt&);//�����������
};

