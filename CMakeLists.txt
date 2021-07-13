cmake_minimum_required(VERSION 3.20.5)

project(Casino VERSION 0.0.3)

add_executable("${PROJECT_NAME}" main.cpp)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES main.cpp DESTINATION src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
