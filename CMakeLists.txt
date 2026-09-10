cmake_minimum_required(VERSION 3.28)

project(crc-c)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

if(DEFINED ENV{ZEPHYR_BASE})
    target_sources(app PRIVATE ${SRC})
    target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
else()
    add_library(crc-c STATIC)
    target_sources(crc-c PRIVATE ${SRC})
    target_include_directories(crc-c PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

    target_compile_options(crc-c PRIVATE -Werror -Wno-attributes)

    option(BUILD_TESTS "Build tests" OFF)
    if(BUILD_TESTS)
        add_subdirectory(TEST)
    endif()
endif()
