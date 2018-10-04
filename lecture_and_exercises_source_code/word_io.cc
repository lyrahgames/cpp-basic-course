#include <iostream>
#include <string>

int main() {
  std::cout << "Geben Sie ein Wort an:" << std::endl;
  std::string word;
  std::cin >> word;
  std::cout << "Das Wort war '" << word << "'.\n";
}