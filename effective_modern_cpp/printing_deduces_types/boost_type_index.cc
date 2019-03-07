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
  auto value = 42;
  auto address = &value;
  auto& reference = value;
  const auto& const_reference = value;
  auto&& universal_reference_lvalue = value;
  auto&& universal_reference_rvalue = 42;
  auto value_const_reference = const_reference;
  auto& reference_const_reference = const_reference;
  auto list = {1, 2, 3};
  auto typed_initializer = static_cast<int>(1.5);

  print_type<decltype(value)>();
  print_type<decltype(address)>();
  print_type<decltype(reference)>();
  print_type<decltype(const_reference)>();
  print_type<decltype(universal_reference_lvalue)>();
  print_type<decltype(universal_reference_rvalue)>();
  print_type<decltype(value_const_reference)>();
  print_type<decltype(reference_const_reference)>();
  print_type<decltype(std::move(value))>();
  print_type<decltype(list)>();
  print_type<decltype(typed_initializer)>();
}