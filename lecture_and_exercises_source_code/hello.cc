#include <cmath>
#include <iostream>

int main() {
  using namespace std;
  // cout << "Hello, World!" << endl << "More text!" << endl;
  cout << "Start\n";
  for (int i = 0; i < 100000000; ++i) {
    float x = std::sin(i);
  }
  cout << "end\n";
}