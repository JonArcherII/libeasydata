#include <fstream>
#include <iostream>

#include "easyini.hpp"

using namespace easydata;

void ini::load() {
  std::ifstream file;
  int index = -1; // AKA: Unassigned

  file.open(ini::filename);

  if (!file.is_open()) return;

  // Loop through every line
  while (!file.eof()) {
    std::string line;
    std::getline(file, line);

    // Check if section, then append if it is
    if (line[0] == '[' && line.find(']') != std::string::npos) {
      ini::sections.push_back(line.substr(1, line.find(']') - 1));
      index = ini::sections.size() - 1;
    }

    // Check if valid key, then append if it is
    if (line.find('=') != std::string::npos) {
      ini::keys.push_back(
          (ini_key_t){index, line.substr(0, line.find('=')),
                      line.substr(line.find('=') + 1, line.size())});
      // Remove leading and trailing quotes
      if (ini::keys[ini::keys.size() - 1].value[0] == '\"' &&
          ini::keys[ini::keys.size() - 1]
                  .value[ini::keys[ini::keys.size() - 1].value.size() - 1] ==
              '\"')
	ini::keys[ini::keys.size() - 1].value =
	    ini::keys[ini::keys.size() - 1].value.substr(
	        1, ini::keys[ini::keys.size() - 1].value.size() - 2);
    }
  }

  file.close();
}

void ini::save() {
  std::ofstream file;
  file.open(ini::filename);
  // Loop through every section and dump its keys to a file
  for (size_t i = 0; i < ini::sections.size(); i++) {
    file << "[" << ini::sections[i] << "]" << std::endl;
    for (size_t j = 0; j < ini::keys.size(); j++)
      if ((size_t)ini::keys[j].section_index == i) {
	file << ini::keys[j].name << "=\"" << ini::keys[j].value << "\""
	     << std::endl;
      }
  }
  file.close();
}