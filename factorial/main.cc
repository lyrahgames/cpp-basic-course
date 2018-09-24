#include <iostream>

int main() {
  std::cout << "Give me your fucking positive number:\n";
  int n;
  std::cin >> n;

  int factorial_int = 1;
  float factorial_float = 1.0f;
  double factorial_double = 1.0;

  std::cout << "n\tn! [int]\tn! [float]\tn! [double]\n";
  std::cout << "0:\t" << factorial_int << "\t" << factorial_float << "\t"
            << factorial_double << std::endl;

  for (int i = 1; i <= n; ++i) {
    factorial_int *= i;
    factorial_float *= i;
    factorial_double *= i;
    std::cout << i << ":\t" << factorial_int << "\t" << factorial_float << "\t"
              << factorial_double << std::endl;
  }
}