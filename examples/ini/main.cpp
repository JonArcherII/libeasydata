#include <easyini.hpp>
#include <iostream>

int main() {
  easydata::ini my_ini("my_example.ini");
  std::cout << "INI filename: " << my_ini.filename << std::endl;

  std::cout << "Writing keys..." << std::endl;
  my_ini.write_key("SECT1", "TEST", "YELLOW");
  my_ini.write_key("SECT1", "Name", "Jon");
  my_ini.write_key("section_2", "git", "torvalds");

  std::cout << "Reading back keys..." << std::endl;
  std::cout << my_ini.read_key("SECT1", "TEST") << std::endl;
  std::cout << my_ini.read_key("SECT1", "Name") << std::endl;
  std::cout << my_ini.read_key("section_2", "git") << std::endl;

  std::cout << "Saving file..." << std::endl;
  my_ini.save();

  return 0;
}