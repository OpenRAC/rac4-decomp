#include "common.h"

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    u32 f8;
} Type1;

extern s32 func_0045D7B0(s16 id, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w);
extern void func_00549A38(s16 id, s32 slot, s32 duration);
extern void *func_00549B00(s32 arg0);
extern s32 func_0054A370(void *, s32, s32);
extern s32 D_0021DE10;
extern s32 D_0021EDD4;
extern u32 D_003DDAB0[];
extern Type1 D_001F1400;
extern u32 D_0021DA70;

void func_00549DC0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if ((u32)(arg1 - 1) < 8) {
        *(u16 *)(arg0 + 0x2A) |= D_003DDAB0[arg1];
        if (D_0021EDD4 != 1 && D_001F1400.f0 == 0) {
            D_001F1400.f0++;
            if (D_0021DA70 > D_001F1400.f4) {
                D_001F1400.f4 = D_0021DA70;
            }
            D_001F1400.f8 = D_001F1400.f8 | (1 << ((D_0021DE10 - 1) % 20)) | 0x80000000;
            func_0045D7B0(0x2578, 0, 2, 0, 0.0f, 1.0f, 0.0f, 64.0f);
        }
        if (arg2 >= 0) {
            func_00549A38(*(s16 *)((u8 *)func_00549B00(arg1) + 0x18), arg2, 0xC8);
        }
        if (arg3 >= 2) {
            func_0054A370(arg0, arg3, arg1);
        }
    }
}
