/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E1CB8 (src/levels/39_multiplayer_menu/L39_004E1CB8.c, GPL-3.0), the same code in both games. */

extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_0051DAB8(u8 **arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    s32 i;
    s32 v;
    u8 *q;
    s32 len;
    u8 t;
    p = *arg0;
    for (i = 0; i < arg2; i++) {
        arg1[i] = 0;
    }
    len = arg2 * 2;
    for (i = 0; i < len; i++) {
        if ((u8)(*p - '0') < 10) {
            v = *p - '0';
        } else if ((u8)(*p - 'A') < 6) {
            v = *p - 'A' + 10;
        } else if ((u8)(*p - 'a') < 6) {
            v = *p - 'a' + 10;
        } else {
            func_L00_004F84C8(9, 0x65, 0x67, 0, 0);
            return 0;
        }
        p++;
        q = &arg1[i / 2];
        t = *q;
        if (i % 2 == 0) {
            *q = t | (v << 4);
        } else {
            *q = t | v;
        }
    }
    *arg0 = p;
    return 1;
}
