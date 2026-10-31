#include "common.h"

/* Stores the free span of the object (words 0x0, 0x4, 0x8) into arg1, or 0 when the word at 0xC is clear; 2 when either pointer is null. */
s32 func_01EA71F0(void *arg0, s32 *arg1) {
    s32 result = 2;
    u32 t0;
    u32 t4;
    u32 diff;
    if (arg0 != 0) {
        if (arg1 != 0) {
            if (*(u32 *)((char *)arg0 + 0xC) != 0) {
                t0 = *(u32 *)((char *)arg0 + 0x0);
                t4 = *(u32 *)((char *)arg0 + 0x4);
                diff = t4 - t0;
                if (t0 < t4) {
                    *arg1 = diff;
                } else {
                    *arg1 = *(u32 *)((char *)arg0 + 0x8) - t0;
                }
            } else {
                *arg1 = 0;
            }
            result = 0;
        }
    }
    return result;
}
