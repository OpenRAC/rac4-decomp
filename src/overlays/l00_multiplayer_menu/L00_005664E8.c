/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* Parses an integer from a string in the given base: skips blanks, reads an optional sign and 0x prefix, stores the end pointer, sets ERANGE on overflow. */
u32 func_L00_005664E8(u8 *str, u8 **endptr, u32 base, s32 *errp) {
    u8 *p;
    u8 c;
    s32 neg;
    s32 state;
    u32 acc;
    u32 limit;
    s32 rem;
    s32 upper;

    p = str;
    neg = 0;
    do {
        c = *p;
        p++;
    } while ((u32)(c - 9) < 5U || c == ' ');

    if (c == '-') {
        neg = 1;
        c = *p;
        p++;
    } else if (c == '+') {
        c = *p;
        p++;
    }

    if ((base == 0 || base == 16) && c == '0' && ((s8)p[0] == 'x' || (s8)p[0] == 'X')) {
        c = p[1];
        base = 16;
        p += 2;
    }
    if (base == 0) {
        base = (c == '0') ? 8 : 10;
    }

    limit = 0xFFFFFFFFU / base;
    rem = 0xFFFFFFFFU % base;
    acc = 0;
    state = 0;

    while ((s8)c >= 0) {
        if ((u8)(c - 0x30) < 10) {
            c = c - 0x30;
        } else {
            upper = (u8)(c - 0x41) < 26;
            if (upper || (u8)(c - 0x61) < 26) {
                c = c - (upper ? 0x37 : 0x57);
            } else {
                break;
            }
        }
        if ((s32)c >= (s32)base) {
            break;
        }
        if (state < 0 || limit < acc || (acc == limit && rem < c)) {
            state = -1;
        } else {
            state = 1;
            acc = acc * base + c;
        }
        c = *p;
        p++;
    }

    if (state < 0) {
        acc = 0xFFFFFFFFU;
        *errp = 0x22;
    } else if (neg) {
        acc = -acc;
    }

    if (endptr != 0) {
        *endptr = (state == 0) ? str : p - 1;
    }
    return acc;
}
