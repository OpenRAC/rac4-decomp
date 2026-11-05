/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    u8 f8[0x50];
    s32 f58;
    s32 f5C;
} Type1;

extern u8 D_004A3118[];
extern s32 func_L00_005405F8(s32, void *, s32);

s32 func_L00_005403D0(Type1 *arg0, s32 arg1, s32 *arg2, u8 *arg3, s32 arg4) {
    s32 seen = -1, count = 0, result = -1, total = 0, i, v, c, n, line, pending;
    u8 *buf;

    n = arg0->f0;
    buf = arg0->f8;
    line = arg0->f58;
    pending = arg0->f5C;

    if (arg4 == 0 || (n == 0 && D_004A3118[*arg3 & 0x7F] == 0xF2)) {
        result = 0;
        goto end;
    }

    for (i = 0; i < arg4; i++) {
        if (line >= 80) {
            result = -1;
            goto end;
        }
        c = *(arg3++);
        v = D_004A3118[c & 0x7F];
        if ((v | 0x13) != 0xF3) {
            buf[n++] = c;
            line++;
        } else if (v == 0xFF) {
            result = -1;
            goto end;
        }
        if (c == '=') {
            if (seen == -1) seen = n;
            count++;
        }
        if (v == 0xF0) {
            line = 0;
            if (pending) {
                pending = 0;
                continue;
            }
        }
        pending = 0;
        if (i + 1 == arg4 && ((n & 3) == 0 || count))
            v = 0xF2;
        if (v == 0xF2 || n >= 64) {
            if (v != 0xF2 && n >= 64) pending = 1;
            if (n > 0) {
                v = func_L00_005405F8(arg1, buf, n);
                if (v < 0) {
                    result = 0;
                    goto end;
                }
                n = 0;
                total += v - count;
            } else {
                count = 1;
                v = 0;
            }
            if (v < arg0->f4 && count) {
                result = 0;
                goto end;
            } else {
                arg0->f4 = v;
            }
            if (seen >= 0) {
                result = 0;
                goto end;
            }
            arg1 += v;
        }
    }
    result = 1;
end:
    *arg2 = total;
    arg0->f0 = n;
    arg0->f58 = line;
    arg0->f5C = pending;
    return result;
}
