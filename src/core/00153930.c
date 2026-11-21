/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void func_00126BC0(s32);
extern s32 func_00126BE0(s32);

typedef struct {
    u8 pad0[4];
    s16 f4;
    u8 pad6[8];
    u16 fE;
    s32 f10;
    u8 pad14[0xC];
    s32 f20;
    s32 f24;
    u8 pad28[0x14];
    u16 f3C;
    u8 pad3E[2];
    u8 f40[0x28];
} Type2;

typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x14];
    s32 f44;
    u8 pad48[0x480];
    Type2 e[1];
} Type1;

extern Type1 D_1BCC28;

/* Finds the table entry whose key matches the record at arg0 and appends the record to its byte block. */
void func_00153930(u8 *arg0) {
    Type2 *e;
    u8 *s1;
    u8 *s2;
    s32 i;
    s32 cnt;
    s32 hi;

    s1 = arg0 + 0x14;
    for (i = 0; i < D_1BCC28.f44; i++) {
        if (D_1BCC28.e[i].f4 == *(s16 *)(arg0 + 6)) {
            break;
        }
    }
    if (i < D_1BCC28.f44) {
        e = &D_1BCC28.e[i];
        s2 = (u8 *)e + e->f24 * 8 + 0x40;
        if (e->fE & 0x8000) {
            if (*s1++ != 1) {
                return;
            }
        }
        if (*(s32 *)(arg0 + 0xC) != 0) {
            e->f10 = *(s32 *)(arg0 + 0xC);
            return;
        }
        func_00126BE0(D_1BCC28.f2C);
        *(s32 *)s2 = *(s32 *)arg0;
        s2[4] = *s1;
        s1 += 1;
        s2[5] = *s1;
        s1 += 1;
        s2[6] = *s1;
        s1 += 1;
        if (e->fE & 0x4000) {
            s2[7] = *s1;
        }
        cnt = e->f24 + 1;
        e->f24 = cnt;
        hi = cnt % 5;
        e->f24 = hi;
        if (hi == e->f20) {
            e->f20 = hi + 1;
            e->f20 = (hi + 1) % 5;
        } else {
            e->f3C += 1;
        }
        func_00126BC0(D_1BCC28.f2C);
    }
}
