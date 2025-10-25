cmake_minimum_required(VERSION 3.10)
project(LeapYearGTest LANGUAGES CXX)

# Bật testing
enable_testing()

# Tìm GTest (CMake cung cấp target GTest::GTest và GTest::Main khi package tìm thấy)
find_package(GTest REQUIRED)

# Add executable cho test (bao gồm cả code chính và test)
add_executable(runTests
    LeapYearLib/LeapYear.cpp
    LeapYearTest/LeapYearTest.cpp
)

# Link thư viện GTest::GTest và GTest::Main. GTest::Main chứa hàm main() cho tests.
# Trên Linux cần pthread; trên Windows thì pthread không cần.
if(UNIX)
    target_link_libraries(runTests PRIVATE GTest::GTest GTest::Main pthread)
else()
    target_link_libraries(runTests PRIVATE GTest::GTest GTest::Main)
endif()

# Thêm test cho ctest
add_test(NAME RunAllTests COMMAND runTests)
