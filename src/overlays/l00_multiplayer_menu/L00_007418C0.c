#include "common.h"
typedef struct S S;
struct S { char _p0[0x284]; u8 buf[0xC8]; s32 idx; };

void func_L00_007418C0(S *p) {
    if (p->idx != 0) {
        u8 *b;
        b = p->buf;
        b[p->idx - 1] = 0;
        p->idx = p->idx - 1;
        if (b[p->idx - 1] & 0x80) {
            b[p->idx - 1] = 0;
            p->idx = p->idx - 1;
        }
    }
}
