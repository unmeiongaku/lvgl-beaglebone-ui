cmake_minimum_required(VERSION 3.10)

project(lvgl_bbb_app)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)

add_subdirectory(lvgl)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    lvgl
)

add_executable(lvgl-bbb-app
    src/main.c
    src/ui/ui.c
    src/platform/sdl/platform_sdl.c
)

target_link_libraries(lvgl-bbb-app
    lvgl
    ${SDL2_LIBRARIES}
)
