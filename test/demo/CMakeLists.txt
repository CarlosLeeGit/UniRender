cmake_minimum_required(VERSION 3.10.0)

set(TARGET_NAME UniRenderDemo)

include_directories(${CMAKE_SOURCE_DIR}/src/include)
set(TARGET_SRC ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_subdirectory(soft_path_tracing)
add_subdirectory(optix_path_tracing)
