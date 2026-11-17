#include "common.h"

extern void func_L00_006EC318(void *, s32 *, s32);
extern s32 func_L01_006B4FC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

// Creates the object of type 8 and, when that returns something, writes arg1's low byte then the word arg2 to it.
void func_L01_004CA890(s32 arg0, s32 arg1, s32 arg2) {
    s32 tag = arg1 & 0xFF;
    s32 p = func_L01_006B4FC0(arg0, 8, 0, 250);
    if (p != 0) {
        u8 b[16];
        s32 w;
        b[0] = tag;
        func_L00_006EC318((void *)p, (s32 *)b, 1);
        w = arg2;
        func_L00_006EC318((void *)p, &w, 4);
    }
}
