#include <iostream>
#include "function.h"

int main() {
  for (int i = 0; i < 10; ++i)
    std::cout << "f(" << i << ") = " << f(i) << std::endl;
}