cmake_minimum_required(VERSION 3.15)
project(mlx_sandbox C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit -lmlx")
add_executable(mlx_sandbox
        includes/consts.h
        includes/control.h
        includes/cub3d.h
        includes/draw.h
        includes/image.h
        includes/map.h
        includes/player.h
        includes/rays.h
        includes/utils.h
        src/control/die.c
        src/control/keys.c
        src/draw/draw.c
        src/extra/utils.c
        src/image/image.c
        src/map/map.c
        src/map/utils.c
        src/player/player.c
        src/player/utils.c
        src/rays/horizontal_cast.c
        src/rays/project.c
        src/rays/rays.c
        src/rays/vertical_cast.c
        main.c)
