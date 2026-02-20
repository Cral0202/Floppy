# Floppy

A simple Flappy Bird-like game written in C++ using SFML.

## Usage

The executable must be run from the project root because assets paths are resolved relative to the project root.

## Build Requirements

Before building, make sure you have:

- C++17 compatible compiler
- CMake 3.20+
- SFML 2.5+ (2.x series)

## Build Instructions

In the project root, create a build folder:

`mkdir build`

`cd build`

Generate build files:

`cmake ..`

Build:

`cmake --build .`

The executable will be placed in the project root.
