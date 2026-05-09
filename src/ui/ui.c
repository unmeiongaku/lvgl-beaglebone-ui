#include "lvgl/lvgl.h"

void ui_create(void)
{
    lv_obj_set_style_bg_color(
        lv_screen_active(),
        lv_color_hex(0x202020),
        0);

    lv_obj_t * label =
        lv_label_create(lv_screen_active());

    lv_label_set_text(label,
                      "Hello BeagleBone + LVGL");

    lv_obj_set_style_text_color(
        label,
        lv_color_hex(0xFFFFFF),
        0);

    lv_obj_center(label);
}
