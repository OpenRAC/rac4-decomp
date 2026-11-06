#include "common.h"

extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_004DAA78(s32);
extern s32 func_004E6FA0(u8 *arg0);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_00322EA4[];
extern s32 D_00322F38[];

void func_004DAB90(void) {
    u8 *b;
    u8 *e;
    u8 *s0;
    s32 i;
    s32 ok;

    b = D_00322EA4;
    if (*(s32 *)(b + 0x50) == 0) {
        return;
    }
    i = *(s32 *)(b + 0x54);
    if (i < 0) {
        e = 0;
    } else {
        e = (u8 *)*(s32 *)(b + 0x34) + i * 0x18;
    }
    s0 = *(u8 **)(e + 8);
    ok = 1;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1 && *(s32 *)(s0 + 0x14) == 0x30EB) {
        if (D_00322F38[0] == 0) ok = 0;
    }
    if (ok) {
        if (func_004E6FA0(s0)) {
            if (*(s32 *)(s0 + 8) <= 0) {
                func_004DAA78(1);
            } else {
                func_0049E790(4, (const char *)func_0045E038(0x8D0), func_004DAA78, 3, 0, 0, 0, -1.0f);
            }
        } else {
            func_00497980(4);
        }
    } else {
        func_00497980(4);
    }
}
