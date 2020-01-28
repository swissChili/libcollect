cmake_minimum_required(VERSION 3.13)
project(collect C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_library(collect SHARED
        map.c include/collect/map.h hash.c
        include/collect/hash.h
        include/collect/vector.h vector.c
        include/collect/list.h list.c)

add_executable(test-collect test.c)
target_link_libraries(test-collect collect)

install(TARGETS collect
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

install(DIRECTORY include/ DESTINATION include)

set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")

set(PRIVATE_LIBS "-lcollect")

configure_file("libcollect.pc.in" "libcollect.pc" @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/libcollect.pc DESTINATION lib/pkgconfig)
