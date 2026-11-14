#include "common.h"

extern void func_L01_004EB408(void *object);
extern void func_L01_00520C50(s32, s32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 D_0021E824;
extern s32 D_0021E828;

// Resets the state byte at 0x2F3 to 0x40 and calls the state change; the first call runs only if the state was not 0x40 or 0x7F
void func_L01_004E84F0(void *arg0, u8 *arg1) {
    if (arg1[0x2F3] != 0x40 && arg1[0x2F3] != 0x7F) {
        func_L01_00520C50(arg1[0x2F3], 0);
    }
    *(s32 *)(arg1 + 0x308) = 0;
    arg1[0x2F3] = 0x40;
    if (D_0021E824 == 0) {
        if (D_0021E828 == 0) {
            func_L01_004EB408(arg0);
        }
    }
    func_L01_00591BD8(arg0, 4, -1);
}
