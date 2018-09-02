find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

set(CMAKE_AUTOMOC ON)

add_library(qcustomplot qcustomplot.cpp)
target_link_libraries(qcustomplot PUBLIC Qt5::Widgets Qt5::PrintSupport)
target_compile_features(qcustomplot PUBLIC cxx_std_11)
target_include_directories(qcustomplot PUBLIC .)

add_library(Qt5::CustomPlot ALIAS qcustomplot)