#include "maths.hpp"
#include "filehandler.hpp"

#include <gtest/gtest.h>

TEST(CalculatorTest, ConvertToDecimal) {
    EXPECT_EQ(Calculator::convertToDecimal(Number("101", 2)) == bigint(5), 1);
    EXPECT_EQ(Calculator::convertToDecimal(Number("1010", 2)) == bigint(10), 1);
    EXPECT_EQ(Calculator::convertToDecimal(Number("FF", 16)) == bigint(255), 1);
    EXPECT_THROW(Calculator::convertToDecimal(Number("123456789", 2)), std::invalid_argument);
}

TEST(CalculatorTest, ConvertFromDecimal) {
    EXPECT_EQ(Calculator::convertFromDecimal(bigint(5), 2), "101");
    EXPECT_EQ(Calculator::convertFromDecimal(bigint(10), 2), "1010");
    EXPECT_EQ(Calculator::convertFromDecimal(bigint(255), 16), "FF");
}

TEST(CalculatorTest, CharToValue) {
    EXPECT_EQ(Calculator::charToValue('0'), 0);
    EXPECT_EQ(Calculator::charToValue('9'), 9);
    EXPECT_EQ(Calculator::charToValue('A'), 10);
    EXPECT_EQ(Calculator::charToValue('F'), 15);
    EXPECT_EQ(Calculator::charToValue('a'), 10);
    EXPECT_EQ(Calculator::charToValue('f'), 15);
}

TEST(CalculatorTest, ValueToChar) {
    EXPECT_EQ(Calculator::valueToChar(0), '0');
    EXPECT_EQ(Calculator::valueToChar(9), '9');
    EXPECT_EQ(Calculator::valueToChar(10), 'A');
    EXPECT_EQ(Calculator::valueToChar(15), 'F');
    EXPECT_THROW(Calculator::valueToChar(36), std::invalid_argument);
}

TEST(CalculatorTest, GetResult) {
    EXPECT_EQ(Calculator::getresult(Number("101", 2), Number("1010", 2), 2), "1111");
    EXPECT_EQ(Calculator::getresult(Number("FAB", 16), Number("101010", 2), 16), "FD5");
    EXPECT_EQ(Calculator::getresult(Number("101", 2), Number("1010", 2), 10), "15");
}

TEST(FileHandlerTest, Process) {
    EXPECT_THROW(FileHandler::process("non_existent_file.txt"), std::invalid_argument);
    EXPECT_THROW(FileHandler::process("input_invalid_base.txt"), std::invalid_argument);
    EXPECT_THROW(FileHandler::process("input_invalid_base1.txt"), std::invalid_argument);
    EXPECT_THROW(FileHandler::process("input_invalid_base2.txt"), std::invalid_argument);
    EXPECT_THROW(FileHandler::process("input_invalid_base3.txt"), std::invalid_argument);
}

TEST(FileHandlerTest, Write) {
    std::string outputFile = "output.txt";
    FileHandler::write(2, "1010", outputFile);
    std::ifstream output(outputFile);
    std::string line;
    std::getline(output, line);
    EXPECT_EQ(line, "2: 1010");
    output.close();
    std::remove(outputFile.c_str());
}