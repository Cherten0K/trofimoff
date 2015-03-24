#include "exceptions.h"

OverFlow::OverFlow(int l, char* oper, int r){
	left = l;
	right = r;
	op = oper;
	message = (char*)malloc(128*sizeof(char));
	sprintf(message, "The error during operation %i%s%i: Overflow", left, op, right);
}

OverFlow::OverFlow(int number, char* oper){
	left = number;
	right = 0;
	op = oper;
	message = (char*)malloc(128*sizeof(char));
	sprintf(message, "The error during operation %i%s: Overflow", left, op);
}

OverFlow::OverFlow( char* oper, int number){
	left = 0;
	right = number;
	op = oper;
	message = (char*)malloc(128 * sizeof(char));
	sprintf(message, "The error during operation %s%i: Overflow", op, right);
}

char* OverFlow::what(){
	return message;
}

DivideByZero::DivideByZero(){
	message = (char*)malloc(18 * sizeof(char));
	sprintf(message, "%s", "Division by zero");
}

char* DivideByZero::what(){
	return message;
}