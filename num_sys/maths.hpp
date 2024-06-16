#pragma once
#include "bigint.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <exception>



class Number {
public:
    std::string number;
    int base;
    Number(const std::string& num, int base) : number(num), base(base) {}
};

class Calculator {
public:
    static bigint convertToDecimal(const Number& num);

    static std::string convertFromDecimal(bigint number, int base);

    static int charToValue(char c);

    static char valueToChar(long long v);

    static std::string getresult(const Number& num1, const Number& num2, int baseC);
};

class Elem {
public:
    Number num1;
    Number num2;
    int baseC;
    Elem(const Number& num1, const Number& num2, int baseC) : num1(num1), num2(num2), baseC(baseC){}
private:
    
};