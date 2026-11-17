#include "common.h"

extern void func_00549A38(s16 id, s32 slot, s32 duration);
extern void *func_00549AE8(s32 arg0);
extern s32 func_0054A290(s32, s32, s32);

/* bumps a byte counter at +0x21 for a valid slot, then queues a call for the entry and a follow-up call */
void func_00549D20(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 temp_a0;
    u8 *temp_v1;

    temp_a0 = arg1 - 1;
    if (temp_a0 < 8U) {
        temp_v1 = arg0 + 0x21;
        temp_v1 += temp_a0;
        *temp_v1 += 1;
        if (arg2 >= 0) {
            func_00549A38(*(s16 *)((u8 *)func_00549AE8(arg1) + 0x20), arg2, 0xC8);
        }
        if (arg3 >= 2) {
            func_0054A290(arg0, arg3, arg1);
        }
    }
}
