#include <iostream>
#include <string>

int main() {
  using namespace std;
  string previous{};
  string current;
  while (cin >> current) {
    if (previous == current) cout << current << "\n";
    previous = current;
  }
}