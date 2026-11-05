/* Not matching yet: BYTES 17/736 (tools/try_func.py func_L00_0053A138 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    s32 count;
    s32 unk4;
    s32 (*check)(struct Type1 *);
} Type1;

typedef struct Type2 {
    s32 unk0;
    s32 lo;
    s32 hi;
    s32 flags;
} Type2;

extern Type2 D_00476F88[];
extern s32 D_004A3054[];

s32 func_L00_00539FD8(s32);
s32 func_L00_0053A060(Type1 *(*)(void), s32, s32, s32, s32);

s32 func_L00_0053A138(Type1 *(*get)(void), s32 a, s32 b, s32 flags)
{
    Type1 *obj;
    s32 ret;
    s32 i;
    s32 n;
    s32 isSet;
    s32 f;
    s32 g;

    n = -1;
    obj = get();
    ret = obj->check(obj);
    if (ret != 0) {
        return ret;
    }
    if (!(flags & 2)) {
        if (a != -1) {
            a = (a << 6) - 0x3F;
        }
        if (b != -1) {
            b = b << 6;
        }
    }
    if (a == -1 || b == -1) {
        if (a == -1) {
            if (obj->count != 0) {
                a = ((obj->count - 1) << 6) + 1;
            } else {
                a = 0;
            }
        }
        if (b == -1) {
            if (obj->count != 0) {
                b = obj->count << 6;
            } else {
                b = 0x7FFFFFFF;
            }
        }
    }
    flags |= 2;
    isSet = flags & 1;
    n = -1;
    for (i = 0; i < D_004A3054[0]; i++) {
        f = D_00476F88[i].flags & 1;
        if (!f && n == -1) {
            n = i;
        }
        g = isSet && f;
        if (g == isSet && D_00476F88[i].lo >= a) {
            break;
        }
    }
    if (i == D_004A3054[0]) {
        if (isSet) {
            i = (n != -1) ? n : 0;
        }
        return func_L00_0053A060(get, a, b, flags, i);
    }
    ret = func_L00_0053A060(get, a, b, flags, i);
    if (ret != 0) {
        return ret;
    }
    i++;
    n++;
    if (i == D_004A3054[0]) {
        return 0;
    }
    if (isSet) {
        while ((D_00476F88[i].flags & 1) == isSet) {
            if (b < D_00476F88[i].hi) {
                if (b >= D_00476F88[i].lo) {
                    D_00476F88[i].lo = b + 1;
                    return 0;
                }
            } else {
                func_L00_00539FD8(i);
                n--;
            }
            if (!(i < n)) {
                break;
            }
        }
    } else {
        for (;;) {
            if (b >= D_00476F88[i].hi) {
                func_L00_00539FD8(i);
                if (!(i < D_004A3054[0])) {
                    goto end;
                }
            } else {
                if (b >= D_00476F88[i].lo) {
                    D_00476F88[i].lo = b + 1;
                }
                return 0;
            }
        }
    }
end:
    return 0;
}
