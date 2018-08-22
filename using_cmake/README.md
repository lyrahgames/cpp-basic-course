# Using CMake

## Building
### Linux
We want to use a so called out-of-source build.
With `cmake ..` CMake first configures the build system for the project.
Please remember that you have to call this command only once.
On Linux CMake uses Make by default.
Therefore the command `cmake --build .` builds the actual application.
Instead of `cmake --build .` one can use `make`.
Even if one changes the file 'CMakeLists.txt' calling `make` or `cmake --build .` makes sure to reconfigure the project's build files.

    mkdir build
    cd build
    cmake ..
    cmake --build .


### Windows
    mkdir build
    cd build
    cmake -G "MinGW Makefiles" ..
    cmake --build .

## Execution
    ./using_cmake

## Example Usage
    $   mkdir build
    $   cd build
    $   cmake ..
    $   cmake --build .
    $   ./using_cmake
    This application was compiled using CMake.
