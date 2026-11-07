/* Not matching yet: BYTES 8/380 (tools/try_func.py func_004F6960 --diff). Not part of the build. */
/* cflags: -fno-opt-stack -mno-split-addresses */
#include "pal/command_buffer.h"

extern char D_00003E90[];

void func_004F64B8(PalCommandCursor *p, int *count, int a, int b, int c, int d, int e);

void func_004F6960(PalCommandCursor *p, s32 *n, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                   s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13) {
    u64 **q = &p->pairs;
    *(*q)++ = (u64)(*n | 0x64048000) << 32;
    *(*q)++ = 0x1183400000008003ULL;
    *(*q)++ = ((s64)(a3 - 1) << 16) | ((s64)(a4 - 1) << 48);
    *(*q)++ = (a2 >> 13) | ((s64)a5 << 16);
    *(*q)++ = a10 | ((s64)a11 << 8) | ((s64)a12 << 16) | ((s64)a13 << 24);
    *(*q)++ = (u32)(*n | 0x72048000) | 0x14D410E00000000ULL;
    *(*q)++ = (u32)(((s32)D_00003E90 >> 3) | 0x14000000);
    *(*q)++ = 0;
    *n += 4;
    func_004F64B8(p, n, a6, a7, a8, a9, 0);
}
