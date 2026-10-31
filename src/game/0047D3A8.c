#include "common.h"

typedef struct {
    u8 pad0[0x11];
    u8 f11[0x13];
    u8 f24;
    u8 f25;
} Type1;

extern void func_00462080(s32 arg0);
extern Type1 D_00171B80;

// Marks slot arg0 of table D_00171B80, and when arg1 is set and arg0 differs from the byte at 0x24, stores it at 0x24 and 0x25 and calls func_00462080.
void func_0047D3A8(s32 arg0, s32 arg1) {
    if ((u32)arg0 < 0xB) {
        D_00171B80.f11[arg0] = 1;
        if (arg1 != 0 && arg0 != D_00171B80.f24) {
            D_00171B80.f24 = arg0;
            D_00171B80.f25 = arg0;
            func_00462080(arg0);
        }
    }
}
