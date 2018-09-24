#include <iostream>
#include <string>

int main() {
  const std::string password = "MOJO";

  std::cout << "Give me my password...FAST...I am hungry:\n";
  std::string input;
  std::cin >> input;

  while (input != password) {
    std::cout << "Access denied, jerk!\n";
    std::cin >> input;
  }

  std::cout << "Oh, behave!\n";
}