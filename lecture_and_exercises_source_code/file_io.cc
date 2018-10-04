#include <fstream>
#include <iostream>
#include <random>
#include <string>

int main(int argc, char** argv) {
  if (argc < 2 || argc > 3) {
    std::cout << "usage: " << argv[0]
              << " <output file path> <input file path>\n"
              << "You son of a bitch!\n";
    return -1;
  }

  if (argc == 3) {
    std::string file_path{argv[2]};
    std::fstream input_file{file_path, std::ios::in};

    while (input_file) {
      float number;
      input_file >> number;
      std::cout << number << std::endl;
    }
  }

  std::string file_path{argv[1]};
  std::fstream file{file_path, std::ios::out | std::ios::trunc};
  if (!file.is_open()) {
    std::cout << "File could not be opened! Suck my balls!\n";
    return -1;
  }

  std::mt19937 rng{std::random_device{}()};
  std::normal_distribution<float> distribution{};
  const int n = 10;

  for (int i = 0; i < n; ++i) {
    file << distribution(rng) << "\n";
  }
}