cmake_minimum_required(VERSION 3.10)
project(SanskritTamilNLP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(SanskritTamilNLP ${SOURCES})
