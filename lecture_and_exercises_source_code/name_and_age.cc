#include <iostream>
#include <string>

int main() {
  std::cout << "Geben Sie bitte Vor-, Nachname und Alter an:" << std::endl;
  std::string first_name;
  std::string last_name;
  int age;
  std::cin >> first_name >> last_name >> age;
  std::cout << "Dein Vorname ist '" << first_name << "' und dein Nachname ist '"
            << last_name << "' und dein Alter ist " << age << ".\n";
}