cmake_minimum_required(VERSION 3.14)

project(Lcd LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

include(FetchContent)

find_package(pigpio QUIET)
if (NOT TARGET pigpio::core)
    message(STATUS "pigpio was not found. Fetching from git")
    FetchContent_Declare(
        pigpio
        GIT_REPOSITORY https://github.com/bog-dan-ro/pigpio.git
        GIT_TAG master
        CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        )
    FetchContent_MakeAvailable(pigpio)
endif()

add_executable(Lcd
  main.cpp
  LiquidCrystal.cpp
  LiquidCrystal.h
)
target_link_libraries(Lcd pigpio::core Threads::Threads)
