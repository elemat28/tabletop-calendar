include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


add_executable(timedateservice_test timedateservice_test.cpp)

target_link_libraries(timedateservice_test
PRIVATE
 GTest::GTest
 timedateservice
)

add_test(timedateservice_basic timedateservice_test)