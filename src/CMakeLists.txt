CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(PONG_SRC main.cpp pong.cpp)

# Enable gcc specific stuff
if(CMAKE_COMPILER_IS_GNUCC)
    # We want c++0x for lambdas
    set_source_files_properties(${PONG_SRC} PROPERTIES COMPILE_FLAGS "-Wall -pedantic -std=c++0x")
endif()

# Pong executable
add_executable(pong ${PONG_SRC})

# Link to SFML
find_package(SFML REQUIRED)
target_link_libraries(pong sfml-system sfml-window GL Xrandr)
