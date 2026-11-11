/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E00C8 (src/levels/39_multiplayer_menu/L39_004DF158.c, GPL-3.0), the same code in both games. */

extern void func_L00_0051BB50();
typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buf[64];
    s32 len;
} Type1;
extern void func_L00_0051BB50(Type1 *, u8 *);
extern void func_0011A518(void *, s32, s32);
void func_L00_0051BEC8(u8 *out, Type1 *c) {
    u8 *buf = c->buf;
    s32 n = c->len;
    u32 w;
    buf[n++] = 0x80;
    if (c->len >= 0x38) {
        while (n < 64)
            buf[n++] = 0;
        func_L00_0051BB50(c, buf);
        n = 0;
    }
    func_0011A518(buf + n, 0, 0x38 - n);
    w = c->count[0];
    buf[0x38] = w;
    buf[0x39] = w >> 8;
    buf[0x3A] = w >> 16;
    buf[0x3B] = w >> 24;
    w = c->count[1];
    buf[0x3C] = w;
    buf[0x3D] = w >> 8;
    buf[0x3E] = w >> 16;
    buf[0x3F] = w >> 24;
    func_L00_0051BB50(c, buf);
    buf = out;
    w = c->state[0];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[1];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[2];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    w = c->state[3];
    *buf++ = w;
    *buf++ = w >> 8;
    *buf++ = w >> 16;
    *buf++ = w >> 24;
    c->len = 0;
}
