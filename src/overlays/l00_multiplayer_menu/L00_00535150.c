/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_L00_00535E08(u8 **pp, s32 constructed, s32 length, s32 tag, s32 xclass);
extern s32 func_L00_00535FB0(s32, s32, s32);

/* Writes a tag and length header and then the content bytes into the buffer at *arg1; returns the encoded size. */
s32 func_L00_00535150(s32 *arg0, u8 **arg1) {
    s32 pad = 0;
    s32 ret;
    s32 r;
    s32 i;
    s32 type;
    u8 *p;
    u8 *n;
    u8 *start;
    u8 pb = 0;

    if (arg0 == NULL || (u8 *)arg0[2] == NULL) {
        return 0;
    }
    type = arg0[1];
    if (arg0[0] == 0) {
        ret = 1;
    } else {
        ret = arg0[0];
        i = *(u8 *)arg0[2];
        if (type == 2 && i > 127) {
            pad = 1;
            pb = 0;
        } else if (type == 0x102 && i > 128) {
            pad = 1;
            pb = 0xFF;
        }
        ret += pad;
    }
    r = func_L00_00535FB0(0, ret, 2);
    if (arg1 == NULL) {
        return r;
    }
    p = *arg1;
    func_L00_00535E08(&p, 0, ret, 2, 0);
    if (pad) {
        *(p++) = pb;
    }
    if (arg0[0] == 0) {
        *(p++) = 0;
    } else if (type == 2) {
        func_0011A370(p, (u8 *)arg0[2], arg0[0]);
        p += arg0[0];
    } else {
        n = (u8 *)arg0[2];
        start = p;
        for (i = arg0[0]; i > 0; i--) {
            *(p++) = ~*(n++) + 1;
        }
        if (!pad) {
            *start |= 0x80;
        }
    }
    *arg1 = p;
    return r;
}
