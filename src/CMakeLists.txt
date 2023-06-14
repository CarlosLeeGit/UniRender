cmake_minimum_required(VERSION 3.10.0)

set(TARGET_NAME unirender)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(loader)
add_subdirectory(render)

set(TARGET_SRC UniLoader.cpp UniRender.cpp render/RenderFactory.cpp)

add_library(${TARGET_NAME} SHARED ${TARGET_SRC})

target_link_libraries(${TARGET_NAME} softpathtracing)
target_link_libraries(${TARGET_NAME} optixpathtracing)
target_link_libraries(${TARGET_NAME} rendercommon)