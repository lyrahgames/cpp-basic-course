cmake_minimum_required(VERSION 3.10)
project(plot VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(QCustomPlot)

add_executable(plot main.cc)
target_link_libraries(plot PRIVATE Qt5::CustomPlot)