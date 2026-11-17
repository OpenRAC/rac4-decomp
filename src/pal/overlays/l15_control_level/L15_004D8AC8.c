#include "common.h"

extern s32 D_0021DE40;
extern s16 D_0024798C[];
extern s32 func_L15_004D8480(void *, s32, ...);
extern s32 func_0045DFC8(s16, s16, s16, s32, f32, f32, f32, f32);

void func_L15_004D8AC8(void *arg0)
{
    s32 selected;
    u8 *context = *(u8 **)((u8 *)arg0 + 0xAC);

    if ((s32)((u32)D_0021DE40 - 15000U) >= *(s32 *)(context + 0x248) &&
        (s32)((u32)D_0021DE40 - 750U) >= *(s32 *)(context + 0x21C) &&
        D_0024798C[0] == 0) {
        selected = func_L15_004D8480(context + 0x24C, 10, 0x2AFF, 0x2B02,
                                    0x2B03, 0x2B08, 0x2B0A, 0x2B0B,
                                    0x2B0E, 0x2B0F, 0x2B22, 0x2B2F);
        *(s32 *)(context + 0x218) = selected;
        if (selected >= 0) {
            *(s32 *)(context + 0x248) = D_0021DE40;
            *(s32 *)(context + 0x21C) = D_0021DE40;
            func_0045DFC8((s16)*(s32 *)(context + 0x218), -1, 2, 0,
                          0.75f, 1.0f, 0.0f, 64.0f);
        }
    }
}
