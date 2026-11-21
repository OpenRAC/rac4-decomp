#include "common.h"

extern s32 func_00547D58(s32 arg0, s32 arg1);
extern u32 func_00549BB8(void *p, s32 idx);
extern s32 func_00549FD0(s32 arg0, s32 arg1);
extern s32 D_0021EDD4;

/* Stores arg2 in the first zero byte of record arg1, or returns 0 when there is none. */
s32 func_0054A290(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 count;
    s32 n;
    s32 offset;
    u8 *base;
    u8 *p;
    u8 *q;

    if ((u32)(arg2 - 1) < 8U) {
        if (func_00549BB8((void *)arg0, arg2) == 0) {
            return 0;
        }
        n = func_00547D58(arg0, arg1);
        count = n + 1;
        if ((D_0021EDD4 ^ 1) == 0) {
            count = 10;
        }
        i = 0;
        if (count > 0) {
            base = (u8 *)(arg0 + 0xA44);
            offset = arg1 * 0x44;
            p = (u8 *)(offset + (s32)base);
            q = (u8 *)(offset + arg0);
            do {
                i++;
                if (*p == 0) {
                    q[0xA44] = arg2;
                    func_00549FD0(arg0, arg2);
                    return 1;
                }
                p += 4;
                q += 4;
            } while (i < count && i < 10);
        }
    }
    return 0;
}
