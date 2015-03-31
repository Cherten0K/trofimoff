#include "exceptions.h"
#include <sstream>

OverFlow::OverFlow(int l, char* oper, int r){
	left = l;
	right = r;
	op = oper;
	std::stringstream stream;
	stream << "The error during operation: " << left << oper << right << ":OverFlow";
	message = stream.str();
}

OverFlow::OverFlow(int number, char* oper){
	left = number;
	right = 0;
	op = oper;
	std::stringstream stream;
	stream << "The error during operation: " << left << oper << ":OverFlow";
	message = stream.str();
}

OverFlow::OverFlow( char* oper, int number){
	left = 0;
	right = number;
	op = oper;
	std::stringstream stream;
	stream << "The error during operation: " << oper << right << ":OverFlow";
	message = stream.str();
}

std::string OverFlow::what(){
	return message;
}

DivideByZero::DivideByZero(){
	message = std::string("Division by zero");
}

std::string DivideByZero::what(){
	return message;
}