#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <integer>\n";
    return -1;
  }

  std::stringstream input(argv[1]);
  int n;
  input >> n;
  if (input.fail()) {
    std::cout << "Du hast Müll angegeben!\n";
    return -1;
  }

  std::cout << "n = " << n << std::endl;
}