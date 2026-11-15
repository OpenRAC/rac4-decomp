#include "common.h"

extern s32 func_0011A9EC(void *, void *);
extern void func_0070B538();
extern void func_L00_00710110();
extern u8 *D_002233A4;
extern u8 D_172160[];

// Copies the settings of the object in D_002233A4 into the block at D_172160, then runs two follow-up calls.
void func_L00_00718688(void) {
    u8 *g;
    u8 *o;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    u8 *s4;

    g = D_002233A4;
    o = D_172160;
    s1 = *(u8 **)(g + 0x64);
    s2 = *(u8 **)(g + 0x34);
    s3 = *(u8 **)(g + 0x3C);
    s4 = *(u8 **)(g + 0x60);
    *(u8 *)(o + 0x2D5) = s1[0x11E];
    *(s32 *)(o + 0x288) = *(s32 *)(s1 + 0x94);
    func_0011A9EC(o + 0x266, s1 + 0x11);
    *(s32 *)(o + 0x2AC) = *(s32 *)(s1 + 0x118);
    func_0011A9EC(o + 0x28C, s1 + 0x98);
    *(s32 *)(o + 0x34) = *(s32 *)s2;
    func_0011A9EC(o + 0xFE, s2 + 4);
    *(s32 *)(o + 0x11C) = *(s32 *)(s2 + 0x24);
    *(u8 *)(o + 0x120) = s2[0x28];
    *(s32 *)(o + 0xD8) = *(s32 *)s3;
    *(u8 *)(o + 0xFD) = s3[0x30];
    func_0011A9EC(o + 0xDC, s3 + 4);
    *(s32 *)(o + 0x128) = *(s32 *)s4;
    func_0070B538();
    func_L00_00710110();
}
