cmake_minimum_required(VERSION 3.10)
project(crc_test C)

set(CMAKE_C_STANDARD 17)

# Добавляем тест как обычное приложение
add_executable(crc_test test.c)

# Линкуем с основной библиотекой
target_link_libraries(crc_test crc-c)

target_compile_options(crc_test PRIVATE -Werror -Wno-attributes)
