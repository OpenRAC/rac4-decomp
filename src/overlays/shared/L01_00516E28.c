#include "common.h"

extern u8 *func_00516F88(void);

s32 func_L01_00516E28(void) {
    return (*(u8 *)(func_00516F88() + 0x20) ^ 3) == 0;
}
