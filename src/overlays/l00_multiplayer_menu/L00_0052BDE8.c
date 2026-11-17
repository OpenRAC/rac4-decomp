/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_0052B040(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8);
extern s64 D_004AF9C8[];

typedef struct Type1 {
    u8 b[32];
} Type1;

/* Builds a 0x4D-byte block (13 header bytes and two 32-byte runs of the object) and calls the setup step with it; returns 0 or 0x30. */
s32 func_L00_0052BDE8(u8 *arg0, s32 a1, s32 arg2, s32 arg3) {
    s64 blk[0xA];
    u8 out[0x30];
    u8 *pv;
    u8 *rv;
    s32 s0;

    __builtin_memcpy(blk, D_004AF9C8, 13);
    pv = *(u8 **)(arg0 + 0x54);
    *(Type1 *)((u8 *)blk + 0xD) = *(Type1 *)(pv + 0x64);
    *(Type1 *)((u8 *)blk + 0x2D) = *(Type1 *)(pv + 0x44);
    rv = *(u8 **)(arg0 + 0xDC);
    s0 = 0x30;
    if (func_L00_0052B040(*(s32 *)(rv + 0x104), *(s32 *)(rv + 0x108), (s32)blk, 0x4D,
                           arg2, arg3, *(u8 **)(arg0 + 0xB0) + 0x14, out, s0) == 0) {
        s0 = 0;
    }
    return s0;
}
