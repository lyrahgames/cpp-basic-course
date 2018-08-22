# Use CMake in subdirectories and for libraries

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
    -- Build files have been written to: /home/lyrahgames/projects/cpp-basic-course/cmake_subdirectory_and_library/build
    $   cmake --build .
    Scanning dependencies of target function
    [ 25%] Building CXX object function/CMakeFiles/function.dir/function.cc.o
    [ 50%] Linking CXX static library libfunction.a
    [ 50%] Built target function
    Scanning dependencies of target app
    [ 75%] Building CXX object CMakeFiles/app.dir/main.cc.o
    [100%] Linking CXX executable app
    [100%] Built target app
    $   ./app
    0
    1
    8
    27
    64
    125
    216
    343
    512
    729