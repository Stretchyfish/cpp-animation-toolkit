cmake_minimum_required(VERSION 3.5.0)
project(cpp-animation-engine VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(vendor/raylib)

include_directories(include/math)
include_directories(include/actions)

set(engine_header_files
    include/animation_engine/animation_engine.h
    include/animation_engine/objects/animation_object.h
    include/animation_engine/objects/animated_text_object.h
    include/animation_engine/animations/animation_movement.h
)

set(engine_source_files
    src/animation_engine.cpp
    src/animation_object.cpp
    src/animated_text_object.cpp
    src/animations/animation_movement_position.cpp
)


add_library(cpp-animation-engine ${engine_source_files} ${engine_header_files})

target_include_directories(cpp-animation-engine PUBLIC include)

target_link_libraries(cpp-animation-engine PUBLIC raylib)
target_include_directories(cpp-animation-engine PUBLIC raylib/include)

file(COPY ${engine_header_files} DESTINATION "include")
