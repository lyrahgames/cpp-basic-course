#include <utility>

template <typename T>
struct type_displayer;

int main() {
  auto a = 42;
  auto b = &a;
  auto& c = a;
  const auto& d = a;
  auto&& e = a;

  type_displayer<decltype(a)>{};
  type_displayer<decltype(b)>{};
  type_displayer<decltype(c)>{};
  type_displayer<decltype(d)>{};
  type_displayer<decltype(e)>{};
  type_displayer<decltype((a))>{};
}