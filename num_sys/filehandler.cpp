#include "filehandler.hpp"

Elem FileHandler::process(const std::string& inputFile)
{    
    std::ifstream input(inputFile);
    int baseA, baseB, baseC;
    std::string numA, numB;
    input >> baseA >> numA >> baseB >> numB >> baseC;
    if (baseA < 2 || baseA > 36 || baseB < 2 || baseB > 36 || baseC < 2 || baseC > 36)
    {
        std::cerr << "Invalid input base" << std::endl;
        throw std::invalid_argument("Invalid input base");
    }
    numA = numA.substr(1, numA.size() - 2);
    numB = numB.substr(1, numB.size() - 2);
    Number numberA(numA, baseA);
    Number numberB(numB, baseB);
    Elem numbers(numberA, numberB, baseC);
    input.close();

    return numbers;
}

void FileHandler::write(int baseC, const std::string& result, const std::string& outputFile){
    std::ofstream output(outputFile);
    output << baseC << ": " << result << std::endl;
    output.close();
}
