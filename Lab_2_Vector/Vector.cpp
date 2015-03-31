#include "Vector.h"
#include "exceptions.h"


Vector::Vector(){
	length = 0;
	array = NULL;
}

Vector::Vector(size_t size){
	length = size;
	array = new float[length];
	for (size_t i = 0; i < length; i++){
		array[i] = 0;
	}
}

Vector::Vector(size_t size, float *_array){
	length = size;
	array = new float[length];
	for (size_t i = 0; i < length; i++){
		array[i] = _array[i];
	}
}

Vector::Vector(const Vector &vector){
	length = vector.length;
	array = new float[length];
	for (size_t i = 0; i < length; i++){
		array[i] = vector.array[i];
	}
}

Vector Vector::operator-(){
	Vector buf(*this);
	for (size_t i = 0; i < length; i++){
		buf.array[i] = -array[i];
	}
	return buf;
}

Vector Vector::operator+(const Vector &right){
	if (length != right.length)
		throw new DiscrepancySize(length, right.length);
	Vector buf(*this);
	for (size_t i = 0; i < length; i++){
		buf.array[i] += right.array[i];
	}
	return buf;
}

Vector Vector::operator-(const Vector &right){
	if (length != right.length)
		throw new DiscrepancySize(length, right.length);
	Vector buf(*this);
	for (size_t i = 0; i < length; i++){
		buf.array[i] -= right.array[i];
	}
	return buf;
}

double Vector::operator*(const Vector &right){
	if (length != right.length)
		throw new DiscrepancySize(length, right.length);
	double result = 0;
	for (size_t i = 0; i < length; i++){
		result += array[i]*right.array[i];
	}
	return result;
}

Vector Vector::operator*(const float number){
	Vector buf(*this);
	for (size_t i = 0; i < length; i++){
		buf.array[i] *= number;
	}
	return buf;
}

Vector operator*(const float number, const Vector &vector){
	Vector buf(vector);
	for (size_t i = 0; i < buf.length; i++){
		buf.array[i] *= number;
	}
	return buf;
}

float& Vector::operator[](const size_t index){
	if (index < 0 || index >= length)
		throw new OutsideRange(index, length);
	return array[index];
}

ostream& operator <<(ostream& out,const Vector& vector){
	for (size_t i = 0; i < vector.length -1; i++){
		out << vector.array[i] << ", ";
	}
	out << vector.array[(size_t)(vector.length - 1)];
	return out;
}

Vector& Vector::operator =(const Vector &vector){
	if (&vector != this){
		length = vector.length;
		array = new float[length];
		for (size_t i = 0; i < length; i++){
			array[i] = vector.array[i];
		}
	}
	return *this;
}

Vector::~Vector()
{
	delete array;
}
