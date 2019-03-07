cmake_minimum_required(VERSION 3.10)
find_package(Boost REQUIRED)
add_executable(type_index boost_type_index.cc)
target_link_libraries(type_index PRIVATE Boost::boost)