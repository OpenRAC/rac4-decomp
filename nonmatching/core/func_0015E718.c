/* Not matching yet: SIZE ours 136 / retail 144 (tools/try_func.py func_0015E718 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s16 f8;
    s16 fA;
    s16 fC;
    s16 fE;
    u8 pad[0xAD0 - 0x10];
} S1;

typedef struct {
    u8 pad0[0x195];
    u8 f195;
    u8 pad1[0x258 - 0x196];
    s32 f258;
    u8 pad2[0x484 - 0x25C];
    s32 f484;
    s32 f488;
    s32 f48C;
    u8 pad3[0x640 - 0x490];
    s32 f640;
} Type2;

extern void func_0011A518(void *, s32, s32);
extern u8 func_0015C770(void);
extern Type2 D_00172160;
extern S1 D_01F31380[];
extern u8 D_2124F0[];
void *D_0021DFE8 = 0;
s32 D_0021DFF0 = 0;
s32 D_0021DFEC = 0;

void func_0015E718(void) {
    s32 *p;
    s32 i;

    if (func_0015C770() == 0) {
        D_0021DFE8 = 0;
        D_00172160.f258 = 0;
        D_0021DFF0 = 0;
    }
    func_0011A518(D_2124F0, 0, 0x1C4);
    i = 9;
    p = &D_01F31380[9].f4;
    do {
        *p = 0;
        i--;
        p = (s32 *)((u8 *)p - 0xAD0);
    } while (i >= 0);
    D_0021DFEC = 0;
    D_00172160.f640 = 0;
    D_00172160.f48C = 0;
    D_00172160.f484 = 0;
    D_00172160.f195 = 0;
}
