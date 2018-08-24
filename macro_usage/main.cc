#include <iostream>

#ifdef NDEBUG
#define CAPTURE(X)
#else
#define CAPTURE(X)                                            \
  std::cout << #X << " = " << (X) << "\t\tfile: " << __FILE__ \
            << "\t\tline: " << __LINE__ << std::endl
#endif

int main() {
  int n = 10;
  int m = 2;
  CAPTURE(n);
  CAPTURE(m);
  CAPTURE(n + m);
}