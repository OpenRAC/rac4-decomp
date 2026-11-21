/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011EAA0(char *file, s32 line, char *expr);
extern void func_01EAE230(u8 *arg0, u8 *arg1, u32 arg2);
extern void *func_01EAEA48(void *, const void *, s32);
extern void *func_01EB1C60(void *, const void *, s32);
extern s32 func_01EE0648(s32, s32, void *, s32);
extern s32 func_01EE0980(void *, s32, u8 *, u8, u8 *, u32);
extern char D_00199DF8[];
extern char D_00199E60[];
extern char D_00199E68[];

// Writes a two-record handshake message into the buffer at arg1 and returns its length.
s32 func_01EDF1A0(u8 *arg0, u8 *arg1) {
    u8 *p;
    u8 *start;
    u8 *hdr;
    s32 n;
    u32 body;
    s32 total;
    s32 ret;

    p = arg1;
    hdr = p;
    switch (*(u32 *)(arg0 + 8)) {
    case 3:
    case 4:
        n = 0x10;
        break;
    case 5:
        n = 0x14;
        break;
    default:
        func_0011EAA0(D_00199DF8, 0x1F1, D_00199E60);
        n = 0x10;
        break;
    }
    *p++ = 0x16;
    *p++ = 3;
    *p++ = 0;
    *p++ = 0;
    body = n + 0x28;
    *p++ = body;
    body -= n;
    start = p;
    body -= 4;
    *p++ = 0x14;
    *p++ = body >> 16;
    *p++ = body >> 8;
    *p++ = body;
    p += func_01EE0648((s32)arg0, 1, p, 0x24);
    total = p - start;
    func_01EB1C60(arg0 + 0x1B0, start, total);
    func_01EAEA48(arg0 + 0x150, start, total);
    body += 4;
    p += func_01EE0980(arg0, 1, p, *hdr, start, body);
    body += n;
    func_01EAE230(arg0 + 0x210, start, body);
    ret = p - hdr;
    if (((p - start) & 0xFF) != body) {
        func_0011EAA0(D_00199DF8, 0x226, D_00199E68);
    }
    return ret;
}
