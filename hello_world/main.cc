// Include the header file of the C++ STL library for input and output
// operations on the console.
#include <iostream>

// The execution of every C++ program starts with the main function.
// This function is obligatory.
// The first term defines the return type.
// For the main function it has to be 'int' for integer.
// The second term defines the name of the function.
// In the case of the main function the name must be 'main'.
// The parentheses enclose optional arguments of the function.
// Between the curly braces one defines the implementation of the function.
int main() {
  // 'std::cout' is the object which is used to put out information on the
  // console. This is done by using the streaming operator '<<'. Text and
  // strings are typically enclosed by '"'. The streaming operator '<<' can be
  // chained. 'std::endl' is an input for streams and defines a newline
  // character.
  std::cout << "Hello World!" << std::endl;
}