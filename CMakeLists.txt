cmake_minimum_required(VERSION 3.10)
project(DatabaseServer)
set(CMAKE_CXX_STANDARD 17)
add_executable(planet_range_arudh
src/planet_range_arudh.cpp
src/aarudh.cpp
src/houseCounter.cpp
src/report.cpp
)

 target_include_directories(planet_range_arudh PRIVATE include)
