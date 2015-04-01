#pragma once

#include <string>

//Represents the number
//Uses bool "sign" to remember number sign and vector of unsigned short numbers to represent the number itself
struct Number;

//Number constructor
//Returns new number pointer
Number* makeNumber();

//Converts string into number
//Receives string
//Returns number pointer
Number* convertIntoNumber(std::string const &insertedNumber);

//Changes number sign
//Receives number pointer
//Returns pointer of number with changed sign
void negative(Number *&oldNumber);

//Subtracts two numbers
//Receives minuend and subtrahend numbers pointers
//Returns difference number pointer
Number* subtract(Number *first, Number *second);

//Sums two numbers
//Receives two summand numbers pointers
//Returns sum number pointer
Number* sum(Number *first, Number *second);

//Multiplies two numbers
//Receives multiplicand and multiplier numbers pointers
//Returns product number pointer
Number* multiply(Number *first, Number *second);

//Prints number
//Receives number pointer
void printNumber(Number *num);

//Number destructor
//Receives number pointer
void deleteNumber(Number *num);