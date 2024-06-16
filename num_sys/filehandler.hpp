#pragma once
#include "maths.hpp"

class FileHandler {
public:
    static Elem process(const std::string& inputFile);

    static void write(int baseC, const std::string& result, const std::string& outputFile);
    
};