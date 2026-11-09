#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
extern void func_0049EF30(s32 index);
extern void func_004BA888(void);
extern void func_004BAD50(s32 a0);
extern void func_005014B0(s32 *a0);
extern s32 func_00505B20(void);
extern void func_004BACD8(s32);

extern s8 D_0030A260[];
extern s32 D_0030A490[];

s32 D_0021F8D0 = 0;
extern s32 D_0021F8D4;
u8 D_0021F8D8 = 0;
u8 D_0021F8D9 = 0;
extern u8 D_0021F8DA;

void func_004B9EB0(s32 *arg0) {
    s32 index = func_00505B20();
    s32 *entry = (s32 *)((u8 *)D_0030A490 + index * 0x14);
    s32 t;

    switch (*entry) {
    case 1:
        *entry = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    case 0:
        func_004BA888();
        break;
    }
    if (D_0021F8D9 != 0) {
        D_0021F8D0++;
        if (D_0021F8D0 >= 15) {
            func_004BAD50(1);
            D_0021F8D8 = 1;
            D_0021F8D0 = 0;
            D_0021F8D4 = 0;
            func_0011D920(D_0030A260, (s8 *)func_0045E038(0x3263), 15);
            func_0049E790(func_00505B20(), D_0030A260, func_004BACD8, 3, 0, 1, 0, -1.0f);
            D_0021F8D9 = 0;
        }
    }
    if (D_0021F8D8 != 0) {
        t = ++D_0021F8D4;
        if (t >= 900) {
            func_00497980(4);
            func_0049EF30(index);
            D_0021F8D8 = 0;
            func_004BAD50(0);
            D_0021F8DA = 0;
            return;
        }
        t = (900 - t) / 60 + 1;
        func_0011D920(D_0030A260, (s8 *)func_0045E038(0x3263), t);
    }
}
