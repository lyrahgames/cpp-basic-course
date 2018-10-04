#include <iostream>

int main() {
  int x;
  int y;
  std::cin >> x >> y;
  std::cout << "The numbers are " << x << " and " << y << "!\n";

  if (x == y) {
    std::cout << "The numbers are equal!\n";
  } else if (x < y) {
    std::cout << "The first number is lower than the second!\n";
  } else if (x > y) {
    std::cout << "The first number is bigger than the second!\n";
  }

  if ((x < 7) && (y != 5)) {
    std::cout << "Jackpot!\n";
  }

  if (x = y) {
    std::cout << "Fail!\n";
  }

  std::cout << "The numbers are " << x << " and " << y << "!\n";
}