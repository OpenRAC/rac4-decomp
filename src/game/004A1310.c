#include "common.h"

extern s32 func_00497628(s32 *, s32, s32);
extern void func_004A1240(void *, s32);

/* Calls func_00497628 with three fields of arg0; if it returns nonzero, calls func_004A1240 with field 0x54. */
void func_004A1310(void *arg0) {
    s32 sp0;

    sp0 = *(s32 *)((u8 *)arg0 + 0x54);
    if (func_00497628(&sp0, *(s32 *)((u8 *)arg0 + 0x50), *(s32 *)((u8 *)arg0 + 0x44)) != 0) {
        func_004A1240(arg0, sp0);
    }
}
