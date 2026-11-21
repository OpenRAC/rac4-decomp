/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_0019C500[];
extern s32 D_0019C510[];
extern s32 D_0019C520[];
extern s32 D_0019C528[];
extern s32 D_0019C530[];
extern void func_0011A518(void *, s32, s32);
extern s8 *func_0011A700(void *, s32);
extern void *func_01EEDCD0(void *, const void *, s32);
extern s32 func_01EEDE74(u8 *buf, s32 size, s32 fmt, ...);
extern void func_01F0C090(char *arg0, s32 arg1);

// Copies the 0x7F-byte strings of arg0 into arg1's buffer of arg2 bytes; returns 1, or 0 when they do not fit.
s32 func_01EF00F8(s8 *arg0, s8 *arg1, s32 arg2) {
    s8 *s3;
    s8 *s0;
    s8 *s2;
    s32 i;
    u32 left;

    if (arg0[0x7EF] != 0) {
        func_01F0C090((char *)D_0019C500, 0x9D);
    }
    func_0011A518(arg1, 0, arg2);
    s3 = arg0;
    i = 0;
    s0 = arg1;
    do {
        if (*s3 != 0) {
            s2 = func_0011A700(s3, 0) + 1;
            if (s2 == 0 || *s2 == 0) {
                func_01F0C090((char *)D_0019C500, 0xA9);
            }
            if ((u32)(func_0011A700(s2, 0) - s3 + 2) > (u32)(arg2 - (s0 - arg1))) {
                func_01F0C090((char *)D_0019C500, 0xB0);
                return 0;
            }
            left = arg2 - (s0 - arg1);
            if (s0 == arg1) {
                func_01EEDCD0(s0, D_0019C510, arg2);
                s0 += 8;
            } else {
                func_01EEDCD0(s0, D_0019C520, left);
                s0 += 2;
            }
            s0 += func_01EEDE74((u8 *)s0, arg2 - (s0 - arg1), (s32)D_0019C528, s3, s2);
        }
        i++;
        s3 += 0x7F;
    } while ((u32)i < 0x10);
    if (s0 != arg1) {
        func_01EEDCD0(s0, D_0019C530, arg2 - (s0 - arg1));
    }
    return 1;
}
