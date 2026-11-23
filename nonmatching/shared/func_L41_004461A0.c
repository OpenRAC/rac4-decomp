/* Not matching yet: BYTES 47/104 (tools/try_func.py func_L41_004461A0 --diff). Not part of the build. */
#include "common.h"

typedef struct Type2 {
    char _p0[0x8];
    s32 f8;
    s32 fC;
    char _p1[0x74 - 0x10];
    u8 f74;
    char _p2[0x7C - 0x75];
    s32 f7C;
} Type2;

typedef struct Type1 {
    char _p0[0x36];
    u16 f36;
    char _p1[0xAC - 0x38];
    Type2 *fAC;
} Type1;

extern s32 D_003980C8[];

void func_L41_004461A0(Type1 *arg0, s32 arg1) {
    Type2 *p = arg0->fAC;

    if (p->f74 != arg1) {
        s32 idx = arg1 & 0xFF;
        p->f74 = arg1;
        p->f7C = 0;
        p->f8 = D_003980C8[idx * 2];
        p->fC = D_003980C8[idx * 2 + 1];
        arg0->f36 = (arg0->f36 & 0x87FF) | (idx << 11);
    }
}
