cmake_minimum_required(VERSION 3.10)
project(matrix VERSION 0.1.0 LANGUAGES CXX)

add_library(matrix matrix.cc)
target_include_directories(matrix PUBLIC .)
target_compile_features(matrix PUBLIC cxx_std_11)

add_executable(prg main.cc)
target_link_libraries(prg PRIVATE matrix)