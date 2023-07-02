#include "WeatherParser.h"

WeatherForecast::WeatherForecast(const std::filesystem::path& path) : file_(path) {
  ConfigParser config_parser(file_);
  config_parser.Parse();
  Config cfg = config_parser.GetConfig();
  ConsolePrinter printer(cfg);
  std::string api_key;
  std::ifstream in("../key.txt");
  in >> api_key_;
  printer.Start();
}

json WeatherForecast::ParseWeather(const std::string& city, uint8_t days) {
  json json_coordinates;
  if (cache_coordinate_city_.find(city) == cache_coordinate_city_.end()) {
    auto coordinates = GetCoordinates(city, api_key_);
    if (coordinates.status_code != WeatherForecast::kStatusCodeOK)
      throw std::domain_error{coordinates.error.message};

    json_coordinates = json::parse(coordinates.text.substr(1, coordinates.text.size() - 2));
    cache_coordinate_city_[city] = json_coordinates;
  } else json_coordinates = cache_coordinate_city_[city];

  std::string coord_x = to_string(json_coordinates.at("latitude"));
  std::string coord_y = to_string(json_coordinates.at("longitude"));

  auto response_forecast = GetWeatherForecast(coord_x, coord_y, std::to_string(days));
  if (response_forecast.status_code != WeatherForecast::kStatusCodeOK)
    throw std::domain_error{response_forecast.error.message};
  json json_forecast = json::parse(response_forecast.text);

  return json_forecast;
}