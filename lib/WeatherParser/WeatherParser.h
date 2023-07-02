#pragma once

#include "../ConfigParser/ConfigParser.h"
#include "../APIParser/APIParser.h"
#include "../ConsolePrinter/ConsolePrinter.h"

#include "cpr/cpr.h"

#include <filesystem>

class WeatherForecast {
 public:

  explicit WeatherForecast(const std::filesystem::path&);

  static json ParseWeather(const std::string&, uint8_t);

 private:
  static const uint8_t kStatusCodeOK = 200;

  static inline std::string api_key_;

  static inline std::unordered_map<std::string, json> cache_coordinate_city_;

  std::filesystem::path file_;
};
