#pragma once

#include "nlohmann/json.hpp"

#include <algorithm>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

using json = nlohmann::json;

struct Config {
  std::vector<std::string> cities;
  uint8_t days;
  size_t frequency;
};

class ConfigParser {
 public:

  explicit ConfigParser(const std::filesystem::path& path);

  void Parse();

  ~ConfigParser();

  Config GetConfig() const;

 private:
  std::ifstream file_;
  json data_;
  Config config_;
};