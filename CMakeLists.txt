cmake_minimum_required(VERSION 3.5.0)
project(simple-animation-toolkit VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(vendor/raylib)

include_directories(include/math)
include_directories(include/actions)

set(toolkit_header_files
    include/simple_animation_toolkit/animation_engine.h
    include/simple_animation_toolkit/objects/animation_object.h
    include/simple_animation_toolkit/objects/animated_text_object.h
    include/simple_animation_toolkit/objects/animated_circle_object.h
    include/simple_animation_toolkit/objects/animated_square_object.h
    include/simple_animation_toolkit/animations/animation_movement.h
    include/simple_animation_toolkit/animations/animation_size.h
)

set(toolkit_header_files_to_output
    include/simple_animation_toolkit.h
)

set(toolkit_source_files
    src/animation_engine.cpp
    src/objects/animation_object.cpp
    src/objects/animated_text_object.cpp
    src/objects/animated_circle_object.cpp
    src/objects/animated_square_object.cpp
    src/animations/animation_movement.cpp
    src/animations/animation_size.cpp
)

add_library(simple-animation-toolkit ${toolkit_source_files} ${toolkit_header_files})

target_include_directories(simple-animation-toolkit PUBLIC include)

target_link_libraries(simple-animation-toolkit PUBLIC raylib)
target_include_directories(simple-animation-toolkit PUBLIC raylib/include)

file(COPY ${toolkit_header_files_to_output} DESTINATION "include")

add_executable(example1 examples/example1.cpp)
target_link_libraries(example1 PRIVATE simple-animation-toolkit)