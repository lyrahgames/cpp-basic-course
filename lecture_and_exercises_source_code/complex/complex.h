#ifndef COMPLEX_COMPLEX_H_
#define COMPLEX_COMPLEX_H_

#include <iostream>

namespace Math {

struct complex {
  float real;
  float imaginary;
};

complex operator+(complex x, complex y);
std::ostream& operator<<(std::ostream& os, complex x);

}  // namespace Math

#endif  // COMPLEX_COMPLEX_H_