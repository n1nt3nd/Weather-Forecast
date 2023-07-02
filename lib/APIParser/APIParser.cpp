#include "APIParser.h"

cpr::Response GetCoordinates(const std::string& city, const std::string& api_key) {
  return Get(Url{kCoordinatesAPI},
             Parameters{{"name", city}},
             Header{{"X-Api-Key", api_key}});
}

cpr::Response GetWeatherForecast(const std::string& coord_x, const std::string& coord_y, const std::string& days) {
  return Get(Url{kWeatherApi},
             Parameters{{"latitude", coord_x}, {"longitude", coord_y}, {"forecast_days", days},
                        {"hourly", "temperature_2m,relativehumidity_2m,apparent_temperature,weathercode,windspeed_10m"},
                        {"timezone", "auto"}, {"daily", "weathercode"}});
}

