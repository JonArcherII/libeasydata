#include "easyini.hpp"

ini::ini() {
  filename = "config.ini";
}

ini::ini(std::string source_filename) {
  filename = source_filename;
  ini::load();
}