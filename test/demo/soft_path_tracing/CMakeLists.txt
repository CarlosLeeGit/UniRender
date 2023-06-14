cmake_minimum_required(VERSION 3.10.0)

set(TARGET_NAME softPathTracingDemo)

add_definitions(-DSOFT)
add_executable(${TARGET_NAME} ${TARGET_SRC})
add_dependencies(${TARGET_NAME} unirender)
target_link_libraries(${TARGET_NAME} unirender)
