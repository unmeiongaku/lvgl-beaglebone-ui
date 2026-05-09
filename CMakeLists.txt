cmake_minimum_required(VERSION 3.10)

project(lvgl_bbb_app)

set(CMAKE_C_STANDARD 99)

option(USE_FBDEV "Use framebuffer backend" OFF)

add_subdirectory(lvgl)

#
# SDL build (PC simulator)
#
if(NOT USE_FBDEV)

    find_package(SDL2 REQUIRED)

    include_directories(
        ${SDL2_INCLUDE_DIRS}
        lvgl
    )

    set(PLATFORM_SRC
        src/platform/sdl/platform_sdl.c
    )

endif()

#
# FBDEV build (BeagleBone)
#
if(USE_FBDEV)

    include_directories(
        lvgl
    )

    set(PLATFORM_SRC
        src/platform/fbdev/platform_fbdev.c
    )

endif()

#
# Application
#
add_executable(lvgl-bbb-app
    src/main.c
    src/ui/ui.c
    ${PLATFORM_SRC}
)

#
# Link libraries
#
if(NOT USE_FBDEV)

    target_link_libraries(lvgl-bbb-app
        lvgl
        ${SDL2_LIBRARIES}
    )

endif()

if(USE_FBDEV)

    target_link_libraries(lvgl-bbb-app
        lvgl
    )

endif()