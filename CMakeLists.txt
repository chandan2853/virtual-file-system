cmake_minimum_required(VERSION 3.10.2)

project(vfs)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(vfs main.cpp ${SRC_FILES})
target_include_directories(vfs PUBLIC $(CMAKE_CURRENT_SOURCE_DIR)/inc $(CMAKE_CURRENT_SOURCE_DIR)/src)