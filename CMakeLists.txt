cmake_minimum_required(VERSION 2.8.9)
project(SGpp_Example_Application)

include_directories(include)

set(SOURCES src/main_quadrature.cpp src/example_function.cpp)

add_executable(quadrature ${SOURCES})
