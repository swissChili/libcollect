cmake_minimum_required(VERSION 3.15)
project(libcollect C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(libcollect map.c include/collect/map.h hash.c include/collect/hash.h
        include/collect/vector.h vector.c)

add_executable(test-collect test.c)
target_link_libraries(test-collect libcollect)