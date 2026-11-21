#include "common.h"
extern u8 D_001DFC60[];
extern s32 D_001DFCF0[];
extern u8 D_001C2040[];
extern s32 D_00221E2C;
extern s32 D_00221E18[];
extern void func_004E7830(s32);
extern void func_00489C28(s32);
extern void func_001634A8(s32);
extern s32 func_00163808(s32, s32, s32, s32, s32, s32, s32);
extern void func_00461EA0(s32, s32, s32, void *, void *);
void func_00462080(s32 arg0)
{
    u8 *p = D_001DFC60;
    if (*(s32 *)(p + 0x40) != arg0) {
        s32 buf;
        u8 *e;
        s32 g;
        *(s32 *)(p + 0x40) = arg0;
        func_004E7830(1);
        buf = D_00221E18[1 - D_00221E2C];
        func_00489C28(1);
        func_001634A8(1);
        e = D_001C2040 + arg0 * 8;
        func_00163808(0, buf, *(s32 *)(D_001C2040 + arg0 * 8 + 0xAF0) + *(s32 *)(D_001C2040 + 0x9AC), *(s32 *)(D_001C2040 + arg0 * 8 + 0xAF4), 0, 0, 0);
        g = D_001DFCF0[8];
        func_00461EA0(D_001DFCF0[14], g, buf, p + 0x44, p + 0x48);
    }
}
