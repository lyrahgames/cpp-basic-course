#include <iostream>
#include <string>

int main() {
  using namespace std;
  cout << "Please enter two names:\n";
  string first, second;
  cin >> first >> second;
  cout << "Alphabetical order:\n"
       << ((first < second) ? (first) : (second)) << "\n"
       << ((first < second) ? (second) : (first)) << "\n";
}