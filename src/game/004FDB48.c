#include "common.h"

extern s32 func_0011AE00(char *, char *, s32);

typedef struct {
    u8 pad0[0x38];
    u32 f38;
    s32 f3C;
} Type1;

typedef struct {
    Type1 *f0;
    u32 f4;
} Type2;

/* matches a name prefix against a table and skips identifier characters */
u8 *func_004FDB48(u8 *name, Type2 *t, s32 *out) {
    u32 i;
    u32 best = 0;
    s32 c;
    s32 under;
    s32 dot;
    s32 dash;

    *out = -1;
    for (i = 0; i < t->f4; i++) {
        if (best < t->f0[i].f38 && func_0011AE00((char *)name, (char *)&t->f0[i], t->f0[i].f38) == 0) {
            best = t->f0[i].f38;
            *out = t->f0[i].f3C;
        }
    }
    under = '_';
    dot = '.';
    dash = '-';
    for (c = *name; (u32)(c - 'A') < 26 || (u32)(c - 'a') < 26 || (u8)c == under || (u32)(c - '0') < 10 || (u8)c == dot || (u8)c == dash; c = *name) {
        name++;
    }
    return name;
}
