#pragma once

#include <string>
#include <vector>

#define __EASYDATA_VER__ "0.1.0"

namespace easydata {

class ini {
public:
  ini(std::string source_filename);
  ini();

  std::string filename;

  void load(); // Reads data from a file
  void save(); // Saves data back to disk

  std::string
  read_key(std::string section_name,
           std::string key_name); // Reads a key's data from a section
  void write_key(std::string section_name, std::string key_name,
                 std::string key_value); // Writes data to a specific key
private:
  typedef struct ini_key_t {
    int section_index; // Section the key is in
    std::string name;
    std::string value;
  } ini_key_t;

  std::vector<std::string> sections;
  std::vector<ini_key_t> keys;
};

} // namespace easydata