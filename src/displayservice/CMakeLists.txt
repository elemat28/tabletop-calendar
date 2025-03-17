cmake_minimum_required(VERSION 3.10.0)
project(displayService VERSION 0.1.0 LANGUAGES C)

add_library(displayservice STATIC displayservice.c)
target_include_directories(displayservice PUBLIC include)