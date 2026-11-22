#include "common.h"
typedef struct B { u8 pad0[0x30]; u8 f30; u8 pad31; u16 f32; u8 pad34[0xAC - 0x34]; struct B *fAC; u8 pad2[0xB8 - 0xB0]; s32 fB8; u8 pad3[0xD0 - 0xBC]; struct B *fD0[4]; u8 pad4[0x228 - 0xE0]; struct B *f228; u8 pad5[0x254 - 0x22C]; s32 f254; u8 pad6[0x274 - 0x258]; struct B *f274; } B;
s32 func_L01_004FD508(B *arg0, s32 arg1) {
    B *p = arg0->fAC;
    s32 i;
    B **pp;
    p->f254 = arg1;
    arg0->fB8 = arg1;
    if (p->f228 != 0) {
        p->f228->f30 = arg0->f30;
        p->f228->f32 = arg0->f32;
        pp = p->f228->fAC->fD0;
        for (i = 3; i >= 0; i--) {
            if (*pp != 0) (*pp)->f32 = arg0->f32;
            pp++;
        }
    } else if (p->f274 != 0) {
        p->f274->f32 = arg0->f32;
    }
    return 1;
}
