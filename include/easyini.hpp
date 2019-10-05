#pragma once

#include <string>
#include <vector>

typedef struct ini_key_t {
  int section_index; // Section the key is in
  std::string name;
  std::string value;
} ini_key_t;

class ini {
public:
  ini(std::string source_filename); // Initialize by reading contents of a file
                                    // into memory
  ini(); // Initialize by creating a new ini object with filename "config.ini"

  std::string filename; // The name of the ini file

  void load(); // Reads data from a file
  void save(); // Saves data back to disk

  std::string
  read_key(std::string section_name,
           std::string key_name); // Reads a key's data from a section
  void write_key(std::string section_name, std::string key_name,
                 std::string data); // Writes data to a specific key
private:
  std::vector<std::string> sections;
  std::vector<ini_key_t> keys;
};