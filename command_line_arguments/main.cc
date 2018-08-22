#include <iostream>

int main(int argc, char** argv) {
  std::cout << "argument values:" << std::endl;
  for (int i = 0; i < argc; ++i)
    std::cout << "\targv[" << i << "] = " << argv[i] << std::endl;
  std::cout << std::endl;
  std::cout << "argument count:\n"
            << "\targc = " << argc << std::endl;
}