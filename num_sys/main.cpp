#include "filehandler.hpp"
#include "maths.hpp"

int main() {
    Elem numbers = FileHandler::process("input.txt");
    std::string result = Calculator::getresult(numbers.num1, numbers.num2, numbers.baseC);
    FileHandler::write(numbers.baseC, result, "output.txt");
    try {
        Elem numbers = FileHandler::process("input.txt");
    }
    catch(const std::exception& e) {
        std::cout << e.what() << "123";
    }
    return 0;
}