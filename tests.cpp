#include <gtest/gtest.h>
#include ".//bitarr.hpp"


TEST(BitArrayTest, Swap) {
    BitArray arr1(1, 10);
    BitArray arr2(2, 15);
    
    arr1.swap(arr2);
    
    EXPECT_EQ(arr1.size(), 2);
    EXPECT_EQ(arr2.size(), 1);
    EXPECT_EQ(arr1.to_string(), "0000000000001111");
    EXPECT_EQ(arr2.to_string(), "00001010");
}

// TEST(BitArrayTest, Resize) {
//     BitArray arr(2, 170);
    
//     arr.resize(3, true);
//     EXPECT_EQ(arr.size(), 3);
//     EXPECT_EQ(arr.to_string(), "111111110000000010101010");
    
//     arr.resize(1, false);
//     EXPECT_EQ(arr.size(), 1);
//     EXPECT_EQ(arr.to_string(), "10101010");
// }

// TEST(BitArrayTest, Clear) {
//     BitArray arr(1, 170);
    
//     arr.clear();
//     EXPECT_EQ(arr.size(), 0);
//     EXPECT_TRUE(arr.empty());
// }

// TEST(BitArrayTest, pushback1){
//     BitArray a(1, 10);
//     a.push_back(1);
//     bool res = 0;
//     if (a[4] == 1){
//         res = 1;
//     }
//     EXPECT_TRUE(res);
// }

// TEST(BitArrayTest, pushback2){
//     BitArray a(1, 170);
//     a.push_back(1);
//     bool res = 0;
//     if (a[9] == 1){
//         res = 1;
//     }
//     EXPECT_TRUE(res);
// }

// TEST(BitArrayTest, Any) {
//     BitArray arr1(1, 170);
//     BitArray arr2(1, 0);
    
//     EXPECT_TRUE(arr1.any());
//     EXPECT_FALSE(arr2.any());
// }

// TEST(BitArrayTest, None) {
//     BitArray arr1(1, 170);
//     BitArray arr2(1, 0);
    
//     EXPECT_FALSE(arr1.none());
//     EXPECT_TRUE(arr2.none());
// }

// TEST(BitArrayTest, Count) {
//     BitArray arr(1, 170);
    
//     EXPECT_EQ(arr.count(), 4);
// }

// TEST(BitArrayTest, Empty) {
//     BitArray arr1(1, 170);
//     BitArray arr2;
    
//     EXPECT_FALSE(arr1.empty());
//     EXPECT_TRUE(arr2.empty());
// }