#include <iostream>
#include <tuple>

namespace unscoped {
enum color { red, green, blue };
}

namespace scoped {
enum class color { red, green, blue };
}

namespace tuple_field_reference {
using node = std::tuple<int, int, bool>;
enum node_field { key, value, empty };
}  // namespace tuple_field_reference

int main() {
  {
    using namespace unscoped;
    // Initializing unscoped enum type is not really desriptive.
    // Additionally 'red', 'green' and 'blue' pollute the namespace 'unscoped'.
    auto c = red;
  }  // namespace intmain()

  {
    using namespace scoped;
    // Initializing scoped enum type is clear and desriptive.
    // 'red', 'green' and 'blue' do not pollute the namespace 'scoped'.
    auto c = color::red;
  }

  {
    using std::cout;
    using std::get;
    using namespace tuple_field_reference;
    // Unscoped enums can be useful for accessing the fields of the standard
    // tuple type.
    tuple_field_reference::node n{1, 2, false};
    cout << "n = {" << get<key>(n) << ", " << get<value>(n) << ", "
         << get<empty>(n) << "}\n";
  }

}  // namespace intmain()