cmake_minimum_required(VERSION 3.10)

project(SDLPlayground)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

add_executable(SDLPlayground
    src/main.cpp
    src/Application.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/assets
     DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(SDLPlayground PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(SDLPlayground PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
)
