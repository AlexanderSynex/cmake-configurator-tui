cmake_minimum_required(VERSION 3.16)
project(tg-tui)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "tg-tui Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for tg-tui
set(tg-tui_Version_Major 0)
set(tg-tui_Version_Minor 1)
set(tg-tui_Version_Patch 0)
set(tg-tui_Version_Status "-dev")
set(PROJECT_VERSION
  "${tg-tui_Version_Major}.${tg-tui_Version_Minor}.${tg-tui_Version_Patch}${tg-tui_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(client src/main.cpp)
