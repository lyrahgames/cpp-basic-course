#include "complex.h"

namespace Math {

complex operator+(complex x, complex y) {
  return {x.real + y.real, x.imaginary + y.imaginary};
}

std::ostream& operator<<(std::ostream& os, complex z) {
  return os << z.real << " + " << z.imaginary << "i";
}

}  // namespace Math
