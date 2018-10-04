cmake_minimum_required(VERSION 3.10)
project(rational VERSION 0.1.0 LANGUAGES CXX)

add_library(rational_lib rational.cc)
target_include_directories(rational_lib PUBLIC .)

add_executable(main main.cc)
target_link_libraries(main PRIVATE rational_lib)