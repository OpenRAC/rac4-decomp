#include "common.h"

extern u8 *func_00490968(s32);
extern u8 func_001633D0(void);
extern u8 *D_270928[];

typedef int Q128 __attribute__((mode(TI)));

/* Allocates a record of kind 4 and fills it from the two source vectors; returns it, or 0. */
u8 *func_00491B88(Q128 *arg0, Q128 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 *p;
    u8 *q;
    u8 c;

    p = func_00490968(4);
    if (p != 0) {
        *(Q128 *)(p + 0x10) = *arg0;
        p[9] = 0xA4;
        *(s32 *)(p + 4) = arg2;
        if (arg7 != 0) {
            p[3] = 0x48;
        } else {
            p[3] = 0x44;
        }
        p[1] = 0;
        c = *D_270928[0];
        p[2] = c;
        p[8] = func_001633D0();
        q = p + 0x20;
        *(s32 *)(p + 0xC) = 0;
        *(Q128 *)(p + 0x10) = *arg0;
        *(Q128 *)(p + 0x20) = *arg1;
        *(s16 *)(p + 0xA) = arg4;
        *(s32 *)(q + 0x1C) = arg4;
        *(s32 *)(q + 0x10) = arg2;
        *(s32 *)(q + 0x14) = arg3;
        *(s16 *)(q + 0x18) = arg6;
        *(s16 *)(q + 0x1A) = arg5;
    }
    return p;
}
