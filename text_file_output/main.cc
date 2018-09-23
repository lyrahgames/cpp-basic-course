#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (2 != argc) {
    std::cout << "usage: " << argv[0] << " <file name>\n";
    return -1;
  }

  std::string file_path{argv[1]};
  std::fstream file(file_path, std::ios::in);
  if (!file) {
    std::cout << "The file '" << file_path << "' could not be opened!\n";
    return -1;
  }

  while (file) {
    std::string line;
    std::getline(file, line);
    if (!file) break;
    std::cout << line << std::endl;
  }
}