#include "maths.hpp"


bigint Calculator::convertToDecimal(const Number& num) {
    bigint result(0);
    for (char c : num.number) {
        int value = charToValue(c);
        if (value >= num.base) throw std::invalid_argument("Invalid digit in number for the given base");
        result = result * num.base + value;
    }
    return result;
}

std::string Calculator::convertFromDecimal(bigint number, int base) {
    if (number == 0) return "0";
    std::string result;
    while (number > 0) {
        result.push_back(valueToChar(number % base));
        number /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int Calculator::charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    throw std::invalid_argument("Invalid character in number string");
}

char Calculator::valueToChar(long long v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 35) return 'A' + (v - 10);
    throw std::invalid_argument("Invalid value to convert to char");
}

std::string Calculator::getresult(const Number& num1, const Number& num2, int baseC){
    bigint decimalA = convertToDecimal(num1);
    bigint decimalB = convertToDecimal(num2);
    bigint sum = decimalA + decimalB;
    std::string result = convertFromDecimal(sum, baseC);
    return (result);
}
