cmake_minimum_required(VERSION 3.0.0)
project(cmake_library VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(function)

add_executable(app main.cc)
target_link_libraries(app PRIVATE function)