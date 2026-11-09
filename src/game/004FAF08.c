#include "common.h"

extern void func_004F7A48(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_0021DEFC;
extern s32 D_0021DF08;
extern s32 D_0021DF30;
extern s64 D_0020F800[];

// Fills a packet header in D_0020F800, runs func_004F7A48 twice, stores the packet size.
void func_004FAF08(void) {
    s64 *p;

    D_0020F800[0] = 0x1000000000000005;
    D_0020F800[1] = 0xE;
    D_0020F800[3] = 0x3F;
    D_0020F800[4] = 0xA0000000A0;
    D_0020F800[5] = 0x19;
    D_0020F800[6] = 0x100000000;
    D_0020F800[7] = 0x4F;
    D_0020F800[8] = 0x60;
    D_0020F800[9] = 0x15;
    D_0020F800[10] = 5;
    D_0020F800[11] = 9;
    D_0020F800[2] = 0;
    p = &D_0020F800[12];
    func_004F7A48((s32)&p, D_0021DEFC, D_0021DF08);
    func_004F7A48((s32)&p, D_0021DEFC, D_0021DF08);
    D_0021DF30 = (s32)p - (s32)D_0020F800;
}
