#include <iostream>

int main() {
  using namespace std;
  cout << "Give number of persons in room " << endl;
  int n;
  cin >> n;

  float tmp = 1;
  for (int i = 2; i <= n; i++) {
    tmp *= (366 - i) / 365.0f;
  }
  float probability = 1 - tmp;

  cout << "The probability, that at least 2 persons have birthday at the ame "
          "day, if "
       << n << " persons are in the room is " << probability << endl;
}