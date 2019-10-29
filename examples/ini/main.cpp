#include <easydata.hpp>
#include <iostream>

int main() {
  easydata::ini my_ini("my_example.ini");

  std::cout << "INI filename: " << my_ini.filename << std::endl;

  std::cout << "Setting keys..." << std::endl;
  my_ini.set_key("SECT1", "TEST", "YELLOW");
  my_ini.set_key("section_2", "name", "Jon");

  std::cout << "Getting keys..." << std::endl;
  std::cout << my_ini.get_key("SECT1", "TEST") << std::endl;
  std::cout << my_ini.get_key("section_2", "name") << std::endl;

  std::cout << "Saving file..." << std::endl;
  my_ini.save();

  return 0;
}