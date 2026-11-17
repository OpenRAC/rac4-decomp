/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct { u8 b[8]; } A8;
typedef struct { s32 kind; A8 addr; char _pC[8]; u16 f14; u16 f16; } Src_18;
extern void func_01EA8C68(A8 *, A8 *);
s32 func_01E9EE28(Src_18 *p, s32 *kind, A8 *dst, u16 *a, u16 *b) {
    s32 r = 0;
    s32 k;
    u16 port;
    A8 t;
    if (p == 0) {
        return 0x17;
    }
    if (kind == 0) {
        return 0x17;
    }
    if (dst == 0) {
        return 0x17;
    }
    if (a == 0) {
        return 0x17;
    }
    if (b == 0) {
        return 0x17;
    }
    k = p->kind;
    port = p->f14;
    *kind = k;
    *a = port;
    *b = 0;
    switch (k) {
    case 1:
    case 2:
    case 3:
        func_01EA8C68(&t, &p->addr);
        *dst = t;
        break;
    case 4:
    case 5:
        *dst = p->addr;
        break;
    case 6:
    case 7:
        *dst = p->addr;
        *b = p->f16;
        break;
    case 0:
    case 8:
    default:
        r = 0x17;
        break;
    }
    return r;
}
