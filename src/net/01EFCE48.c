/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011AB04(char *);
extern s32 func_01EFCD54(s32);
extern void func_01F0C090(void *, s32);
extern char D_0019D750[];
s32 func_01EFCE48(char *arg0, s32 arg1) {
    s32 len = func_0011AB04(arg0);
    if (arg1 >= len) {
        return len;
    }
    switch (func_01EFCD54(arg0[arg1])) {
    case 1:
        arg1 += 2;
        break;
    case 2:
        arg1 += 3;
        break;
    case 3:
        arg1 += 4;
        break;
    case 4:
    case 5:
        func_01F0C090(D_0019D750, 0x75);
    case 0:
        arg1 += 1;
        break;
    }
    return arg1;
}
