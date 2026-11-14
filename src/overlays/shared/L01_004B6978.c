#include "common.h"

extern void func_L01_004B6BA8();
extern s64 func_L01_004B8360(void *object);
extern s32 func_L01_00550790(s32 unused0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 D_222B20[];

/* Runs the object's update when its +0x410 flag is set and func_L01_004B8360 is non-zero, then calls 004B6BA8 and, unless +0x60D is set, 00550790. */
void func_L01_004B6978(void *arg0) {
    u8 *temp_s1;

    temp_s1 = *(u8 **)((u8 *)arg0 + 0xAC);
    if (*(s32 *)(temp_s1 + 0x410) != 0 && func_L01_004B8360(arg0) != 0) {
        func_L01_004B6BA8(arg0);
        if (temp_s1[0x60D] == 0) {
            func_L01_00550790((s32)D_222B20, (s32)arg0, (s32)((u8 *)arg0 + 0x10), (s32)((u8 *)arg0 + 0xF0), 0, 0, 0);
        }
    }
}
