#pragma once

#include "cpr/cpr.h"

#include <string>

using cpr::Get;
using cpr::Parameters;
using cpr::Url;
using cpr::Header;

const std::string kCoordinatesAPI = "https://api.api-ninjas.com/v1/city";

const std::string kWeatherApi = "https://api.open-meteo.com/v1/forecast";

cpr::Response GetCoordinates(const std::string& city, const std::string& api_key);

cpr::Response GetWeatherForecast(const std::string& coord_x, const std::string& coord_y, const std::string& days);



