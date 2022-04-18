include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
add_library(GTest::GMock INTERFACE IMPORTED)
target_link_libraries(
  GTest::GTest INTERFACE gtest_main
  GTest::GMock INTERFACE gmock_main)

add_executable(DailySummaryTest DataTest.cpp ControllerTest.cpp ../src/model/Data.cpp ../src/controller/Controller.cpp)

target_link_libraries(DailySummaryTest
 PRIVATE GTest::GTest)

add_test(DataTest DailySummaryTest)
add_test(ControllerTest DailySummaryTest)
