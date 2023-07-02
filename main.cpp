#include "lib/WeatherParser/WeatherParser.h"

int main() {
  std::filesystem::path file_path = "/home/apodgorny/labwork-10-n1nt3nd/cfg.json";
  WeatherForecast forecast(file_path);
}