cmake_minimum_required(VERSION 3.15)
project(mlx_sandbox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -lmlx")
include_directories(.)

add_executable(mlx_sandbox
        image.c
        key.h
        main.c
        map.c
        sandbox.h player.c player.h)
