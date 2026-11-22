#include "common.h"
extern u32 D_003BDBD8[];
extern u32 func_00453C68(u32, u32, f32);
void func_L01_004F7930(u8 *arg0, u8 arg1) {
    u8 *p = *(u8 **)(arg0 + 0xAC);
    u8 *q;
    s32 i;
    p[0x4F] = arg1;
    *(u32 *)(p + 0x60) = func_00453C68(D_003BDBD8[p[0x4F]], 0x808080, 0.5f) | 0xA0000000;
    *(u32 *)(p + 0x64) = func_00453C68(D_003BDBD8[p[0x4F]], 0x808080, 0.3f) | 0x20000000;
    *(u32 *)(p + 0x68) = func_00453C68(D_003BDBD8[p[0x4F]], 0x808080, 0.3f) | 0x80000000;
    *(u32 *)(p + 0x6C) = func_00453C68(D_003BDBD8[p[0x4F]], 0x808080, 0.0f) | 0x20000000;
    *(u32 *)(p + 0x1C) = func_00453C68(D_003BDBD8[p[0x4F]], 0x808080, 0.75f);
    q = p;
    for (i = 1; i >= 0; i--) {
        *(u32 *)(q + 0xD0) = *(u32 *)(p + 0x60);
        *(u32 *)(q + 0xD4) = *(u32 *)(p + 0x68);
        q += 0x40;
    }
}
