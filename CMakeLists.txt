cmake_minimum_required(VERSION 3.16)
project(Toodle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

add_executable(Toodle main.cpp
        Player.hpp
        Player.cpp
        Platform.hpp
        Platform.cpp)

target_link_libraries(Toodle PRIVATE SFML::Graphics SFML::Audio)