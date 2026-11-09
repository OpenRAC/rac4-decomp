/* Not matching yet: BYTES 12/536 (tools/try_func.py func_004F6AF0 --diff). Not part of the build. */
/* cflags: -fno-opt-stack */
#include "pal/command_buffer.h"

void func_004F6648(PalCommandCursor *p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, s32 s0, s32 s1);

void func_004F6AF0(PalCommandCursor *p, s32 a1, s32 a2, s32 a3, s32 b, s32 c, s32 d, s32 e,
                   s32 w, s32 h, s32 f, s32 g0, s32 g1, s32 g2, s32 g3, s32 g4, s32 g5, s32 g6, s32 g7) {
    u64 **q = &p->pairs;
    *(*q)++ = 0x1000000000000004ULL;
    *(*q)++ = 0xE;
    *(*q)++ = ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48);
    *(*q)++ = 0x41;
    *(*q)++ = (a1 >> 8) | ((u64)b << 14) | ((u64)c << 26) | ((u64)d << 30) | 0x400000000ULL;
    *(*q)++ = 7;
    *(*q)++ = (e >> 13) | ((u64)f << 16);
    *(*q)++ = 0x4D;
    *(*q)++ = 0x30802;
    *(*q)++ = 0x48;
    *(*q)++ = 0x2400000000000001ULL;
    *(*q)++ = 1;
    *(*q)++ = 0x80808080;
    *(*q)++ = 0x316;
    func_004F6648(p, g0, g1, g4, g5, g2, g3, g6, g7, 0);
    *(*q)++ = 0x1000000000008001ULL;
    *(*q)++ = 0xE;
    *(*q)++ = 0;
    *(*q)++ = 0x3F;
}
