#include <iostream>
#include <sstream>

#include "square.h"

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <float>\n";
    return -1;
  }

  std::stringstream input(argv[1]);
  float x;
  input >> x;

  std::cout << "square(" << x << ") = " << square(x) << "!" << std::endl;
}