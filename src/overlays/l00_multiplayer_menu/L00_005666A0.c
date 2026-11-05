/* cflags: @ee29 -O2 -G0 */
#include "common.h"

u32 func_L00_005664E8(const char *s, char **end, s32 base, s32 *err);
u32 func_005664A8(u32 x);

s32 func_L00_005666A0(const char *cp, u32 *addr) {
    u32 parts[4];
    u32 val;
    char *c;
    char *endptr;
    s32 err;
    s32 gotend, n;
    s32 ch;

    c = (char *)cp;
    n = 0;
    gotend = 0;
    while (!gotend) {
        err = 0;
        val = func_L00_005664E8(c, &endptr, 0, &err);
        if (err == 0x22) {
            return 0;
        }
        if (endptr == c) {
            return 0;
        }
        parts[n] = val;
        c = endptr;
        ch = (unsigned char)*c;
        switch (*c) {
        case '.':
            if (n == 3) {
                return 0;
            }
            n++;
            c++;
            break;
        case '\0':
            gotend = 1;
            break;
        default:
            if ((u32)(ch - 9) < 5 || ch == ' ') {
                gotend = 1;
                break;
            }
            return 0;
        }
    }

    switch (n) {
    case 0:
        break;
    case 1:
        if (val > 0xffffff || parts[0] > 0xff) {
            return 0;
        }
        val |= parts[0] << 24;
        break;
    case 2:
        if (val > 0xffff || parts[0] > 0xff || parts[1] > 0xff) {
            return 0;
        }
        val |= (parts[0] << 24) | (parts[1] << 16);
        break;
    case 3:
        if (val > 0xff || parts[0] > 0xff || parts[1] > 0xff || parts[2] > 0xff) {
            return 0;
        }
        val |= (parts[0] << 24) | (parts[1] << 16) | (parts[2] << 8);
        break;
    }
    if (addr != 0) {
        *addr = func_005664A8(val);
    }
    return 1;
}
