#include "common.h"

extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
extern void func_00389F18_003A6890(void (*)(), O_3A1438 *);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
extern void (*D_001D5BD4)(s32);

/* PAL: from rac3-decomp's func_003A5598, constants adapted */
void func_L01_0062C590(u8 *p, s32 i, s32 *v) {
    switch (i) {
    case 3:
        *(s32 *)(p + 0xC) = *v;
        break;
    case 0:
        *(u128_t *)(p + 0x20) = *(u128_t *)v;
        break;
    case 1:
        *(u128_t *)(p + 0x30) = *(u128_t *)v;
        break;
    case 2:
        *(f32 *)(p + 8) = *(f32 *)v;
        break;
    case 4:
        *(s32 *)(p + 0x10) = *v;
        break;
    case 5:
        *(s32 **)(p + 0x14) = v;
        break;
    case 6:
        *(s32 *)(p + 0x18) = *v;
        break;
    }
}
