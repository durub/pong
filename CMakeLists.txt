CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Project definition
project(pong)

# Build source
add_subdirectory(src)

# Add custom modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
