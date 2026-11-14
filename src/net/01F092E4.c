/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A5D0(u8 *, u8 *);
extern s32 func_0011AB04(u8 *);
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern void *func_01EEDCD0(void *, const void *, s32);
extern s32 func_01EEDF50(void *, void *);
extern void func_01F0C090(const char *, s32);
extern u8 D_0019E470[];
extern u8 D_0019E5A8[];
extern s8 D_0019E5B0[];

/* Copies the record at arg2 into arg1 (0x80 bytes when it is empty) and formats its tail. */
void func_01F092E4(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    u8 buf[0x80];
    s32 n;
    s32 span;
    s32 len;

    if ((u32)func_0011AB04(arg2) >= 0x80U) {
        func_01F0C090(D_0019E470, 0x262);
    }
    n = func_01EEDF50(arg2, D_0019E5A8);
    span = n + 6;
    if (n <= 0) {
        func_01EEDCD0(arg1, arg2, 0x80);
        return;
    }
    func_0011A370(arg1, arg2, n);
    (arg1 + n)[-1] = 0;
    func_0011D920(buf, D_0019E5B0, arg0 + 0x8BD4, arg4);
    func_0011A5D0(arg1, buf);
    len = func_0011AB04(arg2);
    func_01EEDCD0(buf, arg2 + span, len);
    func_0011A5D0(arg1, buf);
}
