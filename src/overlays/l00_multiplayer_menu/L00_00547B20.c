/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_0050BD10 (src/levels/39_multiplayer_menu/L39_0050B2B8.c, GPL-3.0), the same code in both games. */

typedef struct {
    unsigned long *d;
    s32 top;
} BN_0050BD10;
extern u8 *D_004A3920[];
s32 func_L00_00547B20(u8 *out, BN_0050BD10 *a, s32 w) {
    u8 *tab;
    s32 mask;
    u8 *p;
    unsigned long *d;
    s32 top;
    unsigned long cur, next, window;
    s32 last;
    u32 carry, bits;
    s32 v, c;
    s32 ret;
    s32 n;
    if (w > 6) w = 6;
    tab = D_004A3920[w];
    mask = (1 << w) - 1;
    bits = 0;
    next = 0;
    n = ((a->top * 64 + w - 1) / w) * 2 + 2;
    p = &out[n];
    *p = 0;
    p--;
    *p = 0;
    p--;
    d = a->d;
    top = a->top;
    window = *d++;
    cur = window;
    last = top < 2;
    if (!last) next = *d++;
    carry = 0;
    for (;;) {
        for (;;) {
            v = (s32)window & mask;
            if ((c = tab[v]) == 0) break;
            carry += c;
            if (carry >= 256) {
                *p-- = carry;
                carry -= 256;
                *p-- = 0;
            }
            bits += c;
            if (bits >= 64) {
                if (last) break;
                top--;
                last = top < 2;
                cur = next;
                next = last ? 0 : *d++;
                bits -= 64;
            }
            if (bits == 0) window = cur; else window = (cur >> bits) | (next << (64 - bits));
        }
        if (v == 0) break;
        *p-- = carry;
        carry = w;
        *p-- = v;
        bits += carry;
        if (bits >= 64) {
            if (last) break;
            top--;
            last = top < 2;
            cur = next;
            next = last ? 0 : *d++;
            bits -= 64;
        }
        if (bits == 0) window = cur; else window = (cur >> bits) | (next << (64 - bits));
    }
    p++;
    ret = 2;
    while (*p) {
        out[0] = p[0];
        ret += 2;
        out[1] = p[1];
        p += 2;
        out += 2;
    }
    out[0] = 0;
    out[1] = 0;
    return ret;
}
