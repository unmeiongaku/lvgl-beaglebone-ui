#include "lvgl/lvgl.h"
#include <unistd.h>

void ui_create(void);

int main(void)
{
    lv_init();

    extern void platform_init(void);
    platform_init();

    ui_create();

    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}
