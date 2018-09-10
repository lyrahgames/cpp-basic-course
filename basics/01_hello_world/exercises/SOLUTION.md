# Hello World!: Solutions

## Exercise: Changing the Executable Name
The code will again be compiled with the compiler `g++`.
Therefore one has to use the flag '-o' to name the executable.

    g++ -o hello_world hello_main.cc

## Exercise: No Given Executable Name
First, one runs the compiler without any name argument.

    g++ hello_main.cc

Given that there was no error, we know that the code was successfully compiled.
Looking into the source directory we see a new file called 'a.out' or 'a.exe'.
This is the default name of the compiled executable.

## Exercise: Changing the Program Output

```cpp
    #include <iostream>
    int main(){
        std::cout << "Hello, programming!\nHere we go!\n";
    }
```

```cpp
    #include <iostream>
    int main(){
        using namespace std;
        cout << "Hello, programming!" << endl
             << "Here we go!" << endl;
    }
```