#include "pch.h"
#include <gtest/gtest.h>

// Khai báo hàm cần test (từ LeapYearLib)
bool IsLeapYear(int n);

// ✅ Năm chia hết cho 400 là năm nhuận
TEST(LeapYearTest, DivisibleBy400_ShouldBeLeapYear) {
    EXPECT_TRUE(IsLeapYear(2000));
}

// ✅ Năm chia hết cho 4 nhưng không chia hết cho 100 là nhuận
TEST(LeapYearTest, DivisibleBy4Not100_ShouldBeLeapYear) {
    EXPECT_TRUE(IsLeapYear(2020));
}

// ❌ Năm chia hết cho 100 nhưng không chia hết cho 400 không nhuận
TEST(LeapYearTest, DivisibleBy100Not400_ShouldNotBeLeapYear) {
    EXPECT_FALSE(IsLeapYear(1900)); // Sẽ FAIL (vì bug trong code)
}

// ✅ Năm không chia hết cho 4 là không nhuận
TEST(LeapYearTest, NotDivisibleBy4_ShouldNotBeLeapYear) {
    EXPECT_FALSE(IsLeapYear(2023));
}
