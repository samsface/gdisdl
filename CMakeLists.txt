cmake_minimum_required(VERSION 3.10)
project(gdi-sdl-compat)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "install" CACHE PATH "..." FORCE)
endif()

add_subdirectory(lib/Catch2)
add_subdirectory(lib/fmt)

# libgai
###############################################################################

add_library(libgai INTERFACE)
target_include_directories(libgai INTERFACE include/)
target_link_libraries(libgai INTERFACE fmt)

# bindings
###############################################################################
add_subdirectory(bindings/godot)

# test
###############################################################################
file(GLOB_RECURSE test_sources test/*.cpp)

add_executable(libgai-test ${test_sources})

set_target_properties(
  libgai-test
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON  
)

target_link_libraries(
  libgai-test 
  Catch2 
  libgai)