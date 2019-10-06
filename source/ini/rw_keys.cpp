#include "easyini.hpp"

using namespace easydata;

std::string ini::read_key(std::string section_name, std::string key_name) {
  int index = -1; // AKA: Unassigned

  // Get index for section
  for (size_t i = 0; i < ini::sections.size(); i++)
    if (section_name.compare(ini::sections[i]) == 0) index = i;

  // Loop through keys to find ones with a matching index and name
  for (size_t i = 0; i < ini::keys.size(); i++)
    if (ini::keys[i].section_index == index &&
        key_name.compare(ini::keys[i].name) == 0)
      return ini::keys[i].value;

  // If we get here, then the does not exist, and we return an empty string
  return "";
}

void ini::write_key(std::string section_name, std::string key_name,
                    std::string key_value) {
  int index = -1; // AKA: Unassigned

  // Get index for section
  for (size_t i = 0; i < ini::sections.size(); i++)
    if (section_name.compare(ini::sections[i]) == 0) index = i;

  // Loop through keys to find ones with a matching index and name
  for (size_t i = 0; i < ini::keys.size(); i++)
    if (ini::keys[i].section_index == index &&
        key_name.compare(ini::keys[i].name) == 0) {
      ini::keys[i].value = key_value;
      return;
    }

  // If our index is negative, then the section didn't exist and it needs to be
  // created
  if (index < 0) {
    ini::sections.push_back(section_name);
    index = ini::sections.size() - 1;
  }

  // If we get to this point, the key does not exist and needs to be created,
  // and we already have a section index
  ini::keys.push_back((ini_key_t){index, key_name, key_value});
}