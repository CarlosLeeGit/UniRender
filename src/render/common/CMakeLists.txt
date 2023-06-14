cmake_minimum_required(VERSION 3.10.0)

set(TARGET_NAME rendercommon)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(TARGET_SRC MeshManager.cpp)

add_library(${TARGET_NAME} STATIC ${TARGET_SRC})
