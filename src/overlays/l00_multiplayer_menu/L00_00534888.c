/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004F8A78 (src/levels/39_multiplayer_menu/L39_004F8A78.c, GPL-3.0), the same code in both games. */

typedef struct Type1 { s32 length; s32 type; u8 *data; long flags; } Type1;
extern s32 func_L00_00535FB0(s32, s32, s32);
extern void func_L00_00535E08(u8 **, s32, s32, s32, s32);
extern void *func_0011A370(void *, const void *, unsigned int);
s32 func_L00_00534888(Type1 *a, u8 **pp) {
    s32 ret, r, bits, len;
    u8 *p, *d;
    if (a == 0) {
        return 0;
    }
    len = a->length;
    if (len > 0) {
        if (a->flags & 8) {
            bits = (s32)a->flags & 7;
        } else {
            bits = 0;
        }
    } else {
        bits = 0;
    }
    ret = 1 + len;
    r = func_L00_00535FB0(0, ret, 3);
    if (pp == 0) {
        return r;
    }
    p = *pp;
    func_L00_00535E08(&p, 0, ret, 3, 0);
    *(p++) = (u8)bits;
    d = a->data;
    func_0011A370(p, d, len);
    p += len;
    if (len > 0) {
        p[-1] &= (0xFF << bits);
    }
    *pp = p;
    return r;
}
