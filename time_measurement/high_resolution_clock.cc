#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;
  using std::chrono::minutes;
  using std::chrono::seconds;

  const auto start = high_resolution_clock::now();
  {
    std::vector<float> data(100000000, 0);
    for (int i = 0; i < data.size(); ++i) data[i] = std::sin(i);
  }
  const auto end = high_resolution_clock::now();

  const auto tmp_duration = duration<float>(end - start);

  const auto time_elapsed_s = tmp_duration.count();
  const auto time_elapsed_ms =
      duration_cast<duration<float, std::milli>>(tmp_duration).count();
  const auto time_elapsed_min =
      duration_cast<duration<float, std::ratio<60, 1>>>(tmp_duration).count();

  std::cout << "time_elapsed"
            << " = " << time_elapsed_ms << " ms"
            << " = " << time_elapsed_s << " s"
            << " = " << time_elapsed_min << " min" << std::endl;
}