/* cflags: -O2 -G16 -fopt-stack -mno-check-zero-division */
#include "common.h"

extern s32 D_0021EE54;
extern s32 D_0021EE58;
/* Four retail entries; direct caller004AFD10 supplies row0..3. */
s32 D_0021F7C8[4] = {13, 12, 11, 16};
extern s32 D_003D9318[];
extern s32 func_00506BB8(void);
extern u32 func_00499650(s32, s32);
extern s32 func_00498E58(s32);
extern u32 func_004996F8(s32, s32);

u32 func_004AFBC0(s32 row)
{
    u32 context = func_00506BB8();
    u32 color;
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        color = func_00499650(4, 3);
        if (func_00498E58(context < 1) == *(s32 *)((u32)D_0021F7C8 + ((u32)row << 2))) {
            u32 alpha = color >> 24;
            f32 scaled = (f32)alpha;
            color = ((u32)(s32)(scaled * 0.2f) << 24) | (color & 0x00FFFFFF);
        }
    } else {
        s32 kind = *(s32 *)((u32)D_003D9318 + (u32)row * 12);
        switch (kind) {
        case 9:
            color = func_00499650(4, 3);
            break;
        case 12:
            color = func_004996F8(0, 2);
            break;
        default:
            color = 0x80D0D0D0;
            break;
        }
    }
    return color;
}
