/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
extern void func_L00_00538128(void *p);
extern int func_L00_005382C8(int a1, int a2);

/* Copies bitset arg1 into arg0 shifted left by arg2 bits, growing arg0 if needed; returns 1 when copied. */
s32 func_L00_00538938(void *arg0, void *arg1, s32 arg2) {
    s32 need;
    s32 q;
    s32 rem;
    s32 inv;
    s32 i;
    u64 *dst;
    u64 *src;
    u64 w;

    need = *(s32 *)((u8 *)arg1 + 4) + arg2 / 64 + 1;
    if ((*(s32 *)((u8 *)arg0 + 8) < need) ? func_L00_005382C8((int)arg0, need) == 0 : arg0 == 0) {
        return 0;
    }
    dst = *(u64 **)arg0;
    *(s32 *)((u8 *)arg0 + 0xC) = *(s32 *)((u8 *)arg1 + 0xC);
    q = arg2 / 64;
    src = *(u64 **)arg1;
    rem = arg2 - (q << 6);
    inv = 64 - rem;
    dst[*(s32 *)((u8 *)arg1 + 4) + q] = 0;
    if (rem == 0) {
        for (i = *(s32 *)((u8 *)arg1 + 4) - 1; i >= 0; i--) {
            dst[q + i] = src[i];
        }
    } else {
        for (i = *(s32 *)((u8 *)arg1 + 4) - 1; i >= 0; i--) {
            w = src[i];
            dst[q + i + 1] |= w >> inv;
            dst[q + i] = w << rem;
        }
    }
    func_0011A518(dst, 0, q * 8);
    *(s32 *)((u8 *)arg0 + 4) = *(s32 *)((u8 *)arg1 + 4) + q + 1;
    func_L00_00538128(arg0);
    return 1;
}
