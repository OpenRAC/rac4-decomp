#include "common.h"

extern s32 func_L00_005BC9B8(void *);
extern s32 func_L00_005C9F50(s32);
extern void func_L00_00764E68(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_L01_00585BB0(u8 *object);
extern s32 func_L01_00585D40(void *arg0);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_00580010(s32 arg0, s32 arg1, s32 arg2);
extern void func_L06_004C8248(void *arg0);
extern s32 D_0021DDB4;
extern s32 D_0021DF64;
extern s32 D_0021E694;
extern s32 D_0021E698;

// Updates the two slots of an active object and calls its helpers for the state it is in.
void func_L06_004C80D0(u8 *arg0) {
    u8 *temp_s1;
    u8 *temp_s0;
    s32 var_v0;

    if (D_0021DDB4 != 2 && func_L01_00585D40(arg0) == 0) {
        if (arg0[0x20] == 0) {
            func_L06_004C8248(arg0);
        }
        temp_s1 = *(u8 **)(arg0 + 0xAC);
        func_L00_005BC9B8(temp_s1 + 0x90);
        if (*(s16 *)(temp_s1 + 0x8C) != -1) {
            func_L00_005BC9B8(temp_s1 + 0x8E);
        }
        if (arg0[0x20] == 1) {
            if (func_L01_00585BB0(arg0) != 0) {
                func_L01_00591BD8(arg0, 2, -1);
            }
        }
        temp_s0 = temp_s1 + 0x74;
        func_L00_00764E68(0, func_L00_005C9F50(0x255C), *(s32 *)(temp_s1 + 0x88), *(s32 *)(temp_s0 + (D_0021DF64 << 2)));
        if (*(s16 *)(temp_s1 + 0x90) != 0) {
            func_00580010(0, func_L00_005C9F50(0x255E), *(s16 *)(temp_s1 + 0x90));
            var_v0 = D_0021E694;
        } else {
            var_v0 = D_0021E694;
        }
        if (var_v0 == 0 && D_0021E698 == 1) {
            func_L00_00764E68(1, func_L00_005C9F50(0x255C), *(s32 *)(temp_s1 + 0x88), *(s32 *)(temp_s0 + (D_0021DF64 << 2)));
            if (*(s16 *)(temp_s1 + 0x90) != 0) {
                func_00580010(1, func_L00_005C9F50(0x255E), *(s16 *)(temp_s1 + 0x90));
            }
        }
    }
}
