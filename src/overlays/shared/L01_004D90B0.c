#include "common.h"

extern s32 func_L01_004D9120(void *);
extern s32 func_L01_00585BB0(void *);
extern s32 func_L01_00585D40();
extern s32 func_L01_00591BD8(void *, s32, s32);

void func_L01_004D90B0(u8 *arg0) {
    if (func_L01_00585D40() == 0) {
        if (arg0[0x20] == 0) {
            func_L01_004D9120(arg0);
        }
        if (arg0[0x20] == 1 && func_L01_00585BB0(arg0) != 0) {
            func_L01_00591BD8(arg0, 2, -1);
        }
    }
}
