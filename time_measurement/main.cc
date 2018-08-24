#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::vector<float> data(10000);

  using std::chrono::duration;
  using std::chrono::system_clock;
  const auto start = system_clock::now();
  {
    for (int i = 0; i < data.size(); ++i) data[i] = std::sin(i);
  }
  const auto end = system_clock::now();
  const auto time_elapsed = duration<float>(end - start).count();
  std::cout << "time_elapsed = " << time_elapsed << " s" << std::endl;
}