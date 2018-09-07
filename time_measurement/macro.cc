#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

#ifdef NDEBUG
#define CAPTURE_TIME_BASE(X) X
#define CAPTURE_TIME(NAME, X) X
#else
#define CAPTURE_TIME_BASE(X)                                               \
  {                                                                        \
    const auto start = std::chrono::high_resolution_clock::now();          \
    { X }                                                                  \
    const auto end = std::chrono::high_resolution_clock::now();            \
    std::cout << "time = "                                                 \
              << std::chrono::duration<float>(end - start).count() << " s" \
              << std::endl;                                                \
  }
#define CAPTURE_TIME(NAME, X) \
  std::cout << NAME << ": ";  \
  CAPTURE_TIME_BASE(X);
#endif

int main() {
  std::vector<float> data(10, 0);

  CAPTURE_TIME("Test", {
    for (int i = 0; i < data.size(); ++i) data[i] = std::sin(i);
  });

  for (auto x : data) {
    std::cout << x << "\t";
  }
  std::cout << std::endl;
}