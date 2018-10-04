#include <chrono>
#include <iostream>
#include <random>
#include <sstream>

#include <matrix.h>

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <dimension>\n";
    return -1;
  }

  std::stringstream input{argv[1]};
  int dimension;
  input >> dimension;
  if (input.fail() || dimension <= 0) {
    std::cout << "Dimension could not be read!\n";
    return -1;
  }

  std::mt19937 rng{std::random_device{}()};
  std::normal_distribution<float> distribution{};

  Math::Matrix m(dimension, 0.0f);
  Math::Matrix n(dimension, 0.0f);

  std::cout << "Give me some matrix elements:\n";
  Math::Matrix p(dimension, 0.0f);
  std::cin >> p;
  std::cout << std::endl << p << std::endl;

  for (int i = 0; i < dimension; ++i) {
    for (int j = 0; j < dimension; ++j) {
      m(i, j) = distribution(rng);
      n(i, j) = distribution(rng);
    }
  }

  const auto start = std::chrono::high_resolution_clock::now();
  m = m + n;
  const auto end = std::chrono::high_resolution_clock::now();
  const auto time = std::chrono::duration<float>(end - start).count();

  std::cout << "time = " << time << " s" << std::endl;

  // std::cout << "m*n = \n" << m * n << std::endl;
}