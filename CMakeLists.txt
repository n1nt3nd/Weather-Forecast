cmake_minimum_required(VERSION 3.23)
project(labwork10)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

add_executable(labwork10 main.cpp lib/ConfigParser/ConfigParser.h lib/ConfigParser/ConfigParser.cpp lib/WeatherParser/WeatherParser.h lib/WeatherParser/WeatherParser.cpp lib/APIParser/APIParser.cpp lib/APIParser/APIParser.h lib/ConsolePrinter/ConsolePrinter.cpp lib/ConsolePrinter/ConsolePrinter.h)

target_link_directories(labwork10 PRIVATE weather_parser)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(labwork10 PRIVATE nlohmann_json::nlohmann_json)

find_package(cpr CONFIG REQUIRED)
target_link_libraries(labwork10 PRIVATE cpr::cpr)

find_package(ftxui CONFIG REQUIRED)
target_link_libraries(labwork10 PRIVATE ftxui::dom ftxui::screen ftxui::component)
