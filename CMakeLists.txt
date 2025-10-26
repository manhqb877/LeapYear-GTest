cmake_minimum_required(VERSION 3.10)
project(LeapYearGTest LANGUAGES CXX)

enable_testing()

# Tìm GoogleTest (đảm bảo đã cài)
find_package(GTest REQUIRED)

# Add target cho test
add_executable(runTests
    LeapYearLib/LeapYear.cpp
    LeapYearTest/LeapYearTest.cpp
)

# Liên kết thư viện GTest + GTest Main (thư viện chứa hàm main())
# Trên Linux cần pthread; trên Windows có thể bỏ.
if(UNIX)
    target_link_libraries(runTests PRIVATE GTest::GTest GTest::Main pthread)
else()
    target_link_libraries(runTests PRIVATE GTest::GTest GTest::Main)
endif()

# Đăng ký test cho ctest
add_test(NAME RunAllTests COMMAND runTests)
