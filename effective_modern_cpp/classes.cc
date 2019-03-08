#include <iostream>

using namespace std;

class Base {
 public:
  Base() : id_{count_} {
    ++count_;
    cout << id_ << "\tBase::Base()\tdefault constructor\n";
  }
  Base(const Base&) : id_{count_} {
    ++count_;
    cout << id_ << "\tBase::Base(const Base&)\tcopy constructor\n";
  }
  Base& operator=(const Base&) {
    cout << id_ << "\tBase::operator=(const Base&)\tcopy assignment\n";
    return *this;
  }
  Base(Base&&) : id_{count_} {
    ++count_;
    cout << id_ << "\tBase::Base(Base&&)\tmove constructor\n";
  }
  Base& operator=(Base&&) {
    cout << id_ << "\tBase::operator=(Base&&)\tmove assignment\n";
    return *this;
  }
  virtual ~Base() { cout << id_ << "\tBase::~Base()\tdestructor\n"; }

  Base& reference_qualifier() & {
    cout << id_ << "\tBase::reference_qualifier() &\n";
    return *this;
  }
  Base&& reference_qualifier() && {
    cout << id_ << "\tBase::reference_qualifier() &&\n";
    return std::move(*this);
  }

  const Base& print() const& {
    cout << id_ << "\tBase::print() const&\n";
    return *this;
  }
  const Base&& print() const&& {
    cout << id_ << "\tBase::print() const&&\n";
    return std::move(*this);
  }
  Base& print() & {
    cout << id_ << "\tBase::print() &\n";
    return *this;
  }
  Base&& print() && {
    cout << id_ << "\tBase::print() &&\n";
    return std::move(*this);
  }

  Base return_value() & {
    cout << id_ << "\tBase::return_value() &\n";
    return *this;
  }
  Base return_value() && {
    cout << id_ << "\tBase::return_value() &&\n";
    return std::move(*this);
  }

  virtual Base& virtual_function() & {
    cout << id_ << "\tBase::virtual_function() &\n";
    return *this;
  }
  virtual Base&& virtual_function() && {
    cout << id_ << "\tBase::virtual_function() &&\n";
    return std::move(*this);
  }

 protected:
  int id_;
  static int count_;
};

int Base::count_ = 0;

class Derived : public Base {
 public:
  Derived() { cout << id_ << "\tDerived::Derived()\tdefault constructor\n"; }
  Derived(const Derived&) {
    cout << id_ << "\tDerived::Derived(const Derived&)\tcopy constructor\n";
  }
  Derived& operator=(const Derived&) {
    cout << id_ << "\tDerived::operator=(const Derived&)\tcopy assignment\n";
    return *this;
  }
  Derived(Derived&&) {
    cout << id_ << "\tDerived::Derived(Derived&&)\tmove constructor\n";
  }
  Derived& operator=(Derived&&) {
    cout << id_ << "\tDerived::operator=(Derived&&)\tmove assignment\n";
    return *this;
  }
  ~Derived() { cout << id_ << "\tDerived::~Derived()\tdestructor\n"; }

  Derived& virtual_function() & override {
    cout << id_ << "\tDerived::virtual_function() & override\n";
    return *this;
  }
};

int main() {
  Base b{};
  b.reference_qualifier();
  b.print();

  // const auto& c = b;
  const Base c = b;
  c.print().print();

  Base{}.reference_qualifier();
  Base{}.print();

  Base{}.reference_qualifier().print().reference_qualifier().print();

  b.return_value();
  Base{}.return_value();

  Derived d{};
  d.print();
  d.virtual_function();
  // Derived e{d};
}