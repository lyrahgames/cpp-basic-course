#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  std::vector<float> data(10000);

  using std::chrono::duration;
  using std::chrono::system_clock;

  const std::chrono::time_point<system_clock> start = system_clock::now();
  {
    for (int i = 0; i < data.size(); ++i) data[i] = std::sin(i);
  }
  const std::chrono::time_point<system_clock> end = system_clock::now();

  const float time_elapsed = duration<float>(end - start).count();
  std::cout << "time_elapsed = " << time_elapsed << " s" << std::endl;
}