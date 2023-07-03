cmake_minimum_required(VERSION 3.25)
project(imgui_SDL2_cmake_template)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(OpenGL REQUIRED)

add_subdirectory(imgui)
add_subdirectory(glad)

option(NFD_PORTAL "FORCE PORTAL" ON)
add_subdirectory(nativefiledialog-extended)

add_library(common SHARED utils.cpp)

set(LIBRARIES imgui glad nfd OpenGL::GL SDL2::SDL2 common)

function(create_my_binary TARGET_NAME T_SOURCES)
    add_executable(${TARGET_NAME} ${T_SOURCES})
    target_link_libraries(${TARGET_NAME} PRIVATE ${LIBRARIES})
endfunction()

create_my_binary(fScreenUI fullScreenUI.cpp)
create_my_binary(glDrawRainBow glDrawRainBow.cpp)
