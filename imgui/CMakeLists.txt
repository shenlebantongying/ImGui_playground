cmake_minimum_required(VERSION 3.16)
project(imgui)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(Freetype REQUIRED)

file(GLOB imgui_SRC ${CMAKE_SOURCE_DIR}/imgui/*.cpp)

add_library(imgui SHARED ${imgui_SRC} misc/freetype/imgui_freetype.cpp)

#target_compile_options(imgui PRIVATE -Wno-stringop-overflow)

target_compile_definitions(imgui PUBLIC IMGUI_USER_CONFIG="imconfig_this_project.h")
target_include_directories(imgui PRIVATE ${FREETYPE_INCLUDE_DIRS})
target_include_directories(imgui PUBLIC .)
target_link_libraries(imgui PRIVATE OpenGL::GL SDL2::SDL2 Freetype::Freetype)

