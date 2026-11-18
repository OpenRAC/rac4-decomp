#include "common.h"

extern void func_004E87A0(s32 word_a, s32 tag);

extern u16 D_00118150[];
extern s32 D_00118160[];
extern s32 *D_00221F20;
extern s32 D_00222070;
extern s32 D_00003E80;

// VIF packet
void func_004FC8E0(void) {
    func_004E87A0((s32)D_00118160, D_00118150[0]);
    D_00222070 = 0;
    D_00221F20[0] = 0x10000001;
    D_00221F20[2] = 0x20000000;
    D_00221F20[3] = 0xCFCFCFCF;
    D_00221F20[4] = 0x01000404;
    D_00221F20[5] = ((s32)&D_00003E80 >> 3) | 0x14000000;
    D_00221F20[6] = 0x03000000;
    D_00221F20[7] = 0x02000000;
    D_00221F20 += 8;
}
