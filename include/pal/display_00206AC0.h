#ifndef PAL_DISPLAY_00206AC0_H
#define PAL_DISPLAY_00206AC0_H
#include "common.h"

typedef struct Display {
    u8 fields[0x150];
    s16 width;
    s16 height;
} Display;
extern Display D_00206AC0;

#endif
