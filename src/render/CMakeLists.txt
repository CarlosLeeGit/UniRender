cmake_minimum_required(VERSION 3.10.0)

include_directories(${CMAKE_CURRENT_SOUCE_DIR})

add_subdirectory(soft_path_tracing)
add_subdirectory(optix_path_tracing)
add_subdirectory(common)