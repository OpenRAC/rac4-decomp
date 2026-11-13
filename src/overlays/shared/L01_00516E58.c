#include "common.h"

extern u8 *func_00516F88(void);
extern void func_L01_00591C18(u8 *object, s32 new_state, s32 param);

void func_L01_00516E58(s32 a0, s32 a1, s32 a2) {
    u8 *v1;

    if (func_00516F88() != NULL) {
        v1 = *(u8 **)(func_00516F88() + 0xAC);
        v1[0x28] = a0;
        v1[0x29] = a1;
        v1[0x2A] = a2;
        func_L01_00591C18(func_00516F88(), 3, -1);
    }
}
