cmake_minimum_required(VERSION 3.5.0)
project(cpp-animation-sandbox VERSION 0.1.0 LANGUAGES C CXX)

add_executable(cpp-animation-sandbox cpp-animation-sandbox.cpp)

target_link_libraries(cpp-animation-sandbox PRIVATE cpp-animation-engine)

target_include_directories(cpp-animation-sandbox PRIVATE cpp-animation-engine/include)   