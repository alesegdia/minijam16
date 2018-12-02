cmake_minimum_required(VERSION 2.8.11)

project(thevaker2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(module/aether)

include("module/aether/cmake/Build.cmake")

file(GLOB_RECURSE GAMESOURCES "src/*.cpp" "src/*.h src/**/*.cpp" "src/**/*.h")

ADD_AETHER_TARGET(thevaker2 "${GAMESOURCES}")


set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")


