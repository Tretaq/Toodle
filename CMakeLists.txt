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
        Platform.cpp
        Constants.hpp
        World.hpp
        World.hpp
        World.cpp
        MovingPlatform.cpp
        MovingPlatform.hpp
        BreakPlatform.cpp
        BreakPlatform.hpp
        DisappearPlatform.cpp
        DisappearPlatform.hpp)

target_link_libraries(Toodle PRIVATE SFML::Graphics SFML::Audio)

add_custom_command(TARGET Toodle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Toodle>/assets
)