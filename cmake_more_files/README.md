# Use CMake to compile more than one file

## Building
    mkdir build
    cd build
    cmake ..
    cmake --build .

## Execution
    ./app

## Example Usage
    $   mkdir build
    $   cd build
    $   cmake ..
    -- The CXX compiler identification is GNU 8.1.1
    -- Check for working CXX compiler: /usr/bin/c++
    -- Check for working CXX compiler: /usr/bin/c++ -- works
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /home/lyrahgames/projects/cpp-basic-course/cmake_library/build
    $   cmake --build .
    Scanning dependencies of target app
    [ 33%] Building CXX object CMakeFiles/app.dir/main.cc.o
    [ 66%] Building CXX object CMakeFiles/app.dir/function.cc.o
    [100%] Linking CXX executable app
    [100%] Built target app
    $   ./app
    f(0) = 0
    f(1) = 1
    f(2) = 4
    f(3) = 9
    f(4) = 16
    f(5) = 25
    f(6) = 36
    f(7) = 49
    f(8) = 64
    f(9) = 81
