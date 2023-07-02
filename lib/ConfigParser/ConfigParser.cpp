#include "ConfigParser.h"

#include <iostream>

ConfigParser::ConfigParser(const std::filesystem::path& path) : file_(path) {}

ConfigParser::~ConfigParser() {
  file_.close();
}

void ConfigParser::Parse() {
  try {
    data_ = json::parse(file_);
  } catch (...) {
    throw std::invalid_argument("Error with parsing config!");
  }

  config_.cities = data_.value<std::vector<std::string>>("cities", {"Minsk"});
  config_.days = data_.value<uint8_t>("days", 1);
  config_.frequency = data_.value<size_t>("frequency", 60);
}

Config ConfigParser::GetConfig() const {
  return config_;
}