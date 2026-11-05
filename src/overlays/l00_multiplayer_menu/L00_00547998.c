/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *buf;
    s32 unk4;
    s32 cap;
    s32 unkC;
    s32 unk10;
} Type1;

typedef struct {
    s32 count;
    Type1 e[1];
} Type2;

typedef struct {
    s64 *key;
    s32 n;
} Type3;

extern int func_L00_005382C8(int a1, int a2);
extern s32 func_L00_00547B20(u8 *dst, Type3 *src, s32 k);
extern u8 D_004B0790[];
extern u8 D_004B07A0[];
extern u8 D_004B07B0[];

s32 func_L00_00547998(Type3 *a0, u8 **out, s32 a2, Type2 *a3) {
    Type1 *ent = &a3->e[a3->count];
    u8 *p = 0;
    s32 n = a0->n;
    s32 w = n << 6;
    s32 k, m, len, sz;
    s64 key;

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        key = *a0->key;
        if (key == 0x10001) {
            p = D_004B07B0;
        } else if (key == 0x11) {
            p = D_004B07A0;
        } else if (key == 3) {
            p = D_004B0790;
        }
        k = 1;
        m = 1;
        w = 0x40;
    } else if (w >= 0x100) {
        k = 5;
        m = 0x10;
        w = 0xD;
    } else if (w >= 0x80) {
        k = 4;
        m = 8;
        w = 0x10;
    } else {
        k = 3;
        m = 4;
        w = 0x16;
    }
    sz = (n * w + 5) / 4;
    if (p == 0) {
        if (ent->cap < sz) {
            func_L00_005382C8((int)ent, sz);
        }
        p = ent->buf;
        len = func_L00_00547B20(p + 4, a0, k) + 2;
        p[2] = k;
        p[3] = m;
        p[0] = len >> 8;
        p[1] = len;
    } else {
        len = 8;
    }
    *out = p;
    return len + 2;
}
