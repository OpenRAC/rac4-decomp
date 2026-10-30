#include "common.h"

// Check a condition and clear fields if a byte matches a halfword
void func_004E24A0(s32 arg0, s64 arg1) {
    char *p;

    p = (char *) ((arg1 << 0x20) >> 0x20);
    if (p != NULL && (unsigned char)p[0x13] == *(unsigned short *)(p + 0x5A)) {
        *(s32 *)p = arg0;
        if (arg0 == 0) {
            *(s32 *)(p + 0x1C) = 0;
            *(s32 *)(p + 0x40) = 0;
            p[0x10] = 0;
        }
        p[0x13] = 0;
    }
}
