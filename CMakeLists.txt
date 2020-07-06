cmake_minimum_required(VERSION 3.10)
project(gdisdl)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "install" CACHE PATH "..." FORCE)
endif()

# libs
###############################################################################
add_subdirectory(lib/Catch2)
add_subdirectory(lib/SDL)

# gdisdl
###############################################################################
file(GLOB_RECURSE gdisdl_sources src/*.cpp)
add_library(gdisdl STATIC ${gdisdl_sources})
target_include_directories(gdisdl INTERFACE include)
set_target_properties(
  gdisdl
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON  
)
target_link_libraries(gdisdl PUBLIC SDL2-static)

# tests
###############################################################################
file(GLOB_RECURSE test_sources test/*.cpp)

add_executable(gdisdl-test ${test_sources})

set_target_properties(
  gdisdl-test
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON  
)

target_link_libraries(
  gdisdl-test
  Catch2 
  gdisdl)

# https://github.com/Nitro/ext_agg/blob/master/src/platform/win32/agg_win32_bmp.cpp