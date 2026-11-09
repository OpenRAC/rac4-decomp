#include "common.h"

void func_00549A38(s32 arg0, s32 arg1, s32 arg2);
extern void *func_00549B18(s32 arg0);
void func_0054A400(s32 arg0, s32 arg1);

void func_00549F08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    u8 *ptr;
    void *temp;

    if ((u32)(arg1 - 1) >= 6) {
        return;
    }

    temp = func_00549B18(arg1);
    ptr = (u8 *)arg0 + (*(u8 *)((u8 *)temp + 0x9) * 0x44);

    for (i = 0; i < 2; i++) {
        if (*(ptr + 0xA6C) == 0) {
            *(ptr + 0xA6C) = arg1;
            if (arg2 >= 0) {
                func_00549A38(*(s16 *)((u8 *)func_00549B18(arg1) + 0x14), arg2, 0xC8);
            }
            if (arg3 >= 2) {
                func_0054A400(arg0, arg1);
            }
            return;
        }
        ptr += 4;
    }
}
