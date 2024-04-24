#include <gtest/gtest.h>
#include <bitarr_dir/bitarr.hpp>

// TEST(factorialTest, SimpleTest) {
//     EXPECT_EQ(factorial(5), 120);
//     EXPECT_EQ(factorial(0), 1);
// }

// TEST(factorialTest, HardTest) {
//     const int n = 100;
//     for (int i = 0; i < n; ++i) {
//         EXPECT_EQ(factorial(i), i == 0 ? 1 : i * factorial(i - 1));
//     }
// }

TEST(bitarrTests, swap){
    BitArray a(4, 2);
    BitArray b(8, 5);
    BitArray c(8, 5);
    BitArray d(4, 2);
    a.swap(b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(b, d);
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}