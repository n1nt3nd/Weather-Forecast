#pragma once

#include "../ConfigParser/ConfigParser.h"
#include "../WeatherParser/WeatherParser.h"

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/loop.hpp"

#include <chrono>
#include <functional>
#include <map>
#include <string>

using namespace ftxui;

class ConsolePrinter {
 public:
  explicit ConsolePrinter(const Config& cfg);

  void Start();

 private:

  Config cfg_;

  std::string GetName(uint8_t);

  std::vector<Element> GetImage(uint8_t);

  std::vector<Element> GetDescriptionOfDay(const json&, uint8_t, const std::string&);

  uint8_t GetWeatherCode(const json&, uint8_t, const std::string&) const;

  std::string Average(const nlohmann::basic_json<>&, size_t, size_t) const;

  void ClearScreen() const;

  const std::vector<std::string> time_of_day_ = {"Morning", "Noon", "Evening", "Night"};

  const uint8_t kUnknownCode = 205;
  const uint8_t kMaxDays = 16;
  const uint8_t kMinDays = 1;
  const uint8_t kBeginOfMorning = 6;
  const uint8_t kEndOfMorning = 12;
  const uint8_t kBeginOfNoon = 13;
  const uint8_t kEndOfNoon = 18;
  const uint8_t kBeginOfEvening = 19;
  const uint8_t kEndOfEvening = 23;
  const uint8_t kBeginOfNight = 0;
  const uint8_t kEndOfNight = 6;
  const uint8_t kHourInDay = 24;
  const uint8_t kSizeOfBox = 80;
  const uint8_t kInformationDay = 4;

  std::unordered_map<uint8_t, std::function<std::vector<Element>()>> code_to_image_map_;
  std::unordered_map<uint8_t, std::string> code_to_name_map_;
};