cmake_minimum_required(VERSION 4.2.1)

project(whatsdoin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(${PROJECT_NAME} src/main.cpp src/commands.cpp)

install(TARGETS whatsdoin DESTINATION bin)