#include <iostream>

void inc(int* x) { ++(*x); }

void inc2(int& x) { ++x; }

int main() {
  int x = 3;
  int y = x;
  int* pointer = &x;
  int& reference = x;

  std::cout << "x = " << x << std::endl
            << "y = " << y << std::endl
            << "pointer = " << pointer << std::endl
            << "*pointer = " << *pointer << std::endl
            << "reference = " << reference << std::endl;

  x = 4;

  std::cout << "x = " << x << std::endl
            << "y = " << y << std::endl
            << "pointer = " << pointer << std::endl
            << "*pointer = " << *pointer << std::endl
            << "reference = " << reference << std::endl;

  // inc(&x);
  // inc2(x);
  ++reference;

  std::cout << "x = " << x << std::endl
            << "y = " << y << std::endl
            << "pointer = " << pointer << std::endl
            << "*pointer = " << *pointer << std::endl
            << "reference = " << reference << std::endl;
}