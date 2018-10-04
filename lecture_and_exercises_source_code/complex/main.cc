#include <complex>
#include <iostream>

#include "complex.h"

int main() {
  using namespace std;
  // using namespace Math;
  Math::complex a{1, 2};
  Math::complex b{3, 4};
  Math::complex c = a + b;

  cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
}
