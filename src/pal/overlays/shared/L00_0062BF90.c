/* cflags:  */
#include "common.h"

extern s64 func_00498280(s32 *, s32, s64);
extern s64 func_004A1F78(void *, s64);

/* Calls func_00498280 with three fields of arg0; if it returns nonzero, calls func_004A1F78 with field 0x54. */
void func_L00_0062BF90(void *arg0) {
    s32 sp0;

    sp0 = *(s32 *)((u8 *)arg0 + 0x54);
    if (func_00498280(&sp0, *(s32 *)((u8 *)arg0 + 0x50), *(s32 *)((u8 *)arg0 + 0x44)) != 0) {
        func_004A1F78(arg0, sp0);
    }
}
