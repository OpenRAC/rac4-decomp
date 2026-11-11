/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F8E00 (src/levels/39_multiplayer_menu/L39_004F8A78.c, GPL-3.0), the same code in both games. */

extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00535C18(u8 **, long *, s32 *, s32 *, long);
s32 func_L00_00534C10(s32 *a, u8 **pp, long length) {
    s32 ret = -1;
    u8 *p;
    long len;
    s32 inf, tag, xclass;
    s32 i = 0;
    p = *pp;
    inf = func_L00_00535C18(&p, &len, &tag, &xclass, length);
    if (inf & 0x80) {
        i = 0x65;
        goto err;
    }
    if (tag != 1) {
        i = 0x75;
        goto err;
    }
    if (len != 1) {
        i = 0x6C;
        goto err;
    }
    ret = (s32)*(p++);
    if (a != 0) {
        *a = ret;
    }
    *pp = p;
    return ret;
err:
    func_L00_004F84C8(13, 0x7D, i, 0, 0);
    return ret;
}
