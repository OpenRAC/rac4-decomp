#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
extern Entry D_003D92A0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F728[2] = { 13, 12 };
extern s32 func_00498120(s32);
extern u32 func_00498918(s32, s32);
extern u32 func_004989C0(s32 a0, s32 a1);
extern s32 func_00505B20(void);

u32 func_004AED30(s32 arg0)
{
    s32 r = func_00505B20();
    u32 c;

    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        c = func_00498918(4, 3);
        if (func_00498120(r == 0) == D_0021F728[arg0])
            c = ((s32)((f32)(c >> 24) * 0.2f) << 24) | (c & 0xFFFFFF);
    } else {
        switch (D_003D92A0[arg0].a) {
        case 9:
            c = func_00498918(4, 3);
            break;
        case 12:
            c = func_004989C0(0, 2);
            break;
        default:
            c = 0x80D0D0D0;
            break;
        }
    }
    return c;
}
