/* cflags: -mno-split-addresses */
#include "pal/command_buffer.h"

extern s32 D_0021DEE8;
extern char D_00003E90[];

/* Write a command sequence and append its payload. */
void func_004F9F28(PalCommandCursor *p, s32 *n) {
    u64 **q = &p->pairs;
    *(*q)++ = (u64)(*n | 0x64098000) << 32;
    *(*q)++ = 0x1183400000008009ULL;
    *(*q)++ = 0xA0000000A0ULL;
    *(*q)++ = 0x100000000ULL;
    *(*q)++ = 0x60;
    *(*q)++ = 5;
    *(*q)++ = (D_0021DEE8 >> 13) | 0x40000;
    *(*q)++ = 0xFF000000FF0000ULL;
    *(*q)++ = 0x3040C;
    *(*q)++ = 0;
    *(*q)++ = (u32)(*n | 0x720A8000) | 0x154F190E00000000ULL;
    *(*q)++ = 0x3F0148414D09ULL;
    *(*q)++ = (u32)(((s32)D_00003E90 >> 3) | 0x14000000);
    *(*q)++ = 0;
    *n += 10;
    func_004F64B8(p, n, 0xA0, 0xA0, 0x10A0, 0x10A0, 0);
}
