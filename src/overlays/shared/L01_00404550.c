#include "common.h"
/* Ported from rac3-decomp's func_L01_0034B8A8 (src/us/levels/func_L01_0034B8A8.c, GPL-3.0), the same code in both games. */

typedef struct {
    u8 pad0[0x228];
    s32 zero228;
    f32 scaled22C;
    u8 pad230[8];
    f32 max238;
    f32 hundred23C;
    u8 pad240[0x10];
    s32 value250;
    s32 value254;
    s32 value258;
} Global_L01_0034B8A8;
extern Global_L01_0034B8A8 D_0023FE40;
extern void func_00447BA8(void);
void func_L01_00404550(u8 *object, f32 angle) {
    f32 scaled;
    *(s32 *)(object + 0x4C) = 30;
    *(f32 *)(object + 0x48) = angle;
    scaled = angle * 1024.0f * 0.4f;
    D_0023FE40.max238 = 255.0f;
    D_0023FE40.scaled22C = scaled;
    D_0023FE40.hundred23C = 100.0f;
    D_0023FE40.zero228 = 0;
    D_0023FE40.value250 = 255;
    D_0023FE40.value254 = 255;
    D_0023FE40.value258 = 255;
    func_00447BA8();
}
