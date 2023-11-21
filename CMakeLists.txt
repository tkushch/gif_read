cmake_minimum_required(VERSION 3.5)

project(gif_read VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11) 

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_compile_options(-Wall -Wextra -Werror)

find_package(GIF REQUIRED)

add_executable(gif_read main.cpp EasyGifReader/EasyGifReader.cpp)

target_link_libraries(gif_read PRIVATE GIF::GIF)
