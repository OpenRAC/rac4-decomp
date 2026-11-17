#include "common.h"

extern s32 func_0011A9EC(void *, void *);
extern s32 func_0071A3B0(void *);
extern void func_L00_0070B508(void);
extern void func_L00_007100D0(void);
extern s32 func_L00_00779750(s8 *arg0);
extern u8 *D_002233A4;
extern u8 D_172160[];
extern u8 D_2124F0[];
extern u8 *D_0021DFE8;

// Copies the settings block at D_172160 into the objects held by D_002233A4, then runs follow-up calls.
void func_L00_00718568(void) {
    u8 *g;
    u8 *o;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    u8 *s4;

    g = D_002233A4;
    o = D_172160;
    *(s32 *)(g + 0x14) = 0;
    *(s32 *)(g + 0x10) = 0;
    s1 = *(u8 **)(g + 0x64);
    s3 = *(u8 **)(g + 0x3C);
    s4 = *(u8 **)(g + 0x60);
    s2 = *(u8 **)(g + 0x34);
    s1[0x11E] = o[0x2D5];
    s1[0x11C] = o[0x261];
    *(s32 *)(s1 + 0x94) = *(s32 *)(o + 0x288);
    func_0011A9EC(s1 + 0x11, o + 0x266);
    *(s32 *)(s1 + 0x118) = *(s32 *)(o + 0x2AC);
    func_0011A9EC(s1 + 0x98, o + 0x28C);
    if (func_0071A3B0(s1) != 0) {
        func_L00_00779750((s8 *)s1);
    }
    *(s32 *)s2 = *(s32 *)(o + 0x34);
    func_0011A9EC(s2 + 4, o + 0xFE);
    *(s32 *)(s2 + 0x24) = *(s32 *)(o + 0x11C);
    s2[0x28] = o[0x120];
    *(s32 *)s3 = *(s32 *)(o + 0xD8);
    s3[0x30] = o[0xFD];
    func_0011A9EC(s3 + 4, o + 0xDC);
    *(s32 *)s4 = *(s32 *)(o + 0x128);
    func_L00_0070B508();
    func_L00_007100D0();
    if (D_0021DFE8 == D_2124F0) {
        D_0021DFE8 = 0;
    }
}
