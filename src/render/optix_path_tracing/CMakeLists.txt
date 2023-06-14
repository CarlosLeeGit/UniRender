cmake_minimum_required(VERSION 3.10.0)

set(TARGET_NAME optixpathtracing)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(TARGET_SRC OptixPathTracing.cpp)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC})
