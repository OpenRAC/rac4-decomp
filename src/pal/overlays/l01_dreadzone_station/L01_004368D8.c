/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/display_overlay.h"

extern s32 D_00222C10;

void func_L01_004368D8(void)
{
    draw_display_overlay(&D_00222C10);
}
