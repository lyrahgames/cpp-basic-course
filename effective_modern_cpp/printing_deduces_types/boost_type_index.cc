#include <boost/type_index.hpp>
#include <iostream>
#include <utility>

template <typename T>
void print_type(T&& parameter) {
  using boost::typeindex::type_id_with_cvr;
  using std::cout;
  cout << "T = " << type_id_with_cvr<T>().pretty_name() << '\n'
       << "decltype(parameter) = "
       << type_id_with_cvr<decltype(parameter)>().pretty_name() << '\n';
}

int main() {
  auto a = 42;
  auto b = &a;
  auto& c = a;
  const auto& d = a;
  auto&& e = a;

  print_type(a);
  print_type(b);
  print_type(c);
  print_type(d);
  print_type(e);
  print_type(std::move(a));
}