#ifndef RAC4_PAL_DISPLAY_OVERLAY_H
#define RAC4_PAL_DISPLAY_OVERLAY_H

#include "pal/display_00206AC0.h"

extern void func_0044E528(void *, s32, s32, s32);
extern void func_0044A540(s32, s32, s32, s32, u64);

static inline void draw_display_overlay(void *scratch)
{
    func_0044E528(scratch, 66, 72, 0);
    func_0044A540(0, D_00206AC0.height, 0, D_00206AC0.width, (s32)0x80808080);
}

#endif
