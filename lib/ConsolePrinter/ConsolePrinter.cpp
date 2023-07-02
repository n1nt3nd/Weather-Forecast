#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter(const Config& cfg) : cfg_(cfg) {
  code_to_name_map_[0] = "Sunny";

  code_to_name_map_[1] = "Mainly clear";
  code_to_name_map_[2] = "Party cloudy";
  code_to_name_map_[3] = "Overcast";

  code_to_name_map_[45] = code_to_name_map_[48] = "Fog";

  code_to_name_map_[51] = "Light drizzle";
  code_to_name_map_[53] = "Moderate drizzle";
  code_to_name_map_[55] = "Dense drizzle";

  code_to_name_map_[61] = "Slight rain";
  code_to_name_map_[63] = "Moderate rain";
  code_to_name_map_[65] = "Heavy rain";

  code_to_name_map_[66] = "Light Freezing Rain";
  code_to_name_map_[67] = "Heavy Freezing Rain";

  code_to_name_map_[71] = "Slight snowfall";
  code_to_name_map_[73] = "Moderate snowfall";
  code_to_name_map_[75] = "Heavy snowfall";

  code_to_name_map_[77] = "Snow grains";

  code_to_name_map_[80] = "Slight rain showers";
  code_to_name_map_[81] = "Moderate rain showers";
  code_to_name_map_[82] = "Violent rain showers";

  code_to_name_map_[85] = "Slight snow showers";
  code_to_name_map_[86] = "Heavy snow showers";

  code_to_name_map_[95] = code_to_name_map_[96] = code_to_name_map_[99] = "Thunderstorm";

  code_to_image_map_[kUnknownCode] = []() {
    return std::vector<Element>{
        text("    .-.      "),
        text("     __)     "),
        text("    (        "),
        text("     `-᾿      "),
        text("      •      ")};
  };

  code_to_image_map_[0] = []() {
    return std::vector<Element>{
        text(R"(    \   /    )"),
        text("     .-.     "),
        text("  ‒ (   ) ‒  "),
        text("     `-᾿     "),
        text(R"(    /   \    )")};
  };

  code_to_image_map_[1] =
  code_to_image_map_[2] =
  code_to_image_map_[3] = []() {
    return std::vector<Element>{
        text("             "),
        text("     .--.    "),
        text("  .-(    ).  "),
        text(" (___.__)__) "),
        text("             ")};
  };

  code_to_image_map_[45] =
  code_to_image_map_[48] = []() {
    return std::vector<Element>{
        text("             "),
        text(" _ - _ - _ - "),
        text("  _ - _ - _  "),
        text(" _ - _ - _ - "),
        text("             ")};
  };

  code_to_image_map_[51] =
  code_to_image_map_[53] =
  code_to_image_map_[53] =
  code_to_image_map_[61] = []() {
    return std::vector<Element>{
        text("     .-.     "),
        text("    (   ).   "),
        text("   (___(__)  "),
        text("    ʻ ʻ ʻ ʻ  "),
        text("   ʻ ʻ ʻ ʻ   ")};
  };

  code_to_image_map_[56] =
  code_to_image_map_[57] =
  code_to_image_map_[66] =
  code_to_image_map_[67] = []() {
    return std::vector<Element>{
        text("     .-.     "),
        text("    (   ).   "),
        text("   (___(__)  "),
        text("    ʻ * ʻ *  "),
        text("   * ʻ * ʻ   ")};
  };

  code_to_image_map_[63] =
  code_to_image_map_[65] = []() {
    return std::vector<Element>{
        text("     .-.     "),
        text("    (   ).   "),
        text("   (___(__)  "),
        text("  ‚ʻ‚ʻ‚ʻ‚ʻ   "),
        text("  ‚ʻ‚ʻ‚ʻ‚ʻ   ")};
  };

  code_to_image_map_[71] =
  code_to_image_map_[73] =
  code_to_image_map_[75] =
  code_to_image_map_[77] = []() {
    return std::vector<Element>{
        text("     .-.     "),
        text("    (   ).   "),
        text("   (___(__)  "),
        text("   * * * *   "),
        text("  * * * *    ")};
  };

  code_to_image_map_[95] =
  code_to_image_map_[96] =
  code_to_image_map_[99] = []() {
    return std::vector<Element>{
        text("     .-.     "),
        text("    (   ).   "),
        text("   (___(__)  "),
        text("   * * * *   "),
        text("  * * * *    ")};
  };

  code_to_image_map_[85] =
  code_to_image_map_[86] = []() {
    return std::vector<Element>{
        text(R"( _`/\"\".-.    )"),
        text(R"(  ,\_(   ).  )"),
        text("   /(___(__) "),
        text("    * * * *  "),
        text("   * * * *   ")};
  };

  code_to_image_map_[80] =
  code_to_image_map_[81] =
  code_to_image_map_[82] = []() {
    return std::vector<Element>{
        text(R"( _`/\"\"-.   )"),
        text(R"(  ,\\_(   ).  )"),
        text("   /(___(__) "),
        text("   ‚ʻ‚ʻ‚ʻ‚ʻ  "),
        text("   ‚ʻ‚ʻ‚ʻ‚ʻ  ")};
  };

}

std::string ConsolePrinter::GetName(uint8_t code) {
  if (code_to_name_map_.find(code) != code_to_name_map_.end())
    return code_to_name_map_[code];

  return "Unknown";
}

std::vector<Element> ConsolePrinter::GetDescriptionOfDay(const json& weather, uint8_t day, const std::string& time) {
  uint8_t begin{};
  uint8_t end{};
  if (time == "Morning") {
    begin = kBeginOfMorning;
    end = kEndOfMorning;
  } else if (time == "Noon") {
    begin = kBeginOfNoon;
    end = kEndOfNoon;
  } else if (time == "Evening") {
    begin = kBeginOfEvening;
    end = kEndOfEvening;
  } else {
    begin = kBeginOfNight;
    end = kEndOfNight;
  }

  std::vector<Element> description;
  description.reserve(kInformationDay);

  size_t index_current_day = kHourInDay * day;
  description.push_back(text(GetName(weather["hourly"]["weathercode"][index_current_day + end].get<uint8_t>())));
  std::string temperatures = Average(weather["hourly"]["temperature_2m"],
                                     index_current_day + begin,
                                     index_current_day + end);
  temperatures += "(" + Average(weather["hourly"]["apparent_temperature"],
                                index_current_day + begin,
                                index_current_day + end) + ")";

  description.push_back(text(temperatures + " °C"));

  description.push_back(text(Average(weather["hourly"]["windspeed_10m"],
                                     index_current_day + begin,
                                     index_current_day + end) + " km/h"));

  description.push_back(text(Average(weather["hourly"]["relativehumidity_2m"],
                                     index_current_day + begin,
                                     index_current_day + end) + "%"));

  return description;
}

std::vector<Element> ConsolePrinter::GetImage(uint8_t code) {
  if (code_to_image_map_.find(code) != code_to_image_map_.end())
    return code_to_image_map_[code]();

  return code_to_image_map_[kUnknownCode]();
}

void ConsolePrinter::Start() {
  auto screen = ScreenInteractive::TerminalOutput();

  auto it_cur_city = cfg_.cities.begin();

  auto component = Renderer([&] {
    json weather_forecast;
    Elements windows;
    try {
      weather_forecast = WeatherForecast::ParseWeather(*it_cur_city, cfg_.days);
    } catch (const std::exception& error) {
      windows.push_back(vbox({text("Error"), text(error.what())}));
      return vbox(std::move(windows));
    }

    for (size_t day = 0; day < cfg_.days; ++day) {
      Elements row;
      row.reserve(time_of_day_.size());
      for (const auto& time : time_of_day_) {
        row.push_back(vbox({text(time) | center | bold,
                            separator(),
                            hbox({
                                     vbox(GetImage(GetWeatherCode(weather_forecast, day, time))),
                                     vbox(GetDescriptionOfDay(weather_forecast, day, time))
                                 })})
                          | border | size(WIDTH, EQUAL, kSizeOfBox));
      }

      windows.push_back(window(
          text(weather_forecast["daily"]["time"][day].get<std::string>() + " " + *it_cur_city) | center,
          vbox(hbox(std::move(row)))));
    }

    ClearScreen();
    return vbox(std::move(windows));
  });

  component = CatchEvent(component, [&](const Event& event) {
    if (event == Event::Escape)
      screen.ExitLoopClosure()();
    else if (event.input() == "+") {
      if (cfg_.days < kMaxDays) cfg_.days++;
    } else if (event.input() == "-") {
      if (cfg_.days > kMinDays) cfg_.days--;
    } else if (event.input() == "n") {
      ++it_cur_city;
      if (it_cur_city == cfg_.cities.end())
        it_cur_city = cfg_.cities.begin();
    } else if (event.input() == "p") {
      if (it_cur_city == cfg_.cities.begin())
        it_cur_city = cfg_.cities.end();
      --it_cur_city;
    }

    return false;
  });

  Loop loop(&screen, component);
  auto last_time = std::chrono::steady_clock::now();
  while (!loop.HasQuitted()) {
    auto cur_time = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::seconds>(cur_time - last_time).count() > cfg_.frequency) {
      last_time = cur_time;
      screen.Post(ftxui::Event::Custom);
    }
    loop.RunOnce();
  }

}

uint8_t ConsolePrinter::GetWeatherCode(const json& weather, uint8_t day, const std::string& time) const {
  uint8_t end{};
  if (time == "Morning") {
    end = kEndOfMorning;
  } else if (time == "Noon") {
    end = kEndOfNoon;
  } else if (time == "Evening") {
    end = kEndOfEvening;
  } else {
    end = kEndOfNight;
  }

  size_t cur = day * kHourInDay + end;
  return weather["hourly"]["weathercode"][cur].get<size_t>();
}

std::string ConsolePrinter::Average(const nlohmann::basic_json<>& cur_json, size_t left, size_t right) const {
  size_t count = 0;
  double sum = 0.0;
  for (size_t i = left; i <= right; ++i)
    if (!cur_json.is_null()) {
      ++count;
      sum += cur_json[i].get<double>();
    }

  return count != 0 ? std::to_string(int(sum / count)) : "null";
}

void ConsolePrinter::ClearScreen() const {
#ifdef WINDOWS
  std::system("cls");
#else
  std::system("clear");
#endif
}