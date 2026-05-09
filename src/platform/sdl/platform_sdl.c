#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/sdl/lv_sdl_window.h"

void platform_init(void)
{
    lv_sdl_window_create(800, 480);
}
