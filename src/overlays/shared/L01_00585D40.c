#include "common.h"

s32 func_L01_00585B78(void *arg0);

s32 func_L01_00585D40(void *arg0) {
    if ((*(u8 *)((s8 *)(func_L01_00585B78(arg0)) + (0x10))) != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x34))) | 2);
        return 1;
    }
    return 0;
}
