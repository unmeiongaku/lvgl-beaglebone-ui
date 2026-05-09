#include "lvgl/lvgl.h"

#include <unistd.h>

void platform_init(void)
{
    lv_display_t * disp;

    disp = lv_linux_fbdev_create();

    lv_linux_fbdev_set_file(disp, "/dev/fb0");

    lv_indev_t * indev;
    indev = lv_evdev_create(LV_INDEV_TYPE_POINTER, "/dev/input/event0");

    (void) indev;
}
