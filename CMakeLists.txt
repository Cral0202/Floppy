cmake_minimum_required(VERSION 3.20)
project(Floppy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS
    system
    window
    graphics
    audio
    REQUIRED
)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Floppy ${SOURCES})

target_link_libraries(Floppy
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)
