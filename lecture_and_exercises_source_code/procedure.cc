#include <iostream>

void hello(int x);
int hello();

int ask_for_number();

int main() {
  std::cout << "Number: " << ask_for_number() << std::endl;
  hello();
  hello(10);
  hello(-1);
}

void hello(int x) {
  if (x < 0) return;
  std::cout << "positive number: " << x << std::endl;
}

int hello() {
  std::cout << "Hello, World!\n";
  return 0;
}

int ask_for_number() {
  std::cout << "Give me number:\n";
  int x;
  std::cin >> x;
  return x;
}