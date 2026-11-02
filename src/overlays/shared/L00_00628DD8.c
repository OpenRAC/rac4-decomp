#include "common.h"

extern s32 func_0061EE48(s32 *, s32, s32);
extern void func_00628CC0(void *, s32);

/* Calls func_0061EE48 with three fields of arg0; if it returns nonzero, calls func_00628CC0 with field 0x54. */
void func_L00_00628DD8(void *arg0) {
    s32 sp0;

    sp0 = *(s32 *)((u8 *)arg0 + 0x54);
    if (func_0061EE48(&sp0, *(s32 *)((u8 *)arg0 + 0x50), *(s32 *)((u8 *)arg0 + 0x44)) != 0) {
        func_00628CC0(arg0, sp0);
    }
}
