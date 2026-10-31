#include "common.h"

extern s32 func_00540650(void *, s32, s32);
extern void func_00511450(void *, s32);
extern u8 D_00172160[];

// Stores the value at +0x50 when accepted; if the +0x34 word differs from the global word at +0x10, copies it to +0x34 and +4 and calls func_00511450.
void func_00540700(void *arg0, s32 arg1, s32 arg2) {
    s32 value = arg1 & 0xFF;

    if (func_00540650(arg0, value, arg2 & 0xFF) != 0) {
        u8 *g = D_00172160;

        *(u8 *)((u8 *)arg0 + 0x50) = value;
        if (*(s32 *)((u8 *)arg0 + 0x34) != *(s32 *)(g + 0x10)) {
            *(s32 *)((u8 *)arg0 + 0x34) = *(s32 *)(g + 0x10);
            *(s32 *)((u8 *)arg0 + 0x4) = *(s32 *)(g + 0x10);
            func_00511450(arg0, 0);
        }
    }
}
