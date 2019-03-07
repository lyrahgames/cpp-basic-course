#include <boost/type_index.hpp>
#include <iostream>
#include <utility>

template <typename T>
void print_type() {
  using boost::typeindex::type_id_with_cvr;
  using std::cout;
  cout << "T = " << type_id_with_cvr<T>().pretty_name() << '\n';
}

int main() {
  auto a = 42;
  auto b = &a;
  auto& c = a;
  const auto& d = a;
  auto&& e = a;   // universal reference with lvalue
  auto&& f = 42;  // universal reference with rvalue
  auto g = d;
  auto& h = d;

  print_type<decltype(a)>();
  print_type<decltype(b)>();
  print_type<decltype(c)>();
  print_type<decltype(d)>();
  print_type<decltype(e)>();
  print_type<decltype(f)>();
  print_type<decltype(g)>();
  print_type<decltype(h)>();
  print_type<decltype(std::move(a))>();
}