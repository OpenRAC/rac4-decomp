/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern char D_0019D750[];
s32 func_01EFCD54(s8 arg0) {
    s32 r = 0;
    s32 hi = arg0 & 0xF0;
    if (hi >= 0x80) {
        r = 4;
        if ((arg0 & 0xC0) != 0x80) {
            switch (hi) {
            case 0xC0:
                r = 1;
                break;
            case 0xF0:
                r = 3;
                break;
            case 0xD0:
            case 0xE0:
                r = 2;
                break;
            default:
                func_01F0C090(D_0019D750, 0x38);
                r = 5;
                break;
            }
        }
    }
    return r;
}
