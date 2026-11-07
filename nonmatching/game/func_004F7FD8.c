/* Not matching yet: BYTES 66/508 (tools/try_func.py func_004F7FD8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    u8 pad54[3];
    u8 unk57;
    u8 pad58[0xA];
    s8 unk62;
} Type1;

extern void func_004F7A48(u64 **arg0, s32 arg1, s32 arg2);
extern void func_004F7A98(u64 **arg0, s32 arg1, s32 arg2);
extern s32 D_0021DECC;
extern s32 D_0021DF0C;
extern s32 D_0021DF18;
extern u64 D_0020C6C0[];
extern s32 D_00221F74;

Type1 *D_002209F8 = 0;

void func_004F7FD8(void) {
    u64 *p;
    u64 *base;
    s32 n;
    s32 i;
    s32 v;

    base = D_0020C6C0;
    p = base;
    if (D_002209F8->unk57 == 0 && D_002209F8->unk62 == -1) {
        D_0021DECC = 0;
        D_00221F74 = D_0021DF0C;
        return;
    }
    *p = 0x1000000000000005;
    p++;
    *p = 0xE;
    p++;
    *p = 0;
    p++;
    *p = 0x3F;
    p++;
    *p = 0xA0000000A0;
    p++;
    *p = 0x19;
    p++;
    *p = 0x100000000;
    p++;
    *p = 0x4F;
    p++;
    *p = 0x60;
    p++;
    *p = 0x15;
    p++;
    *p = 5;
    p++;
    *p = 9;
    p++;
    n = D_002209F8->unk50;
    if (n >= 5) {
        n = 4;
    }
    D_002209F8->unk50 = n;
    if (D_002209F8->unk50 == 4) {
        func_004F7A98(&p, D_0021DF0C, D_0021DF18);
        v = D_0021DF18;
    } else {
        for (i = 0; i < D_002209F8->unk50; i++) {
            func_004F7A48(&p, D_0021DF0C, D_0021DF18);
        }
        v = D_0021DF0C;
    }
    D_00221F74 = v;
    D_0021DECC = (s32)p - (s32)base;
}
