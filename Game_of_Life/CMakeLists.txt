cmake_minimum_required(VERSION 3.10.2)

project(GameOfLife)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(Game)
add_subdirectory(Console)

target_link_libraries(${PROJECT_NAME} Game)
target_link_libraries(${PROJECT_NAME} Console)

# target_include_directories(${PROJECT_NAME} PUBLIC Adder)

# target_link_directories(${PROJECT_NAME} PRIVATE Adder)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)


