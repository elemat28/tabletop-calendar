cmake_minimum_required(VERSION 3.10.0)
project(tabletopCalendar VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)



include(CTest)
enable_testing()

