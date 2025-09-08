cmake_minimum_required(VERSION 3.16)
project(2048)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
include_directories(include)

set(SOURCES
	src/main.cpp
)

add_executable(2048 ${SOURCES})

# find_package(Curses REQUIRED)
# include_directories(${CURSES_INCLUDE_DIR})
# target_link_libraries(2048 ${CURSES_LIBRARIES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
