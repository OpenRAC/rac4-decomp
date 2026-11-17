#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_00494F80(void *);
extern s32 func_00495860(void *object);
extern void func_005A85F8(void *, s32, s32);
extern s32 func_005AF4B8(void *);
extern s32 func_L00_005BC9B8(void *);
extern void func_L00_005EB750(void *, s32);
extern void func_L00_005F15B8(s32 arg0);
extern s32 func_L00_0066D220(s32, s32, void *);
extern void func_L01_00495898(void *arg0);
extern s64 func_L01_004958F0(void *object);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A1B38();
extern s32 func_L01_005AE158(void *);

// Per-object update: when func_L01_004958F0 succeeds, run the 0x458/0x45A checks; otherwise run the timed update and the cleanup.
void func_L01_00494D08(void *arg0) {
    u8 *temp_s2;
    f32 temp_f20;
    s32 temp_s0;
    u128 pos;

    temp_s2 = *(u8 **)((u8 *)arg0 + 0xAC);
    if (func_L01_004958F0(arg0) != 0) {
        if (temp_s2[0x458] != 0 && temp_s2[0x45A] != 0 && func_00495860(arg0) != 0) {
            func_00494F80(arg0);
            func_L01_00495898(arg0);
        }
    } else {
        temp_f20 = *(f32 *)(temp_s2 + 0x280);
        temp_s0 = func_L01_005AE158(arg0);
        func_L00_005EB750(arg0, 0);
        if (temp_s0 == 0 && *(f32 *)(temp_s2 + 0x280) < temp_f20) {
            func_L00_0066D220(0x14, 0, arg0);
        }
        if ((u32)(*(u8 *)((u8 *)arg0 + 0x69) - 6) >= 2U) {
            if (func_005AF4B8(arg0) != 0) {
                func_L01_00591BD8(arg0, 0x13, 6);
            }
        }
        func_005A85F8(arg0, 5, -1);
        func_L01_005A1B38(arg0);
        func_L00_005F15B8((s32)arg0);
        temp_s2[0x482] = 0;
        if (temp_s2[0x4D8] == 0 && *(s32 *)(temp_s2 + 0x140) != 0) {
            pos = *(u128 *)((u8 *)arg0 + 0x10);
            temp_s2[0x4D8] = 1;
            *(u128 *)(temp_s2 + 0x490) = pos;
        }
        func_L00_005BC9B8(temp_s2 + 0x4D4);
    }
}
