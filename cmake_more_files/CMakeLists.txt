cmake_minimum_required(VERSION 3.0.0)
project(cmake_more_files VERSION 0.1.0 LANGUAGES CXX)

# The first argument names the executable.
# All other arguments add source files to the executable.
# Remember not to add header files!
add_executable(app main.cc function.cc)