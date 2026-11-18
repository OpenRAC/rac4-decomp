#include "common.h"

extern u8 *func_00516F88(void);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_00591C18(u8 *object, s32 new_state, s32 param);
extern s32 D_0021EBD8;
extern s32 D_0021DE10;
extern u8 D_1F87F0[];
extern s16 D_001DFC4A[];

void func_L01_00516EC8(void) {
    s32 flags;

    if (func_00516F88() != NULL) {
        if (*(u8 *)(*(u8 **)(func_00516F88() + 0xAC) + 0xA) != 0
            || ((flags = D_1F87F0[D_0021EBD8 * 0xC + ((D_0021DE10 - 1) % 20) * 0x304 + 8]) >> 2 & 1) != 0) {
            func_L01_00591C18(func_00516F88(), 2, -1);
        } else {
            D_001DFC4A[0] = 0;
            func_L01_00591BD8(func_00516F88(), 1, -1);
        }
    }
}
