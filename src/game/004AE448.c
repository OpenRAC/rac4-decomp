#include "common.h"
extern s32 D_0021DDB4;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_002216B0;
extern u8 D_003092A0[];
s32 D_0021F718[2] = { 0x4000, 0x8000 };
s32 D_0021F73C = 0;
extern s32 func_00497458(s32 playerIndex, u32 previousState);
extern s32 func_0049A6E0(f32 *value, f32 target);
extern s32 func_004A7C08(s32 arg0);
extern u8 func_004A7C30(s32 arg0);
extern void func_004AE708(void);
extern void func_004AE778(void);
extern s32 func_004AE820(s32);
extern s32 func_004AE8A8(s32 arg0);
extern void func_004AE910(void);
extern void func_004AEBF8(void);
extern void func_004AEE80(void);
extern void func_004AF198(void);
extern void func_004AF280(void);
extern void func_004AF338(s32);
extern void func_005014B0(s32 *a0);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);

void func_004AE448(s32 *arg0)
{
    s32 ctx = func_00505B20();
    f32 *entry = (f32 *)(D_003092A0 + ctx * 0x64);
    s32 i;

    switch (*(s32 *)entry) {
    case 0:
        if (!(u8)func_0049A6E0(&entry[1], 1.0f))
            *(s32 *)entry = 1;
        func_004AE778();
        break;
    case 2:
        if (!(u8)func_0049A6E0(&entry[1], 0.0f))
            func_005014B0(arg0);
        func_004AE778();
        break;
    case 1:
        if (D_0021DDB4 == 0 || D_0021DDB4 == 4) {
            if (func_00497458(ctx, 5)) {
                if (D_0021EDD4 != 0 || D_0021EDD8 != 1 || !func_004A7C08(ctx)) {
                    for (i = 0; i < 4; i++) {
                        if (!func_004AE820(i) && func_004AE8A8(D_0021F718[i]))
                            func_004AF338(i);
                    }
                }
            }
        }
        if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
            if (func_004A7C30(ctx))
                func_0049A6E0(&entry[24], 0.0f);
            else
                func_0049A6E0(&entry[24], 1.0f);
            func_00505410(D_002216B0, entry[24]);
        }
        break;
    }
    D_0021F73C |= 0x15;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1)
        func_004AE708();
    if (D_0021F73C & 1)
        func_004AE910();
    if (D_0021F73C & 2)
        func_004AEBF8();
    if (D_0021F73C & 4)
        func_004AEE80();
    if (D_0021F73C & 8)
        func_004AF198();
    if (D_0021F73C & 0x10)
        func_004AF280();
}
