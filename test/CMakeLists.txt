include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(DailySummaryTest DataTest.cpp)

target_link_libraries(DailySummaryTest
 PRIVATE GTest::GTest)

add_test(daily_summary_gtests DailySummaryTest)
