#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>

int main() {
  std::mt19937 rng{std::random_device{}()};
  std::normal_distribution<float> distribution(0.5f, 1.0f);

  const auto oracle = std::bind(distribution, std::ref(rng));

  std::vector<float> random_numbers(100000);

  // for (int i = 0; i < 100; ++i) {
  //   random_numbers[i] = distribution(rng);
  // }

  std::generate(random_numbers.begin(), random_numbers.end(), oracle);

  // for (int i = 0; i < 100; ++i) {
  //   std::cout << random_numbers[i] << "\t";
  // }

  const auto mean =
      std::accumulate(random_numbers.begin(), random_numbers.end(), 0.0f) /
      static_cast<float>(random_numbers.size());

  float variance = 0.0f;
  std::for_each(
      random_numbers.begin(), random_numbers.end(),
      [&mean, &variance](float x) { variance += (x - mean) * (x - mean); });
  variance /= static_cast<float>(random_numbers.size() - 1);
  const float stddev = std::sqrt(variance);

  // std::copy(random_numbers.begin(), random_numbers.end(),
  //           std::ostream_iterator<float>{std::cout, "\t"});
  // std::cout << std::endl;

  std::cout << "mean = " << mean << std::endl;
  std::cout << "variance = " << variance << std::endl;

  std::cout << std::endl;
}