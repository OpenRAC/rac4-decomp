#include "common.h"

extern u32 D_00221EE0[2];
extern s32 D_001DFCF4[];
extern void func_00488A98(u32, s32);

/* from rac3-decomp's func_L39_00608C08 */
void func_004F0228(void *a0, int a1, int a2, int a3, int t0)
{
    u8 *p = (u8 *)a0;
    int rows = a3 >> 4;
    int cols = t0 >> 4;
    int i, j;
    u32 *q;
    int off;
    unsigned long c00, c10, c18, c28, c38, c40;
    *(unsigned long *)(p + 0x00) = 0x10000003;
    *(unsigned long *)(p + 0x08) = 0;
    *(unsigned long *)(p + 0x10) = 0x1000000000000002UL;
    *(unsigned long *)(p + 0x18) = 0xE;
    *(unsigned long *)(p + 0x20) = ((unsigned long)((long)D_001DFCF4[0] >> 8) << 32) | 0x8000000000000UL;
    *(unsigned long *)(p + 0x28) = 0x50;
    *(unsigned long *)(p + 0x30) = 0x1000000010UL;
    *(unsigned long *)(p + 0x38) = 0x52;
    p += 0x40;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c00 = 0x10000004;
            c10 = 0x1000000000000002UL;
            c18 = 0xE;
            c28 = 0x51;
            c38 = 0x53;
            c40 = 0x0800000000000040UL;
            *(unsigned long *)(p + 0x00) = c00;
            *(unsigned long *)(p + 0x08) = 0;
            *(unsigned long *)(p + 0x10) = c10;
            *(unsigned long *)(p + 0x18) = c18;
            *(unsigned long *)(p + 0x20) = (((unsigned long)(i << 4)) << 32) | (((unsigned long)(j << 4)) << 48);
            *(unsigned long *)(p + 0x28) = c28;
            *(unsigned long *)(p + 0x30) = 0;
            *(unsigned long *)(p + 0x38) = c38;
            *(unsigned long *)(p + 0x40) = c40;
            *(unsigned long *)(p + 0x48) = 0;
            *(u32 *)(p + 0x50) = 0x30000040;
            *(u32 *)(p + 0x54) = a1 & 0x0FFFFFFF;
            *(unsigned long *)(p + 0x58) = 0;
            a1 += 0x400;
            p += 0x60;
        }
    }
    off = a2 << 2;
    *(u32 *)(p + 0x00) = 0x20000000;
    q = (u32 *)((u8 *)D_00221EE0 + off);
    *(u32 *)(p + 0x04) = *q;
    *(u32 *)(p + 0x08) = 0;
    *(u32 *)(p + 0x0C) = 0;
    func_00488A98((*q & 0x0FFFFFFF) | 0x20000000, 1);
}
