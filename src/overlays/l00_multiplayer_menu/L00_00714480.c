#include "common.h"

extern s32 func_L00_007647B0(s32 identifier);

// Steps the value at +0x60 up (inputs 4 and 7) or down (input 3) by +0x70 within [+0x68, +0x6C], wrapping, and notifies; returns 1 when handled.
s32 func_L00_00714480(void *arg0, s32 arg1) {
    u8 *p = (u8 *)arg0;
    s32 result = 0;
    s32 cur = *(s32 *)(p + 0x60);

    *(s32 *)(p + 0x64) = cur;
    if (arg1 == 4 || arg1 == 7) {
        if (cur == 0 && *(s32 *)(p + 0x68) > 0) {
            *(s32 *)(p + 0x60) = *(s32 *)(p + 0x68);
        } else {
            *(s32 *)(p + 0x60) = *(s32 *)(p + 0x60) + *(s32 *)(p + 0x70);
            if (*(s32 *)(p + 0x6C) < *(s32 *)(p + 0x60)) {
                if (*(u8 *)(p + 0x74) == 1 && *(s32 *)(p + 0x68) > 0) {
                    *(s32 *)(p + 0x60) = 0;
                } else {
                    *(s32 *)(p + 0x60) = *(s32 *)(p + 0x68);
                }
            }
        }
        func_L00_007647B0(6);
        result = 1;
    } else if (arg1 == 3) {
        if (cur == 0 && *(s32 *)(p + 0x68) > 0) {
            *(s32 *)(p + 0x60) = *(s32 *)(p + 0x6C);
        } else {
            *(s32 *)(p + 0x60) = *(s32 *)(p + 0x60) - *(s32 *)(p + 0x70);
            if (*(s32 *)(p + 0x60) < *(s32 *)(p + 0x68)) {
                if (*(u8 *)(p + 0x74) == 1 && *(s32 *)(p + 0x68) > 0) {
                    *(s32 *)(p + 0x60) = 0;
                } else {
                    *(s32 *)(p + 0x60) = *(s32 *)(p + 0x6C);
                }
            }
        }
        func_L00_007647B0(6);
        result = 1;
    }
    return result;
}
