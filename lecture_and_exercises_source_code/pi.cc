#include <chrono>
#include <iostream>
#include <random>

// !!!bad idea!!!:
// float random(){
//   std::mt19937 rng{std::random_device{}()};
//   std::uniform_real_distribution<float> distribution{0, 1};
//   return distribution(rng);
// }

int main() {
  std::mt19937 rng{std::random_device{}()};
  std::uniform_real_distribution<float> distribution{0, 1};

  const auto start = std::chrono::high_resolution_clock::now();

  int n = 1000000;
  int k = 0;

  for (int i = 0; i < n; ++i) {
    const float x = distribution(rng);
    const float y = distribution(rng);
    if (x * x + y * y <= 1) ++k;
  }

  const float pi = 4 * static_cast<float>(k) / n;

  const auto end = std::chrono::high_resolution_clock::now();

  const auto time = std::chrono::duration<float>(end - start).count();

  std::cout << "pi = " << pi << std::endl
            << "time = " << time << " s" << std::endl;
}