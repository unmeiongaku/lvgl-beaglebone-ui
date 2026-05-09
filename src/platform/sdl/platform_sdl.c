#include "lvgl/lvgl.h"

void platform_init(void)
{
    lv_display_t * disp;

    disp = lv_sdl_window_create(800, 480);

    lv_indev_t * mouse = lv_sdl_mouse_create();
    lv_indev_set_display(mouse, disp);

    lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
    lv_indev_set_display(mousewheel, disp);

    lv_indev_t * keyboard = lv_sdl_keyboard_create();
    lv_indev_set_display(keyboard, disp);
}
