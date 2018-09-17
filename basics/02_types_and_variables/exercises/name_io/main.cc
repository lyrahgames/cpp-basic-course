#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your first and last name followed by a newline:\n";
  std::string first, last;
  std::cin >> first >> last;
  std::cout << "Your first name is " << first << " and your last name is "
            << last << "!\n";
}